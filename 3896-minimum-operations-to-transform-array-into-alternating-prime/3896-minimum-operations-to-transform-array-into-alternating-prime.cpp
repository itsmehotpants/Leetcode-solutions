class Solution {
public:
     bool p(int x) {
        if(x < 2) return false;
        for(int i = 2; i * i <= x; i++)
            if(x % i == 0) return false;
        return true;
    }
    
    int minOperations(vector<int>& a) {
    int ans=0;
        for(int i =0;i<a.size();i++){
            int x= a[i];
            while((i%2==0 && !p(x))|| (i%2 && p(x))){
                x++,ans++;
            }
            
        }
        return ans;
    }
};