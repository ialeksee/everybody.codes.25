#pragma once

#include <cstdint>
#include <iterator>
void chapter4()
{
    std::vector<int> inputVec;
    Util::readFile("./input/everybody_codes_e2025_q04_p1.txt", inputVec);

    //part 1:
    
    double gearRatio = (double)inputVec.front()/(double)inputVec.back();
    int result = (int)std::trunc(gearRatio * 2025);
    std::cout << "P1: The last wheel will make " << result << " revolutions.\n";

    //part 2:
    inputVec.clear();
    Util::readFile("./input/everybody_codes_e2025_q04_p2.txt", inputVec);

   
    gearRatio = (double)inputVec.front()/(double)inputVec.back();
    int64_t result_64 = (int64_t)std::ceil((double)10000000000000/gearRatio);
    std::cout << "P2: The first wheel will make " << result_64 << " revolutions.\n";

    //part 3:
    inputVec.clear();
    Util::readFile("./input/everybody_codes_e2025_q04_p3.txt", inputVec);

    //split the input into numerator and denominator vectors
    std::vector<int> v_numerator;
    std::vector<int> v_denominator;  
    for(int counter{0};auto n : inputVec)
        if(++counter%2)
            v_numerator.push_back(n);
        else
            v_denominator.push_back(n); 
    
    
    //eliminate duplicates from denominator and nominator vectors, they are going to cancel each other anyway
    for(std::vector<int>::iterator it = v_numerator.begin(); it != v_numerator.end();)
    {
        std::vector<int>::iterator found = std::find(v_denominator.begin(), v_denominator.end(), *it);
        if(found != v_denominator.end())
        {
            v_denominator.erase(found);
            v_numerator.erase(it);
        }
        else
            it++;
    }

    gearRatio = 1.0;
    for(std::vector<int>::iterator it = v_denominator.begin();auto n : v_numerator)
    {
       gearRatio *= (double)n/(double)*it;
       it++;
    }
 
    result_64 = (int64_t)std::floor((double)100*gearRatio);
    std::cout << "P3: The last wheel will make " << result_64 << " revolutions.\n";


}
