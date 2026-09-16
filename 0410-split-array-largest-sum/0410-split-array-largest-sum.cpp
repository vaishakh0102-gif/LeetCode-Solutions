class Solution {
private:
    int func(vector<int>& arr, int pages) {
        int stu = 1;
        int pagesStudent = 0;
        int n = arr.size();

        for (int i = 0; i < n; i++) {
            if (pagesStudent + arr[i] <= pages) {
                pagesStudent += arr[i];
            } else {
                stu++;
                pagesStudent = arr[i];
            }
        }
        return stu;
    }

public:
    int splitArray(vector<int>& nums, int k) {
        int low = nums[0];
        int high = 1;
        for (int i = 0; i < nums.size(); i++) {
            low = max(low, nums[i]);
            high += nums[i];
        }

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int countStudents = func(nums, mid);

            if (countStudents > k) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return low;
    }
};