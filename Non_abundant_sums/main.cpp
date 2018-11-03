//
//  main.cpp
//  project_euler_23
//
//  Created by Moussa DIAKITE on 03/11/2018.
//  Copyright © 2018 Moussa DIAKITE. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <unordered_set>
#include <time.h>

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
const int g_limit{28123};
const int smallest_abundant_number{12};
const int first_sum_of_two_abundant_numbers{24};

std::vector<int> g_abundant_numbers;
std::unordered_set<int> g_possible_sums;

//tell if divisor is an integer divisor of number
bool isDivisorOf(int divisor, int number)
{
	return number % divisor == 0;
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
	 * 1 divides all numbers and it allows us to exclude further the adding of the number
	 * itself from the sum
	 */
	int sum{1};
	
	/*
	 * we use the theorem that says that all divisors of a number are lower or equal to
	 * the square root of this number
	 */
	int i;
	for(i = 2; i < sqrt(number); ++i)
	{
		if(isDivisorOf(i, number))
			sum += i + number/i; // if i is a divisor then number/i is also one
	}
	
	//in case sqrt(number) is an integer value and then also a divisor of number
	if(i * i == number)
		sum += i;
	
	return sum > number;
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

//store all sums of two abundant numbers lower than g_limit
void storePossibleSums(int limit){
	int sum;
	for(int i{0}; i < g_abundant_numbers.size(); ++i)
		for(int j{i}; j < g_abundant_numbers.size(); ++j)
		{
			sum = g_abundant_numbers.at(i) + g_abundant_numbers.at(j);
			if(sum <= limit)
			{
				auto search = g_possible_sums.find(sum);
				if(search == g_possible_sums.end())
					g_possible_sums.insert(sum);
			}
		}
}

void betterSolution()
{
	//store all positive abundant numbers lower than g_limit
	storeAllPositiveAbundantNumbers(g_limit);
	
	//store all numbers that are sum of two abundant numbers lower than g_limit
	storePossibleSums(g_limit);
	
	/*
	 * g_limit * (g_limit + 1) / 2 is the sum of all numbers from 1 to g_limit
	 * sum is the sum of all the numbers that can be written as the sum of two
	 * abundant numbers
	 * and you obtain the final result by the difference of these 2 values
	 */
	int sum{0};
	for (auto itr = g_possible_sums.begin(); itr != g_possible_sums.end(); ++itr)
		sum += *itr;
	printResult(g_limit * (g_limit + 1) / 2 - sum);
}

int main(int argc, const char * argv[])
{
	clock_t tStart = clock();
	naiveSolution();
	printf("Time taken: %.2fs for naiveSolution\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
	tStart = clock();
	betterSolution();
	printf("Time taken: %.2fs for betterSolution\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}
