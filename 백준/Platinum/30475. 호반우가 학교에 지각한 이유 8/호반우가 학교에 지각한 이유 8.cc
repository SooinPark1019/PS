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

struct point{
    long long x,y, index;
};
int ccw(point A, point B, point C){
    long long temp=(B.x-A.x)*(C.y-B.y)-(C.x-B.x)*(B.y-A.y);
    if(temp>0) return 1;
    else if(temp==0) return 0;
    else return -1;
}

int dis[300005];
int check[300005];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int TC;
    cin >> TC;
    while(TC--){
        int N, M;
        cin >> N >> M;
        vector<point> under;
        vector<point> upper;

        under.push_back({0, 0});
        upper.push_back({0, 0});

        for(int i=0; i<=N; i++){
            check[i]=0;
            dis[i]=1e18;
        }

        priority_queue<pii, vector<pii>, greater<pii>> aPQ;
        priority_queue<pii, vector<pii>, greater<pii>> bPQ;

        aPQ.push({0, 0});

        for(int i=1; i<=N; i++){
            int x, y, a, b;
            cin >> x >> y >> a >> b;
            point p={x, y, i};
            while(under.size()>=2&&ccw(under[under.size()-2], under[under.size()-1], p)<0){
                /*while(upper.size()>=2&&ccw(upper[upper.size()-2], upper[upper.size()-1], under.back())>0){
                    //cout << "out : " << upper.back().index << "\n";
                    check[upper.back().index]=1;
                    bPQ.push({dis[upper.back().index], upper.back().index});
                    upper.pop_back();
                }
                upper.push_back(under.back());*/
                check[under.back().index]++;
                if(check[under.back().index]==2){
                    bPQ.push({dis[under.back().index], under.back().index});
                }
                under.pop_back();
            }
            under.push_back(p);
            while(upper.size()>=2&&ccw(upper[upper.size()-2], upper[upper.size()-1], under.back())>0){
                //cout << "out : " << upper[upper.size()-2].index << " " << upper.back().index << "\n";
                //cout << upper[upper.size()-2].x << " " << upper[upper.size()-2].y << " " << upper[upper.size()-1].x << " " << upper[upper.size()-1].y << " " << 
                check[upper.back().index]++;
                if(check[upper.back().index]==2){
                    bPQ.push({dis[upper.back().index], upper.back().index});
                }
                upper.pop_back();
            }
            upper.push_back(p);
            //upper.push_back(p);
            /*cout << "under : " << "\n";
            for(auto p : under) cout << p.x << " " << p.y << "\n";

            cout << "upper : " << "\n";
            for(auto p : upper) cout << p.x << " " << p.y << "\n";*/

            while(!aPQ.empty()&&(aPQ.top().second<i-M||check[aPQ.top().second]==2)) aPQ.pop();
            while(!bPQ.empty()&&bPQ.top().second<i-M) bPQ.pop();

            if(!aPQ.empty()){
                //cout << "aPQ : " << aPQ.top().first+a << "\n";
                dis[i]=min(aPQ.top().first+a, dis[i]);
            } 
            if(!bPQ.empty()){
                //cout << "bPQ : " << bPQ.top().first+b << "\n";
                dis[i]=min(bPQ.top().first+b, dis[i]);
            } 
            //cout << "i : " << dis[i] << "\n";
            aPQ.push({dis[i], i});
        }

        cout << dis[N] << "\n";
    }

    return 0;
}
