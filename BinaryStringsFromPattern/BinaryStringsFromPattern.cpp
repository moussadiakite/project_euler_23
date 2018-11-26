//
//  BinaryStringsFromPattern.cpp
//  project_euler_23
//
//  Created by Moussa DIAKITE on 25/11/2018.
//  Copyright © 2018 Moussa DIAKITE. All rights reserved.
//

#include "BinaryStringsFromPattern.hpp"
#include <iostream>

void printBinaryStrings(std::string& s, int startingIndex)
{
    if(startingIndex == s.length()){
        std::cout << s << std::endl;
        return;
    }
    if(s[startingIndex] == '?')
    {
        s[startingIndex] = '0';
        printBinaryStrings(s, startingIndex + 1);
        s[startingIndex] = '1';
        printBinaryStrings(s, startingIndex + 1);
        s[startingIndex] = '?';
    } else {
        printBinaryStrings(s, startingIndex + 1);
    }
}
