class Solution {
public:
    int findKthNumber(int n, int k) {
        auto getCount = [](int prefix, long n) {
            long cur = prefix;
            long next = prefix + 1;
            long count = 0;
            while (cur <= n) {
                count += min(n+1, next) - cur;
                cur *= 10;
                next *= 10;
            }
            return count;
        };
        
        int prefix = 1;
        long count = 1;
        while (count < k) {
            long c = getCount(prefix, n);
            if (count + c > k) {
                prefix *= 10;
                count ++;
            } else {
                prefix++;
                count += c;
            }
        }
        return prefix;
    }
};
