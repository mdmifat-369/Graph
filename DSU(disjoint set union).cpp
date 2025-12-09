#include<bits/stdc++.h>
#define mod 1000000007
#define int long long int
using namespace std;
const int N = 2e5+10;

int par[1005];
int group_size[1005];


int Find(int node){

    if(par[node]==-1)return node;
    int leader=Find(par[node]);
    par[node]=leader;

    return leader;
}

bool dsu_union(int node1,int node2){
    int L1=Find(node1);
    int L2=Find(node2);

    if(L1==L2) return false;
    if(group_size[L1]>=group_size[L2]){
         par[L2]=L1;
         group_size[L1]+=group_size[L2];
    }else{
        par[L1]=L2;
        group_size[L2]+=group_size[L1];
    }

    return true;
}

void solve(){
    int n,e;
    cin>>n>>e;
    vector<tuple<int,int,int>>v;

    int real_sum=0;
    while(e--){
        int a,b,c;
        cin>>a>>b>>c;

        v.push_back({c,a,b});
        real_sum+=c;
    }

    sort(v.begin(),v.end());


    int sum=0;
    for(auto[c,a,b]:v){
         
        if(dsu_union(a,b)){
            // cout<< c <<" " <<a <<" "<<b<<endl;
            sum+=c;
        }
    }


    cout<< real_sum <<endl;
    cout<< sum <<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(par,-1,sizeof(par));
    memset(group_size,1,sizeof(group_size));

    solve();
    
    return 0;
}