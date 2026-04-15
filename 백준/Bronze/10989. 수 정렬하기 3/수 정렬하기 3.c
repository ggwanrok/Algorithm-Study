#include <stdio.h>

int main(void) {
  int n, x;
  int s[10001]={0, };
  scanf("%d", &n);
  for(int i=0;i<n;i++){
    scanf("%d", &x);
    s[x]++;
  }
  for(int i=0;i<10001;i++){
    if(s[i] !=0){
      for(int j=0;j<s[i];j++){
        printf("%d\n", i);
      }
    }
  }
  
  return 0;
}