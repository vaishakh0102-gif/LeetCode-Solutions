class Solution {
public:

    int findRow(vector<vector<int>>& mat,int n,int col){
        int max=-1,ind=-1;
        for(int i=0;i<n;i++){
            if(mat[i][col]>max){
                max=mat[i][col];
                ind=i;
            }
        }
        return ind;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int low=0,high=m-1;
        while(low<=high){
            int mid=(low+high)/2;
            int rowInd=findRow(mat,n,mid);
            int left= (mid-1>=0)? mat[rowInd][mid-1]:-1;
            int right=(mid+1<m)? mat[rowInd][mid+1]:-1;
            if (mat[rowInd][mid]>left && mat[rowInd][mid]>right)return {rowInd,mid};
            else if (mat[rowInd][mid]<left)high=mid-1;
            else low=mid+1;
        }
        return {-1,-1};
        
    }
};