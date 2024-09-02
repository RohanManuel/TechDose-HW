class Solution {
public:
    bool isPal(int num) {
        string str = to_string(num);
        int i = 0, j = str.size() - 1;
        while (i < j) {
            if (str[i] != str[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    bool isPrm(int num) {
        if (num < 2) {
            return false;
        }
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }

    int primePalindrome(int n) {
        if (n <= 2) {
            return 2;
        }
        if (n % 2 == 0) {
            n++;
        }
        while (true) {
            if (isPal(n) && isPrm(n)) {
                return n;
            }
            n += 2;
            if (1000 < n && n < 10000) {
                n = 10001;
            }
            if (100000 < n && n < 1000000) {
                n = 1000001;
            }
            if (10000000 < n && n < 100000000) {
                n = 100000001;
            }
        }
        return -1;
    }
};
