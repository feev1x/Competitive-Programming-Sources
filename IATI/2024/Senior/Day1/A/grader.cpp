#include "ones.h"
#include "sol.cpp"

#include <vector>
#include <iostream>
#include <utility>
#include <algorithm>
#include <random>
#include <iomanip>
#include <numeric>
#include <cstring>

static const int N = 1e5 + 3;

static int n, k, n_tests;
static int input[N];

static long long number_of_queries;

static std::vector<int> readOnes()
{
    for(int i=1;i<=n;i++)
        input[i]=0;

    std::vector<int> _ones(k,0);

    for(int i=0;i<k;i++)
    {
        std::cin>>_ones[i];
        input[_ones[i]]=1;
    }

    for(int i=1;i<=n;i++)input[i]+=input[i-1];

    sort(_ones.begin(),_ones.end());

    return _ones;
}

bool hasOnes(int l,int r)
{
    number_of_queries++;

    if(1>l || l>n || 1>r || r>n || l>r)
    {
        std::cout << "Your program made an invalid query: " << ' ' << l << ' ' << r << std::endl;
        exit(0);
    }

    return input[r] != input[l-1];
}

static long long runOneTest(){
    number_of_queries = 0;

    std::vector<int> _ones = readOnes();

    std::vector<int> guess = guessOnes(n,k);

    if(_ones != guess)
    {
        std::cout << "Your program returned an incorrect answer." << std::endl;
        exit(0);
    }

    std::cout << "Your program successfully returned the correct positions and used " << number_of_queries << " queries." << std::endl;

    return number_of_queries;
}

int main(){
    std::cin >> n >> k >> n_tests;

    long long sum_queries = 0;
    for(int i = 0; i < n_tests; ++i)
        sum_queries = sum_queries + runOneTest();

    std::cout << "Your program successfully returned the correct positions and used " << sum_queries << " queries in total." << std::endl;
}
