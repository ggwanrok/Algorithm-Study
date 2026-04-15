#include <stdio.h>
#include <string.h>
int main(void) {
  char s[5];
  int sum = 0;
  scanf("%s", s);
  for (int i = 0; i < 5; i++) {
    int k = s[i]-48;
    int m = k * k * k * k * k;
    sum += m;
  }
  printf("%d", sum);
  return 0;
}