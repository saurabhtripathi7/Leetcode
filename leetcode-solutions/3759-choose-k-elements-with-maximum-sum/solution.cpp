class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<long long> ans(n, 0);
        vector<int> idx(n);
        
        for (int i = 0; i < n; i++) {
            idx[i] = i;
        }
        
        sort(idx.begin(), idx.end(), [&](int a, int b) {
            return nums1[a] < nums1[b];
        });
        
        priority_queue<int, vector<int>, greater<int>> minHeap;
        long long runningSum = 0;
        int i = 0;
        
        while (i < n) {
            int j = i;
            while (j < n && nums1[idx[j]] == nums1[idx[i]]) {
                ans[idx[j]] = runningSum;
                j++;
            }
            for (int p = i; p < j; p++) {
                int curIdx = idx[p];
                minHeap.push(nums2[curIdx]);
                runningSum += nums2[curIdx];
                if (minHeap.size() > k) {
                    runningSum -= minHeap.top();
                    minHeap.pop();
                }
            }
            i = j;
        }
        
        return ans;
    }
};

