#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>

// Configuration de l'écran OLED (128x64)
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1 // Reset partagé avec l'Arduino
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Configuration du capteur DHT22
#define DHTPIN 4       // Broche DATA connectée au PD2 (Pin 4 de l'ATmega)
#define DHTTYPE DHT22  
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  
  // Initialisation du DHT22
  dht.begin();

  // Initialisation de l'écran OLED (Adresse I2C 0x3C pour la plupart des SSD1306)
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("Erreur d'initialisation de l'écran"));
    for(;;); // Bloquer si l'écran ne répond pas
  }

  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(1);
  display.setCursor(10, 20);
  display.print("Station Meteo...");
  display.display();
  delay(2000);
}

void loop() {
  // Lecture des données (le DHT22 est lent, on attend 2 sec entre chaque lecture)
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  // Vérification des erreurs de lecture
  if (isnan(h) || isnan(t)) {
    display.clearDisplay();
    display.setCursor(0, 0);
    display.println("Erreur de lecture");
    display.display();
    return;
  }

  // Affichage sur l'écran OLED
  display.clearDisplay();
  
  // Titre
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("--- DONNEES ---");

  // Température
  display.setTextSize(2);
  display.setCursor(0, 20);
  display.print("T: ");
  display.print(t, 1);
  display.print(" C");

  // Humidité
  display.setCursor(0, 45);
  display.print("H: ");
  display.print(h, 0);
  display.print(" %");

  display.display();

  delay(2000); // Pause de 2 secondes
}
