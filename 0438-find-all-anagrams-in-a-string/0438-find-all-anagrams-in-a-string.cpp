class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>pfreq(26,0);
        vector<int>winfreq(26,0);

    int n1 = s.length(),n2 = p.length();
if(n2>n1) return {};

for(int i =0;i<n2;i++){
    pfreq[p[i]-'a']++;
    winfreq[s[i]-'a']++;
}

vector<int>ans;
if(pfreq==winfreq) ans.push_back(0);

for(int  i =n2;i<n1;i++){
    winfreq[s[i-n2]-'a']--;
    winfreq[s[i]-'a']++;

    if(pfreq == winfreq) ans.push_back(i-n2+1);
}
return ans;

    }
};