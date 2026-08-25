class Solution {
public:
    int compress(vector<char>& c) {
        int n =c.size();
        int idx =0,i=0;

        while(i<n){
            char curr = c[i];
            int cnt= 0;
            while(i<n && c[i]==curr){
                cnt++;
                i++;
            }
            c[idx] = curr;
            idx++;
            if(cnt>1){
                string cnt_str = to_string(cnt);
                for(char &ch:cnt_str){
                    c[idx] = ch;
                    idx++;
                }
           }

        }
        return idx;
    }
};