CC = gcc
CFLAGS = -Wall -Wextra -I$(HOME)/lib/include
LDFLAGS = -L$(HOME)/lib/lib

# Library name (match directory name)
LIBNAME = common_types

# Source files
SRCS = $(LIBNAME).c
OBJS = $(SRCS:.c=.o)

# Targets
all: lib$(LIBNAME).a

lib$(LIBNAME).a: $(OBJS)
	ar rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

install:
	mkdir -p $(HOME)/lib/include/$(LIBNAME)
	cp $(LIBNAME).h $(HOME)/lib/include/$(LIBNAME)/
	cp lib$(LIBNAME).a $(HOME)/lib/lib/

clean:
	rm -f *.o *.a

.PHONY: all install clean
