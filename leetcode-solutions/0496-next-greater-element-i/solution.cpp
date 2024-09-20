class Solution {
public:
    
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int mini;
        vector<int>result;
        
        for(int i =0; i < nums1.size(); ++i){
            bool found = false;
            bool hasGreater = false;

            // finding nums1[i] in nums2
            for(int j = 0; j < nums2.size(); ++j)
            {
                if(nums1[i] == nums2[j]) found = true;
            
                // if found and there's a greater element after it
                if(found && nums2[j] > nums1[i]){
                    result.push_back(nums2[j]);
                    hasGreater = true;
                    break;
                }
            }

            if(!hasGreater){
                result.push_back(-1);
            }
        }
        return result;
    }
};
