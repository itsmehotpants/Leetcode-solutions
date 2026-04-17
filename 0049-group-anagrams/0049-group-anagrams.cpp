// class Solution {
// public:
//     vector<vector<string>> groupAnagrams(vector<string>& s) {
//         // better n*klogk          k = max size of string
//          vector<vector<string>> ans;
//          unordered_map<string, vector<string>> mp;

//          for(int i =0;i<s.size();i++){
//     string temp =s[i];
//     sort(temp.begin(),temp.end());

//     mp[temp].push_back(s[i]);

//              }
//              for(auto it:mp){
//                 ans.push_back(it.second);
//              }
//              return ans;
//     }
// };

// best n*k

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& s) {
        unordered_map<string, vector<string>> ans;

        for (string& s : s) {
            array<int, 26> count = {0};

            for (char c : s) {
                count[c - 'a']++;
            }

            string key;
            for (int num : count) {
                key += to_string(num) + "#";
            }

            ans[key].push_back(s);
        }

        vector<vector<string>> res;
        for (auto& entry : ans) {
            res.push_back(move(entry.second));
        }

        return res;        
    }
};