TGT = a.out
SRCS = main.c test.c
CC  = gcc
RM  = rm
#首先定义变量，指定当前的目录
#$(shell 命令)  执行shell命令，并把执行结果赋值给变量

CUR_DIR	= $(shell pwd)
HEAD_DIR = $(CUR_DIR)/include

#编译选项
CFLAGS = -I $(HEAD_DIR)

#自动推导会用的特殊的变量
#CFLAGS  指定文件（.h）的路径，如  -I $(HEAD_DIR)
#LDFLAGS  gcc编译器的优化的参数，指定库文件的位置  -L /usr/lib
#LIBS  告诉编译器需要链接哪些库文件   -lmytest



$(TGT):$(SRCS:.c=.o)
	$(CC) $^  -o $(TGT) 

#隐藏规则
%.o:%.c
	gcc  $(CFLAGS)  $<  -c -o $@
	

#链接
#a.out:main.o test.o
#   gcc  main.o test.o -o  a.out

#main.o:main.c
#   gcc $(CFLAGS) -c  -o main.o main.c

clean:
	$(RM) -rf $(SRCS:.c=.o)  $(TGT)
