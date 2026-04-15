#include <stdio.h>
#include <string.h>

int main(void) {
  int a;
  int b, c, d;
  int p;
  scanf("%d", &a);
  scanf("%d", &b);
  scanf("%d", &c);
  scanf("%d", &d);
  scanf("%d", &p);
  if (p<=c){
    if(a<=b){
      printf("%d", a*p);
    }
    else{
      printf("%d", b);
    }
  }
  else{
    int x = a*p;
    int y = b + (p-c)*d;
    if(x<=y){
      printf("%d", x);
    }
    else{
      printf("%d", y);
    }
  }
  
  return 0;
}