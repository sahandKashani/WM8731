/*
############
# WM8731.h #
############
Device            : WM8731 Audio CODEC
Author            : Sahand Kashani-Akhavan / Philémon Favrod
Revision          : 1.1
Modification date : 25/05/2015
*/

#ifndef WM8731_H
#define WM8731_H

#include <stdbool.h>
#include <stdint.h>

// Calculates log2 of a number. Attention: the number must be a power of 2
static uint16_t DE1_SOC_WM8731_log2(uint16_t power_of_2) {
    if      (power_of_2 == 0x0001) return 0;
    else if (power_of_2 == 0x0002) return 1;
    else if (power_of_2 == 0x0004) return 2;
    else if (power_of_2 == 0x0008) return 3;
    else if (power_of_2 == 0x0010) return 4;
    else if (power_of_2 == 0x0020) return 5;
    else if (power_of_2 == 0x0040) return 6;
    else if (power_of_2 == 0x0080) return 7;
    else if (power_of_2 == 0x0100) return 8;
    else if (power_of_2 == 0x0200) return 9;
    else if (power_of_2 == 0x0400) return 10;
    else if (power_of_2 == 0x0800) return 11;
    else if (power_of_2 == 0x1000) return 12;
    else if (power_of_2 == 0x2000) return 13;
    else if (power_of_2 == 0x4000) return 14;
    else                           return 15;
}

static uint16_t DE1_SOC_WM8731_shift_amount(uint16_t mask) {
    // (mask & -mask) clears all but the lowest bit of x
    return DE1_SOC_WM8731_log2(mask & (~mask + 1));
}

uint8_t DE1_SOC_WM8731_REG_ADDRESS(uint8_t addr, uint16_t data) {
    return (addr << 1) | ((data >> 8) & 0x1);
}

uint8_t DE1_SOC_WM8731_REG_DATA(uint16_t data) {
    return (data & 0xff);
}

static uint16_t DE1_SOC_WM8731_WRITE(uint16_t write_value, uint16_t mask) {
    return mask & (write_value << DE1_SOC_WM8731_shift_amount(mask));
}

#define DE1_SOC_WM8731_I2C_WRITE_ADDRESS                                                                                     (0x34)

#define DE1_SOC_WM8731_LEFT_LINE_IN_REG                                                                                      (0x00)
#define DE1_SOC_WM8731_LEFT_LINE_IN_REG_LINVOL_MASK                                                                          (0x001f)
#define DE1_SOC_WM8731_LEFT_LINE_IN_REG_LINMUTE_MASK                                                                         (0x0080)
#define DE1_SOC_WM8731_LEFT_LINE_IN_REG_LRINBOTH_MASK                                                                        (0x0100)
#define DE1_SOC_WM8731_LEFT_LINE_IN_REG_LINVOL_MIN                                                                           (0x0000)
#define DE1_SOC_WM8731_LEFT_LINE_IN_REG_LINVOL_MAX                                                                           (0x001f)
#define DE1_SOC_WM8731_LEFT_LINE_IN_REG_LINMUTE_ENABLE_MUTE                                                                  (0x0001)
#define DE1_SOC_WM8731_LEFT_LINE_IN_REG_LINMUTE_DISABLE_MUTE                                                                 (0x0000)
#define DE1_SOC_WM8731_LEFT_LINE_IN_REG_LRINBOTH_ENABLE_SIMULTANEOUS_LOAD                                                    (0x0001)
#define DE1_SOC_WM8731_LEFT_LINE_IN_REG_LRINBOTH_DISABLE_SIMULTANEOUS_LOAD                                                   (0x0000)
#define DE1_SOC_WM8731_LEFT_LINE_IN_REG_LINVOL_DEFAULT                                                                       (0x0017)
#define DE1_SOC_WM8731_LEFT_LINE_IN_REG_LINMUTE_DEFAULT                                                                      (DE1_SOC_WM8731_LEFT_LINE_IN_REG_LINMUTE_ENABLE_MUTE)
#define DE1_SOC_WM8731_LEFT_LINE_IN_REG_LRINBOTH_DEFAULT                                                                     (DE1_SOC_WM8731_LEFT_LINE_IN_REG_LRINBOTH_DISABLE_SIMULTANEOUS_LOAD)
#define DE1_SOC_WM8731_LEFT_LINE_IN_REG_LINVOL_WRITE(write_value)                                                            (DE1_SOC_WM8731_WRITE((write_value), DE1_SOC_WM8731_LEFT_LINE_IN_REG_LINVOL_MASK))
#define DE1_SOC_WM8731_LEFT_LINE_IN_REG_LINMUTE_WRITE(write_value)                                                           (DE1_SOC_WM8731_WRITE((write_value), DE1_SOC_WM8731_LEFT_LINE_IN_REG_LINMUTE_MASK))
#define DE1_SOC_WM8731_LEFT_LINE_IN_REG_LRINBOTH_WRITE(write_value)                                                          (DE1_SOC_WM8731_WRITE((write_value), DE1_SOC_WM8731_LEFT_LINE_IN_REG_LRINBOTH_MASK))

