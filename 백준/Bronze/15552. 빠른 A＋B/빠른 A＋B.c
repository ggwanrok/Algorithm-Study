#include <stdio.h>

int main(void) {
  int t;
  int a, b;
  int sum = 0;
  scanf("%d", &t);
  for(int i=0;i<t;i++){
    scanf("%d %d", &a, &b);
    sum = a+b;
    printf("%d\n", sum);
    
  }
  return 0;
}