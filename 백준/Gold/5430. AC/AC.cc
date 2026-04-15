#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int tc;
    cin>>tc;
    while(tc--){
        int reverse_flag = 1; //1이면 그냥, 0이면 리버스
        string code;
        cin>>code;
        int code_size;
        cin>>code_size;
        string input;
        deque<int> input_deque;
        cin>>input;
        int num = 0;
        for(int i=0; i<input.length(); i++){
            if(input[i] >= '0' && input[i] <= '9'){
                num = num * 10 + input[i] - '0';
            }
            else{
                if(num != 0){
                    input_deque.push_back(num);
                    num = 0;
                }
            }
        }
        int error_flag = 0;
        for(int i=0; i<code.length(); i++){
            if(code[i] == 'R'){
                reverse_flag = (reverse_flag + 1) % 2;
            }
            else if(code[i] == 'D'){
                if(input_deque.size() == 0){
                    error_flag = -1;
                    break;
                }
                else{
                    if(reverse_flag == 1){
                        input_deque.pop_front();
                    }
                    else{
                        input_deque.pop_back();
                    }
                }
            }

            if(error_flag == -1) break;
        }

        if(error_flag == -1){
            cout<<"error"<<'\n';
        }
        else{
            cout<<'[';
            if(input_deque.empty()) {
                cout<<']'<<'\n';
                continue;
            }
            while(!input_deque.empty()){
                int k;
                if(reverse_flag == 1){
                    k = input_deque.front();
                    input_deque.pop_front();
                }
                if(reverse_flag == 0){
                    k = input_deque.back();
                    input_deque.pop_back();
                }
                
                cout<<k;
                if(input_deque.empty()){
                    cout<<']'<<'\n';
                }
                else{
                    cout<<',';
                }
            }
        }
    }
    return 0;
}