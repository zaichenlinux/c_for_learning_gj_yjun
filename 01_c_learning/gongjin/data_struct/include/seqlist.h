#ifndef __SEQLIST_H
#define __SEQLIST_H

#define  MAX_SIZE  20
struct seqlist {
	int data[MAX_SIZE];
	int last;  //该成员一直表示该顺序表的大小
};


//声明了seqlist_class这个类
struct seqlist_class {
	struct seqlist *list;  //成员
						//方法
						//C语言 结构体成员不能放函数；只能放函数指针
	int (*insert)(struct seqlist *l, int data, int weizhi);
	int (*del)(struct seqlist *l, int weizhi);
	int (*search)(struct seqlist *l, int data);
	int (*change)(struct seqlist *l, int data, int weizhi);
	void (*ptr)(struct seqlist *l);
};

//构造函数
//一般构造具体对象，初始化
void   init_seqlist(struct seqlist_class * slist);

//析构函数
//释放掉对象
void destroy_seqlist(struct seqlist_class *slist);

#endif