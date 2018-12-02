//
//  DistinctPowers.cpp
//  project_euler_23
//
//  Created by Moussa DIAKITE on 01/12/2018.
//  Copyright © 2018 Moussa DIAKITE. All rights reserved.
//

#include "DistinctPowers.hpp"
#include <cmath>
#include <utility>
#include <iostream>

std::pair<int*, int> getNonPerfectPowers(int start, int limit){
    int length = limit + 1;
    bool* isNonPerfectPower = new bool[length];
    for(int n = start; n < length; ++n)
        isNonPerfectPower[n] = true;
    int maxPower;
    int nonPerfectPowersCount = 0;
    int n_k;
    for(int n = start; n < length; ++n){
        if(isNonPerfectPower[n]){
            maxPower = floor(log(limit) / log(n));
            n_k = n * n;
            for(int k = 2; k <= maxPower; ++k, n_k *= n){
                isNonPerfectPower[n_k] = false;
            }
            ++nonPerfectPowersCount;
        }
    }
    int* nonPerfectPowers = new int[nonPerfectPowersCount];
    int jjj = start;
    for(int iii = 0; iii < nonPerfectPowersCount; ++iii){
        while(!isNonPerfectPower[jjj])
            ++jjj;
        nonPerfectPowers[iii] = jjj;
        ++jjj;
    }
    delete[] isNonPerfectPower;
    return std::make_pair(nonPerfectPowers, nonPerfectPowersCount);
}

void printNumberOfDistinctPowers(int start, int limit){
    std::pair<int*, int> nonPerfectPowersAndLength = getNonPerfectPowers(start, limit);
    int* nonPerfectPowers = nonPerfectPowersAndLength.first;
    int nonPerfectPowersLength = nonPerfectPowersAndLength.second;
    int numberOfDistinctPowers = (limit - start + 1) * (limit - start + 1);
    int a, a_k;
    int maxPower;
    
    for(int iii = 0; iii < nonPerfectPowersLength; ++iii){
        a = nonPerfectPowers[iii];
        maxPower = floor(log(limit) / log(a));
        a_k = a * a;
        int kp;
        for(int k = 2; k <= maxPower; ++k, a_k *= a){
            for(int b = start; b <= limit; ++b){
                kp = 1;
                while(kp < k && ((k * b) % kp != 0 || k * b > limit * kp))
                    ++kp;
                if(kp < k)
                    --numberOfDistinctPowers;
            }
            std::cout << std::endl;
        }
    }
    delete [] nonPerfectPowers;
    std::cout << "The number of distinct powers for " << start <<
    " <= a, b <= " << limit << " is: " << numberOfDistinctPowers << std::endl;
}
