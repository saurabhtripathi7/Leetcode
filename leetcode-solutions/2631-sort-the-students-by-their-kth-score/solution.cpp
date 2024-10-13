class Solution {
public:
    // Method to sort the scores based on a specific index (subject)
    void sort_score(vector<vector<int>>& score, int k) {
        // Sort the 'score' vector using a custom comparator
        sort(score.begin(), score.end(), [k](vector<int>& x, vector<int>& y) {
            // Compare the scores of two students based on the k-th subject score
            return x[k] > y[k]; 
        });
        // The sort is in descending order; higher scores come first
    }
    
    // Method to sort students based on their scores in a specific subject
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        // Call the sort_score method to sort the scores
        sort_score(score, k);
        // Return the sorted scores
        return score;
    }
};

