#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int n;
int root;
int indexInfo;
vector<int> nodeVector[10001];
int maxLevel;

struct Node{
    int parent;
    int level;
    int left;
    int right;
    bool visited;
};

void cleanNode(Node* array){
    for(int i=1; i<=n; i++){
        array[i].left = -1;
        array[i].right = -1;
        array[i].visited = false;
        array[i].parent = -1;
    }
}
void findMaxLevel(Node* array){
    for(int i=1; i<=n; i++){
        maxLevel = (maxLevel > array[i].level) ? maxLevel : array[i].level;
    }
}

void findLeftNode(Node* tree, int idx, int depth){
    if(tree[tree[idx].left].visited == false && tree[idx].left != -1){
        findLeftNode(tree, tree[idx].left, depth+1);
    }
    tree[idx].level = depth;
    nodeVector[tree[idx].level].push_back(indexInfo);
    tree[idx].visited = true;
    indexInfo++;

    if(tree[tree[idx].right].visited == false && tree[idx].right != -1){
        findLeftNode(tree, tree[idx].right, depth+1);
    }
    
}


int main(void){
    cin>>n;
    Node tree[n+1];
    cleanNode(tree);
    
    for(int i=0; i<n;i++){
        int head, le, ri;
        cin>>head>>le>>ri;
        tree[head].left = le;
        tree[head].right = ri;
        tree[le].parent = head;
        tree[ri].parent = head;
    } 
    for(int i=1; i<=n; i++){
        if(tree[i].parent == -1){
            root = i;
        }
    }
    indexInfo = 1;
    tree[root].level = 1;
    findLeftNode(tree, root, tree[root].level);
    findMaxLevel(tree);
    //여기까지해서 수행하는 알고리즘 종료.

    //여기부터 조건따져 출력문 내용 정하기.
    int maxDepth, maxValue;
    maxDepth = maxValue = 0;
    for(int i=1; i<=maxLevel; i++){
        int value;
        int start, end;
        start = nodeVector[i][0];
        end = nodeVector[i][nodeVector[i].size()-1];
        value = end-start+1;
        
        if(value > maxValue){
            maxValue = value;
            maxDepth = i;
        }
    }

    cout<<maxDepth<<" "<<maxValue<<'\n';


    return 0;
}