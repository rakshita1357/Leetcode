class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int m=n/3;
        vector<int> res;
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        for (auto& pair : freq){
            if(pair.second>m){
                res.push_back(pair.first);
            }
        }
        return res;
    }
};