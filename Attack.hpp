#ifndef Attack_hpp
#define Attack_hpp
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

int FIND(std::string str1, char str2){
    if(str1.find(str2) == std::string::npos)
        return -1;
    return str1.find(str2);
}

int FIND(std::string str1, char str2,  int A){
    if(str1.find(str2, A) == std::string::npos)
    return -1;
    return str1.find(str2, A);
}

int RFIND(std::string str1, char str2,  int A){
    if(str1.rfind(str2, A) == std::string::npos)
    return -1;
    return str1.rfind(str2, A);
}
int FIND(std::string str1, std::string str2,  int A){
    if(str1.find(str2, A) == std::string::npos)
    return -1;
    return str1.find(str2, A);
}

int RFIND(std::string str1, std::string str2,  int A){
    if(str1.rfind(str2, A) == std::string::npos)
    return -1;
    return str1.rfind(str2, A);
}
class attack
{
private:
    int capability;
    int potencial;
    int diviver;
public:
    attack(){
    capability = 0;
    potencial = 0;
    diviver = 1;
    }
    void type(std::string str, int div){
        if (str == " XXXX ")
        {
            capability = 4;
            potencial = 2;
        }
        else if (str == " XXX ")
        {
            capability = 3;
            potencial = 2;
        }
        else if (str == " XX ")
        {
            capability = 2;
            potencial = 2;
        }
        else if (str == " X ")
        {
            capability = 1;
            potencial = 2;
        }
        else if (str == "OXXXX ")
        {
            capability = 4;
            potencial = 1;
        }
        else if (str == "OXXX ")
        {
            capability = 3;
            potencial = 1;
        }
        else if (str == "OXX ")
        {
            capability = 2;
            potencial = 1;
        }
        else if (str == "OX ")
        {
            capability = 1;
            potencial = 1;
        }
        else if (str == " XXXXO")
        {
            capability = 4;
            potencial = 1;
        }
        else if (str == " XXXO")
        {
            capability = 3;
            potencial = 1;
        }
        else if (str == " XXO")
        {
            capability = 2;
            potencial = 1;
        }
        else if (str == " XO")
        {
            capability = 1;
            potencial = 1;
        }
        else if (str == "XXXXX")
        {
            capability = 5;
        }
        diviver = div;
    }
    double wheight(){
        if(capability == 4 && potencial == 2){
            return 200;
        }
        else if (capability == 5){
            return 1000;
        }
        
        else if(capability == 4 && potencial == 1){
            return 14;
        }
        else if(capability == 3 && potencial == 2){
            return 20;
        }
        else if(capability == 3 && potencial == 1){
            return 5;
        }
        else if(capability == 2 && potencial == 2){
            return 7;
        }
        else if(capability == 2 && potencial == 1){
            return 2;
        }
        else if(capability == 1 && potencial == 2){
            return 0.5;
        }
        else if(capability == 1 && potencial == 1){
            return 0.2;
        }
        else 
        {
            return 0;
        }
        
    }
    double Diviver(){
        return diviver;
    }
};



