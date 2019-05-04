#include "pch.h"

#include <algorithm>
#include <string>
#include <utility>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> store;
vector<vector<int>> response;
vector<int> broken;

void run(int tn)
{
    int N, B, F;
    cin >> N >> B >> F;

    int limit = (F >= 5) ? 5 : 2;

    store.clear();
    response.clear();
    broken.clear();

    vector<vector<int>> s;

    for (int i = 0; i < 2; i++)
    {
        vector<int> temp(N);
        for (int j = 0; j < N; j++)
        {
            if (j % 2 == 0)
            {
                (i == 0) ? temp[j] = 1 : temp[j] = 0;
            }
            else
            {
                (i == 0) ? temp[j] = 0 : temp[j] = 1;
            }
        }
        s.push_back(temp);
    }

    if (limit != 2)
    {
        for (int i = 2; i < 4; i++)
        {
            vector<int> temp(N);
            for (int j = 0; j < N; j++)
            {
                if (i == 2)
                {
                    if (j < N / 2)
                        temp[j] = 0;
                    else
                        temp[j] = 1;
                }
                else
                {
                    if (j < N / 2)
                        temp[j] = 1;
                    else
                        temp[j] = 0;
                }
            }
            s.push_back(temp);
        }

        vector<int> temp(N, 1);
        for (int j = 0; j < N; j++)
        {
            if (j % 3 == 0)
                temp[j] = 0;
        }
        s.push_back(temp);
    }

    for (int i = 0; i < limit; i++)
    {
        for (vector<int>::iterator it = s[i].begin(); it != s[i].end(); ++it)
            cout << *it;
        cout << endl << flush;
        store.push_back(s[i]);

        string res;
        cin >> res; if (res == "-1") exit(0);

        vector<int> r(res.length());
        transform(res.begin(), res.end(), r.begin(),
            [](char c) -> int { return (c - '0'); });
        response.push_back(r);
    }

    for (int i = 0, j = 0; i < N && j < (N - B);)
    {
        bool matchesEveryColumnElement = true;
        for (int x = 0; x < limit; x++)
        {
            if (store[x][i] != response[x][j])
            {
                matchesEveryColumnElement = false;
                break;
            }
        }

        if (!matchesEveryColumnElement)
        {
            broken.push_back(i);
            i++;
        }
        else
        {
            i++;
            j++;
        }

        if (j >= (N - B))
        {
            while (i < N)
            {
                broken.push_back(i);
                i++;
            }
            break;
        }
    }

    for (int i = 0; i < (int)broken.size(); i++)
    {
        if (i == (int)(broken.size() - 1))
            cout << broken[i] << endl << flush;
        else
            cout << broken[i] << " ";
    }

    int verdict; cin >> verdict;
    if (verdict != 1) exit(0);
}

int main()
{
    int testcases; cin >> testcases;

    for (int testcase = 1; testcase <= testcases; testcase++)
        run(testcase);
}
