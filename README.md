🌦️ Station Météo Connectée (ATmega328P)

Bienvenue sur le dépôt de ma Station Météo DIY ! Ce projet est basé sur un microcontrôleur ATmega328P et permet de surveiller la température et l'humidité tout en affichant les données localement sur un écran OLED.

🚀 Fonctionnalités

    Mesure précise de la température et de l'humidité via un capteur DHT22.

    Affichage local sur écran OLED 0.96" via le bus I2C.

    Régulation de tension intégrée (LD1117) pour une alimentation via une source DC externe (9V-12V).

    Indicateur LED pour confirmer la mise sous tension.

🛠️ Matériel (BOM)
Composant	Description
MCU	ATmega328P (Microchip)
Capteur	DHT22 (Température & Humidité)
Écran	OLED SSD1306 (128x64)
Alimentation	LD1117S50 (Régulateur 5V)
Cristal	Quartz 16MHz + 2x 22pF
📐 Schéma Électrique

Le projet a été conçu avec KiCad 7. Vous trouverez les fichiers sources dans le dossier /hardware.
Points clés de la conception :

    Protection contre l'inversion de polarité via la diode D1.

    Filtrage de l'alimentation avec des condensateurs électrolytiques et céramiques.

    Résistances de Pull-up nécessaires sur le bus I2C et le capteur DHT.

💻 Logiciel

Le code est écrit en C++/Arduino. Les bibliothèques suivantes sont requises :

    Adafruit_SSD1306 (pour l'écran OLED)

    DHT sensor library (pour le capteur DHT22)

📂 Structure du Dépôt

    📂 hardware/ : Fichiers KiCad (.kicad_sch, .kicad_pcb).

    📂 firmware/ : Code source Arduino/C++.

    📂 assets/ : Images et schémas du projet.

🔧 Installation

    Clonez le dépôt : git clone https://github.com/votre-nom/station-meteo.git

    Ouvrez le schéma sous KiCad pour visualiser le circuit.

    Flashez l'ATmega328P avec le code fourni dans le dossier firmware.

Prochaines étapes suggérées :

    Ajouter une interface Wi-Fi (ESP8266) pour envoyer les données sur le cloud.

    Concevoir un boîtier 3D sur mesure.
