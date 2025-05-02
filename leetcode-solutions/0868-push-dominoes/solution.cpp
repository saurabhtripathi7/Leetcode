class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.length();
        queue<int> q;
        for(int i = 0;i<n;i++){
            if(dominoes[i] == '.')
                q.push(i);
        }
        int prevSize = 0;
        while(!q.empty()){
            int qSize = q.size();
            if(prevSize == qSize)
                break;
            string currentState = dominoes;
            for(int i = 0;i<qSize;i++){
                int ind = q.front();
                q.pop();
                if(ind > 0 and ind < n-1 and dominoes[ind - 1] == 'R' and dominoes[ind+1] == 'L')
                    continue;
                else if(ind > 0 and dominoes[ind-1] == 'R')
                    currentState[ind] = 'R';
                else if(ind < n-1 and dominoes[ind+1] == 'L'){
                    currentState[ind] = 'L';
                }
                else
                    q.push(ind);
            }
            prevSize = qSize;
            dominoes = currentState;
        }
        return dominoes;
    }
};
