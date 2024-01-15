#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_WORD_LENGTH 20
#define MAX_TRIES 6
#define MAX_GENRE_LENGTH 20
#define NUM_GENRES 6

void displayHangman(int incorrectAttempts);
void displayWord(char* word, char* guessedLetters);
void displayMovieDescription(char* movieName, int chosenGenreIndex);

int main() {
    char genres[NUM_GENRES][MAX_GENRE_LENGTH] = {
        "science fiction", "rom-com", "romance", "thriller", "action", "horror"
		};
    char genreChoice[MAX_GENRE_LENGTH];
	printf("WELCOME TO DEATH SENTENCE- where the stakes are high, the clues are cinematic, and your guesses determine the fate of iconic movie titles!!");
	printf("Lights, camera, guess – let the blockbuster guessing game begin!");
    printf("\nGenres Available: \n");
    for (int i = 0; i < NUM_GENRES; ++i) {
        printf("%d. %s\n", i + 1, genres[i]);
    }
    int chosenGenreIndex;
    do {
        printf("Select a genre of your choice: ");
        if (scanf("%d", &chosenGenreIndex) != 1 || chosenGenreIndex < 1 || chosenGenreIndex > NUM_GENRES) {
            printf("Invalid input. Please enter a number between 1 and %d.\n", NUM_GENRES); //validation
            while (getchar() != '\n'); // Clear the input buffer
        } else {
            break;
        }
    } while (1);
    strcpy(genreChoice, genres[chosenGenreIndex - 1]);

    // Words related to different genres
    char sciFiWords[][MAX_WORD_LENGTH] = {"interstellar", "oppenheimer", "inception", "predestination", "blade runner"};
    char romComWords[][MAX_WORD_LENGTH] = {"the notebook", "the proposal", "love actually", "legally blonde", "love rosie"};
    char romanceWords[][MAX_WORD_LENGTH] = {"la la land", "one day", "me before you", "five feet apart", "twilight"};
    char thrillerWords[][MAX_WORD_LENGTH] = {"shutter island", "seven", "gone girl", "sound of freedom", "momento"};
    char actionWords[][MAX_WORD_LENGTH] = {"iron man", "fast and furious", "the dark knight", "black adam", "heart of stone"};
    char horrorWords[][MAX_WORD_LENGTH] = {"halloween", "conjuring", "dabbe", "the nun", "smile"};

     char* sciFiDescriptions[] = {
        "Interstellar is a science fiction film directed by Christopher Nolan, depicting a team of astronauts who embark on a space journey through a wormhole in search of a new habitable planet for humanity's survival.",
        "Oppenheimer is a cinematic masterpiece that delves into the complexities of the human spirit and the pursuit of knowledge. Through the lens of the brilliant physicist J. Robert Oppenheimer, the film weaves a narrative of scientific curiosity and moral dilemmas. ",
        "Inception is a mind-bending science fiction thriller directed by Christopher Nolan, exploring the world of dreams as a skilled thief enters the subconscious to implant and extract information.",
        "Predestination is a mind-bending science fiction film where a temporal agent embarks on a complex mission involving time travel, identity twists, and a mysterious figure known as the Fizzle Bomber.\n",
        "Blade Runner is a dystopian science fiction film directed by Ridley Scott, exploring the moral and existential questions surrounding artificial intelligence and humanity as a detective hunts down bioengineered beings known as replicants in a futuristic, rain-soaked Los Angeles."
    };
    char* romComDescriptions[] = {
        "The Notebook is a romantic drama film that follows the enduring love story between Noah Calhoun and Allie Hamilton, spanning decades as they navigate obstacles and rediscover their connection.",
        "The Proposal is a romantic comedy film that follows a Canadian book editor who convinces her assistant to marry her to avoid deportation, leading to unexpected complications and humorous situations.",
        "Love Actually is a romantic comedy that follows the interconnected lives of various characters in the weeks leading up to Christmas in London, exploring the complexities of love and relationships.",
        "Legally Blonde is a comedy film that follows the journey of Elle Woods, a fashionable sorority girl who enrolls in Harvard Law School to win back her ex-boyfriend and discovers her legal acumen along the way.",
        "Love, Rosie is a romantic comedy-drama film that follows the lifelong, complicated relationship between two best friends, Rosie and Alex, as they navigate love, missed opportunities, and the challenges of maintaining their deep connection over the years."
    };
    char* romanceDescriptions[] = {
        "La La Land is a romantic musical film that follows the love story between a jazz musician and an aspiring actress as they pursue their dreams in Los Angeles.",
        "One Day is a romantic drama that follows the intertwining lives of Emma and Dexter, portrayed by Anne Hathaway and Jim Sturgess, as they reunite on the same day each year over two decades, exploring the complexities of friendship and love.",
        "Me Before You is a romantic drama film that follows the poignant love story between a young caregiver and a paralyzed wealthy man who finds new meaning in life.",
        "Five Feet Apart is a romantic drama depicting the love story between two teenagers with cystic fibrosis who must maintain a safe distance to avoid cross-infection, exploring themes of love, resilience, and the complexities of living with a chronic illness.",
        "Twilight is a romantic fantasy film based on Stephenie Meyer's novel, portraying the love story between a teenage girl, Bella Swan, and a vampire, Edward Cullen, amidst the challenges of their supernatural worlds."
    };
    char* thrillerDescriptions[] = {
        "Shutter Island is a psychological thriller directed by Martin Scorsese, where a U.S. Marshal investigates the mysterious disappearance of a prisoner from a mental institution, unraveling a complex web of deception and psychological twists.",
        "Seven is a psychological thriller directed by David Fincher, where two detectives, played by Brad Pitt and Morgan Freeman, investigate a series of gruesome murders based on the seven deadly sins.",
        "Gone Girl is a psychological thriller film directed by David Fincher, depicting the mysterious disappearance of a woman and the ensuing media frenzy as her husband becomes the prime suspect.",
        "Sound of Freedom is a gripping thriller based on the true story of Tim Ballard, a former government operative, who fights against child trafficking as he risks everything to rescue exploited children around the world.",
        "Memento is a psychological thriller directed by Christopher Nolan, following a man with short-term memory loss as he uses Polaroid photographs and tattoos to piece together the puzzle of his wife's murder in reverse chronological order."
    };
    char* actionDescriptions[] = {
        "Iron Man follows Tony Stark, a genius billionaire weapons manufacturer who, after being kidnapped, builds a powered exoskeleton to escape and later uses it to fight crime as the armored superhero Iron Man.",
        "The Fast and the Furious is a high-octane action film series that follows a group of skilled street racers and their involvement in heists, espionage, and adrenaline-pumping adventures.",
        "The Dark Knight is a gripping superhero film that follows Batman as he confronts the anarchic Joker, testing the limits of justice and morality in Gotham City.",
        "Black Adam is a superhero film that explores the complex and powerful character of Teth-Adam, an ancient Egyptian warrior bestowed with magical abilities, as he navigates the line between anti-hero and villain in the DC Extended Universe.",
        "Heart of Stone is a thrilling heist film centered around a charismatic master thief who faces unexpected challenges and personal dilemmas as she navigates a high-stakes robbery."
    };
    char* horrorDescriptions[] = {
        "Halloween is a classic horror film directed by John Carpenter, featuring the relentless masked killer Michael Myers who escapes from a psychiatric institution to terrorize the small town of Haddonfield on Halloween night.",
        "The Conjuring is a supernatural horror film that follows paranormal investigators Ed and Lorraine Warren as they confront a malevolent presence terrorizing a family in their secluded farmhouse.",
        "Dabbe is a Turkish horror film that follows a series of supernatural events and demonic possessions experienced by a group of people, exploring themes of fear and the unknown.",
        "The Nun is a horror film that follows a Catholic priest and a novice as they investigate a malevolent force haunting a Romanian abbey, uncovering a dark secret that unleashes a terrifying demonic presence.",
        "Smile is a 1975 satirical comedy film directed by Michael Ritchie, portraying the behind-the-scenes chaos of a beauty pageant in a small California town."
    };

    srand(time(NULL));
    char secretWord[MAX_WORD_LENGTH];

    switch (chosenGenreIndex) {
        case 1:
            strcpy(secretWord, sciFiWords[rand() % (sizeof(sciFiWords) / sizeof(sciFiWords[0]))]);
            break;
        case 2:
            strcpy(secretWord, romComWords[rand() % (sizeof(romComWords) / sizeof(romComWords[0]))]);
            break;
        case 3:
            strcpy(secretWord, romanceWords[rand() % (sizeof(romanceWords) / sizeof(romanceWords[0]))]);
            break;
        case 4:
            strcpy(secretWord, thrillerWords[rand() % (sizeof(thrillerWords) / sizeof(thrillerWords[0]))]);
            break;
        case 5:
            strcpy(secretWord, actionWords[rand() % (sizeof(actionWords) / sizeof(actionWords[0]))]);
            break;
        case 6:
            strcpy(secretWord, horrorWords[rand() % (sizeof(horrorWords) / sizeof(horrorWords[0]))]);
            break;
    }

    int wordLength = strlen(secretWord);
    char guessedLetters[MAX_WORD_LENGTH];
    memset(guessedLetters, '_', wordLength);
    guessedLetters[wordLength] = '\0';
    int incorrectAttempts = 0;
    char guess;
    printf("Guess the %s movie!\n", genreChoice);
    do {
        displayHangman(incorrectAttempts);
        displayWord(secretWord, guessedLetters);

        printf("Enter a letter: ");
        scanf(" %c", &guess);
        // Convert guess to lowercase
        guess = tolower(guess);
        int found = 0;
        for (int i = 0; i < wordLength; i++) {
            if (secretWord[i] == guess) {
                guessedLetters[i] = guess;
                found = 1;
            }
        }
        if (!found) {
            printf("Nope. Try Again!\n");
            incorrectAttempts++;
        }
        if (strcmp(secretWord, guessedLetters) == 0) {
            printf("Congratulations! You got it! The movie was: %s\n", secretWord);
            break;
        }
    } 
    while (incorrectAttempts < MAX_TRIES);
    if (incorrectAttempts == MAX_TRIES) {
        displayHangman(incorrectAttempts);
        printf("Ooops! You just hanged the man. The movie was: %s\n", secretWord);
    }
    displayMovieDescription(secretWord, chosenGenreIndex);
    return 0;
}

