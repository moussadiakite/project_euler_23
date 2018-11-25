//
//  main.cpp
//  project_euler_23
//
//  Created by Moussa DIAKITE on 03/11/2018.
//  Copyright © 2018 Moussa DIAKITE. All rights reserved.
//

#include <iostream>
#include <time.h>
#include "TripletsSum.hpp"
#include <vector>

int main(int argc, const char * argv[])
{
	clock_t tStart = clock();
    std::vector<int> arr{0, -1, 2, -3, 1};
    printTripletsSum(arr);
	printf("Time taken: %.2fs for bestSolution\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}
