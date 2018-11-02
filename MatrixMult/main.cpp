#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>

using namespace std;

void readInput(vector<vector<int>>& m1, vector<vector<int>>& m2){
    ifstream inFile;
    inFile.open("input.txt");
    int rows, cols;
    int temp;

    /** Start m1 code **/
    //Reading Rows And Cols
    inFile >> temp;
    rows = temp;
    inFile >> temp;
    cols = temp;

    //Storing Data to Matrix m1
    for(int i=0; i<rows; i++){
        vector<int> tempRow;
        for(int k=0; k<cols; k++){
            inFile >> temp;
            tempRow.push_back(temp);
        }
        m1.push_back(tempRow);
    }
    /** End m1 parsing **/


    /** Start m2 parsing **/
    //Reading Rows and Cols
    inFile >> temp;
    rows = temp;
    inFile >> temp;
    cols = temp;

    //Storing data to Matrix m2
    for(int i=0; i<rows; i++){
        vector<int> tempRow;
        for(int k=0; k<cols; k++){
            inFile >> temp;
            tempRow.push_back(temp);
        }
        m2.push_back(tempRow);
    }
    /** End m2 parsing **/


    inFile.close();
}


void matrixMultiplyByElement(vector<vector<int>>& m1, vector<vector<int>>& m2, vector<vector<int>>& result){

}


void matrixMultiplyByElement(vector<vector<int>>& m1, vector<vector<int>>& m2, vector<vector<int>>& result){

}


void writeOutput(vector<vector<int>>& result1, elapsed1, vector<vector<int>>& result2, elapsed2){
    ofstream outFile;
    outFile.open("output.txt");

    /** Start Writing result1 **/
    for(int i=0; i<result1.size(); i++){
        for(int k=0; k<result1[0].size(); k++){
            outFile << result1[i][k] << " ";
        }
        outFile << "\n";
    }
    outFile << "END1\t\t" << elapsed1 <<endl;
    /** End Writing result1 **/


    /** Start Writing result2 **/
    for(int i=0; i<result2.size(); i++){
        for(int k=0; k<result2[0].size(); k++){
            outFile << result2[i][k] << " ";
        }
        outFile << "\n";
    }
    outFile << "END2\t\t" << elapsed2 <<endl;
    /** End Writing result2 **/


    outFile.close();
}

int main()
{
    vector<vector<int>> m1, m2;

    //Read Input
    readInput(m1,m2);

    //Do Multiplication
    vector<vector<int> result1;
    vector<vector<int> result2;

    time_t elapsed1 = time(NULL);
    matrixMultiplyByElement(m1, m2, result1);
    elapsed1 = time(NULL) - elapsed1;

    time_t elapsed2 = time(NULL);
    matrixMultiplyByRow(m1, m2m result2);
    elapsed2 = time(NULL) - elapsed2;

    //Write Output
    writeOutput(result1, elapsed1, result2, elapsed2);
    return 0;
}
