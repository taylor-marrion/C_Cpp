code-build.out: midterm_template.c
	gcc -o $@ $^ -lm

.PHONY: run
run: code-build.out points.txt
	./$^ output.txt

.PHONY: clean

clean:
	rm -f code-build.out output.txt