#define DE1_SOC_WM8731_RIGHT_LINE_IN_REG                                                                                     (0x01)
#define DE1_SOC_WM8731_RIGHT_LINE_IN_REG_RINVOL_MASK                                                                         (0x001f)
#define DE1_SOC_WM8731_RIGHT_LINE_IN_REG_RINMUTE_MASK                                                                        (0x0080)
#define DE1_SOC_WM8731_RIGHT_LINE_IN_REG_RLINBOTH_MASK                                                                       (0x0100)
#define DE1_SOC_WM8731_LEFT_LINE_IN_REG_RINVOL_MIN                                                                           (0x0000)
#define DE1_SOC_WM8731_LEFT_LINE_IN_REG_RINVOL_MAX                                                                           (0x001f)
#define DE1_SOC_WM8731_RIGHT_LINE_IN_REG_RINMUTE_ENABLE_MUTE                                                                 (0x0001)
#define DE1_SOC_WM8731_RIGHT_LINE_IN_REG_RINMUTE_DISABLE_MUTE                                                                (0x0000)
#define DE1_SOC_WM8731_RIGHT_LINE_IN_REG_RLINBOTH_ENABLE_SIMULTANEOUS_LOAD                                                   (0x0001)
#define DE1_SOC_WM8731_RIGHT_LINE_IN_REG_RLINBOTH_DISABLE_SIMULTANEOUS_LOAD                                                  (0x0000)
#define DE1_SOC_WM8731_RIGHT_LINE_IN_REG_RINVOL_DEFAULT                                                                      (0x0017)
#define DE1_SOC_WM8731_RIGHT_LINE_IN_REG_RINMUTE_DEFAULT                                                                     (DE1_SOC_WM8731_RIGHT_LINE_IN_REG_RINMUTE_ENABLE_MUTE)
#define DE1_SOC_WM8731_RIGHT_LINE_IN_REG_RLINBOTH_DEFAULT                                                                    (DE1_SOC_WM8731_RIGHT_LINE_IN_REG_RLINBOTH_DISABLE_SIMULTANEOUS_LOAD)
#define DE1_SOC_WM8731_RIGHT_LINE_IN_REG_RINVOL_WRITE(write_value)                                                           (DE1_SOC_WM8731_WRITE((write_value), DE1_SOC_WM8731_RIGHT_LINE_IN_REG_RINVOL_MASK))
#define DE1_SOC_WM8731_RIGHT_LINE_IN_REG_RINMUTE_WRITE(write_value)                                                          (DE1_SOC_WM8731_WRITE((write_value), DE1_SOC_WM8731_RIGHT_LINE_IN_REG_RINMUTE_MASK))
#define DE1_SOC_WM8731_RIGHT_LINE_IN_REG_RLINBOTH_WRITE(write_value)                                                         (DE1_SOC_WM8731_WRITE((write_value), DE1_SOC_WM8731_RIGHT_LINE_IN_REG_RLINBOTH_MASK))

#define DE1_SOC_WM8731_LEFT_HEADPHONE_OUT_REG                                                                                (0x02)
#define DE1_SOC_WM8731_LEFT_HEADPHONE_OUT_REG_LHPVOL_MASK                                                                    (0x007f)
#define DE1_SOC_WM8731_LEFT_HEADPHONE_OUT_REG_LZCEN_MASK                                                                     (0x0080)
#define DE1_SOC_WM8731_LEFT_HEADPHONE_OUT_REG_LRHPBOTH_MASK                                                                  (0x0100)
#define DE1_SOC_WM8731_LEFT_HEADPHONE_OUT_REG_LHPVOL_MIN                                                                     (0x002f)
#define DE1_SOC_WM8731_LEFT_HEADPHONE_OUT_REG_LHPVOL_MAX                                                                     (0x007f)
#define DE1_SOC_WM8731_LEFT_HEADPHONE_OUT_REG_LZCEN_ENABLE                                                                   (0x0001)
#define DE1_SOC_WM8731_LEFT_HEADPHONE_OUT_REG_LZCEN_DISABLE                                                                  (0x0000)
#define DE1_SOC_WM8731_LEFT_HEADPHONE_OUT_REG_LRHPBOTH_ENABLE_SIMULTANEOUS_LOAD                                              (0x0001)
#define DE1_SOC_WM8731_LEFT_HEADPHONE_OUT_REG_LRHPBOTH_DISABLE_SIMULTANEOUS_LOAD                                             (0x0000)
#define DE1_SOC_WM8731_LEFT_HEADPHONE_OUT_REG_LHPVOL_DEFAULT                                                                 (0x0079)
#define DE1_SOC_WM8731_LEFT_HEADPHONE_OUT_REG_LZCEN_DEFAULT                                                                  (DE1_SOC_WM8731_LEFT_HEADPHONE_OUT_REG_LZCEN_DISABLE)
#define DE1_SOC_WM8731_LEFT_HEADPHONE_OUT_REG_LRHPBOTH_DEFAULT                                                               (DE1_SOC_WM8731_LEFT_HEADPHONE_OUT_REG_LRHPBOTH_DISABLE_SIMULTANEOUS_LOAD)
#define DE1_SOC_WM8731_LEFT_HEADPHONE_OUT_REG_LHPVOL_WRITE(write_value)                                                      (DE1_SOC_WM8731_WRITE((write_value), DE1_SOC_WM8731_LEFT_HEADPHONE_OUT_REG_LHPVOL_MASK))
#define DE1_SOC_WM8731_LEFT_HEADPHONE_OUT_REG_LZCEN_WRITE(write_value)                                                       (DE1_SOC_WM8731_WRITE((write_value), DE1_SOC_WM8731_LEFT_HEADPHONE_OUT_REG_LZCEN_MASK))
#define DE1_SOC_WM8731_LEFT_HEADPHONE_OUT_REG_LRHPBOTH_WRITE(write_value)                                                    (DE1_SOC_WM8731_WRITE((write_value), DE1_SOC_WM8731_LEFT_HEADPHONE_OUT_REG_LRHPBOTH_MASK))

