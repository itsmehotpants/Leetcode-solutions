class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>temp =arr;
        sort(temp.begin(),temp.end());
        unordered_map<int,int>mp;
        for(int i=0;i<temp.size();i++){
            if(!mp.count(temp[i])){
                mp[temp[i]] = mp.size()+1;
            }
        }

        vector<int>res;
        for(int& i:arr){
           i = mp[i];
        }
        return arr;

    }
};