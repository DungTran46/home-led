#include "..\WifiMgrClass.hpp"
#include <string.h>
#include <WiFi.h>
#include <Arduino.h>

WifiMgrClass::WifiMgrClass(char id[MAX_CHAR], char pass[MAX_CHAR]) {

    memcpy(WifiInfo.Ssid, id, sizeof(id));
    memcpy(WifiInfo.Password, pass, sizeof(pass));

}

char_ptr WifiMgrClass::GetSsid(){

    return WifiInfo.Ssid;

}
char_ptr WifiMgrClass::GetPassword(){

    return WifiInfo.Password;

}

void WifiMgrClass::SetSsid(char id [MAX_CHAR]){

    memcpy(WifiInfo.Ssid, id, sizeof(id));

}
void WifiMgrClass::SetPassword(char pass[MAX_CHAR]){

    memcpy(WifiInfo.Password, pass, sizeof(pass));

}

bool WifiMgrClass::SetupWifi(){

    WiFi.begin(WifiInfo.Ssid, WifiInfo.Password);
    int timeCounter=0;

    while (WiFi.status() != WL_CONNECTED) {

        if(timeCounter>=TIMEOUT_LIMIT)
        {
            return false;
        }
        delay(1000);
        timeCounter++;
    }

    return true;
}