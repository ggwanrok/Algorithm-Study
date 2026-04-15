#include <stdio.h>
#include <string.h>
int main(void) {
  int f=0, m[6], j=0;
  char s[11];
  for(int i = 0; i<5; i++){
    scanf("%s", s);
    if(strstr(s, "FBI") != NULL){
      m[j] = i+1;
      f=1;
      j++;
    }
  }
  if(f==0)printf("HE GOT AWAY!");
  else{
    for(int i = 0;i<j;i++)printf("%d ", m[i]);
  }
  return 0;
}