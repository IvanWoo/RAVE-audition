/*
  ==============================================================================

    EngineUpdater.h
    Author:  Andrew Fyfe

  ==============================================================================
*/

#pragma once
#include "PluginProcessor.h"
#include <JuceHeader.h>

class RAVEAuditionAudioProcessor; // forward declare

//  ==============================================================================

class UpdateEngineJob  : public juce::ThreadPoolJob
{
public:
    explicit UpdateEngineJob(RAVEAuditionAudioProcessor& processor, const std::string modelPath);
    virtual ~UpdateEngineJob();
    virtual auto runJob() -> JobStatus;
    bool waitForFadeOut(size_t waitTimeMs);
    
private:
    RAVEAuditionAudioProcessor& mProcessor;
    const std::string mModelFile;
    // Prevent uncontrolled usage
    UpdateEngineJob(const UpdateEngineJob&);
    UpdateEngineJob& operator=(const UpdateEngineJob&);
    
};

//  ==============================================================================
