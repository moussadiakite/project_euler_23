//
//  non_abundant_sum_constants.h
//  project_euler_23
//
//  Created by Moussa DIAKITE on 03/11/2018.
//  Copyright © 2018 Moussa DIAKITE. All rights reserved.
//

#ifndef non_abundant_sum_constants_h
#define non_abundant_sum_constants_h

#include <vector>

// All integers greater than this number can be written as the sum of two abundant numbers
constexpr int g_limit{28123};

constexpr int smallest_abundant_number{12};

constexpr int first_sum_of_two_abundant_numbers{24};

std::vector<int> g_abundant_numbers;

bool abundant_numbers_sum[g_limit + 1] = {false};

#endif /* non_abundant_sum_constants_h */
