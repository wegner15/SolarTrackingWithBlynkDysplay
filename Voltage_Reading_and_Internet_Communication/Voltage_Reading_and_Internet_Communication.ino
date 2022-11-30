//sketch created by Akshay Joseph
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
//=====================================================================================================
#define BLYNK_TEMPLATE_ID "TMPLYbp8pjd3"
#define BLYNK_DEVICE_NAME "Solar Statistics"
#define BLYNK_AUTH_TOKEN "wmTePVbKu8hvVQc79Y5vsdwikqbpCexF"


// Comment this out to disable prints and save space
#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = BLYNK_AUTH_TOKEN;

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Charles.K";
char pass[] = "0798520081";

float current;
float volts;
float power;

BlynkTimer timer;
//=====================================================

void setup()
{

  lcd.begin();
  lcd.backlight();
  lcd.clear();

lcd.print("Connecting to ");
lcd.setCursor(0,1);
lcd.print(String(ssid));
   // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
  
  timer.setInterval(1000L, sendDataToBlynk);
   randomSeed(10);
  
}
float voltage() {
  float vOUT = 0.0;
  float vIN = 0.0;
  float R1 = 30000.0;
  float R2 = 7500.0;
  int value = 0;
  const int voltageSensor = A0;
  value = analogRead(voltageSensor);
  vOUT = (value * 3) / 1024.0;
  vIN = vOUT / (R2 / (R1 + R2));
  return vIN;

}
void displayOnLcd(String message, int cursoRow=0, int cursoColumn=0){
  lcd.setCursor(cursoRow,cursoColumn);
  lcd.print(message);
}

// This function sends Arduino's uptime every second to Virtual Pin 2.
void  sendDataToBlynk()
{
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  
  current= random(0.1,2)+0.1;
  volts=voltage();
  power=current*volts;
  lcd.clear();
  displayOnLcd("V:"+String(volts)+"V",0,0);
  displayOnLcd("I:"+String(current)+"A",8,0);
  displayOnLcd("Power:"+String(power)+"W",0,1);
  Blynk.virtualWrite(V1,current);//current
  Blynk.virtualWrite(V2, volts);//volts
  Blynk.virtualWrite(V3, power);
}


void loop()
{
   Blynk.run();
  timer.run();
  
}
