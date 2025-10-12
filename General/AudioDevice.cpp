#define MINIAUDIO_IMPLEMENTATION
#include "AudioDevice.h"
#include <iostream>

// Constructor initializes and starts the audio device.
AudioDevice::AudioDevice() : volume(1.0f) { // Default volume to 1.0 (max)
    ma_device_config config = ma_device_config_init(ma_device_type_playback);
    config.playback.format = ma_format_f32;
    config.playback.channels = 2;
    config.sampleRate = 44100;
    config.dataCallback = AudioDevice::data_callback;
    config.pUserData = this; // Pass 'this' so the callback can access instance data.

    if (ma_device_init(NULL, &config, &device) != MA_SUCCESS) {
        std::cerr << "Failed to initialize playback device." << std::endl;
    }

    if (ma_device_start(&device) != MA_SUCCESS) {
        std::cerr << "Failed to start device." << std::endl;
        ma_device_uninit(&device);
    }
}

// Destructor uninitializes the device.
AudioDevice::~AudioDevice() {
    ma_device_uninit(&device);
}

// Set the volume (0.0 to 1.0).
void AudioDevice::setVolume(float newVolume) {
    volume = (newVolume < 0.0f) ? 0.0f : (newVolume > 1.0f) ? 1.0f : newVolume;
}

// Get the current volume.
float AudioDevice::getVolume() const {
    return volume;
}

// Pause the audio playback.
void AudioDevice::pause() {
    ma_device_stop(&device);
}

// Resume the audio playback.
void AudioDevice::resume() {
    ma_device_start(&device);
}

// Static callback function to process audio data.
void AudioDevice::data_callback(ma_device *pDevice, void *pOutput, const void *pInput, ma_uint32 frameCount) {
    AudioDevice *audioDevice = (AudioDevice *)pDevice->pUserData;
    float *output = (float *)pOutput;

    // Generate silence or modify the buffer with the current volume.
    for (ma_uint32 i = 0; i < frameCount; ++i) {
        output[i] = 0.0f * audioDevice->volume; // Replace this with actual audio processing logic
    }
}