#define DE1_SOC_WM8731_RIGHT_HEADPHONE_OUT_REG                                                                               (0x03)
#define DE1_SOC_WM8731_RIGHT_HEADPHONE_OUT_REG_RHPVOL_MASK                                                                   (0x007f)
#define DE1_SOC_WM8731_RIGHT_HEADPHONE_OUT_REG_RZCEN_MASK                                                                    (0x0080)
#define DE1_SOC_WM8731_RIGHT_HEADPHONE_OUT_REG_RLHPBOTH_MASK                                                                 (0x0100)
#define DE1_SOC_WM8731_RIGHT_HEADPHONE_OUT_REG_RHPVOL_MIN                                                                    (0x002f)
#define DE1_SOC_WM8731_RIGHT_HEADPHONE_OUT_REG_RHPVOL_MAX                                                                    (0x007f)
#define DE1_SOC_WM8731_RIGHT_HEADPHONE_OUT_REG_RZCEN_ENABLE                                                                  (0x0001)
#define DE1_SOC_WM8731_RIGHT_HEADPHONE_OUT_REG_RZCEN_DISABLE                                                                 (0x0000)
#define DE1_SOC_WM8731_RIGHT_HEADPHONE_OUT_REG_RLHPBOTH_ENABLE_SIMULTANEOUS_LOAD                                             (0x0001)
#define DE1_SOC_WM8731_RIGHT_HEADPHONE_OUT_REG_RLHPBOTH_DISABLE_SIMULTANEOUS_LOAD                                            (0x0000)
#define DE1_SOC_WM8731_RIGHT_HEADPHONE_OUT_REG_RHPVOL_DEFAULT                                                                (0x0079)
#define DE1_SOC_WM8731_RIGHT_HEADPHONE_OUT_REG_RZCEN_DEFAULT                                                                 (DE1_SOC_WM8731_RIGHT_HEADPHONE_OUT_REG_RZCEN_DISABLE)
#define DE1_SOC_WM8731_RIGHT_HEADPHONE_OUT_REG_RLHPBOTH_DEFAULT                                                              (DE1_SOC_WM8731_RIGHT_HEADPHONE_OUT_REG_RLHPBOTH_DISABLE_SIMULTANEOUS_LOAD)
#define DE1_SOC_WM8731_RIGHT_HEADPHONE_OUT_REG_RHPVOL_WRITE(write_value)                                                     (DE1_SOC_WM8731_WRITE((write_value), DE1_SOC_WM8731_RIGHT_HEADPHONE_OUT_REG_RHPVOL_MASK))
#define DE1_SOC_WM8731_RIGHT_HEADPHONE_OUT_REG_RZCEN_WRITE(write_value)                                                      (DE1_SOC_WM8731_WRITE((write_value), DE1_SOC_WM8731_RIGHT_HEADPHONE_OUT_REG_RZCEN_MASK))
#define DE1_SOC_WM8731_RIGHT_HEADPHONE_OUT_REG_RLHPBOTH_WRITE(write_value)                                                   (DE1_SOC_WM8731_WRITE((write_value), DE1_SOC_WM8731_RIGHT_HEADPHONE_OUT_REG_RLHPBOTH_MASK))

#define DE1_SOC_WM8731_ANALOGUE_AUDIO_PATH_CONTROL_REG                                                                       (0x04)
#define DE1_SOC_WM8731_ANALOGUE_AUDIO_PATH_CONTROL_REG_MICBOOST_MASK                                                         (0x0001)
#define DE1_SOC_WM8731_ANALOGUE_AUDIO_PATH_CONTROL_REG_MUTEMIC_MASK                                                          (0x0002)
#define DE1_SOC_WM8731_ANALOGUE_AUDIO_PATH_CONTROL_REG_INSEL_MASK                                                            (0x0004)
#define DE1_SOC_WM8731_ANALOGUE_AUDIO_PATH_CONTROL_REG_BYPASS_MASK                                                           (0x0008)
#define DE1_SOC_WM8731_ANALOGUE_AUDIO_PATH_CONTROL_REG_DACSEL_MASK                                                           (0x0010)
#define DE1_SOC_WM8731_ANALOGUE_AUDIO_PATH_CONTROL_REG_SIDETONE_MASK                                                         (0x0020)
#define DE1_SOC_WM8731_ANALOGUE_AUDIO_PATH_CONTROL_REG_SIDEATT_MASK                                                          (0x00c0)
#define DE1_SOC_WM8731_ANALOGUE_AUDIO_PATH_CONTROL_REG_MICBOOST_ENABLE                                                       (0x0001)
#define DE1_SOC_WM8731_ANALOGUE_AUDIO_PATH_CONTROL_REG_MICBOOST_DISABLE                                                      (0x0000)
#define DE1_SOC_WM8731_ANALOGUE_AUDIO_PATH_CONTROL_REG_MUTEMIC_ENABLE                                                        (0x0001)
#define DE1_SOC_WM8731_ANALOGUE_AUDIO_PATH_CONTROL_REG_MUTEMIC_DISABLE                                                       (0x0000)
#define DE1_SOC_WM8731_ANALOGUE_AUDIO_PATH_CONTROL_REG_INSEL_MICROPHONE_INPUT                                                (0x0001)
#define DE1_SOC_WM8731_ANALOGUE_AUDIO_PATH_CONTROL_REG_INSEL_LINE_INPUT                                                      (0x0000)
#define DE1_SOC_WM8731_ANALOGUE_AUDIO_PATH_CONTROL_REG_BYPASS_ENABLE                                                         (0x0001)
#define DE1_SOC_WM8731_ANALOGUE_AUDIO_PATH_CONTROL_REG_BYPASS_DISABLE                                                        (0x0000)
#define DE1_SOC_WM8731_ANALOGUE_AUDIO_PATH_CONTROL_REG_DACSEL_SELECT_DAC                                                     (0x0001)
#define DE1_SOC_WM8731_ANALOGUE_AUDIO_PATH_CONTROL_REG_DACSEL_NO_SELECT_DAC                                                  (0x0000)
#define DE1_SOC_WM8731_ANALOGUE_AUDIO_PATH_CONTROL_REG_SIDETONE_ENABLE                                                       (0x0001)
#define DE1_SOC_WM8731_ANALOGUE_AUDIO_PATH_CONTROL_REG_SIDETONE_DISABLE                                                      (0x0000)
#define DE1_SOC_WM8731_ANALOGUE_AUDIO_PATH_CONTROL_REG_SIDEATT_MINUS_15_DB                                                   (0x0003)
#define DE1_SOC_WM8731_ANALOGUE_AUDIO_PATH_CONTROL_REG_SIDEATT_MINUS_12_DB                                                   (0x0002)
#define DE1_SOC_WM8731_ANALOGUE_AUDIO_PATH_CONTROL_REG_SIDEATT_MINUS_9_DB                                                    (0x0001)
#define DE1_SOC_WM8731_ANALOGUE_AUDIO_PATH_CONTROL_REG_SIDEATT_MINUS_6_DB                                                    (0x0000)
#define DE1_SOC_WM8731_ANALOGUE_AUDIO_PATH_CONTROL_REG_MICBOOST_DEFAULT                                                      (DE1_SOC_WM8731_ANALOGUE_AUDIO_PATH_CONTROL_REG_MICBOOST_DISABLE)
#define DE1_SOC_WM8731_ANALOGUE_AUDIO_PATH_CONTROL_REG_MUTEMIC_DEFAULT                                                       (DE1_SOC_WM8731_ANALOGUE_AUDIO_PATH_CONTROL_REG_MUTEMIC_ENABLE)
#define DE1_SOC_WM8731_ANALOGUE_AUDIO_PATH_CONTROL_REG_INSEL_DEFAULT                                                         (DE1_SOC_WM8731_ANALOGUE_AUDIO_PATH_CONTROL_REG_INSEL_LINE_INPUT)
#define DE1_SOC_WM8731_ANALOGUE_AUDIO_PATH_CONTROL_REG_BYPASS_DEFAULT                                                        (DE1_SOC_WM8731_ANALOGUE_AUDIO_PATH_CONTROL_REG_BYPASS_ENABLE)
#define DE1_SOC_WM8731_ANALOGUE_AUDIO_PATH_CONTROL_REG_DACSEL_DEFAULT                                                        (DE1_SOC_WM8731_ANALOGUE_AUDIO_PATH_CONTROL_REG_DACSEL_NO_SELECT_DAC)
#define DE1_SOC_WM8731_ANALOGUE_AUDIO_PATH_CONTROL_REG_SIDETONE_DEFAULT                                                      (DE1_SOC_WM8731_ANALOGUE_AUDIO_PATH_CONTROL_REG_SIDETONE_DISABLE)
#define DE1_SOC_WM8731_ANALOGUE_AUDIO_PATH_CONTROL_REG_SIDEATT_DEFAULT                                                       (DE1_SOC_WM8731_ANALOGUE_AUDIO_PATH_CONTROL_REG_SIDEATT_MINUS_6_DB)
#define DE1_SOC_WM8731_ANALOGUE_AUDIO_PATH_CONTROL_REG_MICBOOST_WRITE(write_value)                                           (DE1_SOC_WM8731_WRITE((write_value), DE1_SOC_WM8731_ANALOGUE_AUDIO_PATH_CONTROL_REG_MICBOOST_MASK))
#define DE1_SOC_WM8731_ANALOGUE_AUDIO_PATH_CONTROL_REG_MUTEMIC_WRITE(write_value)                                            (DE1_SOC_WM8731_WRITE((write_value), DE1_SOC_WM8731_ANALOGUE_AUDIO_PATH_CONTROL_REG_MUTEMIC_MASK))
#define DE1_SOC_WM8731_ANALOGUE_AUDIO_PATH_CONTROL_REG_INSEL_WRITE(write_value)                                              (DE1_SOC_WM8731_WRITE((write_value), DE1_SOC_WM8731_ANALOGUE_AUDIO_PATH_CONTROL_REG_INSEL_MASK))
#define DE1_SOC_WM8731_ANALOGUE_AUDIO_PATH_CONTROL_REG_BYPASS_WRITE(write_value)                                             (DE1_SOC_WM8731_WRITE((write_value), DE1_SOC_WM8731_ANALOGUE_AUDIO_PATH_CONTROL_REG_BYPASS_MASK))
#define DE1_SOC_WM8731_ANALOGUE_AUDIO_PATH_CONTROL_REG_DACSEL_WRITE(write_value)                                             (DE1_SOC_WM8731_WRITE((write_value), DE1_SOC_WM8731_ANALOGUE_AUDIO_PATH_CONTROL_REG_DACSEL_MASK))
#define DE1_SOC_WM8731_ANALOGUE_AUDIO_PATH_CONTROL_REG_SIDETONE_WRITE(write_value)                                           (DE1_SOC_WM8731_WRITE((write_value), DE1_SOC_WM8731_ANALOGUE_AUDIO_PATH_CONTROL_REG_SIDETONE_MASK))
#define DE1_SOC_WM8731_ANALOGUE_AUDIO_PATH_CONTROL_REG_SIDEATT_WRITE(write_value)                                            (DE1_SOC_WM8731_WRITE((write_value), DE1_SOC_WM8731_ANALOGUE_AUDIO_PATH_CONTROL_REG_SIDEATT_MASK))

