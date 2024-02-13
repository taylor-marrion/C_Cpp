code-build.out: creating-linked-lists_template.c
	gcc -o $@ $^

.PHONY: run
run: code-build.out
	./$^

.PHONY: clean

clean:
	rm -f code-build.out