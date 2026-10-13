class Solution {
public:
    double solve(double x, long long n) {
        if (n == 0) {
            return 1.0;
        }
        double half = solve(x, n / 2);
        if (n % 2 != 0) {
            return x * half * half;
        } else {
            return half * half;
        }
    }
    
    double myPow(double x, int n) {
        long long power = n;
        if (power < 0) {
            power = -power;
        }
        double ans = solve(x, power);
        if (n < 0) {
            return 1.0 / ans;
        }
        return ans;
    }
};