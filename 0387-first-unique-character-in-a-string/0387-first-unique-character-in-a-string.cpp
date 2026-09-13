class Solution {
public:
    int firstUniqChar(string s) {
        int n=s.size();
        // for(int i=0;i<n;i++){
        //     int cnt=0;
        //     for(int j=0;j<n;j++){
        //         if(s[i]==s[j]) cnt++ ;
                
        //     }
        //     if (cnt==1)return i;

        // }
        // return -1;

        int hash[26]={0};
        for(int i=0;i<n;i++)hash[s[i]-'a']++;
        for(int i=0;i<n;i++){
            if(hash[s[i]-'a']==1)return i;
        }
        return -1;
        
    }
};