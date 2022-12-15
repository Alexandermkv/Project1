// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include <Runtime/UMG/Public/Components/TextBlock.h>
#include "GameFramework/Actor.h"
#include "ActorSpawnerWidget.generated.h"
/**
*
*/
UCLASS(Blueprintable)
class MYPROJECT2_API UActorSpawnerWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	void NativePreConstruct() override;
	UPROPERTY(EditAnywhere)
		FText DraggedName;
	virtual void NativeConstruct() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;
	FReply NativeOnMouseButtonDown(const FGeometry& InGeometry,
		const FPointerEvent& InMouseEvent) override;
protected:
	UPROPERTY(meta = (BindWidgetOptional))
		UTextBlock* DraggedText;
	UPROPERTY(EditAnywhere)
		TSubclassOf<AActor> DraggedActorClass;
	UPROPERTY()
		AActor* DraggedActor;
	UPROPERTY()
		APlayerController* PlayerController;
	void OnMouseButtonUp();
};

