#include <iostream>
#include <ctime>
void StartScreen()
{
    std::cout << R"(
_________            .___       __________                        __                 
\_   ___ \  ____   __| _/____   \______   \_______   ____ _____  |  | __ ___________ 
/    \  \/ /  _ \ / __ |/ __ \   |    |  _/\_  __ \_/ __ \\__  \ |  |/ // __ \_  __ \
\     \___(  <_> ) /_/ \  ___/   |    |   \ |  | \/\  ___/ / __ \|    <\  ___/|  | \/
 \______  /\____/\____ |\___  >  |______  / |__|    \___  >____  /__|_ \\___  >__|   
        \/            \/    \/          \/              \/     \/     \/    \/       
    )" << '\n';
}
void PrintIntroduction(int Difficulty)
{
    // plays story text
    std::cout << "\n\nYou are a secret agent breaking into a level " << Difficulty << " secure server room...\n";
    std::cout << "Enter the correct code to continue.\n";
}

bool PlayGame(int Difficulty) 
{
    //declares variables
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;
    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    PrintIntroduction(Difficulty);
    
    std::cout << std::endl;
    std::cout << "+ There are 3 numbers in the code.";
    std::cout << "\n+ The codes add-up to: " << CodeSum;
    std::cout << "\n+ The codes multiply to give: " << CodeProduct;
    std::cout << "\nPlease Enter Your Guess: ";
    //takes user guesses
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA;
    std::cin >> GuessB;
    std::cin >> GuessC;
    std::cout << "You entered: " << GuessA << GuessB << GuessC;
    //creates user Guess Sum+Product.
    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;
    //check if the user enters the correct code
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\nThe correct code has been entered!!. Move on to the next level.\n";;
        return true; 
    } 
    //if the user enters incorrect code
    else
    {
        std::cout << "\nThe incorrect code has been entered, Try again\n";;
        return false;
    }
}

int main()
{
    StartScreen();
    srand(time(NULL)); // sets a random seed based on time of day
    // Initialises the difficulty and max diff
    int LevelDifficulty = 1;
    int const MaxDifficulty = 4;
    //while game is not complete
    while (LevelDifficulty <= MaxDifficulty)
    {

        bool bLevelComplete = PlayGame(LevelDifficulty); // play game and return win or lose (t/f)
        std::cin.clear();
        std::cin.ignore();
        // if they beat the game
        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }       
    }
    std::cout << "\n\nWell Done, You have all the files, You'll never have to work again!";
    //closes with no error.
    return 0;
}