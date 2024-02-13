code-build.out: sorting-arrays_template.c
	gcc -o $@ $^

.PHONY: run
run: code-build.out input.txt
	./$^

.PHONY: small
small: code-build.out input1-provided.txt
	./$^

.PHONY: large
large: code-build.out input2-provided.txt
	./$^

.PHONY: clean

clean:
	rm -f code-build.out
