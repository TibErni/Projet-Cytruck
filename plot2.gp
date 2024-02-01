### horizontal bar graph
reset session
DATA_FILE="distances.txt"


set terminal png size 800,600;
set output 'D2.png';
set yrange [0:*]      # start at zero, find max from the data
set style fill solid  # solid color boxes
unset key             # turn off all titles

myBoxWidth = 0.8
set offsets 0,0,0.5-myBoxWidth/2.,0.5

plot "distances.txt" using (0.5*$1):0:(0.5*$1):(myBoxWidth/2.):($0+1):yticlabels( stringcolumn(2).'  '.stringcolumn(3) ) with boxxy lc var
### end of script




