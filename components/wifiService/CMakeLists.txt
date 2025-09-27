
set(WIFI_SERVICE_SOURCES
        src/wifiService.cpp
)

set(SOURCES ${WIFI_SERVICE_SOURCES})
idf_component_register(SRCS ${SOURCES}
                    INCLUDE_DIRS "." "include/"
                    REQUIRES esp_http_server esp_netif esp_wifi esp_timer esp_eth)