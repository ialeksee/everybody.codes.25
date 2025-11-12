#pragma once


#include <cstdint>
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


}
