//
//  main.cpp
//  project_euler_23
//
//  Created by Moussa DIAKITE on 03/11/2018.
//  Copyright © 2018 Moussa DIAKITE. All rights reserved.
//

#include <iostream>
#include <cmath>

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
const int g_limit = 28123;
const int smalllest_abundant_number = 12;
const int first_sum_of_two_abundant_numbers = 24;

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
	if(number <= -smalllest_abundant_number)
		return isAbundantNumber(-number);
	if(number > -smalllest_abundant_number && number < smalllest_abundant_number)
		return false;
	if(number == smalllest_abundant_number)
		return true;
	
	// 1 divides all numbers and it allows us to exclude to add number to the sum further
	int sum{1};
	
	/*
	 * we use the theorem that says that all divisors of a number are less or equal to
	 * the square root of this number
	 */
	int i = 2;
	for(i = 2; i < sqrt(number); ++i)
	{
		if(isDivisorOf(i, number))
			sum += i + sum/i; // if i is a divisor then sum/i is also one
	}
	
	//in case sqrt(number) is an integer value and then a divisor of number
	if(i * i == number)
		sum += i;
	
	return sum > number;
}

bool isSumOfTwoAbundantNumbers(int number)
{
	if(number > g_limit)
		return true;
	for(int i = smalllest_abundant_number; i < number - smalllest_abundant_number; ++i)
	{
		if(isAbundantNumber(i) && isAbundantNumber(number - i))
			return true;
	}
	return false;
}

int main(int argc, const char * argv[])
{
    // insert code here...
	int sum{first_sum_of_two_abundant_numbers};
	for(int  i = first_sum_of_two_abundant_numbers + 1; i <= g_limit; ++i)
		if(isSumOfTwoAbundantNumbers(i))
			sum += i;
	std::cout << "the sum of all the positive integers which cannot be written as the sum of two abundant numbers is: " <<
	sum;
    return 0;
}
