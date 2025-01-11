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
X 이상의 H에 대해서 해당 값을 중앙 값으로 하는 구간의 개수를 센다고 생각하자
왼쪽에 x개, 오른쪽에 y개가 있다면
왼쪽거를 오른쪽거보다 1개 더 많이 뽑을 수 있다
일단 같게 뽑는 거는 min(x+1, y+1)고
오른쪽을 하나 더 뽑는거는
아 잠만 여기서 이항계수를 써야 하는구나

다시 처음부터 가보자

어떤 구간안에서 적어도 해당 구간의 크기/2만큼 X 이상인게 들어있어야 한다
그러면 어떠한 누적합을 생각해볼 수 있지 않을까?

어떤 위치에 대하여 처음부터 해당 위치까지의 부분 배열 중에서 이상인거-미만인거의 개수를 전처리 해주자
그러고 나서 각 위치에 대해서 펜윅느낌으로 보면 될 거 같다
*/

vector<int> Fenwick(200005, 0);

void update(int index, long long value){
    while(index<=200001){
        Fenwick[index]+=value;
        index+=index&(-index);
    }
    return;
}
long long sum(int index){
    long long ret=0;
    while(index>0){
        ret+=Fenwick[index];
        index-=index&(-index);
    }
    return ret;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, X;
    cin >> N >> X;

    int cur=0;
    int ans=0;
    update(100001, 1);
    for(int i=0; i<N; i++){
        int a;
        cin >> a;
        if(a>=X){
            cur++;
        }
        else cur--;
        //cout << cur << " ";
        ans+=sum(cur+100001);
        //cout << sum(cur+100001);
        update(cur+100001, 1);
    }

    cout << ans;

    return 0;
}
