// Main.cpp

#include <JuceHeader.h>
#include "Audio/AudioEngineHost.h"


class LIMIT1Application : public juce::JUCEApplication
{
public:
    const juce::String getApplicationName() override    { return "LIMIT-1"; }
    const juce::String getApplicationVersion() override { return "0.1.0"; }

    void initialise(const juce::String&) override
    {
        host = std::make_unique<AudioEngineHost>();
    }

    void shutdown() override
    {
        host = nullptr;
    }

private:
    std::unique_ptr<AudioEngineHost> host;
};

START_JUCE_APPLICATION(LIMIT1Application)
