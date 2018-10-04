#include <LiquidCrystal.h>
#include <Timers.h>
#include <dht.h>


LiquidCrystal lcd(12,11,5,4,3,2);
Timers<1>alarma;
dht DHT;

#define DHT11_PIN 10

void setup() 

{
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  lcd.begin(16,2);
  lcd.clear();
  digitalWrite(6,HIGH);
  delay(500);
  digitalWrite(6,LOW);
  digitalWrite(7,HIGH);
  delay(500);
  digitalWrite(7,LOW);
  digitalWrite(8,HIGH);
  delay(500);
  digitalWrite(8,LOW);
  lcd.setCursor(3,0);
  lcd.print("!! WITAM !!");
  lcd.setCursor(4,1);
  lcd.print("HUMI 4484");
  delay(3000);
  alarma.attach(0,1000,alarm);
    
//  T1.begin(3000);

}

void loop() 

{

int max=60;
int mid=40;

int chk = DHT.read11(DHT11_PIN);
  digitalWrite(6,HIGH);
  lcd.setCursor(0,0); 
  lcd.print("Temp: ");
  lcd.print(DHT.temperature);
  lcd.print((char)223);
  lcd.print("C");
  lcd.setCursor(0,1);
  lcd.print("Wilgoc: ");
  lcd.print(DHT.humidity);
  lcd.print("%");
  
 if (DHT.humidity<mid)
  {
    digitalWrite(6,HIGH);
    digitalWrite(7,LOW);  
    delay(1000);
  }

 if (DHT.humidity>=mid)
  {
    digitalWrite(7,HIGH);  
    delay(1000);
  }
 
 if (DHT.humidity>=max)
  {
   alarm.process();
  }
  
 }

  void alarm()
  {
     for(int i=0;i<=5;i=i+1)
    {
    lcd.clear();
    lcd.setCursor(4,0);
    lcd.print("!ALARM!");
    lcd.setCursor(0,1);
    lcd.print("WYSOKA WILGOC!!");
    digitalWrite(8,HIGH);  
    delay(500);
    digitalWrite(8,LOW);
    delay(500);
    lcd.clear();
    }
  }
  
 /* else
  {
   digitalWrite(8,LOW); 
  }
 */ 
  delay(1200);
  
/*if (T1.available())
  {
    lcd.setCursor(0,0);
    lcd.print("hello!!");
    delay(2000);
    lcd.clear();
    T1.restart();
  }
*/


}
