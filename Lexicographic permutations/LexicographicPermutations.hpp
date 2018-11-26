//
//  LexicographicPermutations.hpp
//  project_euler_23
//
//  Created by Moussa DIAKITE on 25/11/2018.
//  Copyright © 2018 Moussa DIAKITE. All rights reserved.
//

#ifndef LexicographicPermutations_hpp
#define LexicographicPermutations_hpp

#include <set>
#include <string>

void lexicographicPermutations(int index, int nth, std::set<char>& values, std::string& permutations);
void lexicographicPermutationsImproved(int nth, std::set<char>& values);
void lexicographicPermutations(int nth, std::set<char>& values);

#endif /* LexicographicPermutations_hpp */
