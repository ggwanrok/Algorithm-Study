#include <stdio.h>

int main(void) {
  int a;//고정비용
  int b;//가변비용
  int c;//노트북 한대 판매비용
  int k;//만드는 노트북의 갯수
  //a+bt - t에 따는 회사측 부담비용..1
  //ct - t에 따른 수익..2
  //2가 1보다 커지는 상황이 손익 분기점
  scanf("%d %d %d",&a,&b,&c);
  if(c<=b){
    printf("-1");
    }
  else{
     printf("%d", a/(c-b) +1);
    }
  
 
  return 0;
}