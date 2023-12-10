#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(){
    int sum = 0;
    string line;
    fstream input;
    input.open("test.txt");
    while(input >> line){
        for(int i = 0; i < line.length(); i++){
            
        }
    }
}