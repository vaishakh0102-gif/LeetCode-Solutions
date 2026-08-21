class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int cnt1=0,cnt2=0;
        vector<int>ele;
        int ele1,ele2;
        for (int i=0;i<n;i++){
            if (cnt1==0&& nums[i]!=ele2){
                cnt1=1;
                ele1=nums[i];
            }
            else if (nums[i]==ele1)cnt1++;
            else if ((nums[i]!=ele1 && cnt2==0)){
                cnt2=1;
                ele2=nums[i];

            }
            else if (nums[i]==ele2)cnt2++;
            else {
                cnt1--;
                cnt2--;

            }
        }
        int cnt3=0,cnt4=0;
        for (int i=0;i<n;i++){
            if (nums[i]==ele1) cnt3++;
            else if (nums[i]==ele2) cnt4++;
        }
        if (cnt3 > n / 3) ele.push_back(ele1);
        if (cnt4 > n / 3) ele.push_back(ele2);
        return ele;
        
    
    
    }
   
};