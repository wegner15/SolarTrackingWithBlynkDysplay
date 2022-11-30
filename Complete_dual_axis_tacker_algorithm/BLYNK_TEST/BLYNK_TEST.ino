/*************************************************************

  This is a simple demo of sending and receiving some data.
  Be sure to check out other examples!
 *************************************************************/

// Template ID, Device Name and Auth Token are provided by the Blynk.Cloud
// See the Device Info tab, or Template settings
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

// This function is called every time the Virtual Pin 0 state changes
BLYNK_WRITE(V0)
{
  // Set incoming value from pin V0 to a variable
//  int value = param.asInt();

  // Update state
//  Blynk.virtualWrite(V1, value);
}

// This function is called every time the device is connected to the Blynk.Cloud
BLYNK_CONNECTED()
{
  
}

// This function sends Arduino's uptime every second to Virtual Pin 2.
void  sendDataToBlynk()
{
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  current= random(0.1,10.2)+0.1;
  volts=random(11,24)+0.1;
  power=current*volts;
  Blynk.virtualWrite(V1,current);//current
  Blynk.virtualWrite(V2, volts);//volts
  Blynk.virtualWrite(V3, power);
}

void setup()
{
  // Debug console
  Serial.begin(115200);

  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);

  // Setup a function to be called every second
  timer.setInterval(1000L, sendDataToBlynk);
}

void loop()
{
  Blynk.run();
  timer.run();
  // You can inject your own code or combine it with other sketches.
  // Check other examples on how to communicate with Blynk. Remember
  // to avoid delay() function!
}
