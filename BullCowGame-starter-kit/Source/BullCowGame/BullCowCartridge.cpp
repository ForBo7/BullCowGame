// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

// When game starts.
void UBullCowCartridge::BeginPlay()
{
	Super::BeginPlay();
	
	SetUpGame();

	// Debug lines.
	PrintLine(TEXT("The hidden word is %s."), *HiddenWord);
	PrintLine(TEXT("It is %i characters long."), HiddenWord.Len());
}

// When the player hits enter.
void UBullCowCartridge::OnInput(const FString& Input)
{
	if (bGameOver)
	{
		ClearScreen();
		SetUpGame();
	}
	else
	{
		// Check player guess.
		ProcessGuess(Input);
	}
}

void UBullCowCartridge::SetUpGame()
{
	HiddenWord = TEXT("code");
	Lives = HiddenWord.Len();
	bGameOver = false;
	
	
	// Print intro.
	PrintLine(TEXT("Greetings, traveler!"));
	PrintLine(TEXT("Guess the %i letter word."), HiddenWord.Len());
	PrintLine(TEXT("You have %i lives."), Lives);
	
	PrintLine(TEXT("\nPress tab to access the terminal."));
	PrintLine(TEXT("Enter to continue."));
}

void UBullCowCartridge::EndGame()
{
	bGameOver = true;
	PrintLine(TEXT("Press enter to play again."));
}

void UBullCowCartridge::ProcessGuess(FString Guess)
{
	if (Guess == HiddenWord)
	{
		PrintLine(TEXT("You guessed the correct word!"));
		EndGame();
	}
	else
	{
		// Check if right number of characters.
		if (Guess.Len() != HiddenWord.Len())
		{
			PrintLine(TEXT("The hidden word is %i characters long."),
					  HiddenWord.Len());
		}
		else if (!IsIsogram(Guess))
		{
			PrintLine(TEXT("That is not an isogram!"));
		}
		else if (Lives == 0)
		{
			PrintLine(TEXT("You lose. The word was '%s'."), *HiddenWord);
			EndGame();
		}
		else
		{
			PrintLine(TEXT("You guessed incorrectly!"));
			--Lives;
			PrintLine(TEXT("%i lives remain!"), Lives);
		}
		// Check if isogram.
	}
	// Reveal the word.
}

bool UBullCowCartridge::IsIsogram(FString Word)
{
	/*
	 - Check the first letter against all other letters.
	 - If the first letter is equal to another, return false.
	 - If the letter is unique, repeat for the next letter.
	 - If all are unique, return true.
	 */
	return true;
}
