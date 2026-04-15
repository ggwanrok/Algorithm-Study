#include <stdio.h>

int main(void) {
  int a, b;
  scanf("%d %d", &a, &b);
  int c = a*(b%10);
  int d = a*((b/10)%10);
  int e = a*((b/100)%10);
  printf("%d\n%d\n%d\n%d\n", c, d, e, c+ d*10 + e*100);
  return 0;
}