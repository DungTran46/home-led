// MQTT data structure
#include "Constants.hpp"

#define DEFAULT_SERVER 		"m15.cloudmqtt.com"
#define DEFAULT_PORT		19296
#define DEFAULT_USERNAME	"csrqtrmh"
#define DEFAULT_PASSWORDS	"EWG6Ui9Di3o6"

struct MqttStuct {
	char	server[MAX_CHAR];
	int		port;
	char	username[MAX_CHAR];
	char	passwords[MAX_CHAR];
}

class MqttMgr {
	public:
		//Contructor
		MqttMgr(char ser[MAX_CHAR], 
				int p = DEFAULT_PORT, 
				char uname[MAX_CHAR] = DEFAULT_USERNAME, 
				char pass[MAX_CHAR] = DEFAULT_PASSWORDS);
		
		char_ptr getMqttServer();
		char_ptr getMqttUsername();
		char_ptr getMqttpasswords();
		int getMqttPort();
		
		void setMqttServer(char in[MAX_CHAR);
		void setMqttUsername(char in[MAX_CHAR]);
		void setMqttPasswords(char in[MAX_CHAR]);
		void setMqttPort(int);
		void connectToMqtt();
			
	private:
		MqttStruct MqttData;
		
}	