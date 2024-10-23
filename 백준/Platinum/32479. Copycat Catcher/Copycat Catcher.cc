#include <ext/rope>
#include <bits/stdc++.h>
#define _USE_MATH_DEFINES
#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
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

vector<string> r;
vector<vector<int>> p;
map<string, int> M;
int cur=0;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    for(int i=0; i<N; i++){
        string s;
        cin >> s;
        r.push_back(s);
        if(s.size()==1&&'A'<=s[0]&&s[0]<='z') continue;
        M[s]=cur;
        cur++;
    }

    for(int i=0; i<N; i++){
        vector<int> prevpos(60, -1);
        vector<int> temp;
        for(int j=i; j<N; j++){
            if(r[j].size()==1&&'A'<=r[j][0]&&r[j][0]<='z'){
                if(prevpos[r[j][0]-'A']==-1) temp.push_back(-1);
                else{
                    temp.push_back(-(j-prevpos[r[j][0]-'A'])-1);
                }
                prevpos[r[j][0]-'A']=j;
            }
            else{
                temp.push_back(M[r[j]]);
            }
        }
        p.push_back(temp);
    }
    sort(all(p));

    /*for(auto v : p){
        for(auto i : v) cout << i << " ";
        cout << "\n";
    }*/

    int Q;
    cin >> Q;
    //cout << "---------\n";
    while(Q--){
        int a;
        cin >> a;
        vector<string> pattern;
        for(int i=0; i<a; i++){
            string s;
            cin >> s;
            pattern.push_back(s);
        }
        vector<int> temp;
        vector<int> prevpos(60, -1);
        int flag=0;
        for(int i=0; i<a; i++){
            if(pattern[i].size()==1&&'A'<=pattern[i][0]&&pattern[i][0]<='z'){
                if(prevpos[pattern[i][0]-'A']==-1) temp.push_back(-1);
                else{
                    temp.push_back(-(i-prevpos[pattern[i][0]-'A'])-1);
                }
                prevpos[pattern[i][0]-'A']=i;
            }
            else{
                if(M.find(pattern[i])==M.end()){
                    flag=1;
                    break;
                }
                temp.push_back(M[pattern[i]]); 
            }
        }
        //for(auto i : temp) cout << i << " ";
        //cout << "\n";
        if(flag==1){
            cout << "no\n";
            continue;
        }
        int left=0;
        int right=N;
        while(left<=right){
            int mid=(left+right)/2;
            int dif=0;
            /*for(auto i : p[mid]){
                cout << i << " ";
            }
            cout << "\n";*/
            for(int i=0; i<min(temp.size(), p[mid].size()); i++){
                if(p[mid][i]<temp[i]){
                    dif=-1;
                    break;
                }
                else if(p[mid][i]>temp[i]){
                    dif=1;
                    break;
                }
            }
            //cout << dif << "\n";
            if(dif==-1||(dif==0&&temp.size()>p[mid].size())){
                left=mid+1;
            }
            else if(dif==1){
                right=mid-1;
            }
            else{
                flag=1;
                break;
            }
        }
        if(flag==1) cout << "yes\n";
        else cout << "no\n";
    }
    
    return 0;
}