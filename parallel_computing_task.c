#include <stdio.h> 
#include <omp.h>

int min(int a, int b, int c)    //to find the minimum of 3 numbers
{ 
    int m = a; 
    if (m > b)  
        m = b; 
    if (m > c)  
        m = c; 
    return m; 
} 


int main() 
{ 
	
    int R,C,i,j,max;    //R=number of rows   C=number of columns
    printf("Enter the number of rows in the matrix\n");
    scanf("%d",&R);
    printf("Enter the number of columns in the matrix\n");
    scanf("%d",&C);

    int M[R][C],S[R][C];   //M=matrix S=new matrix    
   
    printf("Enter the elements of the matrix which can either be zero or one\n");

    for(i=0;i<R;i++)
    {
        for(j=0;j<C;j++)
        {
            scanf("%d",&M[i][j]);
            S[i][j]=M[i][j];
        }
    }

    max = S[0][0];     //we will use max later to store the maximum element in matrix S
    
        //parallel code starts here

            #pragma omp parallel for schedule(static,((R*C)/omp_get_num_threads())) 
                for(int k=1;k<R;k++)
                {
                    for(int l=1;l<C;l++)
                    {

                        if(M[k][l] == 1)
                        {
                                S[k][l] = min(S[k][l-1], S[k-1][l], S[k-1][l-1])+1; 
                        
                        }
                        else
                            S[k][l]= 0;

                            if(max < S[k][l]) 
                                max = S[k][l];    
                    }
                }

//Adding a comment as a part of edit 1
// we consider every element as the bottom right element of a 2x2 matrix(and perform the above operation)

    printf("The area of the largest submatrix containing only ones is %d\n",max*max);    
    return 0;
  }
