// #define SATYAM
// #ifdef SATYAM
// const auto satyam = []() {
//     struct RuntimeLogger {
//         static void log() { std::ofstream("display_runtime.txt") << 0 << '\n'; }
//     };
//     std::atexit(&RuntimeLogger::log);
//     return 0;
// }();
// #endif

class Solution {
public:
    bool isAdjacent(string& word1, string& word2) {
        int diffCount = 0, length = word1.size();
        for(int i = 0; i < length; i++) {
            if(word1[i] != word2[i]) diffCount++;
        }
        return diffCount == 1;
    }

    void depthFirstSearch(string& currentWord, map<string, vector<string>>& predecessors, string& startWord, vector<string>& path, vector<vector<string>>& result) {
        if(currentWord == startWord) {
            result.push_back(path);
            return;
        } else {
            for(string predecessor : predecessors[currentWord]) {
                path.push_back(predecessor);
                depthFirstSearch(predecessor, predecessors, startWord, path, result);
                path.pop_back();
            }
        }
    }

    vector<vector<string>> findLadders(string startWord, string endWord, vector<string>& wordList) {
        int wordListSize = wordList.size();
        map<string, vector<string>> adjacencyList;
        int startIdx = -1, endIdx = -1;
        vector<vector<string>> result;
        map<string, int> distances;
        map<string, vector<string>> predecessors;

        for(int i = 0; i < wordListSize; i++) {
            for(int j = i + 1; j < wordListSize; j++) {
                if(isAdjacent(wordList[i], wordList[j])) {
                    adjacencyList[wordList[i]].push_back(wordList[j]);
                    adjacencyList[wordList[j]].push_back(wordList[i]);
                }
            }
            distances[wordList[i]] = INT_MAX;
            if(wordList[i] == startWord) {
                startIdx = i;
            }
            if(wordList[i] == endWord) {
                endIdx = i;
                distances[startWord] = 0;
            }
        }
        
        if(endIdx == -1) return result;

        if(startIdx == -1) {
            wordList.push_back(startWord);
            startIdx = wordListSize;
            wordListSize++;
            for(string word : wordList) {
                if(isAdjacent(startWord, word)) {
                    adjacencyList[startWord].push_back(word);
                }
            }
        }

        queue<string> q;
        q.push(startWord);
        distances[startWord] = 0;
        bool foundEnd = false;
        
        while(!q.empty()) {
            int currentQueueSize = q.size();
            for(int i = 0; i < currentQueueSize; i++) {
                string current = q.front();
                q.pop();
                if(current == endWord) {
                    foundEnd = true;
                }
                for(string neighbor : adjacencyList[current]) {
                    if(distances[neighbor] > distances[current] + 1) {
                        predecessors[neighbor] = {current};
                        distances[neighbor] = distances[current] + 1;
                        q.push(neighbor);
                    } else if(distances[neighbor] == distances[current] + 1) {
                        predecessors[neighbor].push_back(current);
                    }
                }
            }
            if(foundEnd) {
                break;
            }
        }

        if(foundEnd) {
            vector<string> path = {endWord};
            depthFirstSearch(endWord, predecessors, startWord, path, result);
            vector<vector<string>> reversedResult;
            for(auto pathVec : result) {
                reverse(pathVec.begin(), pathVec.end());
                reversedResult.push_back(pathVec);
            }
            return reversedResult;
        } else {
            return {};
        }
    }
};
