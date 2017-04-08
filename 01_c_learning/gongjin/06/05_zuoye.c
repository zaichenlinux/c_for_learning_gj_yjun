#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//1，定义结构体类型
struct user {
	char *name;
	char tel[12];
};

int storageInfo(struct user *);
char *searchTel(char *, struct user *, size_t);
int main()
{
	struct user *us;
	us = malloc(sizeof(struct user) * 10);
	if (!us) {
		printf("申请堆空间失败！\n");
		return 1;
	}

	//&us = malloc(sizeof(struct user) * 10); //error， &us放在赋值号左边，表示一个地址常量，不能被赋值

	//2，保存用户输入的用户信息
	int count = storageInfo(us); //us的类型是struct user *

	printf("count = %d\n", count);
/*
	for (int i = 0; i < count; i++) {
		printf("name: %s, tel: %s\n",
				(us + i)->name, us[i].tel);
	}
*/

	//3，查询用户对应的电话
	printf("请输入您要查询的用户姓名：\n");
	char name[10];
	scanf("%s", name);

	//printf("--------- us.name = %p\n", us->name);

	char *result = searchTel(name, us, count);
	if (result) {
		printf("找到了，电话是：%s\n", result);
	} else {
		printf("抱歉，没找到！\n");
	}

	/*
	for (int i = 0; i <= count; i++) {
		free((us + i)->name);
	}*/

	return 0;
}

int storageInfo(struct user *pus)
{
	int count = 0; //记录一共输入信息的用户个数
	while (1) {
		printf("请输入用户的姓名：\n");
		(pus + count)->name = malloc(10);
		if (!(pus+count)->name) {
			printf("申请堆空间失败！\n");
			return 1;
		}
		
		//scanf("%s", (pus + count)->name); //这一行和下一行只是写法不同，意义相同
		scanf("%s", pus[count].name);
		if (!strcmp(pus[count].name, "#")) { //输入结束
			break;
		}

		printf("请输入用户的电话：\n");
		scanf("%s", (pus + count)->tel);

		count++;
	}
		
	return count;
}

char *searchTel(char *name, struct user *ps, size_t count)
{
	while (count--) {
		printf("ps: %s\n", (ps + count)->name);
		if (!strcmp(name, (ps + count)->name)) { //找到了
			return (ps + count)->tel;
		}
	}

	return NULL;
}
