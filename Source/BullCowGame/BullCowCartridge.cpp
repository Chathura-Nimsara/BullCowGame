// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();

    SetupGame();

    PrintLine((TEXT("The Hidden word is: %s."), *HiddenWord)); //Debug Line
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    if(bGameOver)
    {
        ClearScreen();
        SetupGame();
    }
    else //check the PlayerGuess
    {
        ProcessGuess(Input);
        
    }

    

    //check if isogram
    //check right number caracter
    //remove lives
    //check if lives > 0
    //Yes show Playe again
    //Show the lives left
    //No show game over
    //Ask Play agin?
    //Yes - Reset game
    //No - Exit game

}

void UBullCowCartridge::SetupGame() //Setting up the game
{
    //Welcome the player
    PrintLine(TEXT("Hi there!"));

    HiddenWord = TEXT("cake"); 
    Lives = HiddenWord.Len(); //Set lives
    bGameOver = false; 

    PrintLine(TEXT("Welcome to Bull Cows!"));
    PrintLine(TEXT("Guess the %i letter word! \nyou have %i lives"), HiddenWord.Len(),Lives); 
    PrintLine(TEXT("Type in your guess \nPress Enter to continue..."));
}

void UBullCowCartridge::EndGame()
{
    bGameOver = true;
    PrintLine(TEXT("Press enter to play again"));
}

void UBullCowCartridge::ProcessGuess(FString Guess)
{
    if(Guess == HiddenWord)
        {
            PrintLine(TEXT("You win!"));
            EndGame();
        }
        else
        {
            --Lives;
            PrintLine(TEXT("Wrong guess, You have lost a life!, Try again!"));
            if (Lives > 0)
            {
                if(Guess.Len() != HiddenWord.Len())
                {
                    PrintLine(TEXT("Sorry guess again, you have %i lives left"), Lives);
                }
                // PrintLine(TEXT("The hidden word is %i letters long!,Try again!"),HiddenWord.Len()); 
                    
                // EndGame();   
            }
            else
            {
                PrintLine(TEXT("You have no lives left"));
                EndGame();
            }
        }
}

