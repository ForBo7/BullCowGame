// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

// When game starts.
void UBullCowCartridge::BeginPlay()
{
    Super::BeginPlay();
	PrintLine(TEXT("Greetings, traveler!"));
	// TODO: Remove magic number below.
	PrintLine(TEXT("Guess the 4 letter word."));
	
	SetUpGame();
}

// When the player hits enter.
void UBullCowCartridge::OnInput(const FString& Input)
{
	ClearScreen();
	if (Input == HiddenWord)
	{
		PrintLine(TEXT("You guessed the correct word!"));
	}
	else
	{
		// Check if right number of characters.
		if (Input.Len() != HiddenWord.Len())
		{
			// TODO: Remove magic number below.
			PrintLine(TEXT("The hidden word is 4 characters long."));
		}
		// Check if isogram.
		// If lives > 0, remove life.
		PrintLine(TEXT("You guessed incorrectly!"));
	}
	// If lives are zero or less, end game.
	// Print losing message.
	// Reveal the word.
}

void UBullCowCartridge::SetUpGame()
{
	HiddenWord = TEXT("code");
	// TODO: Set lives based on length of hidden word.
	Lives = 4;
}
