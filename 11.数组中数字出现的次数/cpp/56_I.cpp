class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int res = 0;
        for (int n: nums) {
            res ^= n;
        }
        
        int a = 0;
        int b = 0;
        int i = 1;

        while ((res & i) != i) {
            i <<= 1;
        }
        cout << i<<endl;
        for (int n: nums) {
            if ((n & i) == 0) {
                a ^= n;
            } else {
                b ^= n;
            }
        }

        return {a, b};
    }
};
