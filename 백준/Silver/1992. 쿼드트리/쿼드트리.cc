#include <iostream>
#include <cstring>

using namespace std;

int n;
string qT[65][65];

string quadTree(int rowIdx, int colIdx, int length){
    if(length > 1){
        string a = quadTree(rowIdx, colIdx, length/2);
        string b = quadTree(rowIdx, colIdx + length/2, length/2);
        string c = quadTree(rowIdx + length/2, colIdx, length/2);
        string d = quadTree(rowIdx+length/2, colIdx+length/2, length/2);

        if(a==b && a==c && a==d && length ==2){
            return a;
        }
        
        else{
            if(a==b && a==c && a==d){
                bool checking = true;
                string check = qT[rowIdx][colIdx];
                for(int i=rowIdx; i<rowIdx+length; i++){
                    for(int j=colIdx; j<colIdx+length; j++){
                        if(check != qT[i][j]){
                            checking = false;
                        }
                    }
                }
                if(checking == true){
                    return a;
                }
            }

            return "("+a+b+c+d+")";
        }
    }
    else{  
        string k = qT[rowIdx][colIdx]; 
        return k;
    }

}

int main(void){
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            char input;
            cin>>input;
            qT[i][j] = input;
        }
    }

    cout<<quadTree(0,0,n);

    return 0;
}