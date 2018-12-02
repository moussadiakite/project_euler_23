//
//  main.cpp
//  project_euler_23
//
//  Created by Moussa DIAKITE on 03/11/2018.
//  Copyright © 2018 Moussa DIAKITE. All rights reserved.
//

#include <iostream>
#include <chrono>
#include "DistinctPowers.hpp"

int main(int argc, const char * argv[])
{
	auto start = std::chrono::high_resolution_clock::now();
    printNumberOfDistinctPowers(2, 100);
    auto finish = std::chrono::high_resolution_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(finish-start).count() << "ns\n";
    /*start = std::chrono::high_resolution_clock::now();
    lexicographicPermutationsImproved(nth, values);
    finish = std::chrono::high_resolution_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(finish-start).count() << "ns\n";*/
    return 0;
}
