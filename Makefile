all: getwchan
.PHONY: all

getwchan: getwchan.c
	$(CC) -o $@ -lprocstat $<
