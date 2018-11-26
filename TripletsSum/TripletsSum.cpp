//
//  TripletsSum.cpp
//  project_euler_23
//
//  Created by Moussa DIAKITE on 20/11/2018.
//  Copyright © 2018 Moussa DIAKITE. All rights reserved.
//

#include "TripletsSum.hpp"
#include <iostream>
#include <unordered_set>
#include <utility>

void printTripletsSum(const std::vector<int>& arr)
{
    for(int iii = 0; iii < arr.size(); ++iii)
    {
        for(int jjj = iii+1; jjj < arr.size(); ++jjj)
        {
            for(int kkk = jjj + 1; kkk < arr.size(); kkk++)
            {
                if(arr[iii] + arr[jjj] + arr[kkk] == 0)
                    std::cout << arr[iii] << " " << arr[jjj] << " " << arr[kkk] << std::endl;
            }
        }
    }
}

void printTripletsSumEnhanced(const std::vector<int>& arr){
    std::unordered_set<int> s;
    for(int iii = 0; iii < arr.size(); ++iii)
    {
        for(int jjj = iii+1; jjj < arr.size(); ++jjj)
        {
            int toFind = -(arr[iii] + arr[jjj]);
            auto got = s.find(toFind);
            if(got != s.end())
                std::cout << toFind << " " << arr[iii] << " " << arr[jjj] << std::endl;
        }
        s.insert(arr[iii]);
    }
}
