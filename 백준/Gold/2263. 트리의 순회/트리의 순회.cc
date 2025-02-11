#include <bits/stdc++.h>

using namespace std;

/*
pre :   본인 - 좌 - 우
in  :   좌 - 본인 - 우
post:   좌 - 우 - 본인
*/

/*
후위순회의 마지막 방문이 바로 루트 노드
중위순회에서, 해당 노드가 탐색된 위치 전이 left, 후가 right 부분에 위치한 노드들이다.
이를 분기로 자르고 자르고 자르면 될듯.
*/


int n;
vector<int> in_order;
vector<int> post_order;

// 중위 순회의 값의 위치를 저장하는 해시맵 (빠른 검색을 위해)
unordered_map<int, int> inorder_map;

// 후위 순회의 인덱스를 관리하는 변수
int postIndex;


struct Node
{
    int value;
    Node *left;
    Node *right;

    Node(int x) : value(x), left(nullptr), right(nullptr) {}
};


void input();
void preorderPrint(Node* root);
Node* buildTree(vector<int>& inorder, vector<int>& postorder);
Node* buildTree(vector<int>& inorder, vector<int>& postorder, int inLeft, int inRight);




int main() {
    input();
    Node* root = buildTree(in_order, post_order);
    preorderPrint(root);
    cout<<'\n';

    return 0;
}

// 트리 빌드 함수
Node* buildTree(vector<int>& inorder, vector<int>& postorder) {
    int n = inorder.size();
    postIndex = n - 1; // 후위 순회의 마지막 요소를 가리키도록 설정

    // 값을 통해서 인덱스를 단번에 알아내기 위한 맵 이용
    for (int i = 0; i < n; i++) {
        inorder_map[inorder[i]] = i;
    }

    return buildTree(inorder, postorder, 0, n - 1);
}

// 트리를 구성하는 재귀 함수
Node* buildTree(vector<int>& inorder, vector<int>& postorder, int inLeft, int inRight) {
    if (inLeft > inRight) return nullptr;

    // 후위 순회의 마지막 원소를 가져와서 노드를 생성
    int rootValue = postorder[postIndex--];
    Node* root = new Node(rootValue);

    // 중위 순회에서 루트의 인덱스 찾기
    int rootIndex = inorder_map[rootValue];

    // 오른쪽 서브트리 먼저 생성 (후위 순회에서 오른쪽이 먼저 나옴)
    root->right = buildTree(inorder, postorder, rootIndex + 1, inRight);
    root->left = buildTree(inorder, postorder, inLeft, rootIndex - 1);

    return root;
}


// 트리 출력 (전위 순회)
void preorderPrint(Node* root) {
    if (!root) return;
    cout << root->value << " ";
    preorderPrint(root->left);
    preorderPrint(root->right);
}

void input(){
    cin>>n;
    for(int i=0; i<n; i++){
        int k; cin>>k;
        in_order.push_back(k);
    }
    for(int i=0; i<n; i++){
        int k; cin>>k;
        post_order.push_back(k);
    }
}