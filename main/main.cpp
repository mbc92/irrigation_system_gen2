#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include <dioFactory.h>


using namespace MCAL;

extern "C" void app_main(void)
{
   MCAL::Dio dio;
   uint32_t channel{0u};

   dio.ReadChannel(channel);
}