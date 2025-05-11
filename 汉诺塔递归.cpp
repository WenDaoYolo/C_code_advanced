#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int time=0;

void Print(char x, char y) {
	printf("%c->%c\n", x, y);
	time++;
}
void move(int n, char pos1, char pos2, char pos3) {
	if (n == 1)
		Print(pos1, pos3);
	else
	{
		move(n - 1, pos1, pos3, pos2);
		Print(pos1, pos3);
		move(n - 1, pos2, pos1, pos3);
	}
}

int main() {
	//汉诺塔递归,假设移动一次需要一秒
	char pos1 = 'A', pos2 = 'B', pos3 = 'C';
	int n;
	printf("请输入汉诺塔的层数>");
	scanf("%d", &n);
	move(n, pos1, pos2, pos3);
	printf("耗时:%d秒\n", time);
	return 0;
	return 0;
}