class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        // Step 1: Sort the skill array to facilitate pairing
        sort(skill.begin(), skill.end());
        
        int i = 0; // Start pointer (smallest skill)
        int j = skill.size() - 1; // End pointer (largest skill)
        
        long long totalChemistry = 0;
        int expectedSum = skill[i] + skill[j]; // The sum of the first pair (smallest + largest)
        
        // Step 2: Form pairs and check if their sums match the expected sum
        while (i < j) {
            int currentSum = skill[i] + skill[j]; // Current pair sum
            
            // If the current sum doesn't match the expected sum, return -1
            if (currentSum != expectedSum) {
                return -1;
            }
            
            // Add the product of the pair to the total chemistry
            totalChemistry += (long long)skill[i] * skill[j];
            
            i++; // Move the left pointer forward
            j--; // Move the right pointer backward
        }
        
        // Step 3: Return the total chemistry of all valid pairs
        return totalChemistry;
    }
};

