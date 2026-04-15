#include <stdio.h>

int main(void) {
  int n;
  int i;
  long sum=5;
  scanf("%d", &n);
  if( n==1){
    printf("%ld", sum%45678);
    }
  else{
    for(i=1;i<n;i++){
      sum += 4 + 3*i;
    }
    printf("%ld", sum%45678);
  }
  return 0;
}