#define DE1_SOC_WM8731_DIGITAL_AUDIO_PATH_CONTROL_REG                                                                        (0x05)
#define DE1_SOC_WM8731_DIGITAL_AUDIO_PATH_CONTROL_REG_ADCHPD_MASK                                                            (0x0001)
#define DE1_SOC_WM8731_DIGITAL_AUDIO_PATH_CONTROL_REG_DEEMP_MASK                                                             (0x0006)
#define DE1_SOC_WM8731_DIGITAL_AUDIO_PATH_CONTROL_REG_DACMU_MASK                                                             (0x0008)
#define DE1_SOC_WM8731_DIGITAL_AUDIO_PATH_CONTROL_REG_HPOR_MASK                                                              (0x0010)
#define DE1_SOC_WM8731_DIGITAL_AUDIO_PATH_CONTROL_REG_ADCHPD_DISABLE                                                         (0x0001)
#define DE1_SOC_WM8731_DIGITAL_AUDIO_PATH_CONTROL_REG_ADCHPD_ENABLE                                                          (0x0000)
#define DE1_SOC_WM8731_DIGITAL_AUDIO_PATH_CONTROL_REG_DEEMP_48_KHZ                                                           (0x0003)
#define DE1_SOC_WM8731_DIGITAL_AUDIO_PATH_CONTROL_REG_DEEMP_44_1_KHZ                                                         (0x0002)
#define DE1_SOC_WM8731_DIGITAL_AUDIO_PATH_CONTROL_REG_DEEMP_32_KHZ                                                           (0x0001)
#define DE1_SOC_WM8731_DIGITAL_AUDIO_PATH_CONTROL_REG_DEEMP_DISABLE                                                          (0x0000)
#define DE1_SOC_WM8731_DIGITAL_AUDIO_PATH_CONTROL_REG_DACMU_ENABLE_SOFT_MUTE                                                 (0x0001)
#define DE1_SOC_WM8731_DIGITAL_AUDIO_PATH_CONTROL_REG_DACMU_DISABLE_SOFT_MUTE                                                (0x0000)
#define DE1_SOC_WM8731_DIGITAL_AUDIO_PATH_CONTROL_REG_HPOR_STORE_OFFSET                                                      (0x0001)
#define DE1_SOC_WM8731_DIGITAL_AUDIO_PATH_CONTROL_REG_HPOR_CLEAR_OFFSET                                                      (0x0000)
#define DE1_SOC_WM8731_DIGITAL_AUDIO_PATH_CONTROL_REG_ADCHPD_DEFAULT                                                         (DE1_SOC_WM8731_DIGITAL_AUDIO_PATH_CONTROL_REG_ADCHPD_ENABLE)
#define DE1_SOC_WM8731_DIGITAL_AUDIO_PATH_CONTROL_REG_DEEMP_DEFAULT                                                          (DE1_SOC_WM8731_DIGITAL_AUDIO_PATH_CONTROL_REG_DEEMP_DISABLE)
#define DE1_SOC_WM8731_DIGITAL_AUDIO_PATH_CONTROL_REG_DACMU_DEFAULT                                                          (DE1_SOC_WM8731_DIGITAL_AUDIO_PATH_CONTROL_REG_DACMU_ENABLE_SOFT_MUTE)
#define DE1_SOC_WM8731_DIGITAL_AUDIO_PATH_CONTROL_REG_HPOR_DEFAULT                                                           (DE1_SOC_WM8731_DIGITAL_AUDIO_PATH_CONTROL_REG_HPOR_CLEAR_OFFSET)
#define DE1_SOC_WM8731_DIGITAL_AUDIO_PATH_CONTROL_REG_ADCHPD_WRITE(write_value)                                              (DE1_SOC_WM8731_WRITE((write_value), DE1_SOC_WM8731_DIGITAL_AUDIO_PATH_CONTROL_REG_ADCHPD_MASK))
#define DE1_SOC_WM8731_DIGITAL_AUDIO_PATH_CONTROL_REG_DEEMP_WRITE(write_value)                                               (DE1_SOC_WM8731_WRITE((write_value), DE1_SOC_WM8731_DIGITAL_AUDIO_PATH_CONTROL_REG_DEEMP_MASK))
#define DE1_SOC_WM8731_DIGITAL_AUDIO_PATH_CONTROL_REG_DACMU_WRITE(write_value)                                               (DE1_SOC_WM8731_WRITE((write_value), DE1_SOC_WM8731_DIGITAL_AUDIO_PATH_CONTROL_REG_DACMU_MASK))
#define DE1_SOC_WM8731_DIGITAL_AUDIO_PATH_CONTROL_REG_HPOR_WRITE(write_value)                                                (DE1_SOC_WM8731_WRITE((write_value), DE1_SOC_WM8731_DIGITAL_AUDIO_PATH_CONTROL_REG_HPOR_MASK))

