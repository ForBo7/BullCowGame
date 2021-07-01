// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

// When game starts.
void UBullCowCartridge::BeginPlay()
{
	SetUpGame();
	
	Super::BeginPlay();

	// Debug lines.
	PrintLine(TEXT("The hidden word is %s."), *HiddenWord);
	PrintLine(TEXT("It is %i characters long."), HiddenWord.Len());
	

	PrintLine(TEXT("Greetings, traveler!"));
	PrintLine(TEXT("Guess the %i letter word."), HiddenWord.Len());
	PrintLine(TEXT("You have %i lives."), Lives);
	
	PrintLine(TEXT("\nPress tab to access the terminal."));
	PrintLine(TEXT("Enter to continue."));
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
			PrintLine(TEXT("The hidden word is %i characters long."),
					  HiddenWord.Len());
		}
		else
		{
			PrintLine(TEXT("You guessed incorrectly!"));
		}
		// Check if isogram.
		// If lives > 0, remove life.
	}
	// If lives are zero or less, end game.
	// Print losing message.
	// Reveal the word.
}

void UBullCowCartridge::SetUpGame()
{
	HiddenWord = TEXT("code");
	Lives = HiddenWord.Len();
}
