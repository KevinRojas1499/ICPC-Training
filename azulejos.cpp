#include <bits/stdc++.h>
#define ll long long

using namespace std;

bool cmp(pair<ll,ll> a, pair<ll,ll> b){
    if(a.first < b.first) return true;
    else if ( a.first > b.first) return false;
    else {
        return a.second > b.second;
    }
}
bool cmp2(pair<pair<ll,ll>,ll> a, pair<pair<ll,ll>,ll> b){
    return cmp(a.first,b.first);
}

int main (){
    ll n;
    cin>>n;
    set<ll> precios;
    vector<pair<ll,ll>> ab(n),ar(n);
    vector<pair<pair<ll,ll>,ll>> abConIdx(n);
    for(int i = 0; i<n; i++) cin>>ar[i].first;
    for(int i = 0; i<n; i++) cin>>ar[i].second;
    for(int i = 0; i<n; i++) cin>>ab[i].first;
    for(int i = 0; i<n; i++) cin>>ab[i].second;

    for(int i = 0; i<n; i++) abConIdx[i] = {ab[i],i};
    
    for(int i = 0; i<n; i++) precios.insert(ar[i].first);

    map<ll, multiset<pair<ll,ll>>> al;
    for(int i = 0; i<n; i++){
        al[ar[i].first].insert({ar[i].second,i});
    }
    sort(ab.begin(),ab.end(),cmp);
    sort(abConIdx.begin(),abConIdx.end(),cmp2);

    multiset<pair<ll,ll>> cur;
    vector<ll> resAr(n);
    auto idx = precios.begin();    
    cur = al[(*idx)];
    bool possible = true;
    for(int i = 0; i<n; i++){
        auto it = cur.upper_bound({ab[i].second,n+1});
        if(it == cur.end()) {
            possible = false;
            break;
        }
        resAr[i] = (*it).second;
        cur.erase(it);
        if(cur.size() == 0) {
            idx++;
            cur = al[(*idx)];
        }
    }
    if(possible){
        for(int i = 0; i<n; i++){
            cout<<resAr[i]+1<<" ";
        }
        cout<<"\n";
        for(int i = 0; i<n; i++){
            cout<<abConIdx[i].second+1<<" ";
        }
        cout<<"\n";
    }
    else{
        cout<<"impossible\n";
    }


}
