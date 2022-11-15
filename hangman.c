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





        








    }
}