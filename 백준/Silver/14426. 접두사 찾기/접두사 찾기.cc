#include <iostream>
using namespace std;
struct Trie{
    Trie *next[26];
    bool isTerminal;
    Trie():isTerminal(false){
        for(int i=0; i<26; ++i){
            next[i] = NULL;
        }
    }
    void insert(const char *ch){
        if(*ch == '\0'){
            isTerminal = true;
            return;
        }
        if(next[*ch-'a'] == NULL){
            next[*ch-'a'] = new Trie();
        }
        next[*ch-'a'] ->insert(ch+1);
    }
    bool findh(const char *ch){
        if(*ch == '\0'){
            return true;
        }
        if(next[*ch-'a'] == NULL){
            return false;
        }
        return next[*ch-'a']->findh(ch+1);
    }
};
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m; cin>>n>>m;
    Trie *root = new Trie();
    for(int i=0; i<n; ++i){
        string str; cin>>str;
        root->insert(str.c_str());
    }
    int res =0;
    for(int i=0; i<m; ++i){
        string str; cin>>str;
        if(root->findh(str.c_str())) res++;
    }
    cout<<res<<'\n';
    return 0;
}