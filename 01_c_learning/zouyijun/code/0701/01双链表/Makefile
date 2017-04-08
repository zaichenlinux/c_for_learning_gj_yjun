TGT = a.out
SRCS = test.c list.c
CC = gcc

$(TGT): $(SRCS:.c=.o)
	$(CC) $^ -o $@

%.o: %.c
	$(CC) $< -c

%.d: %.c
	$(CC) $< -MM > $@
sinclude $(SRCS:.c=.d)

clean:
	-rm -vf $(TGT) $(SRCS:.c=.o) $(SRCS:.c=.d)

.PHONY: clean
