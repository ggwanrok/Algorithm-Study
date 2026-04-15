#include <iostream>
#include <vector>
using namespace std;
struct Trie {
    bool isTerminal;
    Trie *nxt[26];
    Trie():isTerminal(false){
        for(int i=0; i<26; ++i) nxt[i]=NULL;
    }
    void insert(const char *ch){
        if(*ch=='\0'){
            isTerminal=true;
            return;
        }
        if(nxt[*ch-'0']==NULL){
            nxt[*ch-'0']=new Trie();
        }
        nxt[*ch-'0']->insert(ch+1);
    }
    bool findh(const char *ch){
        if(*(ch+1) == '\0') return false;

        else if(nxt[*ch-'0']->isTerminal == true){
            return true;
        }
        else{
        return nxt[*ch-'0']->findh(ch+1);
        }
    }
};
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    for(int i=0; i<t; ++i){
        Trie *root = new Trie();
        int n; cin>>n;
        vector<string> v;
        for(int j=0; j<n; ++j){
            string str; cin>>str;
            v.push_back(str);
            root->insert(str.c_str());
        }
        int res =0;
        for(int j=0; j<v.size(); ++j){
            if(root->findh(v[j].c_str()))res++;
        }
        if(res == 0) cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';
    }
}