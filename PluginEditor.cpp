/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
ScscAudioProcessorEditor::ScscAudioProcessorEditor (ScscAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
    , sliderAttachment(audioProcessor.apvts,"testslider", levelSlider)
    , xxxsliderAttachment(audioProcessor.apvts, "xxxtestslider", xxxSlider)
    , EnvAttackAttachment(audioProcessor.apvts, "EnvAttack", EnvAttack)
    , EnvDecayAttachment(audioProcessor.apvts, "EnvDecay", EnvDecay)
    , EnvSustainAttachment(audioProcessor.apvts, "EnvSustain", EnvSustain)
    , EnvReleaseAttachment(audioProcessor.apvts, "EnvRelease", EnvRelease)
    , EnvLevelAttachment(audioProcessor.apvts, "Envlevel", Envlevel)
    , SineButtonAttachment(audioProcessor.apvts, "SineButton", SineButton)
    , SawButtonAttachment(audioProcessor.apvts, "SawButton", SawButton)
    , SquareButtonAttachment(audioProcessor.apvts, "SquareButton", SquareButton)
    , NoiseButtonAttachment(audioProcessor.apvts, "NoiseButton", NoiseButton)
    , AudioWave(p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.

    levelSlider.setRange(-72, 10);//»¬¿éÈ¡Öµ·¶Î§
    levelSlider.setTextBoxStyle(juce::Slider::TextBoxRight, false, 100, 20);
    levelSlider.onValueChange = [this] { juce::Decibels::decibelsToGain((float)levelSlider.getValue()); };//¿ÉÒÔµ±³É»Øµ÷º¯Êý


    xxxSlider.setRange(-72, 10);
    xxxSlider.setTextBoxStyle(juce::Slider::TextBoxRight, false, 100, 20);

    Envlevel.setRange(-72, 10);
    Envlevel.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    Envlevel.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 50, 25);
    Envlevel.setValue(0.5f);

    EnvAttack.setSliderStyle(juce::Slider::LinearVertical);
    EnvDecay.setSliderStyle(juce::Slider::LinearVertical);
    EnvSustain.setSliderStyle(juce::Slider::LinearVertical);
    EnvRelease.setSliderStyle(juce::Slider::LinearVertical);

    EnvAttack.setRange(0, 1000);
    EnvDecay.setRange(0, 1000);
    EnvSustain.setRange(0, 1);
    EnvRelease.setRange(0, 1000);
    EnvAttack.getValue();


    SineButton.setButtonText("sine");
    SawButton.setButtonText("Saw");
    SquareButton.setButtonText("Square");
    NoiseButton.setButtonText("Noise");
    //EnvAttack.setSliderStyle(juce::Slider::LinearBarVertical);
    //EnvAttack.setRange(0.0, 127.0, 1.0);
    //EnvAttack.setTextBoxStyle(juce::Slider::NoTextBox, false, 90, 0);
    //EnvAttack.setPopupDisplayEnabled(true, false, this);
    //EnvAttack.setTextValueSuffix(" Volume");
    //EnvAttack.setValue(1.0);

    addAndMakeVisible(Envlevel);

    addAndMakeVisible(EnvAttack);
    addAndMakeVisible(EnvDecay);
    addAndMakeVisible(EnvSustain);
    addAndMakeVisible(EnvRelease);

    addAndMakeVisible(levelSlider);
    addAndMakeVisible(xxxSlider);
    addAndMakeVisible(AudioWave);

    addAndMakeVisible(SineButton);
    addAndMakeVisible(SawButton);
    addAndMakeVisible(SquareButton);
    addAndMakeVisible(NoiseButton);


    setSize(600, 300);
}

ScscAudioProcessorEditor::~ScscAudioProcessorEditor()
{
}

//==============================================================================
void ScscAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    //g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    //g.setColour (juce::Colours::white);
    //g.setFont (15.0f);
    //g.drawFittedText ("Hello World!", getLocalBounds(), juce::Justification::centred, 1);
    
    //// ½«Õû¸ö´°¿ÚÉèÖÃÎª°×É«
    //g.fillAll(juce::Colours::white);

    //// ½«Í¨ÓÃ»æÖÆÉ«²ÊÉèÖÃÎªºÚÉ«
    //g.setColour(juce::Colours::black);

}
void ScscAudioProcessorEditor::sliderValueChanged(juce::Slider* slider)
{
    //juce::Logger::outputDebugString(juce::String(xxxSlider.getValue()));
}
void ScscAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    levelSlider.setBounds(100, 10, getWidth() - 110, 20);

    xxxSlider.setBounds(100, 50, getWidth() - 110, 20);

    SineButton.setBounds(220,100,70,40);
    SawButton.setBounds(220, 130, 70, 40);
    SquareButton.setBounds(220, 160, 70, 40);
    NoiseButton.setBounds(220, 190, 70, 40);

    EnvAttack.setBounds (400, 100, 20, 100);
    EnvDecay.setBounds  (450, 100, 20, 100);
    EnvSustain.setBounds(500, 100, 20, 100);
    EnvRelease.setBounds(550, 100, 20, 100);

    Envlevel.setBounds(300, 100, 100, 100);

    AudioWave.setBounds(10, 90, 200, 200);

}

