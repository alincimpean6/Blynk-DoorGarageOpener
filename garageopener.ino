#define BLYNK_TEMPLATE_ID "complete with your own"
#define BLYNK_DEVICE_NAME complete with your own"
#define BLYNK_AUTH_TOKEN complete with your own"

#include <SPI.h>
#include <Ethernet.h>
#include <BlynkSimpleEthernet.h>
#include <TimeLib.h>

char auth[] = BLYNK_AUTH_TOKEN;

const int REL_GARAJ = 5;
const int REL_POARTA = 8;
const int REL_USA = 7;
const int REL_HEATER = 9;

void setup() {
  Blynk.begin(auth);
  
  Blynk.virtualWrite(V7,0);
  Blynk.virtualWrite(V8,0);
  Blynk.virtualWrite(V5,0);  
  
  pinMode(REL_GARAJ, OUTPUT);
  digitalWrite(REL_GARAJ, HIGH);
  pinMode(REL_POARTA, OUTPUT);
  digitalWrite(REL_POARTA, HIGH);
  pinMode(REL_USA, OUTPUT);
  digitalWrite(REL_USA, HIGH);
  pinMode(REL_HEATER, OUTPUT);
  digitalWrite(REL_HEATER, HIGH);
}


BLYNK_WRITE(V5)
{
  if(param.asInt() == 1)
  {
    digitalWrite(REL_GARAJ, LOW);
    Blynk.virtualWrite(V5,1); 
    delay(300);
    digitalWrite(REL_GARAJ, HIGH);
    Blynk.virtualWrite(V5,0);
  }
}

BLYNK_WRITE(V8)
{
  if(param.asInt() == 1)
  {
    digitalWrite(REL_POARTA, LOW);
    Blynk.virtualWrite(V8,1); 
    delay(300);
    digitalWrite(REL_POARTA, HIGH);
    Blynk.virtualWrite(V8,0); 
  }
}

BLYNK_WRITE(V7)
{
  if(param.asInt() == 1)
  {
    digitalWrite(REL_USA, LOW);
    Blynk.virtualWrite(V7,1); 
    delay(300);
    digitalWrite(REL_USA, HIGH);
    Blynk.virtualWrite(V7,0); 
  }
}

void loop() {
  if (!Blynk.connected()) {
    Blynk.connect();
    Blynk.logEvent("connected");
  }
  Blynk.run();

  unsigned long currentTime = now();
  restartArduino(currentTime);
}

void restartArduino(unsigned long currentTime) {
  if (hour(currentTime) == 4 && minute(currentTime) == 30) {
  Blynk.logEvent("restart");
  ESP.restart();
  }
}