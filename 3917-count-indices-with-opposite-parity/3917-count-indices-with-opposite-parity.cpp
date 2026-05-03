class Solution {
public:
    vector<int> countOppositeParity(vector<int>& a) {
      int o=0,e=0;
       for(int x:a) x&1?o++:e++;
        vector<int>res;
        for(int x:a){
            if(x&1){
                o--;
                res.push_back(e);
            }
            else{
                e--;
                res.push_back(o);
            }
            
        }
        return res;
    }
};