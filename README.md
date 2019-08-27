The parallel_computing_task.c file is a parallelised version of the program to print the area of the largest submatrix containing only 1s from a given binary matrix.

The program uses OpenMP library constructs.

If you do not have the OpenMP library pre-installed then use the following command line on the terminal(for Linux users)
                      sudo apt-get install libomp-dev

To compile the program on a terminal the required command line is:  
                      gcc -fopenmp parallel_computing_task.c
                       
To run the program after compilation, enter:
                      ./a.out  
