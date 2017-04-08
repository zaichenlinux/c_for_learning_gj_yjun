#子目录下Makefile
#当前目录下的目标（built-in.o）由当前目录下的.c文件生成.o文件以及当前目录下的子目录（如果有的情况）下的目标（built-in.o）链接生成
#ld  -r  不完全的链接
SRCS = test.c
SUB_DIR = 
DEP = $(SRCS:.c=.dep)

$(SUB_TGT):$(SRCS:.c=.o)  $(SUB_DIR)
	ld  $(CFLAGS) $(SRCS:.c=.o)  $(SUB_DIR:=/$(SUB_TGT))  -r -o $(SUB_TGT)

# built_in.o:main.o 
#	ld -I ......     main.o -r -o built-in.o

#%.o:%.c
#	$(CC)  $(CFLAGS) -c $<
#执行子目录下的makefile,编译链接生成built-in.o
$(SUB_DIR):
	make -C $@


%.dep:%.c
	$(CC)  $(CFLAGS)  -MM $<  > $@
-include $(DEP)

clean:
	$(RM) -rf $(SUB_TGT) $(SRCS:.c=.o)  $(SRCS:.c=.dep)
	for dir in $(SUB_DIR);do \
		make -C $$dir  clean; \
	done


.PHONY:$(SUB_DIR)  clean
