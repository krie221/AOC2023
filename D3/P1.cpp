#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <tuple>
#include <algorithm>

using namespace std;



const tuple<int, int> neighbors[8]= {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

bool isNumber(char x){
    return (x <= '9' && x >= '0');
}

int P1(const vector<string> &engine){
    int sum = 0;
    for(int row = 0; row < engine.size(); row++){
        bool found  = false;
        int numStart = -1;
        for(int col = 0; col < engine[row].size(); col++){
            if(isNumber(engine[row][col])){
                if(numStart == -1){
                    numStart = col;
                }
                if(!found){
                    for(auto neigh : neighbors){
                        int y = row + get<0>(neigh);
                        int x = col + get<1>(neigh);

                        if(x < 0 || x > engine[row].size() - 1 || y < 0 || y > engine.size() - 1){
                            continue;
                        }
                        if(!isdigit(engine[y][x]) && engine[y][x] != '.'){
                            found = true;
                            break;
                        }
                    }
                }
            }
            else if(found && numStart != -1){
                sum += stoi(engine[row].substr(numStart, col - numStart));
                numStart = -1;
                found = false;
            }
            else{
                numStart = -1;
            }
        }
        if(numStart != -1 && found){
            sum += stoi(engine[row].substr(numStart));
        }
    }
    return sum;
}

int main(){
    ifstream input;
    input.open("input.txt");
    string line;
    vector<string> engine;
    while(input >> line){
        engine.emplace_back(line);
    }
    cout << "P1: " << P1(engine);
    return 0;
}
