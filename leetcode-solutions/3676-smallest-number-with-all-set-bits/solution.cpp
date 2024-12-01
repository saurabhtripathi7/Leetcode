class Solution {
public:
    int smallestNumber(int n) {
        // Convert n to binary string
    std::string binary = std::bitset<32>(n).to_string();
    
    // Remove leading zeros from the binary string
    binary = binary.substr(binary.find('1'));
    
    // Replace all 0s with 1s
    for (char &ch : binary) {
        if (ch == '0') {
            ch = '1';
        }
    }
    
    // Convert the modified binary string back to decimal
    int result = std::stoi(binary, nullptr, 2);
    
    return result;
    }
};
