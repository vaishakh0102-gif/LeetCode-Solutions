class Solution {
private:
    int possible(vector<int>& arr, int capacity, int n) {
        int cnt = 1;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            if (sum > capacity) {
                cnt++;
                sum = arr[i];
            }
        }
        return cnt;
    }

public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int sum = 0;
        int max_weight = weights[0];

        for (int i = 0; i < n; i++) {
            sum += weights[i];
            if (weights[i] > max_weight) {
                max_weight = weights[i];
            }
        }

        int low = max_weight;
        int high = sum;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (possible(weights, mid, n) <= days) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};