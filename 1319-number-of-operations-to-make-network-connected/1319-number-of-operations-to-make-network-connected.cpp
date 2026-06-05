class Solution {
public:

vector<int>parent,size;
    int find(int x){
        if(x==parent[x]) return x;
        return parent[x]=find(parent[x]);
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
    int makeConnected(int n, vector<vector<int>>& conn) {
        int sz =conn.size();
        if(sz<n-1) return -1;
        parent.resize(n);
        size.resize(n,1);
        iota(parent.begin(),parent.end(),0);
        for(auto &e:conn){
            int u = e[0],v=e[1];
            union_n(u,v);
        }
        // cout<<size[0];
        // return n-size[0];
        int comp=0;
        for(int i =0;i<n;i++){
            if(find(i)==i)
            comp++;
        }
        return comp-1;//leader will also satisfy the condition
    }
};