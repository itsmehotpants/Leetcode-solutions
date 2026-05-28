class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n=s.size();
        unordered_map<char,int>m;
        int i=0,j=0,maxi=0;
        while(j<n)
        {
            m[s[j]]++;
             if(m[s[j]]<=2)
            {
                maxi=max(maxi,j-i+1);
                j++;
            }
            else 
            {
                while(m[s[j]]>2)
                {
                        m[s[i]]--;
                    if(m[s[i]]==0)
                        m.erase(s[i]);
                    i++;
                }
                j++;
            }
        }
        return maxi;
    }
};