#include <iostream>
#include <fstream>
#include <string>
using namespace std;
string line;


int main(){
    int maxRed, maxBlue, maxGreen;
    int lastNum;
    int power;
    int sum = 0;
    fstream input;
    input.open("input.txt");
    while(input >> line){
        if(line == "Game"){
            lastNum = 0;
            power = maxRed * maxGreen * maxBlue;
            sum += power;
            maxRed = 0;
            maxGreen = 0;
            maxBlue = 0;
        }
        else if(isdigit(line[0])){
            lastNum = stoi(line);
            continue;
        }
        else if(line.substr(0, 3) == "red"){
            if(lastNum > maxRed){
                maxRed = lastNum;
            } 
        }
        else if(line.substr(0, 5) == "green"){
            if(lastNum > maxGreen){
                maxGreen = lastNum;
            } 
        }
        else if(line.substr(0, 4) == "blue"){
            if(lastNum > maxBlue){
                maxBlue = lastNum;
            }
        }
    }
    power = maxRed * maxGreen * maxBlue;
    sum += power;
    cout << sum << endl;
    return 0;
}
