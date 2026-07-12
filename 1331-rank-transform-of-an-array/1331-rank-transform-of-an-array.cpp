// class Solution {
// public:
//     vector<int> arrayRankTransform(vector<int>& arr) {
//         vector<int>temp =arr;
//       //  sort(temp.begin(),temp.end());
//         map<int,int>mp;
//         for(int i=0;i<temp.size();i++){
//             if(!mp.count(temp[i])){
//                 mp[temp[i]] = mp.size()+1;
//             }
//         }

//         vector<int>res;
//         for(int& i:arr){
//            i = mp[i];
//         }
//         return arr;

//     }
// };

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int,int> mp;

        for(int x:arr)
            mp[x];

        int rank=1;

        for(auto &p:mp)
            p.second=rank++;

        for(int &x:arr)
            x=mp[x];

        return arr;
    }
};