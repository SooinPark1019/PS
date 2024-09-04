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

using namespace __gnu_cxx;
using namespace std;

typedef long long ll;
//typedef __int128 i128;
typedef long double ld;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;
const ll LNF = 1e18;
const ll mod = 998244353;
const ll MAX = 100000;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> A;
    vector<int> B(N, -1);
    vector<int> cnt(N, 0);

    for(int i=0; i<N; i++){
        A.push_back(i);
    }
    for(int i=N-1; i>=0; i--){
        if(B[i]!=-1) continue;
        int a=0, temp=i;
        while(temp>0){
            a++;
            temp>>=1;
        }
        ll b=1<<a;
        b--;
        //cout << b << endl;
        B[i]=(b^i);
        B[b^i]=i;
    }
    vector<int> ans;
    vector<int> ans2;
    cout << "? ";
    for(auto i : A) cout << i << " ";
    cout << endl;
    for(int i=0; i<N; i++){
        int a;
        cin >> a;
        ans.push_back(a);
    }
    cout << "? ";
    for(auto i : B) cout << i << " ";
    cout << endl;
    for(int i=0; i<N; i++){
        int a;
        cin >> a;
        ans2.push_back(a);
    }
    cout << "! ";
    for(int i=0; i<N; i++) cout <<(ans[i]&ans2[i]) << " ";
    cout << endl;
    cout << endl;
}
