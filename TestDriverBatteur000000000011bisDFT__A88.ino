
 // claude.dufourmont@laposte.net
 // YouTube : https://www.youtube.com/c/ClaudeDufourmont
 // Vidéo : https://youtu.be/YH24vIzr_0g
 // Schéma : https://mega.nz/file/bk9GARaa#RCFJP4ZNqHRy7nrhzwWDpWaAZceQJa1buGdCRgwWGls
 
  #define  ledVerte  0                           // Plein Courant
  #define  ledJaune   3                           // Courant Reduit 
  #define  ledRouge   4                          // Gate PWM Solenoeid                                   
  #define  MosfetGate   1
  
  #define Bouton 2                                    
  
  bool etatBouton = LOW;
    
  unsigned long Tprecedent = 0;
  unsigned long Tactuel = 0;
  
  void setup() 
  {
  pinMode (ledVerte, OUTPUT);
  pinMode (ledJaune, OUTPUT);
  pinMode (ledRouge, OUTPUT);
  pinMode (MosfetGate, OUTPUT);
  pinMode (Bouton, INPUT);
  }

  void loop() 
  {
  if (digitalRead (Bouton)== LOW)
  {
  Tprecedent = Tactuel;
  analogWrite (MosfetGate,0);
  digitalWrite (ledVerte, LOW);
  digitalWrite (ledJaune, LOW);
  digitalWrite (ledRouge, LOW);
  etatBouton = LOW;
  }
  if (digitalRead (Bouton) !=etatBouton && digitalRead (Bouton) ==HIGH)
  {
  Tactuel = millis();
  
  if (Tactuel - Tprecedent >0 && Tactuel - Tprecedent <= 3000)
  {
  analogWrite (MosfetGate,250);
  digitalWrite (ledVerte, HIGH);
  digitalWrite (ledJaune, LOW);
  digitalWrite (ledRouge, HIGH);
  }
   
  if (Tactuel-Tprecedent >3000  && Tactuel-Tprecedent <= 8000)
  {
  analogWrite (MosfetGate, 50);
  digitalWrite (ledVerte, LOW);
  digitalWrite (ledJaune, HIGH);
  digitalWrite (ledRouge, HIGH);
  }
 
  if (Tactuel-Tprecedent > 8000)
  {
  analogWrite (MosfetGate,0);
  digitalWrite (ledVerte, LOW);
  digitalWrite (ledJaune, LOW);
  digitalWrite (ledRouge, LOW); 
  }
  
  }
  else
  {
  analogWrite (MosfetGate,0);
  digitalWrite (ledRouge, LOW);
  
  }
  }
  
    
  
 
