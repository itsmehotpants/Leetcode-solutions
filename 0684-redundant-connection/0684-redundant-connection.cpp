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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n =edges.size();
        parent.resize(n+1);
        size.resize(n+1,1);
        // for(int i =1;i<n+1;i++) parent[i]=i;
        iota(parent.begin(), parent.end(), 0);
        for( auto &e:edges){
            int u =e[0],v=e[1];
            if(find(u)==find(v)) return {u,v};
            union_n(u,v);
        }
        return {-1};
    }
};