set yrange [0:10]
set xlabel "Input"
set ylabel "output"
set term png
set output "Bsearch.png"
plot "bsb.txt" w l ti "Best case","bsavg.txt" w l ti "Average case","bsw.txt" w l ti "worst case"
set term x11