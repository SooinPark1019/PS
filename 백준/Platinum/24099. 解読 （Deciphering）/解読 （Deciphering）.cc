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
const ll mod = 1e7;
const int MAXN = (1<<18)+5;
const int D = 20;

/*
1을 루트로 하는 트리를 생각하자
엘리스는 부모로 올라갈 것이고
퀸은 리프와의 최단 경로로 끌어내릴 것이다
각 정점마다 부모와의 거리, 리프와의 최단 경로를 적어 두자
*/

int DP[300005];
queue<int> Q[30];
int check[30][30]={};

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    string S;
    cin >> S;
    for(int i=0; i<N; i++){
        //cout << S[i]-'A' << endl;
        Q[S[i]-'A'].push(i);
    }

    int M;
    cin >> M;
    for(int i=0; i<M; i++){
        char a, b;
        cin >> a >> b;
        //cout << a-'a' << "  " << b-'a' << endl;
        check[a-'A'][b-'A']=1;
    }

    for(int i=0; i<26; i++){
        if(!Q[i].empty()){
            //cout << Q[i].front() << endl;
            DP[Q[i].front()]=1;
        }
    }
    int ans=0;
    for(int i=0; i<N; i++){
        if(DP[i]==0) continue;
        for(int j=0; j<26; j++){
            if(check[S[i]-'A'][j]) continue;
            while(!Q[j].empty()&&Q[j].front()<=i) Q[j].pop();
            if(Q[j].empty()) continue;
            DP[Q[j].front()]+=DP[i];
            DP[Q[j].front()]%=mod;
        }
        ans+=DP[i];
        ans%=mod;
    }

    cout << ans;

    return 0;
}
