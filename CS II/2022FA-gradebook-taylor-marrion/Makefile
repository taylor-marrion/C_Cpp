code-build.out: gradebook_template.c
	gcc -o $@ $^

.PHONY: run
run: code-build.out input.txt
	./$^

.PHONY: large
large: code-build.out input-large.txt
	./$^

.PHONY: clean

clean:
	rm -f code-build.out
