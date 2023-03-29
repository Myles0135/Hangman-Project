/* Universe - 10 words, no more than 5 characters each. 6 fails*/
// Hangman Game
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char UniverseList[][10] = {"star", "moon", "earth", "galaxy", "space", "planet", "sun", "comet", "orbiter", "gravity"};
char animallist[][10] = {"lion","tiger","bear","rabbit","fish","elephant","giraffe","alligator","frog","shark"};
char subjectlist[][10] = {"math", "art", "biology", "chemistry", "physics", "health", "calculus", "lunch", "history", "english"};
char artlist[][15] = {"pencil", "clay", "easel", "salvador", "raphael", "donatello", "leonardo", "michealangelo", "realism", "cartoon", "charcoal", "marker"};

int main (){
    srand(time(NULL));
    
    //stdin is standard input which is below.
    char pick[5];
   printf("Please pick a category. Enter u for Universe, enter a for Animal, enter s for Subject, or enter t for Art/Artist: ");
    fgets(pick, 5, stdin);
 
    if (strncmp(pick,"u", 3) == 0){
        
        while (1) {
            int randomIndex = rand() % 10;
            char word[20];
            memset(word, 0, sizeof(word));
            strcpy(word, UniverseList[randomIndex]);

            
            // Random index is set to rand % 10.
            int lengthOfWord = strlen(UniverseList[randomIndex]);
            int total = strlen(word);
            //This searches though stringlength of my random word in my HangmanWordList

            // Creating array same length of word to generate word status
            int wordbody[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
            memset(wordbody, 0, sizeof(wordbody));
            
            int exit = 0;
            //Still working on quit = 0
            int NumberOfFails = 5;
            int NumberOfCorrect = 0;
            int OldNumberOfCorrect = 0;
            
            
            char guess[10];
            int characterGuess[13] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
            //Number of guesses I have on max word length.
            
            char letterGuessed;
            // Below gives me information on the word so i can keep check of my data.
          //  printf("Guess word: %s\n" , UniverseList[randomIndex]);
            printf("_______H_A_N_G_M_A_N___________________________________________________\n");
            printf("Welcome to Hangman! The goal of the game is to guess the word but you can only have 5 incorrect guesses. The first category is Universe words. Please make sure to use lower case. If you choose to quit the game please enter quit if not you can continue to enjoy. If you want more guesses enter more. \n");
            printf("**********************************\n");
            
            while (NumberOfCorrect < lengthOfWord){
             //   printf("Number correct so far: %d\n", NumberOfCorrect);
              //  printf("The length of the word is %d characters\n", lengthOfWord);
                printf("\nWord status: ");
                for (int i=0; i<lengthOfWord; i++) {
                    if (wordbody[i] == 1) {
                        printf("%c", UniverseList[randomIndex][i]);
                    } else {
                        printf("_");
                    }
                }
                printf("\n");
                printf("You chose to guess an universe word! Enter a guess letter: ");
                fgets(guess, 10, stdin);
                if (strncmp(guess, "quit", 4) == 0){
                    exit = 1;
                    break;
                }
                else if (strncmp(guess, "more", 3) == 0){
                    NumberOfFails = 5;
                    continue;
                }
                letterGuessed = guess[0];
                printf("letterGuessed:%c\n", letterGuessed);
                // printf("You have %d wrong guesses left\n", NumberOfFails);
                
                OldNumberOfCorrect = NumberOfCorrect;
                int i = 0;
                for (i = 0; i < lengthOfWord; i++){
                    if (characterGuess[i] == 1){
                        continue;
                        // This prevents duplicated guesses as counting towards correct answer.
                    }
                    if(letterGuessed == UniverseList[randomIndex][i]){
                        characterGuess[i] = 1;
                        NumberOfCorrect++;
                        wordbody[i] = 1;
                    }
                    
                    
                }
                int characters_left_in_word = lengthOfWord - NumberOfCorrect;
                //tells user how many characters in the word are left
                if (OldNumberOfCorrect == NumberOfCorrect){
                    NumberOfFails--;
                    printf("Sorry, try again\n");
                    printf("You have %d wrong guesses left\n", NumberOfFails);
                   // printf("You have %d characters left in unknown word\n", characters_left_in_word);
                    if (NumberOfFails == 0){
                        break;
                    }
                }
                else {
                    printf("Correct letter\n");
                    printf("You have %d wrong guesses left\n", NumberOfFails);
                  //  printf("You have %d characters left in unknown word\n", characters_left_in_word);
                    
                }
             
            }
            if (exit == 1){
                printf("You exited the game\n");
                break;
            }
            else if (NumberOfFails == 0){
                printf("You have lost, word was: %s\n", UniverseList[randomIndex]);
            }
            else {
                printf("You guessed the word correctly! It was %s.\n", UniverseList[randomIndex]);
            }
            
        }
    }
    else if (strncmp(pick,"a", 3) == 0){
        while (1) {
            
            int SecondrandomIndex = rand() % 10;
            // Random index is set to rand % 10.
            int Second_LengthOfWord = strlen(animallist[SecondrandomIndex]);
            //This searches though stringlength of my random word in my HangmanWordList

            // Creating array same length of word to generate word status
            int wordbody[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
            memset(wordbody, 0, sizeof(wordbody));
            
            int exit = 0;
            //Still working on quit = 0
            int NumberOfFails = 5;
            int NumberOfCorrect = 0;
            int OldNumberOfCorrect = 0;
            
            
            char guess[10];
            int characterGuess[7] = {0,0,0,0,0,0,0};
            //Number of guesses I have on max word length.
            
            char letterGuessed;
            // Below gives me information on the word so i can keep check of my data.
          //  printf("Guess word: %s\n" , animallist[SecondrandomIndex]);
            printf("_______H_A_N_G_M_A_N___________________________________________________\n");
            printf("Welcome to Hangman! The goal of the game is to guess the word but you can only have 5 incorrect guesses. The first category is Universe words. Please make sure to use lower case. If you choose to quit the game please enter quit if not you can continue to enjoy. If you want more guesses enter more. \n");
            printf("**********************************\n");
            
            while (NumberOfCorrect < Second_LengthOfWord){
            //    printf("Number correct so far: %d\n", NumberOfCorrect);
              //  printf("The length of the word is %d characters\n", Second_LengthOfWord);
                printf("\nWord status: ");
                for (int i=0; i<Second_LengthOfWord; i++) {
                    if (wordbody[i] == 1) {
                        printf("%c", animallist[SecondrandomIndex][i]);
                    } else {
                        printf("_");
                    }
                }
                printf("\n");
                printf("You chose to guess an animal name! Enter a guess letter:");
                fgets(guess, 13, stdin);
                if (strncmp(guess, "quit", 4) == 0){
                    exit = 1;
                    break;
                }
                else if (strncmp(guess, "more", 3) == 0){
                    NumberOfFails = 5;
                    continue;
                }
                letterGuessed = guess[0];
                printf("letterGuessed:%c\n", letterGuessed);
                // printf("You have %d wrong guesses left\n", NumberOfFails);
                
                OldNumberOfCorrect = NumberOfCorrect;
                int i = 0;
                for (i = 0; i < Second_LengthOfWord; i++){
                    if (characterGuess[i] == 1){
                        continue;
                        // This prevents duplicated guesses as counting towards correct answer.
                    }
                    if(letterGuessed == animallist[SecondrandomIndex ][i]){
                        characterGuess[i] = 1;
                        NumberOfCorrect++;
                        wordbody[i] = 1;
                    }
                    
                    
                }
                int characters_left_in_word = Second_LengthOfWord - NumberOfCorrect;
                //tells user how many characters in the word are left
                if (OldNumberOfCorrect == NumberOfCorrect){
                    NumberOfFails--;
                    printf("Sorry, try again\n");
                    printf("You have %d wrong guesses left\n", NumberOfFails);
                 //   printf("You have %d characters left in unknown word\n", characters_left_in_word);
                    if (NumberOfFails == 0){
                        break;
                    }
                }
                else {
                    printf("Correct letter\n");
                    printf("You have %d wrong guesses left\n", NumberOfFails);
                //    printf("You have %d characters left in unknown word\n", characters_left_in_word);
                    
                }
                //   for (int i = 0; i < lengthOfWord; i++){
                //         for (int j = 0; j < 1; j++){
                //             printf("__%c__", HangmanWordList[randomIndex][i]);
                //         }
                
            }
            if (exit == 1){
                printf("You exited the game\n");
                break;
            }
            else if (NumberOfFails == 0){
                printf("You have lost, word was: %s\n", animallist[SecondrandomIndex ]);
            }
            else {
                printf("You guessed the word correctly! It was %s.\n", animallist[SecondrandomIndex]);
            }
            
        }
    }
    else if (strncmp(pick,"s", 3) == 0){
        while (1) {
            
            int ThirdrandomIndex = rand() % 10;
            // Random index is set to rand % 10.
            int Third_LengthOfWord = strlen(subjectlist[ThirdrandomIndex]);
            //This searches though stringlength of my random word in my HangmanWordList
            
            // Creating array same length of word to generate word status
            int wordbody[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
            memset(wordbody, 0, sizeof(wordbody));

            int exit = 0;
            //Still working on quit = 0
            int NumberOfFails = 5;
            int NumberOfCorrect = 0;
            int OldNumberOfCorrect = 0;
            
            
            char guess[13];
            int characterGuess[13] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
            //Number of guesses I have on max word length.
            
            char letterGuessed;
            // Below gives me information on the word so i can keep check of my data.
          //  printf("Guess word: %s\n" , subjectlist[ThirdrandomIndex]);
            printf("_______H_A_N_G_M_A_N___________________________________________________\n");
            printf("Welcome to Hangman! The goal of the game is to guess the word but you can only have 5 incorrect guesses. The first category is Universe words. Please make sure to use lower case. If you choose to quit the game please enter quit if not you can continue to enjoy. If you want more guesses enter more. \n");
            printf("**********************************\n");
            
            while (NumberOfCorrect < Third_LengthOfWord){
         //       printf("Number correct so far: %d\n", NumberOfCorrect);
              //  printf("The length of the word is %d characters\n", Third_LengthOfWord);
                printf("\nWord status: ");
                for (int i=0; i<Third_LengthOfWord; i++) {
                    if (wordbody[i] == 1) {
                        printf("%c", subjectlist[ThirdrandomIndex][i]);
                    } else {
                        printf("_");
                    }
                }
                printf("\n");
                printf("You chose to guess a subject name! Enter a guess letter:");
                fgets(guess, 10, stdin);
                if (strncmp(guess, "quit", 4) == 0){
                    exit = 1;
                    break;
                }
                else if (strncmp(guess, "more", 3) == 0){
                    NumberOfFails = 5;
                    continue;
                }
                letterGuessed = guess[0];
                printf("letterGuessed:%c\n", letterGuessed);
                // printf("You have %d wrong guesses left\n", NumberOfFails);
                
                OldNumberOfCorrect = NumberOfCorrect;
                int i = 0;
                for (i = 0; i < Third_LengthOfWord; i++){
                    if (characterGuess[i] == 1){
                        continue;
                        // This prevents duplicated guesses as counting towards correct answer.
                    }
                    if(letterGuessed == subjectlist[ThirdrandomIndex][i]){
                        characterGuess[i] = 1;
                        NumberOfCorrect++;
                        wordbody[i] = 1;
                    }
                    
                    
                }
                int characters_left_in_word = Third_LengthOfWord - NumberOfCorrect;
                //tells user how many characters in the word are left
                if (OldNumberOfCorrect == NumberOfCorrect){
                    NumberOfFails--;
                    printf("Sorry, try again\n");
                    printf("You have %d wrong guesses left\n", NumberOfFails);
                //    printf("You have %d characters left in unknown word\n", characters_left_in_word);
                    if (NumberOfFails == 0){
                        break;
                    }
                }
                else {
                    printf("Correct letter\n");
                    printf("You have %d wrong guesses left\n", NumberOfFails);
                //    printf("You have %d characters left in unknown word\n", characters_left_in_word);
                    
                }
                //   for (int i = 0; i < lengthOfWord; i++){
                //         for (int j = 0; j < 1; j++){
                //             printf("__%c__", HangmanWordList[randomIndex][i]);
                //         }
                
            }
            if (exit == 1){
                printf("You exited the game\n");
                break;
            }
            else if (NumberOfFails == 0){
                printf("You have lost, word was: %s\n", subjectlist[ThirdrandomIndex]);
            }
            else {
                printf("You guessed the word correctly! It was %s.\n", subjectlist[ThirdrandomIndex]);
            }
            
        }
    }
    else {
        while (1) {
            int FourthRandomIndex = rand() % 10;
            // Random index is set to rand % 10.
            int Fourth_LengthOfWord = strlen (artlist[FourthRandomIndex]);
            //This searches though stringlength of my random word in my HangmanWordList

            // Creating array same length of word to generate word status
            int wordbody[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
            memset(wordbody, 0, sizeof(wordbody));
            
            int exit = 0;
            //Still working on quit = 0
            int NumberOfFails = 5;
            int NumberOfCorrect = 0;
            int OldNumberOfCorrect = 0;
            
            
            char guess[10];
            int characterGuess[7] = {0,0,0,0,0,0,0};
            //Number of guesses I have on max word length.
            
            char letterGuessed;
            // Below gives me information on the word so i can keep check of my data.
          //  printf("Guess word: %s\n" , artlist[FourthRandomIndex]);
            printf("_______H_A_N_G_M_A_N___________________________________________________\n");
            printf("Welcome to Hangman! The goal of the game is to guess the word but you can only have 5 incorrect guesses. The first category is Universe words. Please make sure to use lower case. If you choose to quit the game please enter quit if not you can continue to enjoy. If you want more guesses enter more. \n");
            printf("**********************************\n");
            
            while (NumberOfCorrect < Fourth_LengthOfWord){
          //      printf("Number correct so far: %d\n", NumberOfCorrect);
             //   printf("The length of the word is %d characters\n", Fourth_LengthOfWord);
                printf("\nWord status: ");
                for (int i=0; i<Fourth_LengthOfWord; i++) {
                    if (wordbody[i] == 1) {
                        printf("%c", artlist[FourthRandomIndex][i]);
                    } else {
                        printf("_");
                    }
                }
                printf("\n");
                printf("You chose to enter an artist or art instrument! Enter a guess letter:");
                fgets(guess, 10, stdin);
                if (strncmp(guess, "quit", 4) == 0){
                    exit = 1;
                    break;
                }
                else if (strncmp(guess, "more", 3) == 0){
                    NumberOfFails = 5;
                    continue;
                }
                letterGuessed = guess[0];
                printf("letterGuessed:%c\n", letterGuessed);
                // printf("You have %d wrong guesses left\n", NumberOfFails);
                
                OldNumberOfCorrect = NumberOfCorrect;
                int i = 0;
                for (i = 0; i < Fourth_LengthOfWord; i++){
                    if (characterGuess[i] == 1){
                        continue;
                        // This prevents duplicated guesses as counting towards correct answer.
                    }
                    if(letterGuessed == artlist[FourthRandomIndex][i]){
                        characterGuess[i] = 1;
                        NumberOfCorrect++;
                        wordbody[i] = 1;
                    }
                    
                    
                }
                int characters_left_in_word = Fourth_LengthOfWord - NumberOfCorrect;
                //tells user how many characters in the word are left
                if (OldNumberOfCorrect == NumberOfCorrect){
                    NumberOfFails--;
                    printf("Sorry, try again\n");
                    printf("You have %d wrong guesses left\n", NumberOfFails);
                  //  printf("You have %d characters left in unknown word\n", characters_left_in_word);
                    if (NumberOfFails == 0){
                        break;
                    }
                }
                else {
                    printf("Correct letter\n");
                    printf("You have %d wrong guesses left\n", NumberOfFails);
                 //   printf("You have %d characters left in unknown word\n", characters_left_in_word);
                    
                }
                //   for (int i = 0; i < lengthOfWord; i++){
                //         for (int j = 0; j < 1; j++){
                //             printf("__%c__", HangmanWordList[randomIndex][i]);
                //         }
                
            }
            if (exit == 1){
                printf("You exited the game\n");
                break;
            }
            else if (NumberOfFails == 0){
                printf("You have lost, word was: %s\n", artlist[FourthRandomIndex]);
            }
            else {
                printf("You guessed the word correctly! It was %s.\n", artlist[FourthRandomIndex]);
            }
            
        }
    }
    return 0;
}



