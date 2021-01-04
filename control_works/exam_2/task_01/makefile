.PHONY: clean

app.exe: out/main.o out/bit_pack.o
	gcc -std=c99 -Wall -Wextra -Wpedantic -Werror -g0 -o $@ $^

out/main.o: src/main.c inc/bit_pack.h | out/
	gcc -Iinc/ -std=c99 -Wall -Wextra -Wpedantic -Werror -g0 -c $< -o $@

out/bit_pack.o: src/bit_pack.c inc/bit_pack.h | out/
	gcc -Iinc/ -std=c99 -Wall -Wextra -Wpedantic -Werror -g0 -c $< -o $@

out/:
	mkdir -p $@

clean:
	rm -rf *.exe out/