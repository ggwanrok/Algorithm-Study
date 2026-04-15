#include <stdio.h>
#include <string.h>

int main(void) {
  int n, m;
  char s[11];
  int len, temp;
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; i++){
    scanf("%s", s);
    len = strlen(s);
    for(int j=0;j<len/2;j++){
      temp = s[j];
      s[j] = s[len - j - 1];
      s[len - j - 1] = temp;
    }
    printf("%s\n", s);
    
  }
  return 0;
}