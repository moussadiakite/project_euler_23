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
#include <cmath>

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
    int nb_characters = static_cast<int>(values.size());
    int nb_remaining_characters = nb_characters;
    int i;
    int j = -1;
    int remainingPermutationsCount = nth - count;
    long long fact_n = fact(nb_remaining_characters);
    while(nb_remaining_characters > 0 && remainingPermutationsCount > 0){
        i = remainingPermutationsCount / fact_n;
        if(i * fact_n != remainingPermutationsCount){
            shift(permutations, j, j + i);
            ++j;
        } else {
            shift(permutations, j, j + i - 1);
            char tmp;
            for(int k = j + 1, l = nb_characters - 1; k < l; ++k, --l){
                tmp = permutations[k];
                permutations[k] = permutations[l];
                permutations[l] = tmp;
            }
        }
        count += i * fact_n;
        remainingPermutationsCount = nth - count;
        fact_n /= nb_remaining_characters;
        --nb_remaining_characters;
    }
    std::cout << permutations << std::endl;
}

void lexicographicPermutations(int nth, std::set<char>& values){
    std::string permutations(values.size(), '*');
    count = 0;
    lexicographicPermutations(0, nth, values, permutations);
}
