/*
顺序表：本质是一个数组，用一个标号标志该顺序表的大小

增
删
改
查
*/

#include <stdio.h>
#include <stdlib.h>

#define  MAX_SIZE  20



struct seqlist {
	int data[MAX_SIZE];
	int last;  //该成员一直表示该顺序表的大小
};

//插入：按位置插入,在weizhi上插入data
 int insert_seqlist(struct seqlist *l, int data, int weizhi)
{
	int i;
	//容错处理
	if(l->last >= MAX_SIZE){
		printf("%s, %s, %d顺序表溢出\n",__FILE__, __func__, __LINE__ );
		return -1;
	} else if((weizhi < 1) ||(weizhi >l->last+1)){
		printf("%s, %s, %d位置有误\n", __FILE__, __func__, __LINE__);
		return -1;
	}

	for(i=l->last-1;i>=weizhi-1;i--)
		l->data[i+1] = l->data[i];
	l->data[weizhi-1] = data;
	l->last++;
	return 0;
}

//删除：按照位置删除数据
 int del_seqlist(struct seqlist *l, int weizhi)
{
	int i ;
	if(l->last <= 0){
		printf("%s, %s, %d顺序表为空\n",__FILE__, __func__, __LINE__ );
		return -1;
	} else if((weizhi < 1) ||(weizhi >l->last)){
		printf("%s, %s, %d位置有误\n", __FILE__, __func__, __LINE__);
		return -1;
	}
	for(i=weizhi-1;i<l->last-1;i++)
		l->data[i] = l->data[i+1];
	l->last--;
	return 0;
}

//查：按数据查位置
int search_seqlist(struct seqlist *l, int data)
{
	int i;
	for (i = 0; i < l->last-1; ++i)
	{
		if(l->data[i] == data) {
			return i+1;
		}
	}
	return -1;
}

 int change_seqlist(struct seqlist *l, int data, int weizhi)
{
	if((weizhi < 1) ||(weizhi >l->last)){
		printf("%s, %s, %d位置有误\n", __FILE__, __func__, __LINE__);
		return -1;
	}

	l->data[weizhi-1] = data;
	return 0;
}

 void ptr_seqlist(struct seqlist *l)
{
	int i = 0;
	for(;i<l->last;i++) 
		printf("%d  ", l->data[i]);
	printf("\n");
}

int main()
{
	int i = 0;
	struct seqlist *list = (struct seqlist *)malloc(sizeof(struct seqlist) );
	list->last = 0;

	insert_seqlist(list, 0,1);
	insert_seqlist(list, 1,2);
	insert_seqlist(list, 2,3);
	insert_seqlist(list, 3,1);
	insert_seqlist(list, 4,1);
	ptr_seqlist(list);

	del_seqlist(list, 3);
	del_seqlist(list, 2);
	ptr_seqlist(list);

	if( (i = search_seqlist(list, 1)) > 0)  {
		printf("找到了，位于%d\n", i);
	}

	change_seqlist(list, 8, 1);
	ptr_seqlist(list);

	return 0;
}
