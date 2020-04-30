class Solution {
public:
    bool isHappy(int n) {
        auto square = [](int n) {
            int res = 0;
            while (n) {
                res += (n%10) * (n%10);
                n /= 10;
            }
            return res;
        };
        int slow = n;
        int fast = n;
        do {
            slow = square(slow);
            fast = square(square(fast));
        } while (slow != fast);

        return slow == 1;
    }
};
