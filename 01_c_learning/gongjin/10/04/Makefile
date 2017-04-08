TGT = a.out
SRCS = main.c test.c
OBJ = $(SRCS:.c=.o)
DEP = $(SRCS:.c=.dep)
CC = gcc
RM = rm

#替换机制
#  $(变量名:需要替换的部分=替换的部分)
#:= 不能有空格键
#$(SRCS:.c = .dep)不能有空格


$(TGT):$(OBJ)
	$(CC)  $(OBJ)  -o $(TGT)

#头文件被更新，所以的依赖该头文件的文件都被重新编译
# %  匹配模式规则，执行的过程类似循环


#系统中包含了main.dep  test.dep两个文件
#遇到匹配模式规则
#main.dep:main.c
#   gcc -MM main.c > main.dep

#test.dep:test.c
#	gcc -MM test.c  > test.dep

#下面这三句话存在，是为了解决因为头文件的更新，所以依赖该头文件的文件都需要更新的文件。
%.dep:%.c
	$(CC)  -MM $<  > $@
-include $(DEP)



clean:
	$(RM) -rf $(TGT)  $(OBJ) $(DEP)


