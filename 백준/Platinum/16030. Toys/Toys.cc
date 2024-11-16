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
//#define int long long

using namespace __gnu_cxx;
using namespace std;

typedef long long ll;
//typedef __int128 i128;
typedef long double ld;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;
const ll LNF = 1e18;
const ll mod = 20070713;
const int MAXN = (1<<18)+5;
const int D = 20;

/*
1을 루트로 하는 트리를 생각하자
엘리스는 부모로 올라갈 것이고
퀸은 리프와의 최단 경로로 끌어내릴 것이다
각 정점마다 부모와의 거리, 리프와의 최단 경로를 적어 두자
*/

vector<int> ans;
vector<int> divisors;
set<int> S[1400];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;

    for(int i=1; i*i<=N; i++){
        if(N%i) continue;
        divisors.push_back(i);
        divisors.push_back(N/i);
    }

    sort(all(divisors));
    divisors.erase(unique(all(divisors)), divisors.end());

    /*for(auto i : divisors) cout << i << " ";
    cout << "\n";*/

    S[0].insert(0);

    /*for(int i=0; i<divisors.size(); i++){
        S[i].insert(divisors[i]-1);
    }*/

    for(int i=0; i<divisors.size(); i++){
        //cout << i << endl;
        for(int j=i+1; j<divisors.size(); j++){
            //cout << j << endl;
            //cout << divisors[j] << " " << divisors[i] << endl;
            if(divisors[j]%divisors[i]) continue;
            for(auto k : S[i]){
                //cout << k << endl;
                //cout << k+divisors[j]/divisors[i]-1 << endl;
                S[j].insert(k+divisors[j]/divisors[i]-1);
            }
        }
    }
    cout << S[divisors.size()-1].size() << "\n";
    for(auto i : S[divisors.size()-1]){
        cout << i << " ";
    }
    
    return 0;
}