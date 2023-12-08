#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;
string line;
string linenum;
//zero one two three four five six seven eight nine

string filterToNumeric(string input){
    map<string, string> value_map = {
        {"zero", "0"},
        {"one", "1"},
        {"two", "2"},
        {"three", "3"},
        {"four", "4"},
        {"five", "5"},
        {"six", "6"},
        {"seven", "7"},
        {"eight", "8"},
        {"nine", "9"},
    };
    for(int i = 0; i < input.length(); i++){
        if(!isdigit(input[i])){
            for(auto pair : value_map){
                try{
                    if(pair.first == input.substr(i, pair.first.length())){
                        input.replace(i, pair.first.length(), pair.second);
                        break;
                    }
                }
                catch(const std::exception& e){
                    cout << e.what() << endl;
                }
            }
        }
    }
    return input;
}

int main(){
    int sum = 0;
    ifstream input;
    input.open("input.txt");
    while(input >> line){
        line = filterToNumeric(line);
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
