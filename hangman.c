#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {

    srand(time(NULL));

    // Possible words
    char words[][20] = {
        "lion",
        "tiger",
        "bear",
        "rabbit",
        "fish",
        "elephant",
        "giraffe",
        "alligator",
        "frog",
        "shark"
    };

    int totalWords = sizeof(words) / sizeof(words[0]);

    // Possible guesses (all letters in alphabet)
    char letters[27] = {'a','b','c','d','e','f','g',
                        'h','i','j','k','l','m','n',
                        'o','p','q','r','s','t','u',
                        'v','w','x','y','z'};

    

    while(1) {

        int end_game = 0;
        char guess;
        int lives_remaining = 5;
        int score = 0;

        // Creating a random index to select a word
        int a = rand() % totalWords;

        // Storing selected word
        char word[16];
        memset(word, 0, sizeof(word));
        strcpy(word, words[a]);

        // Getting the length of the word
        int wordLength = strlen(word);
        
        // Creating an array the same length as the word
        int body[wordLength];
        memset(body, 0, sizeof(body));

        // Bringing array of letters in to game
        int guesses[27];
        memset(guesses, 0, sizeof(guesses));
        int availableLetters = sizeof(guesses) / sizeof(guesses[0]);

        // Main Game
        while (score < wordLength) {

            printf("\n");

            printf("Guess a letter!: ");
            scanf("%c", &guess);
            // Only take first letter
            while ( getchar() != '\n' ) { ; }

            int newGuess = 0;
            int wrongGuess= 0;

            // Checking if letter has already been guessed
            for (int i=0; i<availableLetters - 1; i++) {
                if (guess=letters[i] && guesses[i]=0) {
                    guesses[i]=1;
                    newGuess=1;
                    wrongGuess=1;
                    for (int j=0; j<wordLength; j++) {
                        if (guess = word[j]) {
                            body[j] = 1;
                            wrongGuess = 1;
                        }
                    }
                }
            }




        }

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main (){
    srand(time(NULL));
    
    //stdin is standard input which is below.
    char HangmanWordList[][10] = {"star", "moon", "earth", "galaxy", "space", "planet", "sun", "comet", "orbiter", "gravity"};
    int randomIndex = rand() % 10;
    // Random index is set to rand % 10.
    int lengthOfWord = strlen(HangmanWordList[randomIndex]);
    //This searches though stringlength of my random word in my HangmanWordList
    int characterGuess[7] = {0,0,0,0,0,0,0};
    //Number of guesses I have on max word length.
    
    int exit = 0;
    //Still working on quit = 0
    int NumberOfFails = 4;
    int NumberOfCorrect = 0;
    int OldNumberOfCorrect = 0;
    
    
    char guess[10];
    char letterGuessed;
    // Below gives me information on the word so i can keep check of my data.
    printf("Guess word: %s random index : %d, lengthOfWord: %d\n", HangmanWordList[randomIndex], randomIndex, lengthOfWord);
    
    printf("Welcome to Hangman! The goal of the game is to guess the word but you can only have 5 incorrect guesses. The first category is Universe words. Please make sure to use lower case. If you choose to quit the game early please enter quit to quit out of the game. If you choose to end the game early and start over again enter the letter N. ");
    int i = 0;
        while (NumberOfCorrect < lengthOfWord){
            printf("Number correct so far: %d\n", NumberOfCorrect);
            printf("Enter a guess letter:");
            fgets(guess, 10, stdin);
            if (strncmp(guess, "quit", 4) == 0){
                exit = 1;
                break;
            }
            letterGuessed = guess[0];
            printf("letterGuessed:%c\n", letterGuessed);
            
            OldNumberOfCorrect = NumberOfCorrect;
            
            for (i = 0; i < lengthOfWord; i++){
                if (characterGuess[i] == 1){
                    continue;
                }
                if(letterGuessed == HangmanWordList[randomIndex][i]){
                    characterGuess[i] = 1;
                    NumberOfCorrect++;
                }
                
            }
            
            if (OldNumberOfCorrect == NumberOfCorrect){
                NumberOfFails--;
                printf("Sorry, try again\n");
                if (NumberOfFails == 0){
                    break;
                }
            }
            else {
                printf("Correct letter\n");
            }
        }
        if (exit == 1){
            printf("The user quit early\n");
        }
        else if (NumberOfFails == 0){
            printf("You have lost, word was: %s\n", HangmanWordList[randomIndex]);
        }
        else {
            printf("You guessed the word correctly!");
        
        }
    
}
        return 0;

        








    }
}
