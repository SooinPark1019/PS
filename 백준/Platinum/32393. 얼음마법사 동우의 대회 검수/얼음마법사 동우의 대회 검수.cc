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
const ll mod = 1e9+7;
const int MAXN = 1e9+7;
const int D = 20;

int N, M, Q;
set<int> contest[100005];
int maxtester[100005];
int contval[100005];
int testerval[100005];
map<int, int> whenbinding[100005];

struct query{
    int type, contest, tester, value;
};

vector<query> V;

void check(){
    for(auto q : V){
        if(q.type==1){
            if(contest[q.contest].find(q.tester)==contest[q.contest].end()){
                contest[q.contest].insert(q.tester);
                maxtester[q.contest]=max(maxtester[q.contest], (int)contest[q.contest].size());
            }
            else{
                contest[q.contest].erase(q.tester);
            }
        }
    }
}

void type1(int c, int t){
    if(maxtester[c]<=sqrt(N)){
        if(contest[c].find(t)==contest[c].end()){
            contest[c].insert(t);
        }
        else{
            contest[c].erase(t);
        }
    }
    else{
        if(contest[c].find(t)==contest[c].end()){
            contest[c].insert(t);
            whenbinding[t][c]=contval[c];
        }
        else{
            contest[c].erase(t);
            testerval[t]+=contval[c]-whenbinding[t][c];
            whenbinding[t].erase(c);
        }
    }
}

void type2(int c, int val){
    if(maxtester[c]<=sqrt(N)){
        for(auto i : contest[c]){
            testerval[i]+=val;
        }
    }
    else{
        contval[c]+=val;
    }
}

void type3(int t){
    int ans=testerval[t];
    for(auto p : whenbinding[t]){
        int c=p.first;
        int v=p.second;
        ans+=contval[c]-v;
    }
    cout << ans << "\n";
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> Q;

    for(int i=0; i<Q; i++){
        int type, contest, tester, value;
        cin >> type;
        if(type==1){
            cin >> contest >> tester;
        }
        else if(type==2){
            cin >> contest >> value;
        }
        else{
            cin >> tester;
        }
        V.push_back({type, contest, tester, value});
    }

    check();
    for(int i=1; i<=M; i++){
        contest[i].clear();
    }

    for(auto q : V){
        if(q.type==1) type1(q.contest, q.tester);
        else if(q.type==2) type2(q.contest, q.value);
        else type3(q.tester);
    }
    
    return 0;
}