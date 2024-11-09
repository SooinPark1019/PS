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
#define int long long

using namespace __gnu_cxx;
using namespace std;

typedef long long ll;
//typedef __int128 i128;
typedef long double ld;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;
const ll LNF = 1e18;
const ll mod = 998244353;
const int MAXN = (1<<18)+5;
const int D = 20;

/*
반드시 N은 K의 배수여야 할까?
강한 연결요소라고해서 꼭 그래프가 하나의 사이클로 이루어져야 함을 의미하지는 않는다

한쪽 그래프에서 incoming에서 outgoint으로 향하는 모든 경로의 길이를 보고
다른 쪽에서도 마찬가지
안되는 경우를 생각하는게 맞지 않을까 싶은데
2+a+b가 K의 배수

당연히 0이랑 1의 개수는 맞아야 하고

모든 사이클의 길이를 K로 나누어떨어지게 준 걸 잘 활용을 해야 할 것 같은데
감이 안오네

한쪽에서의 0의 개수와 다른쪽의 1의 개수는 맞아야 한다
모든 원소는 어떤 다른 정점과의 거리가 해당 정점에서 이동하는 거랑 그 정점에서 이동하는 거랑 합치면 항상 K로 나누어 떨어진다

lemma를 하나 세워보자
어떤 두쌍을 골라서 사이클의 길이가 K로 나누어떨어지도록 

어떤 점 하나를 잡자
해당 점으로부터 다른 점들의 사이클에서의 위상을 정할 수 있을 것이다
거리%K해가지고

반대쪽도 마찬가지
그렇게 했을 때 왼쪽에서의 1의 위상과 오른쪽에서의 0의 위상을 합하고 2를 더한게 K로 나누어떨어지도록 나눌 수 있다면 되는게 아닐까?
개수를 세가지고
*/

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, M;
    cin >> N >> M;

    int ans=0;

    stack<pii> S;

    for(int i=0; i<N; i++){
        int a, b;
        cin >> a >> b;
        if(!S.empty()&&S.top().first==a){
            if(S.top().second>b) continue;
            else{
                S.pop();
                S.push({a, b});
            }
        }
        else{
            S.push({a, b});
        }
    }
    vector<pii> V;
    while(!S.empty()){
        V.push_back(S.top());
        S.pop();
    }

    reverse(all(V));

    //for(auto i : V) cout << i.first << " " << i.second << "\n";

    int prev=0;
    for(int i=0; i<V.size(); i++){
        if(V[i].second>0){
            ans+=V[i].second;
            prev=1;
        }
        else if(i>0&&i<N-1&&prev==1){
            if(prev==1&&V[i-1].first==V[i+1].first&&V[i].second+V[i+1].second>0){
                ans+=V[i].second+V[i+1].second;
                i++;
                prev=1;
            }
            else{
                prev=0;
            }
        }
        else{
            prev=0;
        }
    }

    cout << ans;
    
    return 0;
}