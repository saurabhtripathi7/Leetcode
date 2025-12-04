class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.size();
        int i = 0, j = n - 1;

        // skip all leading 'L' (they go off to -∞)
        while (i < n && directions[i] == 'L') i++;

        // skip all trailing 'R' (they go off to +∞)
        while (j >= 0 && directions[j] == 'R') j--;

        // if all cars are leading Ls or trailing Rs → no collisions
        if (i > j) return 0;

        // Now every car has something to hit on left and right side (bounded)
        //each car will ultimately collide  except the ones already stationary ('S')
        int stationary = 0;
        for (int k = i; k <= j; k++) {
            if (directions[k] == 'S') stationary++;
        }

        int total = j - i + 1;
        return total - stationary;   // moving cars in middle → all collide
    }
};

 /*
        IMPORTANT LOGIC:

        In the segment directions[i..j]:

        - All 'R' will eventually hit something to the right (L or S)
        - All 'L' will eventually hit something to the left (R or S)
        => Every moving car ('R' or 'L') contributes exactly 1 collision.

        So:

            total_cars_in_middle  = j - i + 1
            non-moving('S') cars   = stationary
            moving cars            = total - stationary
            collisions             = moving cars
*/
