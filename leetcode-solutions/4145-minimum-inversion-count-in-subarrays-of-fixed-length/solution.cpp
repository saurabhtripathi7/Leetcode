#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

// Policy Based Data Structure (PBDS)
template<class T>
using ordered_set = tree<
    T,
    null_type,
    less<T>,
    rb_tree_tag,
    tree_order_statistics_node_update
>;

class Solution {
public:
    long long minInversionCount(vector<int>& nums, int k) {
        int n = nums.size();
        ordered_set<pair<int,int>> os;
        long long inv = 0;

        // First window
        for (int i = 0; i < k; ++i) {
            int x = nums[i];
            long long greater = os.size() - os.order_of_key({x, INT_MAX});
            inv += greater;
            os.insert({x, i});
        }

        long long ans = inv;

        // Slide window
        for (int L = 0; L + k < n; ++L) {
            int R = L + k - 1;
            int newR = R + 1;

            int y = nums[L];
            int x = nums[newR];

            long long less = os.order_of_key({y, L});
            inv -= less;
            os.erase({y, L});

            long long greater = os.size() - os.order_of_key({x, INT_MAX});
            inv += greater;
            os.insert({x, newR});

            ans = min(ans, inv);
        }

        return ans;
    }
};

