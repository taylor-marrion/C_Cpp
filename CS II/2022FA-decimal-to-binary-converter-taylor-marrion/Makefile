code-build.out: decimal-to-binary-converter_template.c
	gcc -o $@ $^

.PHONY: run
run: code-build.out
	./$^

.PHONY: clean

clean:
	rm -f code-build.out