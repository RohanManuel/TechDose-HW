class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans,count=0;
        for(int i:nums){
            if(count==0){
                ans=i;
            }
            if(i==ans){
                count=count+1;
            }else{
                count=count-1;
            }
        }
        return ans;
    }
};