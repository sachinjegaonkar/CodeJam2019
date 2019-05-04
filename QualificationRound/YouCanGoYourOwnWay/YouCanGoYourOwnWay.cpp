#include "pch.h"


#include <algorithm>
#include <string>
#include <utility>
#include <iostream>

using namespace std;

void run(int tn)
{
    int N; string S;
    cin >> N >> S;

    printf("Case #%d: ", tn);
    for (auto itr = S.begin(); itr != S.end(); itr++)
    {
        if (*itr == 'E')
            printf("S");
        else
            printf("E");
    }
    printf("\n");
}


int main()
{
    int testcases; cin >> testcases;

    for (int testcase = 1; testcase <= testcases; testcase++)
        run(testcase);
}
