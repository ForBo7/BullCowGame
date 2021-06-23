// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

// When game starts.
void UBullCowCartridge::BeginPlay()
{
    Super::BeginPlay();
	PrintLine(TEXT("Greetings, traveler!"));
	// TODO: Remove magic number below.
	PrintLine(TEXT("Guess the 4 letter word."));
	HiddenWord = TEXT("code");
}

// When the player hits enter.
void UBullCowCartridge::OnInput(const FString& Input)
{
	ClearScreen();
	
	if (HiddenWord == Input)
	{
		PrintLine(TEXT("You guessed the correct word!"));
	}
	else
	{
		PrintLine(TEXT("You guessed incorrectly!"));
	}
}
