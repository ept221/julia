all: julia mandelbrot

julia: julia.c
	gcc julia.c -O3 -o julia -lpthread -lm

mandelbrot: mandelbrot.c
	gcc mandelbrot.c -O3 -o mandelbrot -lpthread -lm

clean:
	rm julia
	rm mandelbrot