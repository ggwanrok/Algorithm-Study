#include <stdio.h>

int main(void) {
  int n;
  scanf("%d", &n);
  int s[1001] = {0, };
  int temp;
  for(int i=0;i<n;i++){
    scanf("%d",&s[i]);
  }
  
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
      if(s[i]>s[j]){
      temp = s[i];
      s[i] = s[j];
      s[j] = temp;
        }
    }
  }
  for(int i=0;i<n;i++){
    printf("%d\n", s[i]);
  }
  return 0;
}