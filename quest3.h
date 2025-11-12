#pragma once

#include <functional>
void chapter3()
{
    // part 1
    std::vector<int> inputVec;
    Util::readFile("./input/everybody_codes_e2025_q03_p1.txt", inputVec);

    std::sort(inputVec.begin(), inputVec.end(), std::greater<>());

    int container = inputVec.at(0);
    int counter = container;
    for(auto n : inputVec)
    {
        if(n < container)
        {
            container = n;
            counter+=n;
        }
    }
    std::cout << "P1: Largest possible set of crates: " << counter << std::endl;
    
    inputVec.clear();

    // part 2
    Util::readFile("./input/everybody_codes_e2025_q03_p2.txt", inputVec);

    std::sort(inputVec.begin(), inputVec.end(), std::less<>());

    container = inputVec.at(0);
    counter = 1;
    int sum = container;
    for(auto n : inputVec)
    {
        if(n > container)
        {
            container = n;
            sum +=n;
            if(++counter == 20)
                break;
        }
    }
    std::cout << "P2: Smallest possible set of 20 crates: " << sum << std::endl;
    
    inputVec.clear();

    // part 3
    Util::readFile("./input/everybody_codes_e2025_q03_p3.txt", inputVec);

    std::sort(inputVec.begin(), inputVec.end(), std::greater<>());

    std::vector<int> remains;
    counter = 0;
    do{
        remains.clear();
        container = inputVec.at(0);
        for(auto n : inputVec)
        {
            if(n < container)
            {
                container = n;
            }
            else
                remains.push_back(n);
        }
        counter++;
        
        if ( std::adjacent_find( remains.begin(), remains.end(), std::not_equal_to<>() ) == remains.end() )
            remains.clear();
        inputVec = remains;
    }while(!remains.empty());

    std::cout << "P3: Smallest number of ways to pack crates: " << counter << std::endl;
    
 
}
