#include <iostream>
#include <thread>

using namespace std;

void readInput(vector<int>>& arr){
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

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
