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
일단 좌표압축을 해
이분탐색으로 y좌표를 찾는다?
그렇게 한다면 이분탐색의 기준을 잘 정해야 할 것 같은데
현재 x에 대해서 최댓값이 위에 있는 두 사분면 중 하나인 경우 중 y좌표가 최대인 경우
해당 y좌표와 바로 아래 y좌표를 각각 탐색
*/

vector<int> leftseg;
vector<int> rightseg;

void update_seg(int node, int start, int end, int index, long long diff, vector<int>& seg){
    if(index<start||index>end) return;
    if(start==end){
        seg[node]+=diff;
    }
    else{
        int mid=(start+end)/2;
        update_seg(node*2, start, mid, index, diff, seg);
        update_seg(node*2+1, mid+1, end, index, diff, seg);
        seg[node]=seg[node*2]+seg[node*2+1];
    }
    return;
}

int sum_seg(int node, int start, int end, int left, int right, vector<int>& seg){
    if(left>end||right<start) return 0;
    if(left<=start&&end<=right) return seg[node];
    int mid=(start+end)/2;
    return sum_seg(node*2, start, mid, left, right, seg)+sum_seg(node*2+1, mid+1, end, left, right, seg);
}

int N, upleft, upright, downleft, downright;

void calxs(int mid){
    upleft=sum_seg(1, 0, N, mid, N, leftseg);
    downleft=sum_seg(1, 0, N, 0, mid-1, leftseg);
    upright=sum_seg(1, 0, N, mid, N, rightseg);
    downright=sum_seg(1, 0, N, 0, mid-1, rightseg);
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

        cin >> N;
        leftseg.clear();
        rightseg.clear();
        leftseg.resize(4*N+5, 0);
        rightseg.resize(4*N+5, 0);
        vector<pii> V;
        vector<int> X;
        vector<int> Y;
        for(int i=0; i<N; i++){
            int a, b;
            cin >> a >> b;
            V.push_back({a, b});
            X.push_back(a);
            Y.push_back(b);
        }
        sort(all(V));
        zip(X);
        zip(Y);
        map<int, int> dictx;
        map<int, int> dicty;
        for(int i=0; i<X.size(); i++){
            dictx[X[i]]=i;
        }
        for(int i=0; i<Y.size(); i++){
            dicty[Y[i]]=i;
        }
        for(int i=0; i<N; i++){
            update_seg(1, 0, N, dicty[V[i].second], 1, rightseg);
        }
        int maxsz=1e18;
        //int ansx=0, ansy=0;
        int curpointer=0;
        //cout << ansx << " " << ansy << endl;
        for(int i=0; i<=X.size(); i++){
            while(curpointer<N&&dictx[V[curpointer].first]<i){
                update_seg(1, 0, N, dicty[V[curpointer].second], -1, rightseg);
                update_seg(1, 0, N, dicty[V[curpointer].second], 1, leftseg);
                curpointer++;
            }
            int left=0;
            int right=Y.size()-1;
            int ans=0;
            while(left<=right){
                int mid=(left+right)>>1;
                calxs(mid);
                if(max({upleft, upright, downleft, downright})==max(upleft, upright)){
                    ans=max(ans, mid);
                    left=mid+1;
                }
                else{
                    right=mid-1;
                }
            }
            calxs(ans);
            if(max({upleft, upright, downleft, downright})<maxsz){
                maxsz=max({upleft, upright, downleft, downright});
                //ansx=i;
                //ansy=ans;
            }
            ans++;
            calxs(ans);
            if(max({upleft, upright, downleft, downright})<maxsz){
                maxsz=max({upleft, upright, downleft, downright});
                //ansx=i;
                //ansy=ans;
            }
        }
        cout << maxsz;
    return 0;
}
