#编译工程的过程
#编译当前目录下的.c文件生成对应的.o文件，并且链接当前目录的.o文件和子目录下的built-in.o文件，生成built-in.o
#把所有的目录下的built-in.o中间目标文件链接起来，最终生成a.out

TGT = a.out
SUB_DIR = main test
#export
#对变量名加上export  会把该变量导入该目录下的子目录
#子目录中有相同名称的变量，则会覆盖
export SUB_TGT = built-in.o
#arm-linux-gcc 交叉编译工具
export CC = gcc  
export RM = rm
export CUR_DIR = $(shell pwd)
export HEAD_DIR = $(CUR_DIR)/include
export CFLAGS = -I $(HEAD_DIR)

#终极目标
#	$(CC) main/built-in.o test/built-in.o -o $(@)
$(TGT):$(SUB_DIR)
	$(CC) $(^:=/$(SUB_TGT)) -o $(@)

#a.out:main test
#	gcc main/built-in.o test/built-in.o  -o a.out
#main test


#make -C 目录   到目录下去执行make指令
$(SUB_DIR):
	make -C $@

#清除多有的中间文件（.c生成的.o 以及built-in.o），终极目标(a.out)，以及（.dep）
clean:
	$(RM) -rf $(TGT)
	for dir in $(SUB_DIR);do \
		make -C $$dir  clean; \
	done

#.PHONY 伪目标
#当一个目标是伪目标时候，那么也管当前的目录下是否有对应的文件，该目标的规则都会被强制执行
.PHONY:$(SUB_DIR)



