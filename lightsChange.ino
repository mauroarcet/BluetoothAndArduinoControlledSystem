//Project by Mauricio Arce 06/24/2017
//Bluetooth controlled light system
//Uses 5 leds for entertainment and needs an HC-05 Bluetooth Module and AMR_Voice app
//App also named as BT Voice Control for Arduino  
String voice;
int led2 = 2;
int led3 = 3;
int led4 = 4;
int led5 = 5;

void turnOn() {
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, HIGH);
  digitalWrite(led5, HIGH);
}

void turnOff() {
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);
}

//Light Flicking
void fiesta() {
  while(true){
    digitalWrite(led2, HIGH);
    digitalWrite(led4, HIGH);
    delay(100);
    digitalWrite(led2, LOW);
    digitalWrite(led4, LOW);
    delay(100);
    digitalWrite(led3, HIGH);
    digitalWrite(led5, HIGH);
    delay(100);
    digitalWrite(led3, LOW);
    digitalWrite(led5, LOW);
    delay(100);
  }
}

void setup() {
  Serial.begin(9600);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  

}

void loop() {
  while(Serial.available()){
    delay(10);
    char c = Serial.read();
    //The app sends a '#' when it stopped listening 
    if(c == '#'){
      break;
    }
    voice += c;
  }
  //The app sends a '*' at the begginng of every word
  if (voice == "*Lights Up"){
    turnOn();
  }

  else if(voice == "*Lights Down"){
    turnOff();
  }

  else if(voice == "*Party"){
    fiesta();
  }
//LIMPIAR
  voice = "";
}
