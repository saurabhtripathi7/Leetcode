#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template<class T>
using ordered_set = tree<
    T,
    null_type,
    less_equal<T>,
    rb_tree_tag,
    tree_order_statistics_node_update
>;
// PBDS -
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        ordered_set<long long> os;
        int n = nums.size();
        int pairs = 0;
        for(int i = n-1; i >= 0; --i){
            int sm = os.order_of_key(nums[i]);
            pairs += sm;  
            long long val = 2 * 1LL * nums[i];          
            os.insert(val);
        }
        return pairs;
    }
};
