#pragma once

#include <JuceHeader.h>

//==============================================================================
class MainComponent  : public juce::Component
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    //==============================================================================
	juce::ShapeButton pushButton{"PushButton",//ボタンの名前（なんでもよい）
		juce::Colours::grey,    //OFF状態の通常時の色
		juce::Colours::white,   //OFF状態のマウスオーバー時の色
		juce::Colours::lawngreen//OFF状態のクリック時の色
	};
	juce::ShapeButton toggleButton{"ToggleButton",//ボタンの名前（なんでもよい）
		juce::Colours::grey,    //OFF状態の通常時の色
		juce::Colours::white,   //OFF状態のマウスオーバー時の色
		juce::Colours::lawngreen//OFF状態のクリック時の色
	};

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
