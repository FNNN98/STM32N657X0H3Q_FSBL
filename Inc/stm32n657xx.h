/**
  ******************************************************************************
  * @file    stm32n657xx.h
  * @author  MCD Application Team
  * @brief   CMSIS STM32N657xx Device Peripheral Access Layer Header File.
  *
  *          This file contains:
  *           - Data structures and the address mapping for all peripherals
  *           - Peripheral's registers declarations and bits definition
  *           - Macros to access peripheral's registers hardware
  *
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

#ifndef STM32N657xx_H
#define STM32N657xx_H

#ifdef __cplusplus
extern "C" {
#endif

/** @addtogroup ST
  * @{
  */

/** @addtogroup STM32N657xx
  * @{
  */

/** @addtogroup Configuration_of_CMSIS
  * @{
  */

/* =========================================================================================================================== */
/* ================                                Interrupt Number Definition                                ================ */
/* =========================================================================================================================== */
typedef enum
{
/* ======================================  ARM Cortex-M55 Specific Interrupt Numbers  ======================================== */
  NonMaskableInt_IRQn        = -14,    /*!< -14 Non maskable Interrupt, cannot be stopped or preempted                         */
  HardFault_IRQn             = -13,    /*!< -13 Hard Fault, all classes of Fault                                               */
  MemoryManagement_IRQn      = -12,    /*!< -12 Memory Management, MPU mismatch, including Access Violation and No Match       */
  BusFault_IRQn              = -11,    /*!< -11 Bus Fault, Pre-Fetch-, Memory Access Fault, other address/memory related Fault */
  UsageFault_IRQn            = -10,    /*!< -10 Usage Fault, i.e. Undef Instruction, Illegal State Transition                  */
#if defined (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
  SecureFault_IRQn           = -9,     /*!< -9  Secure Fault                                                                   */
#endif
  SVCall_IRQn                = -5,     /*!< -5  System Service Call via SVC instruction                                        */
  DebugMonitor_IRQn          = -4,     /*!< -4  Debug Monitor                                                                  */
  PendSV_IRQn                = -2,     /*!< -2  Pendable request for system service                                            */
  SysTick_IRQn               = -1,     /*!< -1  System Tick Timer                                                              */

/* ======================================  STM32N6xx Specific Interrupt Numbers  ============================================= */
  PVD_PVM_IRQn               = 0,      /*!< PVD/PVM1/PVM2/PVM3/PVM4 through EXTI Line detection                                */
  DTS_IRQn                   = 2,      /*!< Thermal Sensor interruption                                                        */
  RCC_IRQn                   = 3,      /*!< RCC non-secure global interrupts through EXTI Line detection                       */
  LOCKUP_IRQn                = 4,      /*!< LOCKUP / (no Overstack in CM55)                                                    */
  CACHE_ECC_IRQn             = 5,      /*!< Error ECC cache interrupt                                                          */
  TCM_ECC_IRQn               = 6,      /*!< TCM ECC interrupts                                                                 */
  BKP_ECC_IRQn               = 7,      /*!< Backup RAM Interrupts                                                              */
  FPU_IRQn                   = 8,      /*!< FPU interrupt                                                                      */
  RTC_S_IRQn                 = 10,     /*!< RTC secure interrupts through EXTI Line detection                                  */
  TAMP_IRQn                  = 11,     /*!< Tamper secure and non-secure interrupts through EXTI Line detection                */
  RIFSC_TAMPER_IRQn          = 12,     /*!< RIF Tamper interrupts                                                              */
  IAC_IRQn                   = 13,     /*!< IAC interrupt                                                                      */
  RCC_S_IRQn                 = 14,     /*!< RCC secure global interrupts through EXTI Line detection                           */
  RTC_IRQn                   = 16,     /*!< RTC non-secure interrupts through EXTI Line detection                              */
  IWDG_IRQn                  = 18,     /*!< Internal Watchdog interrupt                                                        */
  WWDG_IRQn                  = 19,     /*!< Window Watchdog interrupt                                                          */
  EXTI0_IRQn                 = 20,     /*!< EXTI Line0 interrupt                                                               */
  EXTI1_IRQn                 = 21,     /*!< EXTI Line1 interrupt                                                               */
  EXTI2_IRQn                 = 22,     /*!< EXTI Line2 interrupt                                                               */
  EXTI3_IRQn                 = 23,     /*!< EXTI Line3 interrupt                                                               */
  EXTI4_IRQn                 = 24,     /*!< EXTI Line4 interrupt                                                               */
  EXTI5_IRQn                 = 25,     /*!< EXTI Line5 interrupt                                                               */
  EXTI6_IRQn                 = 26,     /*!< EXTI Line6 interrupt                                                               */
  EXTI7_IRQn                 = 27,     /*!< EXTI Line7 interrupt                                                               */
  EXTI8_IRQn                 = 28,     /*!< EXTI Line8 interrupt                                                               */
  EXTI9_IRQn                 = 29,     /*!< EXTI Line9 interrupt                                                               */
  EXTI10_IRQn                = 30,     /*!< EXTI Line10 interrupt                                                              */
  EXTI11_IRQn                = 31,     /*!< EXTI Line11 interrupt                                                              */
  EXTI12_IRQn                = 32,     /*!< EXTI Line12 interrupt                                                              */
  EXTI13_IRQn                = 33,     /*!< EXTI Line13 interrupt                                                              */
  EXTI14_IRQn                = 34,     /*!< EXTI Line14 interrupt                                                              */
  EXTI15_IRQn                = 35,     /*!< EXTI Line15 interrupt                                                              */
  SAES_IRQn                  = 36,     /*!< SAES interrupt                                                                     */
  CRYP_IRQn                  = 37,     /*!< CRYP interrupt                                                                     */
  PKA_IRQn                   = 38,     /*!< PKA interrupt                                                                      */
  HASH_IRQn                  = 39,     /*!< HASH interrupt                                                                     */
  RNG_IRQn                   = 40,     /*!< RNG global interrupt                                                               */
  MCE1_IRQn                  = 42,     /*!< MCE1 global interrupt                                                              */
  MCE2_IRQn                  = 43,     /*!< MCE2 global interrupt                                                              */
  MCE3_IRQn                  = 44,     /*!< MCE3 global interrupt                                                              */
  MCE4_IRQn                  = 45,     /*!< MCE4 global interrupt                                                              */
  ADC1_2_IRQn                = 46,     /*!< ADC1 & ADC2 interrupt                                                              */
  CSI_IRQn                   = 47,     /*!< CSI global interrupt                                                               */
  DCMIPP_IRQn                = 48,     /*!< DCMIPP global interrupt                                                            */
  PAHB_ERR_IRQn              = 52,     /*!< PAHB error interrupt                                                               */
  NPU0_IRQn                  = 53,     /*!< NPU mst_ints[0] line interrupt                                                     */
  NPU1_IRQn                  = 54,     /*!< NPU mst_ints[1] line interrupt                                                     */
  NPU2_IRQn                  = 55,     /*!< NPU mst_ints[2] line interrupt                                                     */
  NPU3_IRQn                  = 56,     /*!< NPU mst_ints[3] line interrupt                                                     */
  CACHEAXI_IRQn              = 57,     /*!< NPU cache interrupt                                                                */
  LTDC_LO_IRQn               = 58,     /*!< LTDC low-layer global interrupt                                                    */
  LTDC_LO_ERR_IRQn           = 59,     /*!< LTDC low-layer error interrupt                                                     */
  DMA2D_IRQn                 = 60,     /*!< DMA2D global interrupt                                                             */
  JPEG_IRQn                  = 61,     /*!< JPEG global interrupt                                                              */
  VENC_IRQn                  = 62,     /*!< VENC global interrupt                                                              */
  GFXMMU_IRQn                = 63,     /*!< GFXMMU global interrupt                                                            */
  GFXTIM_IRQn                = 64,     /*!< GFXTIM global interrupt                                                            */
  GPU2D_IRQn                 = 65,     /*!< GPU2D interrupt                                                                    */
  GPU2D_ER_IRQn              = 66,     /*!< GPU2D error interrupt                                                              */
  ICACHE_IRQn                = 67,     /*!< GPU2D cache interrupt                                                              */
  HPDMA1_Channel0_IRQn       = 68,     /*!< HPDMA1 Channel 0 global interrupt                                                  */
  HPDMA1_Channel1_IRQn       = 69,     /*!< HPDMA1 Channel 1 global interrupt                                                  */
  HPDMA1_Channel2_IRQn       = 70,     /*!< HPDMA1 Channel 2 global interrupt                                                  */
  HPDMA1_Channel3_IRQn       = 71,     /*!< HPDMA1 Channel 3 global interrupt                                                  */
  HPDMA1_Channel4_IRQn       = 72,     /*!< HPDMA1 Channel 4 global interrupt                                                  */
  HPDMA1_Channel5_IRQn       = 73,     /*!< HPDMA1 Channel 5 global interrupt                                                  */
  HPDMA1_Channel6_IRQn       = 74,     /*!< HPDMA1 Channel 6 global interrupt                                                  */
  HPDMA1_Channel7_IRQn       = 75,     /*!< HPDMA1 Channel 7 global interrupt                                                  */
  HPDMA1_Channel8_IRQn       = 76,     /*!< HPDMA1 Channel 8 global interrupt                                                  */
  HPDMA1_Channel9_IRQn       = 77,     /*!< HPDMA1 Channel 9 global interrupt                                                  */
  HPDMA1_Channel10_IRQn      = 78,     /*!< HPDMA1 Channel 10 global interrupt                                                 */
  HPDMA1_Channel11_IRQn      = 79,     /*!< HPDMA1 Channel 11 global interrupt                                                 */
  HPDMA1_Channel12_IRQn      = 80,     /*!< HPDMA1 Channel 12 global interrupt                                                 */
  HPDMA1_Channel13_IRQn      = 81,     /*!< HPDMA1 Channel 13 global interrupt                                                 */
  HPDMA1_Channel14_IRQn      = 82,     /*!< HPDMA1 Channel 14 global interrupt                                                 */
  HPDMA1_Channel15_IRQn      = 83,     /*!< HPDMA1 Channel 15 global interrupt                                                 */
  GPDMA1_Channel0_IRQn       = 84,     /*!< GPDMA1 Channel 0 interrupt                                                         */
  GPDMA1_Channel1_IRQn       = 85,     /*!< GPDMA1 Channel 1 interrupt                                                         */
  GPDMA1_Channel2_IRQn       = 86,     /*!< GPDMA1 Channel 2 interrupt                                                         */
  GPDMA1_Channel3_IRQn       = 87,     /*!< GPDMA1 Channel 3 interrupt                                                         */
  GPDMA1_Channel4_IRQn       = 88,     /*!< GPDMA1 Channel 4 interrupt                                                         */
  GPDMA1_Channel5_IRQn       = 89,     /*!< GPDMA1 Channel 5 interrupt                                                         */
  GPDMA1_Channel6_IRQn       = 90,     /*!< GPDMA1 Channel 6 interrupt                                                         */
  GPDMA1_Channel7_IRQn       = 91,     /*!< GPDMA1 Channel 7 interrupt                                                         */
  GPDMA1_Channel8_IRQn       = 92,     /*!< GPDMA1 Channel 8 interrupt                                                         */
  GPDMA1_Channel9_IRQn       = 93,     /*!< GPDMA1 Channel 9 interrupt                                                         */
  GPDMA1_Channel10_IRQn      = 94,     /*!< GPDMA1 Channel 10 interrupt                                                        */
  GPDMA1_Channel11_IRQn      = 95,     /*!< GPDMA1 Channel 11 interrupt                                                        */
  GPDMA1_Channel12_IRQn      = 96,     /*!< GPDMA1 Channel 12 interrupt                                                        */
  GPDMA1_Channel13_IRQn      = 97,     /*!< GPDMA1 Channel 13 interrupt                                                        */
  GPDMA1_Channel14_IRQn      = 98,     /*!< GPDMA1 Channel 14 interrupt                                                        */
  GPDMA1_Channel15_IRQn      = 99,     /*!< GPDMA1 Channel 15 interrupt                                                        */
  I2C1_EV_IRQn               = 100,    /*!< I2C1 event interrupt                                                               */
  I2C1_ER_IRQn               = 101,    /*!< I2C1 error interrupt                                                               */
  I2C2_EV_IRQn               = 102,    /*!< I2C2 event interrupt                                                               */
  I2C2_ER_IRQn               = 103,    /*!< I2C2 error interrupt                                                               */
  I2C3_EV_IRQn               = 104,    /*!< I2C3 event interrupt                                                               */
  I2C3_ER_IRQn               = 105,    /*!< I2C3 error interrupt                                                               */
  I2C4_EV_IRQn               = 106,    /*!< I2C4 event interrupt                                                               */
  I2C4_ER_IRQn               = 107,    /*!< I2C4 error interrupt                                                               */
  I3C1_EV_IRQn               = 108,    /*!< I3C1 event interrupt                                                               */
  I3C1_ER_IRQn               = 109,    /*!< I3C1 error interrupt                                                               */
  I3C2_EV_IRQn               = 110,    /*!< I3C2 event interrupt                                                               */
  I3C2_ER_IRQn               = 111,    /*!< I3C2 error interrupt                                                               */
  TIM1_BRK_IRQn              = 112,    /*!< TIM1 Break interrupt                                                               */
  TIM1_UP_IRQn               = 113,    /*!< TIM1 Update interrupt                                                              */
  TIM1_TRG_COM_IRQn          = 114,    /*!< TIM1 Trigger and Commutation interrupt                                             */
  TIM1_CC_IRQn               = 115,    /*!< TIM1 Capture Compare interrupt                                                     */
  TIM2_IRQn                  = 116,    /*!< TIM2 global interrupt                                                              */
  TIM3_IRQn                  = 117,    /*!< TIM3 global interrupt                                                              */
  TIM4_IRQn                  = 118,    /*!< TIM4 global interrupt                                                              */
  TIM5_IRQn                  = 119,    /*!< TIM5 global interrupt                                                              */
  TIM6_IRQn                  = 120,    /*!< TIM6 global interrupt                                                              */
  TIM7_IRQn                  = 121,    /*!< TIM7 global interrupt                                                              */
  TIM8_BRK_IRQn              = 122,    /*!< TIM8 Break interrupt                                                               */
  TIM8_UP_IRQn               = 123,    /*!< TIM8 Update interrupt                                                              */
  TIM8_TRG_COM_IRQn          = 124,    /*!< TIM8 Trigger and Commutation interrupt                                             */
  TIM8_CC_IRQn               = 125,    /*!< TIM8 Capture Compare interrupt                                                     */
  TIM9_IRQn                  = 126,    /*!< TIM9 global interrupt                                                              */
  TIM10_IRQn                 = 127,    /*!< TIM10 global interrupt                                                             */
  TIM11_IRQn                 = 128,    /*!< TIM11 global interrupt                                                             */
  TIM12_IRQn                 = 129,    /*!< TIM12 global interrupt                                                             */
  TIM13_IRQn                 = 130,    /*!< TIM13 global interrupt                                                             */
  TIM14_IRQn                 = 131,    /*!< TIM14 global interrupt                                                             */
  TIM15_IRQn                 = 132,    /*!< TIM15 global interrupt                                                             */
  TIM16_IRQn                 = 133,    /*!< TIM16 global interrupt                                                             */
  TIM17_IRQn                 = 134,    /*!< TIM17 global interrupt                                                             */
  TIM18_IRQn                 = 135,    /*!< TIM18 global interrupt                                                             */
  LPTIM1_IRQn                = 136,    /*!< LPTIM1 global interrupt                                                            */
  LPTIM2_IRQn                = 137,    /*!< LPTIM2 global interrupt                                                            */
  LPTIM3_IRQn                = 138,    /*!< LPTIM3 global interrupt                                                            */
  LPTIM4_IRQn                = 139,    /*!< LPTIM4 global interrupt                                                            */
  LPTIM5_IRQn                = 140,    /*!< LPTIM5 global interrupt                                                            */
  ADF1_FLT0_IRQn             = 141,    /*!< ADF1 Filter 0 global interrupt                                                     */
  MDF1_FLT0_IRQn             = 142,    /*!< MDF1 Filter 0 global interrupt                                                     */
  MDF1_FLT1_IRQn             = 143,    /*!< MDF1 Filter 1 global interrupt                                                     */
  MDF1_FLT2_IRQn             = 144,    /*!< MDF1 Filter 2 global interrupt                                                     */
  MDF1_FLT3_IRQn             = 145,    /*!< MDF1 Filter 3 global interrupt                                                     */
  MDF1_FLT4_IRQn             = 146,    /*!< MDF1 Filter 4 global interrupt                                                     */
  MDF1_FLT5_IRQn             = 147,    /*!< MDF1 Filter 5 global interrupt                                                     */
  SAI1_A_IRQn                = 148,    /*!< Serial Audio Interface 1 block A interrupt                                         */
  SAI1_B_IRQn                = 149,    /*!< Serial Audio Interface 1 block B interrupt                                         */
  SAI2_A_IRQn                = 150,    /*!< Serial Audio Interface 2 block A interrupt                                         */
  SAI2_B_IRQn                = 151,    /*!< Serial Audio Interface 2 block B interrupt                                         */
  SPDIFRX1_IRQn              = 152,    /*!< SPDIFRX1 interrupt                                                                 */
  SPI1_IRQn                  = 153,    /*!< SPI1 global interrupt                                                              */
  SPI2_IRQn                  = 154,    /*!< SPI2 global interrupt                                                              */
  SPI3_IRQn                  = 155,    /*!< SPI3 global interrupt                                                              */
  SPI4_IRQn                  = 156,    /*!< SPI4 global interrupt                                                              */
  SPI5_IRQn                  = 157,    /*!< SPI5 global interrupt                                                              */
  SPI6_IRQn                  = 158,    /*!< SPI6 global interrupt                                                              */
  USART1_IRQn                = 159,    /*!< USART1 global interrupt                                                            */
  USART2_IRQn                = 160,    /*!< USART2 global interrupt                                                            */
  USART3_IRQn                = 161,    /*!< USART3 global interrupt                                                            */
  UART4_IRQn                 = 162,    /*!< UART4 global interrupt                                                             */
  UART5_IRQn                 = 163,    /*!< UART5 global interrupt                                                             */
  USART6_IRQn                = 164,    /*!< USART3 global interrupt                                                            */
  UART7_IRQn                 = 165,    /*!< UART7 global interrupt                                                             */
  UART8_IRQn                 = 166,    /*!< UART8 global interrupt                                                             */
  UART9_IRQn                 = 167,    /*!< UART9 global interrupt                                                             */
  USART10_IRQn               = 168,    /*!< USART10 global interrupt                                                           */
  LPUART1_IRQn               = 169,    /*!< LPUART1 global interrupt                                                           */
  XSPI1_IRQn                 = 170,    /*!< XSPI1 global interrupt                                                             */
  XSPI2_IRQn                 = 171,    /*!< XSPI2 global interrupt                                                             */
  XSPI3_IRQn                 = 172,    /*!< XSPI3 global interrupt                                                             */
  FMC_IRQn                   = 173,    /*!< FMC global interrupt                                                               */
  SDMMC1_IRQn                = 174,    /*!< SDMMC1 global interrupt                                                            */
  SDMMC2_IRQn                = 175,    /*!< SDMMC2 global interrupt                                                            */
  UCPD1_IRQn                 = 176,    /*!< UCPD1 global interrupt                                                             */
  USB1_OTG_HS_IRQn           = 177,    /*!< USB1 OTG HS interrupt                                                              */
  USB2_OTG_HS_IRQn           = 178,    /*!< USB2 OTG HS interrupt                                                              */
  ETH1_IRQn                  = 179,    /*!< ETH1 global interrupt                                                              */
  FDCAN1_IT0_IRQn            = 180,    /*!< FDCAN1 interrupt 0                                                                 */
  FDCAN1_IT1_IRQn            = 181,    /*!< FDCAN1 interrupt 1                                                                 */
  FDCAN2_IT0_IRQn            = 182,    /*!< FDCAN2 interrupt 0                                                                 */
  FDCAN2_IT1_IRQn            = 183,    /*!< FDCAN2 interrupt 1                                                                 */
  FDCAN3_IT0_IRQn            = 184,    /*!< FDCAN3 interrupt 0                                                                 */
  FDCAN3_IT1_IRQn            = 185,    /*!< FDCAN3 interrupt 1                                                                 */
  FDCAN_CU_IRQn              = 186,    /*!< FDCAN Clock Unit interrupt                                                         */
  MDIOS_IRQn                 = 187,    /*!< MDIOS global interrupt                                                             */
  DCMI_PSSI_IRQn             = 188,    /*!< DCMI/PSSI global interrupt                                                         */
  WAKEUP_PIN_IRQn            = 189,    /*!< Wake-up pins interrupt                                                             */
  CTI_INT0_IRQn              = 190,    /*!< CTI INT0 interrupt                                                                 */
  CTI_INT1_IRQn              = 191,    /*!< CTI INT1 interrupt                                                                 */
  LTDC_UP_IRQn               = 193,    /*!< LTDC up-layer global interrupt                                                     */
  LTDC_UP_ERR_IRQn           = 194,    /*!< LTDC up-layer error interrupt                                                      */
} IRQn_Type;


/* =========================================================================================================================== */
/* ================                           Processor and Core Peripheral Section                           ================ */
/* =========================================================================================================================== */

/**
  * @brief Configuration of the Cortex-M55 Processor and Core Peripherals
   */
#define __CM55_REV                0x0101U /*!< Cortex-M55 revision r1p1                      */
#define __FPU_PRESENT             1U      /*!< CM55 Floating Point Unit present              */
#define __DSP_PRESENT             1U      /*!< CM55 Digital Signal Processing Unit present   */
#define __MPU_PRESENT             1U      /*!< CM55 Memory Programming Unit present          */
//#define volatile const 			  ICACHE_PRESENT          1U      /*!< CM55 Instruction cache present                */
#define __DCACHE_PRESENT          1U      /*!< CM55 Data cache present                       */
#define __VTOR_PRESENT            1U      /*!< CM55 Vector table offset register present     */
#define __PMU_PRESENT             1U      /*!< CM55 Performance Monitoring Unit present      */
#define __PMU_NUM_EVENTCNT        8U      /*!< CM55 can monitor up to 8 PMU events           */
#define __NVIC_PRIO_BITS          4U      /*!< CM55 uses 4 bits for the Priority Levels      */
#define __Vendor_SysTickConfig    0U      /*!< Set to 1 if different SysTick Config is used  */
#define __SAUREGION_PRESENT       1U      /*!< SAU regions present                           */

/** @} */ /* End of group Configuration_of_CMSIS */

#if defined (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
#define CPU_IN_SECURE_STATE
#endif

#define CPU_AS_TRUSTED_DOMAIN

#include "core_cm55.h"                    /*!< ARM Cortex-M55 processor and core peripherals */
//#include "system_stm32n6xx.h"             /*!< STM32N6xx System */

/* =========================================================================================================================== */
/* ================                            Device Specific Peripheral Section                             ================ */
/* =========================================================================================================================== */

/** @addtogroup STM32N6xx_peripherals
  * @{
  */

/**
  * @brief Analog to Digital Converter (ADC)
  */
typedef struct
{
  volatile uint32_t ISR;           /*!< ADC interrupt and status register,                     Address offset: 0x00 */
  volatile uint32_t IER;           /*!< ADC interrupt enable register,                         Address offset: 0x04 */
  volatile uint32_t CR;            /*!< ADC control register,                                  Address offset: 0x08 */
  volatile uint32_t CFGR1;         /*!< ADC configuration register 1,                          Address offset: 0x0C */
  volatile uint32_t CFGR2;         /*!< ADC configuration register 2,                          Address offset: 0x10 */
  volatile uint32_t SMPR1;         /*!< ADC sample time register 1,                            Address offset: 0x14 */
  volatile uint32_t SMPR2;         /*!< ADC sample time register 2,                            Address offset: 0x18 */
  volatile uint32_t PCSEL;         /*!< ADC channel preselection register,                     Address offset: 0x1C */
  uint32_t      RESERVED1[4];  /*!< Reserved,                                              Address offset: 0x020-0x02C */
  volatile uint32_t SQR1;          /*!< ADC regular sequence register 1,                       Address offset: 0x30 */
  volatile uint32_t SQR2;          /*!< ADC regular sequence register 2,                       Address offset: 0x34 */
  volatile uint32_t SQR3;          /*!< ADC regular sequence register 3,                       Address offset: 0x38 */
  volatile uint32_t SQR4;          /*!< ADC regular sequence register 4,                       Address offset: 0x3C */
  volatile uint32_t DR;            /*!< ADC regular data register,                             Address offset: 0x40 */
  uint32_t      RESERVED2[2];  /*!< Reserved,                                              Address offset: 0x044-0x048 */
  volatile uint32_t JSQR;          /*!< ADC injected sequence register,                        Address offset: 0x4C */
  volatile uint32_t OFCFGR1;       /*!< ADC offset configuration register 1,                   Address offset: 0x50 */
  volatile uint32_t OFCFGR2;       /*!< ADC offset configuration register 2,                   Address offset: 0x54 */
  volatile uint32_t OFCFGR3;       /*!< ADC offset configuration register 3,                   Address offset: 0x58 */
  volatile uint32_t OFCFGR4;       /*!< ADC offset configuration register 4,                   Address offset: 0x5C */
  volatile uint32_t OFR1;          /*!< ADC offset register 1,                                 Address offset: 0x60 */
  volatile uint32_t OFR2;          /*!< ADC offset register 2,                                 Address offset: 0x64 */
  volatile uint32_t OFR3;          /*!< ADC offset register 3,                                 Address offset: 0x68 */
  volatile uint32_t OFR4;          /*!< ADC offset register 4,                                 Address offset: 0x6C */
  volatile uint32_t GCOMP;         /*!< ADC gain compensation register,                        Address offset: 0x70 */
  uint32_t      RESERVED3[3];  /*!< Reserved,                                              Address offset: 0x074-0x07C */
  volatile uint32_t JDR1;          /*!< ADC injected data register 1,                          Address offset: 0x80 */
  volatile uint32_t JDR2;          /*!< ADC injected data register 2,                          Address offset: 0x84 */
  volatile uint32_t JDR3;          /*!< ADC injected data register 3,                          Address offset: 0x88 */
  volatile uint32_t JDR4;          /*!< ADC injected data register 4,                          Address offset: 0x8C */
  uint32_t      RESERVED4[4];  /*!< Reserved,                                              Address offset: 0x090-0x09C */
  volatile uint32_t AWD2CR;        /*!< ADC analog watchdog 2 configuration register,          Address offset: 0xA0 */
  volatile uint32_t AWD3CR;        /*!< ADC analog watchdog 3 configuration register,          Address offset: 0xA4 */
  volatile uint32_t AWD1LTR;       /*!< ADC analog watchdog 1 low threshold register,          Address offset: 0xA8 */
  volatile uint32_t AWD1HTR;       /*!< ADC analog watchdog 1 high threshold register,         Address offset: 0xAC */
  volatile uint32_t AWD2LTR;       /*!< ADC analog watchdog 2 low threshold register,          Address offset: 0xB0 */
  volatile uint32_t AWD2HTR;       /*!< ADC analog watchdog 2 high threshold register,         Address offset: 0xB4 */
  volatile uint32_t AWD3LTR;       /*!< ADC analog watchdog 3 low threshold register,          Address offset: 0xB8 */
  volatile uint32_t AWD3HTR;       /*!< ADC analog watchdog 3 high threshold register,         Address offset: 0xBC */
  volatile uint32_t DIFSEL;        /*!< ADC differential mode selection register,              Address offset: 0xC0 */
  volatile uint32_t CALFACT;       /*!< ADC calibration factors,                               Address offset: 0xC4 */
  uint32_t      RESERVED5[2];  /*!< Reserved,                                              Address offset: 0x0C8-0x0CC */
  volatile uint32_t OR;            /*!< ADC option register,                                   Address offset: 0xD0 */
} ADC_TypeDef;

typedef struct
{
  volatile uint32_t CSR;           /*!< ADC common status register,                            Address offset: 0x300 */
  uint32_t RESERVED;           /*!< Reserved,                                              Address offset: 0x304 */
  volatile uint32_t CCR;           /*!< ADC common control register,                           Address offset: 0x308 */
  volatile uint32_t CDR;           /*!< ADC common regular data register for dual mode,        Address offset: 0x30C */
  volatile uint32_t CDR2;          /*!< ADC common regular data register for dual mode 32-bit, Address offset: 0x310 */
} ADC_Common_TypeDef;

/**
  * @brief Boot and Security
  */

typedef struct
{
  volatile uint32_t FVRw[384];       /*!< BSEC fuse word (0-383) value register,       Address offset: 0x000-0x5FC */
       uint32_t RESERVED0[128];  /*!< Reserved,                                    Address offset: 0x600-0x7FC */
  volatile uint32_t SPLOCKx[12];     /*!< BSEC sticky program lock register (0-11),    Address offset: 0x800-0x82C */
       uint32_t RESERVED1[4];    /*!< Reserved,                                    Address offset: 0x830-0x83C */
  volatile uint32_t SWLOCKx[12];     /*!< BSEC sticky write lock register (0-11),      Address offset: 0x840-0x86C */
       uint32_t RESERVED2[4];    /*!< Reserved,                                    Address offset: 0x870-0x87C */
  volatile uint32_t SRLOCKx[12];     /*!< BSEC sticky reload lock register (0-11),     Address offset: 0x880-0x8AC */
       uint32_t RESERVED3[4];    /*!< Reserved,                                    Address offset: 0x8B0-0x8BC */
  volatile uint32_t OTPVLDRx[12];    /*!< BSEC OTP valid register (0-11),              Address offset: 0x8C0-0x8EC */
       uint32_t RESERVED4[20];   /*!< Reserved,                                    Address offset: 0x8F0-0x93C */
  volatile uint32_t SFSRx[12];       /*!< BSEC shadowed fuses status register (0-11),  Address offset: 0x940-0x96C */
       uint32_t RESERVED5[165];  /*!< Reserved,                                    Address offset: 0x970-0xC00 */
  volatile uint32_t OTPCR;           /*!< BSEC OTP control register,                   Address offset: 0xC04 */
  volatile uint32_t WDR;             /*!< BSEC write data register,                    Address offset: 0xC08 */
       uint32_t RESERVED6[125];  /*!< Reserved,                                    Address offset: 0xC0C-0xDFC */
  volatile uint32_t SCRATCHRx[4];    /*!< BSEC scratch register (0-3),                 Address offset: 0xE00-0xE0C */
  volatile uint32_t LOCKR;           /*!< BSEC lock register,                          Address offset: 0xE10 */
  volatile uint32_t JTAGINR;         /*!< BSEC JTAG input register,                    Address offset: 0xE14 */
  volatile uint32_t JTAGOUTR;        /*!< BSEC JTAG output register,                   Address offset: 0xE18 */
       uint32_t RESERVED7[2];    /*!< Reserved,                                    Address offset: 0xE1C-0xE20 */
  volatile uint32_t UNMAPR;          /*!< BSEC unmap register,                         Address offset: 0xE24 */
       uint32_t RESERVED8[6];    /*!< Reserved,                                    Address offset: 0xE28-0xE3C */
  volatile uint32_t SR;              /*!< BSEC status register,                        Address offset: 0xE40 */
  volatile uint32_t OTPSR;           /*!< BSEC OTP status register,                    Address offset: 0xE44 */
       uint32_t RESERVED9[14];   /*!< Reserved,                                    Address offset: 0xE48-0xE7C */
  volatile uint32_t EPOCHRx[2];      /*!< BSEC epoch register (0-1),                   Address offset: 0xE80-0xE84 */
  volatile uint32_t EPOCHSELR;       /*!< BSEC epoch select register,                  Address offset: 0xE88 */
  volatile uint32_t DBGCR;           /*!< BSEC debug control register,                 Address offset: 0xE8C */
  volatile uint32_t AP_UNLOCK;       /*!< BSEC AP unlock,                              Address offset: 0xE90 */
  volatile uint32_t HDPLSR;          /*!< BSEC hide protection level status register,  Address offset: 0xE94 */
  volatile uint32_t HDPLCR;          /*!< BSEC hide protection level control register, Address offset: 0xE98 */
  volatile uint32_t NEXTLR;          /*!< BSEC next hide protection level register,    Address offset: 0xE9C */
       uint32_t RESERVED10[40];  /*!< Reserved,                                    Address offset: 0xEA0-0xF3C */
  volatile uint32_t WOSCRx[8];       /*!< BSEC write once scratch register (0-7),      Address offset: 0xF40-0xF5C */
       uint32_t RESERVED11[34];  /*!< Reserved,                                    Address offset: 0xF60-0xFE4 */
  volatile uint32_t HRCR;            /*!< BSEC hot reset count register,               Address offset: 0xFE8 */
  volatile uint32_t WRCR;            /*!< BSEC warm reset count register,              Address offset: 0xFEC */
} BSEC_TypeDef;

/**
  * @brief Axi Cache
  */
typedef struct
{
  volatile uint32_t CR1;            /*!< CACHEAXI control register 1,                   Address offset: 0x00 */
  volatile uint32_t SR;             /*!< CACHEAXI status register,                      Address offset: 0x04 */
  volatile uint32_t IER;            /*!< CACHEAXI interrupt enable register,            Address offset: 0x08 */
  volatile uint32_t FCR;            /*!< CACHEAXI flag clear register,                  Address offset: 0x0C */
  volatile uint32_t RHMONR;         /*!< CACHEAXI read hit monitor register,            Address offset: 0x10 */
  volatile uint32_t RMMONR;         /*!< CACHEAXI read miss monitor register,           Address offset: 0x14 */
  volatile uint32_t RAMMONR;        /*!< CACHEAXI read-allocate miss monitor register,  Address offset: 0x18 */
  volatile uint32_t EVIMONR;        /*!< CACHEAXI eviction monitor register,            Address offset: 0x1C */
  volatile uint32_t WHMONR;         /*!< CACHEAXI write-hit monitor register,           Address offset: 0x20 */
  volatile uint32_t WMMONR;         /*!< CACHEAXI write-miss monitor register,          Address offset: 0x24 */
  volatile uint32_t WAMMONR;        /*!< CACHEAXI write-allocate miss monitor register, Address offset: 0x28 */
  volatile uint32_t WTMONR;         /*!< CACHEAXI write-through monitor register,       Address offset: 0x2C */
       uint32_t RESERVED1[52];  /*!< Reserved,                                      Address offset: 0x30-0xFC */
  volatile uint32_t CR2;            /*!< CACHEAXI control register 2,                   Address offset: 0x100 */
  volatile uint32_t CMDRSADDRR;     /*!< CACHEAXI command start address register,       Address offset: 0x104 */
  volatile uint32_t CMDREADDRR;     /*!< CACHEAXI command end address register,         Address offset: 0x108 */
} CACHEAXI_TypeDef;

/**
  * @brief CRC calculation unit
  */
typedef struct
{
  volatile uint32_t DR;            /*!< CRC Data register,                              Address offset: 0x00 */
  volatile uint32_t IDR;           /*!< CRC Independent data register,                  Address offset: 0x04 */
  volatile uint32_t CR;            /*!< CRC Control register,                           Address offset: 0x08 */
       uint32_t RESERVED1;     /*!< Reserved,                                                       0x0C */
  volatile uint32_t INIT;          /*!< Initial CRC value register,                     Address offset: 0x10 */
  volatile uint32_t POL;           /*!< CRC polynomial register,                        Address offset: 0x14 */
} CRC_TypeDef;


/**
  * @brief Cryp Processor
  */
typedef struct
{
  volatile uint32_t CR;         /*!< CRYP control register,                                    Address offset: 0x00 */
  volatile uint32_t SR;         /*!< CRYP status register,                                     Address offset: 0x04 */
  volatile uint32_t DIN;        /*!< CRYP data input register,                                 Address offset: 0x08 */
  volatile uint32_t DOUT;       /*!< CRYP data output register,                                Address offset: 0x0C */
  volatile uint32_t DMACR;      /*!< CRYP DMA control register,                                Address offset: 0x10 */
  volatile uint32_t IMSCR;      /*!< CRYP interrupt mask set/clear register,                   Address offset: 0x14 */
  volatile uint32_t RISR;       /*!< CRYP raw interrupt status register,                       Address offset: 0x18 */
  volatile uint32_t MISR;       /*!< CRYP masked interrupt status register,                    Address offset: 0x1C */
  volatile uint32_t K0LR;       /*!< CRYP key left  register 0,                                Address offset: 0x20 */
  volatile uint32_t K0RR;       /*!< CRYP key right register 0,                                Address offset: 0x24 */
  volatile uint32_t K1LR;       /*!< CRYP key left  register 1,                                Address offset: 0x28 */
  volatile uint32_t K1RR;       /*!< CRYP key right register 1,                                Address offset: 0x2C */
  volatile uint32_t K2LR;       /*!< CRYP key left  register 2,                                Address offset: 0x30 */
  volatile uint32_t K2RR;       /*!< CRYP key right register 2,                                Address offset: 0x34 */
  volatile uint32_t K3LR;       /*!< CRYP key left  register 3,                                Address offset: 0x38 */
  volatile uint32_t K3RR;       /*!< CRYP key right register 3,                                Address offset: 0x3C */
  volatile uint32_t IV0LR;      /*!< CRYP initialization vector left-word  register 0,         Address offset: 0x40 */
  volatile uint32_t IV0RR;      /*!< CRYP initialization vector right-word register 0,         Address offset: 0x44 */
  volatile uint32_t IV1LR;      /*!< CRYP initialization vector left-word  register 1,         Address offset: 0x48 */
  volatile uint32_t IV1RR;      /*!< CRYP initialization vector right-word register 1,         Address offset: 0x4C */
  volatile uint32_t CSGCMCCM0R; /*!< CRYP GCM/GMAC or CCM/CMAC context swap register 0,        Address offset: 0x50 */
  volatile uint32_t CSGCMCCM1R; /*!< CRYP GCM/GMAC or CCM/CMAC context swap register 1,        Address offset: 0x54 */
  volatile uint32_t CSGCMCCM2R; /*!< CRYP GCM/GMAC or CCM/CMAC context swap register 2,        Address offset: 0x58 */
  volatile uint32_t CSGCMCCM3R; /*!< CRYP GCM/GMAC or CCM/CMAC context swap register 3,        Address offset: 0x5C */
  volatile uint32_t CSGCMCCM4R; /*!< CRYP GCM/GMAC or CCM/CMAC context swap register 4,        Address offset: 0x60 */
  volatile uint32_t CSGCMCCM5R; /*!< CRYP GCM/GMAC or CCM/CMAC context swap register 5,        Address offset: 0x64 */
  volatile uint32_t CSGCMCCM6R; /*!< CRYP GCM/GMAC or CCM/CMAC context swap register 6,        Address offset: 0x68 */
  volatile uint32_t CSGCMCCM7R; /*!< CRYP GCM/GMAC or CCM/CMAC context swap register 7,        Address offset: 0x6C */
  volatile uint32_t CSGCM0R;    /*!< CRYP GCM/GMAC context swap register 0,                    Address offset: 0x70 */
  volatile uint32_t CSGCM1R;    /*!< CRYP GCM/GMAC context swap register 1,                    Address offset: 0x74 */
  volatile uint32_t CSGCM2R;    /*!< CRYP GCM/GMAC context swap register 2,                    Address offset: 0x78 */
  volatile uint32_t CSGCM3R;    /*!< CRYP GCM/GMAC context swap register 3,                    Address offset: 0x7C */
  volatile uint32_t CSGCM4R;    /*!< CRYP GCM/GMAC context swap register 4,                    Address offset: 0x80 */
  volatile uint32_t CSGCM5R;    /*!< CRYP GCM/GMAC context swap register 5,                    Address offset: 0x84 */
  volatile uint32_t CSGCM6R;    /*!< CRYP GCM/GMAC context swap register 6,                    Address offset: 0x88 */
  volatile uint32_t CSGCM7R;    /*!< CRYP GCM/GMAC context swap register 7,                    Address offset: 0x8C */
} CRYP_TypeDef;

/*
 * @brief  (CSI)
 */
typedef struct
{
  volatile uint32_t CR;               /*!< CSI-2 Host control register                           Address offset: 0x0000 */
  volatile uint32_t PCR;              /*!< CSI-2 Host DPHY_RX control register                   Address offset: 0x0004 */
       uint32_t RESERVED0[2];     /*!< Reserved                                              Address offset: 0x0008-0x000C */
  volatile uint32_t VC0CFGR1;         /*!< CSI-2 Host virtual channel 0 configuration register 1 Address offset: 0x0010 */
  volatile uint32_t VC0CFGR2;         /*!< CSI-2 Host virtual channel 0 configuration register 2 Address offset: 0x0014 */
  volatile uint32_t VC0CFGR3;         /*!< CSI-2 Host virtual channel 0 configuration register 3 Address offset: 0x0018 */
  volatile uint32_t VC0CFGR4;         /*!< CSI-2 Host virtual channel 0 configuration register 4 Address offset: 0x001C */
  volatile uint32_t VC1CFGR1;         /*!< CSI-2 Host virtual channel 1 configuration register 1 Address offset: 0x0020 */
  volatile uint32_t VC1CFGR2;         /*!< CSI-2 Host virtual channel 1 configuration register 2 Address offset: 0x0024 */
  volatile uint32_t VC1CFGR3;         /*!< CSI-2 Host virtual channel 1 configuration register 3 Address offset: 0x0028 */
  volatile uint32_t VC1CFGR4;         /*!< CSI-2 Host virtual channel 1 configuration register 4 Address offset: 0x002C */
  volatile uint32_t VC2CFGR1;         /*!< CSI-2 Host virtual channel 2 configuration register 1 Address offset: 0x0030 */
  volatile uint32_t VC2CFGR2;         /*!< CSI-2 Host virtual channel 2 configuration register 2 Address offset: 0x0034 */
  volatile uint32_t VC2CFGR3;         /*!< CSI-2 Host virtual channel 2 configuration register 3 Address offset: 0x0038 */
  volatile uint32_t VC2CFGR4;         /*!< CSI-2 Host virtual channel 2 configuration register 4 Address offset: 0x003C */
  volatile uint32_t VC3CFGR1;         /*!< CSI-2 Host virtual channel 3 configuration register 1 Address offset: 0x0040 */
  volatile uint32_t VC3CFGR2;         /*!< CSI-2 Host virtual channel 3 configuration register 2 Address offset: 0x0044 */
  volatile uint32_t VC3CFGR3;         /*!< CSI-2 Host virtual channel 3 configuration register 3 Address offset: 0x0048 */
  volatile uint32_t VC3CFGR4;         /*!< CSI-2 Host virtual channel 3 configuration register 4 Address offset: 0x004C */
  volatile uint32_t LB0CFGR;          /*!< CSI-2 Host line byte 0 configuration register         Address offset: 0x0050 */
  volatile uint32_t LB1CFGR;          /*!< CSI-2 Host line byte 1 configuration register         Address offset: 0x0054 */
  volatile uint32_t LB2CFGR;          /*!< CSI-2 Host line byte 2 configuration register         Address offset: 0x0058 */
  volatile uint32_t LB3CFGR;          /*!< CSI-2 Host line byte 3 configuration register         Address offset: 0x005C */
  volatile uint32_t TIM0CFGR;         /*!< CSI-2 Host timer 0 configuration register             Address offset: 0x0060 */
  volatile uint32_t TIM1CFGR;         /*!< CSI-2 Host timer 1 configuration register             Address offset: 0x0064 */
  volatile uint32_t TIM2CFGR;         /*!< CSI-2 Host timer 2 configuration register             Address offset: 0x0068 */
  volatile uint32_t TIM3CFGR;         /*!< CSI-2 Host timer 3 configuration register             Address offset: 0x006C */
  volatile uint32_t LMCFGR;           /*!< CSI-2 Host lane merger configuration register         Address offset: 0x0070 */
  volatile uint32_t PRGITR;           /*!< CSI-2 Host program interrupt register                 Address offset: 0x0074 */
  volatile uint32_t WDR;              /*!< CSI-2 Host watchdog register                          Address offset: 0x0078 */
       uint32_t RESERVED1;        /*!< Reserved                                              Address offset: 0x007C */
  volatile uint32_t IER0;             /*!< CSI-2 Host Interrupt enable register 0                Address offset: 0x0080 */
  volatile uint32_t IER1;             /*!< CSI-2 Host Interrupt enable register 1                Address offset: 0x0084 */
       uint32_t RESERVED2[2];     /*!< Reserved                                              Address offset: 0x0088-0x008C */
  volatile uint32_t SR0;              /*!< CSI-2 Host status register 0                          Address offset: 0x0090 */
  volatile uint32_t SR1;              /*!< CSI-2 Host status register 1                          Address offset: 0x0094 */
       uint32_t RESERVED3[26];    /*!< Reserved                                              Address offset: 0x0098-0x00FC */
  volatile uint32_t FCR0;             /*!< CSI-2 Host Flag clear register 0                      Address offset: 0x0100 */
  volatile uint32_t FCR1;             /*!< CSI-2 Host Flag clear register 1                      Address offset: 0x0104 */
       uint32_t RESERVED4[2];     /*!< Reserved                                              Address offset: 0x0108-0x010C */
  volatile uint32_t SPDFR;            /*!< CSI-2 Host short packet data field register           Address offset: 0x0110 */
  volatile uint32_t ERR1;             /*!< CSI-2 Host error register 1                           Address offset: 0x0114 */
  volatile uint32_t ERR2;             /*!< CSI-2 Host error register 2                           Address offset: 0x0118 */
       uint32_t RESERVED5[953];   /*!< Reserved                                              Address offset: 0x011C-0x0FFC */
  volatile uint32_t PRCR;             /*!< CSI PHY reset control register                        Address offset: 0x1000 */
  volatile uint32_t PMCR;             /*!< CSI PHY mode control register                         Address offset: 0x1004 */
  volatile uint32_t PFCR;             /*!< CSI PHY frequency control register                    Address offset: 0x1008 */
       uint32_t RESERVED6;        /*!< Reserved                                              Address offset: 0x100C */
  volatile uint32_t PTCR0;            /*!< CSI PHY test control register 0                       Address offset: 0x1010 */
  volatile uint32_t PTCR1;            /*!< CSI PHY test control register 1                       Address offset: 0x1014 */
  volatile uint32_t PTSR;             /*!< CSI PHY test status register                          Address offset: 0x1018 */
       uint32_t RESERVED7[1017];  /*!< Reserved                                              Address offset: 0x101C-0x1FFC */
} CSI_TypeDef;

/**
  * @brief Debug MCU
  */
typedef struct
{
  volatile uint32_t IDCODE;        /*!< MCU device ID code,                            Address offset: 0x00  */
  volatile uint32_t CR;            /*!< Debug MCU configuration register,              Address offset: 0x04  */
  uint32_t RESERVED1[2];       /*!< Reserved,                                  Address offset: 0x08-0x0C */
  volatile uint32_t APB1LFZ1;      /*!< Debug MCU APB1LFZ1 freeze register,            Address offset: 0x10  */
  volatile uint32_t APB1HFZ1;      /*!< Debug MCU APB1HFZ1 freeze register,            Address offset: 0x14  */
  volatile uint32_t APB2FZ1;       /*!< Debug MCU APB2FZ1 freeze register,             Address offset: 0x18  */
  volatile uint32_t APB4FZ1;       /*!< Debug MCU APB4FZ1 freeze register,             Address offset: 0x1C  */
  volatile uint32_t APB5FZ1;       /*!< Debug MCU APB5FZ1 freeze register,             Address offset: 0x20  */
  volatile uint32_t AHB1FZ1;       /*!< Debug MCU AHB1FZ1 freeze register,             Address offset: 0x24  */
  volatile uint32_t AHB5FZ1;       /*!< Debug MCU AHB5FZ1 freeze register,             Address offset: 0x28  */
  uint32_t RESERVED2[52];      /*!< Reserved,                                  Address offset: 0x2C-0xF8 */
  volatile uint32_t SR;            /*!< Debug MCU status register,                     Address offset: 0xFC  */
  volatile uint32_t DBG_AUTH_HOST; /*!< Debug MCU authentication host register,        Address offset: 0x100 */
  volatile uint32_t DBG_AUTH_DEV;  /*!< Debug MCU authentication device register,      Address offset: 0x104 */
  volatile uint32_t DBG_AUTH_ACK;  /*!< Debug MCU acknowledge authentication register, Address offset: 0x104 */
} DBGMCU_TypeDef;

/**
  * @brief DCMI
  */
typedef struct
{
  volatile uint32_t CR;       /*!< DCMI control register 1,                       Address offset: 0x00 */
  volatile uint32_t SR;       /*!< DCMI status register,                          Address offset: 0x04 */
  volatile uint32_t RISR;     /*!< DCMI raw interrupt status register,            Address offset: 0x08 */
  volatile uint32_t IER;      /*!< DCMI interrupt enable register,                Address offset: 0x0C */
  volatile uint32_t MISR;     /*!< DCMI masked interrupt status register,         Address offset: 0x10 */
  volatile uint32_t ICR;      /*!< DCMI interrupt clear register,                 Address offset: 0x14 */
  volatile uint32_t ESCR;     /*!< DCMI embedded synchronization code register,   Address offset: 0x18 */
  volatile uint32_t ESUR;     /*!< DCMI embedded synchronization unmask register, Address offset: 0x1C */
  volatile uint32_t CWSTRTR;  /*!< DCMI crop window start,                        Address offset: 0x20 */
  volatile uint32_t CWSIZER;  /*!< DCMI crop window size,                         Address offset: 0x24 */
  volatile uint32_t DR;       /*!< DCMI data register,                            Address offset: 0x28 */
} DCMI_TypeDef;

#define DCMIPP_NUM_OF_PIPES 0x03U

typedef struct
{
  uint32_t PxRIxCR1;      /*! DCMIPP Pipex ROIx configuration register 1  Address offset: 0x924 + (x - 1) * 0x400, (x = 1 to 2)  */
  uint32_t PxRIxCR2;      /*! DCMIPP Pipex ROIx configuration register 2  Address offset: 0x928 + (x - 1) * 0x400, (x = 1 to 2)  */
} DCMIPP_Region_TypeDef;

/*
 * @brief Digital camera interface pixel pipeline DCMIPP
 */
typedef struct
{
  volatile uint32_t IPGR1;           /*!< DCMIPP IPPLUG global register 1                                    Address offset: 0x000 */
  volatile uint32_t IPGR2;           /*!< DCMIPP IPPLUG global register 2                                    Address offset: 0x004 */
  volatile uint32_t IPGR3;           /*!< DCMIPP IPPLUG global register 3                                    Address offset: 0x008 */
       uint32_t RESERVED0[4];    /*!< Reserved                                                           Address offset: 0x00C-0x018 */
  volatile uint32_t IPGR8;           /*!< DCMIPP IPPLUG identification register                              Address offset: 0x01C */
  volatile uint32_t IPC1R1;          /*!< DCMIPP IPPLUG Clientx register 1                                   Address offset: 0x020 + 0x10 * (x - 1), (x = 1 to 5) */
  volatile uint32_t IPC1R2;          /*!< DCMIPP IPPLUG Clientx register 2                                   Address offset: 0x024 + 0x10 * (x - 1), (x = 1 to 5) */
  volatile uint32_t IPC1R3;          /*!< DCMIPP IPPLUG Clientx register 3                                   Address offset: 0x028 + 0x10 * (x - 1), (x = 1 to 5) */
       uint32_t RESERVED1;       /*!< Reserved                                                           Address offset: 0x02C */
  volatile uint32_t IPC2R1;          /*!< DCMIPP IPPLUG Clientx register 1                                   Address offset: 0x030 */
  volatile uint32_t IPC2R2;          /*!< DCMIPP IPPLUG Clientx register 2                                   Address offset: 0x034 */
  volatile uint32_t IPC2R3;          /*!< DCMIPP IPPLUG Clientx register 3                                   Address offset: 0x038 */
       uint32_t RESERVED2;       /*!< Reserved                                                           Address offset: 0x03C */
  volatile uint32_t IPC3R1;          /*!< DCMIPP IPPLUG Clientx register 1                                   Address offset: 0x040 */
  volatile uint32_t IPC3R2;          /*!< DCMIPP IPPLUG Clientx register 2                                   Address offset: 0x044 */
  volatile uint32_t IPC3R3;          /*!< DCMIPP IPPLUG Clientx register 3                                   Address offset: 0x048 */
       uint32_t RESERVED3;       /*!< Reserved                                                           Address offset: 0x04C */
  volatile uint32_t IPC4R1;          /*!< DCMIPP IPPLUG Clientx register 1                                   Address offset: 0x050 */
  volatile uint32_t IPC4R2;          /*!< DCMIPP IPPLUG Clientx register 2                                   Address offset: 0x054 */
  volatile uint32_t IPC4R3;          /*!< DCMIPP IPPLUG Clientx register 3                                   Address offset: 0x058 */
       uint32_t RESERVED4;       /*!< Reserved                                                           Address offset: 0x05C */
  volatile uint32_t IPC5R1;          /*!< DCMIPP IPPLUG Clientx register 1                                   Address offset: 0x060 */
  volatile uint32_t IPC5R2;          /*!< DCMIPP IPPLUG Clientx register 2                                   Address offset: 0x064 */
  volatile uint32_t IPC5R3;          /*!< DCMIPP IPPLUG Clientx register 3                                   Address offset: 0x068 */
       uint32_t RESERVED5[38];   /*!< Reserved                                                           Address offset: 0x06C-0x100 */
  volatile uint32_t PRCR;            /*!< DCMIPP parallel interface control register                         Address offset: 0x104 */
  volatile uint32_t PRESCR;          /*!< DCMIPP parallel interface embedded synchronization code register   Address offset: 0x108 */
  volatile uint32_t PRESUR;          /*!< DCMIPP parallel interface embedded synchronization unmask register Address offset: 0x10C */
       uint32_t RESERVED6[57];   /*!< Reserved                                                           Address offset: 0x110-0x1F0 */
  volatile uint32_t PRIER;           /*!< DCMIPP parallel interface interrupt enable register                Address offset: 0x1F4 */
  volatile uint32_t PRSR;            /*!< DCMIPP parallel interface status register                          Address offset: 0x1F8 */
  volatile uint32_t PRFCR;           /*!< DCMIPP parallel interface interrupt clear register                 Address offset: 0x1FC */
       uint32_t RESERVED7;       /*!< Reserved                                                           Address offset: 0x200 */
  volatile uint32_t CMCR;            /*!< DCMIPP common configuration register                               Address offset: 0x204 */
  volatile uint32_t CMFRCR;          /*!< DCMIPP common frame counter register                               Address offset: 0x208 */
       uint32_t RESERVED8[121];  /*!< Reserved                                                           Address offset: 0x20C-0x3EC */
  volatile uint32_t CMIER;           /*!< DCMIPP common interrupt enable register                            Address offset: 0x3F0 */
  volatile uint32_t CMSR1;           /*!< DCMIPP common status register 1                                    Address offset: 0x3F4 */
  volatile uint32_t CMSR2;           /*!< DCMIPP common status register 2                                    Address offset: 0x3F8 */
  volatile uint32_t CMFCR;           /*!< DCMIPP common interrupt clear register                             Address offset: 0x3FC */
       uint32_t RESERVED9;            /*!< Reserved                                                      Address offset: 0x400 */
  volatile uint32_t P0FSCR;          /*!< DCMIPP Pipe0 flow selection configuration register                 Address offset: 0x404 */
       uint32_t RESERVED10[62];  /*!< Reserved                                                           Address offset: 0x408-0x4FC */
  volatile uint32_t P0FCTCR;         /*!< DCMIPP Pipe0 flow control configuration register                   Address offset: 0x500 */
  volatile uint32_t P0SCSTR;         /*!< DCMIPP Pipe0 stat/crop start register                              Address offset: 0x504 */
  volatile uint32_t P0SCSZR;         /*!< DCMIPP Pipe0 stat/crop size register                               Address offset: 0x508 */
       uint32_t RESERVED11[41];  /*!< Reserved                                                           Address offset: 0x50C-0x5AC */
  volatile uint32_t P0DCCNTR;        /*!< DCMIPP Pipe0 dump counter register                                 Address offset: 0x5B0 */
  volatile uint32_t P0DCLMTR;        /*!< DCMIPP Pipe0 dump limit register                                   Address offset: 0x5B4 */
       uint32_t RESERVED12[2];   /*!< Reserved                                                           Address offset: 0x5B8-0x5BC */
  volatile uint32_t P0PPCR;          /*!< DCMIPP Pipe0 pixel packer configuration register                   Address offset: 0x5C0 */
  volatile uint32_t P0PPM0AR1;       /*!< DCMIPP Pipe0 pixel packer Memory0 address register 1               Address offset: 0x5C4 */
  volatile uint32_t P0PPM0AR2;       /*!< DCMIPP Pipe0 pixel packer Memory0 address register 2               Address offset: 0x5C8 */
       uint32_t RESERVED13;      /*!< Reserved                                                           Address offset: 0x5C8-0x5CC */
  volatile uint32_t P0STM0AR;        /*!< DCMIPP Pipe0 status Memory0 address register                       Address offset: 0x5D0 */
       uint32_t RESERVED14[8];   /*!< Reserved                                                           Address offset: 0x5D4-0x5F0 */
  volatile uint32_t P0IER;           /*!< DCMIPP Pipe0 interrupt enable register                             Address offset: 0x5F4 */
  volatile uint32_t P0SR;            /*!< DCMIPP Pipe0 status register                                       Address offset: 0x5F8 */
  volatile uint32_t P0FCR;           /*!< DCMIPP Pipe0 interrupt clear register                              Address offset: 0x5FC */
       uint32_t RESERVED15;      /*!< Reserved                                                           Address offset: 0x600 */
  volatile uint32_t P0CFSCR;         /*!< DCMIPP Pipe0 current flow selection configuration register         Address offset: 0x604 */
       uint32_t RESERVED17[62];  /*!< Reserved                                                           Address offset: 0x608-0x6FC */
  volatile uint32_t P0CFCTCR;        /*!< DCMIPP Pipe0 current flow control configuration register           Address offset: 0x700 */
  volatile uint32_t P0CSCSTR;        /*!< DCMIPP Pipe0 current stat/crop start register                      Address offset: 0x704 */
  volatile uint32_t P0CSCSZR;        /*!< DCMIPP Pipe0 current stat/crop size register                       Address offset: 0x708 */
       uint32_t RESERVED18[45];  /*!< Reserved                                                           Address offset: 0x70C-0x7BC */
  volatile uint32_t P0CPPCR;         /*!< DCMIPP Pipe0 current pixel packer configuration register           Address offset: 0x7C0 */
  volatile uint32_t P0CPPM0AR1;      /*!< DCMIPP Pipe0 current pixel packer Memory0 address register 1       Address offset: 0x7C4 */
  volatile uint32_t P0CPPM0AR2;      /*!< DCMIPP Pipe0 current pixel packer Memory0 address register 2       Address offset: */
       uint32_t RESERVED19[14];  /*!< Reserved                                                           Address offset: 0x7C8-0x7FC */
  volatile uint32_t P1FSCR;          /*!< DCMIPP Pipe1 flow selection configuration register                 Address offset: 0x804 */
       uint32_t RESERVED20[6];   /*!< Reserved                                                           Address offset: 0x808-0x81C */
  volatile uint32_t P1SRCR;          /*!< DCMIPP Pipe1 stat removal configuration register                   Address offset: 0x820 */
  volatile uint32_t P1BPRCR;         /*!< DCMIPP Pipe1 bad pixel removal control register                    Address offset: 0x824 */
  volatile uint32_t P1BPRSR;         /*!< DCMIPP Pipe1 bad pixel removal status register                     Address offset: 0x828 */
       uint32_t RESERVED21;      /*!< Reserved                                                           Address offset: 0x82C */
  volatile uint32_t P1DECR;          /*!< DCMIPP Pipe1 decimation register                                   Address offset: 0x830 */
       uint32_t RESERVED22[3];   /*!< Reserved                                                           Address offset: 0x834-0x83C */
  volatile uint32_t P1BLCCR;         /*!< DCMIPP Pipe1 black level calibration control register              Address offset: 0x840 */
  volatile uint32_t P1EXCR1;         /*!< DCMIPP Pipe1 exposure control register 1                           Address offset: 0x844 */
  volatile uint32_t P1EXCR2;         /*!< DCMIPP Pipe1 exposure control register 2                           Address offset: 0x848 */
       uint32_t RESERVED23;      /*!< Reserved                                                           Address offset: 0x84C */
  volatile uint32_t P1ST1CR;         /*!< DCMIPP Pipe1 statistics 1 control register                         Address offset: 0x850 */
  volatile uint32_t P1ST2CR;         /*!< DCMIPP Pipe1 statistics 2 control register                         Address offset: 0x854 */
  volatile uint32_t P1ST3CR;         /*!< DCMIPP Pipe1 statistics 3 control register                         Address offset: 0x858 */
  volatile uint32_t P1STSTR;         /*!< DCMIPP Pipe1 statistics window start register                      Address offset: 0x85C */
  volatile uint32_t P1STSZR;         /*!< DCMIPP Pipe1 statistics window size register                       Address offset: 0x860 */
  volatile uint32_t P1ST1SR;         /*!< DCMIPP Pipe1 statistics 1 status register                          Address offset: 0x864 */
  volatile uint32_t P1ST2SR;         /*!< DCMIPP Pipe1 statistics 2 status register                          Address offset: 0x868 */
  volatile uint32_t P1ST3SR;         /*!< DCMIPP Pipe1 statistics 3 status register                          Address offset: 0x86C */
  volatile uint32_t P1DMCR;          /*!< DCMIPP Pipe1 demosaicing configuration register                    Address offset: 0x870 */
       uint32_t RESERVED24[3];   /*!< Reserved                                                           Address offset: 0x874-0x87C */
  volatile uint32_t P1CCCR;          /*!< DCMIPP Pipe1 ColorConv configuration register                      Address offset: 0x880 */
  volatile uint32_t P1CCRR1;         /*!< DCMIPP Pipe1 ColorConv red coefficient register 1                  Address offset: 0x884 */
  volatile uint32_t P1CCRR2;         /*!< DCMIPP Pipe1 ColorConv red coefficient register 2                  Address offset: 0x888 */
  volatile uint32_t P1CCGR1;         /*!< DCMIPP Pipe1 ColorConv green coefficient register 1                Address offset: 0x88C */
  volatile uint32_t P1CCGR2;         /*!< DCMIPP Pipe1 ColorConv green coefficient register 2                Address offset: 0x890 */
  volatile uint32_t P1CCBR1;         /*!< DCMIPP Pipe1 ColorConv blue coefficient register 1                 Address offset: 0x894 */
  volatile uint32_t P1CCBR2;         /*!< DCMIPP Pipe1 ColorConv blue coefficient register 2                 Address offset: 0x898 */
       uint32_t RESERVED25;      /*!< Reserved                                                           Address offset: 0x89C */
  volatile uint32_t P1CTCR1;         /*!< DCMIPP Pipe1 contrast control register 1                           Address offset: 0x8A0 */
  volatile uint32_t P1CTCR2;         /*!< DCMIPP Pipe1 contrast control register 2                           Address offset: 0x8A4 */
  volatile uint32_t P1CTCR3;         /*!< DCMIPP Pipe1 contrast control register 3                           Address offset: 0x8A8 */
       uint32_t RESERVED26[21];  /*!< Reserved                                                           Address offset: 0x8AC-0x8FC */
  volatile uint32_t P1FCTCR;         /*!< DCMIPP Pipe1 flow control configuration register                   Address offset: 0x900 */
  volatile uint32_t P1CRSTR;         /*!< DCMIPP Pipe1 crop window start register                            Address offset: 0x904 */
  volatile uint32_t P1CRSZR;         /*!< DCMIPP Pipe1 crop window size register                             Address offset: 0x908 */
  volatile uint32_t P1DCCR;          /*!< DCMIPP Pipe1 decimation register                                   Address offset: 0x90C */
  volatile uint32_t P1DSCR;          /*!< DCMIPP Pipe1 downsize configuration register                       Address offset: 0x910 */
  volatile uint32_t P1DSRTIOR;       /*!< DCMIPP Pipe1 downsize ratio register                               Address offset: 0x914 */
  volatile uint32_t P1DSSZR;         /*!< DCMIPP Pipe1 downsize destination size register                    Address offset: 0x918 */
       uint32_t RESERVED28;      /*!< Reserved                                                           Address offset:  */
  volatile uint32_t P1CMRICR;        /*!< DCMIPP Pipe1 common ROI configuration register                     Address offset: 0x920 */
  volatile uint32_t P1RIxCR1;        /*!< DCMIPP Pipe1 ROIx configuration register 1                         Address offset: 0x924 + (x - 1) * 0x8, (x = 1 to 8) */
  volatile uint32_t P1RIxCR2;        /*!< DCMIPP Pipe1 ROIx configuration register 2                         Address offset: 0x928 + (x - 1) * 0x8, (x = 1 to 8) */
       uint32_t RESERVED29[17];      /*!< Reserved                                                       Address offset:  */
  volatile uint32_t P1GMCR;          /*!< DCMIPP Pipe1 gamma configuration register                          Address offset: 0x970 */
       uint32_t RESERVED30[3];   /*!< Reserved                                                           Address offset: 0x974-0x97C */
  volatile uint32_t P1YUVCR;         /*!< DCMIPP Pipe1 YUVConv configuration register                        Address offset: 0x980 */
  volatile uint32_t P1YUVRR1;        /*!< DCMIPP Pipe1 YUVConv red coefficient register 1                    Address offset: 0x984 */
  volatile uint32_t P1YUVRR2;        /*!< DCMIPP Pipe1 YUVConv red coefficient register 2                    Address offset: 0x988 */
  volatile uint32_t P1YUVGR1;        /*!< DCMIPP Pipe1 YUVConv green coefficient register 1                  Address offset: 0x98C */
  volatile uint32_t P1YUVGR2;        /*!< DCMIPP Pipe1 YUVConv green coefficient register 2                  Address offset: 0x990 */
  volatile uint32_t P1YUVBR1;        /*!< DCMIPP Pipe1 YUVConv blue coefficient register 1                   Address offset: 0x994 */
  volatile uint32_t P1YUVBR2;        /*!< DCMIPP Pipe1 YUV blue coefficient register 2                       Address offset: 0x998 */
       uint32_t RESERVED31[9];   /*!< Reserved                                                           Address offset: 0x99C-0x9BC */
  volatile uint32_t P1PPCR;          /*!< DCMIPP Pipe1 pixel packer configuration register                   Address offset: 0x9C0 */
  volatile uint32_t P1PPM0AR1;       /*!< DCMIPP Pipe1 pixel packer Memory0 address register 1               Address offset: 0x9C4 */
  volatile uint32_t P1PPM0AR2;       /*!< DCMIPP Pipe1 pixel packer Memory0 address register 2               Address offset: 0x9C8 */
  volatile uint32_t P1PPM0PR;        /*!< DCMIPP Pipe1 pixel packer Memory0 pitch register                   Address offset: 0x9CC */
  volatile uint32_t P1STM0AR;        /*!< DCMIPP Pipe1 status Memory0 address register                       Address offset: 0x9D0 */
  volatile uint32_t P1PPM1AR1;       /*!< DCMIPP Pipe1 pixel packer Memory1 address register 1               Address offset: 0x9D4 */
  volatile uint32_t P1PPM1AR2;       /*!< DCMIPP Pipe1 pixel packer Memory1 address register 2               Address offset: 0x9D8 */
  volatile uint32_t P1PPM1PR;        /*!< DCMIPP Pipe1 pixel packer Memory1 pitch register                   Address offset: 0x9DC */
  volatile uint32_t P1STM1AR;        /*!< DCMIPP Pipe1 status Memory1 address register                       Address offset: 0x9E0 */
  volatile uint32_t P1PPM2AR1;       /*!< DCMIPP Pipe1 pixel packer memory2 address register 1               Address offset: 0x9E4 */
  volatile uint32_t P1PPM2AR2;       /*!< DCMIPP Pipe1 pixel packer memory2 address register 2               Address offset: 0x9E8 */
  volatile uint32_t RESERVED34;      /*!< Reserved                                                           Address offset: 0x9EC */
  volatile uint32_t P1STM2AR;        /*!< DCMIPP Pipe1 status Memory2 address register                       Address offset: 0x9F0 */
  volatile uint32_t P1IER;           /*!< DCMIPP Pipe1 interrupt enable register                             Address offset: 0x9F4 */
  volatile uint32_t P1SR;            /*!< DCMIPP Pipe1 status register                                       Address offset: 0x9F8 */
  volatile uint32_t P1FCR;           /*!< DCMIPP Pipe1 interrupt clear register                              Address offset: 0x9FC */
       uint32_t RESERVED35;      /*!< Reserved                                                           Address offset: 0xA00 */
  volatile uint32_t P1CFSCR;         /*!< DCMIPP Pipe1 current flow selection configuration register         Address offset: 0xA04 */
       uint32_t RESERVED36[7];   /*!< Reserved                                                           Address offset: 0xA08-0xA20 */
  volatile uint32_t P1CBPRCR;        /*!< DCMIPP Pipe1 current bad pixel removal register                    Address offset: 0xA24 */
       uint32_t RESERVED37[6];   /*!< Reserved                                                           Address offset: 0xA28-0xA3C */
  volatile uint32_t P1CBLCCR;        /*!< DCMIPP Pipe1 current black level calibration control register      Address offset: 0xA40 */
  volatile uint32_t P1CEXCR1;        /*!< DCMIPP Pipe1 current exposure control register 1                   Address offset: 0xA44 */
  volatile uint32_t P1CEXCR2;        /*!< DCMIPP Pipe1 current exposure control register 2                   Address offset: 0xA48 */
       uint32_t RESERVED38;      /*!< Reserved                                                           Address offset: 0xA4C */
  volatile uint32_t P1CST1CR;        /*!< DCMIPP Pipe1 current statistics 1 control register                 Address offset: 0xA50 */
  volatile uint32_t P1CST2CR;        /*!< DCMIPP Pipe1 current statistics 2 control register                 Address offset: 0xA54 */
  volatile uint32_t P1CST3CR;        /*!< DCMIPP Pipe1 current statistics 3 control register                 Address offset: 0xA58 */
  volatile uint32_t P1CSTSTR;        /*!< DCMIPP Pipe1 current statistics window start register              Address offset: 0xA5C */
  volatile uint32_t P1CSTSZR;        /*!< DCMIPP Pipe1 current statistics window size register               Address offset: 0xA60 */
       uint32_t RESERVED39[7];   /*!< Reserved                                                           Address offset: 0xA64-0xA7C */
  volatile uint32_t P1CCCCR;         /*!< DCMIPP Pipe1 current ColorConv configuration register              Address offset: 0xA80 */
  volatile uint32_t P1CCCRR1;        /*!< DCMIPP Pipe1 current ColorConv red coefficient register 1          Address offset: 0xA84 */
  volatile uint32_t P1CCCRR2;        /*!< DCMIPP Pipe1 current ColorConv red coefficient register 2          Address offset: 0xA88 */
  volatile uint32_t P1CCCGR1;        /*!< DCMIPP Pipe1 current ColorConv green coefficient register 1        Address offset: 0xA8C */
  volatile uint32_t P1CCCGR2;        /*!< DCMIPP Pipe1 current ColorConv green coefficient register 2        Address offset: 0xA90 */
  volatile uint32_t P1CCCBR1;        /*!< DCMIPP Pipe1 current ColorConv blue coefficient register 1         Address offset: 0xA94 */
  volatile uint32_t P1CCCBR2;        /*!< DCMIPP Pipe1 current ColorConv blue coefficient register 2         Address offset: 0xA98 */
       uint32_t RESERVED40;      /*!< Reserved                                                           Address offset: 0xA9C */
  volatile uint32_t P1CCTCR1;        /*!< DCMIPP Pipe1 current contrast control register 1                   Address offset: 0xAA0 */
  volatile uint32_t P1CCTCR2;        /*!< DCMIPP Pipe1 current contrast control register 2                   Address offset: 0xAA4 */
  volatile uint32_t P1CCTCR3;        /*!< DCMIPP Pipe1 current contrast control register 3                   Address offset: 0xAA8 */
       uint32_t RESERVED41[21];  /*!< Reserved                                                           Address offset: 0xAAC-0xAFC */
  volatile uint32_t P1CFCTCR;        /*!< DCMIPP Pipe1 current flow control configuration register           Address offset: 0xB00 */
  volatile uint32_t P1CCRSTR;        /*!< DCMIPP Pipe1 current crop window start register                    Address offset: 0xB04 */
  volatile uint32_t P1CCRSZR;        /*!< DCMIPP Pipe1 current crop window size register                     Address offset: 0xB08 */
  volatile uint32_t P1CDCCR;         /*!< DCMIPP Pipe1 current decimation register                           Address offset: 0xB0C */
  volatile uint32_t P1CDSCR;         /*!< DCMIPP Pipe1 current downsize configuration register               Address offset: 0xB10 */
  volatile uint32_t P1CDSRTIOR;      /*!< DCMIPP Pipe1 current downsize ratio register                       Address offset: 0xB14 */
  volatile uint32_t P1CDSSZR;        /*!< DCMIPP Pipe1 current downsize destination size register            Address offset: 0xB18 */
       uint32_t RESERVED43;      /*!< Reserved                                                           Address offset: 0xB1C */
       uint32_t P1CCMRICR;       /*!< DCMIPP Pipe1 current common ROI configuration register             Address offset: 0xB20 */
  volatile uint32_t P1CRIxCR1;       /*!< DCMIPP Pipe1 current ROIx configuration register 1                 Address offset: 0xB24 + 0x8 * (x - 1), (x = 1 to 8) */
  volatile uint32_t P1CRIxCR2;       /*!< DCMIPP Pipe1 current ROIx configuration register 2                 Address offset: 0xB28 + 0x8 * (x - 1), (x = 1 to 8) */
  uint32_t RESERVED44[37];       /*!< Reserved                                                           Address offset: 0xB64-0xBBC */
  volatile uint32_t P1CPPCR;         /*!< DCMIPP Pipe1 current pixel packer configuration register           Address offset: 0xBC0 */
  volatile uint32_t P1CPPM0AR1;      /*!< DCMIPP Pipe1 current pixel packer Memory0 address register 1       Address offset: 0xBC4 */
  volatile uint32_t P1CPPM0AR2;      /*!< DCMIPP Pipe1 current pixel packer Memory0 address register 1       Address offset: 0xBC8 */
  volatile uint32_t P1CPPM0PR;       /*!< DCMIPP Pipe1 current pixel packer Memory0 pitch register           Address offset: 0xBCC */
       uint32_t RESERVED45;      /*!< Reserved                                                           Address offset: 0xBD0 */
  volatile uint32_t P1CPPM1AR1;      /*!< DCMIPP Pipe1 current pixel packer Memory1 address register 1       Address offset: 0xBD4 */
  volatile uint32_t P1CPPM1AR2;      /*!< DCMIPP Pipe1 current pixel packer Memory1 address register 2       Address offset: 0xBD8 */
  volatile uint32_t P1CPPM1PR;       /*!< DCMIPP Pipe1 current pixel packer Memory1 pitch register           Address offset: 0xBDC */
       uint32_t RESERVED47;      /*!< Reserved                                                           Address offset: 0xBE0 */
  volatile uint32_t P1CPPM2AR1;      /*!< DCMIPP Pipe1 current pixel packer memory2 address register 1       Address offset: 0xBE4 */
  volatile uint32_t P1CPPM2AR2;      /*!< DCMIPP Pipe1 current pixel packer Memory2 address register 2       Address offset: 0xBE8 */
       uint32_t RESERVED48[6];   /*!< Reserved                                                           Address offset: 0xBE8-0xBFC */
  volatile uint32_t P2FSCR;          /*!< DCMIPP Pipe2 flow selection configuration register                 Address offset: 0xC04 */
       uint32_t RESERVED49[62];  /*!< Reserved                                                           Address offset: 0xC08-0xCFC */
  volatile uint32_t P2FCTCR;         /*!< DCMIPP Pipe2 flow control configuration register                   Address offset: 0xD00 */
  volatile uint32_t P2CRSTR;         /*!< DCMIPP Pipe2 crop window start register                            Address offset: 0xD04 */
  volatile uint32_t P2CRSZR;         /*!< DCMIPP Pipe2 crop window size register                             Address offset: 0xD08 */
  volatile uint32_t P2DCCR;          /*!< DCMIPP Pipe2 decimation register                                   Address offset: 0xD0C */
  volatile uint32_t P2DSCR;          /*!< DCMIPP Pipe2 downsize configuration register                       Address offset: 0xD10 */
  volatile uint32_t P2DSRTIOR;       /*!< DCMIPP Pipe2 downsize ratio register                               Address offset: 0xD14 */
  volatile uint32_t P2DSSZR;         /*!< DCMIPP Pipe2 downsize destination size register                    Address offset: 0xD18 */
       uint32_t RESERVED51;      /*!< Reserved                                                           Address offset:  0xD1C */
  volatile uint32_t P2CMRICR;        /*!< DCMIPP Pipe2 common ROI configuration register                     Address offset:  0xD20 */
  volatile uint32_t P2RIxCR1;        /*!< DCMIPP Pipe2 ROIx configuration register 1                         Address offset: 0xD24 + (x - 1) * 0x8, (x = 1 to 8) */
  volatile uint32_t P2RIxCR2;        /*!< DCMIPP Pipe2 ROIx configuration register 2                         Address offset: 0xD28 + (x - 1) * 0x8, (x = 1 to 8) */
       uint32_t RESERVED53[17];  /*!< Reserved                                                           Address offset: */
  volatile uint32_t P2GMCR;          /*!< DCMIPP Pipe2 gamma configuration register                          Address offset: 0xD70 */
       uint32_t RESERVED54[19];  /*!< Reserved                                                           Address offset: 0xD74-0xDBC */
  volatile uint32_t P2PPCR;          /*!< DCMIPP Pipe2 pixel packer configuration register                   Address offset: 0xDC0 */
  volatile uint32_t P2PPM0AR1;       /*!< DCMIPP Pipe2 pixel packer Memory0 address register 1               Address offset: 0xDC4 */
  volatile uint32_t P2PPM0AR2;       /*!< DCMIPP Pipe2 pixel packer Memory0 address register 2               Address offset: 0xDC8 */
  volatile uint32_t P2PPM0PR;        /*!< DCMIPP Pipe2 pixel packer Memory0 pitch register                   Address offset: 0xDCC */
  volatile uint32_t P2STM0AR;        /*!< DCMIPP Pipe2 status Memory0 address register                       Address offset: 0xDD0 */
       uint32_t RESERVED55[8];   /*!< Reserved                                                           Address offset: 0xDD4-0xDF0 */
  volatile uint32_t P2IER;           /*!< DCMIPP Pipe2 interrupt enable register                             Address offset: 0xDF4 */
  volatile uint32_t P2SR;            /*!< DCMIPP Pipe2 status register                                       Address offset: 0xDF8 */
  volatile uint32_t P2FCR;           /*!< DCMIPP Pipe2 interrupt clear register                              Address offset: 0xDFC */
       uint32_t RESERVED56;      /*!< Reserved                                                           Address offset: 0xE00 */
  volatile uint32_t P2CFSCR;         /*!< DCMIPP Pipe2 current flow selection configuration register         Address offset: 0xE04 */
       uint32_t RESERVED57[62];  /*!< Reserved                                                           Address offset: 0xE08-0xEFC */
  volatile uint32_t P2CFCTCR;        /*!< DCMIPP Pipe2 current flow control configuration register           Address offset: 0xF00 */
  volatile uint32_t P2CCRSTR;        /*!< DCMIPP Pipe2 current crop window start register                    Address offset: 0xF04 */
  volatile uint32_t P2CCRSZR;        /*!< DCMIPP Pipe2 current crop window size register                     Address offset: 0xF08 */
  volatile uint32_t P2CDCCR;         /*!< DCMIPP Pipe2 current decimation register                           Address offset: 0xF0C */
  volatile uint32_t P2CDSCR;         /*!< DCMIPP Pipe2 current downsize configuration register               Address offset: 0xF10 */
  volatile uint32_t P2CDSRTIOR;      /*!< DCMIPP Pipe2 current downsize ratio register                       Address offset: 0xF14 */
  volatile uint32_t P2CDSSZR;        /*!< DCMIPP Pipe2 current downsize destination size register            Address offset: 0xF18 */
  volatile uint32_t RESERVED59[2];   /*!< Reserved                                                           Address offset: 0xF1C-0xF20 */
  volatile uint32_t P2CRIxCR1;       /*!< Pipe2 current ROIx configuration register 1                        Address offset: 0xF24 + (x - 1) * 0x8, (x = 1 to 8)*/
  volatile uint32_t P2CRIxCR2;       /*!< Pipe2 current ROIx configuration register 2                        Address offset: 0xF28 + (x - 1) * 0x8, (x = 1 to 8)*/
       uint32_t RESERVED60[37];  /*!< Reserved                                                           Address offset: 0xF64-0xFBC */
  volatile uint32_t P2CPPCR;         /*!< DCMIPP Pipe2 current pixel packer configuration register           Address offset: 0xFC0 */
  volatile uint32_t P2CPPM0AR1;      /*!< DCMIPP Pipe2 current pixel packer Memory0 address register 1       Address offset: 0xFC4 */
  volatile uint32_t P2CPPM0AR2;      /*!< DCMIPP Pipe2 current pixel packer Memory0 address register 2       Address offset: 0xFC8 */
  volatile uint32_t P2CPPM0PR;       /*!< DCMIPP Pipe2 current pixel packer Memory0 pitch register           Address offset: 0xFCC */
       uint32_t RESERVED61[7];   /*!< Reserved                                                           Address offset: 0xFD0-0xFE8 */
  volatile uint32_t HWCFGR2;         /*!< DCMIPP hardware configuration register 2                           Address offset: 0xFEC */
  volatile uint32_t HWCFGR1;         /*!< DCMIPP hardware configuration register 1                           Address offset: 0xFF0 */
  volatile uint32_t VERR;            /*!< DCMIPP version register                                            Address offset: 0xFF4 */
  volatile uint32_t IPIDR;           /*!< DCMIPP identification register                                     Address offset: 0xFF8 */
  volatile uint32_t SIDR;            /*!< DCMIPP size identification register                                Address offset: 0xFFC */
} DCMIPP_TypeDef;

/**
  * @ brief Delay Block
  */
typedef struct
{
  volatile uint32_t CFG;            /*!< Delay Block Configuration Register,                                 Address offset: 0x00 */
  volatile uint32_t STATUS;         /*!< Delay Block Status Register,                                        Address offset: 0x04 */
} DLYB_TypeDef;

/**
  * @brief DMA Controller
  */

typedef struct
{
  volatile uint32_t SECCFGR;      /*!< DMA secure configuration register,               Address offset: 0x00  */
  volatile uint32_t PRIVCFGR;     /*!< DMA privileged configuration register,           Address offset: 0x04 */
  volatile uint32_t RCFGLOCKR;    /*!< DMA configuration lock register,                 Address offset: 0x08 */
  volatile uint32_t MISR;         /*!< DMA non secure masked interrupt status register, Address offset: 0x0C  */
  volatile uint32_t SMISR;        /*!< DMA secure masked interrupt status register,     Address offset: 0x10  */
} DMA_TypeDef;

typedef struct
{
  volatile uint32_t CLBAR;         /*!< DMA channel x linked-list base address register, Address offset: 0x50 + (x * 0x80) */
  volatile uint32_t CCIDCFGR;      /*!< DMA channel x CID register,                      Address offset: 0x54 + (x * 0x80) */
       uint32_t RESERVED1[1];  /*!< Reserved 1,                                      Address offset: 0x58 + (x * 0x80) */
  volatile uint32_t CFCR;          /*!< DMA channel x flag clear register,               Address offset: 0x5C + (x * 0x80) */
  volatile uint32_t CSR;           /*!< DMA channel x flag status register,              Address offset: 0x60 + (x * 0x80) */
  volatile uint32_t CCR;           /*!< DMA channel x control register,                  Address offset: 0x64 + (x * 0x80) */
       uint32_t RESERVED2[10]; /*!< Reserved 2,                                      Address offset: 0x68 -- 0x8C + (x * 0x80) */
  volatile uint32_t CTR1;          /*!< DMA channel x transfer register 1,               Address offset: 0x90 + (x * 0x80) */
  volatile uint32_t CTR2;          /*!< DMA channel x transfer register 2,               Address offset: 0x94 + (x * 0x80) */
  volatile uint32_t CBR1;          /*!< DMA channel x block register 1,                  Address offset: 0x98 + (x * 0x80) */
  volatile uint32_t CSAR;          /*!< DMA channel x source address register,           Address offset: 0x9C + (x * 0x80) */
  volatile uint32_t CDAR;          /*!< DMA channel x destination address register,      Address offset: 0xA0 + (x * 0x80) */
  volatile uint32_t CTR3;          /*!< DMA channel x transfer register 3,               Address offset: 0xA4 + (x * 0x80) */
  volatile uint32_t CBR2;          /*!< DMA channel x block register 2,                  Address offset: 0xA8 + (x * 0x80) */
       uint32_t RESERVED3[8];  /*!< Reserved 3,                                      Address offset: 0xAC -- 0xC8 + (x * 0x80) */
  volatile uint32_t CLLR;          /*!< DMA channel x linked-list address register,      Address offset: 0xCC + (x * 0x80) */
} DMA_Channel_TypeDef;

/**
  * @brief DMA2D Controller
  */
typedef struct
{
  volatile uint32_t CR;            /*!< DMA2D Control Register,                         Address offset: 0x00 */
  volatile uint32_t ISR;           /*!< DMA2D Interrupt Status Register,                Address offset: 0x04 */
  volatile uint32_t IFCR;          /*!< DMA2D Interrupt Flag Clear Register,            Address offset: 0x08 */
  volatile uint32_t FGMAR;         /*!< DMA2D Foreground Memory Address Register,       Address offset: 0x0C */
  volatile uint32_t FGOR;          /*!< DMA2D Foreground Offset Register,               Address offset: 0x10 */
  volatile uint32_t BGMAR;         /*!< DMA2D Background Memory Address Register,       Address offset: 0x14 */
  volatile uint32_t BGOR;          /*!< DMA2D Background Offset Register,               Address offset: 0x18 */
  volatile uint32_t FGPFCCR;       /*!< DMA2D Foreground PFC Control Register,          Address offset: 0x1C */
  volatile uint32_t FGCOLR;        /*!< DMA2D Foreground Color Register,                Address offset: 0x20 */
  volatile uint32_t BGPFCCR;       /*!< DMA2D Background PFC Control Register,          Address offset: 0x24 */
  volatile uint32_t BGCOLR;        /*!< DMA2D Background Color Register,                Address offset: 0x28 */
  volatile uint32_t FGCMAR;        /*!< DMA2D Foreground CLUT Memory Address Register,  Address offset: 0x2C */
  volatile uint32_t BGCMAR;        /*!< DMA2D Background CLUT Memory Address Register,  Address offset: 0x30 */
  volatile uint32_t OPFCCR;        /*!< DMA2D Output PFC Control Register,              Address offset: 0x34 */
  volatile uint32_t OCOLR;         /*!< DMA2D Output Color Register,                    Address offset: 0x38 */
  volatile uint32_t OMAR;          /*!< DMA2D Output Memory Address Register,           Address offset: 0x3C */
  volatile uint32_t OOR;           /*!< DMA2D Output Offset Register,                   Address offset: 0x40 */
  volatile uint32_t NLR;           /*!< DMA2D Number of Line Register,                  Address offset: 0x44 */
  volatile uint32_t LWR;           /*!< DMA2D Line Watermark Register,                  Address offset: 0x48 */
  volatile uint32_t AMTCR;         /*!< DMA2D AHB Master Timer Configuration Register,  Address offset: 0x4C */
  uint32_t      RESERVED[236]; /*!< Reserved,                                 Address offset: 0x50-0x3FF */
  volatile uint32_t FGCLUT[256];   /*!< DMA2D Foreground CLUT,                    Address offset:0x400-0x7FF */
  volatile uint32_t BGCLUT[256];   /*!< DMA2D Background CLUT,                    Address offset:0x800-0xBFF */
} DMA2D_TypeDef;

/**
  * @brief DTS Controller
  */
typedef struct
{
  uint32_t      RESERVED1[4];    /*!< Reserved,                                 Address offset: 0x00-0x0F */
  volatile uint32_t PVTREG_LOCKR;    /*!< DTS PVT Register Lock Register,           Address offset: 0x10 */
  volatile uint32_t PVTLOCK_SR;      /*!< DTS PVT Lock Status Register,             Address offset: 0x14 */
  uint32_t      RESERVED2[2];    /*!< Reserved,                                 Address offset: 0x18-0x1F */
  volatile uint32_t PVTTMR_CR;       /*!< DTS PVT Timer Control Register,           Address offset: 0x20 */
  volatile uint32_t PVTTMR_SR;       /*!< DTS PVT Timer Status Register,            Address offset: 0x24 */
  uint32_t      RESERVED3[6];    /*!< Reserved,                                 Address offset: 0x28-0x3F */
  volatile uint32_t PVT_IER;         /*!< DTS PVT IRQ Enable Register,              Address offset: 0x40 */
  uint32_t      RESERVED4[3];    /*!< Reserved,                                 Address offset: 0x44-0x4F */
  volatile uint32_t PVTIRQTRMASKR;   /*!< DTS PVT IRQ Timer Mask Register,          Address offset: 0x50 */
  volatile uint32_t TS_MR;           /*!< DTS PVT IRQ TS Mask Register,             Address offset: 0x54 */
  uint32_t      RESERVED5[2];    /*!< Reserved,                                 Address offset: 0x58-0x5F */
  volatile uint32_t PVTTR_SR;        /*!< DTS PVT IRQ Timer Status Register,        Address offset: 0x60 */
  volatile uint32_t TS_ISR;          /*!< DTS PVT IRQ TS Status Register,           Address offset: 0x64 */
  uint32_t      RESERVED6[2];    /*!< Reserved,                                 Address offset: 0x68-0x6F */
  volatile uint32_t PVTTMRRAW_ISR;   /*!< DTS PVT IRQ Timer Raw Status Register,    Address offset: 0x70 */
  volatile uint32_t TSRAW_ISR;       /*!< DTS PVT IRQ TS Raw Status Register,       Address offset: 0x74 */
  uint32_t      RESERVED7[2];    /*!< Reserved,                                 Address offset: 0x78-0x7F */
  volatile uint32_t TSCCLKSYNTHR;    /*!< DTS TSC Clock Synthesizer Register,       Address offset: 0x80 */
  volatile uint32_t TSCSDIFDISABLER; /*!< DTS TSC SDIF Interface Disable Register,  Address offset: 0x84 */
  volatile uint32_t TSCSDIF_SR;      /*!< DTS TSC SDIF Status Register,             Address offset: 0x88 */
  volatile uint32_t TSCSDIF_CR;      /*!< DTS TSC SDIF Register,                    Address offset: 0x8C */
  volatile uint32_t TSCSDIFHALTR;    /*!< DTS TSC SDIF Halt Register,               Address offset: 0x90 */
  volatile uint32_t TSCSDIF_CFGR;    /*!< DTS TSC SDIF Control Register,            Address offset: 0x94 */
  uint32_t      RESERVED8[2];    /*!< Reserved,                                 Address offset: 0x98-0x9F */
  volatile uint32_t TSCSMPL_CR;      /*!< DTS TSC Sample Control Register,          Address offset: 0xA0 */
  volatile uint32_t TSCSDIFSMPLCLRR; /*!< DTS TSC Sample Clear Register,            Address offset: 0xA4 */
  volatile uint32_t TSCSMPLCNTR;     /*!< DTS TSC Sample Count Register,            Address offset: 0xA8 */
} DTS_TypeDef;

/**
  * @brief DTS Sensor Controller
  */
typedef struct
{
  volatile uint32_t TS_IER;          /*!< DTS TSx IRQ Enable Register,              Address offset: 0xC0 + 0x40 * x, (x = 0 to 1) */
  volatile uint32_t TS_ISR;          /*!< DTS TSx IRQ Status Register,              Address offset: 0xC4 + 0x40 * x, (x = 0 to 1) */
  volatile uint32_t TS_ICR;          /*!< DTS TSx IRQ Clear Register,               Address offset: 0xC8 + 0x40 * x, (x = 0 to 1) */
  volatile uint32_t TSIRQTESTR;      /*!< DTS TSx IRQ Test Register,                Address offset: 0xCC + 0x40 * x, (x = 0 to 1) */
  volatile uint32_t TSSDIFRDATAR;    /*!< DTS TSx SDIF RDATA Register,              Address offset: 0xD0 + 0x40 * x, (x = 0 to 1) */
  volatile uint32_t TSSDIFDONER;     /*!< DTS TSx SDIF Done Register,               Address offset: 0xD4 + 0x40 * x, (x = 0 to 1) */
  volatile uint32_t TSSDIFDATAR;     /*!< DTS TSx SDIF Data Register,               Address offset: 0xD8 + 0x40 * x, (x = 0 to 1) */
  uint32_t      RESERVED1[1];    /*!< Reserved,                                 Address offset: 0xDC + 0x40 * x, (x = 0 to 1) */
  volatile uint32_t TSALARMA_CFGR;   /*!< DTS TSx Alarm A Configuration Register,   Address offset: 0xE0 + 0x40 * x, (x = 0 to 1) */
  volatile uint32_t TSALARMB_CFGR;   /*!< DTS TSx Alarm B Configuration Register,   Address offset: 0xE4 + 0x40 * x, (x = 0 to 1) */
  volatile uint32_t TSHLSAMPLER;     /*!< DTS TSx High/Low Sample Register,         Address offset: 0xE8 + 0x40 * x, (x = 0 to 1) */
  volatile uint32_t TSHILORESETR;    /*!< DTS TSx High/Low Reset Register,          Address offset: 0xEC + 0x40 * x, (x = 0 to 1) */
} DTS_SensorTypeDef;

/**
  * @brief Ethernet MAC
  */
typedef struct
{
  volatile uint32_t MACCR;               /*!< Operating mode configuration register,                        Address offset: 0x00 */
  volatile uint32_t MACECR;              /*!< Extended operating mode configuration register,               Address offset: 0x04 */
  volatile uint32_t MACPFR;              /*!< Packet filtering control register             ,               Address offset: 0x08 */
  volatile uint32_t MACWTR;              /*!< Watchdog timeout register,                                    Address offset: 0x0C */
  volatile uint32_t MACHT0R;             /*!< Hash Table 0 register,                                        Address offset: 0x10 */
  volatile uint32_t MACHT1R;             /*!< Hash Table 1 register,                                        Address offset: 0x14 */
  uint32_t      RESERVED1[14];
  volatile uint32_t MACVTCR;             /*!< VLAN tag Control register,                                    Address offset: 0x50 */
  volatile uint32_t MACVTDR;             /*!< VLAN tag data register,                                       Address offset: 0x54 */
  volatile uint32_t MACVHTR;             /*!< VLAN Hash table register,                                     Address offset: 0x58 */
  uint32_t      RESERVED2;
  volatile uint32_t MACVIR;              /*!< VLAN inclusion register,                                      Address offset: 0x60 */
  volatile uint32_t MACIVIR;             /*!< Inner VLAN inclusion register,                                Address offset: 0x64 */
  uint32_t      RESERVED3[2];
  volatile uint32_t MACQ0TXFCR;          /*!< Tx Queue 0 flow control register,                             Address offset: 0x70 */
  uint32_t      RESERVED4[7];
  volatile uint32_t MACRXFCR;            /*!< Rx flow control register,                                     Address offset: 0x90 */
  volatile uint32_t MACRXQCR;            /*!< Rx Queue control register,                                    Address offset: 0x94 */
  uint32_t      RESERVED5[2];
  volatile uint32_t MACRXQC0R;           /*!< Rx queue control 0 register,                                  Address offset: 0xA0 */
  volatile uint32_t MACRXQC1R;           /*!< Rx queue control 1 register,                                  Address offset: 0xA4 */
  volatile uint32_t MACRXQC2R;           /*!< Rx queue control 2 register,                                  Address offset: 0xA8 */
  uint32_t      RESERVED6;
  volatile uint32_t MACISR;              /*!< Interrupt status register,                                    Address offset: 0xB0 */
  volatile uint32_t MACIER;              /*!< Interrupt enable register,                                    Address offset: 0xB4 */
  volatile uint32_t MACRXTXSR;           /*!< Rx Tx status register,                                        Address offset: 0xB8 */
  uint32_t      RESERVED7;
  volatile uint32_t MACPCSR;             /*!< PMT control status register,                                  Address offset: 0xC0 */
  volatile uint32_t MACRWKPFR;           /*!< Remote wakeup packet filter register,                         Address offset: 0xC4 */
  uint32_t      RESERVED8[2];
  volatile uint32_t MACLCSR;             /*!< LPI control and status register,                              Address offset: 0xD0 */
  volatile uint32_t MACLTCR;             /*!< LPI timers control register,                                  Address offset: 0xD4 */
  volatile uint32_t MACLETR;             /*!< LPI entry timer register,                                     Address offset: 0xD8 */
  volatile uint32_t MAC1USTCR;           /*!< One-microsecond-tick counter register,                        Address offset: 0xDC */
  uint32_t      RESERVED9[6];
  volatile uint32_t MACPHYCSR;           /*!< PHYIF control status register,                                Address offset: 0xF8 */
  uint32_t      RESERVED10[5];
  volatile uint32_t MACVR;               /*!< Version register,                                             Address offset: 0x110 */
  volatile uint32_t MACDR;               /*!< Debug register,                                               Address offset: 0x114 */
  uint32_t      RESERVED11;
  volatile uint32_t MACHWF0R;            /*!< HW feature 0 register,                                        Address offset: 0x11C */
  volatile uint32_t MACHWF1R;            /*!< HW feature 1 register,                                        Address offset: 0x120 */
  volatile uint32_t MACHWF2R;            /*!< HW feature 2 register,                                        Address offset: 0x124 */
  volatile uint32_t MACHWF3R;            /*!< HW feature 3 register,                                        Address offset: 0x128 */
  uint32_t      RESERVED12[53];
  volatile uint32_t MACMDIOAR;           /*!< MDIO address register,                                        Address offset: 0x200 */
  volatile uint32_t MACMDIODR;           /*!< MDIO data register,                                           Address offset: 0x204 */
  uint32_t      RESERVED13[2];
  volatile uint32_t MACARPAR;            /*!< ARP address register,                                         Address offset: 0x210 */
  uint32_t      RESERVED14[7];
  volatile uint32_t MACCSRSWCR;          /*!< CSR software control register,                                Address offset: 0x230 */
  volatile uint32_t MACFPECSR;           /*!< FPE control and status register,                              Address offset: 0x234 */
   uint32_t     RESERVED15[2];
  volatile uint32_t MACPRSTIMR;          /*!< MAC presentation time register,                               Address offset: 0x0240 */
  volatile uint32_t MACPRSTIMUR;         /*!< MAC presentation time update register,                        Address offset: 0x0244 */
   uint32_t     RESERVED16[46];
  volatile uint32_t MACA0HR;             /*!< MAC Address 0 high register,                                  Address offset: 0x0300 */
  volatile uint32_t MACA0LR;             /*!< MAC Address 0 low register,                                   Address offset: 0x0304 */
  volatile uint32_t MACA1HR;             /*!< MAC Address 1 high register,                                  Address offset: 0x0308 */
  volatile uint32_t MACA1LR;             /*!< MAC Address 1 low register,                                   Address offset: 0x030C */
  volatile uint32_t MACA2HR;             /*!< MAC Address 2 high register,                                  Address offset: 0x0310 */
  volatile uint32_t MACA2LR;             /*!< MAC Address 2 low register,                                   Address offset: 0x0314 */
  volatile uint32_t MACA3HR;             /*!< MAC Address 3 high register,                                  Address offset: 0x0318 */
  volatile uint32_t MACA3LR;             /*!< MAC Address 3 low register,                                   Address offset: 0x031C */
  uint32_t      RESERVED17[248];
  volatile uint32_t MMCCR;               /*!< MMC control register,                                         Address offset: 0x0700 */
  volatile uint32_t MMCRIR;              /*!< MMC Rx interrupt register,                                    Address offset: 0x0704 */
  volatile uint32_t MMCTIR;              /*!< MMC Tx interrupt register,                                    Address offset: 0x0708 */
  volatile uint32_t MMCRIMR;             /*!< MMC Rx interrupt mask register,                               Address offset: 0x070C */
  volatile uint32_t MMCTIMR;             /*!< MMC Tx interrupt mask register,                               Address offset: 0x0710 */
  uint32_t      RESERVED18[14];
  volatile uint32_t MMCTSCGPR;           /*!< Tx single collision good packets register,                    Address offset: 0x074C */
  volatile uint32_t MMCTMCGPR;           /*!< Tx multiple collision good packets register,                  Address offset: 0x0750 */
  uint32_t      RESERVED19[5];
  volatile uint32_t MMCTPCGR;            /*!< Tx packet count good register,                                Address offset: 0x0768 */
  uint32_t      RESERVED20[10];
  volatile uint32_t MMCRCRCEPR;          /*!< Rx CRC error packets register,                                Address offset: 0x0794 */
  volatile uint32_t MMCRAEPR;            /*!< Rx alignment error packets register,                          Address offset: 0x0798 */
  uint32_t      RESERVED21[10];
  volatile uint32_t MMCRUPGR;            /*!< Rx unicast packets good register,                             Address offset: 0x07C4 */
  uint32_t      RESERVED22[9];
  volatile uint32_t MMCTLPIMSTR;         /*!< Tx LPI microsecond timer register,                            Address offset: 0x07EC */
  volatile uint32_t MMCTLPITCR;          /*!< Tx LPI transition counter register,                           Address offset: 0x07F0 */
  volatile uint32_t MMCRLPIMSTR;         /*!< Rx LPI microsecond counter register,                          Address offset: 0x07F4 */
  volatile uint32_t MMCRLPITCR;          /*!< Rx LPI transition counter register,                           Address offset: 0x07F8 */
  uint32_t      RESERVED23[41];
  volatile uint32_t MMCFPETISR;          /*!< MMC FPE Tx interrupt status register,                         Address offset: 0x08A0 */
  volatile uint32_t MMCFPETIMR;          /*!< MMC FPE Tx interrupt mask register,                           Address offset: 0x08A4 */
  volatile uint32_t MMCFPETFCR;          /*!< MMC FPE Tx fragment counter register,       -                 Address offset: 0x08A8 */
  volatile uint32_t MMCTHRCR;            /*!< MMC Tx hold request counter register,                         Address offset: 0x08AC */
  uint32_t      RESERVED24[4];
  volatile uint32_t MMCFPERISR;          /*!< MMC FPE Rx interrupt status register,                         Address offset: 0x08C0 */
  volatile uint32_t MMCFPERIMR;          /*!< MMC FPE Rx interrupt mask register,                           Address offset: 0x08C4 */
  volatile uint32_t MMCRPAER;            /*!< MMC Rx packet assembly error register,                        Address offset: 0x08C8 */
  volatile uint32_t MMCRPSMDER;          /*!< MMC Rx packet SMD error register,                             Address offset: 0x08CC */
  volatile uint32_t MMCRPAOKR;           /*!< MMC Rx packet assembly OK register,                           Address offset: 0x08D0 */
  volatile uint32_t MMCFPERFCR;          /*!< MMC Rx FPE fragments counter register,                        Address offset: 0x08D4 */
  uint32_t      RESERVED25[10];
  volatile uint32_t MACL3L4C0R;          /*!< L3 and L4 control 0 register,                                 Address offset: 0x0900 */
  volatile uint32_t MACL4A0R;            /*!< Layer4 Address filter 0 register,                             Address offset: 0x0904 */
  uint32_t      RESERVED26[2];
  volatile uint32_t MACL3A0R0R;           /*!< Layer3 Address 0 filter 0 register,                           Address offset: 0x0910 */
  volatile uint32_t MACL3A1R0R;           /*!< Layer3 Address 1 filter 0 register,                           Address offset: 0x0914 */
  volatile uint32_t MACL3A2R0R;           /*!< Layer3 Address 2 filter 0 register,                           Address offset: 0x0918 */
  volatile uint32_t MACL3A3R0R;           /*!< Layer3 Address 3 filter 0 register,                           Address offset: 0x091C */
  uint32_t      RESERVED27[4];
  volatile uint32_t MACL3L4C1R;          /*!< L3 and L4 control 1 register,                                 Address offset: 0x0930 */
  volatile uint32_t MACL4A1R;            /*!< Layer 4 address filter 1 register,                            Address offset: 0x0934 */
  uint32_t      RESERVED28[2];
  volatile uint32_t MACL3A01R;           /*!< Layer3 address 0 filter 1 Register,                           Address offset: 0x0940 */
  volatile uint32_t MACL3A11R;           /*!< Layer3 address 1 filter 1 register,                           Address offset: 0x0944 */
  volatile uint32_t MACL3A21R;           /*!< Layer3 address 2 filter 1 Register,                           Address offset: 0x0948 */
  volatile uint32_t MACL3A31R;           /*!< Layer3 address 3 filter 1 register,                           Address offset: 0x094C */
  uint32_t      RESERVED29[72];
  volatile uint32_t MACIACR;             /*!< MAC Indirect Access Control register,                         Address offset: 0x0A70 */
  volatile uint32_t MACTMRQR;            /*!< MAC type-based Rx Queue mapping register,                     Address offset: 0x0A74 */
  uint32_t      RESERVED30[34];
  volatile uint32_t MACTSCR;             /*!< Timestamp control Register,                                   Address offset: 0x0B00 */
  volatile uint32_t MACSSIR;             /*!< Subsecond increment register,                                 Address offset: 0x0B04 */
  volatile uint32_t MACSTSR;             /*!< System time seconds register,                                 Address offset: 0x0B08 */
  volatile uint32_t MACSTNR;             /*!< System time nanoseconds register,                             Address offset: 0x0B0C */
  volatile uint32_t MACSTSUR;            /*!< System time seconds update register,                          Address offset: 0x0B10 */
  volatile uint32_t MACSTNUR;            /*!< System time nanoseconds update register,                      Address offset: 0x0B14 */
  volatile uint32_t MACTSAR;             /*!< Timestamp addend register,                                    Address offset: 0x0B18 */
  uint32_t      RESERVED31;
  volatile uint32_t MACTSSR;             /*!< Timestamp status register,                                    Address offset: 0x0B20 */
  uint32_t      RESERVED32[3];
  volatile uint32_t MACTXTSSNR;          /*!< Tx timestamp status nanoseconds register,                     Address offset: 0x0B30 */
  volatile uint32_t MACTXTSSSR;          /*!< Tx timestamp status seconds register,                         Address offset: 0x0B34 */
  uint32_t      RESERVED33[2];
  volatile uint32_t MACACR;              /*!< Auxiliary control register,                                   Address offset: 0x0B40 */
  uint32_t      RESERVED34;
  volatile uint32_t MACATSNR;            /*!< Auxiliary timestamp nanoseconds register,                     Address offset: 0x0B48 */
  volatile uint32_t MACATSSR;            /*!< Auxiliary timestamp seconds register,                         Address offset: 0x0B4C */
  volatile uint32_t MACTSIACR;           /*!< Timestamp Ingress asymmetric correction register,             Address offset: 0x0B50 */
  volatile uint32_t MACTSEACR;           /*!< Timestamp Egress asymmetric correction register,              Address offset: 0x0B54 */
  volatile uint32_t MACTSICNR;           /*!< Timestamp Ingress correction nanosecond register,             Address offset: 0x0B58 */
  volatile uint32_t MACTSECNR;           /*!< Timestamp Egress correction nanosecond register,              Address offset: 0x0B5C */
  uint32_t      RESERVED35[2];
  volatile uint32_t MACTSILR;            /*!< Timestamp Ingress Latency register,                           Address offset: 0x0B68 */
  volatile uint32_t MACTSELR;            /*!< Timestamp Egress Latency register,                            Address offset: 0x0B6C */
  volatile uint32_t MACPPSCR;            /*!< PPS control register,                                         Address offset: 0x0B70 */
  uint32_t      RESERVED36[3];
  volatile uint32_t MACPPSTTS0R;         /*!< PPS 0 target time seconds register,                           Address offset: 0x0B80 */
  volatile uint32_t MACPPSTTN0R;         /*!< PPS 0 target time nanoseconds register,                       Address offset: 0x0B84 */
  volatile uint32_t MACPPSI0R;           /*!< PPS 0 interval register,                                      Address offset: 0x0B88 */
  volatile uint32_t MACPPSW0R;           /*!< PPS 0 width register,                                         Address offset: 0x0B8C */
  volatile uint32_t MACPPSTTS1R;         /*!< PPS 1 target time seconds register,                           Address offset: 0x0B90 */
  volatile uint32_t MACPPSTTN1R;         /*!< PPS 1 target time nanoseconds register,                       Address offset: 0x0B94 */
  volatile uint32_t MACPPSI1R;           /*!< PPS 1 interval register,                                      Address offset: 0x0B98 */
  volatile uint32_t MACPPSW1R;           /*!< PPS 1 width register,                                         Address offset: 0x0B9C */
  uint32_t      RESERVED37[8];
  volatile uint32_t MACPOCR;             /*!< PTP Offload control register,                                 Address offset: 0x0BC0 */
  volatile uint32_t MACSPI0R;            /*!< PTP Source Port Identity 0 Register,                          Address offset: 0x0BC4 */
  volatile uint32_t MACSPI1R;            /*!< PTP Source port identity 1 register,                          Address offset: 0x0BC8 */
  volatile uint32_t MACSPI2R;            /*!< PTP Source port identity 2 register,                          Address offset: 0x0BCC */
  volatile uint32_t MACLMIR;             /*!< Log message interval register,                                Address offset: 0x0BD0 */
  uint32_t      RESERVED38[11];
  volatile uint32_t MTLOMR;              /*!< Operating mode Register,                                      Address offset: 0x0C00 */
  uint32_t      RESERVED39[7];
  volatile uint32_t MTLISR;              /*!< Interrupt status Register,                                    Address offset: 0x0C20 */
  uint32_t      RESERVED40[3];
  volatile uint32_t MTLRXQDMAMR;         /*!< Rx Queue and DMA Channel Mapping Register,                    Address offset: 0x0C30 */
  uint32_t      RESERVED41[3];
  volatile uint32_t MTLTBSCR;            /*!< TBS control register,                                         Address offset: 0x0C40 */
  uint32_t      RESERVED42[3];
  volatile uint32_t MTLESTCR;            /*!< EST Control Register,                                         Address offset: 0x0C50 */
  volatile uint32_t MTLESTECR;           /*!< EST Extended Control Register,                                Address offset: 0x0C54 */
  volatile uint32_t MTLESTSR;            /*!< EST Status Register,                                          Address offset: 0x0C58 */
  uint32_t      RESERVED43;
  volatile uint32_t MTLESTSCHER;         /*!< EST Schedule Error Register,                                  Address offset: 0x0C60 */
  volatile uint32_t MTLESTFSER;          /*!< EST Frame size Error Register,                                Address offset: 0x0C64 */
  volatile uint32_t MTLESTFSCR;          /*!< EST Frame size Capture Register,                              Address offset: 0x0C68 */
  uint32_t      RESERVED44;
  volatile uint32_t MTLESTIER;           /*!< EST Interrupt Enable Register,                                Address offset: 0x0C70 */
  uint32_t      RESERVED45[3];
  volatile uint32_t MTLESTGCLCR;         /*!< EST Gate Control List Register,                               Address offset: 0x0C80 */
  volatile uint32_t MTLESTGCLDR;         /*!< EST Gate Control List Data Register,                          Address offset: 0x0C84 */
  uint32_t      RESERVED46[2];
  volatile uint32_t MTLFPECSR;           /*!< FPE Frame Preemption Control Status Register,                 Address offset: 0x0C90 */
  volatile uint32_t MTLFPEAR;            /*!< FPE Frame Preemption Advance Register,                        Address offset: 0x0C94 */
  uint32_t      RESERVED47[26];
  struct {
  volatile uint32_t MTLTXQOMR;           /*!< Tx queue x operating mode Register,                           Address offset: 0x0D00 */
  volatile uint32_t MTLTXQUR;            /*!< Tx queue x underflow register,                                Address offset: 0x0D04 */
  volatile uint32_t MTLTXQDR;            /*!< Tx queue x debug register,                                    Address offset: 0x0D08 */
  uint32_t      RESERVED48[1];
  volatile uint32_t MTLTXQ1ECR;           /*!< Tx queue 1 ETS control Register,                              Address offset: 0x0D50 */
  volatile uint32_t MTLTXQESR;           /*!< Tx queue x ETS status Register,                               Address offset: 0x0D14 */
  volatile uint32_t MTLTXQQWR;           /*!< Tx queue x quantum weight register,                           Address offset: 0x0D18 */
  volatile uint32_t MTLTXQ1SSCR;          /*!< Tx queue 1 send slope credit Register,                        Address offset: 0x0D5C */
  volatile uint32_t MTLTXQ1HCR;           /*!< Tx Queue 1 hiCredit register,                                 Address offset: 0x0D60 */
  volatile uint32_t MTLTXQ1LCR;           /*!< Tx queue 1 loCredit register,                                 Address offset: 0x0D64 */
  uint32_t      RESERVED49[1];
  volatile uint32_t MTLQICSR;           /*!< Queue 0 interrupt control status Register,                    Address offset: 0x0D2C */
  volatile uint32_t MTLRXQOMR;          /*!< Rx queue x operating mode register,                           Address offset: 0x0D30 */
  volatile uint32_t MTLRXQMPOCR;        /*!< Rx queue x missed packet and overflow counter register,       Address offset: 0x0D34 */
  volatile uint32_t MTLRXQDR;           /*!< Rx queue x debug register,                                    Address offset: 0x0D38 */
  volatile uint32_t MTLRXQCR;           /*!< Rx queue x control register,                                  Address offset: 0x0D3C */
  } MTL_QUEUE[2];
  uint32_t      RESERVED52[160];
  volatile uint32_t DMAMR;               /*!< DMA mode register,                                            Address offset: 0x1000 */
  volatile uint32_t DMASBMR;             /*!< System bus mode register,                                     Address offset: 0x1004 */
  volatile uint32_t DMAISR;              /*!< Interrupt status register,                                    Address offset: 0x1008 */
  volatile uint32_t DMADSR;              /*!< Debug status register,                                        Address offset: 0x100C */
  uint32_t      RESERVED53[4];
  volatile uint32_t DMAA4TXACR;          /*!< AXI4 transmit channel ACE control register,                   Address offset: 0x1020 */
  volatile uint32_t DMAA4RXACR;          /*!< AXI4 receive channel ACE control register,                    Address offset: 0x1024 */
  volatile uint32_t DMAA4DACR;           /*!< AXI4 descriptor ACE control register,                         Address offset: 0x1028 */
  uint32_t      RESERVED54[5];
  volatile uint32_t DMALPIEI;            /*!< AXI4 LPI Entry Interval register,                             Address offset: 0x1040 */
  uint32_t      RESERVED55[3];
  volatile uint32_t DMATBSCTRL0R;        /*!< DMA TBS control register 0,                                   Address offset: 0x1050 */
  uint32_t      RESERVED56[37];
  struct {
  uint32_t      RESERVED57[6];
  volatile uint32_t DMACCR;             /*!< Channel x control register,                                   Address offset: 0x1100 */
  volatile uint32_t DMACTXCR;           /*!< Channel x transmit control register,                          Address offset: 0x1104 */
  volatile uint32_t DMACRXCR;           /*!< Channel x receive control register,                           Address offset: 0x1108 */
  uint32_t      RESERVED58[2];
  volatile uint32_t DMACTXDLAR;         /*!< Channel x Tx descriptor list address register,                Address offset: 0x1114 */
  uint32_t      RESERVED59;
  volatile uint32_t DMACRXDLAR;         /*!< Channel x Rx descriptor list address register,                Address offset: 0x111C */
  volatile uint32_t DMACTXDTPR;         /*!< Channel x Tx descriptor tail pointer register,                Address offset: 0x1120 */
  uint32_t      RESERVED60;
  volatile uint32_t DMACRXDTPR;         /*!< Channel x Rx descriptor tail pointer register,                Address offset: 0x1128 */
  volatile uint32_t DMACTXRLR;          /*!< Channel x Tx descriptor ring length register,                 Address offset: 0x112C */
  volatile uint32_t DMACRXRLR;          /*!< Channel x Rx descriptor ring length register,                 Address offset: 0x1130 */
  volatile uint32_t DMACIER;            /*!< Channel x interrupt enable register,                          Address offset: 0x1134 */
  volatile uint32_t DMACRXIWTR;         /*!< Channel x Rx interrupt watchdog timer register,               Address offset: 0x1138 */
  volatile uint32_t DMACSFCSR;          /*!< Channel x slot function control status register,              Address offset: 0x113C */
  uint32_t      RESERVED61;
  volatile uint32_t DMACCATXDR;         /*!< Channel x current application transmit descriptor register,   Address offset: 0x1144 */
  uint32_t      RESERVED62;
  volatile uint32_t DMACCARXDR;         /*!< Channel x current application receive descriptor register,    Address offset: 0x114C */
  uint32_t      RESERVED63;
  volatile uint32_t DMACCATXBR;         /*!< Channel x current application transmit buffer register,       Address offset: 0x1154 */
  uint32_t      RESERVED64;
  volatile uint32_t DMACCARXBR;         /*!< Channel x current application receive buffer register,        Address offset: 0x115C */
  volatile uint32_t DMACSR;             /*!< Channel x status register,                                    Address offset: 0x1160 */
  volatile uint32_t DMACMFCR;            /*!< Channel x missed frame count register,                        Address offset: 0x1164 */
  } DMA_CH[2];
}ETH_TypeDef;

/**
  * @brief External Interrupt/Event Controller
  */
typedef struct
{
  volatile uint32_t RTSR1;          /*!< EXTI Rising Trigger Selection Register 1,        Address offset:   0x00 */
  volatile uint32_t FTSR1;          /*!< EXTI Falling Trigger Selection Register 1,       Address offset:   0x04 */
  volatile uint32_t SWIER1;         /*!< EXTI Software Interrupt event Register 1,        Address offset:   0x08 */
  volatile uint32_t RPR1;           /*!< EXTI Rising Pending Register 1,                  Address offset:   0x0C */
  volatile uint32_t FPR1;           /*!< EXTI Falling Pending Register 1,                 Address offset:   0x10 */
  volatile uint32_t SECCFGR1;       /*!< EXTI Security Configuration Register 1,          Address offset:   0x14 */
  volatile uint32_t PRIVCFGR1;      /*!< EXTI Privilege Configuration Register 1,         Address offset:   0x18 */
       uint32_t RESERVED1;      /*!< Reserved 1,                                      Address offset:   0x1C */
  volatile uint32_t RTSR2;          /*!< EXTI Rising Trigger Selection Register 2,        Address offset:   0x20 */
  volatile uint32_t FTSR2;          /*!< EXTI Falling Trigger Selection Register 2,       Address offset:   0x24 */
  volatile uint32_t SWIER2;         /*!< EXTI Software Interrupt event Register 2,        Address offset:   0x28 */
  volatile uint32_t RPR2;           /*!< EXTI Rising Pending Register 2,                  Address offset:   0x2C */
  volatile uint32_t FPR2;           /*!< EXTI Falling Pending Register 2,                 Address offset:   0x30 */
  volatile uint32_t SECCFGR2;       /*!< EXTI Security Configuration Register 2,          Address offset:   0x34 */
  volatile uint32_t PRIVCFGR2;      /*!< EXTI Privilege Configuration Register 2,         Address offset:   0x38 */
       uint32_t RESERVED2;      /*!< Reserved 2,                                      Address offset:   0x3C */
  volatile uint32_t RTSR3;          /*!< EXTI Rising Trigger Selection Register 3,        Address offset:   0x40 */
  volatile uint32_t FTSR3;          /*!< EXTI Falling Trigger Selection Register 3,       Address offset:   0x44 */
  volatile uint32_t SWIER3;         /*!< EXTI Software Interrupt event Register 3,        Address offset:   0x48 */
  volatile uint32_t RPR3;           /*!< EXTI Rising Pending Register 3,                  Address offset:   0x4C */
  volatile uint32_t FPR3;           /*!< EXTI Falling Pending Register 3,                 Address offset:   0x50 */
  volatile uint32_t SECCFGR3;       /*!< EXTI Security Configuration Register 3,          Address offset:   0x54 */
  volatile uint32_t PRIVCFGR3;      /*!< EXTI Privilege Configuration Register 3,         Address offset:   0x58 */
       uint32_t RESERVED3;      /*!< Reserved 3,                                      Address offset:   0x5C */
  volatile uint32_t EXTICR[4];      /*!< EXIT External Interrupt Configuration Register,            0x60 -- 0x6C */
  volatile uint32_t LOCKR;          /*!< EXTI Lock Register,                              Address offset:   0x70 */
       uint32_t RESERVED4[3];   /*!< Reserved 4,                                                0x74 -- 0x7C */
  volatile uint32_t IMR1;           /*!< EXTI Interrupt Mask Register 1,                  Address offset:   0x80 */
  volatile uint32_t EMR1;           /*!< EXTI Event Mask Register 1,                      Address offset:   0x84 */
       uint32_t RESERVED5[2];   /*!< Reserved 5,                                                0x88 -- 0x8C */
  volatile uint32_t IMR2;           /*!< EXTI Interrupt Mask Register 2,                  Address offset:   0x90 */
  volatile uint32_t EMR2;           /*!< EXTI Event Mask Register 2,                      Address offset:   0x94 */
       uint32_t RESERVED6[2];   /*!< Reserved 6,                                                0x98 -- 0x9C */
  volatile uint32_t IMR3;           /*!< EXTI Interrupt Mask Register 3,                  Address offset:   0xA0 */
  volatile uint32_t EMR3;           /*!< EXTI Event Mask Register 3,                      Address offset:   0xA4 */
} EXTI_TypeDef;

/**
 * @brief FD Controller Area Network
 */

typedef struct
{
 volatile uint32_t CREL;           /*!< FDCAN Core Release register,                                     Address offset: 0x000 */
 volatile uint32_t ENDN;           /*!< FDCAN Endian register,                                           Address offset: 0x004 */
 volatile uint32_t RESERVED1;      /*!< Reserved,                                                                        0x008 */
 volatile uint32_t DBTP;           /*!< FDCAN Data Bit Timing & Prescaler register,                      Address offset: 0x00C */
 volatile uint32_t TEST;           /*!< FDCAN Test register,                                             Address offset: 0x010 */
 volatile uint32_t RWD;            /*!< FDCAN RAM Watchdog register,                                     Address offset: 0x014 */
 volatile uint32_t CCCR;           /*!< FDCAN CC Control register,                                       Address offset: 0x018 */
 volatile uint32_t NBTP;           /*!< FDCAN Nominal Bit Timing & Prescaler register,                   Address offset: 0x01C */
 volatile uint32_t TSCC;           /*!< FDCAN Timestamp Counter Configuration register,                  Address offset: 0x020 */
 volatile uint32_t TSCV;           /*!< FDCAN Timestamp Counter Value register,                          Address offset: 0x024 */
 volatile uint32_t TOCC;           /*!< FDCAN Timeout Counter Configuration register,                    Address offset: 0x028 */
 volatile uint32_t TOCV;           /*!< FDCAN Timeout Counter Value register,                            Address offset: 0x02C */
 volatile uint32_t RESERVED2[4];   /*!< Reserved,                                                                0x030 - 0x03C */
 volatile uint32_t ECR;            /*!< FDCAN Error Counter register,                                    Address offset: 0x040 */
 volatile uint32_t PSR;            /*!< FDCAN Protocol Status register,                                  Address offset: 0x044 */
 volatile uint32_t TDCR;           /*!< FDCAN Transmitter Delay Compensation register,                   Address offset: 0x048 */
 volatile uint32_t RESERVED3;      /*!< Reserved,                                                                        0x04C */
 volatile uint32_t IR;             /*!< FDCAN Interrupt register,                                        Address offset: 0x050 */
 volatile uint32_t IE;             /*!< FDCAN Interrupt Enable register,                                 Address offset: 0x054 */
 volatile uint32_t ILS;            /*!< FDCAN Interrupt Line Select register,                            Address offset: 0x058 */
 volatile uint32_t ILE;            /*!< FDCAN Interrupt Line Enable register,                            Address offset: 0x05C */
 volatile uint32_t RESERVED4[8];   /*!< Reserved,                                                                0x060 - 0x07C */
 volatile uint32_t GFC;            /*!< FDCAN Global Filter Configuration register,                      Address offset: 0x080 */
 volatile uint32_t SIDFC;          /*!< FDCAN Standard ID Filter Configuration register,                 Address offset: 0x084 */
 volatile uint32_t XIDFC;          /*!< FDCAN Extended ID Filter Configuration register,                 Address offset: 0x088 */
 volatile uint32_t RESERVED5;      /*!< Reserved,                                                                        0x08C */
 volatile uint32_t XIDAM;          /*!< FDCAN Extended ID AND Mask register,                             Address offset: 0x090 */
 volatile uint32_t HPMS;           /*!< FDCAN High Priority Message Status register,                     Address offset: 0x094 */
 volatile uint32_t NDAT1;          /*!< FDCAN New Data 1 register,                                       Address offset: 0x098 */
 volatile uint32_t NDAT2;          /*!< FDCAN New Data 2 register,                                       Address offset: 0x09C */
 volatile uint32_t RXF0C;          /*!< FDCAN Rx FIFO 0 Configuration register,                          Address offset: 0x0A0 */
 volatile uint32_t RXF0S;          /*!< FDCAN Rx FIFO 0 Status register,                                 Address offset: 0x0A4 */
 volatile uint32_t RXF0A;          /*!< FDCAN Rx FIFO 0 Acknowledge register,                            Address offset: 0x0A8 */
 volatile uint32_t RXBC;           /*!< FDCAN Rx Buffer Configuration register,                          Address offset: 0x0AC */
 volatile uint32_t RXF1C;          /*!< FDCAN Rx FIFO 1 Configuration register,                          Address offset: 0x0B0 */
 volatile uint32_t RXF1S;          /*!< FDCAN Rx FIFO 1 Status register,                                 Address offset: 0x0B4 */
 volatile uint32_t RXF1A;          /*!< FDCAN Rx FIFO 1 Acknowledge register,                            Address offset: 0x0B8 */
 volatile uint32_t RXESC;          /*!< FDCAN Rx Buffer/FIFO Element Size Configuration register,        Address offset: 0x0BC */
 volatile uint32_t TXBC;           /*!< FDCAN Tx Buffer Configuration register,                          Address offset: 0x0C0 */
 volatile uint32_t TXFQS;          /*!< FDCAN Tx FIFO/Queue Status register,                             Address offset: 0x0C4 */
 volatile uint32_t TXESC;          /*!< FDCAN Tx Buffer Element Size Configuration register,             Address offset: 0x0C8 */
 volatile uint32_t TXBRP;          /*!< FDCAN Tx Buffer Request Pending register,                        Address offset: 0x0CC */
 volatile uint32_t TXBAR;          /*!< FDCAN Tx Buffer Add Request register,                            Address offset: 0x0D0 */
 volatile uint32_t TXBCR;          /*!< FDCAN Tx Buffer Cancellation Request register,                   Address offset: 0x0D4 */
 volatile uint32_t TXBTO;          /*!< FDCAN Tx Buffer Transmission Occurred register,                  Address offset: 0x0D8 */
 volatile uint32_t TXBCF;          /*!< FDCAN Tx Buffer Cancellation Finished register,                  Address offset: 0x0DC */
 volatile uint32_t TXBTIE;         /*!< FDCAN Tx Buffer Transmission Interrupt Enable register,          Address offset: 0x0E0 */
 volatile uint32_t TXBCIE;         /*!< FDCAN Tx Buffer Cancellation Finished Interrupt Enable register, Address offset: 0x0E4 */
 volatile uint32_t RESERVED6[2];   /*!< Reserved,                                                                0x0E8 - 0x0EC */
 volatile uint32_t TXEFC;          /*!< FDCAN Tx Event FIFO Configuration register,                      Address offset: 0x0F0 */
 volatile uint32_t TXEFS;          /*!< FDCAN Tx Event FIFO Status register,                             Address offset: 0x0F4 */
 volatile uint32_t TXEFA;          /*!< FDCAN Tx Event FIFO Acknowledge register,                        Address offset: 0x0F8 */
 volatile uint32_t RESERVED7;      /*!< Reserved,                                                                        0x0FC */
} FDCAN_GlobalTypeDef;

/**
  * @brief TTFD Controller Area Network
  */

typedef struct
{
  volatile uint32_t TTTMC;         /*!< TT Trigger Memory Configuration register,        Address offset: 0x100 */
  volatile uint32_t TTRMC;         /*!< TT Reference Message Configuration register,     Address offset: 0x104 */
  volatile uint32_t TTOCF;         /*!< TT Operation Configuration register,             Address offset: 0x108 */
  volatile uint32_t TTMLM;         /*!< TT Matrix Limits register,                       Address offset: 0x10C */
  volatile uint32_t TURCF;         /*!< TUR Configuration register,                      Address offset: 0x110 */
  volatile uint32_t TTOCN;         /*!< TT Operation Control register,                   Address offset: 0x114 */
  volatile uint32_t TTGTP;         /*!< TT Global Time Preset register,                  Address offset: 0x118 */
  volatile uint32_t TTTMK;         /*!< TT Time Mark register,                          Address offset: 0x11C */
  volatile uint32_t TTIR;          /*!< TT Interrupt register,                           Address offset: 0x120 */
  volatile uint32_t TTIE;          /*!< TT Interrupt Enable register,                    Address offset: 0x124 */
  volatile uint32_t TTILS;         /*!< TT Interrupt Line Select register,               Address offset: 0x128 */
  volatile uint32_t TTOST;         /*!< TT Operation Status register,                    Address offset: 0x12C */
  volatile uint32_t TURNA;         /*!< TT TUR Numerator Actual register,                Address offset: 0x130 */
  volatile uint32_t TTLGT;         /*!< TT Local and Global Time register,               Address offset: 0x134 */
  volatile uint32_t TTCTC;         /*!< TT Cycle Time and Count register,                Address offset: 0x138 */
  volatile uint32_t TTCPT;         /*!< TT Capture Time register,                        Address offset: 0x13C */
  volatile uint32_t TTCSM;         /*!< TT Cycle Sync Mark register,                     Address offset: 0x140 */
  volatile uint32_t RESERVED1[111];/*!< Reserved,                                                0x144 - 0x2FC */
  volatile uint32_t TTTS;          /*!< TT Trigger Select register,                      Address offset: 0x300 */
} TTCAN_TypeDef;

/**
  * @brief FD Controller Area Network
  */

typedef struct
{
  volatile uint32_t CREL;          /*!< Clock Calibration Unit Core Release register,    Address offset: 0x00 */
  volatile uint32_t CCFG;          /*!< Calibration Configuration register,              Address offset: 0x04 */
  volatile uint32_t CSTAT;         /*!< Calibration Status register,                     Address offset: 0x08 */
  volatile uint32_t CWD;           /*!< Calibration Watchdog register,                   Address offset: 0x0C */
  volatile uint32_t IR;            /*!< CCU Interrupt register,                          Address offset: 0x10 */
  volatile uint32_t IE;            /*!< CCU Interrupt Enable register,                   Address offset: 0x14 */
} FDCAN_ClockCalibrationUnit_TypeDef;

/**
  * @brief Flexible Memory Controller Bank1
  */
typedef struct
{
  volatile uint32_t BTCR[8];    /*!< NOR/PSRAM chip-select control register(BCR) and chip-select timing register(BTR), Address offset: 0x00-1C */
} FMC_Bank1_TypeDef;

/**
  * @brief Flexible Memory Controller Bank1E
  */
typedef struct
{
  volatile uint32_t BWTR[7];    /*!< NOR/PSRAM write timing registers, Address offset: 0x104-0x11C */
} FMC_Bank1E_TypeDef;

/**
  * @brief Flexible Memory Controller Bank2
  */
typedef struct
{
  volatile uint32_t SDCR[2];         /*!< SDRAM device 1/2 control register                      Address offset: 0x140-0x144 */
  volatile uint32_t SDTR;            /*!< SDRAM timing register                                  Address offset: 0x148 */
       uint32_t RESERVED0;       /*!< Reserved                                               Address offset: 0x14C */
  volatile uint32_t SDCMR;           /*!< SDRAM command mode register                            Address offset: 0x150 */
  volatile uint32_t SDRTR;           /*!< SDRAM refresh timer register                           Address offset: 0x154 */
  volatile uint32_t SDSR;            /*!< SDRAM status register                                  Address offset: 0x158 */
} FMC_Bank5_6_TypeDef;

/**
  * @brief Flexible Memory Controller Bank3
  */
typedef struct
{
  volatile uint32_t PCR;             /*!< NAND Flash Programmable control register               Address offset: 0x080 */
  volatile uint32_t SR;              /*!< FMC status register                                    Address offset: 0x084 */
  volatile uint32_t PMEM;            /*!< Common memory space timing register                    Address offset: 0x088 */
  volatile uint32_t PATT;            /*!< Attribute memory space timing registers                Address offset: 0x08C */
  volatile uint32_t HPR;             /*!< FMC Hamming parity result registers                    Address offset: 0x090 */
  volatile uint32_t HECCR;           /*!< FMC Hamming code ECC result register                   Address offset: 0x094 */
       uint32_t RESERVED0[58];   /*!< Reserved                                               Address offset: 0x098-0x17C */
  volatile uint32_t IER;             /*!< FMC NAND Interrupt Enable Register                     Address offset: 0x180 */
  volatile uint32_t ISR;             /*!< FMC Controller Interrupt Status Register               Address offset: 0x184 */
  volatile uint32_t ICR;             /*!< FMC NAND Controller Interrupt Clear Register           Address offset: 0x188 */
       uint32_t RESERVED1[29];   /*!< Reserved                                               Address offset: 0x18C-0x1FC */
  volatile uint32_t CSQCR;           /*!< FMC NAND Command Sequencer Control Register            Address offset: 0x200 */
  volatile uint32_t CSQCFGR1;        /*!< FMC NAND Command Sequencer Configuration Register 1    Address offset: 0x204 */
  volatile uint32_t CSQCFGR2;        /*!< FMC NAND Command Sequencer Configuration Register 2    Address offset: 0x208 */
  volatile uint32_t CSQCFGR3;        /*!< FMC NAND sequencer configuration register 3            Address offset: 0x20C */
  volatile uint32_t CSQAR1;          /*!< FMC NAND Command Sequencer Address Register 1          Address offset: 0x210 */
  volatile uint32_t CSQAR2;          /*!< FMC NAND Command Sequencer Address Register 2          Address offset: 0x214 */
       uint32_t RESERVED2[2];    /*!< Reserved                                               Address offset: 0x218-0x21C */
  volatile uint32_t CSQIER;          /*!< FMC NAND Command Sequencer Interrupt Enable Register   Address offset: 0x220 */
  volatile uint32_t CSQISR;          /*!< FMC NAND Command Sequencer Interrupt Status Register   Address offset: 0x224 */
  volatile uint32_t CSQICR;          /*!< FMC NAND Command Sequencer Interrupt Clear Register    Address offset: 0x228 */
       uint32_t RESERVED3;       /*!< Reserved                                               Address offset: 0x22C */
  volatile uint32_t CSQEMSR;         /*!< FMC Command Sequencer Error Mapping Status register    Address offset: 0x230 */
       uint32_t RESERVED4[7];    /*!< Reserved                                               Address offset: 0x234-0x24C */
  volatile uint32_t BCHIER;          /*!< FMC BCH Interrupt enable register                      Address offset: 0x250 */
  volatile uint32_t BCHISR;          /*!< FMC BCH Interrupt and Status Register                  Address offset: 0x254 */
  volatile uint32_t BCHICR;          /*!< FMC BCH Interrupt Clear Register                       Address offset: 0x258 */
       uint32_t RESERVED5;       /*!< Reserved                                               Address offset: 0x25C */
  volatile uint32_t BCHPBR1;         /*!< FMC BCH Parity Bits Register 1                         Address offset: 0x260 */
  volatile uint32_t BCHPBR2;         /*!< FMC BCH Parity Bits Register 2                         Address offset: 0x264 */
  volatile uint32_t BCHPBR3;         /*!< FMC BCH Parity Bits Register 3                         Address offset: 0x268 */
  volatile uint32_t BCHPBR4;         /*!< FMC BCH Parity Bits Register 4                         Address offset: 0x26C */
       uint32_t RESERVED6[3];    /*!< Reserved                                               Address offset: 0x270-0x278 */
  volatile uint32_t BCHDSR0;         /*!< FMC BCH Decoder Status register 0                      Address offset: 0x27C */
  volatile uint32_t BCHDSR1;         /*!< FMC BCH Decoder Status register for bank 1             Address offset: 0x280 */
  volatile uint32_t BCHDSR2;         /*!< FMC BCH Decoder Status register for bank 2             Address offset: 0x284 */
  volatile uint32_t BCHDSR3;         /*!< FMC BCH Decoder Status register for bank 3             Address offset: 0x288 */
  volatile uint32_t BCHDSR4;         /*!< FMC BCH Decoder Status register for bank 4             Address offset: 0x28C */
} FMC_Bank3_TypeDef;

/**
  * @brief Flexible Memory Controller Common
  */
typedef struct{
  volatile uint32_t CFGR;            /*!< FMC common configuration register                      Address offset: 0x020 */
} FMC_Common_TypeDef;

/**
  * @brief General Purpose I/O
  */
typedef struct
{
  volatile uint32_t MODER;         /*!< GPIO port mode register,                     Address offset: 0x00      */
  volatile uint32_t OTYPER;        /*!< GPIO port output type register,              Address offset: 0x04      */
  volatile uint32_t OSPEEDR;       /*!< GPIO port output speed register,             Address offset: 0x08      */
  volatile uint32_t PUPDR;         /*!< GPIO port pull-up/pull-down register,        Address offset: 0x0C      */
  volatile uint32_t IDR;           /*!< GPIO port input data register,               Address offset: 0x10      */
  volatile uint32_t ODR;           /*!< GPIO port output data register,              Address offset: 0x14      */
  volatile uint32_t BSRR;          /*!< GPIO port bit set/reset  register,           Address offset: 0x18      */
  volatile uint32_t LCKR;          /*!< GPIO port configuration lock register,       Address offset: 0x1C      */
  volatile uint32_t AFR[2];        /*!< GPIO alternate function registers,           Address offset: 0x20-0x24 */
  volatile uint32_t BRR;           /*!< GPIO bit reset register,                     Address offset: 0x28      */
       uint32_t RESERVED0;     /*!< Reserved,                                    Address offset: 0x2C      */
  volatile uint32_t SECCFGR;       /*!< GPIO port secure configuration register,     Address offset: 0x30      */
  volatile uint32_t PRIVCFGR;      /*!< GPIO port privileged configuration register, Address offset: 0x34      */
  volatile uint32_t RCFGLOCKR;     /*!< GPIO port resource configuration register,   Address offset: 0x38      */
       uint32_t RESERVED1;     /*!< Reserved,                                    Address offset: 0x3C      */
  volatile uint32_t DELAYR[2];     /*!< GPIO port delay register,                    Address offset: 0x40-0x44 */
  volatile uint32_t ADVCFGR[2];    /*!< GPIO port advanced configuration register,   Address offset: 0x48-0x4C */
} GPIO_TypeDef;

/**
  * @brief GFXMMU
  */
typedef struct
{
  volatile uint32_t CR;              /*!< GFXMMU configuration register,                     Address offset: 0x00 */
  volatile uint32_t SR;              /*!< GFXMMU status register,                            Address offset: 0x04 */
  volatile uint32_t FCR;             /*!< GFXMMU flag clear register,                        Address offset: 0x08 */
       uint32_t RESERVED0;       /*!< Reserved0,                                         Address offset: 0x0C */
  volatile uint32_t DVR;             /*!< GFXMMU default value register,                     Address offset: 0x10 */
  volatile uint32_t DAR;             /*!< GFXMMU default alpha register,                     Address offset: 0x14 */
       uint32_t RESERVED1[2];    /*!< Reserved1,                                 Address offset: 0x18 to 0x1C */
  volatile uint32_t B0CR;            /*!< GFXMMU buffer 0 configuration register,            Address offset: 0x20 */
  volatile uint32_t B1CR;            /*!< GFXMMU buffer 1 configuration register,            Address offset: 0x24 */
  volatile uint32_t B2CR;            /*!< GFXMMU buffer 2 configuration register,            Address offset: 0x28 */
  volatile uint32_t B3CR;            /*!< GFXMMU buffer 3 configuration register,            Address offset: 0x2C */
       uint32_t RESERVED2[1012]; /*!< Reserved2,                                 Address offset: 0x30 to 0xFFC */
  volatile uint32_t LUT[2048];       /*!< GFXMMU LUT registers,                      Address offset: 0x1000 to 0x2FFC
                                      For LUT line i, LUTiL = LUT[2*i] and LUTiH = LUT[(2*i)+1] */
} GFXMMU_TypeDef;

/**
  * @brief GFXTIM
  */
typedef struct
{
  volatile uint32_t CR;            /*!< GFXTIM configuration register,                    Address offset: 0x00 */
  volatile uint32_t CGCR;          /*!< GFXTIM clock generator configuration register,    Address offset: 0x04 */
  volatile uint32_t TCR;           /*!< GFXTIM timers configuration register,             Address offset: 0x08 */
  volatile uint32_t TDR;           /*!< GFXTIM timers disable register,                   Address offset: 0x0C */
  volatile uint32_t EVCR;          /*!< GFXTIM events control register,                   Address offset: 0x10 */
  volatile uint32_t EVSR;          /*!< GFXTIM events selection register,                 Address offset: 0x14 */
  uint32_t RESERVED1[2];       /*!< Reserved,                                         Address offset: 0x18-0x1C */
  volatile uint32_t WDGTCR;        /*!< GFXTIM watchdog timer configuration register,     Address offset: 0x20 */
  uint32_t RESERVED2[3];       /*!< Reserved,                                         Address offset: 0x24-0x2C */
  volatile uint32_t ISR;           /*!< GFXTIM interrupt status register,                 Address offset: 0x30 */
  volatile uint32_t ICR;           /*!< GFXTIM interrupt clear register,                  Address offset: 0x34 */
  volatile uint32_t IER;           /*!< GFXTIM interrupt enable register,                 Address offset: 0x38 */
  volatile uint32_t TSR;           /*!< GFXTIM timers status register,                    Address offset: 0x3C */
  volatile uint32_t LCCRR;         /*!< GFXTIM line clock counter reload register,        Address offset: 0x40 */
  volatile uint32_t FCCRR;         /*!< GFXTIM frame clock counter reload register,       Address offset: 0x44 */
  uint32_t RESERVED3[2];       /*!< Reserved,                                         Address offset: 0x48-0x4C */
  volatile uint32_t ATR;           /*!< GFXTIM absolute time register,                    Address offset: 0x50 */
  volatile uint32_t AFCR;          /*!< GFXTIM absolute frame counter register,           Address offset: 0x54 */
  volatile uint32_t ALCR;          /*!< GFXTIM absolute line counter register,            Address offset: 0x58 */
  uint32_t RESERVED4[1];       /*!< Reserved,                                         Address offset: 0x5C */
  volatile uint32_t AFCC1R;        /*!< GFXTIM absolute frame counter compare 1 register, Address offset: 0x60 */
  uint32_t RESERVED5[3];       /*!< Reserved,                                         Address offset: 0x64-0X6C */
  volatile uint32_t ALCC1R;        /*!< GFXTIM absolute line counter compare 1 register,  Address offset: 0x70 */
  volatile uint32_t ALCC2R;        /*!< GFXTIM absolute line counter compare 2 register,  Address offset: 0x74 */
  uint32_t RESERVED6[2];       /*!< Reserved,                                         Address offset: 0x78-0X7C */
  volatile uint32_t RFC1R;         /*!< GFXTIM relative frame counter 1 register,         Address offset: 0x80 */
  volatile uint32_t RFC1RR;        /*!< GFXTIM relative frame counter 1 reload register,  Address offset: 0x84 */
  volatile uint32_t RFC2R;         /*!< GFXTIM relative frame counter 2 register,         Address offset: 0x88 */
  volatile uint32_t RFC2RR;        /*!< GFXTIM relative frame counter 2 reload register,  Address offset: 0x8C */
  uint32_t RESERVED7[4];       /*!< Reserved,                                         Address offset: 0x90-0X9C */
  volatile uint32_t WDGCR;         /*!< GFXTIM watchdog counter register,                 Address offset: 0xA0 */
  volatile uint32_t WDGRR;         /*!< GFXTIM watchdog reload register,                  Address offset: 0xA4 */
  volatile uint32_t WDGPAR;        /*!< GFXTIM watchdog pre-alarm register,               Address offset: 0xA8 */
  uint32_t RESERVED8[209];     /*!< Reserved,                                         Address offset: 0xAC-0X3EC */
  volatile uint32_t HWCFGR;        /*!< GFXTIM HW configuration register,                 Address offset: 0x3F0 */
  volatile uint32_t VERR;          /*!< GFXTIM version register,                          Address offset: 0x3F4 */
  volatile uint32_t IPIDR;         /*!< GFXTIM identification register,                   Address offset: 0x3F8 */
  volatile uint32_t SIDR;          /*!< GFXTIM size identification register,              Address offset: 0x3FC */
} GFXTIM_TypeDef;

/**
  * @brief HASH
  */
typedef struct
{
  volatile uint32_t CR;               /*!< HASH control register,          Address offset: 0x00        */
  volatile uint32_t DIN;              /*!< HASH data input register,       Address offset: 0x04        */
  volatile uint32_t STR;              /*!< HASH start register,            Address offset: 0x08        */
  volatile uint32_t HR[5];            /*!< HASH digest registers,          Address offset: 0x0C-0x1C   */
  volatile uint32_t IMR;              /*!< HASH interrupt enable register, Address offset: 0x20        */
  volatile uint32_t SR;               /*!< HASH status register,           Address offset: 0x24        */
       uint32_t RESERVED[52];     /*!< Reserved, 0x28-0xF4                                         */
  volatile uint32_t CSR[103];         /*!< HASH context swap registers,    Address offset: 0x0F8-0x290 */
} HASH_TypeDef;

/**
  * @brief HASH_DIGEST
  */
typedef struct
{
  volatile uint32_t HR[16];           /*!< HASH digest registers,          Address offset: 0x310-0x34C */
} HASH_DIGEST_TypeDef;

/**
  * @brief Inter-integrated Circuit Interface
  */
typedef struct
{
  volatile uint32_t CR1;         /*!< I2C Control register 1,            Address offset: 0x00 */
  volatile uint32_t CR2;         /*!< I2C Control register 2,            Address offset: 0x04 */
  volatile uint32_t OAR1;        /*!< I2C Own address 1 register,        Address offset: 0x08 */
  volatile uint32_t OAR2;        /*!< I2C Own address 2 register,        Address offset: 0x0C */
  volatile uint32_t TIMINGR;     /*!< I2C Timing register,               Address offset: 0x10 */
  volatile uint32_t TIMEOUTR;    /*!< I2C Timeout register,              Address offset: 0x14 */
  volatile uint32_t ISR;         /*!< I2C Interrupt and status register, Address offset: 0x18 */
  volatile uint32_t ICR;         /*!< I2C Interrupt clear register,      Address offset: 0x1C */
  volatile uint32_t PECR;        /*!< I2C PEC register,                  Address offset: 0x20 */
  volatile uint32_t RXDR;        /*!< I2C Receive data register,         Address offset: 0x24 */
  volatile uint32_t TXDR;        /*!< I2C Transmit data register,        Address offset: 0x28 */
} I2C_TypeDef;

/**
  * @brief Improved Inter-integrated Circuit Interface
  */
typedef struct
{
  volatile uint32_t CR;             /*!< I3C Control register,                      Address offset: 0x00      */
  volatile uint32_t CFGR;           /*!< I3C Controller Configuration register,     Address offset: 0x04      */
  uint32_t      RESERVED1[2];   /*!< Reserved,                                  Address offset: 0x08-0x0C */
  volatile uint32_t RDR;            /*!< I3C Received Data register,                Address offset: 0x10      */
  volatile uint32_t RDWR;           /*!< I3C Received Data Word register,           Address offset: 0x14      */
  volatile uint32_t TDR;            /*!< I3C Transmit Data register,                Address offset: 0x18      */
  volatile uint32_t TDWR;           /*!< I3C Transmit Data Word register,           Address offset: 0x1C      */
  volatile uint32_t IBIDR;          /*!< I3C IBI payload Data register,             Address offset: 0x20      */
  volatile uint32_t TGTTDR;         /*!< I3C Target Transmit register,              Address offset: 0x24      */
  uint32_t      RESERVED2[2];   /*!< Reserved,                                  Address offset: 0x28-0x2C */
  volatile uint32_t SR;             /*!< I3C Status register,                       Address offset: 0x30      */
  volatile uint32_t SER;            /*!< I3C Status Error register,                 Address offset: 0x34      */
  uint32_t      RESERVED3[2];   /*!< Reserved,                                  Address offset: 0x38-0x3C */
  volatile uint32_t RMR;            /*!< I3C Received Message register,             Address offset: 0x40      */
  uint32_t      RESERVED4[3];   /*!< Reserved,                                  Address offset: 0x44-0x4C */
  volatile uint32_t EVR;            /*!< I3C Event register,                        Address offset: 0x50      */
  volatile uint32_t IER;            /*!< I3C Interrupt Enable register,             Address offset: 0x54      */
  volatile uint32_t CEVR;           /*!< I3C Clear Event register,                  Address offset: 0x58      */
  uint32_t RESERVED5;           /*!< Reserved,                                  Address offset: 0x5C      */
  volatile uint32_t DEVR0;          /*!< I3C own Target characteristics register,   Address offset: 0x60      */
  volatile uint32_t DEVRX[4];       /*!< I3C Target x (1<=x<=4) register,           Address offset: 0x64-0x70 */
  uint32_t      RESERVED6[7];   /*!< Reserved,                                  Address offset: 0x74-0x8C */
  volatile uint32_t MAXRLR;         /*!< I3C Maximum Read Length register,          Address offset: 0x90      */
  volatile uint32_t MAXWLR;         /*!< I3C Maximum Write Length register,         Address offset: 0x94      */
  uint32_t      RESERVED7[2];   /*!< Reserved,                                  Address offset: 0x98-0x9C */
  volatile uint32_t TIMINGR0;       /*!< I3C Timing 0 register,                     Address offset: 0xA0      */
  volatile uint32_t TIMINGR1;       /*!< I3C Timing 1 register,                     Address offset: 0xA4      */
  volatile uint32_t TIMINGR2;       /*!< I3C Timing 2 register,                     Address offset: 0xA8      */
  uint32_t      RESERVED9[5];   /*!< Reserved,                                  Address offset: 0xAC-0xBC */
  volatile uint32_t BCR;            /*!< I3C Bus Characteristics register,          Address offset: 0xC0      */
  volatile uint32_t DCR;            /*!< I3C Device Characteristics register,       Address offset: 0xC4      */
  volatile uint32_t GETCAPR;        /*!< I3C GET CAPabilities register,             Address offset: 0xC8      */
  volatile uint32_t CRCAPR;         /*!< I3C Controller CAPabilities register,      Address offset: 0xCC      */
  volatile uint32_t GETMXDSR;       /*!< I3C GET Max Data Speed register,           Address offset: 0xD0      */
  volatile uint32_t EPIDR;          /*!< I3C Extended Provisioned ID register,      Address offset: 0xD4      */
} I3C_TypeDef;

/**
  * @brief Illegal Access Controller
  */
typedef struct
{
  volatile uint32_t IER[5];         /*!< Interrupt Enable register,                 Address offset: 0x000       */
  uint32_t      RESERVED1[27];  /*!< Reserved,                                  Address offset: 0x014-0x07C */
  volatile uint32_t ISR[5];         /*!< Interrupt Status register,                 Address offset: 0x080       */
  uint32_t      RESERVED2[27];  /*!< Reserved,                                  Address offset: 0x094-0x0FC */
  volatile uint32_t ICR[5];         /*!< Interrupt Clear register,                  Address offset: 0x100       */
} IAC_TypeDef;

/**
  * @brief Instruction Cache
  */
typedef struct
{
  volatile uint32_t CR;             /*!< ICACHE control register,                Address offset: 0x00 */
  volatile uint32_t SR;             /*!< ICACHE status register,                 Address offset: 0x04 */
  volatile uint32_t IER;            /*!< ICACHE interrupt enable register,       Address offset: 0x08 */
  volatile uint32_t FCR;            /*!< ICACHE flag clear register,             Address offset: 0x0C */
  volatile uint32_t HMONR;          /*!< ICACHE hit monitor register,            Address offset: 0x10 */
  volatile uint32_t MMONR;          /*!< ICACHE miss monitor register,           Address offset: 0x14 */
} ICACHE_TypeDef;

typedef struct
{
  volatile uint32_t KR;              /*!< IWDG key register                    Address offset: 0x000 */
  volatile uint32_t PR;              /*!< IWDG prescaler register              Address offset: 0x004 */
  volatile uint32_t RLR;             /*!< IWDG reload register                 Address offset: 0x008 */
  volatile uint32_t SR;              /*!< IWDG status register                 Address offset: 0x00C */
  volatile uint32_t WINR;            /*!< IWDG window register                 Address offset: 0x010 */
  volatile uint32_t EWCR;            /*!< IWDG early wakeup interrupt register Address offset: 0x014 */
  volatile uint32_t ICR;             /*!< IWDG interrupt clear register        Address offset: 0x018 */
} IWDG_TypeDef;

/**
  * @brief JPEG Codec
  */
typedef struct
{
  volatile uint32_t CONFR0;          /*!< JPEG Codec Control Register (JPEG_CONFR0),        Address offset: 00h       */
  volatile uint32_t CONFR1;          /*!< JPEG Codec Control Register (JPEG_CONFR1),        Address offset: 04h       */
  volatile uint32_t CONFR2;          /*!< JPEG Codec Control Register (JPEG_CONFR2),        Address offset: 08h       */
  volatile uint32_t CONFR3;          /*!< JPEG Codec Control Register (JPEG_CONFR3),        Address offset: 0Ch       */
  volatile uint32_t CONFR4;          /*!< JPEG Codec Control Register (JPEG_CONFR4),        Address offset: 10h       */
  volatile uint32_t CONFR5;          /*!< JPEG Codec Control Register (JPEG_CONFR5),        Address offset: 14h       */
  volatile uint32_t CONFR6;          /*!< JPEG Codec Control Register (JPEG_CONFR6),        Address offset: 18h       */
  volatile uint32_t CONFR7;          /*!< JPEG Codec Control Register (JPEG_CONFR7),        Address offset: 1Ch       */
  uint32_t  Reserved20[4];       /* Reserved                                            Address offset: 20h-2Ch   */
  volatile uint32_t CR;              /*!< JPEG Control Register (JPEG_CR),                  Address offset: 30h       */
  volatile uint32_t SR;              /*!< JPEG Status Register (JPEG_SR),                   Address offset: 34h       */
  volatile uint32_t CFR;             /*!< JPEG Clear Flag Register (JPEG_CFR),              Address offset: 38h       */
  uint32_t  Reserved3c;          /* Reserved                                            Address offset: 3Ch       */
  volatile uint32_t DIR;             /*!< JPEG Data Input Register (JPEG_DIR),              Address offset: 40h       */
  volatile uint32_t DOR;             /*!< JPEG Data Output Register (JPEG_DOR),             Address offset: 44h       */
  uint32_t  Reserved48[2];       /* Reserved                                            Address offset: 48h-4Ch   */
  volatile uint32_t QMEM0[16];       /*!< JPEG quantization tables 0,                       Address offset: 50h-8Ch   */
  volatile uint32_t QMEM1[16];       /*!< JPEG quantization tables 1,                       Address offset: 90h-CCh   */
  volatile uint32_t QMEM2[16];       /*!< JPEG quantization tables 2,                       Address offset: D0h-10Ch  */
  volatile uint32_t QMEM3[16];       /*!< JPEG quantization tables 3,                       Address offset: 110h-14Ch */
  volatile uint32_t HUFFMIN[16];     /*!< JPEG HuffMin tables,                              Address offset: 150h-18Ch */
  volatile uint32_t HUFFBASE[32];    /*!< JPEG HuffSymb tables,                             Address offset: 190h-20Ch */
  volatile uint32_t HUFFSYMB[84];    /*!< JPEG HUFFSYMB tables,                             Address offset: 210h-35Ch */
  volatile uint32_t DHTMEM[103];     /*!< JPEG DHTMem tables,                               Address offset: 360h-4F8h */
  uint32_t  Reserved4FC;         /* Reserved                                            Address offset: 4FCh      */
  volatile uint32_t HUFFENC_AC0[88]; /*!< JPEG encodor, AC Huffman table 0,                 Address offset: 500h-65Ch */
  volatile uint32_t HUFFENC_AC1[88]; /*!< JPEG encodor, AC Huffman table 1,                 Address offset: 660h-7BCh */
  volatile uint32_t HUFFENC_DC0[8];  /*!< JPEG encodor, DC Huffman table 0,                 Address offset: 7C0h-7DCh */
  volatile uint32_t HUFFENC_DC1[8];  /*!< JPEG encodor, DC Huffman table 1,                 Address offset: 7E0h-7FCh */

} JPEG_TypeDef;


/**
  * @brief LCD-TFT Display Controller (LTDC)
  */
typedef struct
{
       uint32_t RESERVED0[2];   /*!< Reserved Address offset: 0x00-0x04 */
  volatile uint32_t SSCR;           /*!< LTDC synchronization size configuration register Address offset: 0x8 */
  volatile uint32_t BPCR;           /*!< LTDC back porch configuration register Address offset: 0xc */
  volatile uint32_t AWCR;           /*!< LTDC active width configuration register Address offset: 0x10 */
  volatile uint32_t TWCR;           /*!< LTDC total width configuration register Address offset: 0x14 */
  volatile uint32_t GCR;            /*!< LTDC global control register Address offset: 0x18 */
       uint32_t RESERVED1[2];   /*!< Reserved Address offset: */
  volatile uint32_t SRCR;           /*!< LTDC shadow reload configuration register Address offset: 0x24 */
  volatile uint32_t GCCR;           /*!< LTDC gamma correction configuration register Address offset: 0x28 */
  volatile uint32_t BCCR;           /*!< LTDC background color configuration register Address offset: 0x2c */
       uint32_t RESERVED2;      /*!< Reserved Address offset: 0x30 */
  volatile uint32_t IER;            /*!< LTDC interrupt enable register Address offset: 0x34 */
  volatile uint32_t ISR;            /*!< LTDC interrupt status register Address offset: 0x38 */
  volatile uint32_t ICR;            /*!< LTDC Interrupt Clear Register Address offset: 0x3c */
  volatile uint32_t LIPCR;          /*!< LTDC line interrupt position configuration register Address offset: 0x40 */
  volatile uint32_t CPSR;           /*!< LTDC current position status register Address offset: 0x44 */
  volatile uint32_t CDSR;           /*!< LTDC current display status register Address offset: 0x48 */
       uint32_t RESERVED3[5];   /*!< Reserved Address offset: 0x4c */
  volatile uint32_t EDCR;           /*!< LTDC external display control register Address offset: 0x60 */
  volatile uint32_t IER2;           /*!< LTDC interrupt enable register 2 Address offset: 0x64 */
  volatile uint32_t ISR2;           /*!< LTDC interrupt status register 2 Address offset: 0x68 */
  volatile uint32_t ICR2;           /*!< LTDC Interrupt Clear Register 2 Address offset: 0x6c */
  volatile uint32_t LIPCR2;         /*!< LTDC line interrupt position configuration register 2 Address offset: 0x70 */
       uint32_t RESERVED4;      /*!< Reserved Address offset: 0x74 */
  volatile uint32_t ECRCR;          /*!< LTDC expected CRC register Address offset: 0x78 */
  volatile uint32_t CCRCR;          /*!< LTDC computed CRC register Address offset: 0x7c */
  volatile uint32_t RB0AR;          /*!< LTDC rotation buffer 0 address register Address offset: 0x80 */
  volatile uint32_t RB1AR;          /*!< LTDC rotation buffer 1 address register Address offset: 0x84 */
  volatile uint32_t RBPR;           /*!< LTDC rotation buffer pitch register Address offset: 0x88 */
  volatile uint32_t RIFCR;          /*!< LTDC rotation intermediate frame color register Address offset: 0x8c */
  volatile uint32_t FUTR;           /*!< LTDC FIFO underrun threshold register Address offset: 0x90 */
} LTDC_TypeDef;

/**
  * @brief LCD-TFT Display layer x Controller (LTDC)
  */
typedef struct
{
  volatile uint32_t C0R;          /*!< LTDC layer x configuration 0 register Address offset: 0x100 */
  volatile uint32_t C1R;          /*!< LTDC layer x configuration 1 register Address offset: 0x104 */
  volatile uint32_t RCR;          /*!< LTDC layer x reload control register Address offset: 0x108 */
  volatile uint32_t CR;           /*!< LTDC layer x control register Address offset: 0x10c */
  volatile uint32_t WHPCR;        /*!< LTDC layer x window horizontal position configuration register Address offset: 0x110 */
  volatile uint32_t WVPCR;        /*!< LTDC layer x window vertical position configuration register Address offset: 0x114 */
  volatile uint32_t CKCR;         /*!< LTDC layer x color keying configuration register Address offset: 0x118 */
  volatile uint32_t PFCR;         /*!< LTDC layer x pixel format configuration register Address offset: 0x11c */
  volatile uint32_t CACR;         /*!< LTDC layer x constant alpha configuration register Address offset: 0x120 */
  volatile uint32_t DCCR;         /*!< LTDC layer x default color configuration register Address offset: 0x124 */
  volatile uint32_t BFCR;         /*!< LTDC layer x blending factors configuration register Address offset: 0x128 */
  volatile uint32_t BLCR;         /*!< LTDC layer x burst length configuration register Address offset: 0x12c */
  volatile uint32_t PCR;          /*!< LTDC layer x planar configuration register Address offset: 0x130 */
  volatile uint32_t CFBAR;        /*!< LTDC layer x color frame buffer address register Address offset: 0x134 */
  volatile uint32_t CFBLR;        /*!< LTDC layer x color frame buffer length register Address offset: 0x138 */
  volatile uint32_t CFBLNR;       /*!< LTDC layer x color frame buffer line number register Address offset: 0x13c */
  volatile uint32_t AFBA0R;       /*!< LTDC layer x auxiliary frame buffer address 0 register Address offset: 0x140 */
  volatile uint32_t AFBA1R;       /*!< LTDC layer x auxiliary frame buffer address 1 register Address offset: 0x144 */
  volatile uint32_t AFBLR;        /*!< LTDC layer x auxiliary frame buffer length register Address offset: 0x148 */
  volatile uint32_t AFBLNR;       /*!< LTDC layer x auxiliary frame buffer line number register Address offset: 0x14c */
  volatile uint32_t CLUTWR;       /*!< LTDC layer x CLUT write register Address offset: 0x150 */
  volatile uint32_t SISR;         /*!< LTDC layer x Scaler Input Size register Address offset: 0x154 */
  volatile uint32_t SOSR;         /*!< LTDC layer x Scaler Output Size register Address offset: 0x158 */
  volatile uint32_t SVSFR;        /*!< LTDC layer x Scaler Vertical Scaling Factor register Address offset: 0x15c */
  volatile uint32_t SVSPR;        /*!< LTDC layer x Scaler Vertical Scaling Phase register Address offset: 0x160 */
  volatile uint32_t SHSFR;        /*!< LTDC layer x Scaler Horizontal Scaling Factor register Address offset: 0x164 */
  volatile uint32_t SHSPR;        /*!< LTDC layer x Scaler Horizontal Scaling Phase register Address offset: 0x168 */
  volatile uint32_t CYR0R;        /*!< LTDC layer x Conversion YCbCr RGB 0 register Address offset: 0x16c */
  volatile uint32_t CYR1R;        /*!< LTDC layer x Conversion YCbCr RGB 1 register Address offset: 0x170 */
  volatile uint32_t FPF0R;        /*!< LTDC layer x Flexible Pixel Format 0 register Address offset: 0x174 */
  volatile uint32_t FPF1R;        /*!< LTDC layer x Flexible Pixel Format 1 register Address offset: 0x178 */
} LTDC_Layer_TypeDef;


/**
  * @brief LPTIMER
  */
typedef struct
{
  volatile uint32_t ISR;            /*!< LPTIM Interrupt and Status register,    Address offset: 0x00 */
  volatile uint32_t ICR;            /*!< LPTIM Interrupt Clear register,         Address offset: 0x04 */
  volatile uint32_t DIER;           /*!< LPTIM Interrupt Enable register,        Address offset: 0x08 */
  volatile uint32_t CFGR;           /*!< LPTIM Configuration register,           Address offset: 0x0C */
  volatile uint32_t CR;             /*!< LPTIM Control register,                 Address offset: 0x10 */
  volatile uint32_t CCR1;           /*!< LPTIM Capture/Compare register 1,       Address offset: 0x14 */
  volatile uint32_t ARR;            /*!< LPTIM Autoreload register,              Address offset: 0x18 */
  volatile uint32_t CNT;            /*!< LPTIM Counter register,                 Address offset: 0x1C */
  volatile uint32_t RESERVED1;      /*!< Reserved,                               Address offset: 0x20 */
  volatile uint32_t CFGR2;          /*!< LPTIM Configuration register 2,         Address offset: 0x24 */
  volatile uint32_t RCR;            /*!< LPTIM Repetition register,              Address offset: 0x28 */
  volatile uint32_t CCMR1;          /*!< LPTIM Capture/Compare mode register,    Address offset: 0x2C */
  volatile uint32_t RESERVED2;      /*!< Reserved,                               Address offset: 0x30 */
  volatile uint32_t CCR2;           /*!< LPTIM Capture/Compare register 2,       Address offset: 0x34 */
} LPTIM_TypeDef;

/**
  * @brief Memory Cipher Engine (MCE)
  */
typedef struct
{
  volatile uint32_t REGCR;            /*!< MCE region configuration register,             Address offset: 0x040 + 0x10 * (x-1) (x = 1 to 4) */
  volatile uint32_t SADDR;            /*!< MCE region start address register,             Address offset: 0x044 + 0x10 * (x-1) (x = 1 to 4) */
  volatile uint32_t EADDR;            /*!< MCE region end address register,               Address offset: 0x048 + 0x10 * (x-1) (x = 1 to 4) */
} MCE_Region_TypeDef;

typedef struct
{
  volatile uint32_t CCCFGR;           /*!< MCE cipher context configuration register,     Address offset: 0x240 + 0x30 * (x-1) (x = 1 to 2) */
  volatile uint32_t CCNR0;            /*!< MCE cipher context nonce register 0,           Address offset: 0x244 + 0x30 * (x-1) (x = 1 to 2) */
  volatile uint32_t CCNR1;            /*!< MCE cipher context nonce register 1,           Address offset: 0x248 + 0x30 * (x-1) (x = 1 to 2) */
  volatile uint32_t CCKEYR0;          /*!< MCE cipher context key register 0,             Address offset: 0x24C + 0x30 * (x-1) (x = 1 to 2) */
  volatile uint32_t CCKEYR1;          /*!< MCE cipher context key register 1,             Address offset: 0x250 + 0x30 * (x-1) (x = 1 to 2) */
  volatile uint32_t CCKEYR2;          /*!< MCE cipher context key register 2,             Address offset: 0x254 + 0x30 * (x-1) (x = 1 to 2) */
  volatile uint32_t CCKEYR3;          /*!< MCE cipher context key register 3,             Address offset: 0x258 + 0x30 * (x-1) (x = 1 to 2) */
} MCE_Context_TypeDef;

typedef struct
{
  volatile uint32_t CR;               /*!< MCE configuration register,                           Address offset: 0x000       */
  volatile uint32_t SR;               /*!< MCE status register,                                  Address offset: 0x004       */
  volatile uint32_t IASR;             /*!< MCE illegal access status register,                   Address offset: 0x008       */
  volatile uint32_t IACR;             /*!< MCE illegal access clear register,                    Address offset: 0x00C       */
  volatile uint32_t IAIER;            /*!< MCE illegal access interrupt enable register,         Address offset: 0x010       */
  uint32_t RESERVED0[4];          /*!< Reserved,                                             Address offset: 0x014-0x20  */
  volatile uint32_t IADDR;            /*!< MCE illegal address register,                         Address offset: 0x024       */
  uint32_t RESERVED1[118];        /*!< Reserved,                                             Address offset: 0x028-0x1FC */
  volatile uint32_t MKEYR0;           /*!< MCE master key register 0,                            Address offset: 0x200       */
  volatile uint32_t MKEYR1;           /*!< MCE master key register 1,                            Address offset: 0x204       */
  volatile uint32_t MKEYR2;           /*!< MCE master key register 2,                            Address offset: 0x208       */
  volatile uint32_t MKEYR3;           /*!< MCE master key register 3,                            Address offset: 0x20C       */
  volatile uint32_t MKEYR4;           /*!< MCE master key register 4,                            Address offset: 0x210       */
  volatile uint32_t MKEYR5;           /*!< MCE master key register 5,                            Address offset: 0x214       */
  volatile uint32_t MKEYR6;           /*!< MCE master key register 6,                            Address offset: 0x218       */
  volatile uint32_t MKEYR7;           /*!< MCE master key register 7,                            Address offset: 0x21C       */
  volatile uint32_t FMKEYR0;          /*!< MCE fast master key register 0,                       Address offset: 0x220       */
  volatile uint32_t FMKEYR1;          /*!< MCE fast master key register 1,                       Address offset: 0x224       */
  volatile uint32_t FMKEYR2;          /*!< MCE fast master key register 2,                       Address offset: 0x228       */
  volatile uint32_t FMKEYR3;          /*!< MCE fast master key register 3,                       Address offset: 0x22C       */
  volatile uint32_t FMKEYR4;          /*!< MCE fast master key register 4,                       Address offset: 0x230       */
  volatile uint32_t FMKEYR5;          /*!< MCE fast master key register 5,                       Address offset: 0x234       */
  volatile uint32_t FMKEYR6;          /*!< MCE fast master key register 6,                       Address offset: 0x238       */
  volatile uint32_t FMKEYR7;          /*!< MCE fast master key register 7,                       Address offset: 0x23C       */
} MCE_TypeDef;



/**
  * @brief ADF
  */
typedef struct
{
  volatile uint32_t GCR;            /*!< MDF Global Control register,             Address offset: 0x00  */
  volatile uint32_t CKGCR;          /*!< MDF Clock Generator Control Register,    Address offset: 0x04  */
  uint32_t      RESERVED1[6];   /*!< Reserved, 0x08-0x1C                                            */
  volatile uint32_t OR;             /*!< MDF  Option Register,                    Address offset: 0x20  */
} MDF_TypeDef;

/**
  * @brief ADF filter
  */
typedef struct
{
 volatile uint32_t SITFCR;         /*!< MDF Serial Interface Control Register,          Address offset: 0x80 */
 volatile uint32_t BSMXCR;         /*!< MDF Bitstream Matrix Control Register,          Address offset: 0x84 */
 volatile uint32_t DFLTCR;         /*!< MDF Digital Filter Control Register,            Address offset: 0x88 */
 volatile uint32_t DFLTCICR;       /*!< MDF MCIC Configuration Register,                Address offset: 0x8C */
 volatile uint32_t DFLTRSFR;       /*!< MDF Reshape Filter Configuration Register,      Address offset: 0x90 */
 volatile uint32_t DFLTINTR;       /*!< MDF Integrator Configuration Register,          Address offset: 0x94 */
 volatile uint32_t OLDCR;          /*!< MDF Out-Of Limit Detector Control Register,     Address offset: 0x98 */
 volatile uint32_t OLDTHLR;        /*!< MDF OLD Threshold Low Register,                 Address offset: 0x9C */
 volatile uint32_t OLDTHHR;        /*!< MDF OLD Threshold High Register,                Address offset: 0xA0 */
 volatile uint32_t DLYCR;          /*!< MDF Delay control Register,                     Address offset: 0xA4 */
 volatile uint32_t SCDCR;          /*!< MDF short circuit detector control Register,    Address offset: 0xA8 */
 volatile uint32_t DFLTIER;        /*!< MDF DFLT Interrupt enable Register,             Address offset: 0xAC */
 volatile uint32_t DFLTISR;        /*!< MDF DFLT Interrupt status Register,             Address offset: 0xB0 */
 volatile uint32_t OECCR;          /*!< MDF Offset Error Compensation Control Register, Address offset: 0xB4 */
 volatile uint32_t SADCR;          /*!< MDF SAD Control Register,                       Address offset: 0xB8 */
 volatile uint32_t SADCFGR;        /*!< MDF SAD configuration register,                 Address offset: 0xBC */
 volatile uint32_t SADSDLVR;       /*!< MDF SAD Sound level Register,                   Address offset: 0xC0 */
 volatile uint32_t SADANLVR;       /*!< MDF SAD Ambient Noise level Register,           Address offset: 0xC4 */
 uint32_t     RESERVED1[9];    /*!< Reserved, 0xC8-0xE8                                                  */
 volatile uint32_t SNPSDR;         /*!< MDF Snapshot Data Register,                     Address offset: 0xEC */
 volatile uint32_t DFLTDR;         /*!< MDF Digital Filter Data Register,               Address offset: 0xF0 */
} MDF_Filter_TypeDef;


/**
  * @brief MDIOS
  */

typedef struct
{
  volatile uint32_t CR;
  volatile uint32_t WRFR;
  volatile uint32_t CWRFR;
  volatile uint32_t RDFR;
  volatile uint32_t CRDFR;
  volatile uint32_t SR;
  volatile uint32_t CLRFR;
  uint32_t RESERVED[57];
  volatile uint32_t DINR0;
  volatile uint32_t DINR1;
  volatile uint32_t DINR2;
  volatile uint32_t DINR3;
  volatile uint32_t DINR4;
  volatile uint32_t DINR5;
  volatile uint32_t DINR6;
  volatile uint32_t DINR7;
  volatile uint32_t DINR8;
  volatile uint32_t DINR9;
  volatile uint32_t DINR10;
  volatile uint32_t DINR11;
  volatile uint32_t DINR12;
  volatile uint32_t DINR13;
  volatile uint32_t DINR14;
  volatile uint32_t DINR15;
  volatile uint32_t DINR16;
  volatile uint32_t DINR17;
  volatile uint32_t DINR18;
  volatile uint32_t DINR19;
  volatile uint32_t DINR20;
  volatile uint32_t DINR21;
  volatile uint32_t DINR22;
  volatile uint32_t DINR23;
  volatile uint32_t DINR24;
  volatile uint32_t DINR25;
  volatile uint32_t DINR26;
  volatile uint32_t DINR27;
  volatile uint32_t DINR28;
  volatile uint32_t DINR29;
  volatile uint32_t DINR30;
  volatile uint32_t DINR31;
  volatile uint32_t DOUTR0;
  volatile uint32_t DOUTR1;
  volatile uint32_t DOUTR2;
  volatile uint32_t DOUTR3;
  volatile uint32_t DOUTR4;
  volatile uint32_t DOUTR5;
  volatile uint32_t DOUTR6;
  volatile uint32_t DOUTR7;
  volatile uint32_t DOUTR8;
  volatile uint32_t DOUTR9;
  volatile uint32_t DOUTR10;
  volatile uint32_t DOUTR11;
  volatile uint32_t DOUTR12;
  volatile uint32_t DOUTR13;
  volatile uint32_t DOUTR14;
  volatile uint32_t DOUTR15;
  volatile uint32_t DOUTR16;
  volatile uint32_t DOUTR17;
  volatile uint32_t DOUTR18;
  volatile uint32_t DOUTR19;
  volatile uint32_t DOUTR20;
  volatile uint32_t DOUTR21;
  volatile uint32_t DOUTR22;
  volatile uint32_t DOUTR23;
  volatile uint32_t DOUTR24;
  volatile uint32_t DOUTR25;
  volatile uint32_t DOUTR26;
  volatile uint32_t DOUTR27;
  volatile uint32_t DOUTR28;
  volatile uint32_t DOUTR29;
  volatile uint32_t DOUTR30;
  volatile uint32_t DOUTR31;
} MDIOS_TypeDef;

/**
  * @brief PSSI
  */
typedef struct
{
  volatile uint32_t CR;             /*!< PSSI control register,                 Address offset: 0x000 */
  volatile uint32_t SR;             /*!< PSSI status register,                  Address offset: 0x004 */
  volatile uint32_t RIS;            /*!< PSSI raw interrupt status register,    Address offset: 0x008 */
  volatile uint32_t IER;            /*!< PSSI interrupt enable register,        Address offset: 0x00C */
  volatile uint32_t MIS;            /*!< PSSI masked interrupt status register, Address offset: 0x010 */
  volatile uint32_t ICR;            /*!< PSSI interrupt clear register,         Address offset: 0x014 */
  volatile uint32_t RESERVED1[4];   /*!< Reserved,                                      0x018 - 0x024 */
  volatile uint32_t DR;             /*!< PSSI data register,                    Address offset: 0x028 */
} PSSI_TypeDef;

/**
  * @brief Power Control
  */
typedef struct
{
  volatile uint32_t CR1;             /*!< PWR Control register 1                           Address offset: 0x000 */
  volatile uint32_t CR2;             /*!< PWR Control Register 2                           Address offset: 0x004 */
  volatile uint32_t CR3;             /*!< PWR Control Register 3                           Address offset: 0x008 */
  volatile uint32_t CR4;             /*!< PWR Control Register 4                           Address offset: 0x00C */
       uint32_t RESERVED0[4];    /*!< Reserved                                         Address offset: 0x010-0x01C */
  volatile uint32_t VOSCR;           /*!< PWR Voltage scaling control register             Address offset: 0x020 */
  volatile uint32_t BDCR1;           /*!< PWR Backup domain control register 1             Address offset: 0x024 */
  volatile uint32_t BDCR2;           /*!< PWR Backup domain control register 2             Address offset: 0x028 */
  volatile uint32_t DBPCR;           /*!< PWR Disable backup protection control register   Address offset: 0x02C */
  volatile uint32_t CPUCR;           /*!< PWR CPU control register                         Address offset: 0x030 */
  volatile uint32_t SVMCR1;          /*!< PWR Supply voltage monitoring control register 1 Address offset: 0x034 */
  volatile uint32_t SVMCR2;          /*!< PWR Supply voltage monitoring control register 2 Address offset: 0x038 */
  volatile uint32_t SVMCR3;          /*!< PWR Supply voltage monitoring control register 3 Address offset: 0x03C */
       uint32_t RESERVED1[4];    /*!< Reserved                                         Address offset: 0x040-0x04C */
  volatile uint32_t WKUPCR;          /*!< PWR Wakeup control register 1                    Address offset: 0x050 */
  volatile uint32_t WKUPSR;          /*!< PWR Wakeup control register 2                    Address offset: 0x054 */
  volatile uint32_t WKUPEPR;         /*!< PWR Wakeup control register 3                    Address offset: 0x058 */
       uint32_t RESERVED2[5];    /*!< Reserved                                         Address offset: 0x05C-0x06C */
  volatile uint32_t SECCFGR;         /*!< PWR Security configuration register              Address offset: 0x070 */
  volatile uint32_t PRIVCFGR;        /*!< PWR Privilege configuration register             Address offset: 0x074 */
} PWR_TypeDef;

/**
  * @brief PKA
  */
typedef struct
{
  volatile uint32_t CR;            /*!< PKA control register,             Address offset: 0x00 */
  volatile uint32_t SR;            /*!< PKA status register,              Address offset: 0x04 */
  volatile uint32_t CLRFR;         /*!< PKA clear flag register,          Address offset: 0x08 */
  uint32_t Reserved[253];      /*!< Reserved memory area              Address offset: 0x0C  -> 0x03FC */
  volatile uint32_t RAM[1334];     /*!< PKA RAM                           Address offset: 0x400 -> 0x18D4 */
} PKA_TypeDef;

/**
  * @brief RAMs configuration controller
  */
typedef struct
{
  volatile uint32_t CR;          /*!< Control Register,                    Address offset: 0x00 */
  volatile uint32_t IER;         /*!< Interrupt Enable Register,           Address offset: 0x04 */
  volatile uint32_t ISR;         /*!< Interrupt Status Register,           Address offset: 0x08 */
  volatile uint32_t ESEAR;       /*!< ECC Single Error Address Register,   Address offset: 0x0C */
  volatile uint32_t EDEAR;       /*!< ECC Double Error Address Register,   Address offset: 0x10 */
  volatile uint32_t ICR;         /*!< Interrupt Clear Register,            Address offset: 0x14 */
  uint32_t      RESERVED[3]; /*!< Reserved,                       Address offset: 0x18-0x20 */
  volatile uint32_t ECCKEYR;     /*!< RAM ECC Key Register,                Address offset: 0x24 */
  volatile uint32_t ERKEYR;      /*!< RAM Erase Key Register,              Address offset: 0x28 */
}RAMCFG_TypeDef;

/**
  * @brief Reset and Clock Control
  */

typedef struct
{
  volatile uint32_t CR;               /*!< RCC control register                                           Address offset: 0x0000 */
  volatile uint32_t SR;               /*!< RCC status register                                            Address offset: 0x0004 */
  volatile uint32_t STOPCR;           /*!< RCC Stop mode control register                                 Address offset: 0x0008 */
       uint32_t RESERVED0[5];     /*!< Reserved                                                       Address offset: 0x000C-0x001C */
  volatile uint32_t CFGR1;            /*!< RCC configuration register 1                                   Address offset: 0x0020 */
  volatile uint32_t CFGR2;            /*!< RCC configuration register 2                                   Address offset: 0x0024 */
       uint32_t RESERVED1;        /*!< Reserved                                                       Address offset: 0x0028 */
  volatile uint32_t BDCR;             /*!< RCC backup domain protection register                          Address offset: 0x002C */
  volatile uint32_t HWRSR;            /*!< RCC reset status register for hardware                         Address offset: 0x0030 */
  volatile uint32_t RSR;              /*!< RCC reset register                                             Address offset: 0x0034 */
       uint32_t RESERVED2[2];     /*!< Reserved                                                       Address offset: 0x0038-0x003C */
  volatile uint32_t LSECFGR;          /*!< RCC LSE configuration register                                 Address offset: 0x0040 */
  volatile uint32_t MSICFGR;          /*!< RCC MSI configuration register                                 Address offset: 0x0044 */
  volatile uint32_t HSICFGR;          /*!< RCC HSI configuration register                                 Address offset: 0x0048 */
  volatile uint32_t HSIMCR;           /*!< RCC HSI Monitor control register                               Address offset: 0x004C */
  volatile uint32_t HSIMSR;           /*!< RCC HSI Monitor status register                                Address offset: 0x0050 */
  volatile uint32_t HSECFGR;          /*!< RCC HSE configuration register                                 Address offset: 0x0054 */
       uint32_t RESERVED3[10];    /*!< Reserved                                                       Address offset: 0x0058-0x007C */
  volatile uint32_t PLL1CFGR1;        /*!< RCC PLL1 configuration register 1                              Address offset: 0x0080 */
  volatile uint32_t PLL1CFGR2;        /*!< RCC PLL1 configuration register 2                              Address offset: 0x0084 */
  volatile uint32_t PLL1CFGR3;        /*!< RCC PLL1 configuration register 3                              Address offset: 0x0088 */
       uint32_t RESERVED4;        /*!< Reserved                                                       Address offset: 0x008C */
  volatile uint32_t PLL2CFGR1;        /*!< RCC PLL2 configuration register 1                              Address offset: 0x0090 */
  volatile uint32_t PLL2CFGR2;        /*!< RCC PLL2 configuration register 2                              Address offset: 0x0094 */
  volatile uint32_t PLL2CFGR3;        /*!< RCC PLL2 configuration register 3                              Address offset: 0x0098 */
       uint32_t RESERVED5;        /*!< Reserved                                                       Address offset: 0x009C */
  volatile uint32_t PLL3CFGR1;        /*!< RCC PLL3 configuration register 1                              Address offset: 0x00A0 */
  volatile uint32_t PLL3CFGR2;        /*!< RCC PLL3 configuration register 2                              Address offset: 0x00A4 */
  volatile uint32_t PLL3CFGR3;        /*!< RCC PLL3 configuration register 3                              Address offset: 0x00A8 */
       uint32_t RESERVED6;        /*!< Reserved                                                       Address offset: 0x00AC */
  volatile uint32_t PLL4CFGR1;        /*!< RCC PLL4 configuration register 1                              Address offset: 0x00B0 */
  volatile uint32_t PLL4CFGR2;        /*!< RCC PLL4 configuration register 2                              Address offset: 0x00B4 */
  volatile uint32_t PLL4CFGR3;        /*!< RCC PLL4 configuration register 3                              Address offset: 0x00B8 */
       uint32_t RESERVED7[2];     /*!< Reserved                                                       Address offset: 0x00BC-0x00C0 */
  volatile uint32_t IC1CFGR;          /*!< RCC IC1 configuration register                                 Address offset: 0x00C4 */
  volatile uint32_t IC2CFGR;          /*!< RCC IC2 configuration register                                 Address offset: 0x00C8 */
  volatile uint32_t IC3CFGR;          /*!< RCC IC3 configuration register                                 Address offset: 0x00CC */
  volatile uint32_t IC4CFGR;          /*!< RCC IC4 configuration register                                 Address offset: 0x00D0 */
  volatile uint32_t IC5CFGR;          /*!< RCC IC5 configuration register                                 Address offset: 0x00D4 */
  volatile uint32_t IC6CFGR;          /*!< RCC IC6 configuration register                                 Address offset: 0x00D8 */
  volatile uint32_t IC7CFGR;          /*!< RCC IC7 configuration register                                 Address offset: 0x00DC */
  volatile uint32_t IC8CFGR;          /*!< RCC IC8 configuration register                                 Address offset: 0x00E0 */
  volatile uint32_t IC9CFGR;          /*!< RCC IC9 configuration register                                 Address offset: 0x00E4 */
  volatile uint32_t IC10CFGR;         /*!< RCC IC10 configuration register                                Address offset: 0x00E8 */
  volatile uint32_t IC11CFGR;         /*!< RCC IC11 configuration register                                Address offset: 0x00EC */
  volatile uint32_t IC12CFGR;         /*!< RCC IC12 configuration register                                Address offset: 0x00F0 */
  volatile uint32_t IC13CFGR;         /*!< RCC IC13 configuration register                                Address offset: 0x00F4 */
  volatile uint32_t IC14CFGR;         /*!< RCC IC14 configuration register                                Address offset: 0x00F8 */
  volatile uint32_t IC15CFGR;         /*!< RCC IC15 configuration register                                Address offset: 0x00FC */
  volatile uint32_t IC16CFGR;         /*!< RCC IC16 configuration register                                Address offset: 0x0100 */
  volatile uint32_t IC17CFGR;         /*!< RCC IC17 configuration register                                Address offset: 0x0104 */
  volatile uint32_t IC18CFGR;         /*!< RCC IC18 configuration register                                Address offset: 0x0108 */
  volatile uint32_t IC19CFGR;         /*!< RCC IC19 configuration register                                Address offset: 0x010C */
  volatile uint32_t IC20CFGR;         /*!< RCC IC20 configuration register                                Address offset: 0x0110 */
       uint32_t RESERVED8[4];     /*!< Reserved                                                       Address offset: 0x0114-0x0120 */
  volatile uint32_t CIER;             /*!< RCC clock-source interrupt enable register                     Address offset: 0x0124 */
  volatile uint32_t CIFR;             /*!< RCC clock-source interrupt flag register                       Address offset: 0x0128 */
  volatile uint32_t CICR;             /*!< RCC clock-source interrupt clear register                      Address offset: 0x012C */
       uint32_t RESERVED9[5];     /*!< Reserved                                                       Address offset: 0x0130-0x0140 */
  volatile uint32_t CCIPR1;           /*!< RCC clock configuration for independent peripheral register 1  Address offset: 0x0144 */
  volatile uint32_t CCIPR2;           /*!< RCC clock configuration for independent peripheral register 2  Address offset: 0x0148 */
  volatile uint32_t CCIPR3;           /*!< RCC clock configuration for independent peripheral register 3  Address offset: 0x014C */
  volatile uint32_t CCIPR4;           /*!< RCC clock configuration for independent peripheral register 4  Address offset: 0x0150 */
  volatile uint32_t CCIPR5;           /*!< RCC clock configuration for independent peripheral register 5  Address offset: 0x0154 */
  volatile uint32_t CCIPR6;           /*!< RCC clock configuration for independent peripheral register 6  Address offset: 0x0158 */
  volatile uint32_t CCIPR7;           /*!< RCC clock configuration for independent peripheral register 7  Address offset: 0x015C */
  volatile uint32_t CCIPR8;           /*!< RCC clock configuration for independent peripheral register 8  Address offset: 0x0160 */
  volatile uint32_t CCIPR9;           /*!< RCC clock configuration for independent peripheral register 9  Address offset: 0x0164 */
       uint32_t RESERVED10[2];    /*!< Reserved                                                       Address offset: 0x0168-0x016C */
  volatile uint32_t CCIPR12;          /*!< RCC clock configuration for independent peripheral register 12 Address offset: 0x0170 */
  volatile uint32_t CCIPR13;          /*!< RCC clock configuration for independent peripheral register 13 Address offset: 0x0174 */
  volatile uint32_t CCIPR14;          /*!< RCC clock configuration for independent peripheral register 14 Address offset: 0x0178 */
       uint32_t RESERVED11[35];   /*!< Reserved                                                       Address offset: 0x017C-0x0204 */
  volatile uint32_t MISCRSTR;         /*!< RCC miscellaneous configurations reset register                Address offset: 0x0208 */
  volatile uint32_t MEMRSTR;          /*!< RCC embedded memories reset register                           Address offset: 0x020C */
  volatile uint32_t AHB1RSTR;         /*!< RCC AHB1 reset register                                        Address offset: 0x0210 */
  volatile uint32_t AHB2RSTR;         /*!< RCC AHB2 reset register                                        Address offset: 0x0214 */
  volatile uint32_t AHB3RSTR;         /*!< RCC AHB3 reset register                                        Address offset: 0x0218 */
  volatile uint32_t AHB4RSTR;         /*!< RCC AHB4 reset register                                        Address offset: 0x021C */
  volatile uint32_t AHB5RSTR;         /*!< RCC AHB5 reset register                                        Address offset: 0x0220 */
  volatile uint32_t APB1RSTR1;        /*!< RCC APB1 reset register 1                                      Address offset: 0x0224 */
  volatile uint32_t APB1RSTR2;        /*!< RCC APB1 reset register 2                                      Address offset: 0x0228 */
  volatile uint32_t APB2RSTR;         /*!< RCC APB2 reset register                                        Address offset: 0x022C */
       uint32_t RESERVED12;       /*!< Reserved                                                       Address offset: 0x0230 */
  volatile uint32_t APB4RSTR1;        /*!< RCC APB4 reset register 1                                      Address offset: 0x0234 */
  volatile uint32_t APB4RSTR2;        /*!< RCC APB4 reset register 2                                      Address offset: 0x0238 */
  volatile uint32_t APB5RSTR;         /*!< RCC APB5 reset register                                        Address offset: 0x023C */
  volatile uint32_t DIVENR;           /*!< RCC IC dividers enable register                                Address offset: 0x0240 */
  volatile uint32_t BUSENR;           /*!< RCC embedded buses enable register                             Address offset: 0x0244 */
  volatile uint32_t MISCENR;          /*!< RCC miscellaneous configurations enable register               Address offset: 0x0248 */
  volatile uint32_t MEMENR;           /*!< RCC embedded memories enable register                          Address offset: 0x024C */
  volatile uint32_t AHB1ENR;          /*!< RCC AHB1 enable register                                       Address offset: 0x0250 */
  volatile uint32_t AHB2ENR;          /*!< RCC AHB2 enable register                                       Address offset: 0x0254 */
  volatile uint32_t AHB3ENR;          /*!< RCC AHB3 enable register                                       Address offset: 0x0258 */
  volatile uint32_t AHB4ENR;          /*!< RCC AHB4 enable register                                       Address offset: 0x025C */
  volatile uint32_t AHB5ENR;          /*!< RCC AHB5 enable register                                       Address offset: 0x0260 */
  volatile uint32_t APB1ENR1;         /*!< RCC APB1 enable register 1                                     Address offset: 0x0264 */
  volatile uint32_t APB1ENR2;         /*!< RCC APB1 enable register 2                                     Address offset: 0x0268 */
  volatile uint32_t APB2ENR;          /*!< RCC APB2 enable register                                       Address offset: 0x026C */
  volatile uint32_t APB3ENR;          /*!< RCC APB3 enable register                                       Address offset: 0x0270 */
  volatile uint32_t APB4ENR1;         /*!< RCC APB4 enable register 1                                     Address offset: 0x0274 */
  volatile uint32_t APB4ENR2;         /*!< RCC APB4 enable register 2                                     Address offset: 0x0278 */
  volatile uint32_t APB5ENR;          /*!< RCC APB5 enable register                                       Address offset: 0x027C */
       uint32_t RESERVED13;       /*!< Reserved                                                       Address offset: 0x0280 */
  volatile uint32_t BUSLPENR;         /*!< RCC embedded buses sleep enable register                       Address offset: 0x0284 */
  volatile uint32_t MISCLPENR;        /*!< RCC miscellaneous configurations sleep enable register         Address offset: 0x0288 */
  volatile uint32_t MEMLPENR;         /*!< RCC embedded memories sleep enable register                    Address offset: 0x028C */
  volatile uint32_t AHB1LPENR;        /*!< RCC AHB1 sleep enable register                                 Address offset: 0x0290 */
  volatile uint32_t AHB2LPENR;        /*!< RCC AHB2 sleep enable register                                 Address offset: 0x0294 */
  volatile uint32_t AHB3LPENR;        /*!< RCC AHB3 sleep enable register                                 Address offset: 0x0298 */
  volatile uint32_t AHB4LPENR;        /*!< RCC AHB4 sleep enable register                                 Address offset: 0x029C */
  volatile uint32_t AHB5LPENR;        /*!< RCC AHB5 sleep enable register                                 Address offset: 0x02A0 */
  volatile uint32_t APB1LPENR1;       /*!< RCC APB1 sleep enable register 1                               Address offset: 0x02A4 */
  volatile uint32_t APB1LPENR2;       /*!< RCC APB1 sleep enable register 2                               Address offset: 0x02A8 */
  volatile uint32_t APB2LPENR;        /*!< RCC APB2 sleep enable register                                 Address offset: 0x02AC */
  volatile uint32_t APB3LPENR;        /*!< RCC APB3 sleep enable register                                 Address offset: 0x02B0 */
  volatile uint32_t APB4LPENR1;       /*!< RCC APB4 sleep enable register 1                               Address offset: 0x02B4 */
  volatile uint32_t APB4LPENR2;       /*!< RCC APB4 sleep enable register 2                               Address offset: 0x02B8 */
  volatile uint32_t APB5LPENR;        /*!< RCC APB5 sleep enable register                                 Address offset: 0x02BC */
       uint32_t RESERVED14[99];   /*!< Reserved                                                       Address offset: 0x02C0-0x0448 */
  volatile uint32_t RDCR;             /*!< RCC reset duration control register                            Address offset: 0x044C */
       uint32_t RESERVED15[204];  /*!< Reserved                                                       Address offset: 0x0450-0x077C */
  volatile uint32_t SECCFGR0;         /*!< RCC oscillator secure configuration register 0                 Address offset: 0x0780 */
  volatile uint32_t PRIVCFGR0;        /*!< RCC oscillator privilege configuration register 0              Address offset: 0x0784 */
  volatile uint32_t LOCKCFGR0;        /*!< RCC oscillator lock configuration register 0                   Address offset: 0x0788 */
  volatile uint32_t PUBCFGR0;         /*!< RCC oscillator public configuration register 0                 Address offset: 0x078C */
  volatile uint32_t SECCFGR1;         /*!< RCC PLL secure configuration register 1                        Address offset: 0x0790 */
  volatile uint32_t PRIVCFGR1;        /*!< RCC PLL privilege configuration register 1                     Address offset: 0x0794 */
  volatile uint32_t LOCKCFGR1;        /*!< RCC PLL lock configuration register 1                          Address offset: 0x0798 */
  volatile uint32_t PUBCFGR1;         /*!< RCC PLL public configuration register 1                        Address offset: 0x079C */
  volatile uint32_t SECCFGR2;         /*!< RCC divider secure configuration register 2                    Address offset: 0x07A0 */
  volatile uint32_t PRIVCFGR2;        /*!< RCC divider privilege configuration register 2                 Address offset: 0x07A4 */
  volatile uint32_t LOCKCFGR2;        /*!< RCC divider lock configuration register 2                      Address offset: 0x07A8 */
  volatile uint32_t PUBCFGR2;         /*!< RCC divider public configuration register 2                    Address offset: 0x07AC */
  volatile uint32_t SECCFGR3;         /*!< RCC system secure configuration register 3                     Address offset: 0x07B0 */
  volatile uint32_t PRIVCFGR3;        /*!< RCC system privilege configuration register 3                  Address offset: 0x07B4 */
  volatile uint32_t LOCKCFGR3;        /*!< RCC system lock configuration register 3                       Address offset: 0x07B8 */
  volatile uint32_t PUBCFGR3;         /*!< RCC system public configuration register 3                     Address offset: 0x07BC */
  volatile uint32_t SECCFGR4;         /*!< RCC bus secure configuration register 4                        Address offset: 0x07C0 */
  volatile uint32_t PRIVCFGR4;        /*!< RCC bus privilege configuration register 4                     Address offset: 0x07C4 */
  volatile uint32_t LOCKCFGR4;        /*!< RCC bus lock configuration register 4                          Address offset: 0x07C8 */
  volatile uint32_t PUBCFGR4;         /*!< RCC bus public configuration register 4                        Address offset: 0x07CC */
  volatile uint32_t PUBCFGR5;         /*!< RCC bus public configuration register 4                        Address offset: 0x07D0 */
       uint32_t RESERVED16[11];   /*!< Reserved                                                       Address offset: 0x07D4-0x07FC */
  volatile uint32_t CSR;              /*!< RCC control Set register                                       Address offset: 0x0800 */
       uint32_t RESERVED17;       /*!< Reserved                                                       Address offset: 0x0804 */
  volatile uint32_t STOPCSR;          /*!< RCC STOPCSR configuration register                             Address offset: 0x0808 */
       uint32_t RESERVED18[127];  /*!< Reserved                                                       Address offset: 0x080C-0x0A00 */
  volatile uint32_t MISCRSTSR;        /*!< RCC miscellaneous reset register                               Address offset: 0x0A08 */
  volatile uint32_t MEMRSTSR;         /*!< RCC memory reset register                                      Address offset: 0x0A0C */
  volatile uint32_t AHB1RSTSR;        /*!< RCC AHB1 reset register                                        Address offset: 0x0A10 */
  volatile uint32_t AHB2RSTSR;        /*!< RCC AHB2 reset register                                        Address offset: 0x0A14 */
  volatile uint32_t AHB3RSTSR;        /*!< RCC AHB3 reset register                                        Address offset: 0x0A18 */
  volatile uint32_t AHB4RSTSR;        /*!< RCC AHB4 reset register                                        Address offset: 0x0A1C */
  volatile uint32_t AHB5RSTSR;        /*!< RCC AHB5 reset register                                        Address offset: 0x0A20 */
  volatile uint32_t APB1RSTSR1;       /*!< RCC APB1 reset register 1                                      Address offset: 0x0A24 */
  volatile uint32_t APB1RSTSR2;       /*!< RCC APB1 reset register 2                                      Address offset: 0x0A28 */
  volatile uint32_t APB2RSTSR;        /*!< RCC APB2 reset register                                        Address offset: 0x0A2C */
       uint32_t RESERVED19;       /*!< Reserved                                                       Address offset: 0x0A30 */
  volatile uint32_t APB4RSTSR1;       /*!< RCC APB4 reset register 1                                      Address offset: 0x0A34 */
  volatile uint32_t APB4RSTSR2;       /*!< RCC APB4 reset register 2                                      Address offset: 0x0A38 */
  volatile uint32_t APB5RSTSR;        /*!< RCC APB5 reset register                                        Address offset: 0x0A3C */
  volatile uint32_t DIVENSR;          /*!< RCC divider enable register                                    Address offset: 0x0A40 */
  volatile uint32_t BUSENSR;          /*!< RCC bus enable register                                        Address offset: 0x0A44 */
  volatile uint32_t MISCENSR;         /*!< RCC miscellaneous enable register                              Address offset: 0x0A48 */
  volatile uint32_t MEMENSR;          /*!< RCC memory enable register                                     Address offset: 0x0A4C */
  volatile uint32_t AHB1ENSR;         /*!< RCC AHB1 enable register                                       Address offset: 0x0A50 */
  volatile uint32_t AHB2ENSR;         /*!< RCC AHB2 enable register                                       Address offset: 0x0A54 */
  volatile uint32_t AHB3ENSR;         /*!< RCC AHB3 enable register                                       Address offset: 0x0A58 */
  volatile uint32_t AHB4ENSR;         /*!< RCC AHB4 enable register                                       Address offset: 0x0A5C */
  volatile uint32_t AHB5ENSR;         /*!< RCC AHB5 enable register                                       Address offset: 0x0A60 */
  volatile uint32_t APB1ENSR1;        /*!< RCC APB1 enable register 1                                     Address offset: 0x0A64 */
  volatile uint32_t APB1ENSR2;        /*!< RCC APB1 enable register 2                                     Address offset: 0x0A68 */
  volatile uint32_t APB2ENSR;         /*!< RCC APB2 enable register                                       Address offset: 0x0A6C */
  volatile uint32_t APB3ENSR;         /*!< RCC APB3 enable register                                       Address offset: 0x0A70 */
  volatile uint32_t APB4ENSR1;        /*!< RCC APB4 enable register 1                                     Address offset: 0x0A74 */
  volatile uint32_t APB4ENSR2;        /*!< RCC APB4 enable register 2                                     Address offset: 0x0A78 */
  volatile uint32_t APB5ENSR;         /*!< RCC APB5 enable register                                       Address offset: 0x0A7C */
       uint32_t RESERVED20;       /*!< Reserved                                                       Address offset: 0x0A80 */
  volatile uint32_t BUSLPENSR;        /*!< RCC bus sleep enable register                                  Address offset: 0x0A84 */
  volatile uint32_t MISCLPENSR;       /*!< RCC miscellaneous sleep enable register                        Address offset: 0x0A88 */
  volatile uint32_t MEMLPENSR;        /*!< RCC memory sleep enable register                               Address offset: 0x0A8C */
  volatile uint32_t AHB1LPENSR;       /*!< RCC AHB1 sleep enable register                                 Address offset: 0x0A90 */
  volatile uint32_t AHB2LPENSR;       /*!< RCC AHB2 sleep enable register                                 Address offset: 0x0A94 */
  volatile uint32_t AHB3LPENSR;       /*!< RCC AHB3 sleep enable register                                 Address offset: 0x0A98 */
  volatile uint32_t AHB4LPENSR;       /*!< RCC AHB4 sleep enable register                                 Address offset: 0x0A9C */
  volatile uint32_t AHB5LPENSR;       /*!< RCC AHB5 sleep enable register                                 Address offset: 0x0AA0 */
  volatile uint32_t APB1LPENSR1;      /*!< RCC APB1 sleep enable register 1                               Address offset: 0x0AA4 */
  volatile uint32_t APB1LPENSR2;      /*!< RCC APB1 sleep enable register 2                               Address offset: 0x0AA8 */
  volatile uint32_t APB2LPENSR;       /*!< RCC APB2 sleep enable register                                 Address offset: 0x0AAC */
  volatile uint32_t APB3LPENSR;       /*!< RCC APB3 sleep enable register                                 Address offset: 0x0AB0 */
  volatile uint32_t APB4LPENSR1;      /*!< RCC APB4 sleep enable register 1                               Address offset: 0x0AB4 */
  volatile uint32_t APB4LPENSR2;      /*!< RCC APB4 sleep enable register 2                               Address offset: 0x0AB8 */
  volatile uint32_t APB5LPENSR;       /*!< RCC APB5 sleep enable register                                 Address offset: 0x0ABC */
       uint32_t RESERVED21[305];  /*!< Reserved                                                       Address offset: 0x0AC0-0x0F80 */
  volatile uint32_t PRIVCFGSR0;       /*!< RCC oscillator privilege configuration set register 0          Address offset: 0x0F84 */
       uint32_t RESERVED22;       /*!< Reserved                                                       Address offset: 0x0F88 */
  volatile uint32_t PUBCFGSR0;        /*!< RCC oscillator public configuration set register 0             Address offset: 0x0F8C */
       uint32_t RESERVED23;       /*!< Reserved                                                       Address offset: 0x0F90 */
  volatile uint32_t PRIVCFGSR1;       /*!< RCC PLL privilege configuration set register 1                 Address offset: 0x0F94 */
       uint32_t RESERVED24;       /*!< Reserved                                                       Address offset: 0x0F98 */
  volatile uint32_t PUBCFGSR1;        /*!< RCC PLL public configuration set register 1                    Address offset: 0x0F9C */
       uint32_t RESERVED25;       /*!< Reserved                                                       Address offset: 0x0FA0 */
  volatile uint32_t PRIVCFGSR2;       /*!< RCC divider privilege configuration set register 2             Address offset: 0x0FA4 */
       uint32_t RESERVED26;       /*!< Reserved                                                       Address offset: 0x0FA8 */
  volatile uint32_t PUBCFGSR2;        /*!< RCC divider public configuration set register 2                Address offset: 0x0FAC */
       uint32_t RESERVED27;       /*!< Reserved                                                       Address offset: 0x0FB0 */
  volatile uint32_t PRIVCFGSR3;       /*!< RCC system privilege configuration set register 3              Address offset: 0x0FB4 */
       uint32_t RESERVED28;       /*!< Reserved                                                       Address offset: 0x0FB8 */
  volatile uint32_t PUBCFGSR3;        /*!< RCC system public configuration set register 3                 Address offset: 0x0FBC */
       uint32_t RESERVED29;       /*!< Reserved                                                       Address offset: 0x0FC0 */
  volatile uint32_t PRIVCFGSR4;       /*!< RCC privilege configuration set register 4                     Address offset: 0x0FC4 */
       uint32_t RESERVED30;       /*!< Reserved                                                       Address offset: 0x0FC8 */
  volatile uint32_t PUBCFGSR4;        /*!< RCC public configuration set register 4                            Address offset: 0x0FCC */
  volatile uint32_t PUBCFGSR5;        /*!< RCC public configuration set register 5                            Address offset: 0x0FD0 */
       uint32_t RESERVED31[11];   /*!< Reserved                                                       Address offset: 0x0FD4-0x0FFC */
  volatile uint32_t CCR;              /*!< RCC control clear register                                     Address offset: 0x1000 */
       uint32_t RESERVED32;       /*!< Reserved                                                       Address offset: 0x1004 */
  volatile uint32_t STOPCCR;          /*!< RCC Stop mode configuration clear register                     Address offset: 0x1008 */
       uint32_t RESERVED33[127];  /*!< Reserved                                                       Address offset: 0x100C-0x1200 */
  volatile uint32_t MISCRSTCR;        /*!< RCC miscellaneous reset clear register                         Address offset: 0x1208 */
  volatile uint32_t MEMRSTCR;         /*!< RCC memory reset clear register                                Address offset: 0x120C */
  volatile uint32_t AHB1RSTCR;        /*!< RCC AHB1 reset clear register                                  Address offset: 0x1210 */
  volatile uint32_t AHB2RSTCR;        /*!< RCC AHB2 reset clear register                                  Address offset: 0x1214 */
  volatile uint32_t AHB3RSTCR;        /*!< RCC AHB3 reset r clear register                                Address offset: 0x1218 */
  volatile uint32_t AHB4RSTCR;        /*!< RCC AHB4 reset clear register                                  Address offset: 0x121C */
  volatile uint32_t AHB5RSTCR;        /*!< RCC AHB5 reset clear register                                  Address offset: 0x1220 */
  volatile uint32_t APB1RSTCR1;       /*!< RCC APB1 reset clear register 1                                Address offset: 0x1224 */
  volatile uint32_t APB1RSTCR2;       /*!< RCC APB1 reset clear register 2                                Address offset: 0x1228 */
  volatile uint32_t APB2RSTCR;        /*!< RCC APB2 reset clear register                                  Address offset: 0x122C */
       uint32_t RESERVED34;       /*!< Reserved                                                       Address offset: 0x1230 */
  volatile uint32_t APB4RSTCR1;       /*!< RCC APB4 reset clear register 1                                Address offset: 0x1234 */
  volatile uint32_t APB4RSTCR2;       /*!< RCC APB4 reset clear register 2                                Address offset: 0x1238 */
  volatile uint32_t APB5RSTCR;        /*!< RCC APB5 reset clear register                                  Address offset: 0x123C */
  volatile uint32_t DIVENCR;          /*!< RCC divider enable clear register                              Address offset: 0x1240 */
  volatile uint32_t BUSENCR;          /*!< RCC bus enable clear register                                  Address offset: 0x1244 */
  volatile uint32_t MISCENCR;         /*!< RCC miscellaneous enable clear register                        Address offset: 0x1248 */
  volatile uint32_t MEMENCR;          /*!< RCC memory enable clear register                               Address offset: 0x124C */
  volatile uint32_t AHB1ENCR;         /*!< RCC AHB1 enable clear register                                 Address offset: 0x1250 */
  volatile uint32_t AHB2ENCR;         /*!< RCC AHB2 enable clear register                                 Address offset: 0x1254 */
  volatile uint32_t AHB3ENCR;         /*!< RCC AHB3 enable clear register                                 Address offset: 0x1258 */
  volatile uint32_t AHB4ENCR;         /*!< RCC AHB4 enable clear register                                 Address offset: 0x125C */
  volatile uint32_t AHB5ENCR;         /*!< RCC AHB5 enable clear register                                 Address offset: 0x1260 */
  volatile uint32_t APB1ENCR1;        /*!< RCC APB1 enable clear register 1                               Address offset: 0x1264 */
  volatile uint32_t APB1ENCR2;        /*!< RCC APB1 enable clear register 2                               Address offset: 0x1268 */
  volatile uint32_t APB2ENCR;         /*!< RCC APB2 enable clear register                                 Address offset: 0x126C */
  volatile uint32_t APB3ENCR;         /*!< RCC APB3 enable clear register                                 Address offset: 0x1270 */
  volatile uint32_t APB4ENCR1;        /*!< RCC APB4 enable clear register 1                               Address offset: 0x1274 */
  volatile uint32_t APB4ENCR2;        /*!< RCC APB4 enable clear register 2                               Address offset: 0x1278 */
  volatile uint32_t APB5ENCR;         /*!< RCC APB5 enable clear register                                 Address offset: 0x127C */
       uint32_t RESERVED35;       /*!< Reserved                                                       Address offset: 0x1280 */
  volatile uint32_t BUSLPENCR;        /*!< RCC bus sleep enable clear register                            Address offset: 0x1284 */
  volatile uint32_t MISCLPENCR;       /*!< RCC miscellaneous sleep enable clear register                  Address offset: 0x1288 */
  volatile uint32_t MEMLPENCR;        /*!< RCC memory sleep enable clear register                         Address offset: 0x128C */
  volatile uint32_t AHB1LPENCR;       /*!< RCC AHB1 sleep enable clear register                           Address offset: 0x1290 */
  volatile uint32_t AHB2LPENCR;       /*!< RCC AHB2 sleep enable clear register                           Address offset: 0x1294 */
  volatile uint32_t AHB3LPENCR;       /*!< RCC AHB3 sleep enable clear register                           Address offset: 0x1298 */
  volatile uint32_t AHB4LPENCR;       /*!< RCC AHB4 sleep enable clear register                           Address offset: 0x129C */
  volatile uint32_t AHB5LPENCR;       /*!< RCC AHB5 sleep enable clear register                           Address offset: 0x12A0 */
  volatile uint32_t APB1LPENCR1;      /*!< RCC APB1 sleep enable clear register 1                         Address offset: 0x12A4 */
  volatile uint32_t APB1LPENCR2;      /*!< RCC APB1 sleep enable clear register 2                         Address offset: 0x12A8 */
  volatile uint32_t APB2LPENCR;       /*!< RCC APB2 sleep enable clear register                           Address offset: 0x12AC */
  volatile uint32_t APB3LPENCR;       /*!< RCC APB3 sleep enable clear register                           Address offset: 0x12B0 */
  volatile uint32_t APB4LPENCR1;      /*!< RCC APB4 sleep enable clear register 1                         Address offset: 0x12B4 */
  volatile uint32_t APB4LPENCR2;      /*!< RCC APB4 sleep enable clear register 2                         Address offset: 0x12B8 */
  volatile uint32_t APB5LPENCR;       /*!< RCC APB5 sleep enable clear register                           Address offset: 0x12BC */
       uint32_t RESERVED36[305];  /*!< Reserved                                                       Address offset: 0x12C0-0x1780 */
  volatile uint32_t PRIVCFGCR0;       /*!< RCC oscillator privilege configuration clear register 0        Address offset: 0x1784 */
       uint32_t RESERVED37;       /*!< Reserved                                                       Address offset: 0x1788 */
  volatile uint32_t PUBCFGCR0;        /*!< RCC oscillator public configuration clear register 0           Address offset: 0x178C */
       uint32_t RESERVED38;       /*!< Reserved                                                       Address offset: 0x1790 */
  volatile uint32_t PRIVCFGCR1;       /*!< RCC PLL privilege configuration clear register 1               Address offset: 0x1794 */
       uint32_t RESERVED39;       /*!< Reserved                                                       Address offset: 0x1798 */
  volatile uint32_t PUBCFGCR1;        /*!< RCC PLL public configuration clear register 1                  Address offset: 0x179C */
       uint32_t RESERVED40;       /*!< Reserved                                                       Address offset: 0x17A0 */
  volatile uint32_t PRIVCFGCR2;       /*!< RCC divider privilege configuration clear register 2           Address offset: 0x17A4 */
       uint32_t RESERVED41;       /*!< Reserved                                                       Address offset: 0x17A8 */
  volatile uint32_t PUBCFGCR2;        /*!< RCC divider public configuration clear register 2              Address offset: 0x17AC */
       uint32_t RESERVED42;       /*!< Reserved                                                       Address offset: 0x17B0 */
  volatile uint32_t PRIVCFGCR3;       /*!< RCC system privilege configuration clear register 3            Address offset: 0x17B4 */
       uint32_t RESERVED43;       /*!< Reserved                                                       Address offset: 0x17B8 */
  volatile uint32_t PUBCFGCR3;        /*!< RCC system public configuration clear register 3               Address offset: 0x17BC */
       uint32_t RESERVED44;       /*!< Reserved                                                       Address offset: 0x17C0 */
  volatile uint32_t PRIVCFGCR4;       /*!< RCC privilege configuration clear register 4                   Address offset: 0x17C4 */
       uint32_t RESERVED45;       /*!< Reserved                                                       Address offset: 0x17C8 */
  volatile uint32_t PUBCFGCR4;        /*!< RCC public configuration clear register 4                      Address offset: 0x17CC */
  volatile uint32_t PUBCFGCR5;        /*!< RCC public configuration clear register 5                      Address offset: 0x17D0 */
} RCC_TypeDef;

/*
 * @brief  RIFSC Resource Isolation Framework Security Controller (full version) (RIFSC User Spec Rev 1.1)
 */
typedef struct
{
  volatile uint32_t RISC_CR;            /*!< RIFSC RISC slave configuration register x               Address offset: 0x000 */
       uint32_t RESERVED0[3];       /*!< Reserved                                                Address offset: 0x004-0x00C */
  volatile uint32_t RISC_SECCFGRx[6];   /*!< RIFSC RISC slave security configuration register x      Address offset: 0x010-0x24 */
       uint32_t RESERVED1[2];       /*!< Reserved                                                Address offset: 0x028-0x02C */
  volatile uint32_t RISC_PRIVCFGRx[6];  /*!< RIFSC RISFC slave privileged register x                 Address offset: 0x030-0x44 */
       uint32_t RESERVED2[2];       /*!< Reserved                                                Address offset: 0x048-0x04C */
  volatile uint32_t RISC_RCFGLOCKRx[6]; /*!< RIFSC RISC slave resource configuration lock register x Address offset: 0x050 - 0x64 */
       uint32_t RESERVED3[742];     /*!< Reserved                                                Address offset: 0x068-0xBFC */
  volatile uint32_t RIMC_CR;            /*!< RIFSC RIMC master configuration register                Address offset: 0xC00 */
       uint32_t RESERVED4[3];       /*!< Reserved                                                Address offset: 0xC04-0xC0C */
  volatile uint32_t RIMC_ATTRx[13];     /*!< RIFSC RIMC master attribute register x                  Address offset: 0xC10-0xC40 */
       uint32_t RESERVED5[219];     /*!< Reserved                                                Address offset: 0xC40-0xFAC */
  volatile uint32_t PPSRx[6];           /*!< RIFSC peripheral protection status register x           Address offset: 0xFB0-0xFC4 */
       uint32_t RESERVED6[8];       /*!< Reserved                                                Address offset: 0xFC8-0xFE4 */
} RIFSC_TypeDef;

/**
  * @brief RISAF Resource Isolation Slave Unit for Address Space Protection (full version)
  */
typedef struct
{
  volatile uint32_t CFGR;          /*!< RISAF Region X configuration register             */
  volatile uint32_t STARTR;        /*!< RISAF Region X start address register             */
  volatile uint32_t ENDR;          /*!< RISAF Region X end address register               */
  volatile uint32_t CIDCFGR;       /*!< RISAF Region X CID configuration register         */
  volatile uint32_t ACFGR;         /*!< RISAF Region X subregion A configuration register */
  volatile uint32_t ASTARTR;       /*!< RISAF Region X subregion A start address register */
  volatile uint32_t AENDR;         /*!< RISAF Region X subregion A end address register   */
  volatile uint32_t ANESTR;        /*!< RISAF Region X subregion A nested mode register   */
  volatile uint32_t BCFGR;         /*!< RISAF Region X subregion B configuration register */
  volatile uint32_t BSTARTR;       /*!< RISAF Region X subregion B start address register */
  volatile uint32_t BENDR;         /*!< RISAF Region X subregion B end address register   */
  volatile uint32_t BNESTR;        /*!< RISAF Region X subregion B nested mode register   */
       uint32_t RESERVED0[4];  /*!< Reserved                                          */
} RISAF_Region_TypeDef;

/**
  * @brief RISAF Resource Isolation Slave Unit for Address Space Protection (full version) Illegal Access Register (RIF User Spec Rev 1.0.14)
  */
typedef struct
{
  volatile uint32_t IAESR;         /*!< RISAF Illegal access error status register */
  volatile uint32_t IADDR;         /*!< RISAF Illegal address register,            */
} RISAF_Illegal_TypeDef;

/**
  * @brief RISAF Resource Isolation Slave Unit for Address Space Protection (full version) (RIF User Spec Rev 1.0.14)
  */
typedef struct
{
  volatile uint32_t              CR;            /*!< RISAF Configuration register,                            Address offset: 0x000 */
  volatile uint32_t              RESERVED0;     /*!< Reserved,                                                Address offset: 0x004 */
  volatile uint32_t              IASR;          /*!< RISAF Illegal access status register,                    Address offset: 0x008 */
  volatile uint32_t              IACR;          /*!< RISAF Illegal access clear register,                     Address offset: 0x00C */
       uint32_t              RESERVED1[4];  /*!< Reserved,                                                          0x010-0x01C */
       RISAF_Illegal_TypeDef IAR[1];        /*!< RISAF Illegal access error status and address register,            0x020-0x024 */
       uint32_t              RESERVED2[6];  /*!< Reserved,                                                          0x028-0x03C */
       RISAF_Region_TypeDef  REG[15];       /*!< RISAF Region X configuration register,                             0x040-0x3FC */
} RISAF_TypeDef;

/**
  * @brief RNG
  */
typedef struct
{
  volatile uint32_t CR;  /*!< RNG control register, Address offset: 0x00 */
  volatile uint32_t SR;  /*!< RNG status register,  Address offset: 0x04 */
  volatile uint32_t DR;  /*!< RNG data register,    Address offset: 0x08 */
  uint32_t RESERVED;
  volatile uint32_t HTCR;  /*!< RNG health test configuration register, Address offset: 0x10 */
} RNG_TypeDef;

/*
* @brief RTC Specific device feature definitions
*/
#define RTC_BKP_NB         32U
#define RTC_TAMP_NB        7U

/**
 * @brief Real-Time Clock
 */
typedef struct
{
 volatile uint32_t TR;          /*!< RTC time register,                              Address offset: 0x00 */
 volatile uint32_t DR;          /*!< RTC date register,                              Address offset: 0x04 */
 volatile uint32_t SSR;         /*!< RTC sub second register,                        Address offset: 0x08 */
 volatile uint32_t ICSR;        /*!< RTC initialization control and status register, Address offset: 0x0C */
 volatile uint32_t PRER;        /*!< RTC prescaler register,                         Address offset: 0x10 */
 volatile uint32_t WUTR;        /*!< RTC wakeup timer register,                      Address offset: 0x14 */
 volatile uint32_t CR;          /*!< RTC control register,                           Address offset: 0x18 */
 volatile uint32_t PRIVCFGR;    /*!< RTC privilege mode control register,            Address offset: 0x1C */
volatile uint32_t SECCFGR;      /*!< RTC secure mode control register,               Address offset: 0x20 */
 volatile uint32_t WPR;         /*!< RTC write protection register,                  Address offset: 0x24 */
 volatile uint32_t CALR;        /*!< RTC calibration register,                       Address offset: 0x28 */
 volatile uint32_t SHIFTR;      /*!< RTC shift control register,                     Address offset: 0x2C */
 volatile uint32_t TSTR;        /*!< RTC time stamp time register,                   Address offset: 0x30 */
 volatile uint32_t TSDR;        /*!< RTC time stamp date register,                   Address offset: 0x34 */
 volatile uint32_t TSSSR;       /*!< RTC time-stamp sub second register,             Address offset: 0x38 */
      uint32_t RESERVED1;   /*!< Reserved,                                       Address offset: 0x3C */
 volatile uint32_t ALRMAR;      /*!< RTC alarm A register,                           Address offset: 0x40 */
 volatile uint32_t ALRMASSR;    /*!< RTC alarm A sub second register,                Address offset: 0x44 */
 volatile uint32_t ALRMBR;      /*!< RTC alarm B register,                           Address offset: 0x48 */
 volatile uint32_t ALRMBSSR;    /*!< RTC alarm B sub second register,                Address offset: 0x4C */
 volatile uint32_t SR;          /*!< RTC Status register,                            Address offset: 0x50 */
 volatile uint32_t MISR;        /*!< RTC masked interrupt status register,           Address offset: 0x54 */
 volatile uint32_t SMISR;       /*!< RTC secure masked interrupt status register,    Address offset: 0x58 */
 volatile uint32_t SCR;         /*!< RTC status Clear register,                      Address offset: 0x5C */
      uint32_t RESERVED3[4];/*!< Reserved,                                       Address offset: 0x58 */
 volatile uint32_t ALRABINR;    /*!< RTC alarm A binary mode register,               Address offset: 0x70 */
 volatile uint32_t ALRBBINR;    /*!< RTC alarm B binary mode register,               Address offset: 0x74 */
} RTC_TypeDef;

/**
  * @brief SAES Processor
  */
typedef struct
{
  volatile uint32_t CR;             /*!< SAES control register,                      Address offset: 0x000 */
  volatile uint32_t SR;             /*!< SAES status register,                       Address offset: 0x004 */
  volatile uint32_t DINR;           /*!< SAES data input register,                   Address offset: 0x008 */
  volatile uint32_t DOUTR;          /*!< SAES data output register,                  Address offset: 0x00C */
  volatile uint32_t KEYR0;          /*!< SAES key register 0,                        Address offset: 0x010 */
  volatile uint32_t KEYR1;          /*!< SAES key register 1,                        Address offset: 0x014 */
  volatile uint32_t KEYR2;          /*!< SAES key register 2,                        Address offset: 0x018 */
  volatile uint32_t KEYR3;          /*!< SAES key register 3,                        Address offset: 0x01C */
  volatile uint32_t IVR0;           /*!< SAES initialization vector register 0,      Address offset: 0x020 */
  volatile uint32_t IVR1;           /*!< SAES initialization vector register 1,      Address offset: 0x024 */
  volatile uint32_t IVR2;           /*!< SAES initialization vector register 2,      Address offset: 0x028 */
  volatile uint32_t IVR3;           /*!< SAES initialization vector register 3,      Address offset: 0x02C */
  volatile uint32_t KEYR4;          /*!< SAES key register 4,                        Address offset: 0x030 */
  volatile uint32_t KEYR5;          /*!< SAES key register 5,                        Address offset: 0x034 */
  volatile uint32_t KEYR6;          /*!< SAES key register 6,                        Address offset: 0x038 */
  volatile uint32_t KEYR7;          /*!< SAES key register 7,                        Address offset: 0x03C */
       uint32_t RESERVED1[48];  /*!< Reserved,                                   Address offset: 0x040 -- 0x0FC */
  volatile uint32_t DPACFGR;        /*!< SAES DPA configuration register,            Address offset: 0x100 */
       uint32_t RESERVED2[127]; /*!< Reserved,                                   Address offset: 0x104 -- 0x2FC */
  volatile uint32_t IER;            /*!< SAES Interrupt Enable Register,             Address offset: 0x300 */
  volatile uint32_t ISR;            /*!< SAES Interrupt Status Register,             Address offset: 0x304 */
  volatile uint32_t ICR;            /*!< SAES Interrupt Clear Register,              Address offset: 0x308 */
} SAES_TypeDef;

/**
  * @brief Serial Audio Interface
  */
typedef struct
{
  volatile uint32_t GCR;          /*!< SAI global configuration register,        Address offset: 0x00 */
  uint32_t      RESERVED[16]; /*!< Reserved,                         Address offset: 0x04 to 0x40 */
  volatile uint32_t PDMCR;        /*!< SAI PDM control register,                 Address offset: 0x44 */
  volatile uint32_t PDMDLY;       /*!< SAI PDM delay register,                   Address offset: 0x48 */
} SAI_TypeDef;

typedef struct
{
  volatile uint32_t CR1;         /*!< SAI block x configuration register 1,     Address offset: 0x04 */
  volatile uint32_t CR2;         /*!< SAI block x configuration register 2,     Address offset: 0x08 */
  volatile uint32_t FRCR;        /*!< SAI block x frame configuration register, Address offset: 0x0C */
  volatile uint32_t SLOTR;       /*!< SAI block x slot register,                Address offset: 0x10 */
  volatile uint32_t IMR;         /*!< SAI block x interrupt mask register,      Address offset: 0x14 */
  volatile uint32_t SR;          /*!< SAI block x status register,              Address offset: 0x18 */
  volatile uint32_t CLRFR;       /*!< SAI block x clear flag register,          Address offset: 0x1C */
  volatile uint32_t DR;          /*!< SAI block x data register,                Address offset: 0x20 */
} SAI_Block_TypeDef;

/**
  * @brief Secure digital input/output Interface
  */
typedef struct
{
  volatile uint32_t POWER;          /*!< SDMMC power control register,              Address offset: 0x00 */
  volatile uint32_t CLKCR;          /*!< SDMMC clock control register,              Address offset: 0x04 */
  volatile uint32_t ARG;            /*!< SDMMC argument register,                   Address offset: 0x08 */
  volatile uint32_t CMD;            /*!< SDMMC command register,                    Address offset: 0x0C */
  volatile const  uint32_t  RESPCMD;        /*!< SDMMC command response register,           Address offset: 0x10 */
  volatile const  uint32_t  RESP1;          /*!< SDMMC response 1 register,                 Address offset: 0x14 */
  volatile const  uint32_t  RESP2;          /*!< SDMMC response 2 register,                 Address offset: 0x18 */
  volatile const  uint32_t  RESP3;          /*!< SDMMC response 3 register,                 Address offset: 0x1C */
  volatile const  uint32_t  RESP4;          /*!< SDMMC response 4 register,                 Address offset: 0x20 */
  volatile uint32_t DTIMER;         /*!< SDMMC data timer register,                 Address offset: 0x24 */
  volatile uint32_t DLEN;           /*!< SDMMC data length register,                Address offset: 0x28 */
  volatile uint32_t DCTRL;          /*!< SDMMC data control register,               Address offset: 0x2C */
  volatile const  uint32_t  DCOUNT;         /*!< SDMMC data counter register,               Address offset: 0x30 */
  volatile const  uint32_t  STA;            /*!< SDMMC status register,                     Address offset: 0x34 */
  volatile uint32_t ICR;            /*!< SDMMC interrupt clear register,            Address offset: 0x38 */
  volatile uint32_t MASK;           /*!< SDMMC mask register,                       Address offset: 0x3C */
  volatile uint32_t ACKTIME;        /*!< SDMMC Acknowledgement timer register,      Address offset: 0x40 */
  volatile uint32_t FIFOTHR;        /*!< SDMMC data FIFO threshold register,        Address offset: 0x44 */
  uint32_t      RESERVED0[2];   /*!< Reserved, 0x48 - 0x4C                                           */
  volatile uint32_t IDMACTRL;       /*!< SDMMC DMA control register,                Address offset: 0x50 */
  volatile uint32_t IDMABSIZE;      /*!< SDMMC DMA buffer size register,            Address offset: 0x54 */
  volatile uint32_t IDMABASER;      /*!< SDMMC DMA buffer base address register,    Address offset: 0x58 */
  uint32_t      RESERVED1[2];   /*!< Reserved, 0x5C - 0x60                                           */
  volatile uint32_t IDMALAR;        /*!< SDMMC DMA linked list address register,    Address offset: 0x64 */
  volatile uint32_t IDMABAR;        /*!< SDMMC DMA linked list memory base register,Address offset: 0x68 */
  uint32_t      RESERVED2[5];   /*!< Reserved, 0x6C-0x7C                                             */
  volatile uint32_t FIFO;           /*!< SDMMC data FIFO register,                  Address offset: 0x80 */
} SDMMC_TypeDef;

/**
  * @brief SPI
  */
typedef struct
{
  volatile uint32_t CR1;           /*!< SPI/I2S Control register 1,                      Address offset: 0x00 */
  volatile uint32_t CR2;           /*!< SPI Control register 2,                          Address offset: 0x04 */
  volatile uint32_t CFG1;          /*!< SPI Configuration register 1,                    Address offset: 0x08 */
  volatile uint32_t CFG2;          /*!< SPI Configuration register 2,                    Address offset: 0x0C */
  volatile uint32_t IER;           /*!< SPI/I2S Interrupt Enable register,               Address offset: 0x10 */
  volatile uint32_t SR;            /*!< SPI/I2S Status register,                         Address offset: 0x14 */
  volatile uint32_t IFCR;          /*!< SPI/I2S Interrupt/Status flags clear register,   Address offset: 0x18 */
  uint32_t      RESERVED0;     /*!< Reserved, 0x1C                                                        */
  volatile uint32_t TXDR;          /*!< SPI/I2S Transmit data register,                  Address offset: 0x20 */
  uint32_t      RESERVED1[3];  /*!< Reserved, 0x24-0x2C                                                   */
  volatile uint32_t RXDR;          /*!< SPI/I2S Receive data register,                   Address offset: 0x30 */
  uint32_t      RESERVED2[3];  /*!< Reserved, 0x34-0x3C                                                   */
  volatile uint32_t CRCPOLY;       /*!< SPI CRC Polynomial register,                     Address offset: 0x40 */
  volatile uint32_t TXCRC;         /*!< SPI Transmitter CRC register,                    Address offset: 0x44 */
  volatile uint32_t RXCRC;         /*!< SPI Receiver CRC register,                       Address offset: 0x48 */
  volatile uint32_t UDRDR;         /*!< SPI Underrun data register,                      Address offset: 0x4C */
  volatile uint32_t I2SCFGR;       /*!< I2S Configuration register,                      Address offset: 0x50 */
} SPI_TypeDef;


/**
  * @brief UCPD
  */
typedef struct
{
  volatile uint32_t CFG1;        /*!< UCPD configuration register 1,            Address offset: 0x00 */
  volatile uint32_t CFG2;        /*!< UCPD configuration register 2,            Address offset: 0x04 */
  volatile uint32_t RESERVED0;   /*!< UCPD reserved register,                   Address offset: 0x08 */
  volatile uint32_t CR;          /*!< UCPD control register,                    Address offset: 0x0C */
  volatile uint32_t IMR;         /*!< UCPD interrupt mask register,             Address offset: 0x10 */
  volatile uint32_t SR;          /*!< UCPD status register,                     Address offset: 0x14 */
  volatile uint32_t ICR;         /*!< UCPD interrupt flag clear register        Address offset: 0x18 */
  volatile uint32_t TX_ORDSET;   /*!< UCPD Tx ordered set type register,        Address offset: 0x1C */
  volatile uint32_t TX_PAYSZ;    /*!< UCPD Tx payload size register,            Address offset: 0x20 */
  volatile uint32_t TXDR;        /*!< UCPD Tx data register,                    Address offset: 0x24 */
  volatile uint32_t RX_ORDSET;   /*!< UCPD Rx ordered set type register,        Address offset: 0x28 */
  volatile uint32_t RX_PAYSZ;    /*!< UCPD Rx payload size register,            Address offset: 0x2C */
  volatile uint32_t RXDR;        /*!< UCPD Rx data register,                    Address offset: 0x30 */
  volatile uint32_t RX_ORDEXT1;  /*!< UCPD Rx ordered set extension 1 register, Address offset: 0x34 */
  volatile uint32_t RX_ORDEXT2;  /*!< UCPD Rx ordered set extension 2 register, Address offset: 0x38 */
} UCPD_TypeDef;

/**
  * @brief USB_OTG_Core_register
  */
typedef struct
{
  volatile uint32_t GOTGCTL;             /*!< USB_OTG Control and Status Register,       Address offset: 000h */
  volatile uint32_t GOTGINT;             /*!< USB_OTG Interrupt Register,                Address offset: 004h */
  volatile uint32_t GAHBCFG;             /*!< Core AHB Configuration Register,           Address offset: 008h */
  volatile uint32_t GUSBCFG;             /*!< Core USB Configuration Register,           Address offset: 00Ch */
  volatile uint32_t GRSTCTL;             /*!< Core Reset Register,                       Address offset: 010h */
  volatile uint32_t GINTSTS;             /*!< Core Interrupt Register,                   Address offset: 014h */
  volatile uint32_t GINTMSK;             /*!< Core Interrupt Mask Register,              Address offset: 018h */
  volatile uint32_t GRXSTSR;             /*!< Receive Sts Q Read Register,               Address offset: 01Ch */
  volatile uint32_t GRXSTSP;             /*!< Receive Sts Q Read & POP Register,         Address offset: 020h */
  volatile uint32_t GRXFSIZ;             /*!< Receive FIFO Size Register,                Address offset: 024h */
  volatile uint32_t DIEPTXF0_HNPTXFSIZ;  /*!< EP0 / Non Periodic Tx FIFO Size Register,  Address offset: 028h */
  volatile uint32_t HNPTXSTS;            /*!< Non Periodic Tx FIFO/Queue Sts reg,        Address offset: 02Ch */
  volatile uint32_t Reserved30[2];       /*!< Reserved,                                  Address offset: 030h */
  volatile uint32_t GCCFG;               /*!< General Purpose IO Register,               Address offset: 038h */
  volatile uint32_t CID;                 /*!< User ID Register,                          Address offset: 03Ch */
  volatile uint32_t GSNPSID;             /*!< USB_OTG core ID,                           Address offset: 040h */
  volatile uint32_t GHWCFG1;             /*!< User HW config1,                           Address offset: 044h */
  volatile uint32_t GHWCFG2;             /*!< User HW config2,                           Address offset: 048h */
  volatile uint32_t GHWCFG3;             /*!< User HW config3,                           Address offset: 04Ch */
  volatile uint32_t Reserved6;           /*!< Reserved,                                  Address offset: 050h */
  volatile uint32_t GLPMCFG;             /*!< LPM Register,                              Address offset: 054h */
  volatile uint32_t GPWRDN;              /*!< Power Down Register,                       Address offset: 058h */
  volatile uint32_t GDFIFOCFG;           /*!< DFIFO Software Config Register,            Address offset: 05Ch */
  volatile uint32_t GADPCTL;             /*!< ADP Timer, Control and Status Register,    Address offset: 60Ch */
  volatile uint32_t Reserved43[39];      /*!< Reserved,                                  Address offset: 058h */
  volatile uint32_t HPTXFSIZ;            /*!< Host Periodic Tx FIFO Size Reg,            Address offset: 100h */
  volatile uint32_t DIEPTXF[0x0F];       /*!< dev Periodic Transmit FIFO                 Address offset: 104h */
} USB_OTG_GlobalTypeDef;

typedef struct
{
  volatile uint32_t USBPHYC_CR;          /*!< USB_OTG Control and Status Register,       Address offset: 000h */
  volatile uint32_t USBPHYC_TRIM1CR;     /*!< USB_OTG Interrupt Register,                Address offset: 004h */
  volatile uint32_t USBPHYC_TRIM2CR;     /*!< Core AHB Configuration Register,           Address offset: 008h */
} USB_PHY_GlobalTypeDef;

/**
  * @brief USB_OTG_device_Registers
  */
typedef struct
{
  volatile uint32_t DCFG;                /*!< dev Configuration Register,   Address offset: 800h */
  volatile uint32_t DCTL;                /*!< dev Control Register,         Address offset: 804h */
  volatile uint32_t DSTS;                /*!< dev Status Register (RO),     Address offset: 808h */
  volatile uint32_t Reserved0C;          /*!< Reserved,                     Address offset: 80Ch */
  volatile uint32_t DIEPMSK;             /*!< dev IN Endpoint Mask,         Address offset: 810h */
  volatile uint32_t DOEPMSK;             /*!< dev OUT Endpoint Mask,        Address offset: 814h */
  volatile uint32_t DAINT;               /*!< dev All Endpoints Itr Reg,    Address offset: 818h */
  volatile uint32_t DAINTMSK;            /*!< dev All Endpoints Itr Mask,   Address offset: 81Ch */
  volatile uint32_t Reserved20;          /*!< Reserved,                     Address offset: 820h */
  volatile uint32_t Reserved9;           /*!< Reserved,                     Address offset: 824h */
  volatile uint32_t DVBUSDIS;            /*!< dev VBUS discharge Register,  Address offset: 828h */
  volatile uint32_t DVBUSPULSE;          /*!< dev VBUS Pulse Register,      Address offset: 82Ch */
  volatile uint32_t DTHRCTL;             /*!< dev threshold,                Address offset: 830h */
  volatile uint32_t DIEPEMPMSK;          /*!< dev empty msk,                Address offset: 834h */
  volatile uint32_t DEACHINT;            /*!< dedicated EP interrupt,       Address offset: 838h */
  volatile uint32_t DEACHMSK;            /*!< dedicated EP msk,             Address offset: 83Ch */
  volatile uint32_t Reserved40;          /*!< dedicated EP mask,            Address offset: 840h */
  volatile uint32_t DINEP1MSK;           /*!< dedicated EP mask,            Address offset: 844h */
  volatile uint32_t Reserved44[15];      /*!< Reserved,                     Address offset: 844-87Ch */
  volatile uint32_t DOUTEP1MSK;          /*!< dedicated EP msk,             Address offset: 884h */
} USB_OTG_DeviceTypeDef;

/**
  * @brief USB_OTG_IN_Endpoint-Specific_Register
  */
typedef struct
{
  volatile uint32_t DIEPCTL;             /*!< dev IN Endpoint Control Register,          Address offset: 900h + (ep_num * 20h) + 00h */
  volatile uint32_t Reserved04;          /*!< Reserved,                                  Address offset: 900h + (ep_num * 20h) + 04h */
  volatile uint32_t DIEPINT;             /*!< dev IN Endpoint Itr Register,              Address offset: 900h + (ep_num * 20h) + 08h */
  volatile uint32_t Reserved0C;          /*!< Reserved,                                  Address offset: 900h + (ep_num * 20h) + 0Ch */
  volatile uint32_t DIEPTSIZ;            /*!< IN Endpoint Txfer Size Register,           Address offset: 900h + (ep_num * 20h) + 10h */
  volatile uint32_t DIEPDMA;             /*!< IN Endpoint DMA Address Register,          Address offset: 900h + (ep_num * 20h) + 14h */
  volatile uint32_t DTXFSTS;             /*!< IN Endpoint Tx FIFO Status Register,       Address offset: 900h + (ep_num * 20h) + 18h */
  volatile uint32_t Reserved18;          /*!< Reserved,                                  Address offset: 900h + (ep_num * 20h) + 1Ch */
} USB_OTG_INEndpointTypeDef;

/**
  * @brief USB_OTG_OUT_Endpoint-Specific_Registers
  */
typedef struct
{
  volatile uint32_t DOEPCTL;             /*!< dev OUT Endpoint Control Register,         Address offset: B00h + (ep_num * 20h) + 00h */
  volatile uint32_t Reserved04;          /*!< Reserved,                                  Address offset: B00h + (ep_num * 20h) + 04h */
  volatile uint32_t DOEPINT;             /*!< dev OUT Endpoint Itr Register,             Address offset: B00h + (ep_num * 20h) + 08h */
  volatile uint32_t Reserved0C;          /*!< Reserved,                                  Address offset: B00h + (ep_num * 20h) + 0Ch */
  volatile uint32_t DOEPTSIZ;            /*!< dev OUT Endpoint Txfer Size Register,      Address offset: B00h + (ep_num * 20h) + 10h */
  volatile uint32_t DOEPDMA;             /*!< dev OUT Endpoint DMA Address Register,     Address offset: B00h + (ep_num * 20h) + 14h */
  volatile uint32_t Reserved18[2];       /*!< Reserved,                                  Address offset: B00h + (ep_num * 20h) + 18h */
} USB_OTG_OUTEndpointTypeDef;

/**
  * @brief USB_OTG_Host_Mode_Register_Structures
  */
typedef struct
{
  volatile uint32_t HCFG;                 /*!< Host Configuration Register,              Address offset: 400h */
  volatile uint32_t HFIR;                 /*!< Host Frame Interval Register,             Address offset: 404h */
  volatile uint32_t HFNUM;                /*!< Host Frame Nbr/Frame Remaining,           Address offset: 408h */
  volatile uint32_t Reserved40C;          /*!< Reserved,                                 Address offset: 40Ch */
  volatile uint32_t HPTXSTS;              /*!< Host Periodic Tx FIFO/ Queue Status,      Address offset: 410h */
  volatile uint32_t HAINT;                /*!< Host All Channels Interrupt Register,     Address offset: 414h */
  volatile uint32_t HAINTMSK;             /*!< Host All Channels Interrupt Mask,         Address offset: 418h */
} USB_OTG_HostTypeDef;

/**
  * @brief USB_OTG_Host_Channel_Specific_Registers
  */
typedef struct
{
  volatile uint32_t HCCHAR;               /*!< Host Channel Characteristics Register,    Address offset: 500h */
  volatile uint32_t HCSPLT;               /*!< Host Channel Split Control Register,      Address offset: 504h */
  volatile uint32_t HCINT;                /*!< Host Channel Interrupt Register,          Address offset: 508h */
  volatile uint32_t HCINTMSK;             /*!< Host Channel Interrupt Mask Register,     Address offset: 50Ch */
  volatile uint32_t HCTSIZ;               /*!< Host Channel Transfer Size Register,      Address offset: 510h */
  volatile uint32_t HCDMA;                /*!< Host Channel DMA Address Register,        Address offset: 514h */
  uint32_t Reserved[2];               /*!< Reserved,                                 Address offset: 518h */
} USB_OTG_HostChannelTypeDef;

typedef struct
{
  volatile uint32_t USBPHYC_CR;           /*!< USB HS PHY Control Register,              Address offset: 000h */
  volatile uint32_t USBPHYC_TRIM1CR;      /*!< USB HS PHY Trimming_1 Register,           Address offset: 004h */
  volatile uint32_t USBPHYC_TRIM2CR;      /*!< USB HS PHY Trimming_2 Register,           Address offset: 008h */
} USB_HS_PHYC_GlobalTypeDef;

/**
  * @brief SPDIF-RX Interface
  */
typedef struct
{
  volatile uint32_t CR;          /*!< Control register,                   Address offset: 0x00 */
  volatile uint32_t IMR;         /*!< Interrupt mask register,            Address offset: 0x04 */
  volatile uint32_t SR;          /*!< Status register,                    Address offset: 0x08 */
  volatile uint32_t IFCR;        /*!< Interrupt Flag Clear register,      Address offset: 0x0C */
  volatile uint32_t DR;          /*!< Data input register,                Address offset: 0x10 */
  volatile uint32_t CSR;         /*!< Channel Status register,            Address offset: 0x14 */
  volatile uint32_t DIR;         /*!< Debug Information register,         Address offset: 0x18 */
} SPDIFRX_TypeDef;


/**
  * @brief System configuration controller
  */
typedef struct
{
  volatile uint32_t BOOTCR;         /*!< SYSCFG boot pin control register,                                            Address offset: 0x00 */
  volatile uint32_t CM55CR;         /*!< SYSCFG Cortex-M55 control register,                                          Address offset: 0x04 */
  volatile uint32_t CM55TCMCR;      /*!< SYSCFG Cortex-M55 TCM control register,                                      Address offset: 0x08 */
  volatile uint32_t CM55RWMCR;      /*!< SYSCFG Cortex-M55 memory RW margin register,                                 Address offset: 0x0C */
  volatile uint32_t INITSVTORCR;    /*!< SYSCFG Cortex-M55 SVTOR control register,                                    Address offset: 0x10 */
  volatile uint32_t INITNSVTORCR;   /*!< Cortex-M55 NSVTOR control register,                                          Address offset: 0x14 */
  volatile uint32_t CM55RSTCR;      /*!< SYSCFG Cortex-M55 reset type control register,                               Address offset: 0x18 */
  volatile uint32_t CM55PAHBWPR;    /*!< SYSCFG Cortex-M55 P-AHB write posting control register,                      Address offset: 0x1C */
  volatile uint32_t VENCRAMCR;      /*!< SYSCFG VENCRAM control register,                                             Address offset: 0x20 */
  volatile uint32_t POTTAMPRSTCR;   /*!< SYSCFG potential tamper reset register,                                      Address offset: 0x24 */
  volatile uint32_t NPUNICQOSCR;    /*!< SYSCFG NPUNIC QoS control register,                                          Address offset: 0x28 */
  uint32_t      RESERVED1[2];   /*!< Reserved,                                                                    Address offset: 0x2C-0x30 */
  volatile uint32_t ICNEWRCR;       /*!< SYSCFG AHB-AXI bridge early write response,                                  Address offset: 0x34 */
  volatile uint32_t ICNCGCR;        /*!< SYSCFG ICN clock gating control register,                                    Address offset: 0x38 */
  uint32_t      RESERVED2[2];   /*!< Reserved,                                                                    Address offset: 0x3C-0x40 */
  volatile uint32_t VDDIO4CCCR;     /*!< SYSCFG VDDIO4 compensation cell control register,                            Address offset: 0x44 */
  volatile uint32_t VDDIO4CCSR;     /*!< SYSCFG VDDIO4 compensation cell status register,                             Address offset: 0x48 */
  volatile uint32_t VDDIO5CCCR;     /*!< SYSCFG VDDIO5 compensation cell control register,                            Address offset: 0x4C */
  volatile uint32_t VDDIO5CCSR;     /*!< SYSCFG VDDIO5 compensation cell status register,                             Address offset: 0x50 */
  volatile uint32_t VDDIO2CCCR;     /*!< SYSCFG VDDIO2 compensation cell control register,                            Address offset: 0x54 */
  volatile uint32_t VDDIO2CCSR;     /*!< SYSCFG VDDIO2 compensation cell status register,                             Address offset: 0x58 */
  volatile uint32_t VDDIO3CCCR;     /*!< SYSCFG VDDIO3 compensation cell control register,                            Address offset: 0x5C */
  volatile uint32_t VDDIO3CCSR;     /*!< SYSCFG VDDIO3 compensation cell status register,                             Address offset: 0x60 */
  volatile uint32_t VDDCCCR;        /*!< SYSCFG VDD compensation cell control register,                               Address offset: 0x64 */
  volatile uint32_t VDDCCSR;        /*!< SYSCFG VDD compensation cell status register,                                Address offset: 0x68 */
  volatile uint32_t CBR;            /*!< SYSCFG control timer break register,                                         Address offset: 0x6C */
  volatile uint32_t SEC_AIDCR;      /*!< SYSCFG DMA CID secure control register,                                      Address offset: 0x70 */
  volatile uint32_t FMC_RETIMECR;   /*!< SYSCFG FMC retiming logic control register,                                  Address offset: 0x74 */
  volatile uint32_t NPU_ICNCR;      /*!< SYSCFG NPU RAM interleaving control register,                                Address offset: 0x78 */
  uint32_t      RESERVED3[33];  /*!< Reserved,                                                                    Address offset: 0x7C-0xFC */
  volatile uint32_t BOOTSR;         /*!< SYSCFG boot pin status register,                                             Address offset: 0x100 */
  volatile uint32_t AHBWP_ERROR_SR; /*!< SYSCFG AHB write posting address error register,                             Address offset: 0x104 */
  uint32_t      RESERVED4[446]; /*!< Reserved,                                                                    Address offset: 0x108-0x3FC */
  volatile uint32_t SECPRIV_AIDCR;  /*!< SYSCFG DMA CID non-secure control register,                                  Address offset: 0x800 */
  uint32_t      RESERVED5[507]; /*!< Reserved,                                                                    Address offset: 0x804-0xFEC */
  volatile uint32_t DEVICEID;       /*!< SYSCFG Device ID,                                                            Address offset: 0xFF0 */
} SYSCFG_TypeDef;

/**
 * @brief Tamper and backup registers
 */
typedef struct
{
 volatile uint32_t CR1;           /*!< TAMP configuration register 1,                    Address offset: 0x00 */
 volatile uint32_t CR2;           /*!< TAMP configuration register 2,                    Address offset: 0x04 */
 volatile uint32_t CR3;           /*!< TAMP configuration register 3,                    Address offset: 0x08 */
 volatile uint32_t FLTCR;         /*!< TAMP filter control register,                     Address offset: 0x0C */
 volatile uint32_t ATCR1;         /*!< TAMP filter control register 1                    Address offset: 0x10 */
 volatile uint32_t ATSEEDR;       /*!< TAMP active tamper seed register,                 Address offset: 0x14 */
 volatile uint32_t ATOR;          /*!< TAMP active tamper output register,               Address offset: 0x18 */
 volatile uint32_t ATCR2;         /*!< TAMP filter control register 2,                   Address offset: 0x1C */
 volatile uint32_t SECCFGR;       /*!< TAMP secure mode control register,                Address offset: 0x20 */
 volatile uint32_t PRIVCFGR;      /*!< TAMP privilege mode control register,             Address offset: 0x24 */
      uint32_t RESERVED2;     /*!< Reserved,                                         Address offset: 0x28 */
 volatile uint32_t IER;           /*!< TAMP interrupt enable register,                   Address offset: 0x2C */
 volatile uint32_t SR;            /*!< TAMP status register,                             Address offset: 0x30 */
 volatile uint32_t MISR;          /*!< TAMP masked interrupt status register,            Address offset: 0x34 */
 volatile uint32_t SMISR;         /*!< TAMP secure masked interrupt status register,     Address offset: 0x38 */
 volatile uint32_t SCR;           /*!< TAMP status clear register,                       Address offset: 0x3C */
 volatile uint32_t COUNT1R;       /*!< TAMP monotonic counter register,                  Address offset: 0x40 */
      uint32_t RESERVED4[3];  /*!< Reserved,                                         Address offset: 0x43 -- 0x4C */
 volatile uint32_t OR;            /*!< TAMP option register,                             Address offset: 0x50 */
 volatile uint32_t RPCFGR;        /*!< TAMP resources protection configuration register, Address offset: 0x54 */
      uint32_t RESERVED5[42]; /*!< Reserved,                                         Address offset: 0x58 -- 0xFC */
 volatile uint32_t BKP0R;         /*!< TAMP backup register 0,                           Address offset: 0x100 */
 volatile uint32_t BKP1R;         /*!< TAMP backup register 1,                           Address offset: 0x104 */
 volatile uint32_t BKP2R;         /*!< TAMP backup register 2,                           Address offset: 0x108 */
 volatile uint32_t BKP3R;         /*!< TAMP backup register 3,                           Address offset: 0x10C */
 volatile uint32_t BKP4R;         /*!< TAMP backup register 4,                           Address offset: 0x110 */
 volatile uint32_t BKP5R;         /*!< TAMP backup register 5,                           Address offset: 0x114 */
 volatile uint32_t BKP6R;         /*!< TAMP backup register 6,                           Address offset: 0x118 */
 volatile uint32_t BKP7R;         /*!< TAMP backup register 7,                           Address offset: 0x11C */
 volatile uint32_t BKP8R;         /*!< TAMP backup register 8,                           Address offset: 0x120 */
 volatile uint32_t BKP9R;         /*!< TAMP backup register 9,                           Address offset: 0x124 */
 volatile uint32_t BKP10R;        /*!< TAMP backup register 10,                          Address offset: 0x128 */
 volatile uint32_t BKP11R;        /*!< TAMP backup register 11,                          Address offset: 0x12C */
 volatile uint32_t BKP12R;        /*!< TAMP backup register 12,                          Address offset: 0x130 */
 volatile uint32_t BKP13R;        /*!< TAMP backup register 13,                          Address offset: 0x134 */
 volatile uint32_t BKP14R;        /*!< TAMP backup register 14,                          Address offset: 0x138 */
 volatile uint32_t BKP15R;        /*!< TAMP backup register 15,                          Address offset: 0x13C */
 volatile uint32_t BKP16R;        /*!< TAMP backup register 16,                          Address offset: 0x140 */
 volatile uint32_t BKP17R;        /*!< TAMP backup register 17,                          Address offset: 0x144 */
 volatile uint32_t BKP18R;        /*!< TAMP backup register 18,                          Address offset: 0x148 */
 volatile uint32_t BKP19R;        /*!< TAMP backup register 19,                          Address offset: 0x14C */
 volatile uint32_t BKP20R;        /*!< TAMP backup register 20,                          Address offset: 0x150 */
 volatile uint32_t BKP21R;        /*!< TAMP backup register 21,                          Address offset: 0x154 */
 volatile uint32_t BKP22R;        /*!< TAMP backup register 22,                          Address offset: 0x158 */
 volatile uint32_t BKP23R;        /*!< TAMP backup register 23,                          Address offset: 0x15C */
 volatile uint32_t BKP24R;        /*!< TAMP backup register 24,                          Address offset: 0x160 */
 volatile uint32_t BKP25R;        /*!< TAMP backup register 25,                          Address offset: 0x164 */
 volatile uint32_t BKP26R;        /*!< TAMP backup register 26,                          Address offset: 0x168 */
 volatile uint32_t BKP27R;        /*!< TAMP backup register 27,                          Address offset: 0x16C */
 volatile uint32_t BKP28R;        /*!< TAMP backup register 28,                          Address offset: 0x170 */
 volatile uint32_t BKP29R;        /*!< TAMP backup register 29,                          Address offset: 0x174 */
 volatile uint32_t BKP30R;        /*!< TAMP backup register 30,                          Address offset: 0x178 */
 volatile uint32_t BKP31R;        /*!< TAMP backup register 31,                          Address offset: 0x17C */
} TAMP_TypeDef;

/**
  * @brief TIM
  */
typedef struct
{
  volatile uint32_t CR1;            /*!< TIM control register 1,                   Address offset:  0x00 */
  volatile uint32_t CR2;            /*!< TIM control register 2,                   Address offset:  0x04 */
  volatile uint32_t SMCR;           /*!< TIM slave mode control register,          Address offset:  0x08 */
  volatile uint32_t DIER;           /*!< TIM DMA/interrupt enable register,        Address offset:  0x0C */
  volatile uint32_t SR;             /*!< TIM status register,                      Address offset:  0x10 */
  volatile uint32_t EGR;            /*!< TIM event generation register,            Address offset:  0x14 */
  volatile uint32_t CCMR1;          /*!< TIM capture/compare mode register 1,      Address offset:  0x18 */
  volatile uint32_t CCMR2;          /*!< TIM capture/compare mode register 2,      Address offset:  0x1C */
  volatile uint32_t CCER;           /*!< TIM capture/compare enable register,      Address offset:  0x20 */
  volatile uint32_t CNT;            /*!< TIM counter register,                     Address offset:  0x24 */
  volatile uint32_t PSC;            /*!< TIM prescaler,                            Address offset:  0x28 */
  volatile uint32_t ARR;            /*!< TIM auto-reload register,                 Address offset:  0x2C */
  volatile uint32_t RCR;            /*!< TIM repetition counter register,          Address offset:  0x30 */
  volatile uint32_t CCR1;           /*!< TIM capture/compare register 1,           Address offset:  0x34 */
  volatile uint32_t CCR2;           /*!< TIM capture/compare register 2,           Address offset:  0x38 */
  volatile uint32_t CCR3;           /*!< TIM capture/compare register 3,           Address offset:  0x3C */
  volatile uint32_t CCR4;           /*!< TIM capture/compare register 4,           Address offset:  0x40 */
  volatile uint32_t BDTR;           /*!< TIM break and dead-time register,         Address offset:  0x44 */
  volatile uint32_t CCR5;           /*!< TIM capture/compare register 5,           Address offset:  0x48 */
  volatile uint32_t CCR6;           /*!< TIM capture/compare register 6,           Address offset:  0x4C */
  volatile uint32_t CCMR3;          /*!< TIM capture/compare mode register 3,      Address offset:  0x50 */
  volatile uint32_t DTR2;           /*!< TIM deadtime register 2,                  Address offset:  0x54 */
  volatile uint32_t ECR;            /*!< TIM encoder control register,             Address offset:  0x58 */
  volatile uint32_t TISEL;          /*!< TIM Input Selection register,             Address offset:  0x5C */
  volatile uint32_t AF1;            /*!< TIM alternate function option register 1, Address offset:  0x60 */
  volatile uint32_t AF2;            /*!< TIM alternate function option register 2, Address offset:  0x64 */
       uint32_t RESERVED1[221]; /*!< Reserved,                                            0x6C-0x3D8 */
  volatile uint32_t DCR;            /*!< TIM DMA control register,                 Address offset: 0x3DC */
  volatile uint32_t DMAR;           /*!< TIM DMA address for full transfer,        Address offset: 0x3E0 */
} TIM_TypeDef;


/**
  * @brief Universal Synchronous Asynchronous Receiver Transmitter
  */
typedef struct
{
  volatile uint32_t CR1;         /*!< USART Control register 1,                 Address offset: 0x00 */
  volatile uint32_t CR2;         /*!< USART Control register 2,                 Address offset: 0x04 */
  volatile uint32_t CR3;         /*!< USART Control register 3,                 Address offset: 0x08 */
  volatile uint32_t BRR;         /*!< USART Baud rate register,                 Address offset: 0x0C */
  volatile uint32_t GTPR;        /*!< USART Guard time and prescaler register,  Address offset: 0x10 */
  volatile uint32_t RTOR;        /*!< USART Receiver Time Out register,         Address offset: 0x14 */
  volatile uint32_t RQR;         /*!< USART Request register,                   Address offset: 0x18 */
  volatile uint32_t ISR;         /*!< USART Interrupt and status register,      Address offset: 0x1C */
  volatile uint32_t ICR;         /*!< USART Interrupt flag Clear register,      Address offset: 0x20 */
  volatile uint32_t RDR;         /*!< USART Receive Data register,              Address offset: 0x24 */
  volatile uint32_t TDR;         /*!< USART Transmit Data register,             Address offset: 0x28 */
  volatile uint32_t PRESC;       /*!< USART Prescaler register,                 Address offset: 0x2C */
} USART_TypeDef;


/**
  * @brief VREFBUF
  */
typedef struct
{
  volatile uint32_t CSR;         /*!< VREFBUF control and status register,         Address offset: 0x00 */
  volatile uint32_t CCR;         /*!< VREFBUF calibration and control register,    Address offset: 0x04 */
} VREFBUF_TypeDef;


/**
  * @brief Window Watchdog
  */
typedef struct
{
  volatile uint32_t CR;          /*!< WWDG Control register,              Address offset: 0x00 */
  volatile uint32_t CFR;         /*!< WWDG Configuration register,        Address offset: 0x04 */
  volatile uint32_t SR;          /*!< WWDG Status register,               Address offset: 0x08 */
} WWDG_TypeDef;

/**
  * @brief Extended-SPI Interface
  */
typedef struct
{
  volatile uint32_t CR;             /*!< XSPI Control Register,                                Address offset: 0x000         */
       uint32_t RESERVED1;      /*!< Reserved,                                             Address offset: 0x004         */
  volatile uint32_t DCR1;           /*!< XSPI Device Configuration Register 1,                 Address offset: 0x008         */
  volatile uint32_t DCR2;           /*!< XSPI Device Configuration Register 2,                 Address offset: 0x00C         */
  volatile uint32_t DCR3;           /*!< XSPI Device Configuration Register 3,                 Address offset: 0x010         */
  volatile uint32_t DCR4;           /*!< XSPI Device Configuration Register 4,                 Address offset: 0x014         */
       uint32_t RESERVED2[2];   /*!< Reserved,                                             Address offset: 0x018 - 0x01C */
  volatile uint32_t SR;             /*!< XSPI Status Register,                                 Address offset: 0x020         */
  volatile uint32_t FCR;            /*!< XSPI Flag Clear Register,                             Address offset: 0x024         */
       uint32_t RESERVED3[6];   /*!< Reserved,                                             Address offset: 0x028 - 0x03C */
  volatile uint32_t DLR;            /*!< XSPI Data Length Register,                            Address offset: 0x040         */
       uint32_t RESERVED4;      /*!< Reserved,                                             Address offset: 0x044         */
  volatile uint32_t AR;             /*!< XSPI Address Register,                                Address offset: 0x048         */
       uint32_t RESERVED5;      /*!< Reserved,                                             Address offset: 0x04C         */
  volatile uint32_t DR;             /*!< XSPI Data Register,                                   Address offset: 0x050         */
       uint32_t RESERVED6[11];  /*!< Reserved,                                             Address offset: 0x054 - 0x07C */
  volatile uint32_t PSMKR;          /*!< XSPI Polling Status Mask Register,                    Address offset: 0x080         */
       uint32_t RESERVED7;      /*!< Reserved,                                             Address offset: 0x084         */
  volatile uint32_t PSMAR;          /*!< XSPI Polling Status Match Register,                   Address offset: 0x088         */
       uint32_t RESERVED8;      /*!< Reserved,                                             Address offset: 0x08C         */
  volatile uint32_t PIR;            /*!< XSPI Polling Interval Register,                       Address offset: 0x090         */
       uint32_t RESERVED9[27];  /*!< Reserved,                                             Address offset: 0x094 - 0x0FC */
  volatile uint32_t CCR;            /*!< XSPI Communication Configuration Register,            Address offset: 0x100         */
       uint32_t RESERVED10;     /*!< Reserved,                                             Address offset: 0x104         */
  volatile uint32_t TCR;            /*!< XSPI Timing Configuration Register,                   Address offset: 0x108         */
       uint32_t RESERVED11;     /*!< Reserved,                                             Address offset: 0x10C         */
  volatile uint32_t IR;             /*!< XSPI Instruction Register,                            Address offset: 0x110         */
       uint32_t RESERVED12[3];  /*!< Reserved,                                             Address offset: 0x114 - 0x11C */
  volatile uint32_t ABR;            /*!< XSPI Alternate Bytes Register,                        Address offset: 0x120         */
       uint32_t RESERVED13[3];  /*!< Reserved,                                             Address offset: 0x124 - 0x12C */
  volatile uint32_t LPTR;           /*!< XSPI Low-Power Timeout Register,                      Address offset: 0x130         */
       uint32_t RESERVED14[3];  /*!< Reserved,                                             Address offset: 0x134 - 0x13C */
  volatile uint32_t WPCCR;          /*!< XSPI Wrap Communication Configuration Register,       Address offset: 0x140         */
       uint32_t RESERVED15;     /*!< Reserved,                                             Address offset: 0x144         */
  volatile uint32_t WPTCR;          /*!< XSPI Wrap Timing Configuration Register,              Address offset: 0x148         */
       uint32_t RESERVED16;     /*!< Reserved,                                             Address offset: 0x14C         */
  volatile uint32_t WPIR;           /*!< XSPI Wrap Instruction Register,                       Address offset: 0x150         */
       uint32_t RESERVED17[3];  /*!< Reserved,                                             Address offset: 0x154 - 0x15C */
  volatile uint32_t WPABR;          /*!< XSPI Wrap Alternate Bytes Register,                   Address offset: 0x160         */
       uint32_t RESERVED18[7];  /*!< Reserved,                                             Address offset: 0x164 - 0x17C */
  volatile uint32_t WCCR;           /*!< XSPI Write Communication Configuration Register,      Address offset: 0x180         */
       uint32_t RESERVED19;     /*!< Reserved,                                             Address offset: 0x184         */
  volatile uint32_t WTCR;           /*!< XSPI Write Timing Configuration Register,             Address offset: 0x188         */
       uint32_t RESERVED20;     /*!< Reserved,                                             Address offset: 0x18C         */
  volatile uint32_t WIR;            /*!< XSPI Write Instruction Register,                      Address offset: 0x190         */
       uint32_t RESERVED21[3];  /*!< Reserved,                                             Address offset: 0x194 - 0x19C */
  volatile uint32_t WABR;           /*!< XSPI Write Alternate Bytes Register,                  Address offset: 0x1A0         */
       uint32_t RESERVED22[23]; /*!< Reserved,                                             Address offset: 0x1A4 - 0x1FC */
  volatile uint32_t HLCR;           /*!< XSPI HyperBus Latency Configuration Register,         Address offset: 0x200         */
       uint32_t RESERVED23[3];  /*!< Reserved,                                             Address offset: 0x204 - 0x20C */
  volatile uint32_t CALFCR;         /*!< XSPI Full-Cycle Calibration Configuration Register,   Address offset: 0x210         */
       uint32_t RESERVED24;     /*!< Reserved,                                             Address offset: 0x214         */
  volatile uint32_t CALMR;          /*!< XSPI DLL Master Calibration Configuration Register,   Address offset: 0x218         */
       uint32_t RESERVED25;     /*!< Reserved,                                             Address offset: 0x21C         */
  volatile uint32_t CALSOR;         /*!< XSPI Slave Output Calibration Configuration Register, Address offset: 0x220         */
       uint32_t RESERVED26;     /*!< Reserved,                                             Address offset: 0x224         */
  volatile uint32_t CALSIR;         /*!< XSPI Slave Input Calibration Configuration Register,  Address offset: 0x228         */
} XSPI_TypeDef;

/**
  * @brief XSPI IO Manager
  */
typedef struct
{
  volatile uint32_t CR;             /*!< XSPI IO Manager Control Register,                     Address offset: 0x00        */
} XSPIM_TypeDef;

/** @} */ /* End of group STM32N6xx_peripherals */

/* =========================================================================================================================== */
/* ================                          Device Specific Peripheral Address Map                           ================ */
/* =========================================================================================================================== */
/** @addtogroup STM32N6xx_Peripheral_peripheralAddr
  * @{
  */

/* Internal RAMs sizes */
#define SRAM1_AXI_SIZE                  0x100000UL   /*!< SRAM1_AXI = 1024 Kbytes */
#define SRAM2_AXI_SIZE                  0x100000UL   /*!< SRAM2_AXI = 1024 Kbytes */
#define FLEXRAM_SIZE                     0x64000UL   /*!< FLEXRAM <= 400 Kbytes   */
#define SRAM3_AXI_SIZE                   0x70000UL   /*!< SRAM3_AXI = 448 Kbytes  */
#define SRAM4_AXI_SIZE                   0x70000UL   /*!< SRAM4_AXI = 448 Kbytes  */
#define SRAM5_AXI_SIZE                   0x70000UL   /*!< SRAM5_AXI = 448 Kbytes  */
#define SRAM6_AXI_SIZE                   0x70000UL   /*!< SRAM6_AXI = 448 Kbytes  */
#define SRAM1_AHB_SIZE                    0x4000UL   /*!< SRAM1_AHB = 16 Kbytes   */
#define SRAM2_AHB_SIZE                    0x4000UL   /*!< SRAM2_AHB = 16 Kbytes   */
#define VENC_RAM_SIZE                    0x20000UL   /*!< VENC RAM  = 128 Kbytes  */
#define CACHEAXI_RAM_SIZE                0x40000UL   /*!< CACHEAXI RAM = 256 Kbytes */
#define BKPSRAM_SIZE                      0x2000UL   /*!< BKPSRAM  = 8 Kbytes     */


#define FMC_BASE                        0x60000000UL /*!< Base address of : FMC NOR/RAM memories accessible over AXI */
#define FMC_BANK1                       FMC_BASE
#define FMC_BANK1_1                     FMC_BANK1
#define FMC_BANK1_2                     (FMC_BANK1 + 0x04000000UL)
#define FMC_BANK1_3                     (FMC_BANK1 + 0x08000000UL)
#define FMC_BANK1_4                     (FMC_BANK1 + 0x0C000000UL)
#define FMC_BANK5                       0xC0000000UL  /*!< Base address of : FMC SDRAM memories accessible over AXI */
#define FMC_BANK5_1                     FMC_BANK5
#define FMC_BANK5_2                     (FMC_BANK5 + 0x04000000UL)
#define FMC_BANK5_3                     (FMC_BANK5 + 0x08000000UL)
#define FMC_BANK5_4                     (FMC_BANK5 + 0x0C000000UL)
#define FMC_BANK6                       0xD0000000UL  /*!< Base address of : FMC SDRAM memories accessible over AXI */
#define FMC_BANK6_1                     FMC_BANK6
#define FMC_BANK6_2                     (FMC_BANK6 + 0x04000000UL)
#define FMC_BANK6_3                     (FMC_BANK6 + 0x08000000UL)
#define FMC_BANK6_4                     (FMC_BANK6 + 0x0C000000UL)
#define XSPI1_BASE                      0x90000000UL /*!< Base address of : XSPI1 memories accessible over AXI    */
#define XSPI2_BASE                      0x70000000UL /*!< Base address of : XSPI2 memories accessible over AXI    */
#define XSPI3_BASE                      0x80000000UL /*!< Base address of : XSPI3 memories accessible over AXI    */

/**************************************************************************/
/*                                                                        */
/* Peripheral and internal SRAMs base addresses - Non secure (aliased_NS) */
/*                                                                        */
/**************************************************************************/

#define ITCM_BASE_NS                    0x00000000UL /*!< Base address of ITCM from 64 KB up to 256 KB               */
#define BOOTROM_BASE_NS                 0x08000000UL /*!< Base address of 128 KB boot ROM accessible over AXI        */
#define DTCM_BASE_NS                    0x20000000UL /*!< Base address of DTCM from 128 KB up to 256 KB              */
#define SRAM1_AXI_BASE_NS               0x24000000UL /*!< Base address of up to 1 MB system RAM 1 accessible over AXI */
#define SRAM2_AXI_BASE_NS               0x24100000UL /*!< Base address of 1 MB system RAM 2 accessible over AXI      */
#define SRAM3_AXI_BASE_NS               0x24200000UL /*!< Base address of 448 KB system RAM 3 accessible over AXI      */
#define SRAM4_AXI_BASE_NS               0x24270000UL /*!< Base address of 448 KB system RAM 4 accessible over AXI */
#define SRAM5_AXI_BASE_NS               0x242E0000UL /*!< Base address of 448 KB system RAM 5 accessible over AXI */
#define SRAM6_AXI_BASE_NS               0x24350000UL /*!< Base address of 448 KB system RAM 6 accessible over AXI */
#define SRAM_AXI_BASE_NS                SRAM1_AXI_BASE_NS /*!< Base address of 3.792 MB system RAM accessible over AXI */
#define CACHEAXI_RAM_BASE_NS            0x243C0000UL /*!< Base address of 256 KB NPU Cache RAM accessible over AXI   */
#define VENC_RAM_BASE_NS                0x24400000UL /*!< Base address of 128 KB of Video Encoder RAM accessible over AXI */
#define GFXMMU_VIRTUAL_BUFFER0_BASE_NS  0x25000000UL /*!< Base address of 4 MB GFXMMU virtual buffer 0               */
#define GFXMMU_VIRTUAL_BUFFER1_BASE_NS  0x25400000UL /*!< Base address of 4 MB GFXMMU virtual buffer 1               */
#define GFXMMU_VIRTUAL_BUFFER2_BASE_NS  0x25800000UL /*!< Base address of 4 MB GFXMMU virtual buffer 2               */
#define GFXMMU_VIRTUAL_BUFFER3_BASE_NS  0x25C00000UL /*!< Base address of 4 MB GFXMMU virtual buffer 3               */
#define STM500_CHANNELS_BASE_NS         0x27F00000UL /*!< Base address of 1 MB of STM500 Channels (System Trace)     */
#define SRAM1_AHB_BASE_NS               0x28000000UL /*!< Base address of 16 KB system RAM 1 over AXI->AHB Bridge    */
#define SRAM2_AHB_BASE_NS               0x28004000UL /*!< Base address of 16 KB system RAM 2 over AXI->AHB Bridge    */
#define SRAM_AHB_BASE_NS                SRAM1_AHB_BASE_NS /*!< Base address of 32 KB system RAM over AXI->AHB Bridge */
#define BKPSRAM_BASE_NS                 0x2C000000UL /*!< Base address of 8 KB Backup SRAM over AXI->AHB Bridge      */
#define PERIPH_BASE_NS                  0x40000000UL /*!< Base address of : AHB/APB Peripherals                      */

/*!< Peripheral memory map */
#define APB1PERIPH_BASE_NS              PERIPH_BASE_NS
#define AHB1PERIPH_BASE_NS              (PERIPH_BASE_NS + 0x00020000UL)
#define APB2PERIPH_BASE_NS              (PERIPH_BASE_NS + 0x02000000UL)
#define AHB2PERIPH_BASE_NS              (PERIPH_BASE_NS + 0x02020000UL)
#define APB3PERIPH_BASE_NS              (PERIPH_BASE_NS + 0x04000000UL)
#define AHB3PERIPH_BASE_NS              (PERIPH_BASE_NS + 0x04020000UL)
#define APB4PERIPH_BASE_NS              (PERIPH_BASE_NS + 0x06000000UL)
#define AHB4PERIPH_BASE_NS              (PERIPH_BASE_NS + 0x06020000UL)
#define APB5PERIPH_BASE_NS              (PERIPH_BASE_NS + 0x08000000UL)
#define AHB5PERIPH_BASE_NS              (PERIPH_BASE_NS + 0x08020000UL)

/*!< APB1 peripherals */
#define TIM2_BASE_NS                    (APB1PERIPH_BASE_NS + 0x0000UL)
#define TIM3_BASE_NS                    (APB1PERIPH_BASE_NS + 0x0400UL)
#define TIM4_BASE_NS                    (APB1PERIPH_BASE_NS + 0x0800UL)
#define TIM5_BASE_NS                    (APB1PERIPH_BASE_NS + 0x0C00UL)
#define TIM6_BASE_NS                    (APB1PERIPH_BASE_NS + 0x1000UL)
#define TIM7_BASE_NS                    (APB1PERIPH_BASE_NS + 0x1400UL)
#define TIM12_BASE_NS                   (APB1PERIPH_BASE_NS + 0x1800UL)
#define TIM13_BASE_NS                   (APB1PERIPH_BASE_NS + 0x1C00UL)
#define TIM14_BASE_NS                   (APB1PERIPH_BASE_NS + 0x2000UL)
#define LPTIM1_BASE_NS                  (APB1PERIPH_BASE_NS + 0x2400UL)
#define WWDG_BASE_NS                    (APB1PERIPH_BASE_NS + 0x2C00UL)
#define TIM10_BASE_NS                   (APB1PERIPH_BASE_NS + 0x3000UL)
#define TIM11_BASE_NS                   (APB1PERIPH_BASE_NS + 0x3400UL)
#define SPI2_BASE_NS                    (APB1PERIPH_BASE_NS + 0x3800UL)
#define SPI3_BASE_NS                    (APB1PERIPH_BASE_NS + 0x3C00UL)
#define SPDIFRX_BASE_NS                 (APB1PERIPH_BASE_NS + 0x4000UL)
#define USART2_BASE_NS                  (APB1PERIPH_BASE_NS + 0x4400UL)
#define USART3_BASE_NS                  (APB1PERIPH_BASE_NS + 0x4800UL)
#define UART4_BASE_NS                   (APB1PERIPH_BASE_NS + 0x4C00UL)
#define UART5_BASE_NS                   (APB1PERIPH_BASE_NS + 0x5000UL)
#define I2C1_BASE_NS                    (APB1PERIPH_BASE_NS + 0x5400UL)
#define I2C2_BASE_NS                    (APB1PERIPH_BASE_NS + 0x5800UL)
#define I2C3_BASE_NS                    (APB1PERIPH_BASE_NS + 0x5C00UL)
#define I3C1_BASE_NS                    (APB1PERIPH_BASE_NS + 0x6000UL)
#define I3C2_BASE_NS                    (APB1PERIPH_BASE_NS + 0x6400UL)
#define UART7_BASE_NS                   (APB1PERIPH_BASE_NS + 0x7800UL)
#define UART8_BASE_NS                   (APB1PERIPH_BASE_NS + 0x7C00UL)
#define MDIOS_BASE_NS                   (APB1PERIPH_BASE_NS + 0x9400UL)
#define FDCAN1_BASE_NS                  (APB1PERIPH_BASE_NS + 0xA000UL)
#define FDCAN2_BASE_NS                  (APB1PERIPH_BASE_NS + 0xA400UL)
#define FDCAN_CCU_BASE_NS               (APB1PERIPH_BASE_NS + 0xA800UL)
#define SRAMCAN_BASE_NS                 (APB1PERIPH_BASE_NS + 0xC000UL)
#define FDCAN3_BASE_NS                  (APB1PERIPH_BASE_NS + 0xE800UL)
#define UCPD1_BASE_NS                   (APB1PERIPH_BASE_NS + 0xFC00UL)

/*!< AHB1 peripherals */
#define GPDMA1_BASE_NS                  (AHB1PERIPH_BASE_NS + 0x1000UL)
#define GPDMA1_Channel0_BASE_NS         (GPDMA1_BASE_NS + 0x0050UL)
#define GPDMA1_Channel1_BASE_NS         (GPDMA1_BASE_NS + 0x00D0UL)
#define GPDMA1_Channel2_BASE_NS         (GPDMA1_BASE_NS + 0x0150UL)
#define GPDMA1_Channel3_BASE_NS         (GPDMA1_BASE_NS + 0x01D0UL)
#define GPDMA1_Channel4_BASE_NS         (GPDMA1_BASE_NS + 0x0250UL)
#define GPDMA1_Channel5_BASE_NS         (GPDMA1_BASE_NS + 0x02D0UL)
#define GPDMA1_Channel6_BASE_NS         (GPDMA1_BASE_NS + 0x0350UL)
#define GPDMA1_Channel7_BASE_NS         (GPDMA1_BASE_NS + 0x03D0UL)
#define GPDMA1_Channel8_BASE_NS         (GPDMA1_BASE_NS + 0x0450UL)
#define GPDMA1_Channel9_BASE_NS         (GPDMA1_BASE_NS + 0x04D0UL)
#define GPDMA1_Channel10_BASE_NS        (GPDMA1_BASE_NS + 0x0550UL)
#define GPDMA1_Channel11_BASE_NS        (GPDMA1_BASE_NS + 0x05D0UL)
#define GPDMA1_Channel12_BASE_NS        (GPDMA1_BASE_NS + 0x0650UL)
#define GPDMA1_Channel13_BASE_NS        (GPDMA1_BASE_NS + 0x06D0UL)
#define GPDMA1_Channel14_BASE_NS        (GPDMA1_BASE_NS + 0x0750UL)
#define GPDMA1_Channel15_BASE_NS        (GPDMA1_BASE_NS + 0x07D0UL)
#define ADC1_BASE_NS                    (AHB1PERIPH_BASE_NS + 0x2000UL)
#define ADC2_BASE_NS                    (AHB1PERIPH_BASE_NS + 0x2100UL)
#define ADC12_COMMON_BASE_NS            (AHB1PERIPH_BASE_NS + 0x2300UL)

/*!< APB2 peripherals */
#define TIM1_BASE_NS                    (APB2PERIPH_BASE_NS + 0x0000UL)
#define TIM8_BASE_NS                    (APB2PERIPH_BASE_NS + 0x0400UL)
#define USART1_BASE_NS                  (APB2PERIPH_BASE_NS + 0x1000UL)
#define USART6_BASE_NS                  (APB2PERIPH_BASE_NS + 0x1400UL)
#define UART9_BASE_NS                   (APB2PERIPH_BASE_NS + 0x1800UL)
#define USART10_BASE_NS                 (APB2PERIPH_BASE_NS + 0x1C00UL)
#define SPI1_BASE_NS                    (APB2PERIPH_BASE_NS + 0x3000UL)
#define SPI4_BASE_NS                    (APB2PERIPH_BASE_NS + 0x3400UL)
#define TIM18_BASE_NS                   (APB2PERIPH_BASE_NS + 0x3C00UL)
#define TIM15_BASE_NS                   (APB2PERIPH_BASE_NS + 0x4000UL)
#define TIM16_BASE_NS                   (APB2PERIPH_BASE_NS + 0x4400UL)
#define TIM17_BASE_NS                   (APB2PERIPH_BASE_NS + 0x4800UL)
#define TIM9_BASE_NS                    (APB2PERIPH_BASE_NS + 0x4C00UL)
#define SPI5_BASE_NS                    (APB2PERIPH_BASE_NS + 0x5000UL)
#define SAI1_BASE_NS                    (APB2PERIPH_BASE_NS + 0x5800UL)
#define SAI1_Block_A_BASE_NS            (SAI1_BASE_NS + 0x0004UL)
#define SAI1_Block_B_BASE_NS            (SAI1_BASE_NS + 0x0024UL)
#define SAI2_BASE_NS                    (APB2PERIPH_BASE_NS + 0x5C00UL)
#define SAI2_Block_A_BASE_NS            (SAI2_BASE_NS + 0x0004UL)
#define SAI2_Block_B_BASE_NS            (SAI2_BASE_NS + 0x0024UL)

/*!< AHB2 peripherals */
#define RAMCFG_BASE_NS                  (AHB2PERIPH_BASE_NS + 0x3000UL)
#define RAMCFG_SRAM1_AXI_BASE_NS        (RAMCFG_BASE_NS)
#define RAMCFG_SRAM2_AXI_BASE_NS        (RAMCFG_BASE_NS + 0x0080UL)
#define RAMCFG_SRAM3_AXI_BASE_NS        (RAMCFG_BASE_NS + 0x0100UL)
#define RAMCFG_SRAM4_AXI_BASE_NS        (RAMCFG_BASE_NS + 0x0180UL)
#define RAMCFG_SRAM5_AXI_BASE_NS        (RAMCFG_BASE_NS + 0x0200UL)
#define RAMCFG_SRAM6_AXI_BASE_NS        (RAMCFG_BASE_NS + 0x0280UL)
#define RAMCFG_SRAM1_AHB_BASE_NS        (RAMCFG_BASE_NS + 0x0300UL)
#define RAMCFG_SRAM2_AHB_BASE_NS        (RAMCFG_BASE_NS + 0x0380UL)
#define RAMCFG_VENC_RAM_BASE_NS         (RAMCFG_BASE_NS + 0x0400UL)
#define RAMCFG_BKPSRAM_BASE_NS          (RAMCFG_BASE_NS + 0x0480UL)
#define RAMCFG_FLEXRAM_BASE_NS          (RAMCFG_BASE_NS + 0x0500UL)
#define MDF1_BASE_NS                    (AHB2PERIPH_BASE_NS + 0x5000UL)
#define MDF1_Filter0_BASE_NS            (MDF1_BASE_NS + 0x0080UL)
#define MDF1_Filter1_BASE_NS            (MDF1_BASE_NS + 0x0100UL)
#define MDF1_Filter2_BASE_NS            (MDF1_BASE_NS + 0x0180UL)
#define MDF1_Filter3_BASE_NS            (MDF1_BASE_NS + 0x0200UL)
#define MDF1_Filter4_BASE_NS            (MDF1_BASE_NS + 0x0280UL)
#define MDF1_Filter5_BASE_NS            (MDF1_BASE_NS + 0x0300UL)
#define ADF1_BASE_NS                    (AHB2PERIPH_BASE_NS + 0x6000UL)
#define ADF1_Filter0_BASE_NS            (ADF1_BASE_NS + 0x0080UL)

/*!< APB3 peripherals */
#define DAP_ROM_BASE_NS                 (APB3PERIPH_BASE_NS + 0x0000UL)
#define DBGMCU_BASE_NS                  (APB3PERIPH_BASE_NS + 0x1000UL)
#define DFT_APB_BASE_NS                 (APB3PERIPH_BASE_NS + 0x2000UL)

/*!< AHB3 peripherals */
#define RNG_BASE_NS                     (AHB3PERIPH_BASE_NS + 0x0000UL)
#define HASH_BASE_NS                    (AHB3PERIPH_BASE_NS + 0x0400UL)
#define HASH_DIGEST_BASE_NS             (AHB3PERIPH_BASE_NS + 0x0710UL)
#define CRYP_BASE_NS                    (AHB3PERIPH_BASE_NS + 0x0800UL)
#define SAES_BASE_NS                    (AHB3PERIPH_BASE_NS + 0x1000UL)
#define PKA_BASE_NS                     (AHB3PERIPH_BASE_NS + 0x2000UL)
#define RIFSC_BASE_NS                   (AHB3PERIPH_BASE_NS + 0x4000UL)
#define RISAF1_BASE_NS                  (AHB3PERIPH_BASE_NS + 0x6000UL)
#define RISAF2_BASE_NS                  (AHB3PERIPH_BASE_NS + 0x7000UL)
#define RISAF3_BASE_NS                  (AHB3PERIPH_BASE_NS + 0x8000UL)
#define RISAF4_BASE_NS                  (AHB3PERIPH_BASE_NS + 0x9000UL)
#define RISAF5_BASE_NS                  (AHB3PERIPH_BASE_NS + 0xA000UL)
#define RISAF6_BASE_NS                  (AHB3PERIPH_BASE_NS + 0xB000UL)
#define RISAF7_BASE_NS                  (AHB3PERIPH_BASE_NS + 0xC000UL)
#define RISAF8_BASE_NS                  (AHB3PERIPH_BASE_NS + 0xD000UL)
#define RISAF9_BASE_NS                  (AHB3PERIPH_BASE_NS + 0xE000UL)
#define RISAF11_BASE_NS                 (AHB3PERIPH_BASE_NS + 0x010000UL)
#define RISAF12_BASE_NS                 (AHB3PERIPH_BASE_NS + 0x011000UL)
#define RISAF13_BASE_NS                 (AHB3PERIPH_BASE_NS + 0x012000UL)
#define RISAF14_BASE_NS                 (AHB3PERIPH_BASE_NS + 0x013000UL)
#define RISAF15_BASE_NS                 (AHB3PERIPH_BASE_NS + 0x014000UL)
#define RISAF21_BASE_NS                 (AHB3PERIPH_BASE_NS + 0x015000UL)
#define RISAF22_BASE_NS                 (AHB3PERIPH_BASE_NS + 0x016000UL)
#define RISAF23_BASE_NS                 (AHB3PERIPH_BASE_NS + 0x017000UL)

/*!< APB4 peripherals */
#define HDP_BASE_NS                     (APB4PERIPH_BASE_NS + 0x0800UL)
#define LPUART1_BASE_NS                 (APB4PERIPH_BASE_NS + 0x0C00UL)
#define SPI6_BASE_NS                    (APB4PERIPH_BASE_NS + 0x1400UL)
#define I2C4_BASE_NS                    (APB4PERIPH_BASE_NS + 0x1C00UL)
#define LPTIM2_BASE_NS                  (APB4PERIPH_BASE_NS + 0x2400UL)
#define LPTIM3_BASE_NS                  (APB4PERIPH_BASE_NS + 0x2800UL)
#define LPTIM4_BASE_NS                  (APB4PERIPH_BASE_NS + 0x2C00UL)
#define LPTIM5_BASE_NS                  (APB4PERIPH_BASE_NS + 0x3000UL)
#define VREFBUF_BASE_NS                 (APB4PERIPH_BASE_NS + 0x3C00UL)
#define RTC_BASE_NS                     (APB4PERIPH_BASE_NS + 0x4000UL)
#define TAMP_BASE_NS                    (APB4PERIPH_BASE_NS + 0x4400UL)
#define IWDG_BASE_NS                    (APB4PERIPH_BASE_NS + 0x4800UL)
#define SERC_BASE_NS                    (APB4PERIPH_BASE_NS + 0x7C00UL)
#define SYSCFG_BASE_NS                  (APB4PERIPH_BASE_NS + 0x8000UL)
#define BSEC_BASE_NS                    (APB4PERIPH_BASE_NS + 0x9000UL)
#define DTS_BASE_NS                     (APB4PERIPH_BASE_NS + 0xA000UL)
#define DTS_Sensor0_BASE_NS             (DTS_BASE_NS + 0x0C0UL)
#define DTS_Sensor1_BASE_NS             (DTS_BASE_NS + 0x100UL)

/*!< AHB4 peripherals */
#define GPIOA_BASE_NS                   (AHB4PERIPH_BASE_NS + 0x0000UL)
#define GPIOB_BASE_NS                   (AHB4PERIPH_BASE_NS + 0x0400UL)
#define GPIOC_BASE_NS                   (AHB4PERIPH_BASE_NS + 0x0800UL)
#define GPIOD_BASE_NS                   (AHB4PERIPH_BASE_NS + 0x0C00UL)
#define GPIOE_BASE_NS                   (AHB4PERIPH_BASE_NS + 0x1000UL)
#define GPIOF_BASE_NS                   (AHB4PERIPH_BASE_NS + 0x1400UL)
#define GPIOG_BASE_NS                   (AHB4PERIPH_BASE_NS + 0x1800UL)
#define GPIOH_BASE_NS                   (AHB4PERIPH_BASE_NS + 0x1C00UL)
#define GPION_BASE_NS                   (AHB4PERIPH_BASE_NS + 0x3400UL)
#define GPIOO_BASE_NS                   (AHB4PERIPH_BASE_NS + 0x3800UL)
#define GPIOP_BASE_NS                   (AHB4PERIPH_BASE_NS + 0x3C00UL)
#define GPIOQ_BASE_NS                   (AHB4PERIPH_BASE_NS + 0x4000UL)
#define PWR_BASE_NS                     (AHB4PERIPH_BASE_NS + 0x4800UL)
#define CRC_BASE_NS                     (AHB4PERIPH_BASE_NS + 0x4C00UL)
#define EXTI_BASE_NS                    (AHB4PERIPH_BASE_NS + 0x5000UL)
#define RCC_BASE_NS                     (AHB4PERIPH_BASE_NS + 0x8000UL)

/*!< APB5 peripherals */
#define LTDC_BASE_NS                    (APB5PERIPH_BASE_NS + 0x1000UL)
#define LTDC_Layer1_BASE_NS             (LTDC_BASE_NS + 0x0100UL)
#define LTDC_Layer2_BASE_NS             (LTDC_BASE_NS + 0x0200UL)
#define DCMIPP_BASE_NS                  (APB5PERIPH_BASE_NS + 0x2000UL)
#define GFXTIM_BASE_NS                  (APB5PERIPH_BASE_NS + 0x4000UL)
#define VENC_BASE_NS                    (APB5PERIPH_BASE_NS + 0x5000UL)
#define CSI_BASE_NS                     (APB5PERIPH_BASE_NS + 0x6000UL)

/*!< AHB5 peripherals */
#define HPDMA1_BASE_NS                  (AHB5PERIPH_BASE_NS + 0x0000UL)
#define HPDMA1_Channel0_BASE_NS         (HPDMA1_BASE_NS + 0x0050UL)
#define HPDMA1_Channel1_BASE_NS         (HPDMA1_BASE_NS + 0x00D0UL)
#define HPDMA1_Channel2_BASE_NS         (HPDMA1_BASE_NS + 0x0150UL)
#define HPDMA1_Channel3_BASE_NS         (HPDMA1_BASE_NS + 0x01D0UL)
#define HPDMA1_Channel4_BASE_NS         (HPDMA1_BASE_NS + 0x0250UL)
#define HPDMA1_Channel5_BASE_NS         (HPDMA1_BASE_NS + 0x02D0UL)
#define HPDMA1_Channel6_BASE_NS         (HPDMA1_BASE_NS + 0x0350UL)
#define HPDMA1_Channel7_BASE_NS         (HPDMA1_BASE_NS + 0x03D0UL)
#define HPDMA1_Channel8_BASE_NS         (HPDMA1_BASE_NS + 0x0450UL)
#define HPDMA1_Channel9_BASE_NS         (HPDMA1_BASE_NS + 0x04D0UL)
#define HPDMA1_Channel10_BASE_NS        (HPDMA1_BASE_NS + 0x0550UL)
#define HPDMA1_Channel11_BASE_NS        (HPDMA1_BASE_NS + 0x05D0UL)
#define HPDMA1_Channel12_BASE_NS        (HPDMA1_BASE_NS + 0x0650UL)
#define HPDMA1_Channel13_BASE_NS        (HPDMA1_BASE_NS + 0x06D0UL)
#define HPDMA1_Channel14_BASE_NS        (HPDMA1_BASE_NS + 0x0750UL)
#define HPDMA1_Channel15_BASE_NS        (HPDMA1_BASE_NS + 0x07D0UL)
#define DMA2D_BASE_NS                   (AHB5PERIPH_BASE_NS + 0x1000UL)
#define JPEG_BASE_NS                    (AHB5PERIPH_BASE_NS + 0x3000UL)
#define FMC_R_BASE_NS                   (AHB5PERIPH_BASE_NS + 0x4000UL)
#define FMC_Bank1_R_BASE_NS             (FMC_R_BASE_NS + 0x0000UL)
#define FMC_Bank1E_R_BASE_NS            (FMC_R_BASE_NS + 0x0104UL)
#define FMC_Bank3_R_BASE_NS             (FMC_R_BASE_NS + 0x0080UL)
#define FMC_Bank5_6_R_BASE_NS           (FMC_R_BASE_NS + 0x0140UL)
#define FMC_Common_R_BASE_NS            (FMC_R_BASE_NS + 0x0020UL)
#define XSPI1_BASE_NS                   (AHB5PERIPH_BASE_NS + 0x5000UL)
#define PSSI_BASE_NS                    (AHB5PERIPH_BASE_NS + 0x6400UL)
#define SDMMC2_BASE_NS                  (AHB5PERIPH_BASE_NS + 0x6800UL)
#define DLYB_SDMMC2_BASE_NS             (AHB5PERIPH_BASE_NS + 0x6C00UL)
#define SDMMC1_BASE_NS                  (AHB5PERIPH_BASE_NS + 0x7000UL)
#define DLYB_SDMMC1_BASE_NS             (AHB5PERIPH_BASE_NS + 0x8000UL)
#define DCMI_BASE_NS                    (AHB5PERIPH_BASE_NS + 0x8400UL)
#define XSPI2_BASE_NS                   (AHB5PERIPH_BASE_NS + 0xA000UL)
#define XSPIM_BASE_NS                   (AHB5PERIPH_BASE_NS + 0xB400UL)
#define MCE1_BASE_NS                    (AHB5PERIPH_BASE_NS + 0xB800UL)
#define MCE1_REGION1_BASE_NS            (MCE1_BASE_NS + 0x040UL)
#define MCE1_REGION2_BASE_NS            (MCE1_BASE_NS + 0x050UL)
#define MCE1_REGION3_BASE_NS            (MCE1_BASE_NS + 0x060UL)
#define MCE1_REGION4_BASE_NS            (MCE1_BASE_NS + 0x070UL)
#define MCE1_CONTEXT1_BASE_NS           (MCE1_BASE_NS + 0x240UL)
#define MCE1_CONTEXT2_BASE_NS           (MCE1_BASE_NS + 0x270UL)
#define MCE2_BASE_NS                    (AHB5PERIPH_BASE_NS + 0xBC00UL)
#define MCE2_REGION1_BASE_NS            (MCE2_BASE_NS + 0x040UL)
#define MCE2_REGION2_BASE_NS            (MCE2_BASE_NS + 0x050UL)
#define MCE2_REGION3_BASE_NS            (MCE2_BASE_NS + 0x060UL)
#define MCE2_REGION4_BASE_NS            (MCE2_BASE_NS + 0x070UL)
#define MCE2_CONTEXT1_BASE_NS           (MCE2_BASE_NS + 0x240UL)
#define MCE2_CONTEXT2_BASE_NS           (MCE2_BASE_NS + 0x270UL)
#define MCE3_BASE_NS                    (AHB5PERIPH_BASE_NS + 0xC000UL)
#define MCE3_REGION1_BASE_NS            (MCE3_BASE_NS + 0x040UL)
#define MCE3_REGION2_BASE_NS            (MCE3_BASE_NS + 0x050UL)
#define MCE3_REGION3_BASE_NS            (MCE3_BASE_NS + 0x060UL)
#define MCE3_REGION4_BASE_NS            (MCE3_BASE_NS + 0x070UL)
#define MCE3_CONTEXT1_BASE_NS           (MCE3_BASE_NS + 0x240UL)
#define MCE3_CONTEXT2_BASE_NS           (MCE3_BASE_NS + 0x270UL)
#define MCE4_BASE_NS                    (AHB5PERIPH_BASE_NS + 0xE000UL)
#define MCE4_REGION1_BASE_NS            (MCE4_BASE_NS + 0x040UL)
#define MCE4_REGION2_BASE_NS            (MCE4_BASE_NS + 0x050UL)
#define MCE4_REGION3_BASE_NS            (MCE4_BASE_NS + 0x060UL)
#define MCE4_REGION4_BASE_NS            (MCE4_BASE_NS + 0x070UL)
#define MCE4_CONTEXT1_BASE_NS           (MCE4_BASE_NS + 0x240UL)
#define MCE4_CONTEXT2_BASE_NS           (MCE4_BASE_NS + 0x270UL)
#define XSPI3_BASE_NS                   (AHB5PERIPH_BASE_NS + 0xD000UL)
#define GFXMMU_BASE_NS                  (AHB5PERIPH_BASE_NS + 0x010000UL)
#define GPU2D_BASE_NS                   (AHB5PERIPH_BASE_NS + 0x014000UL)
#define GPUCACHE_BASE_NS                (AHB5PERIPH_BASE_NS + 0x015000UL)
#define ICACHE_BASE_NS                  (AHB5PERIPH_BASE_NS + 0x015000UL)
#define ETH1_BASE_NS                    (AHB5PERIPH_BASE_NS + 0x016000UL)
#define ETH1_MAC_BASE_NS                (ETH1_BASE_NS)
#define USB1_HS_PHYC_BASE_NS            (AHB5PERIPH_BASE_NS + 0x01FC00UL)
#define USB2_HS_PHYC_BASE_NS            (AHB5PERIPH_BASE_NS + 0x0A0000UL)
#define USB1_OTG_HS_BASE_NS             (AHB5PERIPH_BASE_NS + 0x020000UL)
#define USB2_OTG_HS_BASE_NS             (AHB5PERIPH_BASE_NS + 0x060000UL)
#define CACHEAXI_BASE_NS                (AHB5PERIPH_BASE_NS + 0x0BFC00UL)
#define NPU_BASE_NS                     (AHB5PERIPH_BASE_NS + 0x0C0000UL)


/*!< Unique device ID register base address */
#define UID_BASE_NS                     (0x46009014UL)

/*!< Revision ID base address */
#define REVID_BASE_NS                   (BOOTROM_BASE_NS + 0x001004UL)


#if defined (CPU_IN_SECURE_STATE)
/*********************************************************************/
/*                                                                   */
/* Peripheral and internal SRAMs base addresses - Secure (aliased_S) */
/*                                                                   */
/*********************************************************************/
#define ITCM_BASE_S                     0x10000000UL /*!< Base address of ITCM from 64 KB up to 256 KB               */
#define BOOTROM_BASE_S                  0x18000000UL /*!< Base address of 128 KB boot ROM accessible over AXI        */
#define DTCM_BASE_S                     0x30000000UL /*!< Base address of DTCM from 128 KB up to 256 KB              */
#define SRAM1_AXI_BASE_S                0x34000000UL /*!< Base address of up to 1 MB system RAM 1 accessible over AXI */
#define SRAM2_AXI_BASE_S                0x34100000UL /*!< Base address of 1 MB system RAM 2 accessible over AXI      */
#define SRAM3_AXI_BASE_S                0x34200000UL /*!< Base address of 448 KB system RAM 3 accessible over AXI      */
#define SRAM4_AXI_BASE_S                0x34270000UL /*!< Base address of 448 KB system RAM 4 accessible over AXI */
#define SRAM5_AXI_BASE_S                0x342E0000UL /*!< Base address of 448 KB system RAM 5 accessible over AXI */
#define SRAM6_AXI_BASE_S                0x34350000UL /*!< Base address of 448 KB system RAM 6 accessible over AXI */
#define SRAM_AXI_BASE_S                 SRAM1_AXI_BASE_NS /*!< Base address of 3.792 MB system RAM accessible over AXI */
#define CACHEAXI_RAM_BASE_S             0x343C0000UL /*!< Base address of 256 KB NPU Cache RAM accessible over AXI   */
#define VENC_RAM_BASE_S                 0x34400000UL /*!< Base address of 128 KB of Video Encoder RAM accessible over AXI */
#define GFXMMU_VIRTUAL_BUFFER0_BASE_S   0x35000000UL /*!< Base address of 4 MB GFXMMU virtual buffer 0               */
#define GFXMMU_VIRTUAL_BUFFER1_BASE_S   0x35400000UL /*!< Base address of 4 MB GFXMMU virtual buffer 1               */
#define GFXMMU_VIRTUAL_BUFFER2_BASE_S   0x35800000UL /*!< Base address of 4 MB GFXMMU virtual buffer 2               */
#define GFXMMU_VIRTUAL_BUFFER3_BASE_S   0x35C00000UL /*!< Base address of 4 MB GFXMMU virtual buffer 3               */
#define STM500_CHANNELS_BASE_S          0x37F00000UL /*!< Base address of 1 MB of STM500 Channels (System Trace)     */
#define SRAM1_AHB_BASE_S                0x38000000UL /*!< Base address of 16 KB system RAM 1 over AXI->AHB Bridge    */
#define SRAM2_AHB_BASE_S                0x38004000UL /*!< Base address of 16 KB system RAM 2 over AXI->AHB Bridge    */
#define SRAM_AHB_BASE_S                 SRAM1_AHB_BASE_S /*!< Base address of 32 KB system RAM over AXI->AHB Bridge  */
#define BKPSRAM_BASE_S                  0x3C000000UL   /*!< Base address of 8 KB Backup SRAM over AXI->AHB Bridge    */
#define PERIPH_BASE_S                   0x50000000UL   /*!< Base address of : AHB/APB Peripherals                    */

/*!< Peripheral memory map */
#define APB1PERIPH_BASE_S               PERIPH_BASE_S
#define AHB1PERIPH_BASE_S               (PERIPH_BASE_S + 0x00020000UL)
#define APB2PERIPH_BASE_S               (PERIPH_BASE_S + 0x02000000UL)
#define AHB2PERIPH_BASE_S               (PERIPH_BASE_S + 0x02020000UL)
#define APB3PERIPH_BASE_S               (PERIPH_BASE_S + 0x04000000UL)
#define AHB3PERIPH_BASE_S               (PERIPH_BASE_S + 0x04020000UL)
#define APB4PERIPH_BASE_S               (PERIPH_BASE_S + 0x06000000UL)
#define AHB4PERIPH_BASE_S               (PERIPH_BASE_S + 0x06020000UL)
#define APB5PERIPH_BASE_S               (PERIPH_BASE_S + 0x08000000UL)
#define AHB5PERIPH_BASE_S               (PERIPH_BASE_S + 0x08020000UL)

/*!< APB1 peripherals */
#define TIM2_BASE_S                     (APB1PERIPH_BASE_S + 0x0000UL)
#define TIM3_BASE_S                     (APB1PERIPH_BASE_S + 0x0400UL)
#define TIM4_BASE_S                     (APB1PERIPH_BASE_S + 0x0800UL)
#define TIM5_BASE_S                     (APB1PERIPH_BASE_S + 0x0C00UL)
#define TIM6_BASE_S                     (APB1PERIPH_BASE_S + 0x1000UL)
#define TIM7_BASE_S                     (APB1PERIPH_BASE_S + 0x1400UL)
#define TIM12_BASE_S                    (APB1PERIPH_BASE_S + 0x1800UL)
#define TIM13_BASE_S                    (APB1PERIPH_BASE_S + 0x1C00UL)
#define TIM14_BASE_S                    (APB1PERIPH_BASE_S + 0x2000UL)
#define LPTIM1_BASE_S                   (APB1PERIPH_BASE_S + 0x2400UL)
#define WWDG_BASE_S                     (APB1PERIPH_BASE_S + 0x2C00UL)
#define TIM10_BASE_S                    (APB1PERIPH_BASE_S + 0x3000UL)
#define TIM11_BASE_S                    (APB1PERIPH_BASE_S + 0x3400UL)
#define SPI2_BASE_S                     (APB1PERIPH_BASE_S + 0x3800UL)
#define SPI3_BASE_S                     (APB1PERIPH_BASE_S + 0x3C00UL)
#define SPDIFRX_BASE_S                  (APB1PERIPH_BASE_S + 0x4000UL)
#define USART2_BASE_S                   (APB1PERIPH_BASE_S + 0x4400UL)
#define USART3_BASE_S                   (APB1PERIPH_BASE_S + 0x4800UL)
#define UART4_BASE_S                    (APB1PERIPH_BASE_S + 0x4C00UL)
#define UART5_BASE_S                    (APB1PERIPH_BASE_S + 0x5000UL)
#define I2C1_BASE_S                     (APB1PERIPH_BASE_S + 0x5400UL)
#define I2C2_BASE_S                     (APB1PERIPH_BASE_S + 0x5800UL)
#define I2C3_BASE_S                     (APB1PERIPH_BASE_S + 0x5C00UL)
#define I3C1_BASE_S                     (APB1PERIPH_BASE_S + 0x6000UL)
#define I3C2_BASE_S                     (APB1PERIPH_BASE_S + 0x6400UL)
#define UART7_BASE_S                    (APB1PERIPH_BASE_S + 0x7800UL)
#define UART8_BASE_S                    (APB1PERIPH_BASE_S + 0x7C00UL)
#define MDIOS_BASE_S                    (APB1PERIPH_BASE_S + 0x9400UL)
#define FDCAN1_BASE_S                   (APB1PERIPH_BASE_S + 0xA000UL)
#define FDCAN2_BASE_S                   (APB1PERIPH_BASE_S + 0xA400UL)
#define FDCAN_CCU_BASE_S                (APB1PERIPH_BASE_S + 0xA800UL)
#define SRAMCAN_BASE_S                  (APB1PERIPH_BASE_S + 0xC000UL)
#define FDCAN3_BASE_S                   (APB1PERIPH_BASE_S + 0xE800UL)
#define UCPD1_BASE_S                    (APB1PERIPH_BASE_S + 0xFC00UL)

/*!< AHB1 peripherals */
#define GPDMA1_BASE_S                   (AHB1PERIPH_BASE_S + 0x1000UL)
#define GPDMA1_Channel0_BASE_S          (GPDMA1_BASE_S + 0x0050UL)
#define GPDMA1_Channel1_BASE_S          (GPDMA1_BASE_S + 0x00D0UL)
#define GPDMA1_Channel2_BASE_S          (GPDMA1_BASE_S + 0x0150UL)
#define GPDMA1_Channel3_BASE_S          (GPDMA1_BASE_S + 0x01D0UL)
#define GPDMA1_Channel4_BASE_S          (GPDMA1_BASE_S + 0x0250UL)
#define GPDMA1_Channel5_BASE_S          (GPDMA1_BASE_S + 0x02D0UL)
#define GPDMA1_Channel6_BASE_S          (GPDMA1_BASE_S + 0x0350UL)
#define GPDMA1_Channel7_BASE_S          (GPDMA1_BASE_S + 0x03D0UL)
#define GPDMA1_Channel8_BASE_S          (GPDMA1_BASE_S + 0x0450UL)
#define GPDMA1_Channel9_BASE_S          (GPDMA1_BASE_S + 0x04D0UL)
#define GPDMA1_Channel10_BASE_S         (GPDMA1_BASE_S + 0x0550UL)
#define GPDMA1_Channel11_BASE_S         (GPDMA1_BASE_S + 0x05D0UL)
#define GPDMA1_Channel12_BASE_S         (GPDMA1_BASE_S + 0x0650UL)
#define GPDMA1_Channel13_BASE_S         (GPDMA1_BASE_S + 0x06D0UL)
#define GPDMA1_Channel14_BASE_S         (GPDMA1_BASE_S + 0x0750UL)
#define GPDMA1_Channel15_BASE_S         (GPDMA1_BASE_S + 0x07D0UL)
#define ADC1_BASE_S                     (AHB1PERIPH_BASE_S + 0x2000UL)
#define ADC2_BASE_S                     (AHB1PERIPH_BASE_S + 0x2100UL)
#define ADC12_COMMON_BASE_S             (AHB1PERIPH_BASE_S + 0x2300UL)

/*!< APB2 peripherals */
#define TIM1_BASE_S                     (APB2PERIPH_BASE_S + 0x0000UL)
#define TIM8_BASE_S                     (APB2PERIPH_BASE_S + 0x0400UL)
#define USART1_BASE_S                   (APB2PERIPH_BASE_S + 0x1000UL)
#define USART6_BASE_S                   (APB2PERIPH_BASE_S + 0x1400UL)
#define UART9_BASE_S                    (APB2PERIPH_BASE_S + 0x1800UL)
#define USART10_BASE_S                  (APB2PERIPH_BASE_S + 0x1C00UL)
#define SPI1_BASE_S                     (APB2PERIPH_BASE_S + 0x3000UL)
#define SPI4_BASE_S                     (APB2PERIPH_BASE_S + 0x3400UL)
#define TIM18_BASE_S                    (APB2PERIPH_BASE_S + 0x3C00UL)
#define TIM15_BASE_S                    (APB2PERIPH_BASE_S + 0x4000UL)
#define TIM16_BASE_S                    (APB2PERIPH_BASE_S + 0x4400UL)
#define TIM17_BASE_S                    (APB2PERIPH_BASE_S + 0x4800UL)
#define TIM9_BASE_S                     (APB2PERIPH_BASE_S + 0x4C00UL)
#define SPI5_BASE_S                     (APB2PERIPH_BASE_S + 0x5000UL)
#define SAI1_BASE_S                     (APB2PERIPH_BASE_S + 0x5800UL)
#define SAI1_Block_A_BASE_S             (SAI1_BASE_S + 0x0004UL)
#define SAI1_Block_B_BASE_S             (SAI1_BASE_S + 0x0024UL)
#define SAI2_BASE_S                     (APB2PERIPH_BASE_S + 0x5C00UL)
#define SAI2_Block_A_BASE_S             (SAI2_BASE_S + 0x0004UL)
#define SAI2_Block_B_BASE_S             (SAI2_BASE_S + 0x0024UL)

/*!< AHB2 peripherals */
#define RAMCFG_BASE_S                   (AHB2PERIPH_BASE_S + 0x3000UL)
#define RAMCFG_SRAM1_AXI_BASE_S         (RAMCFG_BASE_S)
#define RAMCFG_SRAM2_AXI_BASE_S         (RAMCFG_BASE_S + 0x0080UL)
#define RAMCFG_SRAM3_AXI_BASE_S         (RAMCFG_BASE_S + 0x0100UL)
#define RAMCFG_SRAM4_AXI_BASE_S         (RAMCFG_BASE_S + 0x0180UL)
#define RAMCFG_SRAM5_AXI_BASE_S         (RAMCFG_BASE_S + 0x0200UL)
#define RAMCFG_SRAM6_AXI_BASE_S         (RAMCFG_BASE_S + 0x0280UL)
#define RAMCFG_SRAM1_AHB_BASE_S         (RAMCFG_BASE_S + 0x0300UL)
#define RAMCFG_SRAM2_AHB_BASE_S         (RAMCFG_BASE_S + 0x0380UL)
#define RAMCFG_VENC_RAM_BASE_S          (RAMCFG_BASE_S + 0x0400UL)
#define RAMCFG_BKPSRAM_BASE_S           (RAMCFG_BASE_S + 0x0480UL)
#define RAMCFG_FLEXRAM_BASE_S           (RAMCFG_BASE_S + 0x0500UL)
#define MDF1_BASE_S                     (AHB2PERIPH_BASE_S + 0x5000UL)
#define MDF1_Filter0_BASE_S             (MDF1_BASE_S + 0x0080UL)
#define MDF1_Filter1_BASE_S             (MDF1_BASE_S + 0x0100UL)
#define MDF1_Filter2_BASE_S             (MDF1_BASE_S + 0x0180UL)
#define MDF1_Filter3_BASE_S             (MDF1_BASE_S + 0x0200UL)
#define MDF1_Filter4_BASE_S             (MDF1_BASE_S + 0x0280UL)
#define MDF1_Filter5_BASE_S             (MDF1_BASE_S + 0x0300UL)
#define ADF1_BASE_S                     (AHB2PERIPH_BASE_S + 0x6000UL)
#define ADF1_Filter0_BASE_S             (ADF1_BASE_S + 0x0080UL)

/*!< APB3 peripherals */
#define DAP_ROM_BASE_S                  (APB3PERIPH_BASE_S + 0x0000UL)
#define DBGMCU_BASE_S                   (APB3PERIPH_BASE_S + 0x1000UL)
#define DFT_APB_BASE_S                  (APB3PERIPH_BASE_S + 0x2000UL)

/*!< AHB3 peripherals */
#define RNG_BASE_S                      (AHB3PERIPH_BASE_S + 0x0000UL)
#define HASH_BASE_S                     (AHB3PERIPH_BASE_S + 0x0400UL)
#define HASH_DIGEST_BASE_S              (AHB3PERIPH_BASE_S + 0x0710UL)
#define CRYP_BASE_S                     (AHB3PERIPH_BASE_S + 0x0800UL)
#define SAES_BASE_S                     (AHB3PERIPH_BASE_S + 0x1000UL)
#define PKA_BASE_S                      (AHB3PERIPH_BASE_S + 0x2000UL)
#define RIFSC_BASE_S                    (AHB3PERIPH_BASE_S + 0x4000UL)
#define IAC_BASE_S                      (AHB3PERIPH_BASE_S + 0x5000UL)
#define RISAF1_BASE_S                   (AHB3PERIPH_BASE_S + 0x6000UL)
#define RISAF2_BASE_S                   (AHB3PERIPH_BASE_S + 0x7000UL)
#define RISAF3_BASE_S                   (AHB3PERIPH_BASE_S + 0x8000UL)
#define RISAF4_BASE_S                   (AHB3PERIPH_BASE_S + 0x9000UL)
#define RISAF5_BASE_S                   (AHB3PERIPH_BASE_S + 0xA000UL)
#define RISAF6_BASE_S                   (AHB3PERIPH_BASE_S + 0xB000UL)
#define RISAF7_BASE_S                   (AHB3PERIPH_BASE_S + 0xC000UL)
#define RISAF8_BASE_S                   (AHB3PERIPH_BASE_S + 0xD000UL)
#define RISAF9_BASE_S                   (AHB3PERIPH_BASE_S + 0xE000UL)
#define RISAF11_BASE_S                  (AHB3PERIPH_BASE_S + 0x010000UL)
#define RISAF12_BASE_S                  (AHB3PERIPH_BASE_S + 0x011000UL)
#define RISAF13_BASE_S                  (AHB3PERIPH_BASE_S + 0x012000UL)
#define RISAF14_BASE_S                  (AHB3PERIPH_BASE_S + 0x013000UL)
#define RISAF15_BASE_S                  (AHB3PERIPH_BASE_S + 0x014000UL)
#define RISAF21_BASE_S                  (AHB3PERIPH_BASE_S + 0x015000UL)
#define RISAF22_BASE_S                  (AHB3PERIPH_BASE_S + 0x016000UL)
#define RISAF23_BASE_S                  (AHB3PERIPH_BASE_S + 0x017000UL)

/*!< APB4 peripherals */
#define HDP_BASE_S                      (APB4PERIPH_BASE_S + 0x0800UL)
#define LPUART1_BASE_S                  (APB4PERIPH_BASE_S + 0x0C00UL)
#define SPI6_BASE_S                     (APB4PERIPH_BASE_S + 0x1400UL)
#define I2C4_BASE_S                     (APB4PERIPH_BASE_S + 0x1C00UL)
#define LPTIM2_BASE_S                   (APB4PERIPH_BASE_S + 0x2400UL)
#define LPTIM3_BASE_S                   (APB4PERIPH_BASE_S + 0x2800UL)
#define LPTIM4_BASE_S                   (APB4PERIPH_BASE_S + 0x2C00UL)
#define LPTIM5_BASE_S                   (APB4PERIPH_BASE_S + 0x3000UL)
#define VREFBUF_BASE_S                  (APB4PERIPH_BASE_S + 0x3C00UL)
#define RTC_BASE_S                      (APB4PERIPH_BASE_S + 0x4000UL)
#define TAMP_BASE_S                     (APB4PERIPH_BASE_S + 0x4400UL)
#define IWDG_BASE_S                     (APB4PERIPH_BASE_S + 0x4800UL)

#define SERC_BASE_S                     (APB4PERIPH_BASE_S + 0x7C00UL)
#define SYSCFG_BASE_S                   (APB4PERIPH_BASE_S + 0x8000UL)
#define BSEC_BASE_S                     (APB4PERIPH_BASE_S + 0x9000UL)
#define DTS_BASE_S                      (APB4PERIPH_BASE_S + 0xA000UL)
#define DTS_Sensor0_BASE_S              (DTS_BASE_S + 0x0C0UL)
#define DTS_Sensor1_BASE_S              (DTS_BASE_S + 0x100UL)

/*!< AHB4 peripherals */
#define GPIOA_BASE_S                    (AHB4PERIPH_BASE_S + 0x0000UL)
#define GPIOB_BASE_S                    (AHB4PERIPH_BASE_S + 0x0400UL)
#define GPIOC_BASE_S                    (AHB4PERIPH_BASE_S + 0x0800UL)
#define GPIOD_BASE_S                    (AHB4PERIPH_BASE_S + 0x0C00UL)
#define GPIOE_BASE_S                    (AHB4PERIPH_BASE_S + 0x1000UL)
#define GPIOF_BASE_S                    (AHB4PERIPH_BASE_S + 0x1400UL)
#define GPIOG_BASE_S                    (AHB4PERIPH_BASE_S + 0x1800UL)
#define GPIOH_BASE_S                    (AHB4PERIPH_BASE_S + 0x1C00UL)
#define GPION_BASE_S                    (AHB4PERIPH_BASE_S + 0x3400UL)
#define GPIOO_BASE_S                    (AHB4PERIPH_BASE_S + 0x3800UL)
#define GPIOP_BASE_S                    (AHB4PERIPH_BASE_S + 0x3C00UL)
#define GPIOQ_BASE_S                    (AHB4PERIPH_BASE_S + 0x4000UL)
#define PWR_BASE_S                      (AHB4PERIPH_BASE_S + 0x4800UL)
#define CRC_BASE_S                      (AHB4PERIPH_BASE_S + 0x4C00UL)
#define EXTI_BASE_S                     (AHB4PERIPH_BASE_S + 0x5000UL)
#define RCC_BASE_S                      (AHB4PERIPH_BASE_S + 0x8000UL)

/*!< APB5 peripherals */
#define LTDC_BASE_S                     (APB5PERIPH_BASE_S + 0x1000UL)
#define LTDC_Layer1_BASE_S              (LTDC_BASE_S + 0x0100UL)
#define LTDC_Layer2_BASE_S              (LTDC_BASE_S + 0x0200UL)
#define DCMIPP_BASE_S                   (APB5PERIPH_BASE_S + 0x2000UL)
#define GFXTIM_BASE_S                   (APB5PERIPH_BASE_S + 0x4000UL)
#define VENC_BASE_S                     (APB5PERIPH_BASE_S + 0x5000UL)
#define CSI_BASE_S                      (APB5PERIPH_BASE_S + 0x6000UL)

/*!< AHB5 peripherals */
#define HPDMA1_BASE_S                   (AHB5PERIPH_BASE_S + 0x0000UL)
#define HPDMA1_Channel0_BASE_S          (HPDMA1_BASE_S + 0x0050UL)
#define HPDMA1_Channel1_BASE_S          (HPDMA1_BASE_S + 0x00D0UL)
#define HPDMA1_Channel2_BASE_S          (HPDMA1_BASE_S + 0x0150UL)
#define HPDMA1_Channel3_BASE_S          (HPDMA1_BASE_S + 0x01D0UL)
#define HPDMA1_Channel4_BASE_S          (HPDMA1_BASE_S + 0x0250UL)
#define HPDMA1_Channel5_BASE_S          (HPDMA1_BASE_S + 0x02D0UL)
#define HPDMA1_Channel6_BASE_S          (HPDMA1_BASE_S + 0x0350UL)
#define HPDMA1_Channel7_BASE_S          (HPDMA1_BASE_S + 0x03D0UL)
#define HPDMA1_Channel8_BASE_S          (HPDMA1_BASE_S + 0x0450UL)
#define HPDMA1_Channel9_BASE_S          (HPDMA1_BASE_S + 0x04D0UL)
#define HPDMA1_Channel10_BASE_S         (HPDMA1_BASE_S + 0x0550UL)
#define HPDMA1_Channel11_BASE_S         (HPDMA1_BASE_S + 0x05D0UL)
#define HPDMA1_Channel12_BASE_S         (HPDMA1_BASE_S + 0x0650UL)
#define HPDMA1_Channel13_BASE_S         (HPDMA1_BASE_S + 0x06D0UL)
#define HPDMA1_Channel14_BASE_S         (HPDMA1_BASE_S + 0x0750UL)
#define HPDMA1_Channel15_BASE_S         (HPDMA1_BASE_S + 0x07D0UL)
#define DMA2D_BASE_S                    (AHB5PERIPH_BASE_S + 0x1000UL)
#define JPEG_BASE_S                     (AHB5PERIPH_BASE_S + 0x3000UL)
#define FMC_R_BASE_S                    (AHB5PERIPH_BASE_S + 0x4000UL)
#define FMC_Bank1_R_BASE_S              (FMC_R_BASE_S + 0x0000UL)
#define FMC_Bank1E_R_BASE_S             (FMC_R_BASE_S + 0x0104UL)
#define FMC_Bank3_R_BASE_S              (FMC_R_BASE_S + 0x0080UL)
#define FMC_Bank5_6_R_BASE_S            (FMC_R_BASE_S + 0x0140UL)
#define FMC_Common_R_BASE_S             (FMC_R_BASE_S + 0x0020UL)
#define XSPI1_BASE_S                    (AHB5PERIPH_BASE_S + 0x5000UL)
#define PSSI_BASE_S                     (AHB5PERIPH_BASE_S + 0x6400UL)
#define SDMMC2_BASE_S                   (AHB5PERIPH_BASE_S + 0x6800UL)
#define DLYB_SDMMC2_BASE_S              (AHB5PERIPH_BASE_S + 0x6C00UL)
#define SDMMC1_BASE_S                   (AHB5PERIPH_BASE_S + 0x7000UL)
#define DLYB_SDMMC1_BASE_S              (AHB5PERIPH_BASE_S + 0x8000UL)
#define DCMI_BASE_S                     (AHB5PERIPH_BASE_S + 0x8400UL)
#define XSPI2_BASE_S                    (AHB5PERIPH_BASE_S + 0xA000UL)
#define XSPIM_BASE_S                    (AHB5PERIPH_BASE_S + 0xB400UL)
#define MCE1_BASE_S                     (AHB5PERIPH_BASE_S + 0xB800UL)
#define MCE1_REGION1_BASE_S             (MCE1_BASE_S + 0x040UL)
#define MCE1_REGION2_BASE_S             (MCE1_BASE_S + 0x050UL)
#define MCE1_REGION3_BASE_S             (MCE1_BASE_S + 0x060UL)
#define MCE1_REGION4_BASE_S             (MCE1_BASE_S + 0x070UL)
#define MCE1_CONTEXT1_BASE_S            (MCE1_BASE_S + 0x240UL)
#define MCE1_CONTEXT2_BASE_S            (MCE1_BASE_S + 0x270UL)
#define MCE2_BASE_S                     (AHB5PERIPH_BASE_S + 0xBC00UL)
#define MCE2_REGION1_BASE_S             (MCE2_BASE_S + 0x040UL)
#define MCE2_REGION2_BASE_S             (MCE2_BASE_S + 0x050UL)
#define MCE2_REGION3_BASE_S             (MCE2_BASE_S + 0x060UL)
#define MCE2_REGION4_BASE_S             (MCE2_BASE_S + 0x070UL)
#define MCE2_CONTEXT1_BASE_S            (MCE2_BASE_S + 0x240UL)
#define MCE2_CONTEXT2_BASE_S            (MCE2_BASE_S + 0x270UL)
#define MCE3_BASE_S                     (AHB5PERIPH_BASE_S + 0xC000UL)
#define MCE3_REGION1_BASE_S             (MCE3_BASE_S + 0x040UL)
#define MCE3_REGION2_BASE_S             (MCE3_BASE_S + 0x050UL)
#define MCE3_REGION3_BASE_S             (MCE3_BASE_S + 0x060UL)
#define MCE3_REGION4_BASE_S             (MCE3_BASE_S + 0x070UL)
#define MCE3_CONTEXT1_BASE_S            (MCE3_BASE_S + 0x240UL)
#define MCE3_CONTEXT2_BASE_S            (MCE3_BASE_S + 0x270UL)
#define MCE4_BASE_S                     (AHB5PERIPH_BASE_S + 0xE000UL)
#define MCE4_REGION1_BASE_S             (MCE4_BASE_S + 0x040UL)
#define MCE4_REGION2_BASE_S             (MCE4_BASE_S + 0x050UL)
#define MCE4_REGION3_BASE_S             (MCE4_BASE_S + 0x060UL)
#define MCE4_REGION4_BASE_S             (MCE4_BASE_S + 0x070UL)
#define MCE4_CONTEXT1_BASE_S            (MCE4_BASE_S + 0x240UL)
#define MCE4_CONTEXT2_BASE_S            (MCE4_BASE_S + 0x270UL)
#define XSPI3_BASE_S                    (AHB5PERIPH_BASE_S + 0xD000UL)
#define GFXMMU_BASE_S                   (AHB5PERIPH_BASE_S + 0x010000UL)
#define GPU2D_BASE_S                    (AHB5PERIPH_BASE_S + 0x014000UL)
#define GPUCACHE_BASE_S                 (AHB5PERIPH_BASE_S + 0x015000UL)
#define ICACHE_BASE_S                   (AHB5PERIPH_BASE_S + 0x015000UL)
#define ETH1_BASE_S                     (AHB5PERIPH_BASE_S + 0x016000UL)
#define ETH1_MAC_BASE_S                 (ETH1_BASE_S)
#define USB1_HS_PHYC_BASE_S             (AHB5PERIPH_BASE_S + 0x01FC00UL)
#define USB2_HS_PHYC_BASE_S             (AHB5PERIPH_BASE_S + 0x0A0000UL)
#define USB1_OTG_HS_BASE_S              (AHB5PERIPH_BASE_S + 0x020000UL)
#define USB2_OTG_HS_BASE_S              (AHB5PERIPH_BASE_S + 0x060000UL)
#define CACHEAXI_BASE_S                 (AHB5PERIPH_BASE_S + 0x0BFC00UL)
#define NPU_BASE_S                      (AHB5PERIPH_BASE_S + 0x0C0000UL)


/*!< Unique device ID register base address */
#define UID_BASE_S                      (0x56009014UL)

/*!< Revision ID base address */
#define REVID_BASE_S                    (BOOTROM_BASE_S + 0x001004UL)

#endif

/** @} */ /* End of group STM32N6xx_Peripheral_peripheralAddr */

/* =========================================================================================================================== */
/* ================                                  Peripheral declaration                                   ================ */
/* =========================================================================================================================== */
/** @addtogroup STM32N6xx_Peripheral_declaration
  * @{
  */
#define ADC12_COMMON_NS           ((ADC_Common_TypeDef *) ADC12_COMMON_BASE_NS)
#define ADC1_NS                   ((ADC_TypeDef *) ADC1_BASE_NS)
#define ADC2_NS                   ((ADC_TypeDef *) ADC2_BASE_NS)
#define ADF1_NS                   ((MDF_TypeDef *) ADF1_BASE_NS)
#define ADF1_Filter0_NS           ((MDF_Filter_TypeDef *) ADF1_Filter0_BASE_NS)
#define BSEC_NS                   ((BSEC_TypeDef *) BSEC_BASE_NS)
#define CACHEAXI_NS               ((CACHEAXI_TypeDef *) CACHEAXI_BASE_NS)
#define CRC_NS                    ((CRC_TypeDef *) CRC_BASE_NS)
#define CRYP_NS                   ((CRYP_TypeDef *) CRYP_BASE_NS)
#define CSI_NS                    ((CSI_TypeDef *) CSI_BASE_NS)
#define DBGMCU_NS                 ((DBGMCU_TypeDef *) DBGMCU_BASE_NS)
#define DCMI_NS                   ((DCMI_TypeDef *) DCMI_BASE_NS)
#define DCMIPP_NS                 ((DCMIPP_TypeDef *) DCMIPP_BASE_NS)
#define DLYB_SDMMC1_NS            ((DLYB_TypeDef *) DLYB_SDMMC1_BASE_NS)
#define DLYB_SDMMC2_NS            ((DLYB_TypeDef *) DLYB_SDMMC2_BASE_NS)
#define DMA2D_NS                  ((DMA2D_TypeDef *) DMA2D_BASE_NS)
#define DTS_NS                    ((DTS_TypeDef *) DTS_BASE_NS)
#define DTS_Sensor0_NS            ((DTS_SensorTypeDef *) DTS_Sensor0_BASE_NS)
#define DTS_Sensor1_NS            ((DTS_SensorTypeDef *) DTS_Sensor1_BASE_NS)
#define ETH1_NS                   ((ETH_TypeDef *) ETH1_BASE_NS)
#define EXTI_NS                   ((EXTI_TypeDef *) EXTI_BASE_NS)
#define FDCAN1_NS                 ((FDCAN_GlobalTypeDef *) FDCAN1_BASE_NS)
#define FDCAN2_NS                 ((FDCAN_GlobalTypeDef *) FDCAN2_BASE_NS)
#define FDCAN3_NS                 ((FDCAN_GlobalTypeDef *) FDCAN3_BASE_NS)
#define FDCAN_CCU_NS              ((FDCAN_ClockCalibrationUnit_TypeDef *) FDCAN_CCU_BASE_NS)
#define FMC_Bank1E_R_NS           ((FMC_Bank1E_TypeDef *) FMC_Bank1E_R_BASE_NS)
#define FMC_Bank1_R_NS            ((FMC_Bank1_TypeDef *) FMC_Bank1_R_BASE_NS)
#define FMC_Bank3_R_NS            ((FMC_Bank3_TypeDef *) FMC_Bank3_R_BASE_NS)
#define FMC_Bank5_6_R_NS          ((FMC_Bank5_6_TypeDef *) FMC_Bank5_6_R_BASE_NS)
#define FMC_Common_R_NS           ((FMC_Common_TypeDef *) FMC_Common_R_BASE_NS)
#define GFXMMU_NS                 ((GFXMMU_TypeDef *) GFXMMU_BASE_NS)
#define GFXTIM_NS                 ((GFXTIM_TypeDef *) GFXTIM_BASE_NS)
#define GPDMA1_NS                 ((DMA_TypeDef *) GPDMA1_BASE_NS)
#define GPDMA1_Channel0_NS        ((DMA_Channel_TypeDef *) GPDMA1_Channel0_BASE_NS)
#define GPDMA1_Channel1_NS        ((DMA_Channel_TypeDef *) GPDMA1_Channel1_BASE_NS)
#define GPDMA1_Channel2_NS        ((DMA_Channel_TypeDef *) GPDMA1_Channel2_BASE_NS)
#define GPDMA1_Channel3_NS        ((DMA_Channel_TypeDef *) GPDMA1_Channel3_BASE_NS)
#define GPDMA1_Channel4_NS        ((DMA_Channel_TypeDef *) GPDMA1_Channel4_BASE_NS)
#define GPDMA1_Channel5_NS        ((DMA_Channel_TypeDef *) GPDMA1_Channel5_BASE_NS)
#define GPDMA1_Channel6_NS        ((DMA_Channel_TypeDef *) GPDMA1_Channel6_BASE_NS)
#define GPDMA1_Channel7_NS        ((DMA_Channel_TypeDef *) GPDMA1_Channel7_BASE_NS)
#define GPDMA1_Channel8_NS        ((DMA_Channel_TypeDef *) GPDMA1_Channel8_BASE_NS)
#define GPDMA1_Channel9_NS        ((DMA_Channel_TypeDef *) GPDMA1_Channel9_BASE_NS)
#define GPDMA1_Channel10_NS       ((DMA_Channel_TypeDef *) GPDMA1_Channel10_BASE_NS)
#define GPDMA1_Channel11_NS       ((DMA_Channel_TypeDef *) GPDMA1_Channel11_BASE_NS)
#define GPDMA1_Channel12_NS       ((DMA_Channel_TypeDef *) GPDMA1_Channel12_BASE_NS)
#define GPDMA1_Channel13_NS       ((DMA_Channel_TypeDef *) GPDMA1_Channel13_BASE_NS)
#define GPDMA1_Channel14_NS       ((DMA_Channel_TypeDef *) GPDMA1_Channel14_BASE_NS)
#define GPDMA1_Channel15_NS       ((DMA_Channel_TypeDef *) GPDMA1_Channel15_BASE_NS)
#define GPIOA_NS                  ((GPIO_TypeDef *) GPIOA_BASE_NS)
#define GPIOB_NS                  ((GPIO_TypeDef *) GPIOB_BASE_NS)
#define GPIOC_NS                  ((GPIO_TypeDef *) GPIOC_BASE_NS)
#define GPIOD_NS                  ((GPIO_TypeDef *) GPIOD_BASE_NS)
#define GPIOE_NS                  ((GPIO_TypeDef *) GPIOE_BASE_NS)
#define GPIOF_NS                  ((GPIO_TypeDef *) GPIOF_BASE_NS)
#define GPIOG_NS                  ((GPIO_TypeDef *) GPIOG_BASE_NS)
#define GPIOH_NS                  ((GPIO_TypeDef *) GPIOH_BASE_NS)
#define GPION_NS                  ((GPIO_TypeDef *) GPION_BASE_NS)
#define GPIOO_NS                  ((GPIO_TypeDef *) GPIOO_BASE_NS)
#define GPIOP_NS                  ((GPIO_TypeDef *) GPIOP_BASE_NS)
#define GPIOQ_NS                  ((GPIO_TypeDef *) GPIOQ_BASE_NS)
#define HASH_NS                   ((HASH_TypeDef *) HASH_BASE_NS)
#define HASH_DIGEST_NS            ((HASH_DIGEST_TypeDef *) HASH_DIGEST_BASE_NS)
#define HPDMA1_NS                 ((DMA_TypeDef *) HPDMA1_BASE_NS)
#define HPDMA1_Channel0_NS        ((DMA_Channel_TypeDef *) HPDMA1_Channel0_BASE_NS)
#define HPDMA1_Channel1_NS        ((DMA_Channel_TypeDef *) HPDMA1_Channel1_BASE_NS)
#define HPDMA1_Channel2_NS        ((DMA_Channel_TypeDef *) HPDMA1_Channel2_BASE_NS)
#define HPDMA1_Channel3_NS        ((DMA_Channel_TypeDef *) HPDMA1_Channel3_BASE_NS)
#define HPDMA1_Channel4_NS        ((DMA_Channel_TypeDef *) HPDMA1_Channel4_BASE_NS)
#define HPDMA1_Channel5_NS        ((DMA_Channel_TypeDef *) HPDMA1_Channel5_BASE_NS)
#define HPDMA1_Channel6_NS        ((DMA_Channel_TypeDef *) HPDMA1_Channel6_BASE_NS)
#define HPDMA1_Channel7_NS        ((DMA_Channel_TypeDef *) HPDMA1_Channel7_BASE_NS)
#define HPDMA1_Channel8_NS        ((DMA_Channel_TypeDef *) HPDMA1_Channel8_BASE_NS)
#define HPDMA1_Channel9_NS        ((DMA_Channel_TypeDef *) HPDMA1_Channel9_BASE_NS)
#define HPDMA1_Channel10_NS       ((DMA_Channel_TypeDef *) HPDMA1_Channel10_BASE_NS)
#define HPDMA1_Channel11_NS       ((DMA_Channel_TypeDef *) HPDMA1_Channel11_BASE_NS)
#define HPDMA1_Channel12_NS       ((DMA_Channel_TypeDef *) HPDMA1_Channel12_BASE_NS)
#define HPDMA1_Channel13_NS       ((DMA_Channel_TypeDef *) HPDMA1_Channel13_BASE_NS)
#define HPDMA1_Channel14_NS       ((DMA_Channel_TypeDef *) HPDMA1_Channel14_BASE_NS)
#define HPDMA1_Channel15_NS       ((DMA_Channel_TypeDef *) HPDMA1_Channel15_BASE_NS)
#define I2C1_NS                   ((I2C_TypeDef *) I2C1_BASE_NS)
#define I2C2_NS                   ((I2C_TypeDef *) I2C2_BASE_NS)
#define I2C3_NS                   ((I2C_TypeDef *) I2C3_BASE_NS)
#define I2C4_NS                   ((I2C_TypeDef *) I2C4_BASE_NS)
#define I3C1_NS                   ((I3C_TypeDef *) I3C1_BASE_NS)
#define I3C2_NS                   ((I3C_TypeDef *) I3C2_BASE_NS)
#define ICACHE_NS                 ((ICACHE_TypeDef *) ICACHE_BASE_NS)
#define IWDG_NS                   ((IWDG_TypeDef *) IWDG_BASE_NS)
#define JPEG_NS                   ((JPEG_TypeDef *) JPEG_BASE_NS)
#define LPTIM1_NS                 ((LPTIM_TypeDef *) LPTIM1_BASE_NS)
#define LPTIM2_NS                 ((LPTIM_TypeDef *) LPTIM2_BASE_NS)
#define LPTIM3_NS                 ((LPTIM_TypeDef *) LPTIM3_BASE_NS)
#define LPTIM4_NS                 ((LPTIM_TypeDef *) LPTIM4_BASE_NS)
#define LPTIM5_NS                 ((LPTIM_TypeDef *) LPTIM5_BASE_NS)
#define LPUART1_NS                ((USART_TypeDef *) LPUART1_BASE_NS)
#define LTDC_NS                   ((LTDC_TypeDef *)LTDC_BASE_NS)
#define LTDC_Layer1_NS            ((LTDC_Layer_TypeDef *)LTDC_Layer1_BASE_NS)
#define LTDC_Layer2_NS            ((LTDC_Layer_TypeDef *)LTDC_Layer2_BASE_NS)
#define MCE1_NS                   ((MCE_TypeDef *) MCE1_BASE_NS)
#define MCE1_REGION1_NS           ((MCE_Region_TypeDef *) MCE1_REGION1_BASE_NS)
#define MCE1_REGION2_NS           ((MCE_Region_TypeDef *) MCE1_REGION2_BASE_NS)
#define MCE1_REGION3_NS           ((MCE_Region_TypeDef *) MCE1_REGION3_BASE_NS)
#define MCE1_REGION4_NS           ((MCE_Region_TypeDef *) MCE1_REGION4_BASE_NS)
#define MCE1_CONTEXT1_NS          ((MCE_Context_TypeDef *) MCE1_CONTEXT1_BASE_NS)
#define MCE1_CONTEXT2_NS          ((MCE_Context_TypeDef *) MCE1_CONTEXT2_BASE_NS)
#define MCE2_NS                   ((MCE_TypeDef *) MCE2_BASE_NS)
#define MCE2_REGION1_NS           ((MCE_Region_TypeDef *) MCE2_REGION1_BASE_NS)
#define MCE2_REGION2_NS           ((MCE_Region_TypeDef *) MCE2_REGION2_BASE_NS)
#define MCE2_REGION3_NS           ((MCE_Region_TypeDef *) MCE2_REGION3_BASE_NS)
#define MCE2_REGION4_NS           ((MCE_Region_TypeDef *) MCE2_REGION4_BASE_NS)
#define MCE2_CONTEXT1_NS          ((MCE_Context_TypeDef *) MCE2_CONTEXT1_BASE_NS)
#define MCE2_CONTEXT2_NS          ((MCE_Context_TypeDef *) MCE2_CONTEXT2_BASE_NS)
#define MCE3_NS                   ((MCE_TypeDef *) MCE3_BASE_NS)
#define MCE3_REGION1_NS           ((MCE_Region_TypeDef *) MCE3_REGION1_BASE_NS)
#define MCE3_REGION2_NS           ((MCE_Region_TypeDef *) MCE3_REGION2_BASE_NS)
#define MCE3_REGION3_NS           ((MCE_Region_TypeDef *) MCE3_REGION3_BASE_NS)
#define MCE3_REGION4_NS           ((MCE_Region_TypeDef *) MCE3_REGION4_BASE_NS)
#define MCE3_CONTEXT1_NS          ((MCE_Context_TypeDef *) MCE3_CONTEXT1_BASE_NS)
#define MCE3_CONTEXT2_NS          ((MCE_Context_TypeDef *) MCE3_CONTEXT2_BASE_NS)
#define MCE4_NS                   ((MCE_TypeDef *) MCE4_BASE_NS)
#define MCE4_REGION1_NS           ((MCE_Region_TypeDef *) MCE4_REGION1_BASE_NS)
#define MCE4_REGION2_NS           ((MCE_Region_TypeDef *) MCE4_REGION2_BASE_NS)
#define MCE4_REGION3_NS           ((MCE_Region_TypeDef *) MCE4_REGION3_BASE_NS)
#define MCE4_REGION4_NS           ((MCE_Region_TypeDef *) MCE4_REGION4_BASE_NS)
#define MCE4_CONTEXT1_NS          ((MCE_Context_TypeDef *) MCE4_CONTEXT1_BASE_NS)
#define MCE4_CONTEXT2_NS          ((MCE_Context_TypeDef *) MCE4_CONTEXT2_BASE_NS)
#define MDF1_NS                   ((MDF_TypeDef *) MDF1_BASE_NS)
#define MDF1_Filter0_NS           ((MDF_Filter_TypeDef *) MDF1_Filter0_BASE_NS)
#define MDF1_Filter1_NS           ((MDF_Filter_TypeDef *) MDF1_Filter1_BASE_NS)
#define MDF1_Filter2_NS           ((MDF_Filter_TypeDef *) MDF1_Filter2_BASE_NS)
#define MDF1_Filter3_NS           ((MDF_Filter_TypeDef *) MDF1_Filter3_BASE_NS)
#define MDF1_Filter4_NS           ((MDF_Filter_TypeDef *) MDF1_Filter4_BASE_NS)
#define MDF1_Filter5_NS           ((MDF_Filter_TypeDef *) MDF1_Filter5_BASE_NS)
#define MDIOS_NS                  ((MDIOS_TypeDef *) MDIOS_BASE_NS)
#define PKA_NS                    ((PKA_TypeDef *) PKA_BASE_NS)
#define PSSI_NS                   ((PSSI_TypeDef *) PSSI_BASE_NS)
#define PWR_NS                    ((PWR_TypeDef *) PWR_BASE_NS)
#define RAMCFG_NS                 ((RAMCFG_TypeDef *) RAMCFG_BASE_NS)
#define RAMCFG_SRAM1_AXI_NS       ((RAMCFG_TypeDef *) RAMCFG_SRAM1_AXI_BASE_NS)
#define RAMCFG_SRAM2_AXI_NS       ((RAMCFG_TypeDef *) RAMCFG_SRAM2_AXI_BASE_NS)
#define RAMCFG_SRAM3_AXI_NS       ((RAMCFG_TypeDef *) RAMCFG_SRAM3_AXI_BASE_NS)
#define RAMCFG_SRAM4_AXI_NS       ((RAMCFG_TypeDef *) RAMCFG_SRAM4_AXI_BASE_NS)
#define RAMCFG_SRAM5_AXI_NS       ((RAMCFG_TypeDef *) RAMCFG_SRAM5_AXI_BASE_NS)
#define RAMCFG_SRAM6_AXI_NS       ((RAMCFG_TypeDef *) RAMCFG_SRAM6_AXI_BASE_NS)
#define RAMCFG_SRAM1_AHB_NS       ((RAMCFG_TypeDef *) RAMCFG_SRAM1_AHB_BASE_NS)
#define RAMCFG_SRAM2_AHB_NS       ((RAMCFG_TypeDef *) RAMCFG_SRAM2_AHB_BASE_NS)
#define RAMCFG_VENC_RAM_NS        ((RAMCFG_TypeDef *) RAMCFG_VENC_RAM_BASE_NS)
#define RAMCFG_BKPSRAM_NS         ((RAMCFG_TypeDef *) RAMCFG_BKPSRAM_BASE_NS)
#define RAMCFG_FLEXRAM_NS         ((RAMCFG_TypeDef *) RAMCFG_FLEXRAM_BASE_NS)
#define RCC_NS                    ((RCC_TypeDef *) RCC_BASE_NS)
#define RIFSC_NS                  ((RIFSC_TypeDef *) RIFSC_BASE_NS)
#define RISAF1_NS                 ((RISAF_TypeDef *) RISAF1_BASE_NS)
#define RISAF2_NS                 ((RISAF_TypeDef *) RISAF2_BASE_NS)
#define RISAF3_NS                 ((RISAF_TypeDef *) RISAF3_BASE_NS)
#define RISAF4_NS                 ((RISAF_TypeDef *) RISAF4_BASE_NS)
#define RISAF5_NS                 ((RISAF_TypeDef *) RISAF5_BASE_NS)
#define RISAF6_NS                 ((RISAF_TypeDef *) RISAF6_BASE_NS)
#define RISAF7_NS                 ((RISAF_TypeDef *) RISAF7_BASE_NS)
#define RISAF8_NS                 ((RISAF_TypeDef *) RISAF8_BASE_NS)
#define RISAF9_NS                 ((RISAF_TypeDef *) RISAF9_BASE_NS)
#define RISAF11_NS                ((RISAF_TypeDef *) RISAF11_BASE_NS)
#define RISAF12_NS                ((RISAF_TypeDef *) RISAF12_BASE_NS)
#define RISAF13_NS                ((RISAF_TypeDef *) RISAF13_BASE_NS)
#define RISAF14_NS                ((RISAF_TypeDef *) RISAF14_BASE_NS)
#define RISAF15_NS                ((RISAF_TypeDef *) RISAF15_BASE_NS)
#define RISAF21_NS                ((RISAF_TypeDef *) RISAF21_BASE_NS)
#define RISAF22_NS                ((RISAF_TypeDef *) RISAF22_BASE_NS)
#define RISAF23_NS                ((RISAF_TypeDef *) RISAF23_BASE_NS)
#define RNG_NS                    ((RNG_TypeDef *) RNG_BASE_NS)
#define RTC_NS                    ((RTC_TypeDef *) RTC_BASE_NS)
#define SAES_NS                   ((SAES_TypeDef *) SAES_BASE_NS)
#define SAI1_NS                   ((SAI_TypeDef *) SAI1_BASE_NS)
#define SAI1_Block_A_NS           ((SAI_Block_TypeDef *) SAI1_Block_A_BASE_NS)
#define SAI1_Block_B_NS           ((SAI_Block_TypeDef *) SAI1_Block_B_BASE_NS)
#define SAI2_NS                   ((SAI_TypeDef *) SAI2_BASE_NS)
#define SAI2_Block_A_NS           ((SAI_Block_TypeDef *) SAI2_Block_A_BASE_NS)
#define SAI2_Block_B_NS           ((SAI_Block_TypeDef *) SAI2_Block_B_BASE_NS)
#define SDMMC1_NS                 ((SDMMC_TypeDef *) SDMMC1_BASE_NS)
#define SDMMC2_NS                 ((SDMMC_TypeDef *) SDMMC2_BASE_NS)
#define SPDIFRX_NS                ((SPDIFRX_TypeDef *) SPDIFRX_BASE_NS)
#define SPI1_NS                   ((SPI_TypeDef *) SPI1_BASE_NS)
#define SPI2_NS                   ((SPI_TypeDef *) SPI2_BASE_NS)
#define SPI3_NS                   ((SPI_TypeDef *) SPI3_BASE_NS)
#define SPI4_NS                   ((SPI_TypeDef *) SPI4_BASE_NS)
#define SPI5_NS                   ((SPI_TypeDef *) SPI5_BASE_NS)
#define SPI6_NS                   ((SPI_TypeDef *) SPI6_BASE_NS)
#define SYSCFG_NS                 ((SYSCFG_TypeDef *) SYSCFG_BASE_NS)
#define TAMP_NS                   ((TAMP_TypeDef *) TAMP_BASE_NS)
#define TIM1_NS                   ((TIM_TypeDef *) TIM1_BASE_NS)
#define TIM2_NS                   ((TIM_TypeDef *) TIM2_BASE_NS)
#define TIM3_NS                   ((TIM_TypeDef *) TIM3_BASE_NS)
#define TIM4_NS                   ((TIM_TypeDef *) TIM4_BASE_NS)
#define TIM5_NS                   ((TIM_TypeDef *) TIM5_BASE_NS)
#define TIM6_NS                   ((TIM_TypeDef *) TIM6_BASE_NS)
#define TIM7_NS                   ((TIM_TypeDef *) TIM7_BASE_NS)
#define TIM8_NS                   ((TIM_TypeDef *) TIM8_BASE_NS)
#define TIM9_NS                   ((TIM_TypeDef *) TIM9_BASE_NS)
#define TIM10_NS                  ((TIM_TypeDef *) TIM10_BASE_NS)
#define TIM11_NS                  ((TIM_TypeDef *) TIM11_BASE_NS)
#define TIM12_NS                  ((TIM_TypeDef *) TIM12_BASE_NS)
#define TIM13_NS                  ((TIM_TypeDef *) TIM13_BASE_NS)
#define TIM14_NS                  ((TIM_TypeDef *) TIM14_BASE_NS)
#define TIM15_NS                  ((TIM_TypeDef *) TIM15_BASE_NS)
#define TIM16_NS                  ((TIM_TypeDef *) TIM16_BASE_NS)
#define TIM17_NS                  ((TIM_TypeDef *) TIM17_BASE_NS)
#define TIM18_NS                  ((TIM_TypeDef *) TIM18_BASE_NS)
#define UART4_NS                  ((USART_TypeDef *) UART4_BASE_NS)
#define UART5_NS                  ((USART_TypeDef *) UART5_BASE_NS)
#define UART7_NS                  ((USART_TypeDef *) UART7_BASE_NS)
#define UART8_NS                  ((USART_TypeDef *) UART8_BASE_NS)
#define UART9_NS                  ((USART_TypeDef *) UART9_BASE_NS)
#define UCPD1_NS                  ((UCPD_TypeDef *) UCPD1_BASE_NS)
#define USART1_NS                 ((USART_TypeDef *) USART1_BASE_NS)
#define USART2_NS                 ((USART_TypeDef *) USART2_BASE_NS)
#define USART3_NS                 ((USART_TypeDef *) USART3_BASE_NS)
#define USART6_NS                 ((USART_TypeDef *) USART6_BASE_NS)
#define USART10_NS                ((USART_TypeDef *) USART10_BASE_NS)
#define USB1_OTG_HS_NS            ((USB_OTG_GlobalTypeDef *) USB1_OTG_HS_BASE_NS)
#define USB2_OTG_HS_NS            ((USB_OTG_GlobalTypeDef *) USB2_OTG_HS_BASE_NS)
#define USB1_HS_PHYC_NS           ((USB_HS_PHYC_GlobalTypeDef *) USB1_HS_PHYC_BASE_NS)
#define USB2_HS_PHYC_NS           ((USB_HS_PHYC_GlobalTypeDef *) USB2_HS_PHYC_BASE_NS)
#define VENC_NS                   ((VENC_TypeDef *) VENC_BASE_NS)
#define VREFBUF_NS                ((VREFBUF_TypeDef *) VREFBUF_BASE_NS)
#define WWDG_NS                   ((WWDG_TypeDef *) WWDG_BASE_NS)
#define XSPI1_NS                  ((XSPI_TypeDef *) XSPI1_BASE_NS)
#define XSPI2_NS                  ((XSPI_TypeDef *) XSPI2_BASE_NS)
#define XSPI3_NS                  ((XSPI_TypeDef *) XSPI3_BASE_NS)
#define XSPIM_NS                  ((XSPIM_TypeDef *) XSPIM_BASE_NS)

#if defined (CPU_IN_SECURE_STATE)
#define ADC12_COMMON_S            ((ADC_Common_TypeDef *) ADC12_COMMON_BASE_S)
#define ADC1_S                    ((ADC_TypeDef *) ADC1_BASE_S)
#define ADC2_S                    ((ADC_TypeDef *) ADC2_BASE_S)
#define ADF1_S                    ((MDF_TypeDef *) ADF1_BASE_S)
#define ADF1_Filter0_S            ((MDF_Filter_TypeDef *) ADF1_Filter0_BASE_S)
#define BSEC_S                    ((BSEC_TypeDef *) BSEC_BASE_S)
#define CACHEAXI_S                ((CACHEAXI_TypeDef *) CACHEAXI_BASE_S)
#define CRC_S                     ((CRC_TypeDef *) CRC_BASE_S)
#define CRYP_S                    ((CRYP_TypeDef *) CRYP_BASE_S)
#define CSI_S                     ((CSI_TypeDef *) CSI_BASE_S)
#define DBGMCU_S                  ((DBGMCU_TypeDef *) DBGMCU_BASE_S)
#define DCMI_S                    ((DCMI_TypeDef *) DCMI_BASE_S)
#define DCMIPP_S                  ((DCMIPP_TypeDef *) DCMIPP_BASE_S)
#define DLYB_SDMMC1_S             ((DLYB_TypeDef *) DLYB_SDMMC1_BASE_S)
#define DLYB_SDMMC2_S             ((DLYB_TypeDef *) DLYB_SDMMC2_BASE_S)
#define DMA2D_S                   ((DMA2D_TypeDef *) DMA2D_BASE_S)
#define DTS_S                     ((DTS_TypeDef *) DTS_BASE_S)
#define DTS_Sensor0_S             ((DTS_SensorTypeDef *) DTS_Sensor0_BASE_S)
#define DTS_Sensor1_S             ((DTS_SensorTypeDef *) DTS_Sensor1_BASE_S)
#define ETH1_S                    ((ETH_TypeDef *) ETH1_BASE_S)
#define EXTI_S                    ((EXTI_TypeDef *) EXTI_BASE_S)
#define FDCAN1_S                  ((FDCAN_GlobalTypeDef *) FDCAN1_BASE_S)
#define FDCAN2_S                  ((FDCAN_GlobalTypeDef *) FDCAN2_BASE_S)
#define FDCAN3_S                  ((FDCAN_GlobalTypeDef *) FDCAN3_BASE_S)
#define FDCAN_CCU_S               ((FDCAN_ClockCalibrationUnit_TypeDef *) FDCAN_CCU_BASE_S)
#define FMC_Bank1E_R_S            ((FMC_Bank1E_TypeDef *) FMC_Bank1E_R_BASE_S)
#define FMC_Bank1_R_S             ((FMC_Bank1_TypeDef *) FMC_Bank1_R_BASE_S)
#define FMC_Bank3_R_S             ((FMC_Bank3_TypeDef *) FMC_Bank3_R_BASE_S)
#define FMC_Bank5_6_R_S           ((FMC_Bank5_6_TypeDef *) FMC_Bank5_6_R_BASE_S)
#define FMC_Common_R_S            ((FMC_Common_TypeDef *) FMC_Common_R_BASE_S)
#define GFXMMU_S                  ((GFXMMU_TypeDef *) GFXMMU_BASE_S)
#define GFXTIM_S                  ((GFXTIM_TypeDef *) GFXTIM_BASE_S)
#define GPDMA1_S                  ((DMA_TypeDef *) GPDMA1_BASE_S)
#define GPDMA1_Channel0_S         ((DMA_Channel_TypeDef *) GPDMA1_Channel0_BASE_S)
#define GPDMA1_Channel1_S         ((DMA_Channel_TypeDef *) GPDMA1_Channel1_BASE_S)
#define GPDMA1_Channel2_S         ((DMA_Channel_TypeDef *) GPDMA1_Channel2_BASE_S)
#define GPDMA1_Channel3_S         ((DMA_Channel_TypeDef *) GPDMA1_Channel3_BASE_S)
#define GPDMA1_Channel4_S         ((DMA_Channel_TypeDef *) GPDMA1_Channel4_BASE_S)
#define GPDMA1_Channel5_S         ((DMA_Channel_TypeDef *) GPDMA1_Channel5_BASE_S)
#define GPDMA1_Channel6_S         ((DMA_Channel_TypeDef *) GPDMA1_Channel6_BASE_S)
#define GPDMA1_Channel7_S         ((DMA_Channel_TypeDef *) GPDMA1_Channel7_BASE_S)
#define GPDMA1_Channel8_S         ((DMA_Channel_TypeDef *) GPDMA1_Channel8_BASE_S)
#define GPDMA1_Channel9_S         ((DMA_Channel_TypeDef *) GPDMA1_Channel9_BASE_S)
#define GPDMA1_Channel10_S        ((DMA_Channel_TypeDef *) GPDMA1_Channel10_BASE_S)
#define GPDMA1_Channel11_S        ((DMA_Channel_TypeDef *) GPDMA1_Channel11_BASE_S)
#define GPDMA1_Channel12_S        ((DMA_Channel_TypeDef *) GPDMA1_Channel12_BASE_S)
#define GPDMA1_Channel13_S        ((DMA_Channel_TypeDef *) GPDMA1_Channel13_BASE_S)
#define GPDMA1_Channel14_S        ((DMA_Channel_TypeDef *) GPDMA1_Channel14_BASE_S)
#define GPDMA1_Channel15_S        ((DMA_Channel_TypeDef *) GPDMA1_Channel15_BASE_S)
#define GPIOA_S                   ((GPIO_TypeDef *) GPIOA_BASE_S)
#define GPIOB_S                   ((GPIO_TypeDef *) GPIOB_BASE_S)
#define GPIOC_S                   ((GPIO_TypeDef *) GPIOC_BASE_S)
#define GPIOD_S                   ((GPIO_TypeDef *) GPIOD_BASE_S)
#define GPIOE_S                   ((GPIO_TypeDef *) GPIOE_BASE_S)
#define GPIOF_S                   ((GPIO_TypeDef *) GPIOF_BASE_S)
#define GPIOG_S                   ((GPIO_TypeDef *) GPIOG_BASE_S)
#define GPIOH_S                   ((GPIO_TypeDef *) GPIOH_BASE_S)
#define GPION_S                   ((GPIO_TypeDef *) GPION_BASE_S)
#define GPIOO_S                   ((GPIO_TypeDef *) GPIOO_BASE_S)
#define GPIOP_S                   ((GPIO_TypeDef *) GPIOP_BASE_S)
#define GPIOQ_S                   ((GPIO_TypeDef *) GPIOQ_BASE_S)
#define HASH_S                    ((HASH_TypeDef *) HASH_BASE_S)
#define HASH_DIGEST_S             ((HASH_DIGEST_TypeDef *) HASH_DIGEST_BASE_S)
#define HPDMA1_S                  ((DMA_TypeDef *) HPDMA1_BASE_S)
#define HPDMA1_Channel0_S         ((DMA_Channel_TypeDef *) HPDMA1_Channel0_BASE_S)
#define HPDMA1_Channel1_S         ((DMA_Channel_TypeDef *) HPDMA1_Channel1_BASE_S)
#define HPDMA1_Channel2_S         ((DMA_Channel_TypeDef *) HPDMA1_Channel2_BASE_S)
#define HPDMA1_Channel3_S         ((DMA_Channel_TypeDef *) HPDMA1_Channel3_BASE_S)
#define HPDMA1_Channel4_S         ((DMA_Channel_TypeDef *) HPDMA1_Channel4_BASE_S)
#define HPDMA1_Channel5_S         ((DMA_Channel_TypeDef *) HPDMA1_Channel5_BASE_S)
#define HPDMA1_Channel6_S         ((DMA_Channel_TypeDef *) HPDMA1_Channel6_BASE_S)
#define HPDMA1_Channel7_S         ((DMA_Channel_TypeDef *) HPDMA1_Channel7_BASE_S)
#define HPDMA1_Channel8_S         ((DMA_Channel_TypeDef *) HPDMA1_Channel8_BASE_S)
#define HPDMA1_Channel9_S         ((DMA_Channel_TypeDef *) HPDMA1_Channel9_BASE_S)
#define HPDMA1_Channel10_S        ((DMA_Channel_TypeDef *) HPDMA1_Channel10_BASE_S)
#define HPDMA1_Channel11_S        ((DMA_Channel_TypeDef *) HPDMA1_Channel11_BASE_S)
#define HPDMA1_Channel12_S        ((DMA_Channel_TypeDef *) HPDMA1_Channel12_BASE_S)
#define HPDMA1_Channel13_S        ((DMA_Channel_TypeDef *) HPDMA1_Channel13_BASE_S)
#define HPDMA1_Channel14_S        ((DMA_Channel_TypeDef *) HPDMA1_Channel14_BASE_S)
#define HPDMA1_Channel15_S        ((DMA_Channel_TypeDef *) HPDMA1_Channel15_BASE_S)
#define I2C1_S                    ((I2C_TypeDef *) I2C1_BASE_S)
#define I2C2_S                    ((I2C_TypeDef *) I2C2_BASE_S)
#define I2C3_S                    ((I2C_TypeDef *) I2C3_BASE_S)
#define I2C4_S                    ((I2C_TypeDef *) I2C4_BASE_S)
#define I3C1_S                    ((I3C_TypeDef *) I3C1_BASE_S)
#define I3C2_S                    ((I3C_TypeDef *) I3C2_BASE_S)
#define IAC_S                     ((IAC_TypeDef *) IAC_BASE_S)
#define ICACHE_S                  ((ICACHE_TypeDef *) ICACHE_BASE_S)
#define IWDG_S                    ((IWDG_TypeDef *) IWDG_BASE_S)
#define JPEG_S                    ((JPEG_TypeDef *) JPEG_BASE_S)
#define LPTIM1_S                  ((LPTIM_TypeDef *) LPTIM1_BASE_S)
#define LPTIM2_S                  ((LPTIM_TypeDef *) LPTIM2_BASE_S)
#define LPTIM3_S                  ((LPTIM_TypeDef *) LPTIM3_BASE_S)
#define LPTIM4_S                  ((LPTIM_TypeDef *) LPTIM4_BASE_S)
#define LPTIM5_S                  ((LPTIM_TypeDef *) LPTIM5_BASE_S)
#define LPUART1_S                 ((USART_TypeDef *) LPUART1_BASE_S)
#define LTDC_S                    ((LTDC_TypeDef *)LTDC_BASE_S)
#define LTDC_Layer1_S             ((LTDC_Layer_TypeDef *)LTDC_Layer1_BASE_S)
#define LTDC_Layer2_S             ((LTDC_Layer_TypeDef *)LTDC_Layer2_BASE_S)
#define MCE1_S                    ((MCE_TypeDef *) MCE1_BASE_S)
#define MCE1_REGION1_S            ((MCE_Region_TypeDef *) MCE1_REGION1_BASE_S)
#define MCE1_REGION2_S            ((MCE_Region_TypeDef *) MCE1_REGION2_BASE_S)
#define MCE1_REGION3_S            ((MCE_Region_TypeDef *) MCE1_REGION3_BASE_S)
#define MCE1_REGION4_S            ((MCE_Region_TypeDef *) MCE1_REGION4_BASE_S)
#define MCE1_CONTEXT1_S           ((MCE_Context_TypeDef *) MCE1_CONTEXT1_BASE_S)
#define MCE1_CONTEXT2_S           ((MCE_Context_TypeDef *) MCE1_CONTEXT2_BASE_S)
#define MCE2_S                    ((MCE_TypeDef *) MCE2_BASE_S)
#define MCE2_REGION1_S            ((MCE_Region_TypeDef *) MCE2_REGION1_BASE_S)
#define MCE2_REGION2_S            ((MCE_Region_TypeDef *) MCE2_REGION2_BASE_S)
#define MCE2_REGION3_S            ((MCE_Region_TypeDef *) MCE2_REGION3_BASE_S)
#define MCE2_REGION4_S            ((MCE_Region_TypeDef *) MCE2_REGION4_BASE_S)
#define MCE2_CONTEXT1_S           ((MCE_Context_TypeDef *) MCE2_CONTEXT1_BASE_S)
#define MCE2_CONTEXT2_S           ((MCE_Context_TypeDef *) MCE2_CONTEXT2_BASE_S)
#define MCE3_S                    ((MCE_TypeDef *) MCE3_BASE_S)
#define MCE3_REGION1_S            ((MCE_Region_TypeDef *) MCE3_REGION1_BASE_S)
#define MCE3_REGION2_S            ((MCE_Region_TypeDef *) MCE3_REGION2_BASE_S)
#define MCE3_REGION3_S            ((MCE_Region_TypeDef *) MCE3_REGION3_BASE_S)
#define MCE3_REGION4_S            ((MCE_Region_TypeDef *) MCE3_REGION4_BASE_S)
#define MCE3_CONTEXT1_S           ((MCE_Context_TypeDef *) MCE3_CONTEXT1_BASE_S)
#define MCE3_CONTEXT2_S           ((MCE_Context_TypeDef *) MCE3_CONTEXT2_BASE_S)
#define MCE4_S                    ((MCE_TypeDef *) MCE4_BASE_S)
#define MCE4_REGION1_S            ((MCE_Region_TypeDef *) MCE4_REGION1_BASE_S)
#define MCE4_REGION2_S            ((MCE_Region_TypeDef *) MCE4_REGION2_BASE_S)
#define MCE4_REGION3_S            ((MCE_Region_TypeDef *) MCE4_REGION3_BASE_S)
#define MCE4_REGION4_S            ((MCE_Region_TypeDef *) MCE4_REGION4_BASE_S)
#define MCE4_CONTEXT1_S           ((MCE_Context_TypeDef *) MCE4_CONTEXT1_BASE_S)
#define MCE4_CONTEXT2_S           ((MCE_Context_TypeDef *) MCE4_CONTEXT2_BASE_S)
#define MDF1_S                    ((MDF_TypeDef *) MDF1_BASE_S)
#define MDF1_Filter0_S            ((MDF_Filter_TypeDef *) MDF1_Filter0_BASE_S)
#define MDF1_Filter1_S            ((MDF_Filter_TypeDef *) MDF1_Filter1_BASE_S)
#define MDF1_Filter2_S            ((MDF_Filter_TypeDef *) MDF1_Filter2_BASE_S)
#define MDF1_Filter3_S            ((MDF_Filter_TypeDef *) MDF1_Filter3_BASE_S)
#define MDF1_Filter4_S            ((MDF_Filter_TypeDef *) MDF1_Filter4_BASE_S)
#define MDF1_Filter5_S            ((MDF_Filter_TypeDef *) MDF1_Filter5_BASE_S)
#define MDIOS_S                   ((MDIOS_TypeDef *) MDIOS_BASE_S)
#define PKA_S                     ((PKA_TypeDef *) PKA_BASE_S)
#define PSSI_S                    ((PSSI_TypeDef *) PSSI_BASE_S)
#define PWR_S                     ((PWR_TypeDef *) PWR_BASE_S)
#define RAMCFG_S                  ((RAMCFG_TypeDef *) RAMCFG_BASE_S)
#define RAMCFG_SRAM1_AXI_S        ((RAMCFG_TypeDef *) RAMCFG_SRAM1_AXI_BASE_S)
#define RAMCFG_SRAM2_AXI_S        ((RAMCFG_TypeDef *) RAMCFG_SRAM2_AXI_BASE_S)
#define RAMCFG_SRAM3_AXI_S        ((RAMCFG_TypeDef *) RAMCFG_SRAM3_AXI_BASE_S)
#define RAMCFG_SRAM4_AXI_S        ((RAMCFG_TypeDef *) RAMCFG_SRAM4_AXI_BASE_S)
#define RAMCFG_SRAM5_AXI_S        ((RAMCFG_TypeDef *) RAMCFG_SRAM5_AXI_BASE_S)
#define RAMCFG_SRAM6_AXI_S        ((RAMCFG_TypeDef *) RAMCFG_SRAM6_AXI_BASE_S)
#define RAMCFG_SRAM1_AHB_S        ((RAMCFG_TypeDef *) RAMCFG_SRAM1_AHB_BASE_S)
#define RAMCFG_SRAM2_AHB_S        ((RAMCFG_TypeDef *) RAMCFG_SRAM2_AHB_BASE_S)
#define RAMCFG_VENC_RAM_S         ((RAMCFG_TypeDef *) RAMCFG_VENC_RAM_BASE_NS)
#define RAMCFG_BKPSRAM_S          ((RAMCFG_TypeDef *) RAMCFG_BKPSRAM_BASE_S)
#define RAMCFG_FLEXRAM_S          ((RAMCFG_TypeDef *) RAMCFG_FLEXRAM_BASE_S)
#define RCC_S                     ((RCC_TypeDef *) RCC_BASE_S)
#define RIFSC_S                   ((RIFSC_TypeDef *) RIFSC_BASE_S)
#define RISAF1_S                  ((RISAF_TypeDef *) RISAF1_BASE_S)
#define RISAF2_S                  ((RISAF_TypeDef *) RISAF2_BASE_S)
#define RISAF3_S                  ((RISAF_TypeDef *) RISAF3_BASE_S)
#define RISAF4_S                  ((RISAF_TypeDef *) RISAF4_BASE_S)
#define RISAF5_S                  ((RISAF_TypeDef *) RISAF5_BASE_S)
#define RISAF6_S                  ((RISAF_TypeDef *) RISAF6_BASE_S)
#define RISAF7_S                  ((RISAF_TypeDef *) RISAF7_BASE_S)
#define RISAF8_S                  ((RISAF_TypeDef *) RISAF8_BASE_S)
#define RISAF9_S                  ((RISAF_TypeDef *) RISAF9_BASE_S)
#define RISAF11_S                 ((RISAF_TypeDef *) RISAF11_BASE_S)
#define RISAF12_S                 ((RISAF_TypeDef *) RISAF12_BASE_S)
#define RISAF13_S                 ((RISAF_TypeDef *) RISAF13_BASE_S)
#define RISAF14_S                 ((RISAF_TypeDef *) RISAF14_BASE_S)
#define RISAF15_S                 ((RISAF_TypeDef *) RISAF15_BASE_S)
#define RISAF21_S                 ((RISAF_TypeDef *) RISAF21_BASE_S)
#define RISAF22_S                 ((RISAF_TypeDef *) RISAF22_BASE_S)
#define RISAF23_S                 ((RISAF_TypeDef *) RISAF23_BASE_S)
#define RNG_S                     ((RNG_TypeDef *) RNG_BASE_S)
#define RTC_S                     ((RTC_TypeDef *) RTC_BASE_S)
#define SAES_S                    ((SAES_TypeDef *) SAES_BASE_S)
#define SAI1_S                    ((SAI_TypeDef *) SAI1_BASE_S)
#define SAI1_Block_A_S            ((SAI_Block_TypeDef *) SAI1_Block_A_BASE_S)
#define SAI1_Block_B_S            ((SAI_Block_TypeDef *) SAI1_Block_B_BASE_S)
#define SAI2_S                    ((SAI_TypeDef *) SAI2_BASE_S)
#define SAI2_Block_A_S            ((SAI_Block_TypeDef *) SAI2_Block_A_BASE_S)
#define SAI2_Block_B_S            ((SAI_Block_TypeDef *) SAI2_Block_B_BASE_S)
#define SDMMC1_S                  ((SDMMC_TypeDef *) SDMMC1_BASE_S)
#define SDMMC2_S                  ((SDMMC_TypeDef *) SDMMC2_BASE_S)
#define SPDIFRX_S                 ((SPDIFRX_TypeDef *) SPDIFRX_BASE_S)
#define SPI1_S                    ((SPI_TypeDef *) SPI1_BASE_S)
#define SPI2_S                    ((SPI_TypeDef *) SPI2_BASE_S)
#define SPI3_S                    ((SPI_TypeDef *) SPI3_BASE_S)
#define SPI4_S                    ((SPI_TypeDef *) SPI4_BASE_S)
#define SPI5_S                    ((SPI_TypeDef *) SPI5_BASE_S)
#define SPI6_S                    ((SPI_TypeDef *) SPI6_BASE_S)
#define SYSCFG_S                  ((SYSCFG_TypeDef *) SYSCFG_BASE_S)
#define TAMP_S                    ((TAMP_TypeDef *) TAMP_BASE_S)
#define TIM1_S                    ((TIM_TypeDef *) TIM1_BASE_S)
#define TIM2_S                    ((TIM_TypeDef *) TIM2_BASE_S)
#define TIM3_S                    ((TIM_TypeDef *) TIM3_BASE_S)
#define TIM4_S                    ((TIM_TypeDef *) TIM4_BASE_S)
#define TIM5_S                    ((TIM_TypeDef *) TIM5_BASE_S)
#define TIM6_S                    ((TIM_TypeDef *) TIM6_BASE_S)
#define TIM7_S                    ((TIM_TypeDef *) TIM7_BASE_S)
#define TIM8_S                    ((TIM_TypeDef *) TIM8_BASE_S)
#define TIM9_S                    ((TIM_TypeDef *) TIM9_BASE_S)
#define TIM10_S                   ((TIM_TypeDef *) TIM10_BASE_S)
#define TIM11_S                   ((TIM_TypeDef *) TIM11_BASE_S)
#define TIM12_S                   ((TIM_TypeDef *) TIM12_BASE_S)
#define TIM13_S                   ((TIM_TypeDef *) TIM13_BASE_S)
#define TIM14_S                   ((TIM_TypeDef *) TIM14_BASE_S)
#define TIM15_S                   ((TIM_TypeDef *) TIM15_BASE_S)
#define TIM16_S                   ((TIM_TypeDef *) TIM16_BASE_S)
#define TIM17_S                   ((TIM_TypeDef *) TIM17_BASE_S)
#define TIM18_S                   ((TIM_TypeDef *) TIM18_BASE_S)
#define UART4_S                   ((USART_TypeDef *) UART4_BASE_S)
#define UART5_S                   ((USART_TypeDef *) UART5_BASE_S)
#define UART7_S                   ((USART_TypeDef *) UART7_BASE_S)
#define UART8_S                   ((USART_TypeDef *) UART8_BASE_S)
#define UART9_S                   ((USART_TypeDef *) UART9_BASE_S)
#define UCPD1_S                   ((UCPD_TypeDef *) UCPD1_BASE_S)
#define USART1_S                  ((USART_TypeDef *) USART1_BASE_S)
#define USART2_S                  ((USART_TypeDef *) USART2_BASE_S)
#define USART3_S                  ((USART_TypeDef *) USART3_BASE_S)
#define USART6_S                  ((USART_TypeDef *) USART6_BASE_S)
#define USART10_S                 ((USART_TypeDef *) USART10_BASE_S)
#define USB1_OTG_HS_S             ((USB_OTG_GlobalTypeDef *) USB1_OTG_HS_BASE_S)
#define USB2_OTG_HS_S             ((USB_OTG_GlobalTypeDef *) USB2_OTG_HS_BASE_S)
#define USB1_HS_PHYC_S            ((USB_HS_PHYC_GlobalTypeDef *) USB1_HS_PHYC_BASE_S)
#define USB2_HS_PHYC_S            ((USB_HS_PHYC_GlobalTypeDef *) USB2_HS_PHYC_BASE_S)
#define VENC_S                    ((VENC_TypeDef *) VENC_BASE_S)
#define VREFBUF_S                 ((VREFBUF_TypeDef *) VREFBUF_BASE_S)
#define WWDG_S                    ((WWDG_TypeDef *) WWDG_BASE_S)
#define XSPI1_S                   ((XSPI_TypeDef *) XSPI1_BASE_S)
#define XSPI2_S                   ((XSPI_TypeDef *) XSPI2_BASE_S)
#define XSPI3_S                   ((XSPI_TypeDef *) XSPI3_BASE_S)
#define XSPIM_S                   ((XSPIM_TypeDef *) XSPIM_BASE_S)
#endif

/*!< Peripheral Instance aliases for Non-Secure/Secure execution  */
#if defined (CPU_IN_SECURE_STATE)
#define ADC12_COMMON              ADC12_COMMON_S
#define ADC12_COMMON_BASE         ADC12_COMMON_BASE_S

#define ADC1                      ADC1_S
#define ADC1_BASE                 ADC1_BASE_S

#define ADC2                      ADC2_S
#define ADC2_BASE                 ADC2_BASE_S

#define ADF1                      ADF1_S
#define ADF1_BASE                 ADF1_BASE_S

#define ADF1_Filter0              ADF1_Filter0_S
#define ADF1_Filter0_BASE         ADF1_Filter0_BASE_S

#define BSEC                      BSEC_S
#define BSEC_BASE                 BSEC_BASE_S

#define CACHEAXI                  CACHEAXI_S
#define CACHEAXI_BASE             CACHEAXI_BASE_S

#define CRC                       CRC_S
#define CRC_BASE                  CRC_BASE_S

#define CRYP                      CRYP_S
#define CRYP_BASE                 CRYP_BASE_S

#define CSI                       CSI_S
#define CSI_BASE                  CSI_BASE_S

#define DBGMCU                    DBGMCU_S
#define DBGMCU_BASE               DBGMCU_BASE_S

#define DCMI                      DCMI_S
#define DCMI_BASE                 DCMI_BASE_S

#define DCMIPP                    DCMIPP_S
#define DCMIPP_BASE               DCMIPP_BASE_S

#define DLYB_SDMMC1               DLYB_SDMMC1_S
#define DLYB_SDMMC1_BASE          DLYB_SDMMC1_BASE_S

#define DLYB_SDMMC2               DLYB_SDMMC2_S
#define DLYB_SDMMC2_BASE          DLYB_SDMMC2_BASE_S

#define DMA2D                     DMA2D_S
#define DMA2D_BASE                DMA2D_BASE_S

#define DTS                       DTS_S
#define DTS_BASE                  DTS_BASE_S

#define DTS_Sensor0               DTS_Sensor0_S
#define DTS_Sensor0_BASE          DTS_Sensor0_BASE_S

#define DTS_Sensor1               DTS_Sensor1_S
#define DTS_Sensor1_BASE          DTS_Sensor1_BASE_S

#define ETH1                      ETH1_S
#define ETH1_BASE                 ETH1_BASE_S

#define EXTI                      EXTI_S
#define EXTI_BASE                 EXTI_BASE_S

#define FDCAN1                    FDCAN1_S
#define FDCAN1_BASE               FDCAN1_BASE_S

#define FDCAN2                    FDCAN2_S
#define FDCAN2_BASE               FDCAN2_BASE_S

#define FDCAN3                    FDCAN3_S
#define FDCAN3_BASE               FDCAN3_BASE_S

#define FDCAN_CCU                 FDCAN_CCU_S
#define FDCAN_CCU_BASE            FDCAN_CCU_BASE_S

#define FMC_R_BASE                FMC_R_BASE_S

#define FMC_Bank1E_R              FMC_Bank1E_R_S
#define FMC_Bank1E_R_BASE         FMC_Bank1E_R_BASE_S

#define FMC_Bank1_R               FMC_Bank1_R_S
#define FMC_Bank1_R_BASE          FMC_Bank1_R_BASE_S

#define FMC_Bank3_R               FMC_Bank3_R_S
#define FMC_Bank3_R_BASE          FMC_Bank3_R_BASE_S

#define FMC_Bank5_6_R             FMC_Bank5_6_R_S
#define FMC_Bank5_6_R_BASE        FMC_Bank5_6_R_BASE_S

#define FMC_Common_R              FMC_Common_R_S
#define FMC_Common_R_BASE         FMC_Common_R_BASE_S

#define GFXMMU                       GFXMMU_S
#define GFXMMU_BASE                  GFXMMU_BASE_S
#define GFXMMU_VIRTUAL_BUFFER0_BASE  GFXMMU_VIRTUAL_BUFFER0_BASE_S
#define GFXMMU_VIRTUAL_BUFFER1_BASE  GFXMMU_VIRTUAL_BUFFER1_BASE_S
#define GFXMMU_VIRTUAL_BUFFER2_BASE  GFXMMU_VIRTUAL_BUFFER2_BASE_S
#define GFXMMU_VIRTUAL_BUFFER3_BASE  GFXMMU_VIRTUAL_BUFFER3_BASE_S

#define GFXTIM                    GFXTIM_S
#define GFXTIM_BASE               GFXTIM_BASE_S

#define GPDMA1                    GPDMA1_S
#define GPDMA1_BASE               GPDMA1_BASE_S

#define GPDMA1_Channel0           GPDMA1_Channel0_S
#define GPDMA1_Channel0_BASE      GPDMA1_Channel0_BASE_S

#define GPDMA1_Channel1           GPDMA1_Channel1_S
#define GPDMA1_Channel1_BASE      GPDMA1_Channel1_BASE_S

#define GPDMA1_Channel2           GPDMA1_Channel2_S
#define GPDMA1_Channel2_BASE      GPDMA1_Channel2_BASE_S

#define GPDMA1_Channel3           GPDMA1_Channel3_S
#define GPDMA1_Channel3_BASE      GPDMA1_Channel3_BASE_S

#define GPDMA1_Channel4           GPDMA1_Channel4_S
#define GPDMA1_Channel4_BASE      GPDMA1_Channel4_BASE_S

#define GPDMA1_Channel5           GPDMA1_Channel5_S
#define GPDMA1_Channel5_BASE      GPDMA1_Channel5_BASE_S

#define GPDMA1_Channel6           GPDMA1_Channel6_S
#define GPDMA1_Channel6_BASE      GPDMA1_Channel6_BASE_S

#define GPDMA1_Channel7           GPDMA1_Channel7_S
#define GPDMA1_Channel7_BASE      GPDMA1_Channel7_BASE_S

#define GPDMA1_Channel8           GPDMA1_Channel8_S
#define GPDMA1_Channel8_BASE      GPDMA1_Channel8_BASE_S

#define GPDMA1_Channel9           GPDMA1_Channel9_S
#define GPDMA1_Channel9_BASE      GPDMA1_Channel9_BASE_S

#define GPDMA1_Channel10          GPDMA1_Channel10_S
#define GPDMA1_Channel10_BASE     GPDMA1_Channel10_BASE_S

#define GPDMA1_Channel11          GPDMA1_Channel11_S
#define GPDMA1_Channel11_BASE     GPDMA1_Channel11_BASE_S

#define GPDMA1_Channel12          GPDMA1_Channel12_S
#define GPDMA1_Channel12_BASE     GPDMA1_Channel12_BASE_S

#define GPDMA1_Channel13          GPDMA1_Channel13_S
#define GPDMA1_Channel13_BASE     GPDMA1_Channel13_BASE_S

#define GPDMA1_Channel14          GPDMA1_Channel14_S
#define GPDMA1_Channel14_BASE     GPDMA1_Channel14_BASE_S

#define GPDMA1_Channel15          GPDMA1_Channel15_S
#define GPDMA1_Channel15_BASE     GPDMA1_Channel15_BASE_S

#define GPIOA                     GPIOA_S
#define GPIOA_BASE                GPIOA_BASE_S

#define GPIOB                     GPIOB_S
#define GPIOB_BASE                GPIOB_BASE_S

#define GPIOC                     GPIOC_S
#define GPIOC_BASE                GPIOC_BASE_S

#define GPIOD                     GPIOD_S
#define GPIOD_BASE                GPIOD_BASE_S

#define GPIOE                     GPIOE_S
#define GPIOE_BASE                GPIOE_BASE_S

#define GPIOF                     GPIOF_S
#define GPIOF_BASE                GPIOF_BASE_S

#define GPIOG                     GPIOG_S
#define GPIOG_BASE                GPIOG_BASE_S

#define GPIOH                     GPIOH_S
#define GPIOH_BASE                GPIOH_BASE_S

#define GPION                     GPION_S
#define GPION_BASE                GPION_BASE_S

#define GPIOO                     GPIOO_S
#define GPIOO_BASE                GPIOO_BASE_S

#define GPIOP                     GPIOP_S
#define GPIOP_BASE                GPIOP_BASE_S

#define GPIOQ                     GPIOQ_S
#define GPIOQ_BASE                GPIOQ_BASE_S

#define GPU2D                     GPU2D_BASE_S
#define GPU2D_BASE                GPU2D_BASE_S

#define HASH                      HASH_S
#define HASH_BASE                 HASH_BASE_S

#define HASH_DIGEST               HASH_DIGEST_S
#define HASH_DIGEST_BASE          HASH_DIGEST_BASE_S

#define HPDMA1                    HPDMA1_S
#define HPDMA1_BASE               HPDMA1_BASE_S

#define HPDMA1_Channel0           HPDMA1_Channel0_S
#define HPDMA1_Channel0_BASE      HPDMA1_Channel0_BASE_S

#define HPDMA1_Channel1           HPDMA1_Channel1_S
#define HPDMA1_Channel1_BASE      HPDMA1_Channel1_BASE_S

#define HPDMA1_Channel2           HPDMA1_Channel2_S
#define HPDMA1_Channel2_BASE      HPDMA1_Channel2_BASE_S

#define HPDMA1_Channel3           HPDMA1_Channel3_S
#define HPDMA1_Channel3_BASE      HPDMA1_Channel3_BASE_S

#define HPDMA1_Channel4           HPDMA1_Channel4_S
#define HPDMA1_Channel4_BASE      HPDMA1_Channel4_BASE_S

#define HPDMA1_Channel5           HPDMA1_Channel5_S
#define HPDMA1_Channel5_BASE      HPDMA1_Channel5_BASE_S

#define HPDMA1_Channel6           HPDMA1_Channel6_S
#define HPDMA1_Channel6_BASE      HPDMA1_Channel6_BASE_S

#define HPDMA1_Channel7           HPDMA1_Channel7_S
#define HPDMA1_Channel7_BASE      HPDMA1_Channel7_BASE_S

#define HPDMA1_Channel8           HPDMA1_Channel8_S
#define HPDMA1_Channel8_BASE      HPDMA1_Channel8_BASE_S

#define HPDMA1_Channel9           HPDMA1_Channel9_S
#define HPDMA1_Channel9_BASE      HPDMA1_Channel9_BASE_S

#define HPDMA1_Channel10          HPDMA1_Channel10_S
#define HPDMA1_Channel10_BASE     HPDMA1_Channel10_BASE_S

#define HPDMA1_Channel11          HPDMA1_Channel11_S
#define HPDMA1_Channel11_BASE     HPDMA1_Channel11_BASE_S

#define HPDMA1_Channel12          HPDMA1_Channel12_S
#define HPDMA1_Channel12_BASE     HPDMA1_Channel12_BASE_S

#define HPDMA1_Channel13          HPDMA1_Channel13_S
#define HPDMA1_Channel13_BASE     HPDMA1_Channel13_BASE_S

#define HPDMA1_Channel14          HPDMA1_Channel14_S
#define HPDMA1_Channel14_BASE     HPDMA1_Channel14_BASE_S

#define HPDMA1_Channel15          HPDMA1_Channel15_S
#define HPDMA1_Channel15_BASE     HPDMA1_Channel15_BASE_S

#define I2C1                      I2C1_S
#define I2C1_BASE                 I2C1_BASE_S

#define I2C2                      I2C2_S
#define I2C2_BASE                 I2C2_BASE_S

#define I2C3                      I2C3_S
#define I2C3_BASE                 I2C3_BASE_S

#define I2C4                      I2C4_S
#define I2C4_BASE                 I2C4_BASE_S

#define I3C1                      I3C1_S
#define I3C1_BASE                 I3C1_BASE_S

#define I3C2                      I3C2_S
#define I3C2_BASE                 I3C2_BASE_S

#define IAC                       IAC_S
#define IAC_BASE                  IAC_BASE_S

#define ICACHE                    ICACHE_S
#define ICACHE_BASE               ICACHE_BASE_S

#define IWDG                      IWDG_S
#define IWDG_BASE                 IWDG_BASE_S

#define JPEG                      JPEG_S
#define JPEG_BASE                 JPEG_BASE_S

#define LPTIM1                    LPTIM1_S
#define LPTIM1_BASE               LPTIM1_BASE_S

#define LPTIM2                    LPTIM2_S
#define LPTIM2_BASE               LPTIM2_BASE_S

#define LPTIM3                    LPTIM3_S
#define LPTIM3_BASE               LPTIM3_BASE_S

#define LPTIM4                    LPTIM4_S
#define LPTIM4_BASE               LPTIM4_BASE_S

#define LPTIM5                    LPTIM5_S
#define LPTIM5_BASE               LPTIM5_BASE_S

#define LPUART1                   LPUART1_S
#define LPUART1_BASE              LPUART1_BASE_S

#define LTDC                      LTDC_S
#define LTDC_BASE                 LTDC_BASE_S

#define LTDC_Layer1               LTDC_Layer1_S
#define LTDC_Layer1_BASE          LTDC_Layer1_BASE_S

#define LTDC_Layer2               LTDC_Layer2_S
#define LTDC_Layer2_BASE          LTDC_Layer2_BASE_S

#define MCE1                      MCE1_S
#define MCE1_BASE                 MCE1_BASE_S

#define MCE1_REGION1              MCE1_REGION1_S
#define MCE1_REGION1_BASE         MCE1_REGION1_BASE_S

#define MCE1_REGION2              MCE1_REGION2_S
#define MCE1_REGION2_BASE         MCE1_REGION2_BASE_S

#define MCE1_REGION3              MCE1_REGION3_S
#define MCE1_REGION3_BASE         MCE1_REGION3_BASE_S

#define MCE1_REGION4              MCE1_REGION4_S
#define MCE1_REGION4_BASE         MCE1_REGION4_BASE_S

#define MCE1_CONTEXT1             MCE1_CONTEXT1_S
#define MCE1_CONTEXT1_BASE        MCE1_CONTEXT1_BASE_S

#define MCE1_CONTEXT2             MCE1_CONTEXT2_S
#define MCE1_CONTEXT2_BASE        MCE1_CONTEXT2_BASE_S

#define MCE2                      MCE2_S
#define MCE2_BASE                 MCE2_BASE_S

#define MCE2_REGION1              MCE2_REGION1_S
#define MCE2_REGION1_BASE         MCE2_REGION1_BASE_S

#define MCE2_REGION2              MCE2_REGION2_S
#define MCE2_REGION2_BASE         MCE2_REGION2_BASE_S

#define MCE2_REGION3              MCE2_REGION3_S
#define MCE2_REGION3_BASE         MCE2_REGION3_BASE_S

#define MCE2_REGION4              MCE2_REGION4_S
#define MCE2_REGION4_BASE         MCE2_REGION4_BASE_S

#define MCE2_CONTEXT1             MCE2_CONTEXT1_S
#define MCE2_CONTEXT1_BASE        MCE2_CONTEXT1_BASE_S

#define MCE2_CONTEXT2             MCE2_CONTEXT2_S
#define MCE2_CONTEXT2_BASE        MCE2_CONTEXT2_BASE_S

#define MCE3                      MCE3_S
#define MCE3_BASE                 MCE3_BASE_S

#define MCE3_REGION1              MCE3_REGION1_S
#define MCE3_REGION1_BASE         MCE3_REGION1_BASE_S

#define MCE3_REGION2              MCE3_REGION2_S
#define MCE3_REGION2_BASE         MCE3_REGION2_BASE_S

#define MCE3_REGION3              MCE3_REGION3_S
#define MCE3_REGION3_BASE         MCE3_REGION3_BASE_S

#define MCE3_REGION4              MCE3_REGION4_S
#define MCE3_REGION4_BASE         MCE3_REGION4_BASE_S

#define MCE3_CONTEXT1             MCE3_CONTEXT1_S
#define MCE3_CONTEXT1_BASE        MCE3_CONTEXT1_BASE_S

#define MCE3_CONTEXT2             MCE3_CONTEXT2_S
#define MCE3_CONTEXT2_BASE        MCE3_CONTEXT2_BASE_S

#define MCE4                      MCE4_S
#define MCE4_BASE                 MCE4_BASE_S

#define MCE4_REGION1              MCE4_REGION1_S
#define MCE4_REGION1_BASE         MCE4_REGION1_BASE_S

#define MCE4_REGION2              MCE4_REGION2_S
#define MCE4_REGION2_BASE         MCE4_REGION2_BASE_S

#define MCE4_REGION3              MCE4_REGION3_S
#define MCE4_REGION3_BASE         MCE4_REGION3_BASE_S

#define MCE4_REGION4              MCE4_REGION4_S
#define MCE4_REGION4_BASE         MCE4_REGION4_BASE_S

#define MCE4_CONTEXT1             MCE4_CONTEXT1_S
#define MCE4_CONTEXT1_BASE        MCE4_CONTEXT1_BASE_S

#define MCE4_CONTEXT2             MCE4_CONTEXT2_S
#define MCE4_CONTEXT2_BASE        MCE4_CONTEXT2_BASE_S

#define MDF1                      MDF1_S
#define MDF1_BASE                 MDF1_BASE_S

#define MDF1_Filter0              MDF1_Filter0_S
#define MDF1_Filter0_BASE         MDF1_Filter0_BASE_S

#define MDF1_Filter1              MDF1_Filter1_S
#define MDF1_Filter1_BASE         MDF1_Filter1_BASE_S

#define MDF1_Filter2              MDF1_Filter2_S
#define MDF1_Filter2_BASE         MDF1_Filter2_BASE_S

#define MDF1_Filter3              MDF1_Filter3_S
#define MDF1_Filter3_BASE         MDF1_Filter3_BASE_S

#define MDF1_Filter4              MDF1_Filter4_S
#define MDF1_Filter4_BASE         MDF1_Filter4_BASE_S

#define MDF1_Filter5              MDF1_Filter5_S
#define MDF1_Filter5_BASE         MDF1_Filter5_BASE_S

#define MDIOS                     MDIOS_S
#define MDIOS_BASE                MDIOS_BASE_S

#define NPU_PRESENT
#define NPU_BASE                  NPU_BASE_S

#define PKA                       PKA_S
#define PKA_BASE                  PKA_BASE_S

#define PSSI                      PSSI_S
#define PSSI_BASE                 PSSI_BASE_S

#define PWR                       PWR_S
#define PWR_BASE                  PWR_BASE_S

#define RAMCFG                    RAMCFG_S
#define RAMCFG_BASE               RAMCFG_BASE_S

#define RAMCFG_SRAM1_AXI          RAMCFG_SRAM1_AXI_S
#define RAMCFG_SRAM1_AXI_BASE     RAMCFG_SRAM1_AXI_BASE_S

#define RAMCFG_SRAM2_AXI          RAMCFG_SRAM2_AXI_S
#define RAMCFG_SRAM2_AXI_BASE     RAMCFG_SRAM2_AXI_BASE_S

#define RAMCFG_SRAM3_AXI          RAMCFG_SRAM3_AXI_S
#define RAMCFG_SRAM3_AXI_BASE     RAMCFG_SRAM3_AXI_BASE_S

#define RAMCFG_SRAM4_AXI          RAMCFG_SRAM4_AXI_S
#define RAMCFG_SRAM4_AXI_BASE     RAMCFG_SRAM4_AXI_BASE_S

#define RAMCFG_SRAM5_AXI          RAMCFG_SRAM5_AXI_S
#define RAMCFG_SRAM5_AXI_BASE     RAMCFG_SRAM5_AXI_BASE_S

#define RAMCFG_SRAM6_AXI          RAMCFG_SRAM6_AXI_S
#define RAMCFG_SRAM6_AXI_BASE     RAMCFG_SRAM6_AXI_BASE_S

#define RAMCFG_SRAM1_AHB          RAMCFG_SRAM1_AHB_S
#define RAMCFG_SRAM1_AHB_BASE     RAMCFG_SRAM1_AHB_BASE_S

#define RAMCFG_SRAM2_AHB          RAMCFG_SRAM2_AHB_S
#define RAMCFG_SRAM2_AHB_BASE     RAMCFG_SRAM2_AHB_BASE_S

#define RAMCFG_VENC_RAM           RAMCFG_VENC_RAM_S
#define RAMCFG_VENC_RAM_BASE      RAMCFG_VENC_RAM_BASE_S

#define RAMCFG_BKPSRAM            RAMCFG_BKPSRAM_S
#define RAMCFG_BKPSRAM_BASE       RAMCFG_BKPSRAM_BASE_S

#define RAMCFG_FLEXRAM            RAMCFG_FLEXRAM_S
#define RAMCFG_FLEXRAM_BASE       RAMCFG_FLEXRAM_BASE_S

#define RCC                       RCC_S
#define RCC_BASE                  RCC_BASE_S

#define RIFSC                     RIFSC_S
#define RIFSC_BASE                RIFSC_BASE_S

#define RISAF1                    RISAF1_S
#define RISAF1_BASE               RISAF1_BASE_S

#define RISAF2                    RISAF2_S
#define RISAF2_BASE               RISAF2_BASE_S

#define RISAF3                    RISAF3_S
#define RISAF3_BASE               RISAF3_BASE_S

#define RISAF4                    RISAF4_S
#define RISAF4_BASE               RISAF4_BASE_S

#define RISAF5                    RISAF5_S
#define RISAF5_BASE               RISAF5_BASE_S

#define RISAF6                    RISAF6_S
#define RISAF6_BASE               RISAF6_BASE_S

#define RISAF7                    RISAF7_S
#define RISAF7_BASE               RISAF7_BASE_S

#define RISAF8                    RISAF8_S
#define RISAF8_BASE               RISAF8_BASE_S

#define RISAF9                    RISAF9_S
#define RISAF9_BASE               RISAF9_BASE_S

#define RISAF11                   RISAF11_S
#define RISAF11_BASE              RISAF11_BASE_S

#define RISAF12                   RISAF12_S
#define RISAF12_BASE              RISAF12_BASE_S

#define RISAF13                   RISAF13_S
#define RISAF13_BASE              RISAF13_BASE_S

#define RISAF14                   RISAF14_S
#define RISAF14_BASE              RISAF14_BASE_S

#define RISAF15                   RISAF15_S
#define RISAF15_BASE              RISAF15_BASE_S

#define RISAF21                   RISAF21_S
#define RISAF21_BASE              RISAF21_BASE_S

#define RISAF22                   RISAF22_S
#define RISAF22_BASE              RISAF22_BASE_S

#define RISAF23                   RISAF23_S
#define RISAF23_BASE              RISAF23_BASE_S

#define RNG                       RNG_S
#define RNG_BASE                  RNG_BASE_S

#define RTC                       RTC_S
#define RTC_BASE                  RTC_BASE_S

#define SAES                      SAES_S
#define SAES_BASE                 SAES_BASE_S

#define SAI1                      SAI1_S
#define SAI1_BASE                 SAI1_BASE_S

#define SAI1_Block_A              SAI1_Block_A_S
#define SAI1_Block_A_BASE         SAI1_Block_A_BASE_S

#define SAI1_Block_B              SAI1_Block_B_S
#define SAI1_Block_B_BASE         SAI1_Block_B_BASE_S

#define SAI2                      SAI2_S
#define SAI2_BASE                 SAI2_BASE_S

#define SAI2_Block_A              SAI2_Block_A_S
#define SAI2_Block_A_BASE         SAI2_Block_A_BASE_S

#define SAI2_Block_B              SAI2_Block_B_S
#define SAI2_Block_B_BASE         SAI2_Block_B_BASE_S

#define SDMMC1                    SDMMC1_S
#define SDMMC1_BASE               SDMMC1_BASE_S

#define SDMMC2                    SDMMC2_S
#define SDMMC2_BASE               SDMMC2_BASE_S

#define SPDIFRX                   SPDIFRX_S
#define SPDIFRX_BASE              SPDIFRX_BASE_S

#define SPI1                      SPI1_S
#define SPI1_BASE                 SPI1_BASE_S

#define SPI2                      SPI2_S
#define SPI2_BASE                 SPI2_BASE_S

#define SPI3                      SPI3_S
#define SPI3_BASE                 SPI3_BASE_S

#define SPI4                      SPI4_S
#define SPI4_BASE                 SPI4_BASE_S

#define SPI5                      SPI5_S
#define SPI5_BASE                 SPI5_BASE_S

#define SPI6                      SPI6_S
#define SPI6_BASE                 SPI6_BASE_S

#define SRAMCAN_BASE              SRAMCAN_BASE_S

#define SYSCFG                    SYSCFG_S
#define SYSCFG_BASE               SYSCFG_BASE_S

#define TAMP                      TAMP_S
#define TAMP_BASE                 TAMP_BASE_S

#define TIM1                      TIM1_S
#define TIM1_BASE                 TIM1_BASE_S

#define TIM2                      TIM2_S
#define TIM2_BASE                 TIM2_BASE_S

#define TIM3                      TIM3_S
#define TIM3_BASE                 TIM3_BASE_S

#define TIM4                      TIM4_S
#define TIM4_BASE                 TIM4_BASE_S

#define TIM5                      TIM5_S
#define TIM5_BASE                 TIM5_BASE_S

#define TIM6                      TIM6_S
#define TIM6_BASE                 TIM6_BASE_S

#define TIM7                      TIM7_S
#define TIM7_BASE                 TIM7_BASE_S

#define TIM8                      TIM8_S
#define TIM8_BASE                 TIM8_BASE_S

#define TIM9                      TIM9_S
#define TIM9_BASE                 TIM9_BASE_S

#define TIM10                     TIM10_S
#define TIM10_BASE                TIM10_BASE_S

#define TIM11                     TIM11_S
#define TIM11_BASE                TIM11_BASE_S

#define TIM12                     TIM12_S
#define TIM12_BASE                TIM12_BASE_S

#define TIM13                     TIM13_S
#define TIM13_BASE                TIM13_BASE_S

#define TIM14                     TIM14_S
#define TIM14_BASE                TIM14_BASE_S

#define TIM15                     TIM15_S
#define TIM15_BASE                TIM15_BASE_S

#define TIM16                     TIM16_S
#define TIM16_BASE                TIM16_BASE_S

#define TIM17                     TIM17_S
#define TIM17_BASE                TIM17_BASE_S

#define TIM18                     TIM18_S
#define TIM18_BASE                TIM18_BASE_S

#define UART4                     UART4_S
#define UART4_BASE                UART4_BASE_S

#define UART5                     UART5_S
#define UART5_BASE                UART5_BASE_S

#define UART7                     UART7_S
#define UART7_BASE                UART7_BASE_S

#define UART8                     UART8_S
#define UART8_BASE                UART8_BASE_S

#define UART9                     UART9_S
#define UART9_BASE                UART9_BASE_S

#define UCPD1                     UCPD1_S
#define UCPD1_BASE                UCPD1_BASE_S

#define USART1                    USART1_S
#define USART1_BASE               USART1_BASE_S

#define USART2                    USART2_S
#define USART2_BASE               USART2_BASE_S

#define USART3                    USART3_S
#define USART3_BASE               USART3_BASE_S

#define USART6                    USART6_S
#define USART6_BASE               USART6_BASE_S

#define USART10                   USART10_S
#define USART10_BASE              USART10_BASE_S

#define USB1_OTG_HS               USB1_OTG_HS_S
#define USB1_OTG_HS_BASE          USB1_OTG_HS_BASE_S

#define USB2_OTG_HS               USB2_OTG_HS_S
#define USB2_OTG_HS_BASE          USB2_OTG_HS_BASE_S

#define USB1_HS_PHYC              USB1_HS_PHYC_S
#define USB1_HS_PHYC_BASE         USB1_HS_PHYC_BASE_S

#define USB2_HS_PHYC              USB2_HS_PHYC_S
#define USB2_HS_PHYC_BASE         USB2_HS_PHYC_BASE_S

#define VENC                      VENC_S
#define VENC_BASE                 VENC_BASE_S

#define VREFBUF                   VREFBUF_S
#define VREFBUF_BASE              VREFBUF_BASE_S

#define WWDG                      WWDG_S
#define WWDG_BASE                 WWDG_BASE_S

#define XSPI1                     XSPI1_S

#define XSPI2                     XSPI2_S

#define XSPI3                     XSPI3_S

#define XSPIM                     XSPIM_S
#define XSPIM_BASE                XSPIM_BASE_S

/*!< Unique device ID register base address */
#define UID_BASE                  UID_BASE_S

/*!< Revision ID base address */
#define REVID_BASE                REVID_BASE_S

#else

#define ADC12_COMMON              ADC12_COMMON_NS
#define ADC12_COMMON_BASE         ADC12_COMMON_BASE_NS

#define ADC1                      ADC1_NS
#define ADC1_BASE                 ADC1_BASE_NS

#define ADC2                      ADC2_NS
#define ADC2_BASE                 ADC2_BASE_NS

#define ADF1                      ADF1_NS
#define ADF1_BASE                 ADF1_BASE_NS

#define ADF1_Filter0              ADF1_Filter0_NS
#define ADF1_Filter0_BASE         ADF1_Filter0_BASE_NS

#define BSEC                      BSEC_NS
#define BSEC_BASE                 BSEC_BASE_NS

#define CACHEAXI                  CACHEAXI_NS
#define CACHEAXI_BASE             CACHEAXI_BASE_NS

#define CRC                       CRC_NS
#define CRC_BASE                  CRC_BASE_NS

#define CRYP                      CRYP_NS
#define CRYP_BASE                 CRYP_BASE_NS

#define CSI                       CSI_NS
#define CSI_BASE                  CSI_BASE_NS

#define DBGMCU                    DBGMCU_NS
#define DBGMCU_BASE               DBGMCU_BASE_NS

#define DCMI                      DCMI_NS
#define DCMI_BASE                 DCMI_BASE_NS

#define DCMIPP                    DCMIPP_NS
#define DCMIPP_BASE               DCMIPP_BASE_NS

#define DLYB_SDMMC1               DLYB_SDMMC1_NS
#define DLYB_SDMMC1_BASE          DLYB_SDMMC1_BASE_NS

#define DLYB_SDMMC2               DLYB_SDMMC2_NS
#define DLYB_SDMMC2_BASE          DLYB_SDMMC2_BASE_NS

#define DMA2D                     DMA2D_NS
#define DMA2D_BASE                DMA2D_BASE_NS

#define DTS                       DTS_NS
#define DTS_BASE                  DTS_BASE_NS

#define DTS_Sensor0               DTS_Sensor0_NS
#define DTS_Sensor0_BASE          DTS_Sensor0_BASE_NS

#define DTS_Sensor1               DTS_Sensor1_NS
#define DTS_Sensor1_BASE          DTS_Sensor1_BASE_NS

#define ETH1                      ETH1_NS
#define ETH1_BASE                 ETH1_BASE_NS

#define EXTI                      EXTI_NS
#define EXTI_BASE                 EXTI_BASE_NS

#define FDCAN1                    FDCAN1_NS
#define FDCAN1_BASE               FDCAN1_BASE_NS

#define FDCAN2                    FDCAN2_NS
#define FDCAN2_BASE               FDCAN2_BASE_NS

#define FDCAN3                    FDCAN3_NS
#define FDCAN3_BASE               FDCAN3_BASE_NS

#define FDCAN_CCU                 FDCAN_CCU_NS
#define FDCAN_CCU_BASE            FDCAN_CCU_BASE_NS

#define FMC_R_BASE                FMC_R_BASE_NS
#define FMC_R_BASE_BASE           FMC_R_BASE_BASE_NS

#define FMC_Bank1E_R              FMC_Bank1E_R_NS
#define FMC_Bank1E_R_BASE         FMC_Bank1E_R_BASE_NS

#define FMC_Bank1_R               FMC_Bank1_R_NS
#define FMC_Bank1_Rv              FMC_Bank1_R_BASE_NS

#define FMC_Bank3_R               FMC_Bank3_R_NS
#define FMC_Bank3_R_BASE          FMC_Bank3_R_BASE_NS

#define FMC_Bank5_6_R             FMC_Bank5_6_R_NS
#define FMC_Bank5_6_R_BASE        FMC_Bank5_6_R_BASE_NS

#define FMC_Common_R              FMC_Common_R_NS
#define FMC_Common_R_BASE         FMC_Common_R_BASE_NS

#define GFXMMU                       GFXMMU_NS
#define GFXMMU_BASE                  GFXMMU_BASE_NS
#define GFXMMU_VIRTUAL_BUFFER0_BASE  GFXMMU_VIRTUAL_BUFFER0_BASE_NS
#define GFXMMU_VIRTUAL_BUFFER1_BASE  GFXMMU_VIRTUAL_BUFFER1_BASE_NS
#define GFXMMU_VIRTUAL_BUFFER2_BASE  GFXMMU_VIRTUAL_BUFFER2_BASE_NS
#define GFXMMU_VIRTUAL_BUFFER3_BASE  GFXMMU_VIRTUAL_BUFFER3_BASE_NS

#define GFXTIM                    GFXTIM_NS
#define GFXTIM_BASE               GFXTIM_BASE_NS

#define GPDMA1                    GPDMA1_NS
#define GPDMA1_BASE               GPDMA1_BASE_NS

#define GPDMA1_Channel0           GPDMA1_Channel0_NS
#define GPDMA1_Channel0_BASE      GPDMA1_Channel0_BASE_NS

#define GPDMA1_Channel1           GPDMA1_Channel1_NS
#define GPDMA1_Channel1_BASE      GPDMA1_Channel1_BASE_NS

#define GPDMA1_Channel2           GPDMA1_Channel2_NS
#define GPDMA1_Channel2_BASE      GPDMA1_Channel2_BASE_NS

#define GPDMA1_Channel3           GPDMA1_Channel3_NS
#define GPDMA1_Channel3_BASE      GPDMA1_Channel3_BASE_NS

#define GPDMA1_Channel4           GPDMA1_Channel4_NS
#define GPDMA1_Channel4_BASE      GPDMA1_Channel4_BASE_NS

#define GPDMA1_Channel5           GPDMA1_Channel5_NS
#define GPDMA1_Channel5_BASE      GPDMA1_Channel5_BASE_NS

#define GPDMA1_Channel6           GPDMA1_Channel6_NS
#define GPDMA1_Channel6_BASE      GPDMA1_Channel6_BASE_NS

#define GPDMA1_Channel7           GPDMA1_Channel7_NS
#define GPDMA1_Channel7_BASE      GPDMA1_Channel7_BASE_NS

#define GPDMA1_Channel8           GPDMA1_Channel8_NS
#define GPDMA1_Channel8_BASE      GPDMA1_Channel8_BASE_NS

#define GPDMA1_Channel9           GPDMA1_Channel9_NS
#define GPDMA1_Channel9_BASE      GPDMA1_Channel9_BASE_NS

#define GPDMA1_Channel10          GPDMA1_Channel10_NS
#define GPDMA1_Channel10_BASE     GPDMA1_Channel10_BASE_NS

#define GPDMA1_Channel11          GPDMA1_Channel11_NS
#define GPDMA1_Channel11_BASE     GPDMA1_Channel11_BASE_NS

#define GPDMA1_Channel12          GPDMA1_Channel12_NS
#define GPDMA1_Channel12_BASE     GPDMA1_Channel12_BASE_NS

#define GPDMA1_Channel13          GPDMA1_Channel13_NS
#define GPDMA1_Channel13_BASE     GPDMA1_Channel13_BASE_NS

#define GPDMA1_Channel14          GPDMA1_Channel14_NS
#define GPDMA1_Channel14_BASE     GPDMA1_Channel14_BASE_NS

#define GPDMA1_Channel15          GPDMA1_Channel15_NS
#define GPDMA1_Channel15_BASE     GPDMA1_Channel15_BASE_NS

#define GPIOA                     GPIOA_NS
#define GPIOA_BASE                GPIOA_BASE_NS

#define GPIOB                     GPIOB_NS
#define GPIOB_BASE                GPIOB_BASE_NS

#define GPIOC                     GPIOC_NS
#define GPIOC_BASE                GPIOC_BASE_NS

#define GPIOD                     GPIOD_NS
#define GPIOD_BASE                GPIOD_BASE_NS

#define GPIOE                     GPIOE_NS
#define GPIOE_BASE                GPIOE_BASE_NS

#define GPIOF                     GPIOF_NS
#define GPIOF_BASE                GPIOF_BASE_NS

#define GPIOG                     GPIOG_NS
#define GPIOG_BASE                GPIOG_BASE_NS

#define GPIOH                     GPIOH_NS
#define GPIOH_BASE                GPIOH_BASE_NS

#define GPION                     GPION_NS
#define GPION_BASE                GPION_BASE_NS

#define GPIOO                     GPIOO_NS
#define GPIOO_BASE                GPIOO_BASE_NS

#define GPIOP                     GPIOP_NS
#define GPIOP_BASE                GPIOP_BASE_NS

#define GPIOQ                     GPIOQ_NS
#define GPIOQ_BASE                GPIOQ_BASE_NS

#define GPU2D                     GPU2D_BASE_NS
#define GPU2D_BASE                GPU2D_BASE_NS

#define HASH                      HASH_NS
#define HASH_BASE                 HASH_BASE_NS

#define HASH_DIGEST               HASH_DIGEST_NS
#define HASH_DIGEST_BASE          HASH_DIGEST_BASE_NS

#define HPDMA1                    HPDMA1_NS
#define HPDMA1_BASE               HPDMA1_BASE_NS

#define HPDMA1_Channel0           HPDMA1_Channel0_NS
#define HPDMA1_Channel0_BASE      HPDMA1_Channel0_BASE_NS

#define HPDMA1_Channel1           HPDMA1_Channel1_NS
#define HPDMA1_Channel1_BASE      HPDMA1_Channel1_BASE_NS

#define HPDMA1_Channel2           HPDMA1_Channel2_NS
#define HPDMA1_Channel2_BASE      HPDMA1_Channel2_BASE_NS

#define HPDMA1_Channel3           HPDMA1_Channel3_NS
#define HPDMA1_Channel3_BASE      HPDMA1_Channel3_BASE_NS

#define HPDMA1_Channel4           HPDMA1_Channel4_NS
#define HPDMA1_Channel4_BASE      HPDMA1_Channel4_BASE_NS

#define HPDMA1_Channel5           HPDMA1_Channel5_NS
#define HPDMA1_Channel5_BASE      HPDMA1_Channel5_BASE_NS

#define HPDMA1_Channel6           HPDMA1_Channel6_NS
#define HPDMA1_Channel6_BASE      HPDMA1_Channel6_BASE_NS

#define HPDMA1_Channel7           HPDMA1_Channel7_NS
#define HPDMA1_Channel7_BASE      HPDMA1_Channel7_BASE_NS

#define HPDMA1_Channel8           HPDMA1_Channel8_NS
#define HPDMA1_Channel8_BASE      HPDMA1_Channel8_BASE_NS

#define HPDMA1_Channel9           HPDMA1_Channel9_NS
#define HPDMA1_Channel9_BASE      HPDMA1_Channel9_BASE_NS

#define HPDMA1_Channel10          HPDMA1_Channel10_NS
#define HPDMA1_Channel10_BASE     HPDMA1_Channel10_BASE_NS

#define HPDMA1_Channel11          HPDMA1_Channel11_NS
#define HPDMA1_Channel11_BASE     HPDMA1_Channel11_BASE_NS

#define HPDMA1_Channel12          HPDMA1_Channel12_NS
#define HPDMA1_Channel12_BASE     HPDMA1_Channel12_BASE_NS

#define HPDMA1_Channel13          HPDMA1_Channel13_NS
#define HPDMA1_Channel13_BASE     HPDMA1_Channel13_BASE_NS

#define HPDMA1_Channel14          HPDMA1_Channel14_NS
#define HPDMA1_Channel14_BASE     HPDMA1_Channel14_BASE_NS

#define HPDMA1_Channel15          HPDMA1_Channel15_NS
#define HPDMA1_Channel15_BASE     HPDMA1_Channel15_BASE_NS

#define I2C1                      I2C1_NS
#define I2C1_BASE                 I2C1_BASE_NS

#define I2C2                      I2C2_NS
#define I2C2_BASE                 I2C2_BASE_NS

#define I2C3                      I2C3_NS
#define I2C3_BASE                 I2C3_BASE_NS

#define I2C4                      I2C4_NS
#define I2C4_BASE                 I2C4_BASE_NS

#define I3C1                      I3C1_NS
#define I3C1_BASE                 I3C1_BASE_NS

#define I3C2                      I3C2_NS
#define I3C2_BASE                 I3C2_BASE_NS

#define ICACHE                    ICACHE_NS
#define ICACHE_BASE               ICACHE_BASE_NS

#define IWDG                      IWDG_NS
#define IWDG_BASE                 IWDG_BASE_NS

#define JPEG                      JPEG_NS
#define JPEG_BASE                 JPEG_BASE_NS

#define LPTIM1                    LPTIM1_NS
#define LPTIM1_BASE               LPTIM1_BASE_NS

#define LPTIM2                    LPTIM2_NS
#define LPTIM2_BASE               LPTIM2_BASE_NS

#define LPTIM3                    LPTIM3_NS
#define LPTIM3_BASE               LPTIM3_BASE_NS

#define LPTIM4                    LPTIM4_NS
#define LPTIM4_BASE               LPTIM4_BASE_NS

#define LPTIM5                    LPTIM5_NS
#define LPTIM5_BASE               LPTIM5_BASE_NS

#define LPUART1                   LPUART1_NS
#define LPUART1_BASE              LPUART1_BASE_NS

#define LTDC                      LTDC_NS
#define LTDC_BASE                 LTDC_BASE_NS

#define LTDC_Layer1               LTDC_Layer1_NS
#define LTDC_Layer1_BASE          LTDC_Layer1_BASE_NS

#define LTDC_Layer2               LTDC_Layer2_NS
#define LTDC_Layer2_BASE          LTDC_Layer2_BASE_NS

#define MCE1                      MCE1_NS
#define MCE1_BASE                 MCE1_BASE_NS

#define MCE1_REGION1              MCE1_REGION1_NS
#define MCE1_REGION1_BASE         MCE1_REGION1_BASE_NS

#define MCE1_REGION2              MCE1_REGION2_NS
#define MCE1_REGION2_BASE         MCE1_REGION2_BASE_NS

#define MCE1_REGION3              MCE1_REGION3_NS
#define MCE1_REGION3_BASE         MCE1_REGION3_BASE_NS

#define MCE1_REGION4              MCE1_REGION4_NS
#define MCE1_REGION4_BASE         MCE1_REGION4_BASE_NS

#define MCE1_CONTEXT1             MCE1_CONTEXT1_NS
#define MCE1_CONTEXT1_BASE        MCE1_CONTEXT1_BASE_NS

#define MCE1_CONTEXT2             MCE1_CONTEXT2_NS
#define MCE1_CONTEXT2_BASE        MCE1_CONTEXT2_BASE_NS

#define MCE2                      MCE2_NS
#define MCE2_BASE                 MCE2_BASE_NS

#define MCE2_REGION1              MCE2_REGION1_NS
#define MCE2_REGION1_BASE         MCE2_REGION1_BASE_NS

#define MCE2_REGION2              MCE2_REGION2_NS
#define MCE2_REGION2_BASE         MCE2_REGION2_BASE_NS

#define MCE2_REGION3              MCE2_REGION3_NS
#define MCE2_REGION3_BASE         MCE2_REGION3_BASE_NS

#define MCE2_REGION4              MCE2_REGION4_NS
#define MCE2_REGION4_BASE         MCE2_REGION4_BASE_NS

#define MCE2_CONTEXT1             MCE2_CONTEXT1_NS
#define MCE2_CONTEXT1_BASE        MCE2_CONTEXT1_BASE_NS

#define MCE2_CONTEXT2             MCE2_CONTEXT2_NS
#define MCE2_CONTEXT2_BASE        MCE2_CONTEXT2_BASE_NS

#define MCE3                      MCE3_NS
#define MCE3_BASE                 MCE3_BASE_NS

#define MCE3_REGION1              MCE3_REGION1_NS
#define MCE3_REGION1_BASE         MCE3_REGION1_BASE_NS

#define MCE3_REGION2              MCE3_REGION2_NS
#define MCE3_REGION2_BASE         MCE3_REGION2_BASE_NS

#define MCE3_REGION3              MCE3_REGION3_NS
#define MCE3_REGION3_BASE         MCE3_REGION3_BASE_NS

#define MCE3_REGION4              MCE3_REGION4_NS
#define MCE3_REGION4_BASE         MCE3_REGION4_BASE_NS

#define MCE3_CONTEXT1             MCE3_CONTEXT1_NS
#define MCE3_CONTEXT1_BASE        MCE3_CONTEXT1_BASE_NS

#define MCE3_CONTEXT2             MCE3_CONTEXT2_NS
#define MCE3_CONTEXT2_BASE        MCE3_CONTEXT2_BASE_NS

#define MCE4                      MCE4_NS
#define MCE4_BASE                 MCE4_BASE_NS

#define MCE4_REGION1              MCE4_REGION1_NS
#define MCE4_REGION1_BASE         MCE4_REGION1_BASE_NS

#define MCE4_REGION2              MCE4_REGION2_NS
#define MCE4_REGION2_BASE         MCE4_REGION2_BASE_NS

#define MCE4_REGION3              MCE4_REGION3_NS
#define MCE4_REGION3_BASE         MCE4_REGION3_BASE_NS

#define MCE4_REGION4              MCE4_REGION4_NS
#define MCE4_REGION4_BASE         MCE4_REGION4_BASE_NS

#define MCE4_CONTEXT1             MCE4_CONTEXT1_NS
#define MCE4_CONTEXT1_BASE        MCE4_CONTEXT1_BASE_NS

#define MCE4_CONTEXT2             MCE4_CONTEXT2_NS
#define MCE4_CONTEXT2_BASE        MCE4_CONTEXT2_BASE_NS

#define MDF1                      MDF1_NS
#define MDF1_BASE                 MDF1_BASE_NS

#define MDF1_Filter0              MDF1_Filter0_NS
#define MDF1_Filter0_BASE         MDF1_Filter0_BASE_NS

#define MDF1_Filter1              MDF1_Filter1_NS
#define MDF1_Filter1_BASE         MDF1_Filter1_BASE_NS

#define MDF1_Filter2              MDF1_Filter2_NS
#define MDF1_Filter2_BASE         MDF1_Filter2_BASE_NS

#define MDF1_Filter3              MDF1_Filter3_NS
#define MDF1_Filter3_BASE         MDF1_Filter3_BASE_NS

#define MDF1_Filter4              MDF1_Filter4_NS
#define MDF1_Filter4_BASE         MDF1_Filter4_BASE_NS

#define MDF1_Filter5              MDF1_Filter5_NS
#define MDF1_Filter5_BASE         MDF1_Filter5_BASE_NS

#define MDIOS                     MDIOS_NS
#define MDIOS_BASE                MDIOS_BASE_NS

#define NPU_PRESENT
#define NPU_BASE                  NPU_BASE_NS

#define PKA                       PKA_NS
#define PKA_BASE                  PKA_BASE_NS

#define PSSI                      PSSI_NS
#define PSSI_BASE                 PSSI_BASE_NS

#define PWR                       PWR_NS
#define PWR_BASE                  PWR_BASE_NS

#define RAMCFG                    RAMCFG_NS
#define RAMCFG_BASE               RAMCFG_BASE_NS

#define RAMCFG_SRAM1_AXI          RAMCFG_SRAM1_AXI_NS
#define RAMCFG_SRAM1_AXI_BASE     RAMCFG_SRAM1_AXI_BASE_NS

#define RAMCFG_SRAM2_AXI          RAMCFG_SRAM2_AXI_NS
#define RAMCFG_SRAM2_AXI_BASE     RAMCFG_SRAM2_AXI_BASE_NS

#define RAMCFG_SRAM3_AXI          RAMCFG_SRAM3_AXI_NS
#define RAMCFG_SRAM3_AXI_BASE     RAMCFG_SRAM3_AXI_BASE_NS

#define RAMCFG_SRAM4_AXI          RAMCFG_SRAM4_AXI_NS
#define RAMCFG_SRAM4_AXI_BASE     RAMCFG_SRAM4_AXI_BASE_NS

#define RAMCFG_SRAM5_AXI          RAMCFG_SRAM5_AXI_NS
#define RAMCFG_SRAM5_AXI_BASE     RAMCFG_SRAM5_AXI_BASE_NS

#define RAMCFG_SRAM6_AXI          RAMCFG_SRAM6_AXI_NS
#define RAMCFG_SRAM6_AXI_BASE     RAMCFG_SRAM6_AXI_BASE_NS

#define RAMCFG_SRAM1_AHB          RAMCFG_SRAM1_AHB_NS
#define RAMCFG_SRAM1_AHB_BASE     RAMCFG_SRAM1_AHB_BASE_NS

#define RAMCFG_SRAM2_AHB          RAMCFG_SRAM2_AHB_NS
#define RAMCFG_SRAM2_AHB_BASE     RAMCFG_SRAM2_AHB_BASE_NS

#define RAMCFG_VENC_RAM           RAMCFG_VENC_RAM_NS
#define RAMCFG_VENC_RAM_BASE      RAMCFG_VENC_RAM_BASE_NS

#define RAMCFG_BKPSRAM            RAMCFG_BKPSRAM_NS
#define RAMCFG_BKPSRAM_BASE       RAMCFG_BKPSRAM_BASE_NS

#define RAMCFG_FLEXRAM            RAMCFG_FLEXRAM_NS
#define RAMCFG_FLEXRAM_BASE       RAMCFG_FLEXRAM_BASE_NS

#define RCC                       RCC_NS
#define RCC_BASE                  RCC_BASE_NS

#define RIFSC                     RIFSC_NS
#define RIFSC_BASE                RIFSC_BASE_NS

#define RISAF1                    RISAF1_NS
#define RISAF1_BASE               RISAF1_BASE_NS

#define RISAF2                    RISAF2_NS
#define RISAF2_BASE               RISAF2_BASE_NS

#define RISAF3                    RISAF3_NS
#define RISAF3_BASE               RISAF3_BASE_NS

#define RISAF4                    RISAF4_NS
#define RISAF4_BASE               RISAF4_BASE_NS

#define RISAF5                    RISAF5_NS
#define RISAF5_BASE               RISAF5_BASE_NS

#define RISAF6                    RISAF6_NS
#define RISAF6_BASE               RISAF6_BASE_NS

#define RISAF7                    RISAF7_NS
#define RISAF7_BASE               RISAF7_BASE_NS

#define RISAF8                    RISAF8_NS
#define RISAF8_BASE               RISAF8_BASE_NS

#define RISAF9                    RISAF9_NS
#define RISAF9_BASE               RISAF9_BASE_NS

#define RISAF11                   RISAF11_NS
#define RISAF11_BASE              RISAF11_BASE_NS

#define RISAF12                   RISAF12_NS
#define RISAF12_BASE              RISAF12_BASE_NS

#define RISAF13                   RISAF13_NS
#define RISAF13_BASE              RISAF13_BASE_NS

#define RISAF14                   RISAF14_NS
#define RISAF14_BASE              RISAF14_BASE_NS

#define RISAF15                   RISAF15_NS
#define RISAF15_BASE              RISAF15_BASE_NS

#define RISAF21                   RISAF21_NS
#define RISAF21_BASE              RISAF21_BASE_NS

#define RISAF22                   RISAF22_NS
#define RISAF22_BASE              RISAF22_BASE_NS

#define RISAF23                   RISAF23_NS
#define RISAF23_BASE              RISAF23_BASE_NS

#define RNG                       RNG_NS
#define RNG_BASE                  RNG_BASE_NS

#define RTC                       RTC_NS
#define RTC_BASE                  RTC_BASE_NS

#define SAES                      SAES_NS
#define SAES_BASE                 SAES_BASE_NS

#define SAI1                      SAI1_NS
#define SAI1_BASE                 SAI1_BASE_NS

#define SAI1_Block_A              SAI1_Block_A_NS
#define SAI1_Block_A_BASE         SAI1_Block_A_BASE_NS

#define SAI1_Block_B              SAI1_Block_B_NS
#define SAI1_Block_B_BASE         SAI1_Block_B_BASE_NS

#define SAI2                      SAI2_NS
#define SAI2_BASE                 SAI2_BASE_NS

#define SAI2_Block_A              SAI2_Block_A_NS
#define SAI2_Block_A_BASE         SAI2_Block_A_BASE_NS

#define SAI2_Block_B              SAI2_Block_B_NS
#define SAI2_Block_B_BASE         SAI2_Block_B_BASE_NS

#define SDMMC1                    SDMMC1_NS
#define SDMMC1_BASE               SDMMC1_BASE_NS

#define SDMMC2                    SDMMC2_NS
#define SDMMC2_BASE               SDMMC2_BASE_NS

#define SPDIFRX                   SPDIFRX_NS
#define SPDIFRX_BASE              SPDIFRX_BASE_NS

#define SPI1                      SPI1_NS
#define SPI1_BASE                 SPI1_BASE_NS

#define SPI2                      SPI2_NS
#define SPI2_BASE                 SPI2_BASE_NS

#define SPI3                      SPI3_NS
#define SPI3_BASE                 SPI3_BASE_NS

#define SPI4                      SPI4_NS
#define SPI4_BASE                 SPI4_BASE_NS

#define SPI5                      SPI5_NS
#define SPI5_BASE                 SPI5_BASE_NS

#define SPI6                      SPI6_NS
#define SPI6_BASE                 SPI6_BASE_NS

#define SRAMCAN_BASE              SRAMCAN_BASE_NS

#define SYSCFG                    SYSCFG_NS
#define SYSCFG_BASE               SYSCFG_BASE_NS

#define TAMP                      TAMP_NS
#define TAMP_BASE                 TAMP_BASE_NS

#define TIM1                      TIM1_NS
#define TIM1_BASE                 TIM1_BASE_NS

#define TIM2                      TIM2_NS
#define TIM2_BASE                 TIM2_BASE_NS

#define TIM3                      TIM3_NS
#define TIM3_BASE                 TIM3_BASE_NS

#define TIM4                      TIM4_NS
#define TIM4_BASE                 TIM4_BASE_NS

#define TIM5                      TIM5_NS
#define TIM5_BASE                 TIM5_BASE_NS

#define TIM6                      TIM6_NS
#define TIM6_BASE                 TIM6_BASE_NS

#define TIM7                      TIM7_NS
#define TIM7_BASE                 TIM7_BASE_NS

#define TIM8                      TIM8_NS
#define TIM8_BASE                 TIM8_BASE_NS

#define TIM9                      TIM9_NS
#define TIM9_BASE                 TIM9_BASE_NS

#define TIM10                     TIM10_NS
#define TIM10_BASE                TIM10_BASE_NS

#define TIM11                     TIM11_NS
#define TIM11_BASE                TIM11_BASE_NS

#define TIM12                     TIM12_NS
#define TIM12_BASE                TIM12_BASE_NS

#define TIM13                     TIM13_NS
#define TIM13_BASE                TIM13_BASE_NS

#define TIM14                     TIM14_NS
#define TIM14_BASE                TIM14_BASE_NS

#define TIM15                     TIM15_NS
#define TIM15_BASE                TIM15_BASE_NS

#define TIM16                     TIM16_NS
#define TIM16_BASE                TIM16_BASE_NS

#define TIM17                     TIM17_NS
#define TIM17_BASE                TIM17_BASE_NS

#define TIM18                     TIM18_NS
#define TIM18_BASE                TIM18_BASE_NS

#define UART4                     UART4_NS
#define UART4_BASE                UART4_BASE_NS

#define UART5                     UART5_NS
#define UART5_BASE                UART5_BASE_NS

#define UART7                     UART7_NS
#define UART7_BASE                UART7_BASE_NS

#define UART8                     UART8_NS
#define UART8_BASE                UART8_BASE_NS

#define UART9                     UART9_NS
#define UART9_BASE                UART9_BASE_NS

#define UCPD1                     UCPD1_NS
#define UCPD1_BASE                UCPD1_BASE_NS

#define USART1                    USART1_NS
#define USART1_BASE               USART1_BASE_NS

#define USART2                    USART2_NS
#define USART2_BASE               USART2_BASE_NS

#define USART3                    USART3_NS
#define USART3_BASE               USART3_BASE_NS

#define USART6                    USART6_NS
#define USART6_BASE               USART6_BASE_NS

#define USART10                   USART10_NS
#define USART10_BASE              USART10_BASE_NS

#define USB1_OTG_HS               USB1_OTG_HS_NS
#define USB1_OTG_HS_BASE          USB1_OTG_HS_BASE_NS

#define USB2_OTG_HS               USB2_OTG_HS_NS
#define USB2_OTG_HS_BASE          USB2_OTG_HS_BASE_NS

#define USB1_HS_PHYC              USB1_HS_PHYC_NS
#define USB1_HS_PHYC_BASE         USB1_HS_PHYC_BASE_NS

#define USB2_HS_PHYC              USB2_HS_PHYC_NS
#define USB2_HS_PHYC_BASE         USB2_HS_PHYC_BASE_NS

#define VENC                      VENC_NS
#define VENC_BASE                 VENC_BASE_NS

#define VREFBUF                   VREFBUF_NS
#define VREFBUF_BASE              VREFBUF_BASE_NS

#define WWDG                      WWDG_NS
#define WWDG_BASE                 WWDG_BASE_NS

#define XSPI1                     XSPI1_NS

#define XSPI2                     XSPI2_NS

#define XSPI3                     XSPI3_NS

#define XSPIM                     XSPIM_NS
#define XSPIM_BASE                XSPIM_BASE_NS

/*!< Unique device ID register base address */
#define UID_BASE                  UID_BASE_NS

/*!< Revision ID base address */
#define REVID_BASE                REVID_BASE_NS

#endif

/** @} */ /* End of group STM32N6xx_Peripheral_declaration */

/** @addtogroup STM32N6xx_Peripheral_Timing_Definition
  * @{
  */

#define LSI_STARTUP_TIME                16000U /*!< LSI Maximum startup time in us : 4 cycles @ 250 Hz = 16 ms */

/** @} */ /* End of group STM32N6xx_Peripheral_Timing_Definition */

/** @} */ /* End of group STM32N6xx_Peripheral_Exported_macros */

/** @} */ /* End of group STM32N657xx */

/** @} */ /* End of group ST */

#ifdef __cplusplus
 }
#endif /* __cplusplus */

#endif /* STM32N657xx_H */