#define DE1_SOC_WM8731_POWER_DOWN_CONTROL_REG                                                                                (0x06)
#define DE1_SOC_WM8731_POWER_DOWN_CONTROL_REG_LINEINPD_MASK                                                                  (0x0001)
#define DE1_SOC_WM8731_POWER_DOWN_CONTROL_REG_MICPD_MASK                                                                     (0x0002)
#define DE1_SOC_WM8731_POWER_DOWN_CONTROL_REG_ADCPD_MASK                                                                     (0x0004)
#define DE1_SOC_WM8731_POWER_DOWN_CONTROL_REG_DACPD_MASK                                                                     (0x0008)
#define DE1_SOC_WM8731_POWER_DOWN_CONTROL_REG_OUTPD_MASK                                                                     (0x0010)
#define DE1_SOC_WM8731_POWER_DOWN_CONTROL_REG_OSCPD_MASK                                                                     (0x0020)
#define DE1_SOC_WM8731_POWER_DOWN_CONTROL_REG_CLKOUTPD_MASK                                                                  (0x0040)
#define DE1_SOC_WM8731_POWER_DOWN_CONTROL_REG_POWEROFF_MASK                                                                  (0x0080)
#define DE1_SOC_WM8731_POWER_DOWN_CONTROL_REG_LINEINPD_ENABLE_POWER_DOWN                                                     (0x0001)
#define DE1_SOC_WM8731_POWER_DOWN_CONTROL_REG_LINEINPD_DISABLE_POWER_DOWN                                                    (0x0000)
#define DE1_SOC_WM8731_POWER_DOWN_CONTROL_REG_MICPD_ENABLE_POWER_DOWN                                                        (0x0001)
#define DE1_SOC_WM8731_POWER_DOWN_CONTROL_REG_MICPD_DISABLE_POWER_DOWN                                                       (0x0000)
#define DE1_SOC_WM8731_POWER_DOWN_CONTROL_REG_ADCPD_ENABLE_POWER_DOWN                                                        (0x0001)
#define DE1_SOC_WM8731_POWER_DOWN_CONTROL_REG_ADCPD_DISABLE_POWER_DOWN                                                       (0x0000)
#define DE1_SOC_WM8731_POWER_DOWN_CONTROL_REG_DACPD_ENABLE_POWER_DOWN                                                        (0x0001)
#define DE1_SOC_WM8731_POWER_DOWN_CONTROL_REG_DACPD_DISABLE_POWER_DOWN                                                       (0x0000)
#define DE1_SOC_WM8731_POWER_DOWN_CONTROL_REG_OUTPD_ENABLE_POWER_DOWN                                                        (0x0001)
#define DE1_SOC_WM8731_POWER_DOWN_CONTROL_REG_OUTPD_DISABLE_POWER_DOWN                                                       (0x0000)
#define DE1_SOC_WM8731_POWER_DOWN_CONTROL_REG_OSCPD_ENABLE_POWER_DOWN                                                        (0x0001)
#define DE1_SOC_WM8731_POWER_DOWN_CONTROL_REG_OSCPD_DISABLE_POWER_DOWN                                                       (0x0000)
#define DE1_SOC_WM8731_POWER_DOWN_CONTROL_REG_CLKOUTPD_ENABLE_POWER_DOWN                                                     (0x0001)
#define DE1_SOC_WM8731_POWER_DOWN_CONTROL_REG_CLKOUTPD_DISABLE_POWER_DOWN                                                    (0x0000)
#define DE1_SOC_WM8731_POWER_DOWN_CONTROL_REG_POWEROFF_ENABLE_POWEROFF                                                       (0x0001)
#define DE1_SOC_WM8731_POWER_DOWN_CONTROL_REG_POWEROFF_DISABLE_POWEROFF                                                      (0x0000)
#define DE1_SOC_WM8731_POWER_DOWN_CONTROL_REG_LINEINPD_DEFAULT                                                               (DE1_SOC_WM8731_POWER_DOWN_CONTROL_REG_LINEINPD_ENABLE_POWER_DOWN)
#define DE1_SOC_WM8731_POWER_DOWN_CONTROL_REG_MICPD_DEFAULT                                                                  (DE1_SOC_WM8731_POWER_DOWN_CONTROL_REG_MICPD_ENABLE_POWER_DOWN)
#define DE1_SOC_WM8731_POWER_DOWN_CONTROL_REG_ADCPD_DEFAULT                                                                  (DE1_SOC_WM8731_POWER_DOWN_CONTROL_REG_ADCPD_ENABLE_POWER_DOWN)
#define DE1_SOC_WM8731_POWER_DOWN_CONTROL_REG_DACPD_DEFAULT                                                                  (DE1_SOC_WM8731_POWER_DOWN_CONTROL_REG_DACPD_ENABLE_POWER_DOWN)
#define DE1_SOC_WM8731_POWER_DOWN_CONTROL_REG_OUTPD_DEFAULT                                                                  (DE1_SOC_WM8731_POWER_DOWN_CONTROL_REG_OUTPD_ENABLE_POWER_DOWN)
#define DE1_SOC_WM8731_POWER_DOWN_CONTROL_REG_OSCPD_DEFAULT                                                                  (DE1_SOC_WM8731_POWER_DOWN_CONTROL_REG_OSCPD_DISABLE_POWER_DOWN)
#define DE1_SOC_WM8731_POWER_DOWN_CONTROL_REG_CLKOUTPD_DEFAULT                                                               (DE1_SOC_WM8731_POWER_DOWN_CONTROL_REG_CLKOUTPD_DISABLE_POWER_DOWN)
#define DE1_SOC_WM8731_POWER_DOWN_CONTROL_REG_POWEROFF_DEFAULT                                                               (DE1_SOC_WM8731_POWER_DOWN_CONTROL_REG_POWEROFF_ENABLE_POWEROFF)
#define DE1_SOC_WM8731_POWER_DOWN_CONTROL_REG_LINEINPD_WRITE(write_value)                                                    (DE1_SOC_WM8731_WRITE((write_value), DE1_SOC_WM8731_POWER_DOWN_CONTROL_REG_LINEINPD_MASK))
#define DE1_SOC_WM8731_POWER_DOWN_CONTROL_REG_MICPD_WRITE(write_value)                                                       (DE1_SOC_WM8731_WRITE((write_value), DE1_SOC_WM8731_POWER_DOWN_CONTROL_REG_MICPD_MASK))
#define DE1_SOC_WM8731_POWER_DOWN_CONTROL_REG_ADCPD_WRITE(write_value)                                                       (DE1_SOC_WM8731_WRITE((write_value), DE1_SOC_WM8731_POWER_DOWN_CONTROL_REG_ADCPD_MASK))
#define DE1_SOC_WM8731_POWER_DOWN_CONTROL_REG_DACPD_WRITE(write_value)                                                       (DE1_SOC_WM8731_WRITE((write_value), DE1_SOC_WM8731_POWER_DOWN_CONTROL_REG_DACPD_MASK))
#define DE1_SOC_WM8731_POWER_DOWN_CONTROL_REG_OUTPD_WRITE(write_value)                                                       (DE1_SOC_WM8731_WRITE((write_value), DE1_SOC_WM8731_POWER_DOWN_CONTROL_REG_OUTPD_MASK))
#define DE1_SOC_WM8731_POWER_DOWN_CONTROL_REG_OSCPD_WRITE(write_value)                                                       (DE1_SOC_WM8731_WRITE((write_value), DE1_SOC_WM8731_POWER_DOWN_CONTROL_REG_OSCPD_MASK))
#define DE1_SOC_WM8731_POWER_DOWN_CONTROL_REG_CLKOUTPD_WRITE(write_value)                                                    (DE1_SOC_WM8731_WRITE((write_value), DE1_SOC_WM8731_POWER_DOWN_CONTROL_REG_CLKOUTPD_MASK))
#define DE1_SOC_WM8731_POWER_DOWN_CONTROL_REG_POWEROFF_WRITE(write_value)                                                    (DE1_SOC_WM8731_WRITE((write_value), DE1_SOC_WM8731_POWER_DOWN_CONTROL_REG_POWEROFF_MASK))

