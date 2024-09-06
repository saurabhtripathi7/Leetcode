class Solution {
public:
    // Recursive function to generate letter combinations
    // 'digit' -> input digits string
    // 'res' -> stores the final result (all possible combinations)
    // 'nums' -> mapping of digits to their corresponding letters (like a keypad)
    // 'i' -> current index of the digit being processed
    // 'temp' -> stores the current combination of letters being built
    void myLetterComb(const string& digit, vector<string>& res, const string nums[], int i, string& temp) {
        // Base case: If all digits are processed, store the current combination and return
        if (i == digit.length()) {
            res.push_back(temp);  // Add the valid combination to the result
            return;
        }

        // Fetch the string of letters corresponding to the current digit (digit[i])
        string value = nums[digit[i] - '0'];   // Example: for digit[i] = '2', value = "abc"

        // Loop through each letter corresponding to the current digit
        for (int j = 0; j < value.length(); ++j) {
            temp.push_back(value[j]);  // Add the letter to the temporary string
            myLetterComb(digit, res, nums, i + 1, temp);  // Recursively process the next digit
            temp.pop_back();  // Backtrack by removing the last letter (restoring temp for the next letter)
        }
    }

    // Main function to initiate the letter combinations process
    vector<string> letterCombinations(string digits) {
        vector<string> res;  // This will store all possible combinations

        // Edge case: If input is an empty string, return an empty result
        if(digits.empty()) return res;

        // Array to map each digit (2-9) to its corresponding letters
        const string nums[10] = {
            "",    // 0 -> no letters
            "",    // 1 -> no letters
            "abc", // 2
            "def", // 3
            "ghi", // 4
            "jkl", // 5
            "mno", // 6
            "pqrs",// 7
            "tuv", // 8
            "wxyz" // 9
        };

        string temp;  // Temporary string to build each combination
        myLetterComb(digits, res, nums, 0, temp);  // Start recursive process from the first digit
        return res;   // Return the result containing all possible combinations
    }
};

