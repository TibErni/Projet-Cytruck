### horizontal bar graph
reset session
DATA_FILE="top_conducteurs.txt"


set terminal png size 800,600;
set output 'D1.png';
set yrange [0:*]      # start at zero, find max from the data
set style fill solid 1.0 border -1;
set boxwidth 7500;
set xlabel 'NB ROUTES';
set ylabel 'Drivers Names';
set title 'Options -d1 : Nb routes =f(Driver)';

myBoxWidth = 0.8
set offsets 0,0,0.5-myBoxWidth/2.,0.5

plot "top_conducteurs.txt" using (0.5*$1):0:(0.5*$1):(myBoxWidth/2.):($0+1):yticlabels( stringcolumn(2).'  '.stringcolumn(3) ) with boxxy lc var

### end of script


