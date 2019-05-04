#include "pch.h"

#include <algorithm>
#include <string>
#include <utility>
#include <iostream>
#include <vector>
#include <random>

using namespace std;
vector<string> programs;

void run(int tn)
{
    long N;
    cin >> N;

    programs.clear();

    long maxLen = 0;
    for (long i = 0; i < N; i++)
    {
        string program;
        cin >> program;

        if ((long)program.length() > maxLen)
            maxLen = (long)program.length();

        programs.push_back(program);
    }

    // Make all programs with equal length
    for (long i = 0; i < (long)programs.size(); i++)
    {
        if ((long)programs[i].length() < maxLen)
        {
            int itrs = maxLen / (long)programs[i].length();
            int reminder = maxLen % (long)programs[i].length();

            string dummy = programs[i];
            //long k = dummy.length();
            programs[i].resize(maxLen);

            for (long j = 0; j < itrs - 1; j++)
            {
                programs[i] += dummy;
            }
            programs[i] += dummy.substr(0, reminder);
        }
    }

    string WinnerProgram = "";

    // Iterate through all programs and determine winning program over all robots
    for (long i = 0; i < (long)maxLen; i++)
    {
        vector<char> moves{ 'R', 'P', 'S' };

        for (long j = 0; j < (long)programs.size(); j++)
        {
            if ((int)moves.size() == 0) break;

            auto position = find(moves.begin(), moves.end(), programs[j][i]);
            if (position != moves.end())
                moves.erase(position);
            else
                continue; // assume aready removed
        }

        if (moves.empty())
        {
            cout << "Case #" << tn << ": IMPOSSIBLE" << endl << flush;
            return;
        }

        if ((int)moves.size() == 2)
        {
            if (moves[0] == 'R' && moves[1] == 'S')
            {
                WinnerProgram.append(1, 'S');
                cout << "Case #" << tn << ": " << WinnerProgram.c_str() << endl << flush;
                return;
            }
            else if (moves[0] == 'P' && moves[1] == 'S')
            {
                WinnerProgram.append(1, 'P');
                cout << "Case #" << tn << ": " << WinnerProgram.c_str() << endl << flush;
                return;
            }
            else if (moves[0] == 'R' && moves[1] == 'P')
            {
                WinnerProgram.append(1, 'R');
                cout << "Case #" << tn << ": " << WinnerProgram.c_str() << endl << flush;
                return;
            }
        }

        if ((int)moves.size() == 1)
        {
            /*if (moves[0] == 'R')
            {
                WinnerProgram.append(1, 'S');
                continue;
            }
            else if (moves[0] == 'P')
            {
                WinnerProgram.append(1, 'R');
                continue;
            }
            else if (moves[0] == 'S')
            {
                WinnerProgram.append(1, 'P');
                continue;
            }*/
            WinnerProgram.append(1, moves[0]);
            continue;
        }

    }

    switch(WinnerProgram[WinnerProgram.length() - 1])
    {
    case 'R':
        WinnerProgram.append(1, 'P');
        break;
    case 'P':
        WinnerProgram.append(1, 'S');
        break;
    case 'S':
        WinnerProgram.append(1, 'R');
        break;
    }
    cout << "Case #" << tn << ": " << WinnerProgram.c_str() << endl << flush;
}

int main()
{
    int testcases; cin >> testcases;

    for (int testcase = 1; testcase <= testcases; testcase++)
        run(testcase);

    return 0;
}
