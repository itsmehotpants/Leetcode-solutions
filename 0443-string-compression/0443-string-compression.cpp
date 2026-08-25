class Solution {
public:
    int compress(vector<char>& chars) {
        int n =chars.size();
        int i = 0,idx= 0;
        while(i<n){
            char curr= chars[i];
            int cnt= 0;
            while(i<n && chars[i]==curr){
                cnt++;
                i++;
            }
            chars[idx]=curr;
            idx++;
            if(cnt>1){
                string cnt_str = to_string(cnt);
                for(char &c:cnt_str){
                    chars[idx] = c;
                    idx++;
                }
            }
        }
        return idx;
    }
};