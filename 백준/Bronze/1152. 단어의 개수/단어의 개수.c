#include <stdio.h>
#include <string.h>
int main(void) {
  char s[1000001];
  scanf("%[^\n]s", s);
  int t =0;
  int i;
  int len=strlen(s);
  if(s[0] != ' ')t++;
  
  for(i=1;i<len;i++){
    if(s[i-1] == ' '&&s[i] != ' '){
      t++;
    }
  }
  printf("%d", t);
  return 0;
}