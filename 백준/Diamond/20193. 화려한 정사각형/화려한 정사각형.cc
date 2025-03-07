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
//#define sz(x) (int)x.size()
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long

using namespace std;

//using namespace __gnu_pbds;
//using namespace __gnu_cxx;
/*#define ordered_set tree<int, null_type, less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>//이걸 코드의 윗부분에 추가
void m_erase(ordered_set &OS, int val){
    int index = OS.order_of_key(val);
    ordered_set::iterator it = OS.find_by_order(index);
    if(*it == val) OS.erase(it);
}*/
//다른 건 통상적인 PBDS처럼 사용하면 되지만 erase는 반드시!!! 이 함수를 통해서만 해야 함
//m_erase(OS, 지울 원소)처럼 사용하면 된다. 꼭 주의하자.
//얘네 쓰려면 define int long long 꺼라.

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
*/

vector<int> seg;

void update(int node, int start, int end, int index, int val){
    if(index<start||end<index) return;
    if(start==end){
        seg[node]=val;
    }
    else{
        int mid=(start+end)>>1;
        update(node*2, start, mid, index, val);
        update(node*2+1, mid+1, end, index, val);
        seg[node]=min(seg[node*2], seg[node*2+1]);
    }
}

int query(int node, int start, int end, int left, int right){
    if(end<left||right<start) return 1e18;
    else if(left<=start&&end<=right) return seg[node];
    else{
        int mid=(start+end)>>1;
        return min(query(node*2, start, mid, left, right), query(node*2+1, mid+1, end, left, right));
    }
}

bool compare(array<int, 3> A, array<int, 3> B){
    return A[1]<B[1];
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    if(K==2){
        vector<pii> color1;
        vector<pii> color2;

        for(int i=0; i<N; i++){
            int x, y, c;
            cin >> x >> y >> c;
            if(c==1) color1.push_back({x, y});
            else color2.push_back({x, y});
        }

        sort(all(color1));
        sort(all(color2));

        int left=0;
        int right=250000;
        int ans=1e18;

        while(left<=right){
            int mid=(left+right)>>1;
            int flag=0;
            set<int> S;
            vector<array<int, 3>> V;
            for(auto p : color2){
                V.push_back({max(0ll, p.first-mid), 1, p.second});
                V.push_back({p.first+mid+1, -1, p.second});
            }
            sort(all(V));
            int curpointer=0;
            for(auto p : color1){
                while(curpointer<V.size()&&V[curpointer][0]<=p.first){
                    if(V[curpointer][1]==1) S.insert(V[curpointer][2]);
                    else S.erase(V[curpointer][2]);
                    curpointer++;
                }
                auto it=S.lower_bound(p.second);
                if(it!=S.begin()){
                    int a=*prev(it);
                    if(abs(a-p.second)<=mid){
                        flag=1;
                        break;
                    }
                }
                if(it!=S.end()){
                    int a=*it;
                    if(abs(a-p.second)<=mid){
                        flag=1;
                        break;
                    }
                }
            }
            if(flag==1){
                ans=min(ans, mid);
                right=mid-1;
            }
            else left=mid+1;
        }

        cout << ans;
        return 0;
    }

    vector<array<int, 3>> V;
    vector<int> X;

    for(int i=0; i<N; i++){
        int x, y, c;
        cin >> x >> y >> c;
        V.push_back({x, y, c});
        X.push_back(x);
    }

    sort(all(V), compare);
    zip(X);

    int left=0;
    int right=250000;
    int ans=250000;
    while(left<=right){
        int mid=(left+right)>>1;
        int flag=0;
        for(auto x : X){
            seg.clear();
            seg.resize(K*4+5);
            for(auto arr : V){
                if(arr[0]<x||x+mid<arr[0]) continue;
                update(1, 1, K, arr[2], arr[1]);
                if(query(1, 1, K, 1, K)>max(0ll, arr[1]-mid-1)){
                    flag=1;
                    break;
                }
            }
            if(flag==1) break;
        }
        if(flag){
            ans=min(ans, mid);
            right=mid-1;
        }
        else{
            left=mid+1;
        }
    }
    cout << ans;

    return 0;
}
