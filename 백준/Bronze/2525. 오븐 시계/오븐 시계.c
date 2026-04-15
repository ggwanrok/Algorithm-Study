#include <stdio.h>

int main(void) {
  int a, b, c;
  scanf("%d %d", &a, &b);
  scanf("%d", &c);
  int d = c/60;
  int e = c%60;
  int q = a+d;
  int w = b+e;
  
  if(w >= 60){
    q = q + w/60;
    w = w -60;
  }
  if(q >= 24){
    q=q-24;
  }
  printf("%d %d", q, w);
  return 0;
}