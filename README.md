# Counting-Blobs
This code counts blobs in a matrix which is filled with ones and zeros and counts the blobs (or clusters) of ones in the matrix.

<fname> File name for the grid of cells
<M>     Number of rows in the grid
<N>     Number of columns in the grid
<CONN>  Connection type. Can be either `4` or `8`

Where 2 <= M,N <= 100, 4 or 8 is what you consider a blob, 8 cells or 4 cells. The matrix would be inputted as a file.

An example would be 

0 0 0 1 1 1 0 0

0 0 0 1 1 1 0 0

0 0 0 1 1 1 0 0

1 1 1 0 0 0 0 0

1 1 1 0 0 0 0 0

0 0 0 1 1 1 0 0

1 1 0 1 1 1 0 0

1 1 0 1 1 1 0 0


./blobs grid.txt 8 8 4

4

$ ./blobs grid.txt 8 8 8

2

This code was part of a homework assignment for the Data Structures and Abstractions available at my school
