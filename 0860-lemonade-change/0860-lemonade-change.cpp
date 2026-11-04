class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int cnt1=0;
        int cnt2=0;
        int n=bills.size();
        for(int i=0;i<n;i++){
            if(bills[i]==5)cnt1++;
            else if(bills[i]==10){
                if(cnt1>0)cnt1--;
                else return false;
                cnt2++;
            }
            else {
                if(cnt1>0 && cnt2>0){
                    cnt1--;
                    cnt2--;

                }
                else if(cnt1>=3)cnt1-=3;
                else{
                    return false;
                }
            }
            
        }
        return true;
        
    }
};