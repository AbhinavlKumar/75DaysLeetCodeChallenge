#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> parent, rankv;

    DSU(int n) {
        parent.resize(n);
        rankv.resize(n,0);
        for(int i=0;i<n;i++) parent[i]=i;
    }

    int find(int x){
        if(parent[x]!=x)
            parent[x]=find(parent[x]);
        return parent[x];
    }

    bool unite(int a,int b){
        int pa=find(a), pb=find(b);
        if(pa==pb) return false;

        if(rankv[pa] < rankv[pb])
            swap(pa,pb);

        parent[pb]=pa;

        if(rankv[pa]==rankv[pb])
            rankv[pa]++;

        return true;
    }
};

class Solution {
public:

    bool can(int n, vector<vector<int>>& edges, int k, int x){

        DSU dsu(n);
        int used=0;
        int upgrades=0;

        vector<pair<int,int>> normal;
        vector<pair<int,int>> upgrade;

        for(auto &e:edges){
            int u=e[0],v=e[1],s=e[2],m=e[3];

            if(m==1){
                if(s<x) return false;
                if(!dsu.unite(u,v)) return false;
                used++;
            }
        }

        for(auto &e:edges){
            int u=e[0],v=e[1],s=e[2],m=e[3];

            if(m==0){
                if(s>=x)
                    normal.push_back({u,v});
                else if(s*2>=x)
                    upgrade.push_back({u,v});
            }
        }

        for(auto &p:normal){
            if(dsu.unite(p.first,p.second))
                used++;
        }

        for(auto &p:upgrade){
            if(upgrades==k) break;
            if(dsu.unite(p.first,p.second)){
                upgrades++;
                used++;
            }
        }

        return used==n-1;
    }

    int maxStability(int n, vector<vector<int>>& edges, int k) {

        int left=0;
        int right=200000;
        int ans=-1;

        while(left<=right){
            int mid=(left+right)/2;

            if(can(n,edges,k,mid)){
                ans=mid;
                left=mid+1;
            }
            else
                right=mid-1;
        }

        return ans;
    }
};