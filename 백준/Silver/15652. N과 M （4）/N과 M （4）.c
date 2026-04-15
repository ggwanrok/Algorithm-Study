#include <stdio.h>

int check[100];
int arr[100];

void btk (int j, int n, int m, int i){
  if(j==m){
    for(int a=0;a<j;a++){
        printf("%d ", arr[a]);
    }
    printf("\n");
    }
  else{
    for(;i<=n;i++){
    
        arr[j]=i;
        btk(j+1,n,m, i);
      
      
    }
  }
  }
int main(){
  int n, m;
  scanf("%d %d", &n, &m);
  btk(0,n,m, 1);
  return 0;
}
