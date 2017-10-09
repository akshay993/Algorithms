//Program to Implement Binary Search in C
//Element to be entered must be in sorted order

#include<stdio.h>
#include<stdlib.h>

int binsearch(int *a, int x, int p, int r)
{
  int q;

  if(p==r)
  {
    if(a[p]==x)
     return p;
  }

 else
 {
  q=p+(r-1)/2;

  if(a[q]==x)
    return q;

  if(a[q]>x)
    return binsearch(a,x,p,q-1);

  if(a[q]<x)
    return binsearch(a,x,q+1,r);
 }

  return -1;

}



int main()
{
 int *a;
 int n;
 int position, x;


 printf("\nEnter the number of elements you want in the array:\t");
 scanf("%d",&n);

 a=(int*)malloc(n*(sizeof(int)));

 printf("\nEnter the %d elements (sorted order)\n",n);
 for(int i=0;i<n;i++)
 {
  scanf("%d",&a[i]);
 }

  printf("\nEnter the element you want to search:\t");
  scanf("%d",&x);

 //Now, We will search X in the array using binary Search
 position=binsearch(a, x, 0, n-1);

 if(position ==-1)
  printf("\nElement not found\n");

  else
    printf("\n%d found in the array at position : %d\n",x,position+1);

 return 0;
}
