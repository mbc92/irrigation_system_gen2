#pragma once

#include <stdint.h>
#include <esp_http_server.h>

class httpHandler{
    private:
    uint32_t m_u32IpAddress{0u};
    httpd_handle_t m_tServerHandle;

    public:
    httpHandler();
    httpHandler(const uint32_t ipAddress);
    esp_err_t startWebServer(httpd_handle_t& tServerHandle);
    esp_err_t registerUriHandler(httpd_handle_t& handle, const httpd_uri_t& uriHandler);
    uint32_t getIpAddress();
    httpd_handle_t& getServerHandle();
};