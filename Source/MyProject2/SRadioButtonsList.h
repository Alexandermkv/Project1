// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"
#include "RadioButtonsWidgetStyle.h"

UENUM(BlueprintType)

enum class ERadioChoice : uint8
{
	Radio0,
	Radio1,
	Radio2,
};

DECLARE_DELEGATE_OneParam(FOnRadioChoiceChanged, ERadioChoice);
/**
*
*/
class MYPROJECT2_API SRadioButtonsList : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SRadioButtonsList)
	{}
	/** The visual style of the radio button */
	SLATE_STYLE_ARGUMENT(FRadioButtonsStyle, Style)
	/** Called when radio choiñe is changed */
	SLATE_EVENT(FOnRadioChoiceChanged, OnRadioChoiceChanged)
	
	SLATE_END_ARGS()
	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);
	/** See ButtonStyle attribute */
	void SetRadioButtonStyle(const FRadioButtonsStyle* InStyle);

protected:

	ERadioChoice CurrentChoice;
	FOnRadioChoiceChanged OnRadioChoiceChanged;
	ECheckBoxState IsRadioButtonChecked(ERadioChoice RadioButtonID);
	/** Style resource for check boxes */
	const FCheckBoxStyle* CheckBoxStyle;
	/** Style resource for text */
	const FTextBlockStyle* TextStyle;

	void HandleRadioButtonStateChanged(ECheckBoxState NewRadioState,ERadioChoice RadioButtonID);
	TSharedRef<SWidget> CreateRadioButton(const FString& RadioText,ERadioChoice RadioButtonChoice);
};
