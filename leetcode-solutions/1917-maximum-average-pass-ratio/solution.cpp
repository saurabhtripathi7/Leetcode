class Solution {
public:
    typedef pair<double, pair<double, double>> p;
    double calcImprovement(double p, double t) {
        return ((p + 1) / (t + 1)) - (p / t);
    }
    double maxAverageRatio(vector<vector<int>>& classes, int k) {
        int n = classes.size();
        // Max heap based on improvement in pass ratio

        priority_queue<p> pq;
        for (int i = 0; i < n; i++) {
            double p = classes[i][0]; // Passes
            double t = classes[i][1]; // Total students
            double improvement = calcImprovement(p, t);
            pq.push({improvement, {p, t}});
        }

        // Distribute extra students
        while (k--) {
            auto top = pq.top();
            pq.pop();

            double p = top.second.first;  // Current passes
            double t = top.second.second; // Current total
            p++;                          // Add one pass
            t++;                          // Add one total student

            // Recalculate improvement and push back doubleo the heap
            double improvement = calcImprovement(p, t);
            pq.push({improvement, {p, t}});
        }

        // Calculate final average pass ratio
        double ans = 0.0;
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();

            double p = top.second.first;
            double t = top.second.second;
            ans += p / t; // Add the pass ratio of this class
        }

        return ans / n; // Return the average
    }
};
