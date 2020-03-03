/**
 * Auto initialization for used modules
 *
 * Copyright (C) 2020 Freie Universität Berlin
 *               2020 Kaspar Schleiser <kaspar@schleiser.de>
 *               2013  INRIA.
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 *
 * @ingroup sys_auto_init
 * @{
 * @file
 * @brief   initializes any used module that has a trivial init function
 * @author  Oliver Hahm <oliver.hahm@inria.fr>
 * @author  Hauke Petersen <hauke.petersen@fu-berlin.de>
 * @author  Kaspar Schleiser <kaspar@schleiser.de>
 * @}
 */
#include <stdint.h>
#include <stdio.h>

#include "auto_init.h"
#include "log.h"

void auto_init(void)
{
#ifdef MODULE_AUTO_INIT_RANDOM
    LOG_DEBUG("Auto init random.\n");
    extern void auto_init_random(void);
    auto_init_random();
#endif
#ifdef MODULE_AUTO_INIT_XTIMER
    LOG_DEBUG("Auto init xtimer.\n");
    extern void xtimer_init(void);
    xtimer_init();
#endif
#ifdef MODULE_SCHEDSTATISTICS
    LOG_DEBUG("Auto init schedstatistics.\n");
    extern void init_schedstatistics(void);
    init_schedstatistics();
#endif
#ifdef MODULE_EVENT_THREAD
    LOG_DEBUG("Auto init event threads.\n");
    extern void auto_init_event_thread(void);
    auto_init_event_thread();
#endif
#ifdef MODULE_MCI
    LOG_DEBUG("Auto init mci.\n");
    extern void mci_initialize(void);
    mci_initialize();
#endif
#ifdef MODULE_PROFILING
    LOG_DEBUG("Auto init profiling.\n");
    extern void profiling_init(void);
    profiling_init();
#endif
#ifdef MODULE_AUTO_INIT_GNRC_PKTBUF
    LOG_DEBUG("Auto init gnrc_pktbuf.\n");
    extern void gnrc_pktbuf_init(void);
    gnrc_pktbuf_init();
#endif
#ifdef MODULE_AUTO_INIT_GNRC_PKTDUMP
    LOG_DEBUG("Auto init gnrc_pktdump.\n");
    extern void gnrc_pktdump_init(void);
    gnrc_pktdump_init();
#endif
#ifdef MODULE_AUTO_INIT_GNRC_SIXLOWPAN
    LOG_DEBUG("Auto init gnrc_sixlowpan.\n");
    extern void gnrc_sixlowpan_init(void);
    gnrc_sixlowpan_init();
#endif
#ifdef MODULE_AUTO_INIT_GNRC_IPV6
    LOG_DEBUG("Auto init gnrc_ipv6.\n");
    extern void gnrc_ipv6_init(void);
    gnrc_ipv6_init();
#endif
#ifdef MODULE_AUTO_INIT_GNRC_UDP
    LOG_DEBUG("Auto init gnrc_udp.\n");
    extern void gnrc_udp_init(void);
    gnrc_udp_init();
#endif
#ifdef MODULE_AUTO_INIT_GNRC_TCP
    LOG_DEBUG("Auto init gnrc_tcp.\n");
    extern void gnrc_tcp_init(void);
    gnrc_tcp_init();
#endif
#ifdef MODULE_AUTO_INIT_LWIP
    LOG_DEBUG("Bootstraping lwIP.\n");
    extern void lwip_bootstrap(void);
    lwip_bootstrap();
#endif
#ifdef MODULE_OPENTHREAD
    LOG_DEBUG("Bootstrapping openthread.\n");
    extern void openthread_bootstrap(void);
    openthread_bootstrap();
#endif
#ifdef MODULE_GCOAP
    if (!IS_ACTIVE(CONFIG_GCOAP_NO_AUTO_INIT)) {
        LOG_DEBUG("Auto init gcoap.\n");
        extern void gcoap_init(void);
        gcoap_init();
    }
#endif
#ifdef MODULE_DEVFS
    LOG_DEBUG("Mounting /dev.\n");
    extern void auto_init_devfs(void);
    auto_init_devfs();
#endif
#ifdef MODULE_AUTO_INIT_GNRC_IPV6_NIB
    LOG_DEBUG("Auto init gnrc_ipv6_nib.\n");
    extern void gnrc_ipv6_nib_init(void);
    gnrc_ipv6_nib_init();
#endif
#ifdef MODULE_SKALD
    LOG_DEBUG("Auto init Skald.\n");
    extern void skald_init(void);
    skald_init();
#endif
#ifdef MODULE_CORD_COMMON
    LOG_DEBUG("Auto init cord_common.\n");
    extern void cord_common_init(void);
    cord_common_init();
#endif
#ifdef MODULE_CORD_EP_STANDALONE
    LOG_DEBUG("Auto init cord_ep_standalone.\n");
    extern void cord_ep_standalone_run(void);
    cord_ep_standalone_run();
#endif
#ifdef MODULE_ASYMCUTE
    LOG_DEBUG("Auto init Asymcute.\n");
    extern void asymcute_handler_run(void);
    asymcute_handler_run();
#endif
#ifdef MODULE_NIMBLE
    LOG_DEBUG("Auto init NimBLE.\n");
    extern void nimble_riot_init(void);
    nimble_riot_init();
#endif
#ifdef MODULE_AUTO_INIT_LORAMAC
    LOG_DEBUG("Auto init loramac.\n");
    extern void auto_init_loramac(void);
    auto_init_loramac();
#endif
#ifdef MODULE_SOCK_DTLS
    LOG_DEBUG("Auto init sock_dtls.\n");
    extern void sock_dtls_init(void);
    sock_dtls_init();
#endif

/* initialize USB devices */
#ifdef MODULE_AUTO_INIT_USBUS
    LOG_DEBUG("Auto init USB.\n");
    extern void auto_init_usb(void);
    auto_init_usb();
#endif

/* initialize network devices */
#ifdef MODULE_AUTO_INIT_GNRC_NETIF
    LOG_DEBUG("Auto init gnrc_netif.\n");

#ifdef MODULE_STM32_ETH
    extern void auto_init_stm32_eth(void);
    auto_init_stm32_eth();
#endif

#ifdef MODULE_AUTO_INIT_AT86RF2XX
    extern void auto_init_at86rf2xx(void);
    auto_init_at86rf2xx();
#endif

#ifdef MODULE_MRF24J40
    extern void auto_init_mrf24j40(void);
    auto_init_mrf24j40();
#endif

#ifdef MODULE_CC110X
    extern void auto_init_cc110x(void);
    auto_init_cc110x();
#endif

#ifdef MODULE_CC2420
    extern void auto_init_cc2420(void);
    auto_init_cc2420();
#endif

#ifdef MODULE_ENCX24J600
    extern void auto_init_encx24j600(void);
    auto_init_encx24j600();
#endif

#ifdef MODULE_ENC28J60
    extern void auto_init_enc28j60(void);
    auto_init_enc28j60();
#endif

#ifdef MODULE_ESP_ETH
    extern void auto_init_esp_eth(void);
    auto_init_esp_eth();
#endif

/* don't change the order of auto_init_esp_now and auto_init_esp_wifi */
#ifdef MODULE_ESP_NOW
    extern void auto_init_esp_now(void);
    auto_init_esp_now();
#endif

/* don't change the order of auto_init_esp_now and auto_init_esp_wifi */
#ifdef MODULE_ESP_WIFI
    extern void auto_init_esp_wifi(void);
    auto_init_esp_wifi();
#endif

#ifdef MODULE_ETHOS
    extern void auto_init_ethos(void);
    auto_init_ethos();
#endif

#ifdef MODULE_DOSE
    extern void auto_init_dose(void);
    auto_init_dose();
#endif

#ifdef MODULE_SLIPDEV
    extern void auto_init_slipdev(void);
    auto_init_slipdev();
#endif

#ifdef MODULE_CC2538_RF
    extern void auto_init_cc2538_rf(void);
    auto_init_cc2538_rf();
#endif

#ifdef MODULE_XBEE
    extern void auto_init_xbee(void);
    auto_init_xbee();
#endif

#ifdef MODULE_KW2XRF
    extern void auto_init_kw2xrf(void);
    auto_init_kw2xrf();
#endif

#ifdef MODULE_USBUS_CDC_ECM
    extern void auto_init_netdev_cdcecm(void);
    auto_init_netdev_cdcecm();
#endif

#ifdef MODULE_NETDEV_TAP
    extern void auto_init_netdev_tap(void);
    auto_init_netdev_tap();
#endif

#ifdef MODULE_SOCKET_ZEP
    extern void auto_init_socket_zep(void);
    auto_init_socket_zep();
#endif

#ifdef MODULE_NORDIC_SOFTDEVICE_BLE
    extern void gnrc_nordic_ble_6lowpan_init(void);
    gnrc_nordic_ble_6lowpan_init();
#endif

#ifdef MODULE_NRFMIN
    extern void gnrc_nrfmin_init(void);
    gnrc_nrfmin_init();
#endif

#ifdef MODULE_W5100
    extern void auto_init_w5100(void);
    auto_init_w5100();
#endif

#if defined(MODULE_SX127X) && !defined(MODULE_SEMTECH_LORAMAC)
    extern void auto_init_sx127x(void);
    auto_init_sx127x();
#endif

#ifdef MODULE_NRF802154
    extern void auto_init_nrf802154(void);
    auto_init_nrf802154();
#endif

#endif /* MODULE_AUTO_INIT_GNRC_NETIF */

#ifdef MODULE_AUTO_INIT_GNRC_UHCPC
    LOG_DEBUG("Auto init gnrc_uhcpc.\n");
    extern void auto_init_gnrc_uhcpc(void);
    auto_init_gnrc_uhcpc();
#endif

/* initialize NDN module after the network devices are initialized */
#ifdef MODULE_NDN_RIOT
    LOG_DEBUG("Auto init NDN.\n");
    extern void ndn_init(void);
    ndn_init();
#endif

/* initialize sensors and actuators */
#ifdef MODULE_SHT1X
    /* The sht1x module needs to be initialized regardless of SAUL being used,
     * as the shell commands rely on auto-initialization. auto_init_sht1x also
     * performs SAUL registration, but only if module auto_init_saul is used.
     */
    LOG_DEBUG("Auto init sht1x.\n");
    extern void auto_init_sht1x(void);
    auto_init_sht1x();
#endif

#ifdef MODULE_AUTO_INIT_SAUL
    LOG_DEBUG("Auto init SAUL.\n");

#ifdef MODULE_SAUL_ADC
    extern void auto_init_adc(void);
    auto_init_adc();
#endif
#ifdef MODULE_SAUL_GPIO
    extern void auto_init_gpio(void);
    auto_init_gpio();
#endif
#ifdef MODULE_SAUL_NRF_TEMPERATURE
    extern void auto_init_nrf_temperature(void);
    auto_init_nrf_temperature();
#endif
#ifdef MODULE_AD7746
    extern void auto_init_ad7746(void);
    auto_init_ad7746();
#endif
#ifdef MODULE_ADCXX1C
    extern void auto_init_adcxx1c(void);
    auto_init_adcxx1c();
#endif
#ifdef MODULE_ADS101X
    extern void auto_init_ads101x(void);
    auto_init_ads101x();
#endif
#ifdef MODULE_ADXL345
    extern void auto_init_adxl345(void);
    auto_init_adxl345();
#endif
#ifdef MODULE_BMP180
    extern void auto_init_bmp180(void);
    auto_init_bmp180();
#endif
#ifdef MODULE_BMX280
    extern void auto_init_bmx280(void);
    auto_init_bmx280();
#endif
#ifdef MODULE_BMX055
    extern void auto_init_bmx055(void);
    auto_init_bmx055();
#endif
#ifdef MODULE_CCS811
    extern void auto_init_ccs811(void);
    auto_init_ccs811();
#endif
#ifdef MODULE_DHT
    extern void auto_init_dht(void);
    auto_init_dht();
#endif
#ifdef MODULE_DS18
    extern void auto_init_ds18(void);
    auto_init_ds18();
#endif
#ifdef MODULE_DS75LX
    extern void auto_init_ds75lx(void);
    auto_init_ds75lx();
#endif
#ifdef MODULE_FXOS8700
    extern void auto_init_fxos8700(void);
    auto_init_fxos8700();
#endif
#ifdef MODULE_GROVE_LEDBAR
    extern void auto_init_grove_ledbar(void);
    auto_init_grove_ledbar();
#endif
#ifdef MODULE_HDC1000
    extern void auto_init_hdc1000(void);
    auto_init_hdc1000();
#endif
#ifdef MODULE_HTS221
    extern void auto_init_hts221(void);
    auto_init_hts221();
#endif
#ifdef MODULE_INA2XX
    extern void auto_init_ina2xx(void);
    auto_init_ina2xx();
#endif
#ifdef MODULE_INA3221
    extern void auto_init_ina3221(void);
    auto_init_ina3221();
#endif
#ifdef MODULE_IO1_XPLAINED
    extern void auto_init_io1_xplained(void);
    auto_init_io1_xplained();
#endif
#ifdef MODULE_ISL29020
    extern void auto_init_isl29020(void);
    auto_init_isl29020();
#endif
#ifdef MODULE_ITG320X
    extern void auto_init_itg320x(void);
    auto_init_itg320x();
#endif
#ifdef MODULE_JC42
    extern void auto_init_jc42(void);
    auto_init_jc42();
#endif
#ifdef MODULE_L3G4200D
    extern void auto_init_l3g4200d(void);
    auto_init_l3g4200d();
#endif
#ifdef MODULE_LIS2DH12
    extern void auto_init_lis2dh12(void);
    auto_init_lis2dh12();
#endif
#ifdef MODULE_LIS3DH
    extern void auto_init_lis3dh(void);
    auto_init_lis3dh();
#endif
#ifdef MODULE_LIS3MDL
    extern void auto_init_lis3mdl(void);
    auto_init_lis3mdl();
#endif
#ifdef MODULE_LPSXXX
    extern void auto_init_lpsxxx(void);
    auto_init_lpsxxx();
#endif
#ifdef MODULE_LSM303DLHC
    extern void auto_init_lsm303dlhc(void);
    auto_init_lsm303dlhc();
#endif
#ifdef MODULE_LSM6DSL
    extern void auto_init_lsm6dsl(void);
    auto_init_lsm6dsl();
#endif
#ifdef MODULE_LTC4150
    extern void auto_init_ltc4150(void);
    auto_init_ltc4150();
 #endif
#ifdef MODULE_MAG3110
    extern void auto_init_mag3110(void);
    auto_init_mag3110();
#endif
#ifdef MODULE_MMA7660
    extern void auto_init_mma7660(void);
    auto_init_mma7660();
#endif
#ifdef MODULE_MMA8X5X
    extern void auto_init_mma8x5x(void);
    auto_init_mma8x5x();
#endif
#ifdef MODULE_MPL3115A2
    extern void auto_init_mpl3115a2(void);
    auto_init_mpl3115a2();
#endif
#ifdef MODULE_MPU9X50
    extern void auto_init_mpu9x50(void);
    auto_init_mpu9x50();
#endif
#ifdef MODULE_OPT3001
    extern void auto_init_opt3001(void);
    auto_init_opt3001();
#endif
#ifdef MODULE_PCA9685
    extern void auto_init_pca9685(void);
    auto_init_pca9685();
#endif
#ifdef MODULE_PH_OEM
    extern void auto_init_ph_oem(void);
    auto_init_ph_oem();
#endif
#ifdef MODULE_PIR
    extern void auto_init_pir(void);
    auto_init_pir();
#endif
#ifdef MODULE_PULSE_COUNTER
    extern void auto_init_pulse_counter(void);
    auto_init_pulse_counter();
#endif
#ifdef MODULE_QMC5883L
    extern void auto_init_qmc5883l(void);
    auto_init_qmc5883l();
#endif
#ifdef MODULE_SHT2X
    extern void auto_init_sht2x(void);
    auto_init_sht2x();
#endif
#ifdef MODULE_SHT3X
    extern void auto_init_sht3x(void);
    auto_init_sht3x();
#endif
#ifdef MODULE_SHTC1
    extern void auto_init_shtc1(void);
    auto_init_shtc1();
#endif
#ifdef MODULE_SDS011
    extern void auto_init_sds011(void);
    auto_init_sds011();
#endif
#ifdef MODULE_SI114X
    extern void auto_init_si114x(void);
    auto_init_si114x();
#endif
#ifdef MODULE_SI70XX
    extern void auto_init_si70xx(void);
    auto_init_si70xx();
#endif
#ifdef MODULE_SPS30
    extern void auto_init_sps30(void);
    auto_init_sps30();
#endif
#ifdef MODULE_TCS37727
    extern void auto_init_tcs37727(void);
    auto_init_tcs37727();
#endif
#ifdef MODULE_TMP006
    extern void auto_init_tmp00x(void);
    auto_init_tmp00x();
#endif
#ifdef MODULE_TSL2561
    extern void auto_init_tsl2561(void);
    auto_init_tsl2561();
#endif
#ifdef MODULE_TSL4531X
    extern void auto_init_tsl4531x(void);
    auto_init_tsl4531x();
#endif
#ifdef MODULE_VCNL40X0
    extern void auto_init_vcnl40x0(void);
    auto_init_vcnl40x0();
#endif
#ifdef MODULE_VEML6070
    extern void auto_init_veml6070(void);
    auto_init_veml6070();
#endif

#endif /* MODULE_AUTO_INIT_SAUL */

#ifdef MODULE_AUTO_INIT_GNRC_RPL
    LOG_DEBUG("Auto init gnrc_rpl.\n");
    extern void auto_init_gnrc_rpl(void);
    auto_init_gnrc_rpl();
#endif /* MODULE_AUTO_INIT_GNRC_RPL */

/* initialize storage devices */
#ifdef MODULE_AUTO_INIT_STORAGE
    LOG_DEBUG("Auto init STORAGE.\n");

#ifdef MODULE_SDCARD_SPI
    extern void auto_init_sdcard_spi(void);
    auto_init_sdcard_spi();
#endif

#endif /* MODULE_AUTO_INIT_STORAGE */

#ifdef MODULE_AUTO_INIT_CAN
    LOG_DEBUG("Auto init CAN.\n");

    extern void auto_init_candev(void);
    auto_init_candev();

#endif /* MODULE_AUTO_INIT_CAN */

#ifdef MODULE_SUIT
    LOG_DEBUG("Auto init SUIT conditions.\n");
    extern void suit_init_conditions(void);
    suit_init_conditions();
#endif /* MODULE_SUIT */

#ifdef MODULE_AUTO_INIT_SECURITY

#ifdef MODULE_CRYPTOAUTHLIB
    LOG_DEBUG("Auto init cryptoauthlib.\n");
    extern void auto_init_atca(void);
    auto_init_atca();
#endif  /* MODULE_CRYPTOAUTHLIB */

#endif  /* MODULE_AUTO_INIT_SECURITY */

#ifdef MODULE_TEST_UTILS_INTERACTIVE_SYNC
#if !defined(MODULE_SHELL_COMMANDS) || !defined(MODULE_SHELL)
    extern void test_utils_interactive_sync(void);
    test_utils_interactive_sync();
#endif
#endif /* MODULE_TEST_UTILS_INTERACTIVE_SYNC */

#ifdef MODULE_AUTO_INIT_DHCPV6_CLIENT
    LOG_DEBUG("Auto init DHCPv6 client.\n");
    extern void dhcpv6_client_auto_init(void);
    dhcpv6_client_auto_init();
#endif /* MODULE_AUTO_INIT_DHCPV6_CLIENT */

#ifdef MODULE_GNRC_DHCPV6_CLIENT_6LBR
    LOG_DEBUG("Auto init 6LoWPAN border router DHCPv6 client\n");
    extern void gnrc_dhcpv6_client_6lbr_init(void);
    gnrc_dhcpv6_client_6lbr_init();
#endif /* MODULE_GNRC_DHCPV6_CLIENT_6LBR */
}
