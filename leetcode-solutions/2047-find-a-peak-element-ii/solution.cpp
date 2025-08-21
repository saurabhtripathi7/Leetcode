class Solution {
public:
    
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n, m;
        n = mat.size();
        m = mat[0].size();
        int l = 0, r = m-1;

        while(l <= r){ //BS on rows
            int mid = l + (r-l)/2; //mid row

            int maxRow = 0;
            for(int i = 0; i < n; ++i){
                if(mat[i][mid] > mat[maxRow][mid]){
                    maxRow = i;
                }
            }
            
            int curr = mat[maxRow][mid]; 
            //fetch left and right nbr elems
            int left = (mid - 1 >= 0) ? mat[maxRow][mid-1] : -1;
            int right = (mid + 1 < m) ? mat[maxRow][mid+1] : +1;

            if(curr > left && curr > right){
                return {maxRow, mid};
            }
            else if(left > curr){
                r = mid -1; // go left on the same col
            }
            else{
                l = mid+1; // go right on the same col
            }
        }

        return {-1, -1}; 
    }
};

