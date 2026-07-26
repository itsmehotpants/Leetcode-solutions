class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<pair<int,int>>diff;
        for(int i =0;i<arr.size();i++){
            diff.push_back({abs(arr[i]-x),arr[i]});
        }
        sort(diff.begin(),diff.end());
        vector<int>ans;
        for(int i =0;i<k;i++){
            ans.push_back(diff[i].second);
        }
        sort(ans.begin(),ans.end());
return ans;

    }
};