void displayMovieDescription(char* movieName, int chosenGenreIndex) {
    printf("Movie Insight:\n");

    switch (chosenGenreIndex) {
        case 1:
            // Sci-Fi genre descriptions
            if (strcmp(movieName, "interstellar") == 0) {
                printf("Interstellar is a science fiction film directed by Christopher Nolan, depicting a team of astronauts who embark on a space journey through a wormhole in search of a new habitable planet for humanity's survival.\n");
            } else if (strcmp(movieName, "oppenheimer") == 0) {
                printf("Oppenheimer is a cinematic masterpiece that delves into the complexities of the human spirit and the pursuit of knowledge. Through the lens of the brilliant physicist J. Robert Oppenheimer, the film weaves a narrative of scientific curiosity and moral dilemmas. \n");
            } else if (strcmp(movieName, "inception") == 0) {
                printf("Inception is a mind-bending science fiction thriller directed by Christopher Nolan, exploring the world of dreams as a skilled thief enters the subconscious to implant and extract information.\n");
            } else if (strcmp(movieName, "predestination") == 0) {
                printf("Predestination is a mind-bending science fiction film where a temporal agent embarks on a complex mission involving time travel, identity twists, and a mysterious figure known as the Fizzle Bomber.\n");
            } else if (strcmp(movieName, "blade runner") == 0) {
                printf("Blade Runner is a dystopian science fiction film directed by Ridley Scott, exploring the moral and existential questions surrounding artificial intelligence and humanity as a detective hunts down bioengineered beings known as replicants in a futuristic, rain-soaked Los Angeles.\n");
            }
            break;
        case 2:
            // rom-com genre descriptions
            if (strcmp(movieName, "the notebook") == 0) {
                printf("The Notebook is a romantic drama film that follows the enduring love story between Noah Calhoun and Allie Hamilton, spanning decades as they navigate obstacles and rediscover their connection.\n");
            } else if (strcmp(movieName, "the proposal") == 0) {
                printf("The Proposal is a romantic comedy film that follows a Canadian book editor who convinces her assistant to marry her to avoid deportation, leading to unexpected complications and humorous situations.\n");
            } else if (strcmp(movieName, "love actually") == 0) {
                printf("Love Actually is a romantic comedy that follows the interconnected lives of various characters in the weeks leading up to Christmas in London, exploring the complexities of love and relationships.\n");
            } else if (strcmp(movieName, "legally blonde") == 0) {
                printf("Legally Blonde is a comedy film that follows the journey of Elle Woods, a fashionable sorority girl who enrolls in Harvard Law School to win back her ex-boyfriend and discovers her legal acumen along the way.\n");
            } else if (strcmp(movieName, "love rosie") == 0) {
                printf("Love, Rosie is a romantic comedy-drama film that follows the lifelong, complicated relationship between two best friends, Rosie and Alex, as they navigate love, missed opportunities, and the challenges of maintaining their deep connection over the years.\n");
            }
            break;
        case 3:
            // romance genre descriptions
            if (strcmp(movieName, "la la land") == 0) {
                printf("La La Land is a romantic musical film that follows the love story between a jazz musician and an aspiring actress as they pursue their dreams in Los Angeles.\n");
            } else if (strcmp(movieName, "one day") == 0) {
                printf("One Day is a romantic drama that follows the intertwining lives of Emma and Dexter, portrayed by Anne Hathaway and Jim Sturgess, as they reunite on the same day each year over two decades, exploring the complexities of friendship and love.\n");
            } else if (strcmp(movieName, "me before you") == 0) {
                printf("Me Before You is a romantic drama film that follows the poignant love story between a young caregiver and a paralyzed wealthy man who finds new meaning in life.\n");
            } else if (strcmp(movieName, "five feet apart") == 0) {
                printf("Five Feet Apart is a romantic drama depicting the love story between two teenagers with cystic fibrosis who must maintain a safe distance to avoid cross-infection, exploring themes of love, resilience, and the complexities of living with a chronic illness.\n");
            } else if (strcmp(movieName, "twilight") == 0) {
                printf("Twilight is a romantic fantasy film based on Stephenie Meyer's novel, portraying the love story between a teenage girl, Bella Swan, and a vampire, Edward Cullen, amidst the challenges of their supernatural worlds.\n");
            }
            break;
        case 4:
            // thriller genre descriptions
            if (strcmp(movieName, "shutter island") == 0) {
                printf("Shutter Island is a psychological thriller directed by Martin Scorsese, where a U.S. Marshal investigates the mysterious disappearance of a prisoner from a mental institution, unraveling a complex web of deception and psychological twists.\n");
            } else if (strcmp(movieName, "seven") == 0) {
                printf("Seven is a psychological thriller directed by David Fincher, where two detectives, played by Brad Pitt and Morgan Freeman, investigate a series of gruesome murders based on the seven deadly sins.\n");
            } else if (strcmp(movieName, "gone girl") == 0) {
                printf("Gone Girl is a psychological thriller film directed by David Fincher, depicting the mysterious disappearance of a woman and the ensuing media frenzy as her husband becomes the prime suspect.\n");
            } else if (strcmp(movieName, "sound of freedom") == 0) {
                printf("Sound of Freedom is a gripping thriller based on the true story of Tim Ballard, a former government operative, who fights against child trafficking as he risks everything to rescue exploited children around the world.\n");
            } else if (strcmp(movieName, "momento") == 0) {
                printf("Memento is a psychological thriller directed by Christopher Nolan, following a man with short-term memory loss as he uses Polaroid photographs and tattoos to piece together the puzzle of his wife's murder in reverse chronological order.\n");
            }
            break;
        case 5:
            // action genre descriptions
            if (strcmp(movieName, "iron man") == 0) {
                printf("Iron Man follows Tony Stark, a genius billionaire weapons manufacturer who, after being kidnapped, builds a powered exoskeleton to escape and later uses it to fight crime as the armored superhero Iron Man.\n");
            } else if (strcmp(movieName, "fast and furious") == 0) {
                printf("The Fast and the Furious is a high-octane action film series that follows a group of skilled street racers and their involvement in heists, espionage, and adrenaline-pumping adventures.\n");
            } else if (strcmp(movieName, "the dark knight") == 0) {
                printf("The Dark Knight is a gripping superhero film that follows Batman as he confronts the anarchic Joker, testing the limits of justice and morality in Gotham City.\n");
            } else if (strcmp(movieName, "black adam") == 0) {
                printf("Black Adam is a superhero film that explores the complex and powerful character of Teth-Adam, an ancient Egyptian warrior bestowed with magical abilities, as he navigates the line between anti-hero and villain in the DC Extended Universe.\n");
            } else if (strcmp(movieName, "heart of stone") == 0) {
                printf("Heart of Stone is a thrilling heist film centered around a charismatic master thief who faces unexpected challenges and personal dilemmas as she navigates a high-stakes robbery.\n");
            }
            break;
        case 6:
            // horror genre descriptions
            if (strcmp(movieName, "halloween") == 0) {
                printf("Halloween is a classic horror film directed by John Carpenter, featuring the relentless masked killer Michael Myers who escapes from a psychiatric institution to terrorize the small town of Haddonfield on Halloween night.\n");
            } else if (strcmp(movieName, "conjuring") == 0) {
                printf("The Conjuring is a supernatural horror film that follows paranormal investigators Ed and Lorraine Warren as they confront a malevolent presence terrorizing a family in their secluded farmhouse.\n");
            } else if (strcmp(movieName, "dabbe") == 0) {
                printf("Dabbe is a Turkish horror film that follows a series of supernatural events and demonic possessions experienced by a group of people, exploring themes of fear and the unknown.\n");
            } else if (strcmp(movieName, "the nun") == 0) {
                printf("The Nun is a horror film that follows a Catholic priest and a novice as they investigate a malevolent force haunting a Romanian abbey, uncovering a dark secret that unleashes a terrifying demonic presence.\n");
            } else if (strcmp(movieName, "smile") == 0) {
                printf("Smile is a 1975 satirical comedy film directed by Michael Ritchie, portraying the behind-the-scenes chaos of a beauty pageant in a small California town.\n");
            }
            break;
    }
}

