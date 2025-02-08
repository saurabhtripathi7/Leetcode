class NumberContainers {
public:
unordered_map<int,int>indexmp;
unordered_map<int,priority_queue<int,vector<int>,greater<int>>>numbermp;
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        indexmp[index] =number;
        numbermp[number].push(index);
    }
    
    int find(int number) {
        if(numbermp.count(number))
        {
            auto &pq = numbermp[number];
            while(!pq.empty())
            {
                int idx=pq.top();
                if(indexmp[idx]==number)
                {
                    return idx;
                }
                pq.pop();

            }
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
