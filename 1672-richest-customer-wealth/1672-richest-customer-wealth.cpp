class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxWealth = 0;
        for (int i = 0; i < accounts.size(); i++) {
            int currentSum = 0;

          
            for (int j = 0; j < accounts[i].size(); j++) {
                currentSum += accounts[i][j];
            }
            maxWealth=max(maxWealth,currentSum);
        }
        return maxWealth;
        

        
    }
};