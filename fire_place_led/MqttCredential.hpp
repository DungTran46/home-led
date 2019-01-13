// MQTT data structure and constants
#include "Constants.hpp"
#include <WiFi.h>
#include <PubSubClient.h>

#define DEFAULT_SERVER "m14.cloudmqtt.com"
#define DEFAULT_PORT 10472
#define DEFAULT_USERNAME "stbnyubs"
#define DEFAULT_PASSWORDS "m7dmso3dOAhI"

typedef struct {
	char	server[MAX_CHAR];
	int		port;
	char	username[MAX_CHAR];
	char	passwords[MAX_CHAR];
} MqttStruct;

class MqttMgrClass {
public:
	//Contructor
	MqttMgrClass(	char ser[MAX_CHAR]=DEFAULT_SERVER, 
					int p = DEFAULT_PORT, 
					char uname[MAX_CHAR] = DEFAULT_USERNAME, 
					char pass[MAX_CHAR] = DEFAULT_PASSWORDS);
	
	char_ptr GetMqttServer();
	char_ptr GetMqttUsername();
	char_ptr GetMqttpasswords();
	int GetMqttPort();
	
	void SetMqttServer(char in[MAX_CHAR]);
	void SetMqttUsername(char in[MAX_CHAR]);
	void SetMqttPasswords(char in[MAX_CHAR]);
	void SetMqttPort(int);
	bool ConnectToMqtt();

	PubSubClient client;

private:

	WiFiClient EspClient;
	MqttStruct Mqttinfo;
		
};