#include <stdio.h>

int main(void) {
  int n;
  int sum = 0;
  char s[101];
  scanf("%d", &n);
  scanf("%s", s);
  for(int i=0; i <n;i++){
    sum += s[i] - '0';
  }
  printf("%d", sum);
}