#define DE1_SOC_WM8731_DIGITAL_AUDIO_INTERFACE_FORMAT_REG                                                                    (0x07)
#define DE1_SOC_WM8731_DIGITAL_AUDIO_INTERFACE_FORMAT_REG_FORMAT_MASK                                                        (0x0003)
#define DE1_SOC_WM8731_DIGITAL_AUDIO_INTERFACE_FORMAT_REG_IWL_MASK                                                           (0x000c)
#define DE1_SOC_WM8731_DIGITAL_AUDIO_INTERFACE_FORMAT_REG_LRP_MASK                                                           (0x0010)
#define DE1_SOC_WM8731_DIGITAL_AUDIO_INTERFACE_FORMAT_REG_LRSWAP_MASK                                                        (0x0020)
#define DE1_SOC_WM8731_DIGITAL_AUDIO_INTERFACE_FORMAT_REG_MS_MASK                                                            (0x0040)
#define DE1_SOC_WM8731_DIGITAL_AUDIO_INTERFACE_FORMAT_REG_BCLKINV_MASK                                                       (0x0080)
#define DE1_SOC_WM8731_DIGITAL_AUDIO_INTERFACE_FORMAT_REG_FORMAT_DSP                                                         (0x0003)
#define DE1_SOC_WM8731_DIGITAL_AUDIO_INTERFACE_FORMAT_REG_FORMAT_I2S                                                         (0x0002)
#define DE1_SOC_WM8731_DIGITAL_AUDIO_INTERFACE_FORMAT_REG_FORMAT_LEFT_JUSTIFIED                                              (0x0001)
#define DE1_SOC_WM8731_DIGITAL_AUDIO_INTERFACE_FORMAT_REG_FORMAT_RIGHT_JUSTIFIED                                             (0x0000)
#define DE1_SOC_WM8731_DIGITAL_AUDIO_INTERFACE_FORMAT_REG_IWL_32_BITS                                                        (0x0003)
#define DE1_SOC_WM8731_DIGITAL_AUDIO_INTERFACE_FORMAT_REG_IWL_24_BITS                                                        (0x0002)
#define DE1_SOC_WM8731_DIGITAL_AUDIO_INTERFACE_FORMAT_REG_IWL_20_BITS                                                        (0x0001)
#define DE1_SOC_WM8731_DIGITAL_AUDIO_INTERFACE_FORMAT_REG_IWL_16_BITS                                                        (0x0000)
#define DE1_SOC_WM8731_DIGITAL_AUDIO_INTERFACE_FORMAT_REG_LRP_RIGHT_CHANNEL_DAC_DATA_WHEN_DACLRC_HIGH                        (0x0001)
#define DE1_SOC_WM8731_DIGITAL_AUDIO_INTERFACE_FORMAT_REG_LRP_RIGHT_CHANNEL_DAC_DATA_WHEN_DACLRC_LOW                         (0x0000)
#define DE1_SOC_WM8731_DIGITAL_AUDIO_INTERFACE_FORMAT_REG_LRP_MSB_AVAILABLE_ON_2ND_BCLK_RISING_EDGE_AFTER_DACLRC_RISING_EDGE (0x0001)
#define DE1_SOC_WM8731_DIGITAL_AUDIO_INTERFACE_FORMAT_REG_LRP_MSB_AVAILABLE_ON_1ST_BCLK_RISING_EDGE_AFTER_DACLRC_RISING_EDGE (0x0000)
#define DE1_SOC_WM8731_DIGITAL_AUDIO_INTERFACE_FORMAT_REG_LRSWAP_RIGHT_CHANNEL_DAC_DATA_LEFT                                 (0x0001)
#define DE1_SOC_WM8731_DIGITAL_AUDIO_INTERFACE_FORMAT_REG_LRSWAP_RIGHT_CHANNEL_DAC_DATA_RIGHT                                (0x0000)
#define DE1_SOC_WM8731_DIGITAL_AUDIO_INTERFACE_FORMAT_REG_MS_ENABLE_MASTER_MODE                                              (0x0001)
#define DE1_SOC_WM8731_DIGITAL_AUDIO_INTERFACE_FORMAT_REG_MS_ENABLE_SLAVE_MODE                                               (0x0000)
#define DE1_SOC_WM8731_DIGITAL_AUDIO_INTERFACE_FORMAT_REG_BCLKINV_INVERT                                                     (0x0001)
#define DE1_SOC_WM8731_DIGITAL_AUDIO_INTERFACE_FORMAT_REG_BCLKINV_NO_INVERT                                                  (0x0000)
#define DE1_SOC_WM8731_DIGITAL_AUDIO_INTERFACE_FORMAT_REG_FORMAT_DEFAULT                                                     (DE1_SOC_WM8731_DIGITAL_AUDIO_INTERFACE_FORMAT_REG_FORMAT_I2S)
#define DE1_SOC_WM8731_DIGITAL_AUDIO_INTERFACE_FORMAT_REG_IWL_DEFAULT                                                        (DE1_SOC_WM8731_DIGITAL_AUDIO_INTERFACE_FORMAT_REG_IWL_24_BITS)
#define DE1_SOC_WM8731_DIGITAL_AUDIO_INTERFACE_FORMAT_REG_LRP_DEFAULT                                                        (DE1_SOC_WM8731_DIGITAL_AUDIO_INTERFACE_FORMAT_REG_LRP_RIGHT_CHANNEL_DAC_DATA_WHEN_DACLRC_LOW)
#define DE1_SOC_WM8731_DIGITAL_AUDIO_INTERFACE_FORMAT_REG_LRSWAP_DEFAULT                                                     (DE1_SOC_WM8731_DIGITAL_AUDIO_INTERFACE_FORMAT_REG_LRSWAP_RIGHT_CHANNEL_DAC_DATA_RIGHT)
#define DE1_SOC_WM8731_DIGITAL_AUDIO_INTERFACE_FORMAT_REG_MS_DEFAULT                                                         (DE1_SOC_WM8731_DIGITAL_AUDIO_INTERFACE_FORMAT_REG_MS_ENABLE_SLAVE_MODE)
#define DE1_SOC_WM8731_DIGITAL_AUDIO_INTERFACE_FORMAT_REG_BCLKINV_DEFAULT                                                    (DE1_SOC_WM8731_DIGITAL_AUDIO_INTERFACE_FORMAT_REG_BCLKINV_DO_INVERT)
#define DE1_SOC_WM8731_DIGITAL_AUDIO_INTERFACE_FORMAT_REG_FORMAT_WRITE(write_value)                                          (DE1_SOC_WM8731_WRITE((write_value), DE1_SOC_WM8731_DIGITAL_AUDIO_INTERFACE_FORMAT_REG_FORMAT_MASK))
#define DE1_SOC_WM8731_DIGITAL_AUDIO_INTERFACE_FORMAT_REG_IWL_WRITE(write_value)                                             (DE1_SOC_WM8731_WRITE((write_value), DE1_SOC_WM8731_DIGITAL_AUDIO_INTERFACE_FORMAT_REG_IWL_MASK))
#define DE1_SOC_WM8731_DIGITAL_AUDIO_INTERFACE_FORMAT_REG_LRP_WRITE(write_value)                                             (DE1_SOC_WM8731_WRITE((write_value), DE1_SOC_WM8731_DIGITAL_AUDIO_INTERFACE_FORMAT_REG_LRP_MASK))
#define DE1_SOC_WM8731_DIGITAL_AUDIO_INTERFACE_FORMAT_REG_LRSWAP_WRITE(write_value)                                          (DE1_SOC_WM8731_WRITE((write_value), DE1_SOC_WM8731_DIGITAL_AUDIO_INTERFACE_FORMAT_REG_LRSWAP_MASK))
#define DE1_SOC_WM8731_DIGITAL_AUDIO_INTERFACE_FORMAT_REG_MS_WRITE(write_value)                                              (DE1_SOC_WM8731_WRITE((write_value), DE1_SOC_WM8731_DIGITAL_AUDIO_INTERFACE_FORMAT_REG_MS_MASK))
#define DE1_SOC_WM8731_DIGITAL_AUDIO_INTERFACE_FORMAT_REG_BCLKINV_WRITE(write_value)                                         (DE1_SOC_WM8731_WRITE((write_value), DE1_SOC_WM8731_DIGITAL_AUDIO_INTERFACE_FORMAT_REG_BCLKINV_MASK))

