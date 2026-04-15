#include <stdio.h>
#include <string.h>

int main(void) {
  int n;
  int i;
  char s[51];
  scanf("%d", &n);
  for(i=0; i<n; i++){
    scanf("%s", s);
    printf("String #%d\n", i+1);
    int l = strlen(s);
    for(int t=0;t<l;t++){
      if(s[t] == 'Z'){
        s[t] = 'A';
        }
      else{
        s[t] += 1;
      }
     
    }
     printf("%s\n\n", s);
  }
  
  return 0;
}