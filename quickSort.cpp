
#include <iostream>
#include <vector>
using namespace std;

void partition(int Arr[], int l, int r, int *smallerIndex, int *largerIndex)
{
  int pivot = Arr[l]; //using most left elment as pivot
  int lastLeft = l;   //expand  smaller elements at the left side
  int lastRight = r;  //expand  larger elments at the right side
  int temp = 0;
  int i = l;
  while (i <= lastRight)
  {
    if (Arr[i] < pivot)
    {
      lastLeft++;
      //swap
      temp = Arr[i];
      Arr[i] = Arr[lastLeft];
      Arr[lastLeft] = temp;
      i++;
    }
    else if (Arr[i] > pivot)
    {
      //swap
      temp = Arr[i];
      Arr[i] = Arr[lastRight];
      Arr[lastRight] = temp;
      lastRight--;
    }
    else
    {
      i++;
    }
  }

  Arr[l] = Arr[lastLeft];
  Arr[lastLeft] = pivot;
  *smallerIndex = lastLeft;
  *largerIndex = lastRight;
}
void quickSort(int Arr[], int l, int r)
{

  int smallerIndex;
  int largerIndex;
  if (l >= r)
  {
    return;
  }
  //using random pivot
  int k = l + rand() % (r - l + 1);
  int temp = Arr[l];
  Arr[l] = Arr[k];
  Arr[k] = temp;
  partition(Arr, l, r, &smallerIndex, &largerIndex);
  quickSort(Arr, l, smallerIndex - 1);
  quickSort(Arr, largerIndex + 1, r);
}

int main()
{

  int n;
  cin >> n;
  int *arr = (int *)malloc(n * sizeof(int));
  ;
  for (size_t i = 0; i < n; ++i)
  {
    std::cin >> arr[i];
  }
  quickSort(arr, 0, n - 1);
  for (size_t i = 0; i < n; ++i)
  {
    std::cout << arr[i] << ' ';
  }
  return 0;
}
