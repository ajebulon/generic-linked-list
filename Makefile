CC = gcc
CFLAGS += -Wall -Werror -ggdb3 -std=gnu99

PROG_NAME = gen_llist

$(PROG_NAME): gen_llist_driver.o gen_llist.o
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

.PHONY: clean
clean:
	rm -rf *.o
	rm -rf $(PROG_NAME)