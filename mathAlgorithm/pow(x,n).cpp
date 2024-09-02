class Solution {
public:
    double myPow(double x, int n) {
        if (n >= 0) {
            double ans = 1;
            while (n > 0) {
                while (n > 0 && n % 2 == 0) {
                    x *= x;
                    n /= 2;
                }
                ans *= x;
                --n;
            }
            return ans;
        } else {
            n = abs(n);
            double ans = 1;
            while (n > 0) {
                while (n > 0 && n % 2 == 0) {
                    x *= x;
                    n /= 2;
                }
                ans *= x;
                --n;
            }
            return (1 / ans);
        }
    }
};