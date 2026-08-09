class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n= nums.size();
        for (int i=0;i<n;i++){
            int cnt=0;
            int num=nums[i];
            for (int j=0;j<n;j++){
                if (nums[j]==num)
                    cnt++;
            }
            if (cnt==1) return num;

        }
        return -1;
    }
};