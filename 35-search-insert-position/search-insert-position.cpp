class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l=0;int h=nums.size()-1;
        int mid;
        int t=nums.size();
        while(l<=h){
            mid=(l+h)/2;
            if(nums[mid]<target){
                l=mid+1;
            }
            else{
                t=mid;
                h=mid-1;
            }
        }
        return t;
    }
};