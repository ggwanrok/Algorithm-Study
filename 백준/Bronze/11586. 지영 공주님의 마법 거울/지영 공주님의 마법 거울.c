#include <stdio.h>

int main(void) {
  int n;
  char s[101][101];
  scanf("%d", &n);
  for(int i=0;i<n;i++){
    scanf("%s", s[i]);
    }
  int k;
  scanf("%d", &k);
  if(k==1){
    for(int m=0;m<n;m++){
      printf("%s\n", s[m]);
    }
  }
  else if(k ==2){
    for(int m=0;m<n;m++){
      for(int j=0;j<n;j++){
        printf("%c", s[m][n-j-1]);
      }
      printf("\n");
    }
  }
  else if(k==3){
    for(int m=0;m<n;m++){
      for(int j=0;j<n;j++){
        printf("%c", s[n-m-1][j]);
      }
      printf("\n");
  }
    }
  return 0;
}