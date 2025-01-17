#include <bits/stdc++.h>
#include <ios>
#define int long long
#define all(v) v.begin(), v.end()
#define pii pair<int, int>

using namespace std;

const double PI=acos(-1);

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int angle, N;
    cin >> angle >> N;
    vector<pii> V;
    for(int i=0; i<N; i++){
        int a, b;
        cin >> a >> b;
        V.push_back({a, b});
    }
    sort(all(V));
    double a=(double)1/tan((double)angle/180*PI);
    //cout << a << "\n";
    int curs=V[0].first;
    double cure=curs+a*V[0].second;
    double ans=0;
    for(int i=1; i<N; i++){
        if(cure>=V[i].first){
            cure=max(cure, V[i].first+a*V[i].second);
        }
        else{
            ans+=cure-curs;
            curs=V[i].first;
            cure=curs+a*V[i].second;
        }
    }
    ans+=cure-curs;
    cout << fixed;
    cout.precision(12);
    cout << ans;
}