#include "util/util.h"
#include "quest1.h"
#include "quest2.h"

int main()
{
    int input;
    std::cout << "*************** A Song of Ducks and Dragons ****************** \n";
    std::cout << "Choose a challenge:\n";
    std::cout << "1. Whispers in the Shell\n";
    std::cout << "2. Whispers in the Shell\n";
    std::cout << "Any other key to quit.\n";

    std::cin >> input;

    switch(input)
    {
        case 1: 
            chapter1();
        break;
        case 2:
            chapter2_1();
        break;
        default:
            std::cout << input << std::endl;
    }
}


