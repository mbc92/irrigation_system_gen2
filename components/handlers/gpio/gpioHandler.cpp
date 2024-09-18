#include "gpioHandler.hpp"


gpioHandler::gpioHandler(){};

void gpioHandler::gpioTask(void* pvParameters)
{
    EventBits_t xEventGroupValue;

    /* Cast params to event group object*/
    EventGroupHandle_t gpioEventGroup = static_cast<EventGroupHandle_t>(pvParameters);

    while(1)
    {
        ESP_LOGI("GPIO", "gpioTask called");
        xEventGroupValue =  xEventGroupWaitBits(gpioEventGroup,
                                            BITS_TO_WAIT_FOR,
                                            pdTRUE,
                                            pdTRUE,
                                            portMAX_DELAY
                                            );

        /* Drive GPIO to enable pump */
        if((xEventGroupValue & PUMP_ENABLE) !=0)
        {   
            /* Dont want to make an object inside this static method, therefor calling ESP framework directly */
            gpio_set_level(PUMP_PIN, HIGH);
        } 
    }                                      
}

void gpioHandler::setDirection(gpio_num_t tenPin, gpio_mode_t tenPinMode)
{
    gpio_set_direction(tenPin, tenPinMode);   
}

void gpioHandler::write(gpio_num_t pin, bool value)
{
    gpio_set_level(pin, value ? 1 : 0);
}

bool gpioHandler::read(gpio_num_t pin)
{
    return gpio_get_level(pin) == 1;
}

void gpioHandler::init()
{
    // Create GPIO eventgroup with standard 8 BIT length
    this->m_gpioEventGroup = xEventGroupCreate();

    // Start freeRTOS task for GPIO service
    m_taskReturn = xTaskCreate(gpioTask, "GPIO", 2048, this->m_gpioEventGroup, 1, &m_taskHandle);

    // Set pin 33 ( pump ) as output
    setDirection(PUMP_PIN, GPIO_MODE_OUTPUT);
}