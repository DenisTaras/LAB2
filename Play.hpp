#ifndef PLAY_HPP
#define PLAY_HPP
#include "Field.hpp"
#include "Attack.hpp"
class Play
{
    public:
    void Selection(Field& F, int& x, int& y){
        int len = F.Get_Lenght();
        int WHEIGHT = 0;
        for(int i = 0; i < len; i++){
            for(int j = 0; j<len; j++){
                if(F.Get(i,j) ==' '){
                    F.Set(i, j, 'X');
                    int wheightX = point_wheight(F, i, j, 0);
                    F.Set(i, j, 'O');
                    int wheightY = point_wheight(F, i, j, 1);
                    if(wheightX + wheightY >= WHEIGHT){
                        x = i;
                        y = j;
                        WHEIGHT = wheightX + wheightY;
                        if(wheightX >= 1000){
                            WHEIGHT = 10*wheightX;
                        }
                        //std::cout<<x<<' '<<y<<' '<<WHEIGHT<<"\n";
                    }
                    F.Set(i,j,' ');
                }
            }
        }
    }

    int point_wheight(Field& F, int& i, int& j, bool TR){
        int len = F.Get_Lenght();
        int strlong = 11;
        String S;
                int mainSTR1 = 6;
                int mainSTR2 = 6;
                int mainSTR3 = 6;
                int mainSTR4 = 6;
                std::string STR1;
                std::string STR2;
                std::string STR3;
                std::string STR4;
                if((i - strlong/2) < 0  || (j - strlong/2) < 0){
                    mainSTR1 += std::min(i,j) - strlong/2;
                }

                for(int p = 0; p < strlong; p++){
                    if((i - strlong/2 + p) < 0  || (j - strlong/2 + p) < 0 || (j - strlong/2 + p) >= len || (i - strlong/2 + p) >= len){
                        continue;
                    }
                    STR1.push_back(F.Get(i - strlong/2 + p, j - strlong/2 + p ));
                }

                if((i - strlong/2) < 0 ){
                    mainSTR2 += i - strlong/2;
                }
                for(int p = 0; p < strlong; p++){
                    if((i - strlong/2 + p) < 0 || (i - strlong/2 + p) >= len){
                        continue;
                    }
                    STR2.push_back(F.Get(i - strlong/2 + p, j));
                }

                if((j - strlong/2) < 0 ){
                    mainSTR3 += j - strlong/2;
                }
                for(int p = 0; p < strlong; p++){
                    if((j - strlong/2 + p) < 0 || (j - strlong/2 + p) >= len){
                        continue;
                    }
                    STR3.push_back(F.Get(i, j - strlong/2 + p));
                }
                if((i - strlong/2) < 0 || j + strlong/2 >= len ) {
                    mainSTR4 += std::min(i - strlong/2, len - (j + strlong/2));
                }
                for(int p = 0; p < strlong; p++){
                    if((j + strlong/2 - p) < 0 || (j + strlong/2 - p) >= len || (i - strlong/2 + p) < 0 || (i - strlong/2 + p) >= len){
                        continue;
                    }
                    STR4.push_back(F.Get(i - strlong/2 + p, j + strlong/2 - p));
                }
                STR1.insert(0,1,'K');
                STR1.push_back('K');
                STR2.insert(0, 1,'K');
                STR2.push_back('K');
                STR3.insert(0,1, 'K');
                STR3.push_back('K');
                STR4.insert(0,1,'K');
                STR4.push_back('K');
                if(TR){
                    S.replace(STR1);
                    S.replace(STR2);
                    S.replace(STR3);
                    S.replace(STR4);
                }
                S.help(STR1);
                S.help(STR2);
                S.help(STR3);
                S.help(STR4);
                /*std::cout<<STR1<<"\n"<<mainSTR1<<"\n"<<S.wheight_string(STR1, mainSTR1)<<"\n";
                std::cout<<STR2<<"\n"<<mainSTR2<<"\n"<<S.wheight_string(STR2, mainSTR2)<<"\n";
                std::cout<<STR3<<"\n"<<mainSTR3<<"\n"<<S.wheight_string(STR3, mainSTR3)<<"\n";
                std::cout<<STR4<<"\n"<<mainSTR4<<"\n"<<S.wheight_string(STR4, mainSTR4)<<"\n";*/
                std::cout<<'\n';
                int X_wheight = S.wheight_string(STR1, mainSTR1) + S.wheight_string(STR2, mainSTR2) + S.wheight_string(STR3, mainSTR3) + S.wheight_string(STR4, mainSTR4);
                return X_wheight;
    }  
};
#endif