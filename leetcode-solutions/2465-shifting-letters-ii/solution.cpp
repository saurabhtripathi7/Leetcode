class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();                // Length of the input string
        vector<int> diff(n);               // Create a difference array to apply range updates

        // Step 1: Build the difference array based on the shifts
        for (auto query : shifts) {
            int L = query[0];              // Starting index of the range
            int R = query[1];              // Ending index of the range
            int dir = query[2];            // Direction of the shift (0 = left, 1 = right)

            int x;
            if (dir == 0) {                // If the shift is to the left
                x = -1;
            } else {                       // If the shift is to the right
                x = 1;
            }

            diff[L] += x;                  // Add `x` to the start of the range
            if (R + 1 < n) {               // If `R+1` is within bounds, subtract `x` from it
                diff[R + 1] -= x;          // This marks the end of the range influence
            }
        }

        // Step 2: Compute the cumulative sum from the difference array
        for (int i = 1; i < n; ++i) {
            diff[i] += diff[i - 1];        // Accumulate the influence of previous shifts
        }

        // Step 3: Apply the shifts to the string
        for (int i = 0; i < n; ++i) {
            int shift = diff[i] % 26;      // Calculate the effective shift for the current character
                                           // Use modulo 26 to keep within valid alphabet range
            if (shift < 0) {               // Handle negative shifts (for leftward shifts)
                shift = shift + 26;        // Convert negative shift to equivalent positive shift
            }

            // Update the character by applying the shift
            s[i] = (((s[i] - 'a') + shift) % 26) + 'a';
        }

        return s;                          // Return the modified string
    }
};

