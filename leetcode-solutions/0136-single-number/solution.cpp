class Solution {
public:
    int singleNumber(vector<int>& nums) { 
       int ans=0;
	   for(auto x:nums)
	        ans^=x;
	   return ans;
    }
};


auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
