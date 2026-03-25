
/*
 *---------------------------------------------------------------------------------
 *
 * Copyright (c) 2022-2024, SparkFun Electronics Inc.
 *
 * SPDX-License-Identifier: MIT
 *
 *---------------------------------------------------------------------------------
 */

/*
 * SparkFun Data Logger - setup methods
 *
 */
#include "sfeDLBoard.h"
#include "sfeDataLogger.h"

#include <Flux/flxDevSerial.h>

//---------------------------------------------------------------------
// Setup the IOT clients
bool sfeDataLogger::setupIoTClients()
{

    _iotEndpoints.setTitle("Services");
    _iotEndpoints.setName("IoT Services", "IoT Service Connection Drivers");
    // Add title for this section
    _mqttClient.setTitle("IoT Services");
    // setup the network connection for the mqtt
    _mqttClient.setNetwork(&_wifiConnection);
    // add mqtt to JSON
    _fmtJSON.add(_mqttClient);
    _iotEndpoints.push_back(_mqttClient);

    // setup the network connection for the mqtt
    _mqttSecureClient.setNetwork(&_wifiConnection);
    // add mqtt to JSON
    _fmtJSON.add(_mqttSecureClient);

    _iotEndpoints.push_back(_mqttSecureClient);

    // // AWS
    // _iotAWS.setName("AWS IoT", "Connect to an AWS Iot Thing");
    // _iotAWS.setNetwork(&_wifiConnection);

    // // Add the filesystem to load certs/keys from the SD card
    // _iotAWS.setFileSystem(&_theSDCard);
    // _fmtJSON.add(_iotAWS);

    // _iotEndpoints.push_back(_iotAWS);

    // // Thingspeak driver
    // _iotThingSpeak.setNetwork(&_wifiConnection);

    // // Add the filesystem to load certs/keys from the SD card
    // _iotThingSpeak.setFileSystem(&_theSDCard);
    // _fmtJSON.add(_iotThingSpeak);

    // // Add the ThingSpeak driver to the flux system
    // _iotEndpoints.push_back(_iotThingSpeak);

    // // Azure IoT
    // _iotAzure.setNetwork(&_wifiConnection);

    // // Add the filesystem to load certs/keys from the SD card
    // _iotAzure.setFileSystem(&_theSDCard);
    // _fmtJSON.add(_iotAzure);

    // // Add the Azure IoT driver to the flux system
    // _iotEndpoints.push_back(_iotAzure);

    // general HTTP / URL logger
    _iotHTTP.setNetwork(&_wifiConnection);
    _iotHTTP.setFileSystem(&_theSDCard);
    _fmtJSON.add(_iotHTTP);

    // Add the HTTP driver to the flux system
    _iotEndpoints.push_back(_iotHTTP);

    // Web server
    // _iotWebServer.setTitle("Preview");
    // _iotWebServer.setNetwork(&_wifiConnection);
    // _iotWebServer.setFileSystem(&_theSDCard);

    return true;
}

//---------------------------------------------------------------------------
// setupTime()
//
// Setup any time sources/sinks. Called after devices are loaded

bool sfeDataLogger::setupTime()
{

    // what is our clock - as setup from init/prefs
    std::string refClock = flxClock.referenceClock();

    flxClock.addReferenceClock(&_ntpClient, _ntpClient.name());

    // Any GNSS devices attached?
    auto allGNSS = flux.get<flxDevGNSS>();
    for (auto gnss : *allGNSS)
        flxClock.addReferenceClock(gnss, gnss->name());

    // RTC clock?
    auto allRTC8803 = flux.get<flxDevRV8803>();
    for (auto rtc8803 : *allRTC8803)
    {
        flxClock.addReferenceClock(rtc8803, rtc8803->name());
        flxClock.addConnectedClock(rtc8803);
    }

    // Now that clocks are loaded, set the ref clock to what was started with.
    flxClock.referenceClock = refClock;

    // update the system clock to the reference clock
    flxClock.updateClock();

    return true;
    // }

    // //---------------------------------------------------------------------------
    // void sfeDataLogger::setupGNSS(void)
    // {
    //     // do we have one attached?
    //     auto gnssDevices = flux.get<flxDevGNSS>();
    //     if (gnssDevices->size() == 0)
    //         return;

    //     // get the first GNSS device and set the PPS Pin that can be used
    //     flxDevGNSS *pGNSS = gnssDevices->at(0);
    //     if (!pGNSS)
    //         return;

    //     // set the in we use for PPS -- expect the input to be wired to this
    //     pGNSS->setAvailablePPSPins(kDLBoardGNSSPPSPins, sizeof(kDLBoardGNSSPPSPins) /
    //     sizeof(kDLBoardGNSSPPSPins[0]));

    //     // map the GNSS PPS event to the log observation event
    //     flxAddEventAliasWithValue(flxEvent::kOnGNSSPPSEvent, flxEvent::kOnLogObservationWithSource, "PPS");
    // }

    //---------------------------------------------------------------------------
    void sfeDataLogger::setupExtSerial(void)
    {
        // setup the default pins
        _extSerial.rxPin(kDLBoardExtSerialRXPin);
        _extSerial.txPin(kDLBoardExtSerialTXPin);

        // map the data available event to the log observation event
        flxAddEventAliasWithValue(flxEvent::kOnSerialDataAvailable, flxEvent::kOnLogObservationWithSource, "SERIAL");
    }
    //---------------------------------------------------------------------------
    void sfeDataLogger::setInterruptEvent(void)
    {
        _extIntrEvent.setDescription("Trigger a logging event from an interrupt");
        _extIntrEvent.setAvailablePins(kDLBoardInterruptPins,
                                       sizeof(kDLBoardInterruptPins) / sizeof(kDLBoardInterruptPins[0]));

        _extIntrEvent.setEventToSend(flxEvent::kOnLogObservationWithSource);
    }
