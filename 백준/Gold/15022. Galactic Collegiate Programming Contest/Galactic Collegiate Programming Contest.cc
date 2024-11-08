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
#define int long long

using namespace __gnu_cxx;
using namespace std;

typedef long long ll;
//typedef __int128 i128;
typedef long double ld;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;
const ll LNF = 1e18;
const ll mod = 998244353;
const int MAX = 200005;
const int D = 20;

/*
*/

bool compare(pii A, pii B){
    if(A.first==B.first){
        return A.second>B.second;
    }
    return A.first<B.first;
}

pii status[100005];

vector<int> Fenwick(100005);

int N, M;

void update(int index, long long value){
    while(index>0){
        Fenwick[index]+=value;
        index-=index&(-index);
    }
    return;
}
long long sum(int index){
    long long ret=0;
    while(index<=M){
        ret+=Fenwick[index];
        index+=index&(-index);
    }
    return ret;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;

    vector<pii> V;
    vector<pii> A;

    for(int i=0; i<M; i++){
        int a, b;
        cin >> a >> b;
        status[a].first++;
        status[a].second+=b;
        V.push_back({a, b});
        A.push_back({status[a]});
    }

    A.push_back({0, 0});

    map<pii, int> C;

    sort(all(A), compare);
    A.erase(unique(all(A)), A.end());

    for(int i=0; i<A.size(); i++){
        C[A[i]]=i+1;
    }

    for(int i=0; i<=N; i++){
        status[i]={0, 0};
    }

    for(int i=0; i<M; i++){
        update(C[status[V[i].first]], -1);
        status[V[i].first].first++;
        status[V[i].first].second+=V[i].second;
        update(C[status[V[i].first]], 1);
        cout << sum(C[status[1]]+1)+1 << "\n";
    }

    return 0;
}