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
const int MAXN = 2e5+5;
const int D = 20;

/*
상태를 어떻게 표현하는 것이 좋을까?
의외로 DP가 아닐 수도 있다는 생각을 하자
모든 공들이 정확하게 K개의 칸으로 이동해야 하는데
*/

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<int> A;
    int Atotalzero=0;
    int Btotalzero=0;
    int Aonecnt=0;
    int Bonecnt=0;
    for(int i=0; i<N; i++){
        int a;
        cin >> a;
        A.push_back(a);
        if(a==1) Aonecnt++;
        else Atotalzero++;
    }
    vector<int> B;
    int M;
    cin >> M;
    for(int i=0; i<M; i++){
        int a;
        cin >> a;
        B.push_back(a);
        if(a==1) Bonecnt++;
        else Btotalzero++;
    }

    vector<int> Azerocnt(N+1, 0);
    vector<int> Bzerocnt(M+1, 0);

    int a=0;
    int b=0;

    Azerocnt[0]=Aonecnt;
    Bzerocnt[0]=Bonecnt;

    for(int i=0; i<N; i++){
        if(A[i]==0) a++;
        else Aonecnt--;
        Azerocnt[a]=max(Azerocnt[a], Aonecnt);
        //cout << a << " " << Azerocnt[a] << "\n";
    }
    for(int i=0; i<M; i++){
        if(B[i]==0) b++;
        else Bonecnt--;
        Bzerocnt[b]=max(Bzerocnt[b], Bonecnt);
        //cout << b << " " << Bzerocnt[b] << "\n";
    }
    int ans=0;
    for(int i=0; i<=min(Atotalzero, Btotalzero); i++){
        ans=max(ans, i+min(Azerocnt[i], Bzerocnt[i]));
    }
    cout << ans;
    
    return 0;
}