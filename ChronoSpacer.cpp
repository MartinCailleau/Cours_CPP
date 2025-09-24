#include <iostream>
#include <Windows.h>
#include <time.h>
#include <conio.h>


// Get Input
bool isKeyPressed()
{
    if (_kbhit())
    {
        while (_kbhit()) // Flush input buffer
        {
            _getch();
        }
        return true; // Key Was Hit
    }
    return false; // No keys were pressed
}

int main(){
    int i = 0;
    bool isWinning = true;
    while (isWinning == true)
    {   
        i++;
        float winInterval = 2.0f;
        // init random seed
        srand((unsigned int)time(NULL));
        // random pick
        float timeToFind = (float)(rand() % 10 + 1); // random between 1 and 10

        std::cout << "Chrono Spacer - testez votre capaciter à mesurer le temps" << std::endl;
        std::cout << "Le jeu va vous indiquer une durée en secondes." << std::endl;
        std::cout << "vous devrez appuyer sur une touche lorsque vous estimez que le temps donné est passé" << std::endl;
        std::cout << "Le temps à attendre est de : " << timeToFind << " secondes" << std::endl;
        std::cout << "La tolerance est de " << winInterval << "s"<< std::endl;
        std::cout << "Appuyez sur une touche pour commencer " << std::endl;
        while (!isKeyPressed()){}
                
        float startTime = (float)clock() / (float)CLOCKS_PER_SEC;

        while (!isKeyPressed() && (float)clock() / (float)CLOCKS_PER_SEC - startTime < 15.0f){
        }

        float endTime = (float)clock() / (float)CLOCKS_PER_SEC;
        float elapsedTime = endTime - startTime;
        std::cout << "Vous avez attendu : " << elapsedTime << " secondes" << std::endl;
        std::cout << "Vous aviez pour objectif : " << timeToFind << " secondes" << std::endl;
        std::cout << "Vous avez donc fait une erreur de : " << abs(elapsedTime - timeToFind) << " secondes" << std::endl;
        if(abs(elapsedTime - timeToFind) <= winInterval){
            std::cout << "Bravo, vous avez gagné !" << std::endl;
            winInterval *= 0.8f;
        } else {
            std::cout << "Dommage, vous avez perdu !" << std::endl;
            isWinning = false;
        }
        std::cout << "Appuyez sur une touche pour quitter" << std::endl;
    }

    return 0;
}

