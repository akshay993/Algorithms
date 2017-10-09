//Implementation of quicksort for an unsorted array in C Language
//In this, we take pivot as the last element of the array

#include<stdio.h>
#include<stdlib.h>


void swap(int *x, int *y)
{
  int temp;
  temp=*x;
  *x=*y;
  *y=temp;
}

int partition (int *a,int p,int r)
{
  int x=a[r]; //Here, we take pivot as the last element of the array
  int i=p-1;

  for(int j=p;j<r; j++)
  {
    if(a[j]<=x)
    {
      i++;
      swap(&a[i],&a[j]);
    }
  }
  swap(&a[i+1],&a[r]);
  return i+1;
}



void quicksort(int *a,int p,int  r)
{
  int q=0;
  if(p<r)
   {

    //partition function will return the correct position
    //of the pivot element in the sorted array
     q=partition(a,p,r);

     quicksort(a,p,q-1);
     quicksort(a,q+1,r);
   }

}

int main()
{
  int n;
  int *a;

  printf("Enter the number of elements you want in the array: ");
  scanf("%d",&n);

  a=(int*)malloc(n*sizeof(int));

  printf("\nEnter %d elements in the array",n);
  for(int i=0;i<n;i++)
  {
    scanf("%d",&a[i]);

  }

  //Now we apply quick sort on this array
  quicksort(a,0,n-1);

 //Now, we print the sorted array
  printf("\nThe Sorted Array is as follows: \n");
  for(int i=0;i<n;i++)
  {
   printf("%d\n",a[i]);
 }
  return 0;
}
