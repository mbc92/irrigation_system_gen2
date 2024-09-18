#pragma once

#include "esp_event.h"
#include "esp_log.h"
#include "freertos/event_groups.h"
#include <driver/gpio.h>
#include "freertos/task.h"

/* Pump enable */
#define PUMP_ENABLE   (1UL << 0UL) // zero shift for bit0

/* Bits to define which task to enable */
#define TASK2_BIT     (1UL << 1UL) // 1 shift for flag  bit 1
#define TASK3_BIT     (1UL << 2UL) // 2 shift for flag bit 2

/* Simple High and Low logic define */
#define HIGH 1
#define LOW  0

/* Pump is connected to pin 33 */ 
#define PUMP_PIN GPIO_NUM_33

/* Eventgroup wait bits */
#define BITS_TO_WAIT_FOR (PUMP_ENABLE | TASK2_BIT | TASK3_BIT)

class gpioHandler{

private:
/* FreeRTOS event group to signal which GPIO to trigger */
EventGroupHandle_t m_gpioEventGroup;

/* GPIO task function */
static void gpioTask(void* pvParameters);

/* Return handle from RTOS task */
BaseType_t m_taskReturn;

/* Task handle */
TaskHandle_t m_taskHandle = NULL;

public:

/**
 * @brief Constructor for the GPIO Handler class.
 * 
 * Initializes the GPIO handler object. This may set default configurations 
 * or allocate necessary resources for GPIO handling.
 */
gpioHandler();

/**
 * @brief Initializes the GPIO handler.
 * 
 * This method sets up the necessary configurations to enable the GPIO operations.
 * It should be called before any GPIO operations are performed.
 */
void init();

/**
 * @brief Sets the direction of a specific GPIO pin.
 * 
 * @param tenPin The GPIO pin number.
 * @param tenPinMode The mode of the pin (input or output).
 * 
 */
void setDirection(gpio_num_t tenPin, gpio_mode_t tenPinMode);

/**
 * @brief Writes a value to a GPIO pin.
 * 
 * @param tenPinNUmber The GPIO pin number.
 * @param bValue The boolean value to write to the pin (true for HIGH, false for LOW).
 * 
 */
void write(gpio_num_t tenPinNUmber, bool bValue);

/**
 * @brief Reads the value of a GPIO pin.
 * 
 * @param tenPinNUmber The GPIO pin number.
 * @return true If the pin is HIGH.
 * @return false If the pin is LOW.
 * 
 */
bool read(gpio_num_t tenPinNUmber);

};