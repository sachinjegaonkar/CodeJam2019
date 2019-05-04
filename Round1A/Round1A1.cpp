#include "pch.h"

#include <algorithm>
#include <string>
#include <utility>
#include <iostream>
#include <vector>
#include <random>

using namespace std;

vector<string> words;

static bool endsWith(const string& str, const string& suffix)
{
    return str.size() >= suffix.size() && 0 == str.compare(str.size() - suffix.size(), suffix.size(), suffix);
}

void run(int tn)
{
    int N;
    cin >> N;

    words.clear();

    string S;
    for (int i = 0; i < N; i++)
    {
        cin >> S;
        words.push_back(S);
    }

    int pairCount = 0;
    while ((int)words.size() > 0)
    {
        auto word = words[0];
        vector<string>::iterator it = words.end();

        if (word.length() == 1)
        {
            char endchar = word[0];
            string endStr = string(1, endchar);
            if ((int)words.size() > 1 && all_of(words.begin() + 1, words.end(), [endStr](const string& a) {return endsWith(a, endStr); }))
            {
                pairCount += 2;
                it = words.end();
                break;
            }
            else
            {
                it = find_if(words.begin() + 1, words.end(), [endStr](const string& a) {return endsWith(a, endStr); });
                if (it == words.end())
                {
                    words.erase(words.begin());
                    continue;
                }
            }
        }


        int len = word.length() >= 3 ? 3 : 2;

        auto substr = word.substr(word.length() - len);
        //it = find_if(words.begin() + 1, words.end(), [substr](const string& a) {return a.find_last_of(substr, substr.length()) != string::npos; });
        it = find_if(words.begin() + 1, words.end(), [substr](const string& a) {return endsWith(a, substr); });
        if (it == words.end())
        {
            if (len == 3)
            {
                len = 2;
                substr = word.substr(word.length() - 2);
            }
            //it = find_if(words.begin() + 1, words.end(), [substr](const string& a) {return a.find_last_of(substr, substr.length()) != string::npos; });
            it = find_if(words.begin() + 1, words.end(), [substr](const string& a) {return endsWith(a, substr); });
            if (it == words.end())
            {
                char endchar = word[word.length() - 1];
                string endStr = string(1, endchar);
                if ((int)words.size() > 1 && all_of(words.begin() + 1, words.end(), [endStr](const string& a) {return endsWith(a, endStr); }))
                {
                    pairCount += 2;
                    it = words.end();
                    break;
                }
                else
                {
                    it = find_if(words.begin() + 1, words.end(), [endStr](const string& a) {return endsWith(a, endStr); });
                    if (it == words.end())
                    {
                        words.erase(words.begin());
                        continue;
                    }
                }
            }
        }

        if (it != words.end())
        {
            pairCount++;
            if (it != words.begin())
            {
                words.erase(it);
                words.erase(words.begin());
                pairCount++;
            }
            else
                words.erase(it);
        }
    }

    cout << "Case #" << tn << ": " << pairCount << endl << flush;
}

int main()
{
    int testcases; cin >> testcases;

    for (int testcase = 1; testcase <= testcases; testcase++)
        run(testcase);

    return 0;
}
