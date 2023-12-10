#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
using namespace std;
string line;
/*
    ifstream input;
    input.open("input.txt");
*/

int main(){
    bool possible = true;
    int k = 0;
    int sum = 0;
    int lastNum;
    ifstream input;
    input.open("input.txt");
    while(input >> line){
        //cout << line << endl;
        if(isdigit(line[0])){
            lastNum = stoi(line);
            continue;
        }
        else if(line.substr(0, 3) == "red"){
            //cout << "lastNum: " << lastNum << endl;
            if(lastNum > 12){
                possible = false;
            } 
            //cout << "redCount: " << redCount << endl;
        }
        else if(line.substr(0, 5) == "green"){
            if(lastNum > 13){
                possible = false;
            } 
            //cout << "greenCount: " << greenCount << endl;
        }
        else if(line.substr(0, 4) == "blue"){
            if(lastNum > 14){
                possible = false;
            } 
            //cout << "blueCount: " << blueCount << endl;
        }
        else if(line == "Game"){
            if(k > 0 & possible){
                sum += k;
            }
            possible = true;
            k++;
        }
    }
    if(possible){
        sum += k;
    }
    cout << "sum is: " << sum << endl;
    return 0;
}