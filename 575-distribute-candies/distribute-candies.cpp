class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        set<int> S;
        int count=0;
        int n=candyType.size();
        for(int i=0;i<n;i++){
            if(S.size()<n/2){
                S.insert(candyType[i]);
            }
        }
        count=S.size();
        return count;
    }
};