cmake_minimum_required(VERSION 3.22)
project(LIMIT1 VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_INSTALL_PREFIX ${CMAKE_BINARY_DIR}/install)
set(JUCE_ENABLE_MODULE_SOURCE_GROUPS ON)
set(JUCE_COPY_PLUGIN_AFTER_BUILD FALSE)

add_subdirectory(JUCE)

juce_add_gui_app(LIMIT1
    PRODUCT_NAME "LIMIT-1"
    BUNDLE_ID "com.arcsinengineering.limit1"
    MICROPHONE_PERMISSION_ENABLED TRUE
    IPHONE_SCREEN_ORIENTATIONS UIInterfaceOrientationPortrait
    REQUIRES_FULL_SCREEN TRUE
)

set_target_properties(LIMIT1 PROPERTIES
    XCODE_ATTRIBUTE_DEVELOPMENT_TEAM "$ENV{DEVELOPMENT_TEAM}"
    XCODE_ATTRIBUTE_CODE_SIGN_STYLE "Automatic"
)

juce_generate_juce_header(LIMIT1)

target_sources(LIMIT1 PRIVATE
    Source/Main.cpp
    Source/Audio/AudioEngine.h
    Source/Audio/AudioEngine.cpp
    Source/Audio/AudioEngineHost.h
    Source/Audio/AudioEngineHost.cpp
)

target_compile_definitions(LIMIT1 PUBLIC
    JUCE_WEB_BROWSER=0
    JUCE_USE_CURL=0
)

target_link_libraries(LIMIT1 PRIVATE
    juce::juce_audio_utils
    juce::juce_audio_processors
    juce::juce_dsp
    juce::juce_core
    juce::juce_recommended_config_flags
    juce::juce_recommended_warning_flags
)
