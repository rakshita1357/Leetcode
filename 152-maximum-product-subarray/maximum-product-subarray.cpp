class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxV=1;
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        int res = INT_MIN;
        for(int i=0;i<nums.size();i++){
            maxV*=nums[i];
            res=max(res,maxV);
            if(maxV==0)
                maxV=1;
        }
        maxV=1;
        for(int i=nums.size()-1;i>=0;i--){
            maxV*=nums[i];
            res=max(res,maxV);
            if(maxV==0)
                maxV=1;
        }
        return res;
    }
};