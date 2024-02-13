code-build.out: property-tracker_template.c
	gcc -o $@ $^

.PHONY: run
run: code-build.out input1.txt input2.txt
	./$^

.PHONY: small
small: code-build.out props1-sm-provided.txt props2-sm-provided.txt
	./$^

.PHONY: large
large: code-build.out props1-lg-provided.txt props2-lg-provided.txt
	./$^

.PHONY: clean
clean:
	rm -f code-build.out