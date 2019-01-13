#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include <WiFi.h>
#include <PubSubClient.h>
#include "led.h"    
#include "MqttMgrClass.hpp"
#include "WifiMgrClass.hpp"

WifiMgrClass wifiManager;
MqttMgrClass mqttManager;

//other variable
bool mqtt_flat=false;
char* mqtt_topic;
int blink_time = DEFALT__BLINK_TIME;

void setup() {

    Serial.begin(115200);
    // put your setup code here, to run once:
    pinMode(LED_RED,  OUTPUT);
    pinMode(LED_BLUE, OUTPUT);

    //set off state for all led
    digitalWrite(LED_RED, LOW);
    digitalWrite(LED_BLUE, LOW);

    //setup wifi
    Serial.println("Connect to WIFI");

    Serial.print("SSID: ");
    Serial.println(wifiManager.GetSsid());

    Serial.print("PASSWORD: ");
    Serial.println(wifiManager.GetPassword());

    if(!wifiManager.SetupWifi()) {

        Serial.println(">>>>FAIL to connect to Wifi<<<<");
        Serial.println(">>>>IGNORE to setup to MQTT<<<<");
        return;
    }

    Serial.println("WIFI connect SUCCESSFULLY");

    //Connect to MQTT
    Serial.println("Connect to MQTT");

    Serial.print("SERVER");
    Serial.println(mqttManager.GetMqttServer());

    Serial.println("PORT");
    Serial.println(mqttManager.GetMqttPort());

    Serial.println("USERNAME");
    Serial.println(mqttManager.GetMqttUsername());

    Serial.println("PASSWORD");
    Serial.println(mqttManager.GetMqttpasswords());

    if(!mqttManager.ConnectToMqtt()) {

        Serial.println(">>>>FAIL to connect to MQTT SERVER<<<<");
        return;
    }

    Serial.println("MQTT SERVER connect SUCCESSFULLY");
    mqttManager.client.setCallback(callback);
    mqttManager.client.subscribe("6ikpsw474/Led");

} 

void loop() {
    mqttManager.client.loop();//start up MQTT LOOP
    if(mqtt_flat==false) {

        normalMode(DEFALT__BLINK_TIME);

    } else {
        blink_time=2000;
        normalMode(blink_time);
        // if(String(mqttCmd)=="WHITE")
        // {
        //     digitalWrite(LED_RED, HIGH);
        //     digitalWrite(LED_BLUE, HIGH);
        // }
        // else if(String(mqttCmd)=="BLUE")
        // {
        //     digitalWrite(LED_RED, LOW);
        //     digitalWrite(LED_BLUE, HIGH);
        // }
        // else if(String(mqttCmd)=="RED")
        // {
        //     digitalWrite(LED_RED, HIGH);
        //     digitalWrite(LED_BLUE, LOW);
        // }
        // else if(String(mqttCmd)=="GREEN")
        // {
        //     digitalWrite(LED_RED, LOW);
        //     digitalWrite(LED_BLUE, LOW);
        // }
        // else if(String(mqttCmd)=="NORMAL")
        // {
        //     t= (int)mqttValue;
        // }
    }

}

/*******************************************************************************
*************************************MQTTT CALL BACK FUNCTION*******************
********************************************************************************/
void callback(char* topic, byte* payload, unsigned int length)
{
    mqtt_flat=true;
    bool space_flat=false;
    Serial.println(topic);
    for (int i = 0; i <length; i++) {

        Serial.print(payload[i]);
        // if((char)payload[i]==' ')
        // {
        //     space_flat=true;
        //     break;
        // }
        // if(space_flat==false)
        // {
        //     mqttCmd[i]=(char)payload[i];
        // }
        // else
        // {
        //     mqttValue[i]=(char)payload[i];
        // }

    }

    Serial.println();
    mqtt_flat=1;
    mqtt_topic=topic;
}
