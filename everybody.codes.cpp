#include "util/util.h"
void chapter1();
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

void chapter1()
{
    std::vector<std::string> inputVec;
    Util::readFile("./input/everybody_codes_e2025_q01_p1.txt", inputVec);

    for(auto str : inputVec)
        std::cout << str << std::endl;
}
