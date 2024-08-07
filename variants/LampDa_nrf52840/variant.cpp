#include "variant.h"

#include "nrf.h"
#include "wiring_constants.h"
#include "wiring_digital.h"

#define PINNUM(port, pin)    ((port)*32 + (pin))

const uint32_t g_ADigitalPinMap[] = {
    PINNUM(0, 28),  // AD0 is P0.28/AIN4
    PINNUM(0, 29),  // AD1 is P0.29/AIN5
    PINNUM(0, 3),   // AD2 is P0.03/AIN1
    PINNUM(0, 2),   // AD3 is P0.02/AIN0
    PINNUM(1, 13),  // D4 is P1.13
    PINNUM(1, 14),  // D5 is P1.14
    PINNUM(1, 10),  // D6 is P1.10
    PINNUM(1, 12),  // D7 is P1.12
    PINNUM(1, 11),  // D8 is P1.11

    PINNUM(0, 31),  // D9 is P0.31/AIN7: strip brightness

    PINNUM(0, 13),  // D10 is P0.13 (SCL: Data of the main I2C line)
    PINNUM(0, 15),  // D11 is P0.15 (SDA: Clock of the main I2C line)

    PINNUM(0, 14),  // D12 is P0.14 USB 3.3V pwr

    PINNUM(0, 30),  // D13 is P0.30/AIN6 : BAT21: battery level

    PINNUM(0, 12),  // D14 is P0.12, CH_OK
    PINNUM(0, 11),  // D15 is P0.11, EN_OTG
    PINNUM(1, 9),  // D16 is P1.09, PROC_HOT

    PINNUM(0, 17),  // D17 is P0.17, CH_INT

    // MIC
    PINNUM(0, 20),  // D18 is P0.20 (MIC_PWR)
    PINNUM(1, 0),  // D19 is P1.00 (PDM_CLK)
    PINNUM(0, 16),  // D20 is P0.16 (PDM_DATA)

    // LSM6DS3TR
    PINNUM(1, 8),  // D21 is P1.08 (IMU_PWR)
    PINNUM(0, 27),  // D22 is P0.27 (IMU_SDA)
    PINNUM(0, 7),   // D23 is P0.07 (IMU_SCL)
};

void initVariant() {
  pinMode(OUTPUT_VOLTAGE, INPUT);

  pinMode(USB_33V_PWR, OUTPUT);
  digitalWrite(USB_33V_PWR, HIGH);

  pinMode(OUT_BRIGHTNESS, OUTPUT);
  digitalWrite(OUT_BRIGHTNESS, LOW);

  pinMode(BAT21, INPUT);

  pinMode(CHARGE_OK, INPUT_PULLUP);
  pinMode(ENABLE_OTG, OUTPUT);
  pinMode(CHARGE_PROC_HOT, INPUT_PULLUP);

  digitalWrite(ENABLE_OTG, LOW);

  pinMode(CHARGE_INT, INPUT);
}
