class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        // Direction vectors for North, East, South, West
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};

    int x = 0, y = 0;  // Start position
    int direction = 0; // Start facing North
    int maxDist = 0;
    
    for (int cmd : commands) {
        if (cmd == -2) {
            // Turn left
            direction = (direction + 3) % 4;
        } else if (cmd == -1) {
            // Turn right
            direction = (direction + 1) % 4;
        } else {
            // Move forward k units
            for (int i = 0; i < cmd; ++i) {
                int nx = x + dx[direction];
                int ny = y + dy[direction];
                
                // Check for obstacles
                bool hitObstacle = false;
                for (const auto& obs : obstacles) {
                    if (obs[0] == nx && obs[1] == ny) {
                        hitObstacle = true;
                        break;
                    }
                }

                if (hitObstacle) {
                    // Stop if there's an obstacle
                    break;
                } else {
                    // No obstacle, move to the new position
                    x = nx;
                    y = ny;
                    maxDist = max(maxDist, x * x + y * y);
                }
            }
        }
    }
    
    return maxDist;

        
    }
};
