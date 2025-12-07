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
// PBDS
class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        ordered_set<int>os;
        // nums1[i] - nums2[i] <= nums1[j] - nums2[j] + diff (Rearranged)
        //Push RHS of Inequality
        int n = nums1.size();
        long long ans = 0;
        os.insert(nums1[n-1] - nums2[n-1] + diff);
        for(int i = n-2; i >= 0; --i){
            int val = nums1[i] - nums2[i];
            int sm = os.order_of_key(val);
            int gr = os.size() - sm; // gives no of pair such that LHS <= RHS 
            ans += gr;
            os.insert(val + diff);
        }
        return ans;
    }
};
