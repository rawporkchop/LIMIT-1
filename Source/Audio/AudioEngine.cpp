// AudioEngine.cpp

#include "AudioEngine.h"


AudioEngine::AudioEngine()
    : AudioProcessor(BusesProperties()
        .withInput ("Input",  juce::AudioChannelSet::stereo(), true)
        .withOutput("Output", juce::AudioChannelSet::stereo(), true))
{}

void AudioEngine::prepareToPlay(double sampleRate, int samplesPerBlock)
{
    juce::ignoreUnused(sampleRate, samplesPerBlock);
}

void AudioEngine::releaseResources() {}

void AudioEngine::processBlock(juce::AudioBuffer<float>& buffer,
                               juce::MidiBuffer& midiMessages)
{
    juce::ignoreUnused(midiMessages);
    // Pass-through: JUCE fills buffer with input, we return it untouched
}
