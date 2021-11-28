#include "Play.hpp"
void Print_Field(Field& F){
        for(int i = 0; i< 15; i++){
            for(int j = 0; j<15; j++){
                std::cout<< F.Get(j,i);
            }
            std::cout<<"\n";
        }
    }
    
int main(){
    bool end_game = 1;
    Play AI;
    Field F(15);
    while (end_game)
    {   
        int x, y;
        int X,Y;
        std::cout<<"Enter cords"<<"\n"<<"x:"<<"\n";
        std::cin>>x;
        std::cout<<"y:"<<"\n";
        std::cin>>y;
        F.Set(x,y,'O');
        AI.Selection(F,X,Y);
        F.Set(X,Y,'X');
        Print_Field(F);
        //std::cout<<"end_game:";
        //std::cin>>end_game;
        std::cout<<"\n";
    }
    
    return 0;
}