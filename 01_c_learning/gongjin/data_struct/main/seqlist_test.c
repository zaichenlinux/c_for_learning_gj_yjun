#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "seqlist.h"


void seqlist_test()
{

	int i = 0;
	struct seqlist_class *slist = (struct seqlist_class *)malloc(sizeof(struct seqlist_class));
	assert(slist);
	init_seqlist(slist);//构造函数
	

	slist->insert(slist->list, 0,1);
	slist->insert(slist->list, 1,2);
	slist->insert(slist->list, 2,3);
	slist->insert(slist->list, 3,1);
	slist->insert(slist->list, 4,1);
	slist->ptr(slist->list);

	slist->del(slist->list, 3);
	slist->del(slist->list, 2);
	slist->ptr(slist->list);

	if( (i = slist->search(slist->list, 1)) > 0)  {
		printf("找到了，位于%d\n", i);
	}

	slist->change(slist->list, 8, 1);
	slist->ptr(slist->list);

	return 0;


}
