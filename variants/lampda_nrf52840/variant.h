#ifndef _LAMPDA_NRF52840_H_
#define _LAMPDA_NRF52840_H_

#define TARGET_LAMPDA_NRF52840

/** Master clock frequency */
#define VARIANT_MCK (64000000ul)

//#define USE_LFXO  // Board uses 32khz crystal for LF
#define USE_LFRC    // Board uses RC for LF

/*----------------------------------------------------------------------------
 *        Headers
 *----------------------------------------------------------------------------*/

#include "WVariant.h"

#ifdef __cplusplus
extern "C" {
#endif  // __cplusplus

#define LAMPDA_FIRMWARE_VERSION_MAJOR 1
#define LAMPDA_FIRMWARE_VERSION_MINOR 4

#define ADC_RESOLUTION (12) // 12 bit ADC

#define PINS_COUNT (29)
#define NUM_DIGITAL_PINS (29)
#define NUM_ANALOG_INPUTS (3)
#define NUM_ANALOG_OUTPUTS (0)

/**
 * user available PIN/GPIO definitions
 */
static const uint8_t D0 = 0;
static const uint8_t D1 = 1;
static const uint8_t D2 = 2;
static const uint8_t D3 = 3;
static const uint8_t D4 = 4;
static const uint8_t D5 = 5;
static const uint8_t D6 = 6;
static const uint8_t D7 = 7;

// only the 3 last gpio can be analog pins
static const uint8_t AD0 = D5;
static const uint8_t AD1 = D6;
static const uint8_t AD2 = D7;

/**
 * internal PIN/GPIO definitions
 */

// inputs
#define I_IS_CHARGE_OK (8)       // goes to high if a good power source is at the charger input

// input interrupts
#define I_INT_PD_SIGNAL (9)         // signal low if the USB PD negociation component registers an event 
#define I_INT_USB_PROT_FAULT (10)   // signal low if the usb-c protection components registers an event
#define I_INT_VBUS_GATE_FAULT (11)  // signal low if the vbus gate registers an event
#define I_INT_CHARGE_PROC_HOT (12)  // signal low if the charger component registers an event 
#define I_INT_BLNC_ALERT (13)       // signal low if the balancer registers an event
#define I_INT_IMU_INT1 (14)         // signal high if a programmed IMU event occured
#define I_INT_IMU_INT2 (15)         // signal high if a programmed IMU event occured

// outputs
#define O_EN_EXT_PWR (16)   // set high to enable the power to the peripherals (3.3V)
#define O_EN_PDM_PWR (17)   // set high to power external microphone
#define O_VBUS_FRS (18)     // set the VBUS Fast role swap mode
#define O_VBUS_DIR (19)     // set VBUS direction (in or out)
// this pin should only be set high when batteries are present and stable
#define O_DIS_5V_VBUS (20)  // set high to disable the vbus 5V power converter (unused in hardware > 1.0)
#define O_ENABLE_OTG (21)   // enable the OTG signal

// the pins below should never be high at the same time !!!
#define O_VBUS_DISCHARGE (22)   // discharge VBUS
#define O_EN_VBUS_GATE (23)     // set high to close the VBUS gate (power will go to the charger) 
#define O_EN_OUTPUT_PWR (24)    // set to high to close the output power path (tied to VBUS)

// input/outputs
#define IO_I2C_SDA (25)   // i2C data
#define IO_I2C_SCL (26)   // i2c clock
#define IO_I2S_PDM_SDA (27)   // PDM microphone SDA
#define IO_I2S_PDM_SCL (28)   // PDM microphone clock


/**
 * END OF internal PIN/GPIO definitions
 */


// set global interfaces
#define SPI_INTERFACES_COUNT (0)
#define WIRE_INTERFACES_COUNT (1)

#define SDA_MASTER IO_I2C_SDA
#define SCL_MASTER IO_I2C_SCL
#define PIN_WIRE_SDA SDA_MASTER
#define PIN_WIRE_SCL SCL_MASTER
#define PIN_PDM_CLK IO_I2S_PDM_SCL
#define PIN_PDM_DIN IO_I2S_PDM_SDA
#define PIN_PDM_PWR O_EN_PDM_PWR

static const uint8_t SDA = PIN_WIRE_SDA;
static const uint8_t SCL = PIN_WIRE_SCL;

static const uint8_t SS = 7;

// On-board QSPI Flash
#define EXTERNAL_FLASH_DEVICES (P25Q16H)
#define EXTERNAL_FLASH_USE_QSPI


/**
 *      Compatibility declarations
 */

// LEDs (ignore all)
#define LED_BLUE (PINS_COUNT)  // No connection
#define PIN_LED (PINS_COUNT)
#define LED_BUILTIN  (PINS_COUNT)

#define LED_STATE_ON (1)  // State when LED is litted

// serial states
#define PIN_SERIAL1_RX (PINS_COUNT)
#define PIN_SERIAL1_TX (PINS_COUNT)


#ifdef __cplusplus
}
#endif

/*----------------------------------------------------------------------------
 *        Arduino objects - C++ only
 *----------------------------------------------------------------------------*/

#endif
