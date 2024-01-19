#pragma once

#include <stdint.h>

class httpHandler{
    private:
    uint32_t u32IpAddress{0u};

    public:
    httpHandler();
    httpHandler(const uint32_t ipAddress);
    uint32_t getIpAddress();
};