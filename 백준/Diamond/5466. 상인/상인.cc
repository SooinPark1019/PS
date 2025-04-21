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
int N, U, D, S;
int segU[2020202];
int segD[2020202];
int cost[500001];
void update(int node, int start, int end, int index, int value, int seg[2020202], int type){
    if(index<start||end<index) return;
    if(start==end){
        if(type==1) seg[node]=max(seg[node], value-start*U);
        else seg[node]=max(seg[node], value-(500001-start)*D);
    }
    else{
        int mid=(start+end)>>1;
        update(node*2, start, mid, index, value, seg, type);
        update(node*2+1, mid+1, end, index, value, seg, type);
        seg[node]=max(seg[node*2], seg[node*2+1]);
    }
}
int query(int node, int start, int end, int left, int right, int seg[2020202]){
    if(end<left||right<start) return -1e18;
    if(left<=start&&end<=right) return seg[node];
    int mid=(start+end)>>1;
    return max(query(node*2, start, mid, left, right, seg), query(node*2+1, mid+1, end, left, right, seg));
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> U >> D >> S;

    for(int i=0; i<2020202; i++){
        segU[i]=-1e18;
        segD[i]=-1e18;
    }

    update(1, 0, 500001, S, 0, segU, 1);
    update(1, 0, 500001, S, 0, segD, 2);

    vector<array<int, 3>> V;

    for(int i=0; i<N; i++){
        int a, b, c;
        cin >> a >> b >> c;
        V.push_back({a, b, c});
    }

    sort(all(V));

    int curpointer=0;
    for(int i=1; i<=500000; i++){
        vector<array<int, 3>> temp;
        while(curpointer<N&&i==V[curpointer][0]){
            temp.push_back(V[curpointer]);
            curpointer++;
        }
        if(temp.size()==0) continue;
        for(auto arr : temp){
            int curpos=arr[1];
            int x=query(1, 0, 500001, 0, curpos, segD)+(500001-curpos)*D;
            int y=query(1, 0, 500001, curpos, 500001, segU)+curpos*U;
            cost[curpos]=max(x, y);
            //cout << "curpos : " << curpos << " cost[curpos] : " << cost[curpos] << "\n";
        }
        int curprofit=-1e18;
        for(int j=0; j<temp.size(); j++){
            if(j>0){
                curprofit-=D*abs(temp[j-1][1]-temp[j][1]);
            }
            curprofit=max(curprofit+temp[j][2], cost[temp[j][1]]+temp[j][2]);
            //cout << "curprofit : " << curprofit << "\n";
            update(1, 0, 500001, temp[j][1], curprofit, segU, 1);
            update(1, 0, 500001, temp[j][1], curprofit, segD, 2);
        }
        curprofit=-1e18;
        for(int j=temp.size()-1; j>=0; j--){
            if(j<temp.size()-1){
                curprofit-=U*abs(temp[j+1][1]-temp[j][1]);
            }
            curprofit=max(curprofit+temp[j][2], cost[temp[j][1]]+temp[j][2]);
            //cout << "curprofit : " << curprofit << "\n";
            update(1, 0, 500001, temp[j][1], curprofit, segU, 1);
            update(1, 0, 500001, temp[j][1], curprofit, segD, 2);
        }
    }

    cout << max({0ll, query(1, 0, 500001, 0, S, segD)+(500001-S)*D, query(1, 0, 500001, S, 500001, segU)+S*U});
    
    return 0;
}
