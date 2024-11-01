/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "WavetableSynth/PluginProcessor.h"
#include "WavetableSynth/PluginEditor.h"

//==============================================================================
WavetableSynthAudioProcessorEditor::WavetableSynthAudioProcessorEditor(WavetableSynthAudioProcessor &p)
    : AudioProcessorEditor(&p), audioProcessor(p)
{
  addAndMakeVisible(playStopButtonLabel);
  playStopButtonLabel.setText("Play/Stop", juce::dontSendNotification);
  // Make sure that before the constructor has finished, you've set the
  // editor's size to whatever you need it to be.
  setSize(400, 300);
}

WavetableSynthAudioProcessorEditor::~WavetableSynthAudioProcessorEditor()
{
}

//==============================================================================
void WavetableSynthAudioProcessorEditor::paint(juce::Graphics &g)
{
  // (Our component is opaque, so we must completely fill the background with a solid colour)
  g.fillAll(getLookAndFeel().findColour(juce::ResizableWindow::backgroundColourId));

  g.setColour(juce::Colours::white);
  g.setFont(juce::FontOptions(15.0f));
  g.drawFittedText("Sin Thesizer", getLocalBounds(), juce::Justification::centred, 1);
  // addAndMakeVisible(playStopButton);
  // addAndMakeVisible(playStopButtonLabel);
}

void WavetableSynthAudioProcessorEditor::resized()
{
  playStopButton.setBounds({10, 10, 10, 10});
  playStopButtonLabel.setBounds({10, 10, 10, 10});
}
