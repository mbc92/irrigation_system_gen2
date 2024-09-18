#include <string>
#include "esp_log.h"
#include "mdns_framework/mdns.h"

using namespace std;

#define MASTER "_master"
#define PROTOCOL "_tcp"

class mdnsHandler {
static constexpr string m_tag{"mdnsHandler"};
static constexpr string m_masterLookup{"_master"};


public:
mdnsHandler();
esp_err_t mdnsInit();
esp_err_t queryService(const string service_name, const string proto);

};