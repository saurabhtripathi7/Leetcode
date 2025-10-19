#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(string &s, int b) {
        reverse(s.begin(), s.begin() + b);
        reverse(s.begin() + b, s.end());
        reverse(s.begin(), s.end());
    }

    string findLexSmallestString(string s, int a, int b) {
        string smallestString = s;
        queue<string> q;
        unordered_set<string> visited;

        q.push(s);
        visited.insert(s);

        while (!q.empty()) {
            string curr = q.front();
            q.pop();

            smallestString = min(smallestString, curr);

            // Operation 1: Add 'a' to odd indices (problem definition)
            string temp = curr;
            for (int i = 1; i < temp.length(); i += 2) {
                temp[i] = (temp[i] - '0' + a) % 10 + '0';
            }
            if (!visited.count(temp)) {
                visited.insert(temp);
                q.push(temp);
            }

            // Operation 2: Rotate left by b
            string rotated = curr;
            rotate(rotated, b);
            if (!visited.count(rotated)) {
                visited.insert(rotated);
                q.push(rotated);
            }
        }
        return smallestString;
    }
};

