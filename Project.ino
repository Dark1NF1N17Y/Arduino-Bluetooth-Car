#include <Adafruit_LiquidCrystal.h>
#include <Wire.h>
Adafruit_LiquidCrystal lcd(0);
int rightmotor = 13;
int leftmotor = 12;
int sensor = 7;
int frontled = 8;
int redled1 = 4;
int redled2 = 2;
int horn = 3;
char command;

void setup()
{ 
  pinMode(rightmotor, OUTPUT);
  pinMode(leftmotor, OUTPUT);
  pinMode(sensor, INPUT);
  pinMode(frontled, OUTPUT);
  pinMode(redled1, OUTPUT);
  pinMode(redled2, OUTPUT);
  pinMode(horn, OUTPUT);
  Serial.begin(500);
  digitalWrite(redled1, HIGH);
  digitalWrite(redled2, HIGH);
  lcd.begin(16, 2);
}

void loop()
{
  lcd.setCursor(0,0);
  lcd.print("                ");
  if(digitalRead(sensor) == HIGH){
  Serial.println("Something Blocks Us!");
  lcd.setCursor(0,0);
  lcd.print("Something Blocks");
  digitalWrite(rightmotor, LOW);
  digitalWrite(leftmotor, LOW);
  digitalWrite(redled1, HIGH);
  digitalWrite(redled2, HIGH);
  delay(2000);
  loop();
  }
  if(Serial.available() > 0){
  command = Serial.read();
  if(command == 'h'){
  digitalWrite(frontled, HIGH);
  delay(500);
  digitalWrite(frontled, LOW);
  Serial.println("=====================");
  Serial.println("h --> Help , 0 --> Stop , 1 --> Forward , 2 --> Turn Right");
  Serial.println("3 --> Turn Left , 4 --> Lights On-Off , 5 --> Horn");
  Serial.println("=====================");
  }
  else if(command == '1'){
  digitalWrite(rightmotor, HIGH);
  digitalWrite(leftmotor, HIGH);
  digitalWrite(redled1,LOW);
  digitalWrite(redled2,LOW);
  }
  else if(command == '0'){
  digitalWrite(rightmotor, LOW);
  digitalWrite(leftmotor, LOW);
  digitalWrite(redled1,HIGH);
  digitalWrite(redled2,HIGH);
  }
  else if(command == '2'){
  digitalWrite(rightmotor, LOW);
  digitalWrite(leftmotor, HIGH);
  digitalWrite(redled1, LOW);
  digitalWrite(redled2, HIGH);
  }
  else if(command == '3'){
  digitalWrite(rightmotor, HIGH);
  digitalWrite(leftmotor, LOW);
  digitalWrite(redled1, HIGH);
  digitalWrite(redled2, LOW);
  }
  else if(command == '4'){
    if(digitalRead(frontled) == LOW){
    digitalWrite(frontled, HIGH);
    }else{
    digitalWrite(frontled, LOW);
    }
  }
  else if(command == '5'){
    //digitalWrite(horn , HIGH);
    tone(horn,3000,500);
    delay(500);
    digitalWrite(horn , LOW);
  }
  else{
  Serial.println("Wrong Input!");
  lcd.setCursor(0,0);
  lcd.print("Wrong Input!");
  }
  }
    }
