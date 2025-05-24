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
const double EPS = 1e-7;
const ll LNF = 1e18;
const ll mod = 1e9+7;
const int MAXN = (1<<18)+5;
const double PI = acos(-1);

/*
*/
int N;
vector<pair<long double, long double>> V;
long double total_length, total_area;
struct line{
    pair<int, long double> start, end;
};
bool compare_line(line A, line B){
    if(A.start.first==B.start.first) return A.start.second<B.start.second;
    return A.start.first<B.start.first;
}
long double cal_dist(pair<long double, long double> A, pair<long double, long double> B){
    return sqrt((A.first-B.first)*(A.first-B.first)+(A.second-B.second)*(A.second-B.second));
}
pair<long double, long double> calc_exact_point(pair<int, long double> P){
    long double x=V[P.first].first*(1-P.second)+V[(P.first+1)%N].first*P.second;
    long double y=V[P.first].second*(1-P.second)+V[(P.first+1)%N].second*P.second;
    return {x, y};
}
void calc_total_length(){
    for(int i=0; i<N; i++){
        total_length+=cal_dist(V[i], V[(i+1)%N]);
    }
}
long double ccw(pair<long double, long double> A, pair<long double, long double> B, pair<long double, long double> C){
    return A.first*B.second+B.first*C.second+C.first*A.second-A.second*B.first-B.second*C.first-C.second*A.first;
}
long double cal_area(vector<pair<long double, long double>>& V){
    long double ret=0;
    for(int i=0; i<V.size(); i++){
        ret+=V[i].first*V[(i+1)%V.size()].second;
        ret-=V[i].second*V[(i+1)%V.size()].first;
    }
    //cout << "ret : " << ret << "\n";
    return ret;
}
void calc_total_area(){
    total_area=cal_area(V);
}
vector<line> make_segments(){
    long double cur_dis=0;
    int curpointer=0;
    vector<line> ret;
    for(int i=0; i<N; i++){
        while(1){
            long double nxt_dis=cal_dist(V[curpointer], V[(curpointer+1)%N]);
            if(cur_dis+nxt_dis>total_length/2){
                long double exceed=(cur_dis+nxt_dis)-(total_length/2);
                long double inner_split=1-exceed/nxt_dis;
                pair<int, long double> A={i, 0};
                pair<int, long double> B={curpointer, inner_split};
                if(A.first>B.first) swap(A, B);
                ret.push_back({A, B});
                break;
            }
            cur_dis+=nxt_dis;
            curpointer++;
            curpointer%=N;
        }
        cur_dis-=cal_dist(V[i], V[(i+1)%N]);
    }
    sort(all(ret), compare_line);
    return ret;
}
long double calc_segement_area(line L){
    vector<pair<long double, long double>> temp;
    temp.push_back(calc_exact_point(L.start));
    for(int i=L.start.first+1; i<=L.end.first; i++){
        temp.push_back(V[i]);
    }
    temp.push_back(calc_exact_point(L.end));
    //cout << "temp : \n";
    //for(auto i : temp) cout << i.first << " " << i.second << "\n";
    return cal_area(temp);
}
vector<long double> cal_areas(vector<line> segments){
    vector<pair<long double, long double>> temp;
    vector<long double> ret;
    long double cur_area=calc_segement_area(segments[0]);
    ret.push_back(cur_area);
    //cout << "cur_area : " << cur_area << " " << total_area << endl;
    for(int i=1; i<segments.size(); i++){
        cur_area+=ccw(calc_exact_point(segments[i-1].start), calc_exact_point(segments[i].end), calc_exact_point(segments[i].start));
        cur_area-=ccw(calc_exact_point(segments[i-1].start) ,calc_exact_point(segments[i].end), calc_exact_point(segments[i-1].end));
        ret.push_back(cur_area);
    }
    return ret;
}
int find_point(vector<long double>& areas){
    for(int i=0; i<areas.size()-1; i++){
        if((areas[i]-total_area/2)*(areas[i+1]-total_area/2)<=0){
            return i;
        }
    }
    return areas.size()-1;
}
void sol(vector<long double>& areas, vector<line>& segments){
    int flag=0;
    int critical_point=find_point(areas);
    //cout << "critical_point : " << critical_point << endl;
    if(critical_point<0){
        assert(0);
        cout << "NO";
        return;
    }
    long double left=segments[critical_point].start.second;
    long double right=segments[(critical_point+1)%segments.size()].start.second;
    int index=segments[critical_point].start.first;
    //cout << "left : " << left << " " << " right : " << right << " index : " << index << "\n";
    pair<int, long double> secondpoint;
    long double ans;
    if(right<=left) right=1;
    for(int i=0; i<100; i++){
        long double mid=(left+right)/2;
        //cout << "mid : " << mid << "\n";
        ans=mid;
        long double cur_length=0;
        int cur_pointer=index;
        vector<pair<long double, long double>> polygon;
        polygon.push_back(calc_exact_point({index, mid}));
        cur_length+=cal_dist(V[index], V[(index+1)%N])*(1-mid);
        cur_pointer++;
        polygon.push_back(calc_exact_point({index+1, 0}));
        //cout << "cur_length : " << cur_length << "\n";
        while(1){
            long double nxt_dis=cal_dist(V[cur_pointer], V[(cur_pointer+1)%N]);
            if(cur_length+nxt_dis>total_length/2){
                long double exceed=(cur_length+nxt_dis)-(total_length/2);
                long double inner_split=1-exceed/nxt_dis;
                secondpoint={cur_pointer, inner_split};
                polygon.push_back(calc_exact_point(secondpoint));
                break;
            }
            cur_length+=nxt_dis;
            cur_pointer++;
            cur_pointer%=N;
            polygon.push_back({calc_exact_point({cur_pointer, 0})});
            //cout << "cur_length : " << cur_length << "\n";
        }
        //cout << "polygon : \n";
        //for(auto p : polygon){
            //cout << p.first << " " << p.second << "\n";
        //}
        long double curarea=cal_area(polygon);
        //cout << "curarea : " << curarea << "\n";
        if(critical_point==areas.size()-1){
            if(areas[critical_point]<areas[(critical_point+1)%areas.size()]){
                if(curarea>total_area/2) left=mid;
                else right=mid;
            }
            else{
                if(curarea>total_area/2) right=mid;
                else left=mid;
            }
        }
        else{
            if(areas[critical_point]<areas[(critical_point+1)%areas.size()]){
                if(curarea>total_area/2) right=mid;
                else left=mid;
            }
            else{
                if(curarea>total_area/2) left=mid;
                else right=mid;
            }
        }
    }
    cout << "YES\n";
    cout << fixed;
    cout.precision(12);
    cout << index+1 << " " << ans << "\n";
    cout << secondpoint.first+1 << " " << secondpoint.second << "\n";
}   
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    
    for(int i=0; i<N; i++){
        int a, b;
        cin >> a >> b;
        V.push_back({a, b});
    }

    calc_total_area();
    calc_total_length();

    //cout << "total_area : " << total_area << "\n";

    vector<line> segments=make_segments();
    //cout << "segments : \n";
    //for(auto l : segments){
        //cout << "start : " << l.start.first << " " << l.start.second << "\n";
        //cout << "end : " << l.end.first << " " << l.end.second << "\n";
    //}
    //cout << endl;
    vector<long double> areas=cal_areas(segments);

    //cout << "areas : \n";
    //for(auto i : areas) cout << i << " ";
    //cout << endl;

    sol(areas, segments);
}