TGT = a.out
SRCS = main.c test.c
CC = gcc

$(TGT): $(SRCS:.c=.o) #将SRCS变量中的.c替换为.o
	$(CC) $^

#test.o: test.c
#main.o: main.c
%.o: %.c #模式规则，%匹配的是.c前面的部分
	@echo '$$* = ' $*
	@echo '$$? = ' $?
	$(CC) -c $<

#下面的规则用来解决头文件的更新，没有使得所有依赖于这个头文件的那些文件重新生成对应的.o文件的问题
# gcc -MM 某个源文件 // 这条命令，会自动生成这个源文件所生成的.o文件都会依赖于那些文件
%.dep: %.c
	$(CC) -MM $< > $@  
# 上面的这条规则，仅仅用来告诉make,如何生成文件之间的依赖关系
include $(SRCS:.c=.dep) #这一行是将上面规则生成的.dep文件中的内容包含进当前文件
# include 也可以写为 -include 或者 sinclude(这个更通用)

.PHNOY: clean

clean:
	rm -vf $(TGT) $(SRCS:.c=.o) $(SRCS:.c=.dep)

