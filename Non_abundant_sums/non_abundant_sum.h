//
//  non_abundant_sums.h
//  project_euler_23
//
//  Created by Moussa DIAKITE on 03/11/2018.
//  Copyright © 2018 Moussa DIAKITE. All rights reserved.
//

#ifndef non_abundant_sums_h
#define non_abundant_sums_h

// tell if divisor is an integer divisor of number
bool isDivisorOf(int divisor, int number);

int naiveSumOfDivisors(int number);

// A really optimized sum of divisors
int sumOfDivisors(int number);

bool isAbundantNumber(int number);

bool isSumOfTwoAbundantNumbers(int number);

void printResult(int result);

void naiveSolution();

//store all positive abundant numbers lower than limit
void storeAllPositiveAbundantNumbers(int limit);

/*
 * compute the sums of abundant numbers that are the sum of two abundant numbers lower
 * than g_limit
 */
int getTotalSum();

void bestSolution();

#endif /* non_abundant_sums_h */
