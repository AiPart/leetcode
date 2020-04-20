class Solution {
public:
    int maximumSwap(int num) {
        vector<int> digits;
        int n = num;
        while (n) {
            digits.push_back(n%10);
            n /= 10;
        }
        reverse(digits.begin(), digits.end());

        auto old = digits;

        sort(digits.begin(), digits.end(), greater<int>());
 
        int size = digits.size();
        
        int big = -1;
        int small = -1;
        int si = -1;
        for (int i = 0; i < size; ++i) {
            if (digits[i] != old[i]) {
                big = digits[i];
                small = old[i];
                si = i;
                break;
            }
        }
        int t = big;
        for (int i = size-1; i >=0; --i) {
            if (big != -1 && old[i] == big) {
                old[i] = small;
                big = -1;
            }
            if (i == si) {
                old[i] = t;
            }
        }
        
        int d = 0;
        for (int i: old) {
            d = d*10 +i;
        }
 
        return d;
    }
};
