#写Makefile之前，先要了解如何编译

#Makefile 一般还会有一个清除一个指令
#一般标签的名称命名为  clean

#Makefile 要有通用性
TGT = a.out
#SRCS = main.c test.c 
CC = gcc
RM = rm

#a.out:
#	gcc main.c test.c -o a.out

#Makefile中的特殊的变量
# $@  表示当前规则中的目标   @是变量  $@取变量的值
# $^  表示当前规则中所有的依赖或者说条件
# $<  表示当前规则中所有的依赖（条件）中的第一个
# $? 。。。。。。所有比目标更新的文件
# $*  模式规则中%匹配的部分

#目标 一般指的是对应的文件   标签 就是一个称号
#all2 规则执行的过程
#all2 依赖 file1 file2 file3
#首先到该目录，去找有没有file1 file2 file3这三个文件
#如果没有这三个文件，然后去makefile下文中，找有没有file1, file2, file3目标
#如果目标也没有，那么就会报依赖关系错误

all2:file1  file2  file3
	echo all2
	@echo $@
	@echo $^
	@echo $<
	@echo $?


file1:
	echo file1

file2:
	echo file2

file3:
	echo file3


#$(TGT):
#	$(CC)  $(SRCS)  -o $(TGT)

$(TGT):$(SRCS)
	$(CC)  $^  -o $@


all:
	gcc main.c test.c

#Makefile再执行命令列表时，会先把该命令打印出来，如果想屏蔽该命令的打印，命令列表前加上@
#有时候，命令列表需要强制执行，不管上一条指令执行的对与错。
#命令列表前 加上-强制执行。
test:
	-ls -alh  asdfasdfadsdf
	@echo "hello world"

#clean标签，清除工程的中间文件以及最终的目标
clean:
	rm -rf  a.out  file1 file2 file3
	
