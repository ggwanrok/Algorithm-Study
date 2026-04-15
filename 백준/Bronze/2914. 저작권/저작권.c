#include <stdio.h>

int main(void) {
  int a, i;
  scanf("%d %d", &a, &i);
  int t = a*(i-1) + 1;
  printf("%d", t);
  
  return 0;
}