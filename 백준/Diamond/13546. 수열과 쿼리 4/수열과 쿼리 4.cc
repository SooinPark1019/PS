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
//#define sz(x) (int)x.size()
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
//#define int long long

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

deque<int> indexes[100005];
priority_queue<int> curgaps;

int N, sqrtn;
vector<int> A;
struct query{
    int start, end, index;
};
bool compare(query A, query B){
    if(A.start/sqrtn==B.start/sqrtn) return A.end<B.end;
    return A.start/sqrtn < B.start/sqrtn;
}
vector<query> V;
int ans[100005];
int cnt[100005];
void rollback(int a){
    if(indexes[a].size()){
        int gap=indexes[a].back()-indexes[a].front();
        cnt[gap]++;
    }
}
void refresh(int a){
    if(indexes[a].size()){
        int gap=indexes[a].back()-indexes[a].front();
        //cout << "gap : " << gap << "\n";
        curgaps.push(gap);
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    sqrtn=500;

    for(int i=0; i<N; i++){
        int a;
        cin >> a;
        A.push_back(a);
    }

    int Q;
    cin >> Q;

    for(int i=0; i<Q; i++){
        int a, b;
        cin >> a >> b;
        V.push_back({a-1, b-1, i});
    }
    sort(all(V), compare);

    int start=V[0].start;
    int end=V[0].end;
    int index=V[0].index;

    //cout << "start : " << start << " end : " << end << " index : " << index << endl;

    for(int i=start; i<=end; i++){
        int a=A[i];
        //cout << "a : " << a << " i : " << i << "\n";
        rollback(a);
        indexes[a].push_back(i);
        refresh(a);
    }
    //cout << "-----------curgaps\n";
    // for(auto i : curgaps){
    //     cout << i << "\n";
    // }
    //cout << *prev(curgaps.end()) << "\n";
    while(!curgaps.empty()&&cnt[curgaps.top()]){
        cnt[curgaps.top()]--;
        curgaps.pop();
    }
    ans[index]=curgaps.top();

    for(int i=1; i<Q; i++){
        int curs=V[i].start;
        int cure=V[i].end;
        int curi=V[i].index;
        //cout << "start : " << curs << " end : " << cure << " index : " << curi << endl;
        while(start>curs){
            start--;
            int a=A[start];
            rollback(a);
            indexes[a].push_front(start);
            refresh(a);
        }
        while(end<cure){
            end++;
            int a=A[end];
            rollback(a);
            indexes[a].push_back(end);
            refresh(a);
        }
        while(start<curs){
            int a=A[start];
            rollback(a);
            indexes[a].pop_front();
            refresh(a);
            start++;
        }
        while(end>cure){
            int a=A[end];
            rollback(a);
            indexes[a].pop_back();
            refresh(a);
            end--;
        }
        while(!curgaps.empty()&&cnt[curgaps.top()]){
            cnt[curgaps.top()]--;
            curgaps.pop();
        }
        ans[curi]=curgaps.top();
    }

    for(int i=0; i<Q; i++){
        cout << ans[i] << "\n";
    }
    
    return 0;
}
