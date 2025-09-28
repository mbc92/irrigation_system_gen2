#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include <mcalFactory.h>
#include <wifiService.h>


using namespace MCAL;

extern "C" void app_main(void)
{
    MCAL::Flash flash;
    flash.init();

    WifiService wifiService;

    wifiService.connect();
}