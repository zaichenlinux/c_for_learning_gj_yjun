TGT = a.out
SRCS = test.c stack.c
CC = gcc
RM = rm

$(TGT): $(SRCS:.c=.o)
	$(CC) $^ -o $@

%.o: %.c
	$(CC) $< -c

%.d: %.c
	$(CC) $< -MM > $@

sinclude $(SRCS:.c=.d)

clean:
	$(RM) -vf $(TGT) $(SRCS:.c=.o) $(SRCS:.c=.d)

.PHONY: clean
