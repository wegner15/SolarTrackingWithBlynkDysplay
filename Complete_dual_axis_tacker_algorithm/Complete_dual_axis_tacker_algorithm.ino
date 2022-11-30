//Motors
#define motorT1 4
#define motorT2 5
#define northSouthMotorSpeed 6

#define motorT3 7
#define motorT4 8
#define eastWestMotorSpeed 9

//Sensors
#define east A0
#define west A1
#define north A2
#define south A3


void setup() {
 
  // put your setup code here, to run once:
pinMode(motorT1, OUTPUT);
pinMode(motorT2, OUTPUT);
pinMode(northSouthMotorSpeed, OUTPUT);

pinMode(motorT3, OUTPUT);
pinMode(motorT4, OUTPUT);
pinMode(eastWestMotorSpeed, OUTPUT);

Serial.begin(9600);
}
void sensorTests(){
  int eastValue=analogRead(east);
  int westValue=analogRead(west);
  int northValue=analogRead(north);
  int southValue=analogRead(south);
  Serial.println("East:"+String(eastValue)+"  West:"+String(westValue)+"  North:"+String(northValue)+"  \nSouth:"+String(southValue));
}
void northSouthMovement(){
  int northLight=analogRead(north);
  int southLight=analogRead(south);

 int Speed=map(abs(northLight-southLight),0,1000,50,255);
 if(northLight>southLight){
  moveNorth(Speed);
  
 }
 else if(northLight<southLight){
  moveSouth(Speed);
  
 }
 delay(100);
 Stop();
 
}
void eastWestMovement(){
int eastLight=analogRead(east);
  int westLight=analogRead(west);
  int Speed=map(abs(eastLight-westLight),0,1000,10,255);
  if (eastLight>westLight){
    //Move east
   
    moveEast(Speed);
    
    
  }
  else if (westLight>eastLight){
    //Move west
    
     moveWest(Speed);
    
  }
  delay(100);
  Stop();

  
  
  }
void loop() {
  northSouthMovement();
  delay(100);
  eastWestMovement();
  delay(100);
  sensorTests();
  delay(100);
    
}
void Stop(){
  analogWrite(northSouthMotorSpeed,0);
  analogWrite(eastWestMotorSpeed, 0);
}

void moveNorth(int Speed){
  analogWrite(northSouthMotorSpeed, Speed);
  digitalWrite(motorT1, LOW);
  digitalWrite(motorT2, HIGH);
  
}
void moveSouth(int Speed){
  analogWrite(northSouthMotorSpeed, Speed);
  digitalWrite(motorT1, HIGH);
  digitalWrite(motorT2, LOW);
}
void moveEast(int Speed){
  analogWrite(eastWestMotorSpeed, Speed);
  digitalWrite(motorT3, LOW);
  digitalWrite(motorT4, HIGH);
  
}
void moveWest(int Speed){
  analogWrite(eastWestMotorSpeed, Speed);
  digitalWrite(motorT3, HIGH);
  digitalWrite(motorT4, LOW);
}
 
