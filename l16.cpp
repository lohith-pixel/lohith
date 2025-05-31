#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cctype>

using namespace std;

class HangmanGame {
private:
    vector<string> wordList;
    string secretWord;
    string guessedWord;
    vector<char> guessedLetters;
    vector<char> wrongGuesses;
    int maxWrongGuesses;
    int currentWrongGuesses;
    int score;
    int gamesPlayed;
    int gamesWon;

public:
    HangmanGame() {
        initializeWordList();
        maxWrongGuesses = 6;
        currentWrongGuesses = 0;
        score = 0;
        gamesPlayed = 0;
        gamesWon = 0;
        srand((unsigned int)time(0));
    }

    void initializeWordList() {
        // Easy words (4-5 letters)
        wordList.push_back("APPLE");
        wordList.push_back("HOUSE");
        wordList.push_back("WATER");
        wordList.push_back("HAPPY");
        wordList.push_back("WORLD");
        wordList.push_back("MUSIC");
        wordList.push_back("LIGHT");
        wordList.push_back("PIZZA");
        wordList.push_back("BEACH");
        wordList.push_back("SMILE");

        // Medium words (6-7 letters)
        wordList.push_back("COMPUTER");
        wordList.push_back("RAINBOW");
        wordList.push_back("ELEPHANT");
        wordList.push_back("BICYCLE");
        wordList.push_back("KITCHEN");
        wordList.push_back("GARDEN");
        wordList.push_back("FREEDOM");
        wordList.push_back("JOURNEY");
        wordList.push_back("CRYSTAL");
        wordList.push_back("BREATHE");

        // Hard words (8+ letters)
        wordList.push_back("UNIVERSITY");
        wordList.push_back("CHOCOLATE");
        wordList.push_back("ADVENTURE");
        wordList.push_back("BEAUTIFUL");
        wordList.push_back("TELEPHONE");
        wordList.push_back("WONDERFUL");
        wordList.push_back("BUTTERFLY");
        wordList.push_back("LIGHTNING");
        wordList.push_back("KNOWLEDGE");
        wordList.push_back("YESTERDAY");
    }

    void selectRandomWord() {
        int randomIndex = rand() % wordList.size();
        secretWord = wordList[randomIndex];
        guessedWord = string(secretWord.length(), '_');
    }

    void resetGame() {
        guessedLetters.clear();
        wrongGuesses.clear();
        currentWrongGuesses = 0;
        selectRandomWord();
    }

    void displayHangman() {
        cout << "\n";
        cout << "   +---+\n";

        switch (currentWrongGuesses) {
        case 0:
            cout << "   |   |\n";
            cout << "       |\n";
            cout << "       |\n";
            cout << "       |\n";
            cout << "       |\n";
            break;
        case 1:
            cout << "   |   |\n";
            cout << "   O   |\n";
            cout << "       |\n";
            cout << "       |\n";
            cout << "       |\n";
            break;
        case 2:
            cout << "   |   |\n";
            cout << "   O   |\n";
            cout << "   |   |\n";
            cout << "       |\n";
            cout << "       |\n";
            break;
        case 3:
            cout << "   |   |\n";
            cout << "   O   |\n";
            cout << "  /|   |\n";
            cout << "       |\n";
            cout << "       |\n";
            break;
        case 4:
            cout << "   |   |\n";
            cout << "   O   |\n";
            cout << "  /|\\  |\n";
            cout << "       |\n";
            cout << "       |\n";
            break;
        case 5:
            cout << "   |   |\n";
            cout << "   O   |\n";
            cout << "  /|\\  |\n";
            cout << "  /    |\n";
            cout << "       |\n";
            break;
        case 6:
            cout << "   |   |\n";
            cout << "   O   |\n";
            cout << "  /|\\  |\n";
            cout << "  / \\  |\n";
            cout << "       |\n";
            break;
        }
        cout << " =========\n";
    }

