#pragma once

class Bone{
public:
    enum class Type
    {Left, Spine, Right, None};

    Bone(){ Bone(0);};
    Bone(int val):t{Type::None}, hasLeft{false}, hasRight{false}, value{val}{};

    Type t;
    bool hasLeft, hasRight;
    int value;
};


void chapter5()
{
    std::vector<int> inputVec;
    std::vector<Bone> fishbone;
    Util::readFile("./input/everybody_codes_e2025_q05_p1.txt", inputVec);
    
    std::vector<int>::iterator it = inputVec.begin();
    while( ++it != inputVec.end())
    {
        Bone b{*it};
        if(fishbone.empty())
        {
            b.t = Bone::Type::Spine;
            fishbone.push_back(b);
            continue;
        }
       
        bool bAdded = false;
        for(auto& bb : fishbone)
        {
            if(bb.t == Bone::Type::Spine)
            {
                if(bb.hasLeft && bb.hasRight)
                    continue;
                if((b.value < bb.value) && !bb.hasLeft)
                {
                    b.t = Bone::Type::Left;
                    bb.hasLeft = true;
                    fishbone.push_back(b);
                    bAdded = true;
                    break;
                }
                if((b.value > bb.value) &&  !bb.hasRight)
                {
                    b.t = Bone::Type::Right;
                    bb.hasRight = true;
                    fishbone.push_back(b);
                    bAdded = true;
                    break;
                }
            }
        }
        if(!bAdded)
        {
            b.t = Bone::Type::Spine;
            fishbone.push_back(b);
        }
    }
    for(auto b : fishbone)
        if(b.t == Bone::Type::Spine)
            std::cout << b.value;
    std::cout << std::endl;
}

