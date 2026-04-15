#include <stdio.h>

int main(void) {
  int i, j, t, n;
  scanf("%d", &n);
  for(i=0;i<n;i++){
    for(j=n-1;j>i;j--)printf(" ");
    for(t=0;t<2*i+1;t++)printf("*");
    printf("\n");
  }
  return 0;
}