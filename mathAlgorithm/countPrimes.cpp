class Solution {
public:
    int countPrimes(int n) {
        if (n < 2) {
            return 0;
        }
        vector<bool> prime(n, false);
        prime[0] = true;
        prime[1] = true;
        for (int i = 2; i < n; i++) {
            if (!prime[i]) {
                for (int j = i * 2; j < n; j += i) {
                    prime[j] = true;
                }
            }
        }
        int cnt = 0;
        for (bool prm : prime) {
            if (!prm) {
                cnt++;
            }
        }
        return cnt;
    }
};