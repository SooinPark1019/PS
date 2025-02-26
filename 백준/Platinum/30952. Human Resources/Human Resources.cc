#include <bits/stdc++.h>
#include <string>
#define int long long
#define all(v) v.begin(), v.end()
#define pii pair<int, int>

using namespace std;

map<string, vector<string>> graph;
map<string, string> p;

void dfs(string node, string par, vector<string>& ret){
    //cout << "node : " << node << "\n";
    ret.push_back(node);
    for(auto& s : graph[node]){
        if(s==par) continue;
        dfs(s, node, ret);
    }
    return;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    string S;
    cin >> S;
    if(S=="ENCODE"){
        cin.ignore();
        string total;
        string root="";
        while(getline(cin, total)){
            //cout << total << endl;
            string node="";
            string temp="";
            int appearedcolone=0;
            for(auto c : total){
                if(c==':'){
                    appearedcolone=1;
                }
                else if(c==' '){
                    if(temp!=""){
                        graph[node].push_back(temp);
                        p[temp]=node;
                    }
                    temp="";
                }
                else{
                    if(appearedcolone) temp+=c;
                    else node+=c;
                }
                //cout << "temp : " << temp << endl;
            }
            p[temp]=node;
            graph[node].push_back(temp);
            //cout << "node : " << node << endl;
            //for(auto i : graph[node]) cout << i << " ";
            //cout << endl;
            if(root=="") root=node;
        }
        vector<string> ret;
        dfs(root, "", ret);
        string cur=root;
        string ans="";
        for(auto s : ret){
            if(s==root) continue;
            //cout << "s :" << s << " cur : " << cur << endl;
            while(cur!=root&&cur!=p[s]){
                ans+='1';
                cur=p[cur];
            }
            ans+='0';
            cur=s;
        }
        for(auto s : ret) cout << s << "\n";
        cout << ans;
    }
    else{
        vector<string> ret;
        string S;
        while(cin >> S){
            ret.push_back(S);
        }
        string move=ret.back();
        ret.pop_back();

        map<string, vector<string>> graph;
        map<string, string> par;
        string cur=ret[0];
        int curindex=0;
        for(int i=1; i<ret.size(); i++){
            string s=ret[i];
            //cout << "s : " << s << " cur : " << cur << "\n";
            while(curindex<move.size()&&move[curindex]=='1'){
                cur=par[cur];
                curindex++;
            }
            //cout << "cur : " << cur << "\n";
            graph[cur].push_back(s);
            par[s]=cur;
            cur=s;
            curindex++;
        }
        for(auto s : ret){
            if(graph[s].size()==0) continue;
            cout << s << ": ";
            for(int j=0; j<graph[s].size(); j++){
                cout << graph[s][j];
                if(j!=graph[s].size()-1) cout << " ";
            }
            cout << "\n";
        }
    }
}