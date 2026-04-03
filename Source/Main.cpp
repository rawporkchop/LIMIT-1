#include <JuceHeader.h>

class LIMIT1Application : public juce::JUCEApplication
{
public:
    const juce::String getApplicationName() override    { return "LIMIT-1"; }
    const juce::String getApplicationVersion() override { return "0.1.0"; }

    void initialise(const juce::String&) override {}
    void shutdown() override {}
};

START_JUCE_APPLICATION(LIMIT1Application)
