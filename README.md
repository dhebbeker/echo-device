# Embedded-Software-Base
Base for embedded software.

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
