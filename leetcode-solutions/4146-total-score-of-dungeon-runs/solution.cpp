#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template<class T>
using ordered_set = tree<
    T,
    null_type,
    less<T>,
    rb_tree_tag,
    tree_order_statistics_node_update
>;
// PBDS

class Solution {
public:
    long long totalScore(int hp, vector<int>& damage, vector<int>& req) {
        int n = damage.size();
        vector<long long> pref(n + 1, 0);

        for (int i = 1; i <= n; i++)
            pref[i] = pref[i - 1] + damage[i - 1];

        ordered_set<long long> os;
        long long ans = 0;

        os.insert(pref[0]); // = 0

        for (int i = 1; i <= n; i++) {
            long long L = pref[i] + req[i - 1] - hp;

            int less = os.order_of_key(L);      // count of prefix sums < L
            int ge   = (int)os.size() - less;   // remaining are >= L

            ans += ge;

            os.insert(pref[i]);
        }

        return ans;
    }
};

