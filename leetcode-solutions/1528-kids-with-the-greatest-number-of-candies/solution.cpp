class Solution 
{

public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) 
    {
        vector<bool> result;
        int currMax = 0;
        for (auto it : candies) {
            if (it > currMax) {
                currMax = it;
            }
        }
        for (int i = 0; i < candies.size(); ++i) 
        {
            if (candies[i] + extraCandies >= currMax)
            {
                result.push_back(true);
            } else {
                result.push_back(false);
            }
        }

         return result;
    }
};
