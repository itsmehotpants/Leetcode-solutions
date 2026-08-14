class Solution {
public:
    int maximumLengthSubstring(string s) {
        int  n=s.size();
        unordered_map<char,int> mp;
        int i=0,j=0,maxi=0;
        while(j<n){
            mp[s[j]]++;
            if(mp[s[j]]<=2){
                maxi = max(maxi,j-i+1);
                j++;
            }
            else{
                while(mp[s[j]]>2){
                    mp[s[i]]--;
                    if(mp[s[i]]==0) mp.erase(s[i]);
                    i++;
                }
                j++;
            }
        }
        return maxi;
    }
};