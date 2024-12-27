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
const ll mod = 10007;
const int MAXN = (1<<18)+5;
const double PI = acos(-1);

/*

*/
struct myst{
    int a, b;
    double c;
};
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, X;
    double V;
    cin >> N >> X >> V;


    double left=1;
    double right=2;
    double ans=1e18;

    vector<myst> A;

    for(int i=0; i<N; i++){
        int a, b;
        double c;
        cin >> a >> b >> c;
        A.push_back({a, b, c});
    }

    while(left<=right){
        double mid=(left+right)/2;
        //cout << "mid : " << mid << "\n";
        double total=0;
        for(int i=0; i<N; i++){
            int a=A[i].a;
            int b=A[i].b;
            double c=A[i].c;
            total+=(double)(b-a)*mid/V*c;
            //cout << (double)(b-a)*mid/V*c << "\n";
        }
        double dist=sqrt((X*X)+(total*total));
        if(dist<X*mid){
            right=mid-EPS;
            ans=min(ans, mid);
        }
        else{
            left=mid+EPS;
        }
    }
    if(ans>2) cout << "Too hard";
    else{
        cout << fixed;
        cout.precision(3);
        cout << ans*X/V;
    }
    return 0;
}
