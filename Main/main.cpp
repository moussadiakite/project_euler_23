//
//  main.cpp
//  project_euler_23
//
//  Created by Moussa DIAKITE on 03/11/2018.
//  Copyright © 2018 Moussa DIAKITE. All rights reserved.
//

#include <iostream>
#include <chrono>
#include "LexicographicPermutations.hpp"
#include <string>
#include <set>

int main(int argc, const char * argv[])
{
	auto start = std::chrono::high_resolution_clock::now();
    std::set<char> values{'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    lexicographicPermutations(1000000, values);
    auto finish = std::chrono::high_resolution_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(finish-start).count() << "ns\n";
    start = std::chrono::high_resolution_clock::now();
    lexicographicPermutationsImproved(1000000, values);
    finish = std::chrono::high_resolution_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(finish-start).count() << "ns\n";
    return 0;
}
