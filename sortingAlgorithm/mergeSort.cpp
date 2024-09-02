class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int len=size(nums);
        vector <int> res={-1,-1};
        for(int i=0;i<len;i++){
            if(nums[i]==target){
                res[0]=i;
                break;
            }
        }
        for(int i=len-1;i>=0;i--){
            if(nums[i]==target){
                res[1]=i;
                break;
            }
        }
        return res;
    }
};