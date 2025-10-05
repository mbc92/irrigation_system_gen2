#pragma once

#include <string>
#include "esp_wifi.h"
#include "esp_log.h"
#include "freertos/event_groups.h"

#define WIFI_SSID "mcwifi2.4"
#define WIFI_PASS "77470455588136770390"

class WifiService{
    private:
    char m_ipAddr[40];
    const char *TAG = "WIFI HANDLER";
    int m_retryNum = 0;

    public:
    WifiService();
    //~WifiService();

    WifiService(WifiService&&) = delete;
    WifiService& operator=(WifiService&&) = delete;

    esp_err_t connect();
    uint32_t getIpAddress();
    EventGroupHandle_t& getWifiEventGroup();
    int& getRetryCount();
    void setIpAddr(esp_ip4_addr_t* ip);

    private:

    static void eventHandler(void* arg,esp_event_base_t event_base,
                            int32_t event_id, void* event_data);

    /* The event group allows multiple bits for each event, but we only care about two events:
    * - we are connected to the AP with an IP
    * - we failed to connect after the maximum amount of retries 
    */
    static constexpr uint8_t _wifiConnectedBit{BIT0};
    static constexpr uint8_t _wifiFailBit{BIT1};
    static constexpr uint8_t _maximumRetry{5u};
    EventGroupHandle_t _wifiEventGroup;
};

inline EventGroupHandle_t& WifiService::getWifiEventGroup()
{
    return _wifiEventGroup;
}

inline int& WifiService::getRetryCount()
{
    return m_retryNum;
}