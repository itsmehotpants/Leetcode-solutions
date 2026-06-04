class Solution {
private:
    int help(vector<int>& aS , vector<int>& aD , vector<int>& bS , vector<int>& bD){
        int early = INT_MAX;
        for(int i = 0, n = aS.size(); i < n; ++i) early = min(early , aS[i] + aD[i]);
        int res = INT_MAX;
        for(int j = 0, m = bS.size(); j < m; ++j) res = min(res , max(early , bS[j]) + bD[j]);
        return res;
    }
public:
    int earliestFinishTime(vector<int>& lst, vector<int>& ld, vector<int>& wst, vector<int>& wd) {
        int land = help(lst , ld , wst, wd);
        int water = help(wst , wd , lst , ld);
        return min(land , water);
    }
};