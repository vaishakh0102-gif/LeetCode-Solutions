class Solution {
private:
    long long sumSubarrayMins(vector<int>& nums) {
        int n = nums.size();
        vector<int> nse = findNSE(nums);
        vector<int> psee = findPSEE(nums);
        long long total = 0;
        
        for (int i = 0; i < n; i++) {
            long long left = i - psee[i];
            long long right = nse[i] - i;
            long long subways = (left * right);
            long long contribution = (subways * nums[i]);
            total += contribution;
        }
        return total;
    }

    long long sumSubarrayMaxs(vector<int>& nums) {
        int n = nums.size();
        vector<int> nge = findNGE(nums);
        vector<int> pgee = findPGEE(nums);
        long long total = 0;
        
        for (int i = 0; i < n; i++) {
            long long left = i - pgee[i];
            long long right = nge[i] - i;
            long long subways = (left * right);
            long long contribution = (subways * nums[i]);
            total += contribution;
        }
        return total;
    }

    vector<int> findNSE(const vector<int>& nums) {
        int n = nums.size();
        vector<int> nse(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] >= nums[i]) st.pop();
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nse;
    }

    vector<int> findPSEE(const vector<int>& nums) {
        int n = nums.size();
        vector<int> psee(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] > nums[i]) st.pop();
            psee[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return psee;
    }

    vector<int> findNGE(const vector<int>& nums) {
        int n = nums.size();
        vector<int> nge(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] <= nums[i]) st.pop();
            nge[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nge;
    }

    vector<int> findPGEE(const vector<int>& nums) {
        int n = nums.size();
        vector<int> pgee(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] < nums[i]) st.pop();
            pgee[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return pgee;
    }

public:
    long long subArrayRanges(vector<int>& nums) {
        long long maxSum = sumSubarrayMaxs(nums);
        long long minSum = sumSubarrayMins(nums);
        
        return maxSum - minSum;
    }
};