class Solution {
public:
    double maxAmount(string initialCurrency, 
                       vector<vector<string>>& pairs1, vector<double>& rates1, 
                       vector<vector<string>>& pairs2, vector<double>& rates2) {
 
        auto graph1 = buildGraph(pairs1, rates1);
        auto graph2 = buildGraph(pairs2, rates2);

        unordered_map<string, double> day1Values;
        day1Values[initialCurrency] = 1.0; 
        bfs(graph1, day1Values);

        
        unordered_map<string, double> day2Values = day1Values; 
        bfs(graph2, day2Values);

        
        return day2Values[initialCurrency];
    }

private:

    unordered_map<string, vector<pair<string, double>>> buildGraph(vector<vector<string>>& pairs, vector<double>& rates) {
        unordered_map<string, vector<pair<string, double>>> graph;
        for (int i = 0; i < pairs.size(); ++i) {
            string from = pairs[i][0], to = pairs[i][1];
            double rate = rates[i];
            graph[from].emplace_back(to, rate);    // Forward conversion
            graph[to].emplace_back(from, 1.0 / rate); // Backward conversion
        }
        return graph;
    }

    void bfs(unordered_map<string, vector<pair<string, double>>>& graph, unordered_map<string, double>& values) {
        queue<string> q;
        for (const auto& [currency, _] : values) {
            q.push(currency);
        }

        while (!q.empty()) {
            string current = q.front();
            q.pop();
            double currentValue = values[current];

            for (const auto& [neighbor, rate] : graph[current]) {
                double newValue = currentValue * rate;
                if (newValue > values[neighbor]) {
                    values[neighbor] = newValue;
                    q.push(neighbor);
                }
            }
        }
    }
};

