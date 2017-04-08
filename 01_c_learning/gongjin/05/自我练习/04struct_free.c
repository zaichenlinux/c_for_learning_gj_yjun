#include<stdio.h>
#include<stdlib.h>
struct foo
{
	int a;
	char *p;
};

#define SAFE_FREE(p) do{free(p);p=NULL;}while(0)
int main()
{
	struct foo *pfoo;
	pfoo=(struct foo*)malloc(sizeof(struct foo));
	if(pfoo==NULL)
	{
		//return;
	}
//
	pfoo->a=88;
	pfoo->p=(char *)malloc(sizeof("hello"));
	pfoo->p="hello";
	//free(pfoo);
	//pfoo=NULL;
	printf("pfoo->a=%d,pfoo->p=%s\n",pfoo->a,pfoo->p);//free仅仅是告知系统，该空间可以被回收；
	//但是该指针pfoo仍然指向该空间，为了防止误修改地址，
	SAFE_FREE(pfoo);
	return 0;
}
