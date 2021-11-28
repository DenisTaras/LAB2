#ifndef FIELD_HPP
#define FIELD_HPP
#include <vector>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
class Field
{
private:
    std::vector<std::vector<char>> data;
public:
    Field(int len): data() {
        for(int i = 0; i < len; i++){
            data.push_back(std::vector<char>(len,' '));
        }
    }
    void extention(){
        for(int i = 0; i < data.size(); i++){
            data[i].push_back(' ');
            data[i].insert(data[i].begin(),' ');
        }
        data.push_back(std::vector<char>(data.size()));
        data.insert( data.begin(), std::vector<char>(data[0].size(),' '));
    }
    void Set(int i, int j, char cell){
        data[i][j] = cell;
    }
    char Get(int i, int j){
        return data[i][j];
    }
    int Get_Lenght(){
        return data.size();
    }
};
#endif