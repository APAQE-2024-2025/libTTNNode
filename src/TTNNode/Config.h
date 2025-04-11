#pragma once

#include <lmic.h>

// #define LORAWAN_PORT 10              // Port the messages will be sent to
#define LORAWAN_CONFIRMED_EVERY 0    // Send confirmed message every these many messages (0 means never)
#define LORAWAN_SF DR_SF7            // Spreading factor (recommended DR_SF7 for ttn network map purposes, DR_SF10 works for slow moving trackers)
#define LORAWAN_ADR 0                // Enable ADR
#define SHOW_DEBUG true              // Show debug information (very verbose, but lots of serial prints slows down program)
#define USE_OTAA false               // Uses OTAA if true, else ABP. tbh if OTAA doesnt work, try ABP it just may


#warning "THIS WARNING IS HERE TO REMIND YOU TO UPDATE/SET YOUR CREDENTIALS!!! (and to drink 1.5L of water/day)"

#if USE_OTAA

// This key should be in little endian format (lsb)
static const uint8_t PROGMEM APPEUI[8] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
// This key should be in little endian format (lsb)
static const uint8_t DEVEUI[8] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
// This key should be in big endian format (msb)
static const uint8_t PROGMEM APPKEY[16] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

#else

//all msb format
static const uint8_t PROGMEM NWKSKEY[16] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static const uint8_t PROGMEM APPSKEY[16] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static const uint32_t DEVADDR = 0x00000000; //just randomly generate one or copy the one from the TTN dashboard if theres already one there

#endif

// -----------------------------------------------------------------------------
// Custom messages
// -----------------------------------------------------------------------------

#define EV_QUEUED 100
#define EV_PENDING 101
#define EV_ACK 102
#define EV_RESPONSE 103

// -----------------------------------------------------------------------------
// LoRa
// -----------------------------------------------------------------------------

// Lilygo T-BEAM
#define SCK_GPIO 5
#define MISO_GPIO 19
#define MOSI_GPIO 27
#define NSS_GPIO 18
#define RESET_GPIO 14
#define DIO0_GPIO 26
#define DIO1_GPIO 33
#define DIO2_GPIO 32

// Firebeetle32
// #define SCK_GPIO 18
// #define MISO_GPIO 19
// #define MOSI_GPIO 23
// #define NSS_GPIO D3
// #define RESET_GPIO D4
// #define DIO0_GPIO D2
// #define DIO1_GPIO D5
// #define DIO2_GPIO LMIC_UNUSED_PIN