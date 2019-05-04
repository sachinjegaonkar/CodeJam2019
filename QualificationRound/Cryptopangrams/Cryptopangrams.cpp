#include "pch.h"


#include <algorithm>
#include <string>
#include <utility>
#include <iostream>
#include <vector>
#include <map>
#include <list>

using namespace std;

vector<int> primes;
vector<int> products;
list<pair<int, int>> factors;
vector<int> selected_primes;
map<int, int> dictionary;

enum ALPHABETS { A = 0, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z };

bool isDivisible(int number, int divisor)
{
    return number % divisor == 0;
}

struct Divisible {
    Divisible(int s) : toFind(s) { }
    bool operator() (const Divisible &n)
    {
        return (toFind % n.toFind == 0);
    }
    int toFind;
};

bool isPrime(int number)
{
    for (int i = 2; i < number; i++)
    {
        if (isDivisible(number, i))
        {
            return false;
        }
    }
    return true;
}

void findFactors(int P)
{
    vector<int>::iterator it = find_if(primes.begin(), primes.end(), Divisible(P));
    factors.push_back(pair<int, int>(*it, P / (*it)));
}

void addSelectedPrime(pair<int, int> elements)
{
    vector<int>::iterator it = std::find(selected_primes.begin(), selected_primes.end(), elements.first);
    if (it == selected_primes.end())
        selected_primes.push_back(elements.first);

    it = std::find(selected_primes.begin(), selected_primes.end(), elements.second);
    if (it == selected_primes.end())
        selected_primes.push_back(elements.second);
}

void run(int tn)
{
    // cleanup everything
    primes.clear();
    products.clear();
    factors.clear();
    selected_primes.clear();
    dictionary.clear();

    int N, L;
    cin >> N >> L;

    primes.push_back(2);
    for (int i = 3; i <= N; i += 2)
        if (isPrime(i))
            primes.push_back(i);

    for (int i = 0, x; i < L; i++)
    {
        cin >> x;
        products.push_back(x);
    }

    for_each(products.begin(), products.end(), findFactors);
    for_each(factors.begin(), factors.end(), addSelectedPrime);
    std::sort(selected_primes.begin(), selected_primes.end());

    for (int i = 0; i < (int)selected_primes.size(); i++)
        dictionary.insert(std::pair<int, int>(selected_primes[i], ALPHABETS(i)));

    int lastConsidered = 0; // 1 => first, 2 => second
    for (list<pair<int, int>>::iterator itr = factors.begin(); itr != factors.end(); itr++)
    {
        list<pair<int, int>>::iterator itrNext = next(itr, 1);
        if (itrNext == factors.end())
        {
            if (lastConsidered == 1)
                cout << (dictionary.find(itr->first)->second + 65) << endl << flush;
            else if (lastConsidered == 2)
                cout << (dictionary.find(itr->second)->second + 65) << endl << flush;

            break;
        }

        if (itr->first == itrNext->first || itr->first == itrNext->second)
        {
            if (itr == factors.begin())
                cout << (dictionary.find(itr->second)->second + 65) << endl << flush;

                cout << (dictionary.find(itr->first)->second + 65) << endl << flush;
            lastConsidered = 1;
        }
        else if(itr->second == itrNext->first || itr->second == itrNext->second)
        {
            if (itr == factors.begin())
                cout << (dictionary.find(itr->first)->second + 65) << endl << flush;

            cout << (dictionary.find(itr->second)->second + 65) << endl << flush;
            lastConsidered = 2;
        }
    }
}

int main()
{
    int testcases; cin >> testcases;

    for (int testcase = 1; testcase <= testcases; testcase++)
        run(testcase);
}
