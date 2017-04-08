SRCS = main.c test.c 
TGT = a.out
CC = gcc

#系统可以参考的Makefile的文件可以在/usr/src目录下找到

$(TGT): $(SRCS)
	$(CC) $^ -o $@

#每一次重新编译，都需要先清除之前一次编译后的中间文件和终极目标文件
#下面的clean标签所在的规则，就是用来清理的。以备下一次重新编译。
clean:
	rm -rf $(TGT) 

# clean这个目标被作为伪目标
.PHONY: clean

#伪目标：这个目标不是一个真正的目标。make不会判断以clean为名字的这个文件是否存在，也不会去查看这个目标是否有依赖，只会简单的执行这个伪目标下的命令。
