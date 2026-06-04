class Solution {
public:
    int ladderLength(string bw, string ew, vector<string>& wl) {

        set<string> s(wl.begin(), wl.end());

        if(!s.count(ew))
            return 0;

        queue<string> q;
        q.push(bw);

        set<string> vis;
        vis.insert(bw);

        int del = 1;

        while(!q.empty()) {

            int sz = q.size();

            for(int i = 0; i < sz; i++) {

                string word = q.front();
                q.pop();

                if(word == ew)
                    return del;

                for(int j = 0; j < word.length(); j++) {

                    string temp = word;

                    for(char k = 'a'; k <= 'z'; k++) {

                        temp[j] = k;

                        if(s.count(temp) && !vis.count(temp)) {

                            q.push(temp);
                            vis.insert(temp);
                        }
                    }
                }
            }

            del++;
        }

        return 0;
    }
};