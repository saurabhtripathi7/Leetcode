class Solution {
public:
    int calPoints(vector<string>& op) {
        vector<int>record;
        
        for(auto ch: op){
            if(ch != "+" && ch != "D" && ch != "C"){
                record.push_back(stoi(ch));
            }
            else if(ch == "+"){
               int last = record.back();
               int prevLast = record[record.size()-2];
               record.push_back(last + prevLast); 
            }
            else if( ch == "D"){
                int last = record.back();
                record.push_back(last*2);
            }
            else if(ch == "C"){
                record.pop_back();
            }
        }
        return accumulate(record.begin(), record.end(), 0);
    }
};
