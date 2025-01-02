#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define all(V) V.begin(), V.end()

struct st{
    string S;
    int cnt, index;
};

bool compare(st A, st B){
    if(A.cnt==B.cnt) return A.index>B.index;
    return A.cnt>B.cnt;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    map<string, pii> M;

    int N, K;
    cin >> N >> K;

    cin.ignore();

    for(int i=0; i<3*N; i++){
        string S;
        getline(cin, S);
        //cout << S << "\n";
        M[S].first++;
        M[S].second=i;
    }

    vector<st> V;

    for(auto p : M){
        V.push_back({p.first, p.second.first, p.second.second});
    }

    sort(all(V), compare);

    for(int i=0; i<min(K, (int)V.size()); i++){
        cout << V[i].S << "\n";
    }

    return 0;
}