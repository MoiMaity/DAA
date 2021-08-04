#include<stdio.h>

void swap (int *xp, int *yp)
{
  int temp = *xp;
  *xp = *yp;
  *yp = temp;
}

void bsort (int f[], int s[], int a[], int n)
{
  int i, j, b;
  for (i = 0; i < n; i++)
    {
      b = 0;
      for (j = 1; j < n; j++)
	{
	  if (f[b] > f[j])
	    {
	      swap (&f[b], &f[j]);
	      swap (&s[b], &s[j]);
	      swap (&a[b], &a[j]);
	      b++;
	    }
	  else
	    {
	      b++;
	    }
	}
    }
}

void main ()
{
  printf (">>> Activity Selection Problem <<<");
  printf ("\n\n");

  int s[50], f[50], i, n, act[50];


  printf ("Enter number of activity: ");
  scanf ("%d", &n);
  printf ("\n");
  for (i = 0; i < n; i++)
    {
      printf ("Enter the Starting Time of Activity A%d : ", i + 1);
      scanf ("%d", &s[i]);
      printf ("Enter the Finishing Time of Activity A%d : ", i + 1);
      scanf ("%d", &f[i]);
      printf ("\n");
    }

  for (i = 0; i < n; i++)
    {
      act[i] = i + 1;
    }

  printf ("\nUser Input : \n");
  for (i = 0; i < n; i++)
    {
      printf ("Activity: A%d  -> Starting Time: %d -> Finishing Time: %d\n",
	      act[i], s[i], f[i]);
    }
  printf ("\n");

  bsort (f, s, act, n);

  printf ("\nAfter sorting fi : \n");
  for (i = 0; i < n; i++)
    {
      printf ("Activity: A%d  -> Starting Time: %d -> Finishing Time: %d\n",
	      act[i], s[i], f[i]);
    }
  printf ("\n");

  int fa[20], fs[20], ff[20], l = 0;

  fa[l] = act[0];
  fs[l] = s[0];
  ff[l] = f[0];

  int k = 0;
  for (i = 1; i < n; i++)
    {
      if (f[k] <= s[i])
	{
	  l = l + 1;
	  fa[l] = act[i];
	  fs[l] = s[i];
	  ff[l] = f[i];
	  k = i;
	}
    }


  printf ("\nResult : \n");
  for (i = 0; i <= l; i++)
    {
      printf ("Activity: A%d  -> Starting Time: %d -> Finishing Time: %d\n",
	      fa[i], fs[i], ff[i]);
    }
  printf ("\n");


  	printf("\nResult: \n");
	
	printf("Activity      Starting time       Finishing time     \n");
	printf("------------------------------------------------------\n");
	for(i=0; i<=l ; i++){
	printf("  A%d              %d                    %d           \n",fa[i],fs[i],ff[i]);}
	printf("------------------------------------------------------\n");
	printf("\n");
    printf("Bye Bye!! :)");
}

