#include "pch.h"




/*#include <algorithm>
#include <bitset>
#include <deque>
#include <fstream>
#include <iterator>
#include <list>
#include <map>
#include <queue>
#include <random>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
#include <iostream>


using namespace std;


#define sz(x) (int(x.size()))


void run(int tn)
{
    int D; string S, temp;
    cin >> S;

    temp = S;
    string::size_type len;
    D = stoi(S, &len);

    if (temp.find('4') == string::npos)
    {
        printf("Case #%d: %d 0\n", tn, D);
        return;
    }

    int x, y;
    x = y = D / 2;

    int attempt = 2;
    while (to_string(x).find('4') != string::npos || to_string(y).find('4') != string::npos)
    {
        attempt++;
        while (D % attempt != 0) attempt++;
        x = D/attempt;
        y = x * (attempt -1);
    }

    if (to_string(x).find('4') == string::npos && to_string(y).find('4') == string::npos)
        printf("Case #%d: %d %d\n", tn, x, y);
}


int main()
{
    int testcases; cin >> testcases;

    for (int testcase = 1; testcase <= testcases; testcase++)
        run(testcase);
}
*/

#include <algorithm>
#include <string>
#include <utility>
#include <iostream>

using namespace std;

void run(int tn)
{
    long long D;
    cin >> D;

    long long x, y;
    /*x = y = D / 2;

    int attempt = 2;
    while (to_string(x).find('4') != string::npos || to_string(y).find('4') != string::npos)
    {
        attempt++;
        while (D % attempt != 0 && attempt < D) attempt++;
        x = D / attempt;
        y = x * (attempt - 1);
        printf("attempt #%d: x=%d y=%d, x+y=%d\n", attempt, x, y, x+y);
    }*/

    x = (long long)(D / 2);
    long long reminder = (long long)(D / 2) + (D % 2);
    y = reminder;

    int attempt = 0;
    while (to_string(x).find('4') != string::npos || to_string(y).find('4') != string::npos)
    {
        attempt+=4;
        x = (long long)(D / 2) + attempt; y = reminder - attempt;
    }

    printf("Case #%d: %lld %lld\n", tn, x, y);
}


int main()
{
    int testcases; cin >> testcases;

    for (int testcase = 1; testcase <= testcases; testcase++)
        run(testcase);
}
