#include <stdio.h>

int main(void) {
  long n;
  int i;
  long sum=1;
  long mm =1;
  int t=0;
  scanf("%ld", &n);
  if(n==1)printf("1");
  else{
  while(1){
  sum += 6*t;
  mm += 6*(t-1);
   t++;
    if(n>mm && n<=sum){
      printf("%d", t);
       break;
    }
  
    }
    }
  return 0;
}