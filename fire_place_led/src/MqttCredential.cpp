#include "..\MqttCredential.hpp"
#include <string.h>
#include <Arduino.h>


MqttMgrClass::MqttMgrClass(char ser[MAX_CHAR], int p , char uname[MAX_CHAR], char pass[MAX_CHAR]):client(EspClient) {

    memcpy(Mqttinfo.server, ser, sizeof(ser));
    Mqttinfo.port=p;
    memcpy(Mqttinfo.username, uname, sizeof(uname));
    memcpy(Mqttinfo.passwords, pass, sizeof(pass));

}

char_ptr MqttMgrClass::GetMqttServer() {
    
    return Mqttinfo.server;
}


char_ptr MqttMgrClass::GetMqttUsername(){

    return Mqttinfo.username;
}


char_ptr MqttMgrClass::GetMqttpasswords(){

    return Mqttinfo.passwords;
}


int MqttMgrClass::GetMqttPort(){

    return Mqttinfo.port;
}


void MqttMgrClass::SetMqttServer(char ser[MAX_CHAR]){

    memcpy(Mqttinfo.server, ser, sizeof(ser));
}


void MqttMgrClass::SetMqttUsername(char uname[MAX_CHAR]){

    memcpy(Mqttinfo.username, uname, sizeof(uname));
}


void MqttMgrClass::SetMqttPasswords(char pass[MAX_CHAR]){

    memcpy(Mqttinfo.passwords, pass, sizeof(pass));
}


void MqttMgrClass::SetMqttPort(int port){

    Mqttinfo.port=port;
}

void Callback(char* topic, byte* payload, unsigned int length)
{
    // mqtt_flat=true;
    // bool space_flat=false;
    // for (int i = 0; i <length; i++) {

    //     if((char)payload[i]==' ') {

    //         space_flat=true;
    //         break;

    //     }
    //     if(space_flat==false) {

    //         mqttCmd[i]=(char)payload[i];

    //     } else {

    //         mqttValue[i]=(char)payload[i];
    //     }
    // }

    // mqtt_flat=1;
}
bool MqttMgrClass::ConnectToMqtt(){

    if (WiFi.status() == WL_CONNECTED){

        client.setServer(Mqttinfo.server, Mqttinfo.port); //connect to server
        int timeCounter = 0;
        while (!client.connected()) {

            if(timeCounter>=TIMEOUT_LIMIT) {

                Serial.println("Unable to connect to wifi");
                return false;
            }
            timeCounter++;
            delay(1000);

        }

    } else {

        return false;
    }

}