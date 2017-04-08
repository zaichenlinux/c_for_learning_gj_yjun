TGT = a.out
SRCS = main.c sort.c
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
	-rm -vf $(TGT) $(SRCS:.c=.o) $(SRCS:.c=.d)

