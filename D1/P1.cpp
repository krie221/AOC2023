#include <iostream>
#include <fstream>
#include <string>
using namespace std;
string line;
string linenum;
int main(){
    int sum = 0;
    ifstream input;
    input.open("input.txt");
    while(input >> line){
        linenum = "";
        for(int i = 0; i < line.length(); i++){
            if(isdigit(line[i])){
                linenum = line[i];
                break;
            }
        }
        for(int i = line.length() - 1; i > -1; i--){
            if(isdigit(line[i])){
                linenum += line[i];
                break;
            }
        }
        sum = sum + stoi(linenum);
    }
    cout << sum << endl;
    return sum;
}