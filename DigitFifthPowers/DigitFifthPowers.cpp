//
//  DigitFifthPowers.cpp
//  project_euler_23
//
//  Created by Moussa DIAKITE on 02/12/2018.
//  Copyright © 2018 Moussa DIAKITE. All rights reserved.
//

#include "DigitFifthPowers.hpp"
#include <cmath>
#include <iostream>

int nbDigits(long number){
    return ceil(log10(number));
}

void printSumOfAllNumbers(int power){
    long nine_power = pow(9, power);
    long maxNumberKDigits = 9;
    int k;
    for(k = 1; k * nine_power > maxNumberKDigits; ++k)
        maxNumberKDigits = 10 * maxNumberKDigits + 1;
    long bound = k * nine_power;
    int m;
    int digit;
    int digitsSum;
    int sum = 0;
    for(int n = 2; n <= bound; ++n){
        m = n;
        digitsSum = 0;
        while(m > 0 && digitsSum <= n){
            digit = m % 10;
            m /= 10;
            digitsSum += pow(digit, power);
        }
        if(digitsSum == n){
            sum += n;
        }
    }
    std::cout << "The sum is: " << sum << std::endl;
}
