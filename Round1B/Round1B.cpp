#include "pch.h"

#include <algorithm>
#include <string>
#include <utility>
#include <iostream>
#include <vector>
#include <random>

using namespace std;

void run(int tn)
{
    int N;
    cin >> N;

    cout << "Case #" << tn << ": " << N << endl << flush;
}

int main()
{
    int testcases; cin >> testcases;

    for (int testcase = 1; testcase <= testcases; testcase++)
        run(testcase);

    return 0;
}
