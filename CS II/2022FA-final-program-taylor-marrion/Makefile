code-build.out: train_stations_template.c
	gcc -o $@ $^

.PHONY: run
run: code-build.out stations.dat trains.dat
	./$^

.PHONY: clean
clean:
	rm -f code-build.out