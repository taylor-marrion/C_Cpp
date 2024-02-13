code-build.out: inventory-system_template.c
	gcc -o $@ $^

.PHONY: run
run: code-build.out input.txt
	./$^

.PHONY: clean

clean:
	rm -f code-build.out
