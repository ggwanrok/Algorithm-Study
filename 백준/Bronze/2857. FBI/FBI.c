#include <stdio.h>
#include <string.h>
int main(void){
	int f = 0, num[6], j = 0;
	char name[11];
	for (int i = 1; i < 6; i++) {
		scanf("%s", name);
		if (strstr(name, "FBI") != NULL) {
			num[j] = i;
			f = 1;
			j++;
		}
	}
	if (f == 0) printf("HE GOT AWAY!");
	else {
		for (int i = 0; i < j; i++) printf("%d ", num[i]);
	}
	return 0;
}

