class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i=0;
        while(i<matrix.size()&&matrix[i][0]<=target){
            if(matrix[i][0]==target){
                return true;
            }
            i++;
        }
        i--;
        if(i>=0){
            int low=0,high=matrix[i].size(),mid;
            while(low<=high){
                mid=(low+high)/2;
                if(matrix[i][mid]==target){
                    return true;
                }else if(matrix[i][mid]<target){
                    low=mid+1;
                }else{
                    high=mid-1;
                }
            }
        }
        return false;
    }
};