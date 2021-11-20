# julia
To build the project, run:
```bash
Make all
```

To create a Julia set plot, run:
```bash
./julia.sh 0.0 0.0 2.0 1000 200 -0.4 0.6
```

This will create an output png centered at (0.0,0.0) with a radius of 2, with a resolution of 1000x1000, run at 200 max iterations per pixel, and c = -0.4 + 0.6i.

To create a Mandelbrot set plot, run:
```bash
./mandelbrot.sh 0.0 0.0 2.0 1000 200
```

This will create an output png centered at (0.0,0.0) with a radius of 2, with a resolution of 1000x1000, and run at 200 max iterations per pixel.

You can change the color map in display.py.

Requiers numpy and matplotlib.

![mandelbrot](resources/mandelbrot0.png)
![mandelbrot](resources/mandelbrot1.png)
![mandelbrot](resources/mandelbrot2.png)
![julia](resources/julia.png)