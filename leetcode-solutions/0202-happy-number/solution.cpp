class Solution {
public:
    int SOS(int num) {
        int sum = 0;
        while (num > 0) {
            int digit = num % 10;
            sum += digit * digit;
            num /= 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        int slow = n;
        int fast = SOS(n);

        while (fast != 1 && slow != fast) {
            slow = SOS(slow);
            fast = SOS(SOS(fast));
        }

        return fast == 1;
    }
};

