class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
       int n =nums.size();
        unordered_set<int> s(nums.begin(),nums.end());
        for(int i = k; ; i+=k){
            if(!s.count(i)) return i;
        }
    }
};