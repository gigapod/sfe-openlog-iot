# SparkFun OpenLog IoT

Firmware for the OpenLog IoT - using the flux-sdk

## Current compile line

```sh
arduino-cli compile --fqbn esp32:esp32:esp32 --board-options FlashSize=8M --board-options PartitionScheme=default_8MB ./sfeOpenLogIoT/sfeOpenLogIoT.ino --export-binaries --library `pwd`/SparkFun_OpenScaleIoT
```

## upload/flash command

On a Mac (note --baud needs to be slower)

```sh
esptool.py --chip esp32 --port /dev/tty.usbserial-130 --baud 460800 --before default_reset --after hard_reset write_flash -z --flash_mode dio --flash_freq 80m --flash_size 8MB 0x1000 "./sfeOpenLogIoT/build/esp32.esp32.esp32/sfeOpenLogIoT.ino.bootloader.bin" 0x8000 "./sfeOpenLogIoT/build/esp32.esp32.esp32/sfeOpenLogIoT.ino.partitions.bin" 0x10000 "./sfeOpenLogIoT/build/esp32.esp32.esp32/sfeOpenLogIoT.ino.bin"
```
