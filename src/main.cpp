#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main(int argc, char* argv[])
{
    if(argc < 2){
        cout << "Usage: ./denoise input.txt\n";
        return 1;
    }

    ifstream file(argv[1]);

    if(!file){
        cout << "Error opening file\n";
        return 1;
    }

    int rows, cols;
    file >> rows >> cols;

    vector<vector<int>> img(rows, vector<int>(cols));
    vector<vector<int>> out = img;

    for(int i=0;i<rows;i++)
        for(int j=0;j<cols;j++)
            file >> img[i][j];

    // 3x3 mean filter (ignore borders)
    for(int i=1;i<rows-1;i++){
        for(int j=1;j<cols-1;j++){

            int sum = 0;

            for(int di=-1;di<=1;di++)
                for(int dj=-1;dj<=1;dj++)
                    sum += img[i+di][j+dj];

          int val = sum/9;
if(val < 0) val = 0;
if(val > 255) val = 255;
out[i][j] = val;;
        }
    }

    cout << "Loaded matrix:\n";

    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++)
            cout << out[i][j] << " ";
        cout << endl;
    }

    // write output file
    ofstream outFile("output.txt");

    outFile << rows << " " << cols << endl;

    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++)
            outFile << out[i][j] << " ";
        outFile << endl;
    }

    outFile.close();

    return 0;
}
