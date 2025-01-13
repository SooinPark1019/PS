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
#define int long long
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
const int mod = 1e9+7;
const int mod2 = 998244353;
const int MAXN = (1<<18)+5;
const double PI = acos(-1);

/*
인접한 두 수가 서로소 -> 자명하게 추가할 필요가 없다
*/

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, M;
    cin >> N >> M;

    vector<int> A;
    vector<int> B;
    for(int i=0; i<N; i++){
        int a;
        cin >> a;
        A.push_back(a);
    }
    for(int i=0; i<N; i++){
        int a;
        cin >> a;
        B.push_back(a);
    }

    int left=0;
    int right=1e18;
    int ans=0;
    while(left<=right){
        int mid=(left+right)>>1;
        int totalcnt=0;
        for(int i=0; i<N; i++){
            if(A[i]>B[i]){
                assert(A[i]*M>=0);
                if(A[i]*M>=mid){
                    totalcnt+=mid/A[i];
                    if(mid%A[i]) totalcnt++;
                }
                else{
                    totalcnt+=M;
                    int temp=mid-A[i]*M;
                    totalcnt+=temp/B[i];
                    if(temp%B[i]) totalcnt++;
                }
            }
            else{
                totalcnt+=mid/B[i];
                if(mid%B[i]) totalcnt++;
            }
            if(totalcnt>N*M){
                break;
            }
        }
        assert(totalcnt>=0);
        if(totalcnt<=N*M){
            ans=max(ans, mid);
            left=mid+1;
        }
        else right=mid-1;
    }

    cout << ans;
    
    return 0;
}