class String
{
private:

public:
    double wheight_string(std::string str, int center){
        int END = FIND( str,' ', center);
        int end = FIND(str,'O', center);
        int start = RFIND( str,'O', center);
        int START = RFIND( str, ' ', center);
        int S = std::max(start, START);
        if(end - start < 6){
            return 0;
        }
        //std:: cout<< start <<" "<< START <<" "<< end <<" "<< END<<" " << S << "\n";
        ///////главная атака
        int XXXXX = -1, XXXX = -1, XXX = -1, XX = -1, X = -1;
        
        XXXXX = FIND(str, "XXXXX", S);
        XXXX = FIND(str, " XXXX ", S);
        XXX = FIND(str, " XXX ", S);
        XX = FIND(str, " XX ", S);
        X = FIND(str, " X ", S);

        int OXXXX = -1, OXXX = -1, OXX = -1, OX = -1;
        OXXXX = FIND(str, "OXXXX ", S);
        OXXX = FIND( str, "OXXX ", S);
        OXX = FIND(str, "OXX ", S);
        OX = FIND( str, "OX ", S);

        int XXXXO = -1, XXXO = -1, XXO = -1, XO = -1;
        XXXXO= FIND(str, " XXXXO", S);
        XXXO = FIND(str," XXXO", S);
        XXO = FIND(str," XXO", S);
        XO = FIND(str," XO", S);

        
        attack main_attack;
        int num;
        int main_start;
        if(XXXX != -1 && XXXX < center + 1){
            main_attack.type(" XXXX ", 1);
            num = 6;
            main_start = XXXX;
        }
        else if(XXXXX != -1 && XXXXX < center + 1){
            main_attack.type("XXXXX", 1);
            num = 5;
            main_start = XXXXX;
        }
        else if(XXX != -1 && XXX < center + 1){
            main_attack.type(" XXX ", 1);
            num = 5;
            main_start = XXX;
        }
        else if(XX != -1 && XX < center +1){
            main_attack.type(" XX ", 1);
            num = 4;
            main_start = XX;
        }
        else if(X != -1 && X < center + 1){
            main_attack.type(" X ", 1);
            num = 3;
            main_start = X;
        }
        else if(OXXXX != -1){
            main_attack.type("OXXXX ", 1);
            num = 6;
            main_start = OXXXX;
        }
        else if(OXXX != -1){
            main_attack.type("OXXX ", 1);
            num = 5;
            main_start = OXXX;
        }
        else if(OXX != -1){
            main_attack.type("OXX ", 1);
            num = 4;
            main_start = OXX;
        }
        else if(OX != -1){
            main_attack.type("OX ", 1);
            num = 3;
            main_start = OX;
        }
        else if(XXXXO != -1){
            main_attack.type(" XXXXO", 1);
            num = 6;
            main_start = XXXXO;
        }
        else if(XXXO != -1){
            main_attack.type(" XXXO", 1);
            num = 5;
            main_start = XXXO;
        }
        else if(XXO != -1){
            main_attack.type(" XXO", 1);
            num = 4;
            main_start = XXO;
        }
        else if(XO != -1){
            main_attack.type(" XO", 1);
            num = 3;
            main_start = XO;
        }

        S = main_start;
        
        ////////// левая побочная атака
        attack left_attack;
        if(S>0){
        XXXX = RFIND(str," XXXX ", S - 1);
        XXX = RFIND(str," XXX ", S - 1);
        XX = RFIND(str," XX ", S - 1);
        X = RFIND(str," X ", S - 1);

        OXXXX = RFIND(str,"OXXXX ", S -1);
        OXXX = RFIND(str,"OXXX ", S-1);
        OXX = RFIND(str,"OXX ", S-1);
        OX = RFIND(str,"OX ", S-1);

        if(XXX != -1){
            left_attack.type(" XXX ", S - XXX - 2);
        }
        else if(XX != -1){
            left_attack.type(" XX ", S - XX - 1);
        }
        else if(X != -1){
            left_attack.type(" X ", S - X );
        }

        else if(OXXX != -1){
            left_attack.type("OXXX ", S - OXXX  - 2);
        }
        else if(OXX != -1){
            left_attack.type("OXX ", S - OXX - 1 );
        }
        else if(OX != -1){
            left_attack.type("OX ", S - OX );
        }
        }
        //std::cout<<OXX<<XX<<X<<S<<"\n";
        ////////// правая побочная атака
        S = S + num -1 ;

        attack right_attack;
        XXX = FIND(str," XXX ", S);
        XX = FIND(str," XX ", S);
        X = FIND(str," X ", S);

        XXXO = FIND(str," XXXO", S);
        XXO = FIND(str," XXO", S);
        XO = FIND(str," XO", S);
        
        if(XXX != -1){
            right_attack.type(" XXX ", XXX - S + 1);
        }
        else if(XX != -1){
            right_attack.type(" XX ", XX - S + 1);
        }
        else if(X != -1){
            right_attack.type(" X ", X - S + 1);
        }

        else if(XXXO != -1){
            right_attack.type(" XXXO",XXXO - S + 1 );
        }
        else if(XXO != -1){
            right_attack.type(" XXO", XXO - S + 1);
        }
        else if(XO != -1){
            right_attack.type(" XO", XO - S + 1);
        }
        
        /*std::cout<<right_attack.wheight()<<"\n";
        std::cout<<left_attack.wheight()<<"\n";
        std::cout<<main_attack.wheight()<<"\n";
        std::cout<<main_attack.Diviver()<<"\n";
        std::cout<<left_attack.Diviver()<<"\n";
        std::cout<<right_attack.Diviver()<<"\n";*/
        return left_attack.wheight()/left_attack.Diviver() + right_attack.wheight()/right_attack.Diviver() + main_attack.wheight()/main_attack.Diviver();

    }
    void replace(std::string& str){
        int t = 0;
        while (t >=0){
            t = FIND(str,'X');
            if(t== -1){
                break;
            }
            str[t] = 'T';
        }
        t = 0;
        while (t >=0){
            t = FIND(str,'O');
            if(t== -1){
                break;
            }
            str[t] = 'X';
        }
        t = 0;
        while (t >=0){
            t = FIND(str,'T');
            if(t== -1){
                break;
            }
            str[t] = 'O';
        }
    }
    void help(std::string& str){
        int t = 0;
        while (t >=0){
            t = FIND(str,'K');
            if(t== -1){
                break;
            }
            str[t] = 'O';
        }
    }
};
#endif