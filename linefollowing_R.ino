#define _DEBUG_

#include <math.h>
// pin of moters
#define MOT_L_IN1 3
#define MOT_L_IN2 5
#define MOT_R_IN3 6
#define MOT_R_IN4 7
#define En_1 8
#define En_2 9

// pin of lsa08
#define JP 10
#define LED 13

uint8_t val;
uint8_t sensor;
bool isJP;
void setup() {
   Serial.begin(115200);
  Serial3.begin(115200);
  pinMode(JP, INPUT);

  pinMode(MOT_L_IN1,OUTPUT);
  pinMode(MOT_L_IN2,OUTPUT);
  pinMode(MOT_R_IN3,OUTPUT);
  pinMode(MOT_R_IN4,OUTPUT);
  pinMode(En_1 ,OUTPUT);
  pinMode(En_2 ,OUTPUT);
  pinMode(LED ,OUTPUT);

  digitalWrite(En_1, LOW);
  digitalWrite(En_2, LOW);

  }
void loop()
{  
  digitalWrite(En_1, HIGH);
  digitalWrite(En_2, HIGH);
   
if(Serial3.available())
 {
   sensor = Serial3.read();
   Serial.print("value  ::");
   Serial.println(sensor);
   digitalWrite(LED , LOW);
 }
 else{
  Serial.println(" hello");
  digitalWrite(LED , HIGH);
 }
 do
 {
  delay(50);
  run();

 }while(Serial.available());
}

 void straight(){
  digitalWrite(MOT_L_IN1,HIGH);
  digitalWrite(MOT_L_IN2,LOW);
  digitalWrite(MOT_R_IN3,LOW);
  digitalWrite(MOT_R_IN4,HIGH);
 }
 void wait(){
   digitalWrite(En_1,LOW);
   digitalWrite(En_2,LOW);
}
 void follow(){
  digitalWrite(MOT_L_IN1,HIGH);
  digitalWrite(MOT_L_IN2,LOW);
  digitalWrite(MOT_R_IN3,LOW);
  digitalWrite(MOT_R_IN4,HIGH);
 }


void run(){
  if(isJP){
    straight();
  }
  else if((sensor >= 25)&&(sensor <= 45)){
    follow();
  }
  else{
    wait();
  }
  
  }
