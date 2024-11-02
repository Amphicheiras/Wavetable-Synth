/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "WavetableSynth/PluginEditor.h"

//==============================================================================
PluginEditor::PluginEditor(PluginProcessor &p)
    : AudioProcessorEditor(&p), audioProcessor(p)
{
  addAndMakeVisible(playStopButtonLabel);
  playStopButtonLabel.setText("Play/Stop", juce::dontSendNotification);

  noteLabel.setText("Note: ", juce::dontSendNotification);
  noteLabel.setColour(juce::Label::textColourId, juce::Colours::white);
  addAndMakeVisible(noteLabel);

  setSize(400, 300);

  startTimer(100);
}

PluginEditor::~PluginEditor()
{
}

//==============================================================================
void PluginEditor::paint(juce::Graphics &g)
{
  g.fillAll(juce::Colours::blueviolet);

  addAndMakeVisible(playStopButton);
  addAndMakeVisible(playStopButtonLabel);
}

void PluginEditor::resized()
{
  playStopButton.setBounds({10, 10, 10, 10});
  playStopButtonLabel.setBounds({10, 10, 10, 10});
  noteLabel.setBounds(getWidth() / 4, getHeight() / 2 - 10, getWidth() / 2, 20);
}

void PluginEditor::updateNoteDisplay(int noteNumber)
{
  // Display the note if it's valid, otherwise show "No note"
  if (noteNumber >= 0)
    noteLabel.setText("Note: " + juce::String(noteNumber), juce::dontSendNotification);
  else
    noteLabel.setText("Note: No note", juce::dontSendNotification);
}

void PluginEditor::timerCallback()
{
  int currentNote = audioProcessor.getLastNote(); // Get the last note from processor
  if (currentNote >= 0)
    noteLabel.setText("Note: " + juce::String(currentNote), juce::dontSendNotification);
  else
    noteLabel.setText("Note: No note", juce::dontSendNotification);
}