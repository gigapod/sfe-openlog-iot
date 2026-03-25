# SparkFun OpenLog IoT

Firmware for the OpenLog IoT - using the flux-sdk

## Current compile line

arduino-cli compile --fqbn esp32:esp32:esp32 --board-options FlashSize=8M --board-options PartitionScheme=default_8MB ./sfeDataLoggerIoT/sfeDataLoggerIoT.ino  --export-binaries --library `pwd`/SparkFun_OpenScaleIoT
