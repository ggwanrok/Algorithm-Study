#include <stdio.h>
#include <string.h>
int main(void) {
  char s[101];
  int i;
  scanf("%s", s);
  for(i=0;i<strlen(s);i++){
    printf("%c", s[i]);
    if((i+1)%10 == 0)printf("\n");
  }
  
  return 0;
}