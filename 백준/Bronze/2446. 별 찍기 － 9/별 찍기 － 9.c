#include <stdio.h>

int main(void) {
  int n;
  scanf("%d", &n);
  int i, j;
  for(i=0;i<n-1;i++){ 
    for(j=0;j<i;j++)printf(" ");
    for(j=0;j<2*n-1-2*i;j++)printf("*");
      printf("\n");
    }
  for(i=0;i<n;i++){
    for(j=n;j>i+1;j--)printf(" ");
    for(j=0;j<2*i+1;j++)printf("*");
    printf("\n");
  }  
     
  
  return 0;
}