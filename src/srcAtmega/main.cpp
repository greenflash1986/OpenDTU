// SPDX-License-Identifier: GPL-2.0-or-later
/*
 * Copyright (C) 2022 Thomas Basler and others
 */
// #include "Configuration.h"
#include "Hoymiles.h"
// #include "NtpSettings.h"
#include "defaults.h"
#include <Arduino.h>

// https://forum.arduino.cc/t/compiler-confusion-headers/569022/2

// https://community.platformio.org/t/c-stl-on-an-avr-platform/10351
//     https://www.etlcpp.com/
//     https://github.com/mike-matera/ArduinoSTL

void setup()
{
    // Initialize serial output
    Serial.begin(SERIAL_BAUDRATE);
    while (!Serial)
        yield();
    Serial.println();
    Serial.println(F("Starting OpenDTU"));

    // Read configuration values
    // Serial.print(F("Reading configuration... "));
    // if (!Configuration.read()) {
    //     Serial.print(F("initializing... "));
    //     Configuration.init();
    //     if (Configuration.write()) {
    //         Serial.print(F("written... "));
    //     } else {
    //         Serial.print(F("failed... "));
    //     }
    // }
    // if (Configuration.get().Cfg_Version != CONFIG_VERSION) {
    //     Serial.print(F("migrated... "));
    //     Configuration.migrate();
    // }
    // Serial.println(F("done"));

    // Initialize NTP
    // Serial.print(F("Initialize NTP... "));
    // NtpSettings.init();
    // Serial.println(F("done"));

    // Initialize inverter communication
    Serial.print(F("Initialize Hoymiles interface... "));
    // CONFIG_T& config = Configuration.get();
    Hoymiles.init();
    Hoymiles.getRadio()->setPALevel(RF24_PA_MAX); // (rf24_pa_dbm_e)config.Dtu_PaLevel);
    Hoymiles.getRadio()->setDtuSerial(12345); // TODO config.Dtu_Serial);
    Hoymiles.setPollInterval(60); // TODOconfig.Dtu_PollInterval);

    Hoymiles.addInverter(
                "Meiner",
                1234555);
    // for (uint8_t i = 0; i < 10; /*TODO INV_MAX_COUNT;*/ i++) {
    //     if (config.Inverter[i].Serial > 0) {
    //         auto inv = Hoymiles.addInverter(
    //             config.Inverter[i].Name,
    //             config.Inverter[i].Serial);

    //         for (uint8_t c = 0; c < 10; /*TODO INV_MAX_COUNT;*/ c++) {
    //             inv->Statistics()->setChannelMaxPower(c, config.Inverter[i].MaxChannelPower[c]);
    //         }
    //     }
    // }
    Serial.println(F("done"));
}

void loop()
{
    // NetworkSettings.loop();
    // yield();
    Hoymiles.loop();
    yield();
    // MqttPublishing.loop();
    // yield();
    // MqttHassPublishing.loop();
    // yield();
    // WebApi.loop();
    // yield();
}