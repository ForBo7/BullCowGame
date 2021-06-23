// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
	PrintLine(TEXT("Greetings, traveler!"));
	PrintLine(TEXT("To type something, press tab then type and hit enter."));
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
	ClearScreen();
	FString HiddenWord = TEXT("code");
	PrintLine(Input);
}
