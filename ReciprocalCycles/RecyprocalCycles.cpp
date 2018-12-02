//
//  RecyprocalCycles.cpp
//  project_euler_23
//
//  Created by Moussa DIAKITE on 27/11/2018.
//  Copyright © 2018 Moussa DIAKITE. All rights reserved.
//

#include "RecyprocalCycles.hpp"

int decimalDigit(int d, int digitIndex){
    int dividendStart = 10;
    int digit = dividendStart / d;
    while(digit == 0){
        dividendStart *= 10;
        digit = dividendStart / d;
    }
    int currentDigitIndex = 1;
    while(currentDigitIndex <= digitIndex){
        digit = dividendStart / d;
        dividendStart = (dividendStart - digit * d) * 10;
        ++currentDigitIndex;
    }
    return digit;
}
