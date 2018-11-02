#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <thread>

using namespace std;
using namespace std::chrono;

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


void initializeWithZeros(vector<vector<int>>& matrix, int rows, int cols){
    for(int i=0; i<rows; i++){
        vector<int> tempRow;
        for(int k=0; k<cols; k++){
            tempRow.push_back(0);
        }
        matrix.push_back(tempRow);
    }
}


void matrixMultiplyByElement(vector<vector<int>>& m1, vector<vector<int>>& m2, vector<vector<int>>& result){
    //Initialize result with zeros
    initializeWithZeros(result, m1.size(), m2[0].size());
    vector<thread> threads(m1.size() * m2[0].size());

    int t=0;
    for(int i=0; i<m1.size(); i++){
        for(int j=0; j<m2[0].size(); j++){
            threads[t] = thread{[&](){
                for(int k=0; k<m1[0].size(); k++){
                    result[i][j] += m1[i][k] * m2[k][j];
                }
            }};
            threads[t].join();
            t++;
        }
    }
}


void matrixMultiplyByRow(vector<vector<int>>& m1, vector<vector<int>>& m2, vector<vector<int>>& result){
    //Initialize result with zeros
    initializeWithZeros(result, m1.size(), m2[0].size());
    vector<thread> threads(m1.size() * m2[0].size());

    int t=0;
    for(int i=0; i<m1.size(); i++){
        threads[t] = thread{[&](){
            for(int j=0; j<m2[0].size(); j++){
                for(int k=0; k<m1[0].size(); k++){
                    result[i][j] += m1[i][k] * m2[k][j];
                }
            }
        }};
        threads[t].join();
        t++;
    }
}


void writeOutput(vector<vector<int>>& result1, auto elapsed1, vector<vector<int>>& result2, auto elapsed2){
    ofstream outFile;
    outFile.open("output.txt");

    /** Start Writing result1 **/
    for(int i=0; i<result1.size(); i++){
        for(int k=0; k<result1[0].size(); k++){
            outFile << result1[i][k] << " ";
        }
        outFile << "\n";
    }
    outFile << "END1\t\t" << elapsed1 << " microseconds"<<endl;
    /** End Writing result1 **/


    /** Start Writing result2 **/
    for(int i=0; i<result2.size(); i++){
        for(int k=0; k<result2[0].size(); k++){
            outFile << result2[i][k] << " ";
        }
        outFile << "\n";
    }
    outFile << "END2\t\t" << elapsed2 << " microseconds"<<endl;
    /** End Writing result2 **/


    outFile.close();
}

int main()
{
    vector<vector<int>> m1, m2;

    //Read Input
    readInput(m1,m2);

    //Do Multiplication
    vector<vector<int>> result1;
    vector<vector<int>> result2;

    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    matrixMultiplyByElement(m1, m2, result1);
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    auto elapsed1 = duration_cast<microseconds>( t2 - t1 ).count();

    t1 = high_resolution_clock::now();
    matrixMultiplyByRow(m1, m2, result2);
    t2 = high_resolution_clock::now();
    auto elapsed2 = duration_cast<microseconds>( t2 - t1 ).count();

    //Write Output
    writeOutput(result1, elapsed1, result2, elapsed2);
    return 0;
}
