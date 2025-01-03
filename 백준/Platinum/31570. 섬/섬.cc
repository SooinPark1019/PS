#include "island.h"
#include <ext/rope>
#include <bits/stdc++.h>
#define _USE_MATH_DEFINES
#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define all(v) (v).begin(), (v).end()
#define zip(v) sort(all(v)); v.erase(unique(all(v)), v.end());
//#define int long long
#define sz(x) (int)x.size()

using namespace __gnu_cxx;
using namespace std;

typedef long long ll;
typedef complex<double> cpx;
//typedef __int128 i128;
typedef long double ld;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;
const ll LNF = 1e18;
const ll mod = 998244353;
const int MAXN = (1<<18)+5;
const double PI = acos(-1);

/*
먼저 각 간선들에 대해 간선의 양 끝점과 모두 인접한 정점이 존재하는지를 검사한다

존재한다면 해당 세 점을 처음의 삼각형으로 생각하고 해당 삼각형 내부에서 지역을 생성한다

여기서 대충 간선 세 개씩 사이클 안 생기게 잘 고르고
이후 얘네랑 인접한 점들 중에서 두번 이상 등장하는 놈들을 고른다

그렇게 정점하나씩 추가하면서 인접한 간선 하나씩을 트리에 추가하고 이거를 반복
*/
vector<int> graph[200005];
vector<int> cur_adj[200005];
set<int> cur;
queue<int> nxt;

void add_adj(int node){
    for(auto i : graph[node]){
        if(cur.find(i)!=cur.end()) continue;
        cur_adj[i].push_back(node);
        if(cur_adj[i].size()==2){
            nxt.push(i);
        }
    }
}

void construct_two_trees(int N, std::vector<int> U, std::vector<int> V){
    for(int i=0; i<N; i++){
        graph[i].push_back((i+1)%N);
        graph[i].push_back((i-1+N)%N);
    }
    for(int i=0; i<U.size(); i++){
        graph[U[i]].push_back(V[i]);
        graph[V[i]].push_back(U[i]);
    }

    int initiala=-1, initialb=-1, initialc=-1;
    for(int i=0; i<N; i++){
        set<int> S;
        for(auto j : graph[i]){
            S.insert(j);
        }
        for(auto j : graph[i]){
            for(auto k : graph[j]){
                if(S.find(k)!=S.end()){
                    initiala=i;
                    initialb=j;
                    initialc=k;
                    break;
                }
            }
            if(initiala!=-1) break;
        }
        if(initiala!=-1) break;
    }
    //cout << initiala << " " << initialb << " " << initialc << "\n";
    add_vertex(initiala, initialb, initialc);

    cur.insert(initiala);
    cur.insert(initialb);
    cur.insert(initialc);
    vector<array<int, 2>> tree1;
    vector<array<int, 2>> tree2;

    tree1.push_back({initiala, N});
    tree1.push_back({initialb, N});
    tree1.push_back({initialc, initialb});
    tree2.push_back({initiala, initialb});
    tree2.push_back({initiala, initialc});
    tree2.push_back({N, initialc});

    add_adj(initiala);
    add_adj(initialb);
    add_adj(initialc);

    while(!nxt.empty()){
        int x=nxt.front();
        nxt.pop();
        int flag=0;
        for(auto j : cur_adj[x]){
            if(flag==0){
                tree1.push_back({j, x});
                flag=1;
            }
            else tree2.push_back({j, x});
        }
        add_adj(x);
    }
    report(tree1);
    report(tree2);
}
