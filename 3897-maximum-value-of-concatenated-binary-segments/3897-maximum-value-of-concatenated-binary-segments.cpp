class Solution {
public:
    int maxValue(vector<int>& nums1, vector<int>& nums0) {
        int n=nums1.size();

        vector<string>v;

        for(int i=0;i<n;i++){
            string temp=string(nums1[i],'1');
            temp+=string(nums0[i],'0');
            v.push_back(temp);
        }

        sort(v.begin(),v.end(),[](const string&a, const string& b){
            return a+b>b+a;
        });

        string s;
        
        for(auto t:v) s+=t;

        int mod=1e9+7;
        long long ans=0;

        for(char bit:s) ans=(ans*2 + (bit-'0')) %mod;

        return ans;
    }
};