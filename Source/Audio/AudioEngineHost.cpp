// AudioEngineHost.cpp

#include "AudioEngineHost.h"

AudioEngineHost::AudioEngineHost()
{
    deviceManager.addAudioCallback(&player);
    player.setProcessor(&engine);

    auto error = deviceManager.initialiseWithDefaultDevices(2, 2);
    if (error.isNotEmpty())
        DBG("AudioDeviceManager error: " + error);
}

AudioEngineHost::~AudioEngineHost()
{
    player.setProcessor(nullptr);
    deviceManager.removeAudioCallback(&player);
}
