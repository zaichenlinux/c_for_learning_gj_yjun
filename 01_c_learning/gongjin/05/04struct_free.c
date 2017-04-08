/*
free()
*/
#include <stdio.h>
#include <stdlib.h>
struct foo
{
	int a;
	char *p;
};

#define SAFE_FREE(p)  do{free(p);p=NULL;}while(0)

int main(int argc, char const *argv[])
{
	/* code */

	struct foo *pfoo;
	pfoo = (struct foo *)malloc(sizeof(struct foo));
	if(pfoo == NULL)
	{
		return ;
	}

	//free(pfoo);//释放空间

	pfoo->a = 88;
	pfoo->p = "hello";

	free(pfoo); //free仅仅是告知系统,该空间可以被回收
	//但是pfoo仍然指向该空间.
	//为了防止pfoo误修改,地址. 
	//free(pfoo);
	pfoo=NULL;
	printf("%d, %s\n",pfoo->a, pfoo->p );
	return 0;
}