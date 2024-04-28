class Solution {
public:
    int addedInteger(vector<int>& nums1, vector<int>& nums2) {
        int n1= nums1.size();
        int n2 = nums2.size(); 
        int ans = 0;

        int sum1 = accumulate(nums1.begin(), nums1.end(), 0);
        int sum2 = accumulate(nums2.begin(), nums2.end(), 0);

        ans = (sum2-sum1)/n1;
        return ans;
    }
};
