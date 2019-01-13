#include "Constants.hpp"

//Wifi credential constants
#define DEFAULT_SSID		"NETGEAR44"
#define DEFAULT_PASSWORDS 	"xuatcanh01"

/*this file is for wifi credential data stucture*/
typedef struct{

	char Ssid[MAX_CHAR];
	char Password[MAX_CHAR];

} WifiCred;

class WifiMgrClass {

public:
	WifiMgrClass(char id [MAX_CHAR]=DEFAULT_SSID, 
				char pass[MAX_CHAR] = DEFAULT_PASSWORDS );
	
	char_ptr GetSsid();
	char_ptr GetPassword();

	void SetSsid(char id [MAX_CHAR]);
	void SetPassword(char pass[MAX_CHAR]);

	bool SetupWifi();

private:
	WifiCred WifiInfo;

};