void displayHangman(int incorrectAttempts) {
    switch (incorrectAttempts) {
        case 0:
            printf("  +---+\n");
            printf("      |\n");
            printf("      |\n");
            printf("      |\n");
            break;
        case 1:
            printf("  +---+\n");
            printf("  O   |\n");
            printf("      |\n");
            printf("      |\n");
            break;
        case 2:
            printf("  +---+\n");
            printf("  O   |\n");
            printf("  |   |\n");
            printf("      |\n");
            break;
        case 3:
            printf("  +---+\n");
            printf("  O   |\n");
            printf(" /|   |\n");
            printf("      |\n");
            break;
        case 4:
            printf("  +---+\n");
            printf("  O   |\n");
            printf(" /|\\  |\n");
            printf("      |\n");
            break;
        case 5:
            printf("  +---+\n");
            printf("  O   |\n");
            printf(" /|\\  |\n");
            printf(" /    |\n");
            break;
        case 6:
            printf("  +---+\n");
            printf("  O   |\n");
            printf(" /|\\  |\n");
            printf(" / \\  |\n");
            break;
    }
}

void displayWord(char* word, char* guessedLetters) {
    printf("Movie: ");
    int length = strlen(word);
    for (int i = 0; i < length; i++) {
        if (word[i] == ' ') {
            printf("  ");
        } else if (guessedLetters[i] == '_') {
            printf("_ ");
        } else {
            printf("%c ", guessedLetters[i]);
        }
    }
    printf("\n");
}