class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        vector<int> distances(houses.size(), INT_MAX);

        // Calculate distance to nearest right-hand side heater
        for (int i = 0, h = 0; i < houses.size() && h < heaters.size();) {
            if (houses[i] <= heaters[h]) {
                distances[i] = heaters[h] - houses[i];
                i++;
            } else {
                h++;
            }
        }

        // Calculate distance to nearest left-hand side heater
        for (int i = houses.size() - 1, h = heaters.size() - 1;
             i >= 0 && h >= 0;) {
            if (houses[i] >= heaters[h]) {
                distances[i] = min(distances[i], houses[i] - heaters[h]);
                i--;
            } else {
                h--;
            }
        }

        return *max_element(distances.begin(), distances.end());
    }
};
