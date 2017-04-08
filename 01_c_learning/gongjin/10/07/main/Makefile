SRCS = main.c
SUB_DIR =
DEP = $(SRCS:.c=.dep)

$(SUB_TGT):$(SRCS:.c=.o) $(SUB_DIR)
	ld	$(CFLAGS) $(SRCS:.c=.o) $(SUB_DIR:/$(SUB_TGT)) -r -o $(SUB_TGT)

#执行子目录下的makefile，编译链接生成built-in.o
$(SUB_DIR):
		make -C $@
%.dep:%.c
		$(CC) $(CFLAGS) -MM $< > $@
-include $(DEP)
#清除
clean:
	$(RM) -rf $(SUB_TGT) $(SRCS:.c=.o) $(SRCS:.c=.dep)
	for dir in $(SUB_DIR); \
			make -C $$dir clean; \
	done
.PHONY:$(SUB_DIR) clean

