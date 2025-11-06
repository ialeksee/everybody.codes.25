#include "util/util.h"
#include "day1.h"

int main()
{
    int input;
    std::cout << "*************** A Song of Ducks and Dragons ****************** \n";
    std::cout << "Choose a challenge:\n";
    std::cout << "1. Whispers in the Shell\n";
    std::cout << "Any other key to quit.\n";
    std::cin >> input;

    switch(input)
    {
        case 1: 
            chapter1();
        break;
        default:
            std::cout << input << std::endl;
    }
}


