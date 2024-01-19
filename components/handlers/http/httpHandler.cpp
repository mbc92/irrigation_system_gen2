#include "httpHandler.hpp"

httpHandler::httpHandler(){};

httpHandler::httpHandler(const uint32_t Ipaddress)
    :u32IpAddress(Ipaddress){};

uint32_t httpHandler::getIpAddress()
{
    return u32IpAddress;
}

