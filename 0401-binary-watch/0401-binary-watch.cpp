class Solution {
public:
    vector<string> readBinaryWatch(int k) {
        vector<string>res;
        for(int h =0;h<=11;h++){
            for(int m =0;m<=59;m++){
                if(__builtin_popcount(h)+__builtin_popcount(m)==k){
                    string hr = to_string(h);
                    string min  = (m<10?"0":"")+to_string(m);

                    res.push_back(hr+':'+min);
                }
            }
            
        }
return res;
    }
};