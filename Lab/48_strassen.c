#include<stdio.h>

void main()
{
	int a[100][100], b[100][100], c[100][100], i, j, n;
	int p, q, r, s, t, u, v;
 
 	printf("Enter the no. of rows and columns: ");
 	scanf("%d", &n);
 	
	printf("\nEnter the elements of first matrix: ");
  	for(i = 0;i < n; i++)
    	for(j = 0;j < n; j++)
        	scanf("%d", &a[i][j]);
 
  	printf("\nEnter the elements of second matrix: ");
  	for(i = 0; i < n; i++)
    	for(j = 0;j < n; j++)
        	scanf("%d", &b[i][j]);
 
  	printf("\n\nThe first matrix is: \n");
  	for(i = 0; i < 2; i++)
	{
    	printf("\n");
    	for(j = 0; j < 2; j++)
        	printf("%d\t", a[i][j]);
  	}
 
  	printf("\n\nThe second matrix is: \n");
  	for(i = 0;i < 2; i++)
	{
    	printf("\n");
    	for(j = 0;j < 2; j++)
           printf("%d\t", b[i][j]);
  	}
 
  	p= (a[0][0] + a[1][1]) * (b[0][0] + b[1][1]);
  	q= (a[1][0] + a[1][1]) * b[0][0];
  	r= a[0][0] * (b[0][1] - b[1][1]);
  	s= a[1][1] * (b[1][0] - b[0][0]);
  	t= (a[0][0] + a[0][1]) * b[1][1];
  	u= (a[1][0] - a[0][0]) * (b[0][0]+b[0][1]);
  	v= (a[0][1] - a[1][1]) * (b[1][0]+b[1][1]);
 
  	c[0][0] = p + s- t + v;
  	c[0][1] = r + t;
  	c[1][0] = q + s;
  	c[1][1] = p - q + r + u;
 
   	printf("\n\nAfter multiplication using Strassen's algorithm: \n");
   	for(i = 0; i < 2 ; i++)
	{
    	printf("\n");
    	for(j = 0;j < 2; j++)
           printf("%d\t", c[i][j]);
   	}
   	getch();
}
