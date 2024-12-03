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
const ll mod = 998244353;
const int MAXN = (1<<18)+5;
const double PI = acos(-1);

/*
바꾸는 쿼리가 없다고 생각을 해보자

어떤 l, r이 주어졌을 때
최댓값을 어떻게 찾을까?
하나의 연속합형태로 나타난다면
양 끝의 b와 내부에서 붙어있는 b 두개

금광+최댓값 세그로 할 수 있는데
문제는 하나의 연속합 형태로 나타나지 않는 경우

*/

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, Q;
    cin >> N >> Q;
    vector<int> res(N);
    vector<int> V;
    for(int i=0; i<N; i++){
        int a;
        cin >> a;
        V.push_back(a);
    }
    vector<int> interval;
    for(int i=0; i<N-1; i++){
        interval.push_back(V[i+1]-V[i]);
    }
    vector<pii> wind;
    int cur=0;
    int leftest=0;
    int rightest=0;
    for(int i=0; i<Q; i++){
        int a;
        cin >> a;
        cur+=a;
        if(cur<leftest){
            leftest=cur;
            wind.push_back({leftest, rightest});
        }
        if(cur>rightest){
            rightest=cur;
            wind.push_back({leftest, rightest});
        }
    }
    //for(auto p : wind) cout << p.first << " " << p.second << "\n";
    for(int i=0; i<N-1; i++){
        //cout << "interval : " << interval[i] << "\n";
        int left=0;
        int right=wind.size()-1;
        int ans=-1;
        while(left<=right){
            int mid=(left+right)>>1;
            if(-wind[mid].first+wind[mid].second<=interval[i]){
                ans=max(ans, mid);
                left=mid+1;
            }
            else right=mid-1;
        }
        //cout << "ans : " << ans << "\n";
        if(ans!=-1){
            res[i]+=wind[ans].second;
            res[i+1]+=abs(wind[ans].first);
        }
        //cout << "res : " << res[i] << " " << res[i+1] << "\n";
        if(ans!=wind.size()-1){
            if(ans==-1){
                if(wind[ans+1].first<0){
                    int a=min(interval[i], abs(wind[ans+1].first));
                    res[i+1]+=a;
                }
                else{
                    int a=min(interval[i], abs(wind[ans+1].second));
                    res[i]+=a;
                }
            }
            else{
                if(wind[ans].first!=wind[ans+1].first){
                    int a=min(interval[i]+wind[ans].first-wind[ans].second, abs(wind[ans].first-wind[ans+1].first));
                    res[i+1]+=a;
                }
                else{
                    int a=min(interval[i]+wind[ans].first-wind[ans].second, abs(wind[ans].second-wind[ans+1].second));
                    res[i]+=a;
                }
            }
        }
        //out << "res : " << res[i] << " " << res[i+1] << "\n";
    }
    if(wind.size()>0){
        res[0]+=abs(wind.back().first);
        res[N-1]+=abs(wind.back().second);
    }
    for(int i=0; i<N; i++) cout << res[i] << "\n";
    return 0;
}

