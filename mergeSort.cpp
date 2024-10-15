#include <iostream>
using namespace std;

void merge(int* inputArray, int lStartIndex, int lEndIndex, int rStartIndex, int rEndIndex, int length){
    int* newArray = new int[length];
    int lPointer = lStartIndex;
    int rPointer = rStartIndex;
    int mainPointer = 0;
    while((lPointer < lEndIndex) && (rPointer < rEndIndex)){
        if(inputArray[lPointer] < inputArray[rPointer]){
            newArray[mainPointer] = inputArray[lPointer];
            lPointer++;
        }
        else{
            newArray[mainPointer] = inputArray[rPointer];
            rPointer++;
        }
        if((lPointer < lEndIndex)){
            while(lPointer < lEndIndex){
                newArray[mainPointer] = inputArray[lPointer];
                lPointer++;
            }
        }
        else{
            newArray[mainPointer] = inputArray[rPointer];
            rPointer++;
        }
        mainPointer++;
    }

    for(int i = 0; i < 5; i++){
        cout << newArray[i] << " ";
    }
    cout << endl;
    inputArray = newArray;
}

void mergeSort(int* inputArray, int startIndex, int endIndex){
    int length = endIndex - startIndex + 1;
    cout << "Start Index: " << startIndex << ", End Index: " << endIndex << endl;
    if(length <= 1){
        return;
    }

    int mid = (endIndex - startIndex) / 2;
    mergeSort(inputArray, startIndex, mid);
    mergeSort(inputArray, mid + 1, endIndex);
    merge(inputArray, startIndex, mid, mid + 1, endIndex, length);

}

int main(){
    int passedArray[] = {5, 4, 3, 2, 1};
    mergeSort(passedArray, 0, 4);
    for(int i = 0; i < 5; i++){
        cout << passedArray[i] << endl;
    }
}