#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
#define int long long
#define ll long long

using namespace std;

//using namespace __gnu_pbds;
//using namespace __gnu_cxx;
//#define ordered_set tree<ll, null_type, less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update>//이걸 코드의 윗부분에 추가
/*void m_erase(ordered_set &OS, ll val){
    ll index = OS.order_of_key(val);
    ordered_set::iterator it = OS.find_by_order(index);
    if(*it == val) OS.erase(it);
}*/
//다른 건 통상적인 PBDS처럼 사용하면 되지만 erase는 반드시!!! 이 함수를 통해서만 해야 함
//m_erase(OS, 지울 원소)처럼 사용하면 된다. 꼭 주의하자.
//얘네 쓰려면 define int long long 꺼라.

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
int num=0;
int ans=0;
void calc(priority_queue<pii, vector<pii>, greater<pii>>& PQ, int finish, int depth){
    for(int i=0; i<finish; i++){
        ans+=PQ.top().first-depth;
        int a=PQ.top().first;
        int b=PQ.top().second;
        PQ.pop();
        if(b){
            PQ.push({a+2, 0});
        }
        else{
            PQ.push({a+1, 0});
            PQ.push({a+1, 0});
        }
    }
}
struct Trie{
    int finish;
    Trie* next[2];
    int depth;
    Trie(): finish(0){
        memset(next, 0, sizeof(next));
        depth=0;
    }
    Trie(int d): finish(0), depth(d){
        memset(next, 0, sizeof(next));
    }
    ~Trie(){
        for(int i=0; i<2; i++){
            if(next[i]) delete next[i];
        }
    }
    void insert(string& key, int pos){
        if(pos==key.length()){
            finish++;
            //cout << "finish : " << finish << "\n";
        }
        else{
            int curr=key[pos]-'0';
            if(next[curr]==NULL){
                next[curr]=new Trie(depth+1);
            }
            next[curr]->insert(key, pos+1);
        }
    }
    priority_queue<pii, vector<pii>, greater<pii>> sol(){
        if(!next[0]&&!next[1]){
            priority_queue<pii, vector<pii>, greater<pii>> PQ;
            PQ.push({depth+2, 0});
            calc(PQ, finish-1, depth);
            return PQ;
        }
        else if(!next[0]){
            priority_queue<pii, vector<pii>, greater<pii>> PQ=next[1]->sol();
            PQ.push({depth+1, 1});
            calc(PQ, finish, depth);
            return PQ;
        }
        else if(!next[1]){
            priority_queue<pii, vector<pii>, greater<pii>> PQ=next[0]->sol();
            PQ.push({depth+1, 1});
            calc(PQ, finish, depth);
            return PQ;
        }
        else{
            priority_queue<pii, vector<pii>, greater<pii>> PQA=next[0]->sol();
            priority_queue<pii, vector<pii>, greater<pii>> PQB=next[1]->sol();
            if(PQA.size()>PQB.size()) swap(PQA, PQB);
            while(!PQA.empty()){
                PQB.push(PQA.top());
                PQA.pop();
            }
            calc(PQB, finish, depth);
            return PQB;
        }
    }
}root;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    for(int i=0; i<N; i++){
        string S;
        cin >> S;
        root.insert(S, 0);
    }
    root.sol();
    cout << ans;

    return 0;
}
