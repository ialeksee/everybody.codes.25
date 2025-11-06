#ifndef DAY_1
#define DAY_1
void chapter1()
{
    {
        std::vector<std::string> inputVec;
        Util::readFile("./input/everybody_codes_e2025_q01_p1.txt", inputVec);

        std::vector<std::string> names;
        {
            std::stringstream ss(inputVec[0]);
            while(ss.good())
            {
                std::string substr;
                getline(ss, substr, ',');
                names.push_back(substr);
            }
        }
        std::stringstream ss(inputVec[1]);
        std::vector<std::string> instructions;
        while(ss.good())
        {
            std::string substr;
            getline(ss, substr, ',');
            instructions.push_back(substr);
        }


        int8_t index = 0;
        for(auto str : instructions)
        {
            char direction = str.at(0);
            uint8_t steps = str.at(1);

            switch(direction)
            {
                case 'L':
                    index -= steps;
                break;
                case 'R':
                    index += steps;
                break;
            };

            if(index < 0)
                index = 0;
            if(index >= names.size())
                index = names.size() - 1;
        }
        std::cout << "Part 1, my name: " << names.at(index) << std::endl;
    }

    {
        std::vector<std::string> inputVec;
        Util::readFile("./input/everybody_codes_e2025_q01_p2.txt", inputVec);

        std::vector<std::string> names;
        {
            std::stringstream ss(inputVec[0]);
            while(ss.good())
            {
                std::string substr;
                getline(ss, substr, ',');
                names.push_back(substr);
            }
        }
        std::stringstream ss(inputVec[1]);
        std::vector<std::string> instructions;
        while(ss.good())
        {
            std::string substr;
            getline(ss, substr, ',');
            instructions.push_back(substr);
        }



        int index = 0;
        for(auto str : instructions)
        {
            char direction = str.at(0);
            int steps = (int)(str.at(1) - 0x30);
            if(str.size() > 2)
            {    
                steps *= 10;
                steps += (int)(str.at(2) - 0x30);
                
            }

            switch(direction)
            {
                case 'L':
                    index -= steps;
                break;
                case 'R':
                    index += steps;
                break;
            };

            if(index < 0)
            {
                index += names.size();
            }
            if(index >= names.size())
                index -= names.size();
        }
    
        std::cout << "Part 2, my parent's name: " << names.at(index) << std::endl;
    }
    {
        std::vector<std::string> inputVec;
        Util::readFile("./input/everybody_codes_e2025_q01_p3.txt", inputVec);

        std::vector<std::string> names;
        {
            std::stringstream ss(inputVec[0]);
            while(ss.good())
            {
                std::string substr;
                getline(ss, substr, ',');
                names.push_back(substr);
            }
        }
        std::stringstream ss(inputVec[1]);
        std::vector<std::string> instructions;
        while(ss.good())
        {
            std::string substr;
            getline(ss, substr, ',');
            instructions.push_back(substr);
        }



        for(auto str : instructions)
        {
            int index = 0;
            char direction = str.at(0);
            int steps = (int)(str.at(1) - 0x30);
            if(str.size() > 2)
            {    
                steps *= 10;
                steps += (int)(str.at(2) - 0x30);
                
            }
            
            if(steps >= names.size())
                steps %= names.size();


            switch(direction)
            {
                case 'L':
                    index -= steps;
                break;
                case 'R':
                    index += steps;
                break;
            };

            if(index < 0)
                index += names.size();

            if(index >= names.size())
                index -= names.size();

            std::string temp = names.at(0);
            std::cout << temp << std::endl; 
            std::cout << "index at: " << index << std::endl;
            names[0] = names[index];
            std::cout << names[0] << std::endl; 
            names[index] = temp;
            std::cout << names[index] << std::endl; 
 
        }
    
        std::cout << "Part 3, my other parent's name: " << names.at(0) << std::endl;
    }
}
#endif
