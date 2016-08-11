// Wifi hack Livebox V.3
// By TheValentin61
// OPEN SOURCE !

int pinboutton = 2;    // bouton 1
int moteur1Pin1 = 3;    // pin 2 sur L293D
int moteur1Pin2 = 4;    // pin 7 sur  L293D
int pinboutton2 = 5; // bouton 2
int enablePin = 9;    // pin 1 sur  L293D

char val;

void setup() {
  // mettre le bouton en INPUT
  pinMode(pinboutton, INPUT);
  pinMode(pinboutton2, INPUT);
  // mettre les autres pins en OUTPUT
  pinMode(moteur1Pin1, OUTPUT);
  pinMode(moteur1Pin2, OUTPUT);
  pinMode(enablePin, OUTPUT);
  // mettre enablePin en HIGH
  digitalWrite(enablePin, HIGH);
  
  // Led
  pinMode(13, OUTPUT); // Led "ATTENTE"
  pinMode(6, OUTPUT); // Led "FIN PROCESSUS"
  pinMode(7, OUTPUT); // Led  "DEBUT PROCESSUS"
  pinMode(8, OUTPUT); // Led  "ERREUR"

 // Communication
  Serial.begin(115200);       // Commencer la communication a 115200 baud
}

void loop() {

// Led d'attente...
    {
    digitalWrite(13, HIGH);   
    delay(1000);              // Attendre pendant une seconde
    digitalWrite(13, LOW);    
    delay(1000);              // Attendre pendant une seconde
    }
  
    if( Serial.available() )       // Si le data est sûr read
  {;}
    val = Serial.read();         // Lire et stocker dans 'val'
 
  if( val == 'o' )
  
  Serial.println("En cours..."); // Message de retour quand il recoi "ouvrir"

    digitalWrite(7, HIGH);  //Led commencement du processus   
    delay(3000);              // Attendre pendant une seconde
    digitalWrite(7, LOW);    
    delay(3000); 
 
  // Si le bouton1 est pressé le moteur va tourner dans un sens
  if (digitalRead(pinboutton) == HIGH) {
    digitalWrite(moteur1Pin1, LOW);   // mettre le pin 2 en LOW
    delay(2500);
    digitalWrite(moteur1Pin2, HIGH);  // mettre le pin 2 en HIGH
    delay(2500);
  }
  // Si le bouton2 est presser il tourne dans l'autre sens
  if (digitalRead(pinboutton2) == HIGH) {
    digitalWrite(moteur1Pin1, HIGH);  // mettre le pin 2 en HIGH
    delay(2500);
    digitalWrite(moteur1Pin2, LOW);   // mettre le pin 2 en LOW
    delay(2500);

    digitalWrite(6, HIGH); //Led processus terminé  "FIN"
    delay(3000);              // Attendre pendant une seconde
    digitalWrite(6, LOW);    
    delay(3000); 
  }
    {

       if( Serial.available() )       // Si le data est sûr read
  {;}
    val = Serial.read();         // Lire et stocker dans 'val'
 
  if( val == '0' )
  
  Serial.println("Commande inconnue..."); // Message de retour quand il recoi "un mot autre que 1"
  
    digitalWrite(8, HIGH);   
    delay(1000);              // Attendre pendant une seconde
    digitalWrite(8, LOW);    
    delay(1000);              // Attendre pendant une seconde

    }
  }
//fin du programme