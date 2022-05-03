#include <Servo.h>

Servo servothumb;          
Servo servoindex;          
Servo servomiddle;
Servo servoring;
Servo servopinky;


char number[50];
char c;
int state = 0;
String myStringRec;
int stringCounter = 0;
bool stringCounterStart = false;
String myRevivedString;
int stringLength = 6;

int servoPinky,servoMiddle,servoIndex,servoThumb,servoRing;
int myVals[] ={2,2,2,2,2} ;

void receiveData() {
  int i = 0;
  while (Serial.available()) {
   char c = Serial.read();
  
    if (c == '$') {
      stringCounterStart = true;
    }
    if (stringCounterStart == true )
    {
      if (stringCounter < stringLength)
      {
        myRevivedString = String(myRevivedString + c);
        stringCounter++;
      }
      if (stringCounter >= stringLength) {
        stringCounter = 0; stringCounterStart = false;
        servoPinky = myRevivedString.substring(1, 2).toInt();
        servoRing = myRevivedString.substring(2, 3).toInt();
        servoMiddle = myRevivedString.substring(3, 4).toInt();
        servoIndex = myRevivedString.substring(4, 5).toInt();
        servoThumb = myRevivedString.substring(5, 6).toInt();
//        Serial.print(servoPinky);
//        Serial.print(" ");
//        Serial.print(servoRing);
//        Serial.print(" ");
//        Serial.print(servoMiddle);
//        Serial.print(" ");
//        Serial.print(servoIndex);
//        Serial.print(" ");
//        Serial.println(servoThumb);       
        myRevivedString = "";
      }
    }
  }
}


void setup() {

  Serial.begin(9600);
  servothumb.attach(9);  
  servoindex.attach(12);  
  servopinky.attach(11);
  servoring.attach(10);
  servomiddle.attach(13);
  delay(5);

  

}

void loop() {

receiveData();
if (servoPinky ==0){  servopinky.write(150);}else if (servoPinky ==1){servopinky.write(45);}else{servopinky.write(0);delay(10);}
if (servoIndex ==0){  servoindex.write(135);}else if(servoIndex ==1){servoindex.write(45);}else{servoindex.write(0);delay(10);}
if (servoMiddle ==0){  servomiddle.write(135);}else if(servoMiddle ==1){servomiddle.write(45);}else{servomiddle.write(0);delay(10);}
if (servoThumb ==0){  servothumb.write(120);}else if(servoThumb ==1){servothumb.write(45);}else{servothumb.write(0);delay(10);}
if (servoRing ==0){  servoring.write(135);}else if(servoRing ==1){servoring.write(45);}else{servoring.write(0);delay(10);}
}
