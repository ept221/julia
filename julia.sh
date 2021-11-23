./bin/julia $1 $2 $3 $4 $5 $6 $7 | python3 scripts/display.py julia $4
mkdir -p pics
mv julia.png pics/julia.png
open pics/julia.png