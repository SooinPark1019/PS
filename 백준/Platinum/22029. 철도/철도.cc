#include "railroad.h"
#include <ext/rope>
#include <bits/stdc++.h>
#define _USE_MATH_DEFINES
//#pragma GCC optimize ("O3")
//#pragma GCC optimize ("Ofast")
//#pragma GCC optimize ("unroll-loops")
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define all(v) (v).begin(), (v).end()
#define zip(v) sort(all(v)); v.erase(unique(all(v)), v.end());
//#define sz(x) (int)x.size()
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>


using namespace std;

typedef long long ll;
typedef complex<double> cpx;
//typedef __int128 i128;
typedef long double ld;
typedef pair<double, int> pdl;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;
const ll LNF = 1e18;
const ll mod = 1e9+7;
const int MAXN = (1<<18)+5;
const double PI = acos(-1);

vector<int> graph[205];
std::vector<std::pair<int, int> > encode_map(int N, int K, int &X, std::vector<std::pair<int, int> > E) {
	//cout << "N : " << N << " K : " << K << endl;
	std::vector<std::pair<int, int> > ret;
	for(int i=1; i<=N; i++){
		graph[i].clear();
	}
    for(auto p : E){
		//cout << "p.first : " << p.first << " p.end : " << p.second << endl;
        graph[p.first].push_back(p.second);
        graph[p.second].push_back(p.first);
    }
	for(int i=1; i<=N; i++){
		//cout << "root : " << i << endl;
		vector<int> dis(N+1, -1);
		vector<vector<int>> V(N+1);
		dis[i]=0;
		queue<int> Q;
		Q.push(i);
		while(!Q.empty()){
			int x=Q.front();
			Q.pop();
			//cout << "x : " << x << endl;
			for(auto j : graph[x]){
				if(dis[j]!=-1) continue;
				//cout << "nxt : " << j << endl;
				dis[j]=dis[x]+1;
				V[dis[j]].push_back(j);
				Q.push(j);
			}
		}
		ret.clear();
		for(auto v : V){
			for(int j=0; j<v.size(); j++){
				for(int k=j+1; k<v.size(); k++){
					//cout << v[j] << " " << v[k] << endl;
					ret.push_back({v[j], v[k]});
					if(ret.size()>=K){
						X=i;
						return ret;
					}
				}
			}
		}
	}
	assert(0);
	return ret;
}

std::vector<std::pair<int, int> > decode_map(int N, int K, int X, std::vector<std::pair<int, int> > E) {
	for(int i=1; i<=N; i++){
		graph[i].clear();
	}
    for(auto p : E){
		//cout << "p.first : " << p.first << " p.end : " << p.second << endl;
        graph[p.first].push_back(p.second);
        graph[p.second].push_back(p.first);
    }
	map<pii, int> M;
	vector<int> dis(N+1, -1);
	queue<int> Q;
	Q.push(X);
	dis[X]=0;
	while(!Q.empty()){
		int x=Q.front();
		Q.pop();
		//cout << "x : " << x << "\n";
		for(auto i : graph[x]){
			if(dis[i]==dis[x]){
				//cout << i << " " << x << "\n";
				M[{i, x}]=1;
				M[{x, i}]=1;
			}
			if(dis[i]!=-1) continue;
			dis[i]=dis[x]+1;
			Q.push(i);
		}
	}
	vector<pii> ret;
	for(auto e : E){
		if(M[e]) continue;
		ret.push_back(e);
	}
	return ret;
}
