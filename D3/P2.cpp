#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <tuple>

using namespace std;

const tuple<int, int> neighbors[8] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

int P2(const vector<string> &engine){
    int ratio = 0;
    vector<int> adjNum;
    for(int r = 0; r < engine.size(); r++){
        for(int c = 0; c < engine.size(); c++){
            int numStartx = -1;
            int numStarty = -1;
            if(engine[r][c] != '*'){
                continue;
            }
            else{
                for(auto n : neighbors){
                    int y = r + get<0>(n);
                    int x = c + get<1>(n);

                    if(x < 0 || x > engine.size() - 1 || y < 0 || y > engine[r].size() - 1){
                        continue;
                    }
                    if(isdigit(engine[y][x])){
                        while(x >= 0 && isdigit(engine[y][x])){
                            x--;
                        }
                        x++;
                        if(numStartx == x && numStarty == y){
                            continue;
                        }
                        numStartx = x;
                        numStarty = y;
                        while(x <= engine.size() - 1 && isdigit(engine[y][x])){
                            x++;
                        }
                        adjNum.push_back(stoi(engine[y].substr(numStartx, x - numStartx)));
                        if(adjNum.size() == 2){
                            ratio += adjNum[0]*adjNum[1];
                            break;
                        }
                    }
                }
                adjNum.clear();
            }
        }
    }
    return ratio;
}

int main(){
    ifstream input;
    input.open("input.txt");
    vector<string> engine;
    string line;
    while(input >> line){
        engine.emplace_back(line);
    }
    cout << "P2: " << P2(engine);
    return -1;
}
