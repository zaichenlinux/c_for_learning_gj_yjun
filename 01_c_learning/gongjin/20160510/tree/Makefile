TGT = a.out
SRCS = main.c btree.c stack.c queue.c
CFLAGS = -O

$(TGT): $(SRCS:.c=.o)
	gcc $^ $(CFLAGS)

%.o: %.c
	gcc $< -c $(CFLAGS)

%.d: %.c
	gcc $< -MM > $@
sinclude $(SRCS:.c=.d)

.PHONY: clean

clean:
	-rm -rf $(TGT) $(SRCS:.c=.o) $(SRCS:.c=.d)

