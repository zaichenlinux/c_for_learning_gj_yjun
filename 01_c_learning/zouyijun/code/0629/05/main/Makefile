#子Makefile，用来告诉make如何生成当前目录下的子目标built-in.o

SUB_DIR =
SRCS = main.c

#下面的规则，用来告诉make当前目录下的built-in.o是由当前目录下的.o和当前目录下的子目录下的built-in.o链接生成的
$(SUB_TGT): $(SRCS:.c=.o) $(SUB_DIR) 
	$(LD) $(SRCS:.c=.o) $(SUB_DIR:=/$(SUB_TGT)) -r -o $@ 

%.o: %.c
	$(CC) $(CFLAGS) -c $<

$(SUB_DIR):
	make -C $@

%.d: %.c
	$(CC) $(CFLAGS) -MM $< > $@
sinclude $(SRCS:.c=.d)

clean:
	-rm -vf $(SUB_TGT) $(SRCS:.c=.o) $(SRCS:.c=.d)
	for dir in $(SUB_DIR); do \
		make -C $$dir clean; \
	done

.PHONY: clean $(SUB_DIR)

