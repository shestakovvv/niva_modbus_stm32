#include "niva_modbus_stm32_config.h"

static inline void modbus_gpio_on(GPIO_TypeDef* port, uint16_t pin) {
    // LL_GPIO_SetOutputPin(port, pin);
        port->BSRR = (uint32_t)pin;
}

static inline void modbus_gpio_off(GPIO_TypeDef* port, uint16_t pin) {
    // LL_GPIO_ResetOutputPin(port, pin);
        port->BSRR = ((uint32_t)pin << 16);
}

static inline void modbus_gpio_toggle(GPIO_TypeDef* port, uint16_t pin) {
    // LL_GPIO_TogglePin(port, pin);
        port->ODR ^= pin;
}