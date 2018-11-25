//
//  non_abundant_sums.cpp
//  project_euler_23
//
//  Created by Moussa DIAKITE on 03/11/2018.
//  Copyright © 2018 Moussa DIAKITE. All rights reserved.
//

#include <iostream>
#include "non_abundant_sum_constants.h"

/*
 * Problem 23: Abundant sums
 * A perfect number is a number for which the sum of its proper divisors
 * is exactly equal to the number. For example, the sum of the proper divisors
 * of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.
 *
 * A number n is called deficient if the sum of its proper divisors is less than n
 * and it is called abundant if this sum exceeds n.
 *
 * As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number
 * that can be written as the sum of two abundant numbers is 24. By mathematical analysis,
 * it can be shown that all integers greater than 28123 can be written as the sum of two
 * abundant numbers. However, this upper limit cannot be reduced any further by analysis
 * even though it is known that the greatest number that cannot be expressed as the sum of
 * two abundant numbers is less than this limit.
 *
 * Find the sum of all the positive integers which cannot be written as the sum of two
 * abundant numbers.
 */

// All integers greater than this number can be written as the sum of two abundant numbers
/*constexpr int g_limit{28123};

constexpr int smallest_abundant_number{12};

constexpr int first_sum_of_two_abundant_numbers{24};

std::vector<int> g_abundant_numbers;

bool abundant_numbers_sum[g_limit + 1] = {false};*/

//tell if divisor is an integer divisor of number
bool isDivisorOf(int divisor, int number)
{
	return number % divisor == 0;
}

int naiveSumOfDivisors(int number){
	if(number == 1)
		return 1;
	int sum{number + 1};
	int i;
	/*
	 * we use the theorem that says that any number n can at most have one prime factor
	 * greater than square root(n)
	 */
	for(i = 2; i * i < number; i++)
		if(isDivisorOf(i, number))
			sum += i + number / i;
	if(i * i == number)
		sum += i;
	return sum;
}

int sumOfDivisors(int number){
	int sum{1};
	int sum_pow_p_i;
	for(int i = 2; i * i <= number; ++i){
		sum_pow_p_i = 1;
		while(number % i == 0){
			sum_pow_p_i = i * sum_pow_p_i + 1;
			number /= i;
		}
		sum *= sum_pow_p_i;
	}
	if(number > 1)
		sum *= number + 1;
	return sum;
}

bool isAbundantNumber(int number)
{
	/*
	 * 12 is the smallest abundant number so we don't need to check wether the numbers
	 * between -12 and 12 are abundant or not
	 */
	if(number <= -smallest_abundant_number)
		return isAbundantNumber(-number);
	if(number > -smallest_abundant_number && number < smallest_abundant_number)
		return false;
	if(number == smallest_abundant_number)
		return true;
	
	/*
	 * As number is added in the sum of divisor we also need to add number to the
	 * other member of the inequation
	 */
	return sumOfDivisors(number) > 2 * number;
}

bool isSumOfTwoAbundantNumbers(int number)
{
	if(number > g_limit)
		return true;
	for(int i{smallest_abundant_number}; i < number - smallest_abundant_number; ++i)
	{
		if(isAbundantNumber(i) && isAbundantNumber(number - i))
			return true;
	}
	return false;
}

void printResult(int result)
{
	std::cout << "the sum of all the positive integers which cannot be written as the sum of two abundant numbers is: " <<
	result << std::endl;
}

void naiveSolution()
{
	/*
	 * The sum of numbers from 1 to n is n * n + 1 / 2. As all numbers lower the first
	 * number that can be expressed as sum of two abundant numbers, cannot be expressed
	 * as sum of two abundant numbers, we can compute their sum using the previous
	 * formula with n = first_sum_of_two_abundant_numbers - 1
	 */
	int sum{(first_sum_of_two_abundant_numbers - 1) *
		(first_sum_of_two_abundant_numbers) / 2};
	for(int  i = first_sum_of_two_abundant_numbers + 1; i <= g_limit; ++i)
	{
		if(!isSumOfTwoAbundantNumbers(i))
			sum += i;
	}
	printResult(sum);
}

//store all positive abundant numbers lower than limit
void storeAllPositiveAbundantNumbers(int limit){
	for(int i{smallest_abundant_number}; i <= limit; ++i)
		if(isAbundantNumber(i))
			g_abundant_numbers.push_back(i);
}

/*
 * compute the sums of abundant numbers that are the sum of two abundant numbers lower
 * than g_limit
 */
int getTotalSum(){
	int sum_2;
	for(int i{0}; i < g_abundant_numbers.size(); ++i)
		for(int j{i};j < g_abundant_numbers.size(); ++j)
		{
			sum_2 = g_abundant_numbers[i] + g_abundant_numbers[j];
			if(sum_2 <= g_limit)
				abundant_numbers_sum[sum_2] = true;
		}
	
	int sum{0};
	
	for(int i{1}; i < g_limit; ++i)
		if(!abundant_numbers_sum[i])
			sum += i;
	return sum;
}

void bestSolution()
{
	//store all positive abundant numbers lower than g_limit
	storeAllPositiveAbundantNumbers(g_limit);
	
	printResult(getTotalSum());
}
