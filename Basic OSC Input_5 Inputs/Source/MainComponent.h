/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent   : public Component,
	public Timer
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
	void timerCallback() override;
	bool sendOsc();

private:
    //==============================================================================
    // Your private member variables go here...
	Slider param1;
	Label label1;
	Slider param2;
	Label label2;
	Slider param3;
	Label label3;
	Slider param4;
	Label label4;
	Slider param5;
	Label label5;
	OSCSender sender;
	double value1;
	double value2;
	double value3;
	double value4;
	double value5;

	

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
