SRCS = test.c
SUB_DIR =
DEP = $(SRCS:.C=.DEP)
$(SUB_TGT):$(SRCS:.c=.o) $(SUB_DIR)
	ld	$(CFLAGS)	$(SRCS:.C=.o)	$(SUB_DIR:=/$(SUB_TGT))
$(SUB_DIR):
	make -C $@
%.dep:%.c
		$(CC)	$(CFLAGS)	-MM	$ <	>$@
-include $(DEP)
clean:
	$(RM)-rf $(SUB_TGT) $(SRCS:.c=.o) $(SRCS:.c=.dep)
	for dir in $(SUB_DIR);do \
			make -C $$dir	clean; \
	done
.PHONY:$(SUB_DIR)	clean
