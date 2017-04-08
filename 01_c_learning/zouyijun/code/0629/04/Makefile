#注意：时间信息必须是正确的，否则编译会出错

TGT = a.out
SRCS = main.c test.c
CC = gcc
OBJ = main.o test.o
DEP = main.d test.d

#下面的变量，用来保存当前所在目录
CUR_DIR = $(shell pwd)
#下面的变量，用来保存头文件所在目录
HEAD_DIR = $(CUR_DIR)/head
#下面的变量，用来指定编译的选项
CFLAGS = -I$(HEAD_DIR) -Wall

$(TGT): $(SRCS:.c=.o)
	$(CC) $(CFLAGS) $^

#上面12行展开即为下面一行
#gcc -I头文件所在目录 main.o test.o

%.o: %.c
	$(CC) $(CFLAGS) -c $<

%.d: %.c
	$(CC) -MM $(CFLAGS) $< > $@
sinclude $(SRCS:.c=.d)

# rm前面的-号，可以保证如果当前命令执行出错，make会跳过当前错误，继续向下执行
clean:
	-rm -vf $(TGT) $(DEP) $(OBJ)

.PHONY: clean

