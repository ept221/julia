all: julia mandelbrot

julia: src/julia.c
	mkdir -p bin
	gcc src/julia.c -O3 -o bin/julia -lpthread -lm

mandelbrot: src/mandelbrot.c
	mkdir -p bin
	gcc src/mandelbrot.c -O3 -o bin/mandelbrot -lpthread -lm

clean:
	rm -rf bin