//오름차순 알고리즘과 퀵정렬 알고리즘에 대해서 배워본 시간이었다.
//공부하는데에 시간이 꽤나 걸리긴 했지만,
//포인터를 사용하는 것. 여러 알고리즘을 구현하는 것. return값의 의미.
//특히 퀵정렬, 선택정렬, 등의 여러 정렬 알고리즘을 찾아볼 수 있었다.
//메인함수 이전에 어떠한 구조체를 정의하고 함수를 작성(알고리즘)을 넣어 문제를 해결 할 수 있다는 c언어 기본서에 적혀있는 내용에 대해서
//다시 한번더 복기하는 기회가 되었다.
//앞으로 이런 문제가 나왔을 때, 이렇게 해결해버리고싶다. ㅋㅋ
//암튼 구조체, 퀵정렬, 포인터, 동적메모리, 여러 알고리즘...
//유익한 공부시간이었다.!!


#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int x;
  int y;
} Point;

int compare(const void *a, const void *b){
  Point A = *(Point *)a;
  Point B = *(Point *)b;
  if(A.x > B.x){
    return 1;
  }
  else if(A.x == B.x){
    if(A.y > B.y){
      return 1;
    }
    else{
      return -1;
    }
  }
  return -1;
}

int main(){
  int test;
  scanf("%d",&test);
  Point *arr;
  arr = (Point *)malloc(sizeof(Point) * test);
  for(int i = 0; i < test; i++){
    scanf("%d %d",&arr[i].x,&arr[i].y);
  }
  qsort(arr,test,sizeof(Point),compare);
  for(int i = 0; i < test; i++){
    printf("%d %d\n",arr[i].x,arr[i].y); 
  }
  free(arr);
  return 0;
}