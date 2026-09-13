class Solution {
public:
    int countDigits(int num) {
        int cnt=0;
        int cpy=num;
        while(cpy>0){
            int digit=cpy%10;
            if(num%digit==0)cnt++;
            cpy/=10;

        }
        return cnt;
    }
};