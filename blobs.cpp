#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
class Cellgrid {
    private:

        int rows, cols;

        bool *grid;

    public:

        int countCells4(int row, int col,int&counter);
        int countCells8(int row, int col, int&counter);
        void CountCells(int startRow, int startCol, int conn,int holder);
        Cellgrid(const char *fname, int m, int n);
        int countBlobs(int conn);

        ~Cellgrid();

        void print();
};
Cellgrid::Cellgrid(const char *fname, int m, int n) {

    rows = m;
    cols = n;


    grid = new bool[rows*cols];

    ifstream infile;


    infile.open(fname);


    for(int i = 0; i < rows; i++) {

        int base = i * cols;
        for(int offset = 0; offset < cols; offset++) {

            infile >> grid[base + offset];
        }
    }


    infile.close();
}

// destruct object where not implicit to the program
Cellgrid::~Cellgrid() {

    delete[] grid;
}

void Cellgrid::CountCells(int startRow, int startCol, int conn, int holder)
{
   // int counter = 0;
   //Cellgrid::print();
    if (conn == 4)
    {
        Cellgrid::countCells4( startRow,  startCol , holder);

    }
    else if(conn == 8)
    {

        Cellgrid::countCells8(startRow,  startCol , holder);
    }
   // Cellgrid::print();
}

int Cellgrid::countCells4(int row, int col, int& counter)
{
    if((grid[row * rows + col] != 1) || row < 0 || col < 0 || row >= rows || col >= cols)
    {
        return 0;
    }
    //std::cout << row << " " << col << "\n";
    //std::cout << grid[row * rows + col];
    counter += 1;
       // std::cout << counter << " " ;
     //std::cout << grid[row * rows + col] << " " << row << " " << col  << "\n";
        grid[row * rows + col] = 0;
        //std::cout << counter;
        return 0 + countCells4(row + 1, col,counter) + countCells4(row - 1, col ,counter) + countCells4(row, col + 1,counter ) + countCells4(row, col - 1,counter);


}
int Cellgrid::countCells8(int row, int col, int& counter)
{

    if(row < 0 || col < 0 || row >= rows || col >= cols || grid[row * cols + col] != 1)
    {
        return 0;
    }


        grid[row * cols + col] = 0;
        counter ++;

        return 0 + countCells8(row + 1, col,counter) + countCells8(row - 1, col,counter) + countCells8(row, col + 1,counter) + countCells8(row, col - 1,counter) +  countCells8(row + 1, col + 1,counter) + countCells8(row + 1, col - 1,counter) + countCells8(row - 1, col + 1,counter) + countCells8(row - 1, col - 1,counter);


}


int Cellgrid::countBlobs(int conn)
{
    int counter = 0;
    int holder = 0;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if(grid[i * cols + j] == 1)
                {
                 //   int holder = i *cols;
                  counter++;
                     if (conn == 4)
    {
       countCells4( i,  j , holder);

    }
    else if(conn == 8)
    {

        countCells8(i,  j , holder);
    }
                }
            }
        }


    return counter;
}


void Cellgrid::print() {
    for(int i = 0; i < rows; i++) {
        int base = i * cols;
        std::cout << grid[base];
        for(int offset = 1; offset < cols; offset++) {
            std::cout << ' ' << grid[base + offset];
        }
        std::cout << std::endl;
    }
}

int main(int argc, char *argv[]) {

    int rows,cols,startRow, startCol, conn;


    char *fname = argv[1];


    rows = atoi(argv[2]); // number of rows in grid
    cols = atoi(argv[3]); // number of cols in grid
    conn = atoi(argv[4]); // connection type


    Cellgrid myGrid(fname, rows, cols);
    //std::cout << conn;
   std::cout << myGrid.countBlobs(conn) << "\n";
   // myGrid.print();

}


/*
<fname> File name for the grid of cells
<M>     Number of rows in the grid
<N>     Number of columns in the grid
<CONN>  Connection type. Can be either `4` or `8`

*/
