#include "LostCore.hpp"

// PixelPhobicGames - LostEngine.V.1 - 2021

int main(void){

    LostInit();

    while(LostEngine.Running){

        LostMainLoop();

    }

    LostClose();
}