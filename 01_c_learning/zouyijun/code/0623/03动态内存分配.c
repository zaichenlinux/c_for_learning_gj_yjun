#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>

struct foo {
	char *name;
	int age;
};

int main()
{
	struct foo *pf;
	pf = malloc(sizeof(struct foo));
	if (!pf) {
		printf("申请失败！\n");
		return 1;
	}

	// -> 指针运算符，或者称为箭头运算符。前面的操作数必须是结构体(或联合体)指针类型。
	
	pf->name = calloc(10, sizeof(char));
	if (!(pf->name)) {
		printf("申请失败！\n");
		return 1;
	}

	strcpy(pf->name, "tim");
	printf("pf->name = %s\n", pf->name);

	free(pf->name);
	free(pf);

	return 0;
}
