// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "Components/Widget.h"
#include "SRadioButtonsList.h"
#include "RadioButtons.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnRadioChoiceChangedEvent, ERadioChoice, NewRadioChoise);
/**
*
*/
UCLASS()
class MYPROJECT2_API URadioButtons : public UWidget
{
	GENERATED_BODY()

public:
	/** The button style used at runtime */
	UPROPERTY(EditAnywhere, Category = "Appearance", meta = (DisplayName = "Style"))
	FRadioButtonsStyle WidgetStyle;

public:
	/** Called when radio choice changed by click */
	UPROPERTY(BlueprintAssignable, Category = "RadioButtons|Event")
	FOnRadioChoiceChangedEvent OnRadioChoiceChanged;
public:
	//~ Begin UVisual Interface
	virtual void ReleaseSlateResources(bool bReleaseChildren) override;
	//~ End UVisual Interface
protected:
	/** Handle the actual click event from slate and forward it on */
	void HandleOnRadioChoiceChanged(ERadioChoice NewRadioChoise);
protected:
	//~ Begin UWidget Interface
	virtual TSharedRef<SWidget> RebuildWidget() override;
	//~ End UWidget Interface
protected:
	TSharedPtr<SRadioButtonsList> MyRadioButtons;
};
