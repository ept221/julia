julia: julia.c
	gcc julia.c -O3 -o julia

mandelbrot: mandelbrot.c
	gcc mandelbrot.c -O3 -o mandelbrot

clean:
	rm julia
	rm mandelbrot