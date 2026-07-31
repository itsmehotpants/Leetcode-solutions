class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>ans;
        int n =nums.size();
        // unordered_map<int,int>mp;
        // for(int i:nums) mp[i]++;
        // for(auto& [num,freq]:mp){
        //     if(freq>n/3) ans.push_back(num);
        // }
        // return ans;

        int p1=-1,p2=-1,c1=0,c2=0;
        for(int i :nums){
            if(p1==i) c1++;
            else if(p2==i) c2++;
            else if(c1==0) p1=i,c1=1;
            else if(c2==0) p2=i,c2=1;
           
            else c1--,c2--;
        }
        int r1=0,r2=0;
        for(int i:nums){
            if(i==p1) r1++;
            else if(i==p2) r2++;
        }
       // vector<int>ans;
        if(r1>n/3) ans.push_back(p1);
        if(r2>n/3) ans.push_back(p2);
        return ans;
    }
};