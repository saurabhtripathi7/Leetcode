class Solution {
public:
    // Custom comparator function to decide the sorting order
    static bool myComp(string a, string b) {
        // Concatenate a with b and b with a
        string t1 = a + b;  // concatenate a first, then b
        string t2 = b + a;  // concatenate b first, then a

        // Compare the two concatenated strings and return true if t1 is larger (to sort in descending order)
        return t1 > t2;
    }

    // Function to return the largest number that can be formed by concatenating integers
    string largestNumber(vector<int>& nums) {
        // Convert the integer vector to a string vector
        vector<string> snums;
        for (auto n : nums) {
            snums.push_back(to_string(n));  // convert each integer to string and push to snums
        }

        // Sort the strings using the custom comparator to get the desired order
        sort(snums.begin(), snums.end(), myComp);  // sort based on custom logic to form largest number

        // Edge case: if the largest number is "0", return "0" (to handle cases like [0, 0])
        if (snums[0] == "0") return "0";

        // Concatenate all strings to form the largest number
        string ans = "";
        for (auto s : snums) {
            ans += s;  // append each sorted string to the result
        }

        // Return the final largest number string
        return ans;
    }
};

