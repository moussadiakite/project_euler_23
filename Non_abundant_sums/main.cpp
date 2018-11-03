//
//  main.cpp
//  project_euler_23
//
//  Created by Moussa DIAKITE on 03/11/2018.
//  Copyright © 2018 Moussa DIAKITE. All rights reserved.
//

#include <iostream>
#include <time.h>
#include "non_abundant_sum.h"

int main(int argc, const char * argv[])
{
	clock_t tStart = clock();
	naiveSolution();
	printf("Time taken: %.2fs for naiveSolution\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
	tStart = clock();
	bestSolution();
	printf("Time taken: %.2fs for betterSolution\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}
