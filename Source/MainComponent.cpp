#include "MainComponent.h"

/*
SVG Path Converterで変換したパス
Google Material icon create_new_folder
https://material.io/resources/icons/?icon=create_new_folder&style=outline
*/
static const unsigned char pathData[] = {110, 109, 0, 0, 160, 65, 0, 0, 192, 64, 108, 0, 0, 64, 65, 0, 0, 192, 64, 108, 0, 0, 32, 65, 0, 0, 128, 64, 108, 0, 0, 128, 64, 0, 0, 128, 64, 98, 194, 245, 56, 64, 0, 0, 128, 64, 215, 163, 0, 64, 225, 122, 156, 64, 215, 163, 0, 64, 0, 0, 192, 64, 108, 0, 0, 0, 64, 0, 0, 144, 65, 98, 0, 0, 0, 64, 72, 225, 152, 65, 194, 245, 56, 64,
										 0, 0, 160, 65, 0, 0, 128, 64, 0, 0, 160, 65, 108, 0, 0, 160, 65, 0, 0, 160, 65, 98, 72, 225, 168, 65, 0, 0, 160, 65, 0, 0, 176, 65, 72, 225, 152, 65, 0, 0, 176, 65, 0, 0, 144, 65, 108, 0, 0, 176, 65, 0, 0, 0, 65, 98, 0, 0, 176, 65, 225, 122, 220, 64, 72, 225, 168, 65, 0, 0, 192, 64, 0, 0, 160, 65, 0, 0, 192, 64, 99, 109, 0, 0, 160, 65,
										 0, 0, 144, 65, 108, 0, 0, 128, 64, 0, 0, 144, 65, 108, 0, 0, 128, 64, 0, 0, 192, 64, 108, 82, 184, 18, 65, 0, 0, 192, 64, 108, 82, 184, 50, 65, 0, 0, 0, 65, 108, 0, 0, 160, 65, 0, 0, 0, 65, 108, 0, 0, 160, 65, 0, 0, 144, 65, 99, 109, 0, 0, 64, 65, 0, 0, 96, 65, 108, 0, 0, 96, 65, 0, 0, 96, 65, 108, 0, 0, 96, 65, 0, 0, 128, 65, 108, 0, 0,
										 128, 65, 0, 0, 128, 65, 108, 0, 0, 128, 65, 0, 0, 96, 65, 108, 0, 0, 144, 65, 0, 0, 96, 65, 108, 0, 0, 144, 65, 0, 0, 64, 65, 108, 0, 0, 128, 65, 0, 0, 64, 65, 108, 0, 0, 128, 65, 0, 0, 32, 65, 108, 0, 0, 96, 65, 0, 0, 32, 65, 108, 0, 0, 96, 65, 0, 0, 64, 65, 108, 0, 0, 64, 65, 0, 0, 64, 65, 99, 101, 0, 0};

//==============================================================================
MainComponent::MainComponent()
{
	juce::Path path;
	path.loadPathFromData(pathData, sizeof(pathData)); // SVG Path Converterで変換したパスを読み込む

	// Push button
	addAndMakeVisible(pushButton);
	pushButton.setBounds(50, 100, 200, 200); //ボタンの表示領域 x, y, width, height
	pushButton.setShape(path,
						false, //ShapeButtonをPathのサイズにリサイズするか
						true,	 //元素材のアスペクト比をキープするか
						false);//ドロップシャドウ効果をつけるか

	// Toggle button
	addAndMakeVisible(toggleButton);
	toggleButton.setBounds(350, 100, 200, 200); //ボタンの表示領域 x, y, width, height
	toggleButton.setShape(path,
						  false, //ShapeButtonをPathのサイズにリサイズするか
						  true,	 //元素材のアスペクト比をキープするか
						  false);//ドロップシャドウ効果をつけるか

	toggleButton.setOnColours(juce::Colours::lawngreen, //ON状態の通常時の色
														juce::Colours::lawngreen, //ON状態のマウスオーバー時の色
														juce::Colours::lawngreen);//ON状態のクリック時の色
	toggleButton.shouldUseOnColours(true);//ON状態の色を使用する
	toggleButton.setClickingTogglesState(true);//トグルボタン化

	setSize(600, 400);
}

MainComponent::~MainComponent()
{
}

//==============================================================================
void MainComponent::paint(juce::Graphics &g)
{
	g.fillAll(getLookAndFeel().findColour(juce::ResizableWindow::backgroundColourId));
	g.setFont(juce::Font(24.0f));
	g.setColour(juce::Colours::white);
	g.drawText("Push button", 50, 50, 200, 50, juce::Justification::centred);
	g.drawText("Toggle button", 350, 50, 200, 50, juce::Justification::centred);
}

void MainComponent::resized()
{
}
