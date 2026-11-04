class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        
        int lsum=0,rsum=0;
        int maxscore=0;
        for(int i=0;i<k;i++){
            lsum+=cardPoints[i];
        }
        maxscore=lsum;
        int rindex=n-1;
        for(int i=0;i<k;i++){
            lsum-=cardPoints[k-i-1];
            rsum+=cardPoints[rindex];
            rindex--;
            maxscore=max(maxscore,lsum+rsum);
        }
        return maxscore;
        
    }
};