#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll mxN = 2505;
ll n;
vector<ll> wSize;


vector<vector<ll>> currentState;
ll dp[mxN][mxN];
ll res = 0, maxWidthRes = 0;
ll maxxWidth = 0;

void process(ll i){
	// Ver si puede extender un river length en la fila i
	int l = 1;
	for(int k = 1; k < (ll) currentState[i].size(); k++){
		dp[i][k] = 1;
		if(dp[i][k] > res){
			maxWidthRes = maxxWidth;
			res = dp[i][k];
		}
		if(i == 0) continue;
		for(; l< currentState[i-1].size() && currentState[i-1][l]<=currentState[i][k]+1; l++){
			ll curB = currentState[i-1][l], cur = currentState[i][k], curN = -1;
			if(k != currentState[i].size() -1) curN = currentState[i][k+1];
			if(curB == cur-1 || curB == cur || curB == cur+1){
				dp[i][k] = max(dp[i][k],dp[i-1][l]+1);
				if(dp[i][k] > res){
					maxWidthRes = maxxWidth;
					res = dp[i][k];
				}
			}
			if(curB == curN-1 || curB == curN || curB == curN+1){
				dp[i][k] = max(dp[i][k],dp[i-1][l]+1);
				if(dp[i][k] > res){
					maxWidthRes = maxxWidth;
					res = dp[i][k];
				}
			}
		}
		l--;
	}
}

void solve(ll currentWord, ll maxWidth = maxxWidth){
	if(currentWord >= n) return ;
	
	ll rows = currentState.size();
	
	currentState.push_back({0});
	ll length = -1;
	int i = currentWord;
	for(; i<n && length <= maxWidth; i++){
		ll newLength = length+wSize[i]+1;
		if( newLength <= maxWidth){
			if(length > 0) currentState[rows].push_back(length+1);
			length = newLength;
		}
		else{
			break;
		}
	}
	solve(i,maxWidth);
}
	
	

int main(){
	string s;
	cin>>n;
	ll sum = 0;
	wSize.resize(n);
	memset(dp,0,sizeof dp);
	ll maxWord = -1;
	for(int i = 0; i<n; i++){
		cin>>s;
		wSize[i] = s.size();
		sum+= wSize[i];
		maxWord = max(maxWord, wSize[i]);
		sum++;
	}
	maxWidthRes = maxWord;
	for(int i = maxWord; i<= sum; i++){
		maxxWidth = i;
		solve(0);
		if(currentState.size() <= res){
			break;
		}
		for(int j = 0; j < (ll) currentState.size(); j++){
			process(j);
		}
		currentState.clear();
	}
	

	cout<<maxWidthRes<<" "<<res<<"\n";
	
}
