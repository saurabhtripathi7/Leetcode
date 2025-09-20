class Router {
public:
    int maxSize;
    unordered_map<string,vector<int>>packetStore;
    queue<string>que;
    unordered_map<int,vector<int>>desTimeMap;
    Router(int memoryLimit) {
        maxSize = memoryLimit;
    }
    string makeKey(int s, int d, int t){
        return to_string(s) + "_" + to_string(d) +"_" + to_string(t) +"_";
    }
    bool addPacket(int source, int destination, int timestamp) {
        
        string key = makeKey(source,destination,timestamp);
        if(packetStore.find(key)!=packetStore.end()){
            return false;
        }
        if(que.size()>=maxSize){
            forwardPacket();
        }

        que.push(key);
        packetStore[key] = {source,destination,timestamp};
        desTimeMap[destination].push_back(timestamp);

        return true;
    }
    
    vector<int> forwardPacket() {
        if(packetStore.empty())
        return {};
        string key = que.front();
        que.pop();
        vector<int>packet = packetStore[key];
        packetStore.erase(key);
        int d = packet[1];
        desTimeMap[d].erase(desTimeMap[d].begin());
        return packet;
    }

    
    int getCount(int destination, int startTime, int endTime) {
        auto it = desTimeMap.find(destination);
        if(it==desTimeMap.end()||it->second.empty())
        {
            return 0;
        }

        int i = lower_bound(it->second.begin(),it->second.end(),startTime) - it->second.begin();
        int j = upper_bound(it->second.begin(),it->second.end(),endTime) - it->second.begin();

        return j-i;
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */
