#include "Attack.hpp"
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
int main(){
    String weight;
    char buffer[12];

    std::cin.getline(buffer, 14);
    std::string str(buffer);
    std::cout<<str << "\n";
    double w = weight.wheight_string(str, 6);
    //int w = str.find("0", 5);
    std::cout << "weight:"<< w <<"\n";
    return 0;
}