#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int P1(string filename){
    int sum = 0;
    fstream input;
    input.open(filename);
    string line;
    vector<int> haveNums;
    vector<int> winningNums;
    bool start;
    bool foundSplit = false;
    while(input >> line){
        //cout << line << endl;
        if(line == "Card"){
            int exp = -1;
            if(!haveNums.empty() && !winningNums.empty()){
                sort(haveNums.begin(), haveNums.end());
                sort(winningNums.begin(), winningNums.end());
                int k = 0;
                int i = 0;
                while(i < haveNums.size() && k < winningNums.size()){
                    if(haveNums[i] < winningNums[k]){
                        i++;
                    }
                    else if(haveNums[i] > winningNums[k]){
                        k++;
                    }
                    else if(haveNums[i] == winningNums[k]){
                        exp++;
                        k++;
                        i++;
                    }
                }
                if(exp > -1){
                    sum += pow(2.0, exp);
                }
            }
            haveNums.clear();
            winningNums.clear();
            foundSplit = false;
            start = false;
        }
        if(line.back() == ':'){
            start = true;
        }
        if(isdigit(line.back()) && start){
            if(!foundSplit){
                haveNums.push_back(stoi(line));
            }else winningNums.push_back(stoi(line));
        }
        if(line == "|"){
            foundSplit = true;
        }
    }
    return sum;
}

int main(){
    fstream input;
    string line;
    cout << "P1: " << P1("input.txt");
    return P1("input.txt");
}
