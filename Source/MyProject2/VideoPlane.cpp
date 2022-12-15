// Fill out your copyright notice in the Description page of Project Settings.


#include "VideoPlane.h"

// Sets default values
AVideoPlane::AVideoPlane()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AVideoPlane::BeginPlay()
{
	Super::BeginPlay();
	if (MediaPlayer)
	{
		FString Path; //= "C:\\Users\\79046\\Videos\\Captures\\MyProject2 - Unreal Editor 2022-11-24 01-51-05.mp4"
		TArray<FString> OutFileNames;
		IDesktopPlatform* DesktopPlatform = FDesktopPlatformModule::Get();
		if (DesktopPlatform)
		{
			FString FileTypes = "All Files(*.PNG;*.JPG;*.MP4)|*.PNG;*.JPG;*.MP4|"
				"Image Files(*.PNG;*.JPG;)|*.PNG;*.JPG;|"
				"Video Files(*.MP4)|*.MP4";
			uint32 SelectionFlag = 0;
			DesktopPlatform->OpenFileDialog(
				FSlateApplication::Get().FindBestParentWindowHandleForDialogs(nullptr),
				"Choose content", "", "", FileTypes, SelectionFlag, OutFileNames);
			if (OutFileNames.Num() > 0)
			{
				Path = OutFileNames[0];
			}
		}
		UFileMediaSource* MediaSource = NewObject<UFileMediaSource>();
		MediaSource->FilePath = Path;
		MediaPlayer->OpenSource(MediaSource);

		UMediaSoundComponent* Comp = NewObject<UMediaSoundComponent>(this);
		Comp->SetMediaPlayer(MediaPlayer);
		Comp->RegisterComponent();

		UTexture2D* Texture = UKismetRenderingLibrary::ImportFileAsTexture2D(this,Path);
		//Image->SetBrushFromTexture(Texture, true);
	}
}

// Called every frame
void AVideoPlane::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

