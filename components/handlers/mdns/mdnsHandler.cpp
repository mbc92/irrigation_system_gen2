#include "mdnsHandler.hpp"

mdnsHandler::mdnsHandler()
{
    mdnsFramework_init();
};

esp_err_t mdnsHandler::mdnsInit()
{
    return mdnsFramework_init();
};

esp_err_t mdnsHandler::queryService(const string service_name, const string proto)
{
    ESP_LOGI(this->m_tag.c_str(), "Querying for service: %s.%s", service_name.c_str(), proto.c_str());
        
    // Query the service
    mdns_result_t* results = nullptr;
    esp_err_t err = mdns_query_ptr(service_name.c_str(), proto.c_str(), 3000, 10, &results);
    
    if (err) {
        ESP_LOGE(this->m_tag.c_str(), "mDNS Query failed: %d", err);
        return err;
    }

    if (!results) {
        ESP_LOGI(this->m_tag.c_str(), "No results found, master node offline");
        return err;
    }

    return err;
}