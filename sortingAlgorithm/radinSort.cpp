class Solution {
public:
    int firstBadVersion(int n) {
        int low = 1;
        int high = n;
        while (low < high) {
            int mid = low + ((high - low) / 2);
            if (isBadVersion(mid)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        if (low == high && isBadVersion(low)) {
            return low;
        } else {
            return -1;
        }
    }
};