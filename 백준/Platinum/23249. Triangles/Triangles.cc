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

struct point{
    long long x,y;
};
int ccw(point A, point B, point C){
    long long temp=(B.x-A.x)*(C.y-B.y)-(C.x-B.x)*(B.y-A.y);
    if(temp>0) return 1;
    else if(temp==0) return 0;
    else return -1;
}

vector<point> V;

int dividepoints(point p){
    if(p.x>0 && p.y==0) return 1;
	else if(p.x>0 && p.y>0) return 2;
	else if(p.x==0 && p.y>0) return 3;
	else if(p.x<0 && p.y>0) return 4;
	else if(p.x<0 && p.y==0) return 5;
	else if(p.x<0 && p.y<0) return 6;
	else if(p.x==0 && p.y<0) return 7;
	else return 8;
}

bool compare(point A, point B){
    A.x-=V[0].x;
    A.y-=V[0].y;
    B.x-=V[0].x;
    B.y-=V[0].y;
    if(dividepoints(A)!=dividepoints(B)){
        return dividepoints(A)<dividepoints(B);
    }
    else{
        int a=ccw({0, 0}, A, B);
        return a>0;
    }
}
int N;
int progress(int a){
    if(a==N-1) return 1;
    else return a+1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    vector<point> A;
    for(int i=0; i<N; i++){
        ll x, y;
        cin >> x >> y;
        A.push_back({x, y});
    }
    ll ans=0;
    for(int i=0; i<N; i++){
        V.clear();
        for(int j=0; j<N; j++) V.push_back(A[j]);
        swap(V[0], V[i]);
        sort(V.begin()+1, V.end(), compare);
        //cout << i << " : " << "\n";
        //for(auto p : V) cout << p.x << " " << p.y << "\n";
        //cout << "A : " << V[0].x << " " <<  V[0].y << "\n";
        for(int j=1; j<N; j++){
            int smallestindex=progress(j);
            //cout << "pivot : " << V[j].x << " " << V[j].y << "\n";
            for(int k=progress(smallestindex); k!=j; k=progress(k)){
                //cout << "smallest : " << V[smallestindex].x << " " << V[smallestindex].y << "\n";
                //cout << "next : " << V[k].x << " " << V[k].y << "\n";
                if(ccw(V[0], V[j], V[k])<=0){
                    //cout << "over 180!\n";
                    break;
                }
                //cout << ccw(V[smallestindex], V[j], V[k]) << "\n";
                if(ccw(V[smallestindex], V[j], V[k])>0){
                    //cout << "ans plus!\n";
                    ans++;
                }
                else smallestindex=k;
            }
            //cout << "----------------\n";
        }
        //cout << ans << "\n";
    }
    cout << ans/3;
    return 0;
}