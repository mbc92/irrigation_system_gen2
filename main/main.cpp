#include <iostream>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "../components/handlers/http/httpHandler.hpp"

httpHandler handler(1234);
extern "C" void app_main(void)
{
    uint32_t ip = handler.getIpAddress();
    std::cout << "Hello World from C++ " << ip << '\n';
}