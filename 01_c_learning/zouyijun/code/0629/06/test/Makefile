#子Makefile，用来告诉make如何生成当前目录下的子目标built-in.o

SUB_DIR = foo
SRCS = test.c

#下面的规则，用来告诉make当前目录下的built-in.o是由当前目录下的.o和当前目录下的子目录下的built-in.o链接生成的
$(SUB_TGT): $(SRCS:.c=.o) $(SUB_DIR) 
	$(LD) $(SRCS:.c=.o) $(SUB_DIR:=/$(SUB_TGT)) -r -o $@ 

%.o: %.c
	$(CC) $(CFLAGS) -c $<

$(SUB_DIR):
	make -C $@

#下面的生成.d文件的写法比较通用。该规则中的3条命令，需要在同一条进程中完成（也就是说：需要在多个命令之间用;连接，并且用\表示是处于同一行的）其中的$$$$会被替换为$$，表示当前执行的进程的进程编号; 借用的shell中的针对行替换的sed命令，sed命令的用法是：sed 's/旧的内容/新的内容/' 要操作的文件
%.d: %.c
	$(CC) $(CFLAGS) -MM $< > $@.$$$$; \
		sed 's/$*.o: /$*.o $*.d: /' $@.$$$$ > $@; \
		rm -vf $@.$$$$ 
sinclude $(SRCS:.c=.d)

clean:
	-rm -vf $(SUB_TGT) $(SRCS:.c=.o) $(SRCS:.c=.d)
	for dir in $(SUB_DIR); do \
		make -C $$dir clean; \
	done

.PHONY: clean $(SUB_DIR)

