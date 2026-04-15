#include <stdio.h>
#include <string.h>
#define MIN(a,b) (a<b? a:b)

void sloution(int n);
int arr[1000001] = {0, };
int num;

void solution (int n){
  int i;
  arr[0] = 0;
  arr[1] = 0;
  int temp;

  for(i=2;i<n+1;i++){
    arr[i]=arr[i-1]+1;
    if(i%3==0){
      temp = arr[i/3]+1;
      arr[i] = MIN(temp, arr[i]);
    }
    if(i%2==0){
      temp = arr[i/2]+1;
      arr[i] = MIN(temp, arr[i]);
    }
  }
  printf("%d", arr[n]);
}

int main(void) {
  scanf("%d", &num);
  solution(num);
  
  return 0;
}
