#include <WiFi.h>
#include <PubSubClient.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "led.hpp"    
#include "MqttCredential.hpp"

//Wifi credential declaration 
const char* ssid = "NETGEAR44";
const char* password = "xuatcanh01";

//MQTT credential decleration
const char* mqttServer = "b37.mqtt.one";
const int mqttPort = 1883;
const char* mqttUser = "6ikpsw474";
const char* mqttPassword = "bchmpqtwyz";
char mqttCmd[50];
char mqttValue[50];
WiFiClient espClient;
PubSubClient client(espClient);


//other variable
bool mqtt_flat=false;
char* mqtt_topic;
int t=BLINK_TIME;





void setup() 
{
  // put your setup code here, to run once:
  pinMode(LED_RED,  OUTPUT);
  pinMode(LED_BLUE, OUTPUT);
  
  //set off state for all led
  digitalWrite(LED_RED, LOW);
  digitalWrite(LED_BLUE, LOW);
  //setup wifi
  WiFi.begin(ssid);
  int timeOut=0;
  while (WiFi.status() != WL_CONNECTED){
    if(timeOut>TIMEOUT_LIMIT)
    {
      break;
    }
    delay(1000);
    timeOut++;
  }
  timeOut=0;
  
  //Connect to MQTT
  client.setServer(mqttServer, mqttPort); //connect to server
  client.setCallback(callback);
  while (!client.connected()) 
  {
    if(timeOut>TIMEOUT_LIMIT)
    {
      Serial.println("Unable to connect to wifi");
      break;
    }
    timeOut++;
    delay(1000);
  }
  client.subscribe("6ikpsw474/Led");

} 

void loop() {
  client.loop();//start up MQTT LOOP
  if(mqtt_flat==false)
  {
    normalMode(BLINK_TIME);
  }
  else{
    normalMode(t);
    if(String(mqttCmd)=="WHITE")
    {
      digitalWrite(LED_RED, HIGH);
      digitalWrite(LED_BLUE, HIGH);
    }
    else if(String(mqttCmd)=="BLUE")
    {
      digitalWrite(LED_RED, LOW);
      digitalWrite(LED_BLUE, HIGH);
    }
    else if(String(mqttCmd)=="RED")
    {
      digitalWrite(LED_RED, HIGH);
      digitalWrite(LED_BLUE, LOW);
    }
    else if(String(mqttCmd)=="GREEN")
    {
      digitalWrite(LED_RED, LOW);
      digitalWrite(LED_BLUE, LOW);
    }
    else if(String(mqttCmd)=="NORMAL")
    {
      t= (int)mqttValue;
    }
  }

}
void normalMode(int t)
{
    // put your main code here, to run repeatedly:
    blink_red(t);
    blink_blue(t);
    blink_both(t);
    off_both(t);
}
/*
 * blink the red led
 * @t time in minisecond
 *  return nothing
 */
void blink_red(int t)
{
  digitalWrite(LED_RED, HIGH);
  delay(t);
  digitalWrite(LED_RED, LOW);
}

/*
 * blink the red blue
 * @t time in minisecond
 *  return nothing
 */
 void blink_blue(int t)
{
  digitalWrite(LED_BLUE, HIGH);
  delay(t);
  digitalWrite(LED_BLUE, LOW);
}
/*
 * blink the red and the blue
 * @t time in minisecond
 *  return nothing
 */
void blink_both(int t)
{
  digitalWrite(LED_RED, HIGH);
  digitalWrite(LED_BLUE, HIGH);
  delay(t);
  digitalWrite(LED_RED, LOW);
  digitalWrite(LED_BLUE, LOW);
}

void off_both(int t)
{  
  digitalWrite(LED_RED, LOW);
  digitalWrite(LED_BLUE, LOW);
  delay(t);
}

/*******************************************************************************
*************************************MQTTT CALL BACK FUNCTION*******************
********************************************************************************/
void callback(char* topic, byte* payload, unsigned int length)
{
  mqtt_flat=true;
  bool space_flat=false;
  for (int i = 0; i <length; i++) 
  {
    if((char)payload[i]==' ')
    {
      space_flat=true;
      break;
    }
    if(space_flat==false)
    {
      mqttCmd[i]=(char)payload[i];
    }
    else
    {
      mqttValue[i]=(char)payload[i];
    }
  }
  
  mqtt_flat=1;
  mqtt_topic=topic;
}
