#include "nvmHandler.hpp"

nvmHandler::nvmHandler(){};

esp_err_t nvmHandler::nvmHandlerInit()
{
    //Initialize NVS
    esp_err_t tRetVal = nvs_flash_init();
        if (tRetVal == ESP_ERR_NVS_NO_FREE_PAGES || tRetVal == ESP_ERR_NVS_NEW_VERSION_FOUND) {
            ESP_ERROR_CHECK(nvs_flash_erase());
            tRetVal = nvs_flash_init();
        }
   return tRetVal;
}
 