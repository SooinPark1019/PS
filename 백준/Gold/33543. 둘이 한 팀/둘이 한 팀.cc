#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define all(v) v.begin(), v.end()

using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;
    vector<int> A;
    vector<int> B;
    int asum=0;
    int bsum=0;
    vector<int> V;
    int addA=0;
    for(int i=0; i<N; i++){
        int a, b;
        cin >> a >> b;
        asum+=a;
        bsum+=a;
        A.push_back(a);
        B.push_back(b);
        V.push_back(b-a);
    }
    sort(all(V));
    vector<int> prefix;
    for(int i=0; i<N; i++){
        int a=V[i];
        if(prefix.size()>0) a+=prefix.back();
        prefix.push_back(a);
    }
    //for(auto i : V) cout << i << " ";
    //cout << "\n";
    int Q;
    cin >> Q;
    while(Q--){
        char c;
        int a;
        cin >> c >> a;
        if(c=='A'){
            addA+=a;
            asum+=a*N;
        }
        else addA-=a;
        auto it=lower_bound(all(V), addA);
        int cnt=N-(it-V.begin());//addA보다 큰 애들의 개수
        int index=it-V.begin()-1;//작은 애들의 누적합
        int sum=prefix.back();
        if(index>=0) sum-=prefix[index];//큰 애들의 누적합
        //cout << sum << " " << cnt << "\n";
        sum-=addA*cnt;
        cout << asum+sum << "\n";
    }
}