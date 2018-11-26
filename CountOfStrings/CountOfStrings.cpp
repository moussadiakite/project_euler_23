//
//  CountOfStrings.cpp
//  project_euler_23
//
//  Created by Moussa DIAKITE on 25/11/2018.
//  Copyright © 2018 Moussa DIAKITE. All rights reserved.
//

#include "CountOfStrings.hpp"
#include <vector>
#include <algorithm>

const int maxSize = 100;
static int count = 0;
static long long facts[maxSize];

long long factNaive(int n){
    if(n < 0)
        return -1ll;
    else if(n <= 1ll)
        return 1ll;
    else
        return n * factNaive(n-1);
}

long long fact(int n){
    if(n < 0)
        return -1ll;
    else if(n == 0)
        facts[0] = 1ll;
    else if(n <= count)
        return facts[n];
    else
        facts[n] = n * fact(n - 1);
    return facts[n];
}

long long numberOfPermutations(int n, int na, int nb, int nc){
    return fact(na + nb + nc) / (fact(na) * fact(nb) * fact(nc));
}

long long CountOfStrings(int n, int maxNa, int maxNb, int maxNc){
    long long countOfs{0ll};
    int maxNaBis = maxNa > n ? n : maxNa, maxNbBis, maxNcBis;
    for(int na = 0; na <= maxNaBis; ++na){
        maxNbBis = maxNb > (n - na) ? n - na : maxNb;
        for(int nb = 0; nb <= maxNbBis; ++nb){
            maxNcBis = maxNc > (n - na - nb) ? n - na - nb : maxNc;
            for(int nc = n - na - nb; nc <= maxNcBis; ++nc){
                countOfs += numberOfPermutations(n, na, nb, nc);
            }
        }
    }
    return countOfs;
}
