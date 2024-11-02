/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "juce_audio_basics/juce_audio_basics.H"
#include "WavetableSynth/PluginProcessor.h"

//==============================================================================
/**
 */
class PluginEditor : public juce::AudioProcessorEditor, public juce::Timer
{
public:
  PluginEditor(PluginProcessor &);
  ~PluginEditor() override;

  //==============================================================================
  void paint(juce::Graphics &) override;
  void resized() override;

private:
  // This reference is provided as a quick way for your editor to
  // access the processor object that created it.
  PluginProcessor &audioProcessor;

  // Button, Attachment & Label for play stop
  juce::ToggleButton playStopButton;
  std::unique_ptr<juce::AudioProcessorValueTreeState::ButtonAttachment>
      playStopAttachment;
  juce::Label playStopButtonLabel;
  juce::Label noteLabel;

  void updateNoteDisplay(int noteNumber);

  void timerCallback() override;

  JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PluginEditor)
};
