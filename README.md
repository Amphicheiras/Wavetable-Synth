# Wavetable Synthesizer Audio Plugin


## Features



## Getting Started
### Prerequisites

- JUCE Framework: Required for building and running the plugin. Download from JUCE.
- Supported DAWs: Any Digital Audio Workstation that supports VST, AU, or standalone plugins.
- Compiler: Ensure a compatible C++ compiler is installed. For Windows, MSVC is recommended, while Xcode works well on macOS.

### Installation

1. Clone the repository:
    ```sh
     git clone https://github.com/Amphicheiras/Wavetable-Synth.git
     cd Wavetable-Synth
    ```

2. Configure with CMake:
   ```sh
   cmake -S . -B build
   ```

3. Compile with CMake:
   ```sh
   cmake --build build
   ```

### Usage

1. Load the Plugin:
   After compiling, load the plugin in a supported DAW or run as a standalone application if built as such.
2. Place the Synth in a MIDI channel and play a MIDI note!

### Code Overview


### Parameters


### Contributing

Contributions are welcome! Please fork this repository, create a branch, and submit a pull request for any improvements or bug fixes.

### Issues

If you encounter bugs or have feature requests, please report them in the Issues section of this repository.

### License

This project is licensed under the GNU GPL-3.0 License - see the LICENSE file for details.

### Acknowledgments

Special thanks to the open-source audio community and JUCE for their continuous support and resources.

Super special thanks to Jan Wilczek!

# Useful Links

- [JUCE with CMake](https://www.youtube.com/watch?v=Uq7Hwt18s3s)
