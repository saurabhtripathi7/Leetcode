class Solution {
public:
    bool check(vector<int>& tasks, vector<int>& workers, int pills, int strength, int mid){
        int pillsUsed = 0;
        multiset<int>st(begin(workers), begin(workers)+mid); //choose only strongest mid no of workers
        for(int i = mid-1; i >= 0; --i){
            int required = tasks[i];
            auto it = prev(st.end()); //ptr to last item

            if(*it >= required){
                st.erase(it);
            }
            else if(pillsUsed >= pills){
                return false;
            }
            else{
                //find weakest worker who can do the hardest task with pills
                auto weakestIt = st.lower_bound(required - strength);
                if(weakestIt == st.end()){ //not found
                    return false;
                }
                st.erase(weakestIt);
                pillsUsed++;
            }
        }
        return true;
    }

    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        int m = tasks.size();
        int n = workers.size();

        int l = 0; //min we can do 0 tasks
        int r = min(m,n); // max no of tasks = r
        sort(begin(tasks), end(tasks));
        sort(begin(workers), end(workers), greater<>());

        int result = 0;
        //BS on Ans
        while(l <= r){
            int mid = l + (r-l)/2;

            if(check(tasks, workers, pills, strength, mid)){
                result = mid;
                l = mid+1;
            }
            else{
                r = mid - 1;
            }
        }
        return result;
    }
};
