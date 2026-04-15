#include <stdio.h>
#include <math.h>
int main(void) {
  float d2;
  int d, h, w;
  scanf("%d %d %d", &d, &h, &w);
  d2 = sqrt(h*h+w*w);
  float h1 = d*h/d2;
  float w1 = d*w/d2;
  printf("%d %d", (int)h1, (int)w1);
  return 0;
}