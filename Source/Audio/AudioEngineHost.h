// AudioEngineHost.h

#pragma once
#include <JuceHeader.h>
#include "AudioEngine.h"


class AudioEngineHost
{
public:
    AudioEngineHost();
    ~AudioEngineHost();

    AudioEngine& getEngine() { return engine; }

private:
    AudioEngine engine;
    juce::AudioProcessorPlayer player;
    juce::AudioDeviceManager deviceManager;
};
