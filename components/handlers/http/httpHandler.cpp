#include "httpHandler.hpp"

httpHandler::httpHandler(){};

httpHandler::httpHandler(const uint32_t Ipaddress)
    :m_u32IpAddress(Ipaddress){};

esp_err_t httpHandler::startWebServer(httpd_handle_t& tServerHandle)
{
    httpd_config_t config = HTTPD_DEFAULT_CONFIG();
    // Run HTTPD on core ONE
    config.core_id = 1;
    config.lru_purge_enable = true;

    /* Start httpd from ESP HTTP package*/
    return httpd_start(&tServerHandle, &config);
}

esp_err_t httpHandler::registerUriHandler(httpd_handle_t& handle, const httpd_uri_t& uriHandler)
{
    return httpd_register_uri_handler(handle, &uriHandler);
}

uint32_t httpHandler::getIpAddress()
{
    return m_u32IpAddress;
}

httpd_handle_t& httpHandler::getServerHandle()
{
    return m_tServerHandle;
}