    void displayGameState() {
        system("cls"); // For Windows. Use system("clear") for Linux/Mac

        cout << string(50, '=') << endl;
        cout << "           HANGMAN GAME" << endl;
        cout << string(50, '=') << endl;

        displayHangman();

        cout << "\nWord: ";
        for (int i = 0; i < (int)guessedWord.length(); i++) {
            cout << guessedWord[i] << " ";
        }
        cout << endl;

        cout << "\nWrong guesses (" << currentWrongGuesses << "/" << maxWrongGuesses << "): ";
        for (int i = 0; i < (int)wrongGuesses.size(); i++) {
            cout << wrongGuesses[i] << " ";
        }
        cout << endl;

        cout << "Guessed letters: ";
        for (int i = 0; i < (int)guessedLetters.size(); i++) {
            cout << guessedLetters[i] << " ";
        }
        cout << endl;

        cout << "\nScore: " << score << " | Games Won: " << gamesWon << "/" << gamesPlayed << endl;
        cout << string(50, '-') << endl;
    }

    char getPlayerGuess() {
        char guess;
        cout << "\nEnter a letter (or '?' for hint, '!' to quit): ";
        cin >> guess;
        return toupper(guess);
    }

    bool isValidGuess(char guess) {
        if (guess == '?' || guess == '!') {
            return true;
        }

        if (!isalpha(guess)) {
            cout << "Please enter a valid letter!" << endl;
            return false;
        }

        // Check if already guessed
        for (int i = 0; i < (int)guessedLetters.size(); i++) {
            if (guessedLetters[i] == guess) {
                cout << "You already guessed that letter!" << endl;
                return false;
            }
        }

        return true;
    }

    void processGuess(char guess) {
        guessedLetters.push_back(guess);
        bool correctGuess = false;

        // Check if guess is in the word
        for (int i = 0; i < (int)secretWord.length(); i++) {
            if (secretWord[i] == guess) {
                guessedWord[i] = guess;
                correctGuess = true;
            }
        }

        if (correctGuess) {
            cout << "\nGood guess! '" << guess << "' is in the word!" << endl;
            score += 10;
        }
        else {
            cout << "\nSorry! '" << guess << "' is not in the word." << endl;
            wrongGuesses.push_back(guess);
            currentWrongGuesses++;
            score = max(0, score - 5); // Don't let score go negative
        }
    }

    void giveHint() {
        cout << "\nHINT: ";

        // Find an unguessed letter in the word
        vector<char> unguessedLetters;
        for (int i = 0; i < (int)secretWord.length(); i++) {
            char letter = secretWord[i];
            bool alreadyGuessed = false;

            for (int j = 0; j < (int)guessedLetters.size(); j++) {
                if (guessedLetters[j] == letter) {
                    alreadyGuessed = true;
                    break;
                }
            }

            if (!alreadyGuessed) {
                bool alreadyInList = false;
                for (int k = 0; k < (int)unguessedLetters.size(); k++) {
                    if (unguessedLetters[k] == letter) {
                        alreadyInList = true;
                        break;
                    }
                }
                if (!alreadyInList) {
                    unguessedLetters.push_back(letter);
                }
            }
        }

        if (!unguessedLetters.empty()) {
            int randomIndex = rand() % unguessedLetters.size();
            cout << "Try the letter '" << unguessedLetters[randomIndex] << "'" << endl;
            score = max(0, score - 15); // Penalty for using hint
        }
        else {
            cout << "No more hints available!" << endl;
        }
    }

    bool isGameWon() {
        return guessedWord == secretWord;
    }

    bool isGameLost() {
        return currentWrongGuesses >= maxWrongGuesses;
    }

    void displayWinMessage() {
        cout << "\n" << string(50, '*') << endl;
        cout << "CONGRATULATIONS! YOU WON!" << endl;
        cout << "The word was: " << secretWord << endl;
        cout << "Your score: " << score << endl;
        cout << string(50, '*') << endl;
    }

    void displayLoseMessage() {
        displayHangman();
        cout << "\n" << string(50, 'X') << endl;
        cout << "GAME OVER! YOU LOST!" << endl;
        cout << "The word was: " << secretWord << endl;
        cout << "Better luck next time!" << endl;
        cout << string(50, 'X') << endl;
    }

