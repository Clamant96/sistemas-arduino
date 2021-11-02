#include <LiquidCrystal.h>

const int rs=12,en=11,d4=5,d5=4,d6=3,d7=2;
const int trig = 8;
const int echo = 7;
const int l = 13;
float dist;

LiquidCrystal lcd(rs,en,d4,d5,d6,d7); // PORTAS DE CONEXAO

void setup() {
  lcd.begin(16,2);
  Serial.begin(9600);
  
  lcd.print("hello IOT");
  
  pinMode (trig,OUTPUT);
  pinMode (echo,INPUT);
  
}

void loop() {
  //lcd.home () ;
  //area dos comandos do sensor ultrasonico
  digitalWrite(trig,LOW);
  delayMicroseconds(5);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  dist=pulseIn(echo,HIGH);
  //dist=dist/58;

  lcd.setCursor(0, 1);
  lcd.display();

  Serial.print ("distancia inicial ");    
  Serial.print (dist);
  Serial.print ("cm:  ");         
  Serial.println();
  
  dist=(dist/2) * 0.0343;
 
  Serial.print ("distancia final ");    
  Serial.print (dist);
  Serial.print ("cm: ");         
  Serial.println();
  
  if (dist >= 329) {
    dist=0; 
    
  }
   
  float cdist=dist;
  
  if (cdist <= 0) {
    digitalWrite (l,HIGH);
    lcd.home () ;
    lcd.print ("fora de alcance");
    Serial.print ("fora de alcance \n");
    delay (500);
    lcd.clear();
  
  }
  else {
    digitalWrite (l,LOW);
    lcd.home () ;
    lcd.print ("dentro de alcance");
    
    Serial.print ("dentro de alcance \n");
    
    delay (500); 
    
    for (int seq=0; seq <=2; seq ++) {
      lcd.scrollDisplayLeft();
      delay (500);
    
    }
      
    delay (500);
    
  }

  // area dos comandos do sensor ultrasonico
  digitalWrite(trig,HIGH);
  
  Serial.print ("distancia   ");    
  Serial.print (dist);
  Serial.print ("cm  ");         
  Serial.println();
 
}
