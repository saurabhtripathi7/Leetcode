class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int n = row*col;
        
        // for Binary Search in 2D matrix 
        int s = 0;
        int e = n-1;
        while (s <= e){
            int mid = s + (e-s)/2;
            int rowIndex = mid / col;
            int colIndex = mid % col;
            int currentMid = matrix[rowIndex][colIndex]; //represents element at current mid index

            if(currentMid == target) return true;
            else if (currentMid < target){
                // right shift
                s = mid+1;
            }
            else e = mid-1;
        }
        return false;

    }
};
