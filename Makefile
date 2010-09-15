shell: shell.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -rf shell
