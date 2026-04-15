#include <stdio.h>

int main(void) {
  int n; scanf("%d", &n);
  int q = n%15;
  int W = n/5; int w = n%5;
  int E = n/3; int e = n%3;
  if(q == 0)printf("%d", W);
  else if(w==0)printf("%d", W);
  else if(w==3)printf("%d", W+1);
  else if(w==4){
    if(W>=1){
      printf("%d", W-1+3);
    }
    else{
      printf("-1");
    }
  }
  else if(w==2){
    if(W>=2){
      printf("%d",W-2+4);
    }
    else{
      printf("-1");
    }
  }
  else if(w==1){
    if(W>=1){
      printf("%d", W-1+2);
    }
    else{
      printf("-1");
    }
  }
  else if(e==0)printf("%d", E);
  return 0;
}