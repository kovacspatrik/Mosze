#include "typeSelection.hpp"

int typeSelectionMenu(){
    int valasz;
    std::cout << "Kerem adja meg a mely termektipuson szeretne vegrehajtani a muveletet:\n";
    std::cout << "1 - Szamitogepek \n";
    std::cout << "2 - Konzolok \n";
    std::cout << "3 - Notebookok \n";
    std::cout << "4 - Telefonok \n";
    std::cout << "5 - Vissza \n";
    
    std::cin >> valasz;
    while(valasz !=0){
        if(valasz == 1){
            return 1;
        }
        if(valasz == 2){
            return 2;
        }
        if(valasz == 3){
            return 3;
        }
        if(valasz == 4){
            return 4;
        }
        if(valasz == 0){
            return 0;
        }
    }
    return 0;
}