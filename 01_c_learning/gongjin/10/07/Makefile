#作业：写Makefile管理该工程
#LD_LIBRARY_PATH  动态库的环境变量  环境变量的配置一般不在makefile中配置。

#数据结构
#1.顺序表 链表 双向循环链表 内核链表
#栈 队列 排序二叉树 哈希表 7大排序
#2.用makefile管理一个工程
#3.C语言模拟面向对象
TGT = a.out
SUB_DIR = main test foo lib

export SUB_TGT = built-in.o
export CC = gcc
export RM = rm
export CUR_DIR = $(shell pwd)
export HEAD_DIR = $(CUR_DIR)/include
export CFLAGS = -I $(HEAD_DIR)

$(TGT):$(SUB_DIR)
	$(CC) $(^:=/$(SUB_TGT)) -o $(@)

$(SUB_DIR):
		make -C $@
clean:
		$(RM) -rf $(TGT)
		for dir in $(SUB_DIR);do \
				make -C $$dir clean; \
		done
.PHONY:$(SUB_DIR)
