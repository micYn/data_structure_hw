//Author:B103040009尹信淳
//Date:2022/11/19
//Purpose:測試五種排序(sorting)演算法的執行效率
#include <iostream>
#include <iomanip>
#include <fstream>
#include <time.h>
#include <ctime>
#include <cstdlib>
#include <algorithm>
using namespace std;

//Insertion Sort 函式
void insertionSort(int arr[], int n){
    int i, key, j;
    for (i = 1; i < n; i++){
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
///////////////////////////////////////////////////////////////////////////////////
void merge(int array[], int const left, int const mid,int const right){
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;

    auto *leftArray = new int[subArrayOne], *rightArray = new int[subArrayTwo];

    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];

    auto indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;

    while(indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo){
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]){
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else{
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    while (indexOfSubArrayOne < subArrayOne){
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;   indexOfMergedArray++;
    }

    while(indexOfSubArrayTwo < subArrayTwo){
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;   indexOfMergedArray++;
    }
    delete[] leftArray; delete[] rightArray;
}
//Merge Sort 函式 會用到 merge
void mergeSort(int array[], int const begin, int const end){
    if (begin >= end)   return; // Returns recursively
    auto mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}
//////////////////////////////////////////////////////////////////////////////
void swap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
}
int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
//Quick Sort 函式 會用到 swap 跟 partition
void quickSort(int arr[], int low, int high){
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
// C qsort() 參數會用到的compare函數
int compare (const void * a, const void * b){return ( *(int*)a - *(int*)b );}
//產生亂數的函式
void randnum(int* arr,int size){
    for(int i=0;i<size;i++)
        arr[i] = rand()%500000+1;
}
int main(){
    srand(time(NULL));  //亂數種子
    ifstream in;
    ofstream os;

    in.open("input.txt");   //開檔並讀入資料
    int arrsize;
    in>>arrsize;
    int arr[arrsize];

    ////////////////////////////////
    //Insertion Sort 測試
    os.open("outputA.txt");
    int i=0;
    while(in>>arr[i++]){}
    os<<"Insertion Sort"<<endl;
    insertionSort(arr,arrsize);
    for(int i=0;i<arrsize;i++)
        os<<arr[i]<<endl;
    os.close();
    /////////////////////////////////
    //Merge Sort 測試
    os.open("outputB.txt");
    in>>arrsize;
    i=0;
    while(in>>arr[i++]){}
    os<<"Merge Sort"<<endl;
    mergeSort(arr,0,arrsize-1);
    for(int i=0;i<arrsize;i++)
        os<<arr[i]<<endl;
    os.close();
    /////////////////////////////////
    //Quick Sort 測試
    os.open("outputC.txt");
    in>>arrsize;
    i=0;
    while(in>>arr[i++]){}
    os<<"Quick Sort"<<endl;
    quickSort(arr,0,arrsize-1);
    for(int i=0;i<arrsize;i++)
        os<<arr[i]<<endl;
    os.close();
    ////////////////////////////////
    //C qsort() 測試
    os.open("outputD.txt");
    in>>arrsize;
    i=0;
    while(in>>arr[i++]){}
    os<<"C qsort()"<<endl;
    qsort(arr,arrsize,sizeof(int),compare);
    for(int i=0;i<arrsize;i++)
        os<<arr[i]<<endl;
    os.close();
    ///////////////////////////////////
    //C++ sort() 測試
    os.open("outputE.txt");
    in>>arrsize;
    i=0;
    while(in>>arr[i++]){}
    os<<"C++ sort()"<<endl;
    sort(arr,arr+arrsize,less<int>());
    for(int i=0;i<arrsize;i++)
        os<<arr[i]<<endl;
    os.close();
    /////////////////////////////////////

    in.close(); //關閉檔案指標


    return 0;
}
