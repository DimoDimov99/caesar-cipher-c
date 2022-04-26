SRCS=$(wildcard *.c)

OBJS=$(SRCS:.c=.o)

main: $(OBJS)