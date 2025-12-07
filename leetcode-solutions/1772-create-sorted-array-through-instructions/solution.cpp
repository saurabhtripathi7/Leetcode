#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template <class T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag,
                         tree_order_statistics_node_update>;
// PBDS
static const int MOD = (int)1e9 + 7;

class Solution {
public:
    int createSortedArray(vector<int>& instructions) {
        ordered_set<int> os;
        int n = instructions.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int curr = instructions[i];
            int smaller = os.order_of_key(curr);
            int greater = os.size() - os.order_of_key(curr + 1);
            ans = (ans % MOD + min(smaller, greater) % MOD) % MOD;
            os.insert(curr);
        }
        return ans;
    }
};
