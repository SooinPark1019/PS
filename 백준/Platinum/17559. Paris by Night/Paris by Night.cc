#include <bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define all(v) (v).begin(), (v).end()
#define zip(v) sort(all(v)); v.erase(unique(all(v)), v.end());
#define int long long
#define ll long long

using namespace std;

const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;
const ll LNF = 1e18;
const ll mod = 1e9+7;
const int MAXN = (1<<18)+5;
const double PI = acos(-1);

struct point{
    long long x, y, score;
};
long long ccw(point A, point B, point C){
    long long temp=A.x*B.y+B.x*C.y+C.x*A.y-A.y*B.x-B.y*C.x-C.y*A.x;
    return temp;
}

vector<point> A;
vector<point> V;

int dividepoints(point p){
    if(p.x>0 && p.y==0) return 1;
	else if(p.x>0 && p.y>0) return 2;
	else if(p.x==0 && p.y>0) return 3;
	else if(p.x<0 && p.y>0) return 4;
	else if(p.x<0 && p.y==0) return 5;
	else if(p.x<0 && p.y<0) return 6;
	else if(p.x==0 && p.y<0) return 7;
	else return 8;
}

bool compare(point A, point B){
    A.x-=V[0].x;
    A.y-=V[0].y;
    B.x-=V[0].x;
    B.y-=V[0].y;
    if(dividepoints(A)!=dividepoints(B)){
        return dividepoints(A)<dividepoints(B);
    }
    else{
        int a=ccw({0, 0}, A, B);
        return a>0;
    }
}

signed main(){
    ios::sync_with_stdio(false);    
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    int total=0;
    for(int i=0; i<N; i++){
        int a, b, c;
        cin >> a >> b >> c;
        A.push_back({a, b, c});
        total+=c;
    }

    int ans=total;

    for(int i=0; i<N; i++){
        //cout << i << "\n";
        V=A;
        swap(V[0], V[i]);
        sort(V.begin()+1, V.end(), compare);
        //cout << "V: \n";
        /*for(auto s : V){
            cout << s.x << " " << s.y << " " << s.score << "\n";
        }*/
        int temp=V[0].score;
        int pointer=1;
        for(int j=1; j<V.size(); j++){
            //cout << "j : " << j << "\n";
            while(pointer<N+j&&ccw(V[0], V[j], V[(pointer)%N])>=0){
                //cout << "pointer : " << pointer << "\n";
                if(pointer%N!=0) temp+=V[(pointer)%N].score;
                pointer++;
            }
            //cout << "temp : " << temp << " V[0]l.score : " << V[0].score << " " << V[j].score << "\n";
            ans=min(ans, abs(total-2*temp+V[0].score+V[j].score));
            //cout << ans << "\n";
            temp-=V[j].score;
        }
    }

    cout << ans;

    return 0;
}