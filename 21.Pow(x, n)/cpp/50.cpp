class Solution {
public:
    double myPow(double x, int n) {
        long int N = n;
        if (N < 0) {
            x = 1/x;
            N *= -1;
        }
        if (N == 0) {
            return 1.0;
        } else if (N == 1) {
            return x;
        }
        double result = x;

        long int temp=1;
        while (temp < N){
            result *= result;
            temp *= 2;//记录已经指数运算的部分
        }
        return result * myPow(x, N-temp);//n-temp表示剩余未处理的指数
    }
};
