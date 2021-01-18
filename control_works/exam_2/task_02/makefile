.PHONY: clean

app.exe: out/main.o out/my_malloc.o
	gcc -std=c99 -Wall -Wextra -Wpedantic -Werror -g0 -o $@ $^

out/main.o: src/main.c inc/my_malloc.h | out/
	gcc -Iinc/ -std=c99 -Wall -Wextra -Wpedantic -Werror -g0 -c $< -o $@

out/my_malloc.o: src/my_malloc.c inc/my_malloc.h | out/
	gcc -Iinc/ -std=c99 -Wall -Wextra -Wpedantic -Werror -g0 -c $< -o $@

out/:
	mkdir -p $@

clean:
	rm -rf *.exe out/