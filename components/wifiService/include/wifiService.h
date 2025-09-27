#pragma once

#include "esp_wifi.h"
#include "esp_log.h"

#include "freertos/event_groups.h"


/* The event group allows multiple bits for each event, but we only care about two events:
 * - we are connected to the AP with an IP
 * - we failed to connect after the maximum amount of retries 
*/


class WifiService
{
    public:
        WifiService();
        esp_err_t connect();
        uint32_t getIpAddress();
        EventGroupHandle_t& getWifiEventGroup();
        int& getRetryCount();
        void setIpAddr(esp_ip4_addr_t* ip);

     private:
        const char* _wifiSSID = "mcwifi2.4";
        const char* _wifiPass = "77470455588136770390";

        /* The event group allows multiple bits for each event, but we only care about two events:
        * - we are connected to the AP with an IP
        * - we failed to connect after the maximum amount of retries 
        */
        static constexpr uint8_t _wifiConnectedBit{0x00000001};
        static constexpr uint8_t _wifiFailBit{0x00000002};
        static constexpr uint8_t _maximumRetry{5u};


        char _ipAddr[40];
        const char *TAG = "WIFI HANDLER";
        int _retryNum = 0;
    
        /* FreeRTOS event group to signal when we are connected*/
        EventGroupHandle_t _wifiEventGroup;
    
        static void eventHandler(void* arg,esp_event_base_t event_base,
                            int32_t event_id, void* event_data);
};

inline EventGroupHandle_t& WifiService::getWifiEventGroup()
{
    return _wifiEventGroup;
}

inline int& WifiService::getRetryCount()
{
    return _retryNum;
}