./bin/mandelbrot $1 $2 $3 $4 $5 | python3 scripts/display.py mandelbrot $4
mkdir -p pics
mv mandelbrot.png pics/mandelbrot.png
open pics/mandelbrot.png