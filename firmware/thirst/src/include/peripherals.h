#ifndef PERIPHERALS_H
#define PERIPHERALS_H

// Enable/disable debug prints.
#define PERIPH_ENABLE_DEBUG 0

// RTC memory.
#define PERIPH_MEM_ADDR_RTC 0x40

// ADC.
#define PERIPH_ADC_SAMPLE_SIZE 8192

// UART.
#define PERIPH_UART_BIT_RATE (UART_CLK_FREQ / BIT_RATE_115200)

// GPIO.
#define PERIPH_GPIO_O_BIT_LED_BLUE     BIT2
#define PERIPH_GPIO_O_FUNC_LED_BLUE    FUNC_GPIO2
#define PERIPH_GPIO_O_LED_BLUE         PERIPHS_IO_MUX_GPIO2_U
#define PERIPH_GPIO_I_BIT_CONFIG_MODE  BIT0
#define PERIPH_GPIO_I_FUNC_CONFIG_MODE FUNC_GPIO0
#define PERIPH_GPIO_I_CONFIG_MODE      PERIPHS_IO_MUX_GPIO0_U
#define PERIPH_GPIO_O_BIT_SENSOR       BIT15
#define PERIPH_GPIO_O_FUNC_SENSOR      FUNC_GPIO15
#define PERIPH_GPIO_O_SENSOR           PERIPHS_IO_MUX_MTDO_U

void ICACHE_FLASH_ATTR
periph_sesnor_toggle(bool toggle);

void ICACHE_FLASH_ATTR
periph_led_blue_toggle(bool toggle);

uint32_t ICACHE_FLASH_ATTR
periph_read_adc(uint32_t adc_sample_size);

#endif // PERIPHERALS_H