#define DE1_SOC_WM8731_SAMPLING_CONTROL_REG                                                                                  (0x08)
#define DE1_SOC_WM8731_SAMPLING_CONTROL_REG_USB_NORMAL_MASK                                                                  (0x0001)
#define DE1_SOC_WM8731_SAMPLING_CONTROL_REG_BOSR_MASK                                                                        (0x0002)
#define DE1_SOC_WM8731_SAMPLING_CONTROL_REG_SR_MASK                                                                          (0x003c)
#define DE1_SOC_WM8731_SAMPLING_CONTROL_REG_CLKIDIV2_MASK                                                                    (0x0040)
#define DE1_SOC_WM8731_SAMPLING_CONTROL_REG_CLKODIV2_MASK                                                                    (0x0080)
#define DE1_SOC_WM8731_SAMPLING_CONTROL_REG_USB_NORMAL_USB_MODE                                                              (0x0001)
#define DE1_SOC_WM8731_SAMPLING_CONTROL_REG_USB_NORMAL_NORMAL_MODE                                                           (0x0000)
#define DE1_SOC_WM8731_SAMPLING_CONTROL_REG_BOSR_USB_MODE_250_FS                                                             (0x0000)
#define DE1_SOC_WM8731_SAMPLING_CONTROL_REG_BOSR_USB_MODE_272_FS                                                             (0x0001)
#define DE1_SOC_WM8731_SAMPLING_CONTROL_REG_BOSR_NORMAL_MODE_256_FS                                                          (0x0000)
#define DE1_SOC_WM8731_SAMPLING_CONTROL_REG_BOSR_NORMAL_MODE_384_FS                                                          (0x0001)
#define DE1_SOC_WM8731_SAMPLING_CONTROL_REG_CLKIDIV2_MCLK_DIV_2                                                              (0x0001)
#define DE1_SOC_WM8731_SAMPLING_CONTROL_REG_CLKIDIV2_MCLK                                                                    (0x0000)
#define DE1_SOC_WM8731_SAMPLING_CONTROL_REG_CLKODIV2_CORE_CLK_DIV_2                                                          (0x0001)
#define DE1_SOC_WM8731_SAMPLING_CONTROL_REG_CLKODIV2_CORE_CLK                                                                (0x0000)
#define DE1_SOC_WM8731_SAMPLING_CONTROL_REG_USB_NORMAL_DEFAULT                                                               (DE1_SOC_WM8731_SAMPLING_CONTROL_REG_USB_NORMAL_NORMAL_MODE)
#define DE1_SOC_WM8731_SAMPLING_CONTROL_REG_BOSR_DEFAULT                                                                     (DE1_SOC_WM8731_SAMPLING_CONTROL_REG_BOSR_NORMAL_MODE_256_FS)
#define DE1_SOC_WM8731_SAMPLING_CONTROL_REG_SR_DEFAULT                                                                       (0x0000)
#define DE1_SOC_WM8731_SAMPLING_CONTROL_REG_CLKIDIV2_DEFAULT                                                                 (DE1_SOC_WM8731_SAMPLING_CONTROL_REG_CLKIDIV2_MCLK)
#define DE1_SOC_WM8731_SAMPLING_CONTROL_REG_CLKODIV2_DEFAULT                                                                 (DE1_SOC_WM8731_SAMPLING_CONTROL_REG_CLKODIV2_CORE_CLK)
#define DE1_SOC_WM8731_SAMPLING_CONTROL_REG_USB_NORMAL_WRITE(write_value)                                                    (DE1_SOC_WM8731_WRITE((write_value), DE1_SOC_WM8731_SAMPLING_CONTROL_REG_USB_NORMAL_MASK))
#define DE1_SOC_WM8731_SAMPLING_CONTROL_REG_BOSR_WRITE(write_value)                                                          (DE1_SOC_WM8731_WRITE((write_value), DE1_SOC_WM8731_SAMPLING_CONTROL_REG_BOSR_MASK))
#define DE1_SOC_WM8731_SAMPLING_CONTROL_REG_SR_WRITE(write_value)                                                            (DE1_SOC_WM8731_WRITE((write_value), DE1_SOC_WM8731_SAMPLING_CONTROL_REG_SR_MASK))
#define DE1_SOC_WM8731_SAMPLING_CONTROL_REG_CLKIDIV2_WRITE(write_value)                                                      (DE1_SOC_WM8731_WRITE((write_value), DE1_SOC_WM8731_SAMPLING_CONTROL_REG_CLKIDIV2_MASK))
#define DE1_SOC_WM8731_SAMPLING_CONTROL_REG_CLKODIV2_WRITE(write_value)                                                      (DE1_SOC_WM8731_WRITE((write_value), DE1_SOC_WM8731_SAMPLING_CONTROL_REG_CLKODIV2_MASK))

