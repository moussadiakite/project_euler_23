//
//  LexicographicPermutations.cpp
//  project_euler_23
//
//  Created by Moussa DIAKITE on 25/11/2018.
//  Copyright © 2018 Moussa DIAKITE. All rights reserved.
//

#include "LexicographicPermutations.hpp"
#include "CountOfStrings.hpp"
#include <string>
#include <iostream>

static int count;

void lexicographicPermutations(int index, int nth, std::set<char>& values, std::string& permutations){
    if(index == permutations.size() || count > nth){
        count++;
        if(count == nth)
            std::cout << permutations << std::endl;
        return;
    }
    std::set<char>::iterator pos = values.begin();
    while(pos != values.end()){
        char current = *pos;
        permutations[index] = current;
        pos = values.erase(pos);
        lexicographicPermutations(index + 1, nth, values, permutations);
        pos = values.insert(current).first;
        ++pos;
    }
}

int swap(std::string& s, int i, int j){
    if(i < 0 || j < 0 || i >= s.size() || j >= s.size())
        return -1;
    char tmp = s[i];
    s[i] = s[j];
    s[j] = tmp;
    return 1;
}

int shift(std::string& s, int i, int j){
    if(i == j)
        return 1;
    char tmp = s[i];
    s[i] = s[j];
    for(int k = j; k > i + 1; --k)
        s[k] = s[k - 1];
    s[i + 1] = tmp;
    return 1;
}

void lexicographicPermutationsImproved(int nth, std::set<char>& values){
    std::string permutations("0123456789");
    count = 0;
    int n = static_cast<int>(values.size());
    int i;
    long long forwardPermutationsNb;
    int j = 0;
    int remainingPermutations = nth - count;
    while(n > 0 && remainingPermutations > 0){
        i = 0;
        forwardPermutationsNb = 0;
        while(forwardPermutationsNb < remainingPermutations){
            ++i;
            forwardPermutationsNb = i * fact(n);
        }
        if(i - 1 != 0){
            shift(permutations, j, j + i - 1);
            ++j;
        }
        count += (i- 1) * fact(n);
        remainingPermutations = nth - count;
        --n;
    }
    std::cout << permutations << std::endl;
}

void lexicographicPermutations(int nth, std::set<char>& values){
    std::string permutations(values.size(), '*');
    count = 0;
    lexicographicPermutations(0, nth, values, permutations);
}
