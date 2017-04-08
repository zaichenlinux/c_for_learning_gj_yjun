#自动推导
#gcc    -c -o main.o main.c
#gcc    -c -o test.o test.c

#Makefile 会有一个自动推导的过程
#隐藏的规则
#自动推导只是针对中间文件.o，会自动找到中间文件.c
#自动调用  gcc 指令
#如果存在中间文件.o规则，那么自动推导就不会发生
#main.o:mian.c
#	gcc     -c -o  main.o mian.c
#test.o:test.c
#   gcc     -c -o test.o test.c
#最终目标更新的条件：
#1.目标文件是否存在，若不存在，则执行该规则
#2.目标文件存在，但是时间戳比它的依赖要旧，则执行该规则
#3.目标文件存在，但是它的依赖文件需要更新

TGT = a.out
SRCS = main.c test.c
OBJ = main.o test.o
CC = gcc
RM = rm


$(TGT):$(OBJ)
	$(CC)  $^ -o $@

#a.out:main.o test.o
#	gcc main.o test.o -o a.out


clean:
	rm -rf $(OBJ)  $(TGT)
