class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        // Store {position, speed}
        vector<pair<int, int>> cars;
        for (int i = 0; i < n; i++) {
            cars.push_back({position[i], speed[i]});
        }

        // Closest to target first
        sort(cars.rbegin(), cars.rend());

        int fleets = 0;

        // Time taken by the fleet immediately ahead
        double lastFleetTime = 0;

        for (auto [pos, spd] : cars) {
            double currTime = (double)(target - pos) / spd;

            // Current car cannot catch the fleet ahead
            if (currTime > lastFleetTime) {
                fleets++;

                // This car becomes the new fleet ahead
                lastFleetTime = currTime;
            }
            // Otherwise currTime <= lastFleetTime:
            // current car catches the fleet ahead,
            // so it joins that fleet.
        }

        return fleets;
    }
};