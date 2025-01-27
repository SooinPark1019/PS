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
using namespace __gnu_pbds;
using namespace std;
#define ordered_set tree<int, null_type, less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>//이걸 코드의 윗부분에 추가
void m_erase(ordered_set &OS, int val){
    int index = OS.order_of_key(val);
    auto it = OS.find_by_order(index);
    if(*it == val) OS.erase(it);
}//다른 건 통상적인 PBDS처럼 사용하면 되지만 erase는 반드시!!! 이 함수를 통해서만 해야 함
//m_erase(OS, 지울 원소)처럼 사용하면 된다. 꼭 주의하자.

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
일단 k_max는 그냥 더 많은 쪽에서 두개 빼고 더 적은 쪽에서 한 개 빼는 식으로 해서 구할 수 있다

그 다음 스텝을 생각을 해보면

점들 중에서 차이가 가장 큰 쌍을 우선적으로 제거하고
반대쪽은 가운데 있는 점을 제거하도록 한다
이거는 PBDS를 써야 할 것 같고

그렇게 지워나가다가 한 쪽이 떨어진다면
해당 사이드에서 가장 낮은 점수로 지워졌던 거 하나 롤백 시키고
반대쪽에서 두번 지워준다

이걸 반복하면 될듯
*/
#define int long long
struct st{
    int score;
    int s[2];
    int o;
};
struct comp{
    bool operator()(st A, st B){
        return B.score<A.score;
    }
};

void add_triangle(ordered_set& OS1, ordered_set& OS2, ll& ans, priority_queue<st, vector<st>, comp>& PQ){
    int a=OS1.size();
    int b=OS2.size();
    int x=*OS1.find_by_order(a-1)-*OS1.find_by_order(0);
    int point1, point2, point3;
    point1=*OS1.find_by_order(0);
    point2=*OS1.find_by_order(a-1);
    point3=*OS2.find_by_order(b/2);
    //cout << point1 << " " << point2 << " " << point3 << "\n";
    ans+=x;
    st A;
    A.score=x;
    A.s[0]=point1;
    A.s[1]=point2;
    A.o=point3;
    PQ.push(A);
    OS1.erase(OS1.find_by_order(OS1.order_of_key(point1)));
    OS1.erase(OS1.find_by_order(OS1.order_of_key(point2)));
    OS2.erase(OS2.find_by_order(OS2.order_of_key(point3)));
    return;
}

void sol(ordered_set& OS1, ordered_set& OS2, ll& ans, priority_queue<st, vector<st>, comp>& PQ1, priority_queue<st, vector<st>, comp>& PQ2){
    int a=OS1.size();
    int b=OS2.size();
    //cout << "a : " << a << " b : " << b << "\n";
    if(a>1){
        int x=*OS1.find_by_order(a-1)-*OS1.find_by_order(0);
        int y=*OS2.find_by_order(b-1)-*OS2.find_by_order(0);
        if(x>y){
            add_triangle(OS1, OS2, ans, PQ1);
        }
        else{
            add_triangle(OS2, OS1, ans, PQ2);
        }
    }
    else if(a==1){
        add_triangle(OS2, OS1, ans, PQ2);
    }
    else{
        st A=PQ1.top();
        PQ1.pop();
        ans-=A.score;
        //cout << "A.s[0] : " << A.s[0] << " A.s[1] : " << A.s[1] << " A.o : " << A.o << "\n";
        OS1.insert(A.s[0]);
        OS1.insert(A.s[1]);
        OS2.insert(A.o);
        add_triangle(OS2, OS1, ans, PQ2);
        add_triangle(OS2, OS1, ans, PQ2);
    }
    return;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int TC;
    cin >> TC;
    while(TC--){
        int N, M;
        cin >> N >> M;
        ordered_set OS1;
        ordered_set OS2;
        priority_queue<st, vector<st>, comp> PQ1;
        priority_queue<st, vector<st>, comp> PQ2;

        for(int i=0; i<N; i++){
            int a;
            cin >> a;
            OS1.insert(a);
        }

        for(int i=0; i<M; i++){
            int a;
            cin >> a;
            OS2.insert(a);
        }

        int tempa=N;
        int tempb=M;
        int kmax=0;
        while(tempa>0&&tempb>0){
            if(tempa==1&&tempb==1) break;
            kmax++;
            if(tempa>tempb){
                tempa--;
            }
            else tempb--;
            tempa--;
            tempb--;
        }
        cout << kmax << "\n";
        ll ans=0;
        for(int i=0; i<kmax; i++){
            int a=OS1.size();
            int b=OS2.size();
            if(a>b){
                sol(OS2, OS1, ans, PQ2, PQ1);
            }
            else{
                sol(OS1, OS2, ans, PQ1, PQ2);
            }
            cout << ans << " ";
        }
        cout << "\n";
    }

    return 0;
}
