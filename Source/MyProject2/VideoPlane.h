// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <Runtime/MediaAssets/Public/MediaPlayer.h>
#include "FileMediaSource.h"
#include "MediaSoundComponent.h"
#include <Developer/DesktopPlatform/Public/IDesktopPlatform.h>
#include <Developer/DesktopPlatform/Public/DesktopPlatformModule.h>
#include <Runtime/Engine/Classes/Kismet/KismetRenderingLibrary.h>
#include <Runtime/UMG/Public/Components/Image.h>
#include "VideoPlane.generated.h"


UCLASS()
class MYPROJECT2_API AVideoPlane : public AActor
{
	GENERATED_BODY()

	
public:	
	// Sets default values for this actor's properties
	AVideoPlane();
	UPROPERTY(EditAnywhere)
		UMediaPlayer* MediaPlayer;
	/*UPROPERTY(EditAnywhere)
		UImage* Image;*/

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
