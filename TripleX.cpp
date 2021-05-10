#include <iostream>
#include <ctime>

bool PlayGame(int Difficulty);

void PrintIntro(int Difficulty);

int tries = 3;

int main()
{   
    srand(time(NULL)); // generate new random sequence based on time of day
    
    int LevelDifficulty = 1;
    const int MaxDifficulty = 5;

    while (LevelDifficulty <= MaxDifficulty && tries > 0) // loop game untill all levels cleared 
    {   
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); // Clears any errors
        std::cin.ignore(); // Discards the buffer

        if (bLevelComplete)
        {
            ++LevelDifficulty; // increase the level difficulty
        }   
    }
        
    if (tries == 0)
    {
        std::cout << "\nSnake! SNAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAKE!!!" << std::endl;
        return 0;
    }
    else
    {
        std::cout << "\n*** Great work agent Snake! you got all the files! Now get out of there! ***\n";
    }
}

bool PlayGame(int Difficulty)
{
    PrintIntro(Difficulty);

    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    std::cout << std::endl;
    std::cout << "Hints:\n+ There are 3 numbers in the code\n";
    std::cout << "+ The codes add-up to: " << CodeSum << std::endl;
    std::cout << "+ The codes multiply to give: " << CodeProduct << std::endl;

    int GuessA, GuessB, GuessC;

    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        if (Difficulty < 5)
        {
            std::cout << "\n*** Well done agent Snake! You have extracted a file! Keep going! ***\n";
            return true;
        }
    }
    else 
    {   
        --tries;

        if (tries > 0)
        {
          std::cout << "\n*** You entered the wrong code! Careful Agent Snake! " << tries << " trie(s) left! ***\n";
        }
        return false;
    }
}

void PrintIntro(int Difficulty)
{
    std::cout << "\nYou are a secret agent \"Snake\" breaking into a level " << Difficulty <<  " secure server room... \n";
    std::cout << "\t\t\t*** " << tries << " trie(s) left! ***\n";
    std::cout << "Enter the correct code to continue...\n"; 
}

