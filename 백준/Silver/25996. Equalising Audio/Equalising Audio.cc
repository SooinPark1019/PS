#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define all(v) v.begin(), v.end()

using namespace std;

signed main(){
    int N, X;
    cin >> N >> X;
    vector<int> V;
    int squaretotal=0;
    for(int i=0; i<N; i++){
        int a;
        cin >> a;
        V.push_back(a);
        squaretotal+=a*a;
    }
    if(squaretotal==0){
        for(int i=0; i<N; i++){
            cout << V[i] << " ";
        }
        return 0;
    }
    double factor=sqrt((double)N*X/squaretotal);
    cout << fixed;
    cout.precision(12);
    for(int i=0; i<N; i++){
        cout << (double)V[i]*factor << " ";
    }
}