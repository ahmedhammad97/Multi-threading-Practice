#include <iostream>
#include <vector>
#include <fstream>
#include <thread>
#include <cmath>

using namespace std;

/**
Coded by : Ahmed Hammad
All copyrights reserved
**/

void readInput(vector<int>& arr){
    ifstream inFile;
    inFile.open("input.txt");
    int n;
    inFile >> n;

    for(int i=0; i<n; i++){
        int temp;
        inFile >> temp;
        arr.push_back(temp);
    }

    inFile.close();
}

void merge(vector<int>& arr, int start, int middle, int end){
    vector<int> temp;
    int i=start, j=middle+1;

    while(i <= middle && j <= end){
        if(arr[i]<arr[j]){
            temp.push_back(arr[i++]);
        }
        else{
            temp.push_back(arr[j++]);
        }
    }

    while(i <= middle){
        temp.push_back(arr[i++]);
    }

    while(j <= end){
        temp.push_back(arr[j++]);
    }

    for(int i=0; i<temp.size(); i++){
        arr[start+i] = temp[i];
    }
}

void mergeSort(vector<int>& arr, int start, int end){
    if(end>start){

        thread t1{[&](){mergeSort(arr, start, (start+end)/2);}};

        thread t2{[&](){mergeSort(arr, ((start+end)/2)+1, end);}};

        t1.join();
        t2.join();

        merge(arr, start, (start+end)/2, end);
    }
}


void printArray(vector<int>& arr){
    for(auto& num : arr){
        cout<<num<<" ";
    }
    cout<<"\n";
}

int main()
{
    vector<int> arr;
    readInput(arr);
    mergeSort(arr, 0, arr.size()-1);
    printArray(arr);
    return 0;
}