#define DE1_SOC_WM8731_ACTIVE_CONTROL_REG                                                                                    (0x09)
#define DE1_SOC_WM8731_ACTIVE_CONTROL_REG_ACTIVE_MASK                                                                        (0x0001)
#define DE1_SOC_WM8731_ACTIVE_CONTROL_REG_ACTIVE_ACTIVE                                                                      (0x0001)
#define DE1_SOC_WM8731_ACTIVE_CONTROL_REG_ACTIVE_INACTIVE                                                                    (0x0000)
#define DE1_SOC_WM8731_ACTIVE_CONTROL_REG_ACTIVE_DEFAULT                                                                     (DE1_SOC_WM8731_ACTIVE_CONTROL_REG_ACTIVE_INACTIVE)
#define DE1_SOC_WM8731_ACTIVE_CONTROL_REG_ACTIVE_WRITE(write_value)                                                          (DE1_SOC_WM8731_WRITE((write_value), DE1_SOC_WM8731_ACTIVE_CONTROL_REG_ACTIVE_MASK))

#define DE1_SOC_WM8731_RESET_REGISTER_REG                                                                                    (0x0f)
#define DE1_SOC_WM8731_RESET_REGISTER_REG_RESET_MASK                                                                         (0x01ff)
#define DE1_SOC_WM8731_RESET_REGISTER_REG_RESET_RESET                                                                        (0x0000)
#define DE1_SOC_WM8731_RESET_REGISTER_REG_RESET_WRITE(write_value)                                                           (DE1_SOC_WM8731_WRITE((write_value), DE1_SOC_WM8731_RESET_REGISTER_REG_RESET_MASK))

#endif /* WM8731_H */
