class Solution {
public:
    bool isPossible(vector<int>& position,int m, int mid){
        int ballCount = 1;
        int lastPos = position[0];

        for(int i=1; i<position.size(); i++){

            if(position[i] - lastPos >= mid ){
            ballCount++;
            lastPos = position[i];
            
            if(ballCount == m) return true;
            }
        }
        return false;   // or return ballCount >= m;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int s = 0;
        int maxi = -1;
        for (int i=0; i < position.size(); i++){
            maxi = max(maxi, position[i]); 
        }
        int e = maxi;
        int ans = -1;
        
        while(s <= e){
            int mid = s + (e-s)/2;
            if(isPossible(position, m, mid)){
                ans = mid;
                s = mid+1;
            }
            else{
                e = mid-1;
            }
        }
        return ans;
    }
};
