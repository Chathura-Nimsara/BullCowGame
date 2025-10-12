// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();

    SetupGame();

    //Welcome the player
    PrintLine(TEXT("Hi there!"));
    PrintLine(TEXT("Welcome to Bull Cows!"));
    PrintLine(TEXT("Guess the 4 letter word!")); // Magic Number Remove!
    PrintLine(TEXT("Press Enter to continue..."));

    
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    ClearScreen();

    //Check if the player guess is correct
    if(Input == HiddenWord)
    {
        PrintLine(TEXT("You win!"));
    }
    else
    {
        if(Input.Len != HiddenWord.Len())
        {
            PrintLine(TEXT("The hidden word is 4 letters long!,Try again!")); //Magic number
        }
        PrintLine(TEXT("You have Lost, Try again!"));
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

void UBullCowCartidge::SetupGame() //Setting up the game
{
    HiddenWord = TEXT("cake"); 
    Lives = 4; 
}

