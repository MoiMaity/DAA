#include<stdio.h>
#include<conio.h>

int i,j;

void dec_ratio(float q[],float p[],float r[],int n)
{
    float t1,t2,t3;
    for(i=0;i<n;i++)
    {
		for(j=0;j<n;j++)
		{
			if(r[i]>r[j])
			{
				t1=r[i];
				r[i]=r[j];
				r[j]=t1;
				t2=q[i];
				q[i]=q[j];
				q[j]=t2;
				t3=p[i];
				p[i]=p[j];
				p[j]=t3;
			}
		}
   	}
}

void dec_profit(float q[],float p[],float r[],int n)
{
    float t1,t2,t3;
    for(i=0;i<n;i++)
    {
		for(j=0;j<n;j++)
		{
			if(p[i]>p[j])
			{
				t1=r[i];
				r[i]=r[j];
				r[j]=t1;
				t2=q[i];
				q[i]=q[j];
				q[j]=t2;
				t3=p[i];
				p[i]=p[j];
				p[j]=t3;
			}
		}
   	}
}

void asc_weight(float q[],float p[],float r[],int n)
{
    float t1,t2,t3;
   	for(i=0;i<n;i++)
   	{
		for(j=0;j < n;j++)
		{
			if(q[i] < q[j])
			{
				t1=r[i];
				r[i]=r[j];
				r[j]=t1;
				t2=q[i];
				q[i]=q[j];
				q[j]=t2;
				t3=p[i];
				p[i]=p[j];
				p[j]=t3;
			}
		}
   	}
}

void knapsack(float capacity,int n,float q[],float p[],float r[])
{
    float ks[n];
    int ch=0;
    float fc;
    while(ch!=4)
    {
    	printf("\n");
 		printf("1. Press 1 to do by Profit.\n2. Press 2 to do by Weight.\n3. Press 3 to do by Ratio\n\n");
  		printf("Enter your Choice :");
    	scanf("%d",&ch);
    	printf("----------------------------------------\n");
    	if(ch==1)
    	{
        	float pr=0.0;
        	dec_profit(q,p,r,n);
        	fc=capacity;
        	for(i=0;(i<n)&&(fc>0);++i)
        	{
            	if(q[i]<fc)
            	{
                	ks[i]=1;
                	fc=fc-q[i];
                	pr=pr+p[i];
            	}	
            	else
           		{
                	ks[i]=fc/q[i];
                	pr=pr+(p[i]*(fc/q[i]));
                	fc=0;
            	}
        	}
        	printf("Max Profit is =%f\n",pr);
        	printf("Solution Vector is :");
        	for(i=0;i<n;i++)
    		{
    	    	printf("%f ",ks[i]);
    		}
    		printf("\n\n");
   		}1
    	else if(ch==2)
    	{
        	float pr=0.0;
        	asc_weight(q,p,r,n);
        	fc=capacity;
        	for(i=0;(i<n)&&(fc>0);++i)
       		{
            	if(q[i]<fc)
            	{
                	ks[i]=1;
                	fc=fc-q[i];
                	pr=pr+p[i];
            	}
            	else
            	{
                	ks[i]=fc/q[i];
                	pr=pr+(p[i]*(fc/q[i]));
                	fc=0;
            	}
        	}
        	printf("Max Profit=%f\n",pr);
        	printf("Solution Vector is :");
        	for(i=0;i<n;i++)
    		{
    	    	printf("%f",ks[i]);
    		}
    		printf("\n\n");
    	}
    	else if(ch==3)
    	{
        	float pr=0.0;
        	dec_ratio(q,p,r,n);
        	fc=capacity;
        	for(i=0;(i<n)&&(fc>0);i++)
        	{
            	if(q[i]<fc)
            	{
                	ks[i]=1;
                	pr=pr+p[i];
                	fc=fc-q[i];
            	}
            	else
            	{
                	ks[i]=fc/q[i];
                	pr=pr+(p[i]*(fc/q[i]));
                	fc=0;
            	}
        	}
        	printf("Max Profit is=%f\n",pr);
        	printf("Solution Vector is :");
        	for(i=0;i<n;i++)
    		{
    	    	printf("%f ",ks[i]);
    		}
    		printf("\n\n");
    	}
    	else
    	{
        	break;
    	}
    }
}

void main()
{
    int n;
    printf("Enter number of objects:  ");
	scanf("%d", &n);
	float q[n],p[n],r[n];
	float capacity;
	printf("Enter the capacity of knapsack: ");
	scanf("%f", &capacity);
	printf("\n\n");
	for(i=0;i<n;i++)
	{
		printf("%dth Profit:", (i+1));
		scanf("%f", &p[i]);
		printf("%dth Weight: ", (i+1));
		scanf("%f", &q[i]);
		printf("\n\n");
		r[i]=p[i]/q[i];
	}
	knapsack(capacity,n,q,p,r);
	getch();
}

