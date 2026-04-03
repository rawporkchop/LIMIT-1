cmake_minimum_required(VERSION 3.22)
project(LIMIT1 VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(JUCE)

juce_add_gui_app(LIMIT1
    PRODUCT_NAME "LIMIT-1"
    BUNDLE_ID "com.arcsinengineering.limit1"
    MICROPHONE_PERMISSION_ENABLED TRUE
)

juce_generate_juce_header(LIMIT1)

target_sources(LIMIT1 PRIVATE
    Source/Main.cpp
)

target_compile_definitions(LIMIT1 PUBLIC
    JUCE_WEB_BROWSER=0
    JUCE_USE_CURL=0
    JUCE_DISPLAY_SPLASH_SCREEN=0
)

target_link_libraries(LIMIT1 PRIVATE
    juce::juce_audio_utils
    juce::juce_audio_processors
    juce::juce_dsp
    juce::juce_core
    juce::juce_recommended_config_flags
    juce::juce_recommended_warning_flags
)
