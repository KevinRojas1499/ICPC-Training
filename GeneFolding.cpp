#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll mxN = 4000005;
ll n;
int d2[mxN];
string s;

void manacher() {
    int l = 0, r = -1;
    for (int i = 0; i < n; i++) {
        int k = (i > r ? 0 : min(d2[l + r - i + 1], r - i + 1)) + 1;
        while (i + k - 1 < n && i - k >= 0 && s[i + k - 1] == s[i - k])
            k++;
        d2[i] = --k;
        if (i + k - 1 > r)
            l = i - k, r = i + k - 1;
    }
}

int main() {
    cin>>s;
    n = s.size();
    manacher();
    ll l = 0, r = 0;

    for(int i = 0; i<n; i++){
        if(i-l <= d2[i]){
            l = i;
        }
    }
    string s1 = s.substr(l);
    reverse(s1.begin(),s1.end());
    s = s1;
    n = s.size();
    manacher();
    for(int i = 0; i<n; i++){
        if(i-r <= d2[i]){
            r = i;
        }
    }
    s1 = s1.substr(r);
    cout<<s1.size()<<"\n";
}