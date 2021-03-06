// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"

// When game starts.
void UBullCowCartridge::BeginPlay()
{
	Super::BeginPlay();
	
	// Import the word list to the array.
	const FString HiddenWordListPath = FPaths::ProjectContentDir() /
	TEXT("WordLists/HiddenWordList.txt");
	FFileHelper::LoadFileToStringArrayWithPredicate
	(
	 Isograms,
	 *HiddenWordListPath,
	 [](const FString& Word)
		{
			return Word.Len() >=4 & Word.Len() <= 8 && IsIsogram(Word);
		}
	 );
	
	SetUpGame();
	

	// Debug lines.
	PrintLine(TEXT("The hidden word is %s."), *HiddenWord);
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
//	Isograms = GetValidWords(HiddenWordList);
	HiddenWord = Isograms[FMath::RandRange(0, Isograms.Num()-1)];
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

void UBullCowCartridge::ProcessGuess(const FString& Guess)
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
	}
}

bool UBullCowCartridge::IsIsogram(const FString& Word)
{
	for (int32 CharToCheck = 0; CharToCheck < Word.Len(); ++CharToCheck)
	{
		for (int32 AnotherChar = CharToCheck + 1; AnotherChar < Word.Len();
			 ++AnotherChar)
		{
			if (Word[CharToCheck] == Word[AnotherChar])
			{
				return false;
			}
		}
	}
	return true;
}
