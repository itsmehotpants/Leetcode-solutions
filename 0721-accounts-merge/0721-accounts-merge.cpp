class Solution {
public:
vector<int>parent,size;
    int find(int n){
        if(n==parent[n]) return n;
        return parent[n]=find(parent[n]);
    }

    void union_n(int a , int b){
        int roota = find(a);
        int rootb=find(b);
        if(roota==rootb) return;
        if(size[roota]<size[rootb]){
            swap(roota,rootb);
        }
        parent[rootb]=roota;
        size[roota]+=size[rootb];
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& acc) {
        int n =acc.size();
        parent.resize(n);
        size.resize(n,1);
        iota(parent.begin(),parent.end(),0);
        unordered_map<string,int>mailToAcc;

        for(int i =0;i<n;i++){
            for(int j =1;j<acc[i].size();j++){
                string email =acc[i][j];
                if(mailToAcc.find(email)==mailToAcc.end()) mailToAcc[email]=i;
                else union_n(i,mailToAcc[email]);
            }
        }
        vector<vector<string>> mergedMails(n);

for(auto [mail,node] : mailToAcc){
    int parent  =find(node);
    mergedMails[parent].push_back(mail);
}

vector<vector<string>> ans;

for(int i=0;i<n;i++){

    if(mergedMails[i].empty()) continue;

    sort(mergedMails[i].begin(),mergedMails[i].end());

    vector<string> temp;
    temp.push_back(acc[i][0]);
    for(auto it:mergedMails[i]) temp.push_back(it);

    ans.push_back(temp);
}

return ans;

    }
};