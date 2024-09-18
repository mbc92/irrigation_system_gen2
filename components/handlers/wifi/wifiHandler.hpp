#pragma once

#include "esp_wifi.h"
#include "esp_log.h"
#include "lwip/err.h"
#include "lwip/sys.h"
#include "freertos/event_groups.h"
#include "config.h"

/* The event group allows multiple bits for each event, but we only care about two events:
 * - we are connected to the AP with an IP
 * - we failed to connect after the maximum amount of retries */
#define WIFI_CONNECTED_BIT BIT0
#define WIFI_FAIL_BIT      BIT1

/* Wifi credentials */
#define WIFI_SSID "mcwifi2.4"
#define WIFI_PASS "77470455588136770390"
#define MAXIMUM_RETRY  5

class wifiHandler{
    private:
    char m_ipAddr[40];
    const char *TAG = "WIFI HANDLER";
    int m_retryNum = 0;

    /* FreeRTOS event group to signal when we are connected*/
    EventGroupHandle_t m_wifiEventGroup;

    static void eventHandler(void* arg,esp_event_base_t event_base,
                            int32_t event_id, void* event_data);
    public:
    wifiHandler();
    esp_err_t connect();
    uint32_t getIpAddress();
    EventGroupHandle_t& getWifiEventGroup();
    int& getRetryCount();
    void setIpAddr(esp_ip4_addr_t* ip);
};

inline EventGroupHandle_t& wifiHandler::getWifiEventGroup()
{
    return m_wifiEventGroup;
}

inline int& wifiHandler::getRetryCount()
{
    return m_retryNum;
}