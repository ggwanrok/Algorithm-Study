#include <stdio.h>

int check[100];
int arr[100];
int mon[10001];
int k;
void swap(int* x, int* y) {
	int t = *x;
	*x = *y;
	*y = t;
}

void btk (int j, int n, int m, int i){
  if(j==m){
    for(int a=0;a<j;a++){
        printf("%d ", arr[a]);
    }
    printf("\n");
    }
  else{
    for(int i=1;i<=n;i++){
      
      
        arr[j]=mon[i];
       
        btk(j+1,n,m, i+1);
      
      }
    }
  }
  
int main(){
  int n, m;
  scanf("%d %d", &n, &m);
  for(int i=1;i<=n;i++){
    scanf("%d", &mon[i]);
  }
  for(int i=1;i<=n;i++){
    for(int j=i+1;j<=n;j++){
      if(mon[i]>mon[j]){
        swap(&mon[i], &mon[j]);
      }
    }
  }
  btk(0,n,m, 1);
  return 0;
}