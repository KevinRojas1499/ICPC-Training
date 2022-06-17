#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll HOR = 1, VER = 2;
ll n, m;

struct Nodo {
    ll x,y,dir,id;

    Nodo(ll xx, ll yy, ll dirr, ll idd){
        x = xx; y = yy; dir = dirr; id = idd;
    }
};

ll getId(ll x,ll y, bool VER){
    ll id = x*n+y;
    id*=2;
    if(VER == 1) id++;
    return id;
}

int main() {
    cin>>n>>m;
    char mat[n][m];
    vector<Nodo> invId;

    ll k = 0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin>>mat[i][j];
            Nodo n1(i,j,HOR,k);
            invId.push_back(n1);
            k++;
            Nodo n2(i,j,VER,k);
            invId.push_back(n2);
        }
    }
    string s;
    cin>>s;
    vector<pair<ll,ll>> adj;    


    



}