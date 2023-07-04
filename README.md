# Echo Device

Simple device which answers with the message which has been received.

## System requirements

The software is configured to run on the development board [ESP32-S3-DevKitC-1 v1.1](https://docs.espressif.com/projects/esp-idf/en/latest/esp32s3/hw-reference/esp32s3/user-guide-devkitc-1.html#esp32-s3-devkitc-1-v1-1).

## Deployment

### Generate the documentation

Documentation may be generated with [Doxygen](https://www.doxygen.org/).
Simply call in the root directory of this repository:

    doxygen

The HTML documentation will be written to [`doc/html/index.xhtml`](doc/html/index.xhtml).

### Build and Upload the Software

This project uses [PlatformIO](https://platformio.org/) as build system and package manager.
PlatformIO may be used via a GUI (PlatformIO IDE) or command line interface (PlatformIO Core). The project configuration ([`platformio.ini`](platformio.ini)) is part of this repository.

In order to use the software (some call it "firmware"), the following steps are required:

1. Build (the default configuration of) the project.
   For example via:
   ```
   platformio run
   ```
2. Connect the device with the host system (where you build the software).
3. Upload the built binary to the device.
   For example via:
   ```
   platformio run --target upload
   ```

Please refer to the [PIO documentation](https://docs.platformio.org/) for detailed instructions.

### Simulate

The Visual Studio Code extension [Wokwi Simulator](https://marketplace.visualstudio.com/items?itemName=wokwi.wokwi-vscode) may be used to simulate the software on the device.
The project configuration for the simulator is provided as [`wokwi.toml`](wokwi_files/wokwi.toml).

Note, that you must build the software (using the default build configuration) before it can be simulated.

Please refer to the documentation of the simulator for instructions on how to simulate the device.

## User manual

1. Build and upload the software.
2. Physically [connect](https://docs.espressif.com/projects/esp-idf/en/latest/esp32s3/get-started/establish-serial-connection.html#usb-to-uart-bridge-on-development-board) the UART port of the development board to the personal computer (does not apply to the simulation).
   Installing drivers may be necessary.
3. Open a serial terminal using the following settings:
   - Baud rate: `9600`
   - Data bits: `8`
   - Stop bits: `1`
   - Parity: none
4. Type and send a line.
5. The device will answer
   ```
   Echo:    '<your message>'
   ```