    void displayStatistics() {
        cout << "\n" << string(40, '=') << endl;
        cout << "        GAME STATISTICS" << endl;
        cout << string(40, '=') << endl;
        cout << "Games Played: " << gamesPlayed << endl;
        cout << "Games Won: " << gamesWon << endl;
        cout << "Games Lost: " << (gamesPlayed - gamesWon) << endl;
        if (gamesPlayed > 0) {
            double winRate = (double)gamesWon / gamesPlayed * 100;
            cout << "Win Rate: " << (int)winRate << "%" << endl;
        }
        cout << "Total Score: " << score << endl;
        cout << string(40, '=') << endl;
    }

    void displayInstructions() {
        cout << "\n" << string(50, '=') << endl;
        cout << "           HOW TO PLAY HANGMAN" << endl;
        cout << string(50, '=') << endl;
        cout << "1. Guess letters one at a time" << endl;
        cout << "2. Correct guesses reveal letters in the word" << endl;
        cout << "3. Wrong guesses add parts to the hangman" << endl;
        cout << "4. Win by guessing the word before hangman is complete" << endl;
        cout << "5. You have " << maxWrongGuesses << " wrong guesses allowed" << endl;
        cout << "\nSpecial commands:" << endl;
        cout << "  ? - Get a hint (costs 15 points)" << endl;
        cout << "  ! - Quit current game" << endl;
        cout << "\nScoring:" << endl;
        cout << "  +10 points for correct guess" << endl;
        cout << "  -5 points for wrong guess" << endl;
        cout << "  -15 points for using hint" << endl;
        cout << string(50, '=') << endl;
    }

    void displayMenu() {
        cout << "\n" << string(40, '=') << endl;
        cout << "          HANGMAN GAME MENU" << endl;
        cout << string(40, '=') << endl;
        cout << "1. Play Game" << endl;
        cout << "2. View Instructions" << endl;
        cout << "3. View Statistics" << endl;
        cout << "4. Reset Statistics" << endl;
        cout << "5. Exit" << endl;
        cout << string(40, '=') << endl;
        cout << "Enter your choice (1-5): ";
    }

    void playGame() {
        resetGame();
        gamesPlayed++;

        cout << "\nStarting new game..." << endl;
        cout << "Word length: " << secretWord.length() << " letters" << endl;
        cout << "Press Enter to continue...";
        cin.ignore();
        cin.get();

        while (!isGameWon() && !isGameLost()) {
            displayGameState();

            char guess = getPlayerGuess();

            if (guess == '!') {
                cout << "Game quit! The word was: " << secretWord << endl;
                return;
            }

            if (guess == '?') {
                giveHint();
                cout << "Press Enter to continue...";
                cin.ignore();
                cin.get();
                continue;
            }

            if (!isValidGuess(guess)) {
                cout << "Press Enter to continue...";
                cin.ignore();
                cin.get();
                continue;
            }

            processGuess(guess);

            cout << "Press Enter to continue...";
            cin.ignore();
            cin.get();
        }

        displayGameState();

        if (isGameWon()) {
            displayWinMessage();
            gamesWon++;
            score += 50; // Bonus for winning
        }
        else {
            displayLoseMessage();
        }

        cout << "\nPress Enter to continue...";
        cin.get();
    }

    void resetStatistics() {
        score = 0;
        gamesPlayed = 0;
        gamesWon = 0;
        cout << "\nStatistics have been reset!" << endl;
        cout << "Press Enter to continue...";
        cin.ignore();
        cin.get();
    }

    void run() {
        cout << "Welcome to Hangman Game!" << endl;

        while (true) {
            displayMenu();

            int choice;
            cin >> choice;

            switch (choice) {
            case 1:
                playGame();
                break;
            case 2:
                displayInstructions();
                cout << "Press Enter to continue...";
                cin.ignore();
                cin.get();
                break;
            case 3:
                displayStatistics();
                cout << "Press Enter to continue...";
                cin.ignore();
                cin.get();
                break;
            case 4:
                resetStatistics();
                break;
            case 5:
                cout << "\nThanks for playing Hangman!" << endl;
                cout << "Final Statistics:" << endl;
                displayStatistics();
                return;
            default:
                cout << "Invalid choice! Please select 1-5." << endl;
                cout << "Press Enter to continue...";
                cin.ignore();
                cin.get();
            }
        }
    }
};

int main() {
    HangmanGame game;
    game.run();
    return 0;
}