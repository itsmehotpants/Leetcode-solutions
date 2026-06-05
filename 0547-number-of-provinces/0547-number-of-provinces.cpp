class Solution {
public:

    vector<int>parent,size;
    int find(int x){
        if(x==parent[x]) return x;
        return parent[x] =find(parent[x]);
    }

    void unite(int a,int b){
        int roota=find(a),rootb=find(b);
        if(roota==rootb) return;
        if(size[roota]<size[rootb]){
            swap(roota,rootb);
        }
        parent[rootb]=roota;
        size[roota]+=size[rootb];
    }


    int findCircleNum(vector<vector<int>>& conn) {
        int n =conn.size();
        parent.resize(n);
        size.resize(n,1);
        for(int i =0;i<n;i++) parent[i]=i;
        for(int i =0;i<n;i++){
            for(int j =i+1;j<n;j++){
                if(conn[i][j]==1) unite(i,j);
            }
        }
        unordered_set<int>s;
        for(int i =0;i<n;i++){
            s.insert(find(i));
        }
        return s.size();
    }
};