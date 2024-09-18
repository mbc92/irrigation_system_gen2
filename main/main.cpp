#include <iostream>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "nvs_flash.h"
#include "../components/handlers/http/httpHandler.hpp"
#include "../components/handlers/wifi/wifiHandler.hpp"
#include "../components/handlers/mdns/mdnsHandler.hpp"
#include "../components/handlers/nvm/nvmHandler.hpp"
#include "../components/handlers/gpio/gpioHandler.hpp"


#include "driver/uart.h"
#include "driver/gpio.h"
#include "sdkconfig.h"
#include "esp_log.h"

//httpHandler g_httpHandler(1234);
mdnsHandler g_mdnsHandler;
nvmHandler g_nvmHandler;
wifiHandler g_wifiHandler;
gpioHandler g_gpioHandler;


extern "C" void app_main(void)
{
    /* Initialize ESP netif */
    ESP_ERROR_CHECK(esp_netif_init()); 
    /* Initialize ESP32 NVM */
    ESP_ERROR_CHECK(g_nvmHandler.nvmHandlerInit());
    /* Send query for finding master service*/
    g_gpioHandler.init();
    /* Connect to the wifi network */ 
    ESP_ERROR_CHECK(g_wifiHandler.connect());
    /* Initialize MDNS framwork*/
    ESP_ERROR_CHECK(g_mdnsHandler.mdnsInit());
    /* Send query for finding master service*/
    ESP_ERROR_CHECK(g_mdnsHandler.queryService(MASTER, PROTOCOL));

}