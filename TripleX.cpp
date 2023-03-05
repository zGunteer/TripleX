#include <iostream>
#include <ctime>
void PrintIntroduction(int Difficulty)
{
    //Intro of TripleX
    std::cout << "\n\nYou've just spawned in another world which looks like a huge tower in the sky.Right now you are at level " <<Difficulty<< std::endl;
    std::cout << "\nIn order to get out of this level you have to climb the tower, by entering the code!\n";
}

bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);
    //Declare 3 nr code
    const int CodeA = rand() %Difficulty + Difficulty;
    const int CodeB = rand() %Difficulty + Difficulty;
    const int CodeC = rand() %Difficulty + Difficulty;

    //print result

    const int CodeSum= CodeA+CodeB+CodeC;
    const int CodeProduct= CodeA*CodeB*CodeC;
    std::cout << std::endl << "* There are 3  numbers in the code.";
    std::cout << std::endl << "\n * Those 3 numbers added up ="<<  CodeSum << "\n * And multiplied = "<< CodeProduct<< std::endl;

    // Player guess
    int GuessA,GuessB,GuessC;
    std::cin >>GuessA >> GuessB >> GuessC;
    
    int GuessSum=GuessA+GuessB+GuessC;
    int GuessProduct=GuessA*GuessB*GuessC;
    
    //Check if guess is correct
    if((GuessSum == CodeSum) && (GuessProduct==CodeProduct))
    {
        std::cout << "\n -_-_-_-_-Congrats! You are on to the next level!-_-_-_-_-";
        return true;
    }else
    {
    std::cout<< "\n -_-_-_-_-Oh no... you've failed to guess the code and have fallen of the Tower-_-_-_-_-.\n\n Try again!";
        return false;
    }
}
int main()
{   
    srand(time(NULL));    //creates a random sequence based on pc time
    int LevelDifficulty=1;
    const int MaxDifficulty=5;

    while (LevelDifficulty <= MaxDifficulty)  //Loop game until completed game
    {
        bool bLevelComplete=PlayGame(LevelDifficulty);
        std::cin.clear(); //Clears any errors
        std::cin.ignore(); //Clears the buffer
        if (bLevelComplete)
        {
            //Increase difficulty (nextlevel)
            ++LevelDifficulty;
        }
        
    }
    std::cout << "\nCongratulations it seems like you've reached at the top of the tower and you have returned to your home world !";
    
}           