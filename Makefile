CC = gcc
CFLAGS += -Wall -Werror

PROG_NAME = gen_llist

$(PROG_NAME): gen_llist_driver.o gen_llist.o
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

.PHONY: clean
clean:
	rm *.o
	rm $(PROG_NAME)