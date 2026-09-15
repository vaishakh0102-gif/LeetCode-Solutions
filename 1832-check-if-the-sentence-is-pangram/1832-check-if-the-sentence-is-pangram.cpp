class Solution {
public:
    bool checkIfPangram(string sentence) {
        int n=sentence.size();
        if(n<26)return false;
        int seen[26]={0};
        for(int i=0;i<n;i++){
            seen[sentence[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if (seen[i]==0)return false;
            
        }
        return true;

        // bool seen[26] = {false};
        // int count = 0;

        // for (int i = 0; i < n; i++) {
        //     int idx = sentence[i] - 'a';
        //     if (!seen[idx]) {
        //         seen[idx] = true;
        //         count++;
        //         if (count == 26) return true; // Early exit
        //     }
        // }

        // return false;
        
    }
    
    
};