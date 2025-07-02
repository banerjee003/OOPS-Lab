#include<iostream>
#include<algorithm>
using namespace std;

template<class T>
class Sorter{
  public:
   void sortArray(T arr[], int size){
    sort(arr, arr + size);
   }
   void displayArray(T arr[], int size){
       for(int i=0; i<size;i++){
        cout<<arr[i]<<" ";
        
       }
   }
};

int main(){
  Sorter<int>intSort;
  int arr[]={2,5,4,3};
  cout<<"Before sorting(int)\n";

  intSort.displayArray(arr, 4);
  intSort.sortArray(arr, 4);

  cout<<"\nAfter sorting(int)\n";
  intSort.displayArray(arr, 4);

  Sorter<float>floatSort;
  float arr1[]={1.5,5.56,5.20,3.21};
  cout<<"\n\nBefore sorting(float)\n";

  floatSort.displayArray(arr1, 4);
  floatSort.sortArray(arr1, 4);
  cout<<"\nAfter sorting(float)\n";

  floatSort.displayArray(arr1, 4);

  Sorter<char>charSort;
  char arr2[]={'c','a','m','t'};
  cout<<"\n\nBefore sorting(char)\n";

  charSort.displayArray(arr2, 4);
  charSort.sortArray(arr2, 4);
  cout<<"\nAfter sorting(char)\n";

  charSort.displayArray(arr2, 4);
  return 0;
}
