#主Makefile 用来指定规则，说明如何生成最终的目标的

#终极目标是由终极目标所依赖的那些目录下的子目标链接而成的
TGT = a.out 
#下面的变量，被称为子目录，用来指定当前目录下的子目录的
SUB_DIR = test main
#下面的变量，被称为子目标，用来告诉make如何生成当前这个目录下的子目标的，这个子目标是由这个子目录下的源文件生成的.o文件和这个子目录下的子子目录下的子子目标文件built-in.o链接生成的
export SUB_TGT = built-in.o
# 下面的变量，称为交叉编译器，用来指定使用的是哪个交叉编译器
#export CROSS_COMPILER = arm-linux-
export CC = $(CROSS_COMPILER)gcc
export CUR_DIR = $(shell pwd)
export HEAD_DIR = $(CUR_DIR)/head
export CFLAGS = -I$(HEAD_DIR) -Wall
#下面的变量，用来指定链接器
export LD = ld
#下面的变量，用来指定链接选项
export LDFLAGS =

#下面的规则，就是终极目标所在的规则
$(TGT): $(SUB_DIR)
	$(CC) $(CFLAGS) $(^:=/$(SUB_TGT))

#下面的规则，用来告诉make如何进入终极目标所依赖的目录(-C选项，用来告诉make需要进入目录)
$(SUB_DIR):
	make -C $@

#下面的清理规则中的31行开始，是调用了shell脚本语言中的for循环
clean:
	-rm -vf $(TGT)	
	for dir in $(SUB_DIR); do \
		make -C $$dir clean; \
	done

.PHONY: $(SUB_DIR) clean
