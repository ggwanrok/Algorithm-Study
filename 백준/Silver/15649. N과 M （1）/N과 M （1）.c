#include <stdio.h>

int N, M;
int arr[8];                                         // 정답 배열
int check[9];                                       // 체크포인트

void print_num(int);

int main() {
	scanf("%d %d", &N, &M);
	print_num(0);
}

void print_num(int cnt) {
	if (cnt == M) {                                  // 배열 길이가 M이라면
		for (int i = 0; i < cnt; i++)
			printf("%d ", arr[i]);
		printf("\n");
	}
	else {
		for (int i = 1; i <= N; i++) {               // 1 ~ N 수 중
			if (check[i] == 0) {                     // 중복되지 않는 수라면
				check[i] = 1;                        // 해당 수 확인함
				arr[cnt] = i;                        // 배열에 숫자 추가
				print_num(cnt + 1);                  // 배열길이 1 증가
				check[i] = 0;                        // 모든 경우를 다 보기 위하여 체크 초기화
			}
		}
	}
}
