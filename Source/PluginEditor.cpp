/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
GainAudioProcessorEditor::GainAudioProcessorEditor (GainAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    
    addAndMakeVisible(slider1);
    slider1.setRange(0,2,0.001);
    slider1.setSliderStyle(Slider::LinearBar);
    slider1.setTextBoxStyle(Slider::TextBoxLeft, false, 60, 40);
    slider1.addListener(this);
    slider1.setValue(processor.gain);
    
    
    addAndMakeVisible(slider2);
    slider2.setRange(0,50,0.01);
    slider2.setSliderStyle(Slider::LinearBar);
    slider2.setTextBoxStyle(Slider::TextBoxLeft, false, 60, 40);
    slider2.addListener(this);
    slider2.setValue(processor.threshold);
    
    
    setSize (400, 300);
    
}

GainAudioProcessorEditor::~GainAudioProcessorEditor()
{
}

//==============================================================================
void GainAudioProcessorEditor::paint (Graphics& g)
{
    g.fillAll (Colours::white);

    g.setColour (Colours::black);
    g.setFont (15.0f);
    
}

void GainAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    slider1.setBounds(100, 50, 150, 100);
    slider2.setBounds(100, 200, 150, 100);
}


void GainAudioProcessorEditor::sliderValueChanged(Slider* slider)
{
    if (slider == &slider1)
        processor.gain = slider1.getValue();
    if (slider == &slider2)
        processor.threshold = slider2.getValue();
}

void GainAudioProcessorEditor::timerCallback()
{
    startTimer(50);
}
