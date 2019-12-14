#include "GameMode.h"

int main()
{
    std::cout << "Hello Tanks!"  <<  std::endl;
    std::cout << "1. Start"      <<  std::endl;
    std::cout << "2. Exit!"      <<  std::endl;

    std::cout << "Enter number: ";
    int MenuStatus = 0;
    std::cin >> MenuStatus;

    switch(MenuStatus)
    {
        case 1:
            GameMode* Game = new GameMode(3);
            while(Game->GetGameStatus())
            {
                Game->Play();
            }
            break;
    }

    std::cout << "See you soon." << std::endl;
    system("pause>null");
    return 0;
}
