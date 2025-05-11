#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//模拟qsort函数实现一个冒泡排序的通用算法
struct stu {
	char name[20];
	int age;
};

void Print(stu arr[],int n) {
	int i = 0;
	while (i < n) {
		printf("(%s %d);", arr[i].name,arr[i].age);
		i++;
	}
}

void swap(char* a,char* b,int width) {
	int i = 0;
	while (i < width-1) {
		char temp = *a;
		*a = *b;
		*b = temp;
		i++;
		a++;
		b++;
	}
}

void bubble(void* base,int sz, int width,int (*cmp)(void*,void*)) {
	int i = 0, j = 0;
	for (i = 0; i < sz-1; i++) {
		for (j = 0; j < sz - 1 - i; j++) {
			if (cmp((char*)base + j * width,(char*)base + (j+1) * width)>0)
				swap((char*)base + j * width, (char*)base + (j + 1) * width,width);
		}
	}
}

int cmp_by_age(void* e1,void* e2) {
	return ((stu*)e1)->age - ((stu*)e2)->age;
}

int cmp_by_name(void* e1, void* e2) {
	return strcmp(((stu*)e2)->name,((stu*)e1)->name);
}

int main() {
	stu arr[3] = { {"ahangsan",22},{"bangwu",24},{"cisi",19} };
	int sz = sizeof(arr) / sizeof(arr[0]);
	printf("排序前>\n");
	Print(arr,sz);
	bubble(arr, sz, sizeof(arr[0]), cmp_by_age);
	printf("\n按年龄升序排序后>\n");
	Print(arr, sz);
	bubble(arr, sz, sizeof(arr[0]), cmp_by_name);
	printf("\n按名字降序排序后>\n");
	Print(arr, sz);
}

