/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"
//==============================================================================
MainComponent::MainComponent()
{
    setSize (500, 400);

	param1.setSliderStyle(Slider::SliderStyle::LinearBarVertical);
	param1.setTextBoxStyle(Slider::TextBoxAbove, true, 60, 20);
	param1.setColour(Slider::backgroundColourId, Colours::azure);
	param1.setRange(0.0,1.0);
	addAndMakeVisible(&param1);

	label1.setText("P1", NotificationType::dontSendNotification);
	addAndMakeVisible(&label1);

	param2.setSliderStyle(Slider::SliderStyle::LinearBarVertical);
	param2.setTextBoxStyle(Slider::TextBoxAbove, true, 60, 20);
	param2.setColour(Slider::backgroundColourId, Colours::azure);
	param2.setRange(0.0, 1.0);
	
	addAndMakeVisible(&param2);

	label2.setText("P2", NotificationType::dontSendNotification);
	addAndMakeVisible(&label2);

	param3.setSliderStyle(Slider::SliderStyle::LinearBarVertical);
	param3.setTextBoxStyle(Slider::TextBoxAbove, true, 60, 20);
	param3.setColour(Slider::backgroundColourId, Colours::azure);
	param3.setRange(0.0, 1.0);
	
	addAndMakeVisible(&param3);

	label3.setText("P3", NotificationType::dontSendNotification);
	addAndMakeVisible(&label3);

	param4.setSliderStyle(Slider::SliderStyle::LinearBarVertical);
	param4.setTextBoxStyle(Slider::TextBoxAbove, true, 60, 20);
	param4.setColour(Slider::backgroundColourId, Colours::azure);
	param4.setRange(0.0, 1.0);
	
	addAndMakeVisible(&param4);

	label4.setText("P4", NotificationType::dontSendNotification);
	addAndMakeVisible(&label4);

	param5.setSliderStyle(Slider::SliderStyle::LinearBarVertical);
	param5.setTextBoxStyle(Slider::TextBoxAbove, true, 60, 20);
	param5.setColour(Slider::backgroundColourId, Colours::azure);
	param5.setRange(0.0, 1.0);
	
	addAndMakeVisible(&param5);

	label5.setText("P5", NotificationType::dontSendNotification);
	addAndMakeVisible(&label5);


		//Couldn't connect.
	if (!sender.connect("127.0.0.1", 6448))
	{
		AlertWindow::showMessageBox(AlertWindow::AlertIconType::WarningIcon, "Connection error", "Couldn't connect!", "OK");
	}

	startTimer(50);


	

}

MainComponent::~MainComponent()
{
}

//==============================================================================
void MainComponent::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));
    g.setFont (Font (16.0f));
    g.setColour (Colours::white);
	g.drawFittedText("Message is \"/wek/inputs\" with 5 inputs. Created by Tarcan Gul", getWidth()/25, getHeight() * 9 / 10, getWidth(), getHeight() / 10, Justification::centredLeft,3);
}

void MainComponent::resized()
{
    // This is called when the MainComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
	int w = getWidth();
	int h = getHeight();

	param1.setBounds(w/25, 3*h/50,3*w/25,h/2 + h/5);
	label1.setBounds(w/25,  8* h / 10, w/10,h/10);

	param2.setBounds(6*w / 25, 3 * h / 50, 3 * w / 25, h / 2 + h / 5);
	label2.setBounds(6*w / 25, 8 * h / 10, w / 10, h / 10);

	param3.setBounds(11*w / 25, 3 * h / 50, 3 * w / 25, h / 2 + h / 5);
	label3.setBounds(11*w / 25, 8 * h / 10, w / 10, h / 10);

	param4.setBounds(16*w / 25, 3 * h / 50, 3 * w / 25, h / 2 + h / 5);
	label4.setBounds(16*w / 25, 8 * h / 10, w / 10, h / 10);

	param5.setBounds(21*w / 25, 3 * h/ 50, 3 * w / 25, h / 2 + h / 5);
	label5.setBounds(21*w / 25, 8 * h / 10, w / 10, h / 10);
}

void MainComponent::timerCallback() 
{
	if (!sendOsc())
	{
		AlertWindow::showMessageBox(AlertWindow::AlertIconType::WarningIcon, "Connection error", "Couldn't send message!", "OK");
		stopTimer();
	}

}

bool MainComponent::sendOsc() 
{
	OSCMessage message(OSCAddressPattern("/wek/inputs"));
	message.addFloat32(param1.getValue());
	message.addFloat32(param2.getValue());
	message.addFloat32(param3.getValue());
	message.addFloat32(param4.getValue());
	message.addFloat32(param5.getValue());
	return sender.send(message);
}
