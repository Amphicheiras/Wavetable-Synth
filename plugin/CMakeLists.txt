cmake_minimum_required(VERSION 3.5)

project(WavetableSynth VERSION 0.1.0)

set(INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include/WavetableSynth")

juce_add_plugin(${PROJECT_NAME}
    COMPANY_NAME _UF0
    IS_SYNTH TRUE
    NEEDS_MIDI_INPUT TRUE
    NEEDS_MIDI_OUTPUT FALSE
    PLUGIN_MANUFACTURER_CODE UF00
    PLUGIN_CODE WTSY
    FORMATS Standalone VST3
    PRODUCT_NAME "SinThesizer"
)

target_sources(${PROJECT_NAME}
    PRIVATE
        src/PluginEditor.cpp
        src/PluginProcessor.cpp
        src/WavetableOscillator.cpp
        src/WavetableSynth.cpp
        ${INCLUDE_DIR}/PluginEditor.h
        ${INCLUDE_DIR}/PluginProcessor.h
        ${INCLUDE_DIR}/WavetableOscillator.h
        ${INCLUDE_DIR}/WavetableSynth.h
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        juce::juce_audio_utils
    PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_lto_flags
        juce::juce_recommended_warning_flags
)

target_compile_definitions(${PROJECT_NAME}
    PUBLIC
        JUCE_WEB_BROWSER=0
        JUCE_USE_CURL=0
        JUCE_VST3_CAN_REPLACE_VST2=0
)

if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4 /WX)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic)
endif()

## ***** COMMENT-OUT IF USING LOCAL JUCE LIB ******
# source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR}/..)
## ************************************************