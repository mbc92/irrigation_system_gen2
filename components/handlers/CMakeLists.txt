set(SOURCES "http/httpHandler.cpp" "wifi/wifiHandler.cpp" "gpio/gpioHandler.cpp" "mdns/mdnsHandler.cpp" "mdns/mdns_framework/mdns.c" "mdns/mdns_framework/mdns_networking.c" "nvm/nvmHandler.cpp")
idf_component_register(SRCS ${SOURCES}
                    INCLUDE_DIRS "."
                    REQUIRES esp_http_server esp_netif esp_wifi driver esp_timer esp_eth nvs_flash)