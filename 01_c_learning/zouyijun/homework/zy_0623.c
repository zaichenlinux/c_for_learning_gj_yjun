#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//1、定义一个结构体，其中包含姓名和电话号码。要求用户通过键盘输入姓名和电话号码，在输入#号时表示输入结束。实现可以通过输入姓名查询出对应的电话号码
struct user {
	char *name;
	char tel[20];
};

int count = 0;
int storage_user_info(struct user *pu, int n)
{
#if 0
	// scanf解决
	for (int i = 0; i < n; i++) {
		printf("请输入用户的姓名: ");
		(pu + i)->name = malloc(8);
		if (!((pu + i)->name)) {
			printf("申请堆空间失败！\n");
			exit(EXIT_FAILURE);
		}
		scanf("%s", (pu + i)->name);

		if (!strcmp((pu + i)->name, "#")) {
			printf("ok\n");
			break;
		}

		printf("请输入用户的电话：");
		scanf("%s", (pu + i)->tel);

		count++;
	}
#endif

	// fgets解决
	for (int i = 0; i < n; i++) {
		printf("请输入用户的姓名: ");
		(pu + i)->name = malloc(8);
		if (!((pu + i)->name)) {
			printf("申请堆空间失败！\n");
			exit(EXIT_FAILURE);
		}
		fgets((pu+i)->name, 20, stdin);

		//printf(":: %s\n", (pu+i)->name);
		//if (!strcmp((pu + i)->name, "#\n")) {
		if (!strncmp((pu + i)->name, "#", 1)) {
			printf("ok\n");
			break;
		}

		printf("请输入用户的电话：");
		fgets((pu+i)->tel, 20, stdin);

		count++;
	}

	return count;
}

// 第二个参数表示要查询的用户的姓名
void query_tel(struct user *pu, char *name)
{
	for (int i = 0; i < count; i++) {
		if (!strncmp(name, (pu + i)->name, strlen((pu + i)->name)-1)) {
			printf("%s用户的电话是：%s\n", name, (pu + i)->tel);
			return;
		}
	}

	printf("sorry, 并未保存这个用户的信息\n");
}

int main()
{
	struct user info[100] = {0};

	// 1, 保存用户输入的信息
	int num = storage_user_info(info, 100);

	printf("num = %d\n", num);

	for (int i = 0; i < num; i++) {
		printf("%s-%s\n", (info + i)->name, (info + i)->tel);
	}

	// 2, 查询姓名对应的电话
	printf("请输入您要查询的用户姓名：");
	char name[20];
	scanf("%s", name);
	query_tel(info, name);

	// 3, 释放之前申请的空间
	for (int i = 0; i <= count; i++) {
		free((info + i)->name);
	}

	return 0;
}
