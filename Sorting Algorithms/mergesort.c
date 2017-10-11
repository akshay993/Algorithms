//Merge Sort implementation in C

#include<stdio.h>
#include<stdlib.h>


void merge(int *a, int p, int q, int r)
{
  int n1=q-p+1;
  int n2=r-q;
  int i=0;
  int j=0;
  int k=0;

  int arr1[n1];
  int arr2[n2];

  for (i = 0;i < n1;i++)
      arr1[i] = a[p + i];
  for (j = 0;j < n2;j++)
      arr2[j] = a[q + 1+ j];

  i=0;
  j=0;

  while(i<n1 && j<n2)
  {
      if(arr1[i]<=arr2[j])
      {
        a[k]=arr1[i];
        i++;
      }
      if(arr2[j]< arr1[i])
      {
        a[k]=arr2[j];
        j++;
      }

      k++;
  }

  while(i<n1)
  {
    a[k]=arr1[i];
    i++;
    k++;
  }

  while(j<n2)
  {
    a[k]=arr2[j];
    j++;
    k++;
  }

}



void mergesort1(int *a, int p, int r)
{
  int q;
  if(p<r)
  {
    q=p+(r-1)/2;

    mergesort1(a, p, q);
    mergesort1(a, q+1, r);
    merge(a, p, q, r);
  }

}


int main()
{
  int *a;
  int n;
  printf("Enter the number of elements in the array: ");
  scanf("%d",&n);
  a=(int*)malloc(n*(sizeof(n)));
  printf("\nEnter the %d elements in the array: ",n);
  for(int i=0;i<n;i++)
  {
    scanf("%d",&a[i]);
  }

  //Now, we will sort the array using merge sort
  mergesort1(a, 0, n-1);


  //Now, We print the sorted array
  printf("The sorted array is: \n");
  for(int i=0;i<n;i++)
    printf("%d\n",a[i]);

    return 0;

}
