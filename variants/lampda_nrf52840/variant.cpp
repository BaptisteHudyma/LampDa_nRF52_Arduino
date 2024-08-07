#include "variant.h"

#include "nrf.h"
#include "wiring_constants.h"
#include "wiring_digital.h"

#define PINNUM(port, pin) ((port) * 32 + (pin))

const uint32_t g_ADigitalPinMap[] = {
    // gpio pins
    PINNUM(1, 2),  // D0 is P1.02
    PINNUM(1, 11), // D1 is P1.11
    PINNUM(0, 9),  // D2 is P0.09
    PINNUM(1, 15), // D3 is P1.15
    PINNUM(1, 13), // D4 is P1.13
    PINNUM(0, 29), // D5 is P0.29/AIN5
    PINNUM(0, 2),  // D6 is P0.02/AIN0
    PINNUM(0, 31), // D7 P0.31/is AIN7

    // inputs
    PINNUM(1, 6), // I_IS_CHARGE_OK is P1.06

    // input interrupts
    PINNUM(0, 14), // I_INT_PD_SIGNAL is P0.14
    PINNUM(0, 24), // I_INT_USB_PROT_FAULT is P0.24
    PINNUM(0, 11), // I_INT_VBUS_GATE_FAULT is P0.11
    PINNUM(0, 4),  // I_INT_CHARGE_PROC_HOT is P0.04/AIN2
    PINNUM(0, 0),  // I_INT_BLNC_ALERT is P0.00
    PINNUM(0, 26), // I_INT_IMU_INT1 is P0.26
    PINNUM(0, 1),  // I_INT_IMU_INT2 is P0.01

    // outputs
    PINNUM(1, 7),  // O_EN_EXT_PWR is P1.07
    PINNUM(0, 20), // O_EN_PDM_PWR is P0.20
    PINNUM(1, 9),  // O_VBUS_FRS is P1.09
    PINNUM(0, 8),  // O_VBUS_DIR is P0.08
    PINNUM(0, 25), // O_DIS_5V_VBUS is P0.25 (removed in hardware > 1.0)
    PINNUM(0, 6),  // O_ENABLE_OTG is P0.06
    PINNUM(1, 4),  // O_VBUS_DISCHARGE is P1.04
    PINNUM(0, 12), // O_EN_VBUS_GATE is P0.12
    PINNUM(0, 22), // O_EN_OUTPUT_PWR is P0.22

    // input/outputs
    PINNUM(0, 15), // IO_I2C_SDA is P0.15
    PINNUM(0, 13), // IO_I2C_SCL is P0.13
    PINNUM(0, 17), // IO_I2S_PDM_SDA is P0.17
    PINNUM(1, 0),  // IO_I2S_PDM_SCL is P1.00
};

void initVariant() {
  // gpios

  // inputs
  pinMode(I_IS_CHARGE_OK, INPUT);

  // input interrupts
  pinMode(I_INT_PD_SIGNAL, INPUT);              // no pullup, already on circuit
  pinMode(I_INT_USB_PROT_FAULT, INPUT);         // no pullup, already on circuit
  pinMode(I_INT_VBUS_GATE_FAULT, INPUT);        // no pullup, already on circuit
  pinMode(I_INT_CHARGE_PROC_HOT, INPUT);
  pinMode(I_INT_BLNC_ALERT, INPUT);
  pinMode(I_INT_IMU_INT1, INPUT);               // no pullups
  pinMode(I_INT_IMU_INT2, INPUT);               // no pullups

  // outputs
  pinMode(O_EN_EXT_PWR, OUTPUT);
  pinMode(O_EN_PDM_PWR, OUTPUT);
  pinMode(O_VBUS_FRS, OUTPUT);
  pinMode(O_VBUS_DIR, OUTPUT);
  pinMode(O_DIS_5V_VBUS, OUTPUT);               // removed in hardware > 1.0
  pinMode(O_ENABLE_OTG, OUTPUT);
  pinMode(O_VBUS_DISCHARGE, OUTPUT);
  pinMode(O_EN_VBUS_GATE, OUTPUT);
  pinMode(O_EN_OUTPUT_PWR, OUTPUT);

  // input/outputs

  // set base states
  digitalWrite(O_EN_EXT_PWR, LOW);    // disable all outputs
  digitalWrite(O_EN_PDM_PWR, LOW);    // disable all outputs
  digitalWrite(O_VBUS_FRS, LOW);      // disable all outputs
  digitalWrite(O_VBUS_DIR, LOW);      // disable all outputs
  digitalWrite(O_DIS_5V_VBUS, LOW);   // disable all outputs (removed in hardware > 1.0)
  digitalWrite(O_ENABLE_OTG, LOW);    // disable all outputs
  digitalWrite(O_VBUS_DISCHARGE, LOW);  // disable all outputs
  digitalWrite(O_EN_VBUS_GATE, LOW);  // disable all outputs
  digitalWrite(O_EN_OUTPUT_PWR, LOW); // disable all outputs
}
