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
vector<int> lazy;

void lazyupdate(int node, int start, int end){
    if(lazy[node]!=0){
        seg[node]+=lazy[node];
        if(start!=end){
            lazy[node*2]+=lazy[node];
            lazy[node*2+1]+=lazy[node];
        }
        lazy[node]=0;
    }
}

void update(int node, int start, int end, int left, int right, int value){
    lazyupdate(node, start, end);
    if(right<start||end<left) return;
    else if(left<=start&&end<=right){
        lazy[node]+=value;
        lazyupdate(node, start, end);
    }
    else{
        int mid=(start+end)>>1;
        update(node*2, start, mid, left, right, value);
        update(node*2+1, mid+1, end, left, right, value);
        seg[node]=max(seg[node*2], seg[node*2+1]);
    }
}

int query(int node, int start, int end, int left, int right){
    lazyupdate(node, start, end);
    if(right<start||end<left) return 0;
    else if(left<=start&&end<=right){
        return seg[node];
    }
    else{
        int mid=(start+end)>>1;
        return max(query(node*2, start, mid, left, right), query(node*2+1, mid+1, end, left, right));
    }
}

multiset<int> intervalstarts[100005];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;
    vector<array<int, 3>> V;
    for(int i=0; i<N; i++){
        int a, b, c;
        cin >> a >> b >> c;
        V.push_back({a, b, c});
    }
    sort(all(V));
    int left=0;
    int right=250000;
    int ans=250000;
    while(left<=right){
        int mid=(left+right)>>1;
        //cout << "mid : " << mid << endl;
        for(int i=1; i<=K; i++){
            intervalstarts[i].clear();
        }
        seg.clear();
        lazy.clear();
        seg.resize(250005*4);
        lazy.resize(250005*4);

        vector<array<int, 4>> queries;

        for(auto a : V){
            queries.push_back({a[0], 1, a[1], a[2]});
            queries.push_back({a[0]+mid+1, -1, a[1], a[2]});
        }

        sort(all(queries));

        int flag=0;
        int curpointer=0;
        for(int i=1; i<=250000; i++){
            while(curpointer<queries.size()&&queries[curpointer][0]==i){
                int type=queries[curpointer][1];
                int start=queries[curpointer][2];
                int end=queries[curpointer][2]+mid;
                int color=queries[curpointer][3];
                //cout << "x : " << queries[curpointer][0] << " type : " << type << " start : " << start << " end : " << end << " color " << color << "\n";
                if(type==-1){
                    intervalstarts[color].erase(intervalstarts[color].find(start));
                }
                auto it=intervalstarts[color].lower_bound(start);
                int start2=start;
                int end2=end;
                if(it!=intervalstarts[color].begin()){
                    auto it2=prev(it);
                    start2=max(start2, *it2+mid+1);
                }
                if(it!=intervalstarts[color].end()){
                    int a=*it;
                    end2=min(end2, a-1);
                }
                //cout << start2 << " " << end2 << "\n";
                if(start2<=end2) update(1, 1, 250000, start2, end2, type);
                if(type==1){
                    intervalstarts[color].insert(start);
                }
                curpointer++;
            }
            //if(mid==5&&i<10) cout << "query : " << query(1, 1, 250000, 1, 250000) << " " << query(1, 1, 250000, 8, 8) << "\n";
            if(query(1, 1, 250000, 1, 250000)==K){
                flag=1;
                break;
            }
        }
        if(flag){
            right=mid-1;
            ans=min(ans, mid);
        }
        else{
            left=mid+1;
        }
    }

    cout << ans;

    return 0;
}
