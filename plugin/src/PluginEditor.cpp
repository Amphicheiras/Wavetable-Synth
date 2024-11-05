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

	setSize(200, 100);
	startTimer(100);
}

PluginEditor::~PluginEditor()
{
}

//==============================================================================
void PluginEditor::paint(juce::Graphics &g)
{
	g.fillAll(juce::Colours::blueviolet);

	// addAndMakeVisible(playStopButton);
	// addAndMakeVisible(playStopButtonLabel);
}

void PluginEditor::resized()
{
	playStopButton.setBounds({10, 10, 10, 10});
	playStopButtonLabel.setBounds({10, 10, 10, 10});
	noteLabel.setBounds((getWidth() - 100) / 2, (getHeight() - 100) / 2, 100, 100);
}

void PluginEditor::updateNoteDisplay(int noteNumber)
{
	if (noteNumber >= 0)
		noteLabel.setText("Note: " + juce::String(midiNoteToString(noteNumber)), juce::dontSendNotification);
	else
		noteLabel.setText("Note: No note", juce::dontSendNotification);
	DBG(noteLabel.getWidth());
}

void PluginEditor::timerCallback()
{
	int currentNote = audioProcessor.getLastNote(); // Get the last note from processor
	updateNoteDisplay(currentNote);
}

// Function to convert MIDI note number to note name
juce::String PluginEditor::midiNoteToString(int midiNote)
{
	// MIDI note numbers range from 0 (C-1) to 127 (G9)
	static const char *noteNames[] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};

	// Calculate octave and note name
	if (midiNote < 0 || midiNote > 127)
		return "Invalid Note";

	int octave = (midiNote / 12) - 2; // Octave starts at C-1 (MIDI note 0)
	int noteIndex = midiNote % 12;	  // Note name index

	// Return the formatted note name
	return juce::String(noteNames[noteIndex]) + juce::String(octave);
}