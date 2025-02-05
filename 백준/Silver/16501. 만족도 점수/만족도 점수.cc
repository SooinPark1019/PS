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
//#define sz(x) (int)x.size()

using namespace __gnu_cxx;
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

/*
DP[i]=첫번째 재료의 가치가 i일 때 두번째 재료의 가능한 최대 가치

두 차원 모두 양수인 거는 당연히 그대로 합치고
그렇지 않을 경우 취할 차원을 선택

나머지는 취할 차원만 취하거나 아니면 둘다 취해야 함
*/

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int ans=0;

    int arr[8]={};
    for(int i=0; i<8; i++){
        cin >> arr[i];
    }

    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if(i==j) continue;
            for(int k=0; k<8; k++){
                if(k==i||k==j) continue;
                for(int l=0; l<8; l++){
                    if(l==i||l==j||l==k) continue;
                    for(int a=0; a<8; a++){
                        if(a==i||a==j||a==k||a==l) continue;
                        for(int b=0; b<8; b++){
                            if(b==i||b==j||b==k||b==l||b==a) continue;
                            for(int c=0; c<8; c++){
                                if(c==i||c==j||c==k||c==l||c==a||c==b) continue;
                                for(int d=0; d<8; d++){
                                    if(d==i||d==j||d==k||d==l||d==a||d==b||d==c) continue;
                                    int sum1=arr[i]+arr[j];
                                    int sum2=arr[k]+arr[l];
                                    int sum3=arr[a]+arr[b];
                                    int sum4=arr[c]+arr[d];
                                    ans=max(ans, min(100-5*abs(sum1-sum2), 100-5*abs(sum3-sum4)));
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    //cout << ans << "\n";
    if(ans%100==0) cout << ans/100 << ".0";
    else if(ans%10==0) cout << ans/100 << "." << (ans%100)/10;
    else cout << ans/100 << "." << ans%100;

    return 0;
}
