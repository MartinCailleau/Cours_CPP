#include <iostream>
#include <numeric>

struct AIData
{
    bool isActive = false;
    int boundMin = 1;
    int boundMax = 100;
    int aiLevel = 1; // 1 easy, 10 hard
};

int CompareAndDisplay(int value1, int value2)
{
    if (value1 == value2)
    {
        std::cout << "Bravo vous avez trouvé le chiffre mystère : " << value1 << std::endl;
        return 0;
    }
    else if (value1 < value2)
    {
        std::cout << "c'est plus" << std::endl;
        return -1;
    }
    else
    {
        std::cout << "c'est moins" << std::endl;
        return 1;
    }
}

int AI_Guess(AIData ai,int min, int max)
{
    int aiInterval = (max - min) * (1.0f - ai.aiLevel/10.0f);
   // std::cout << "Intervalle : " << min << " - " << max << " (" << aiInterval << ")" << std::endl;
    int r = rand() % (100 + 1);
    int guess = min+ (aiInterval * r/100.0f);
    std::cout << "L'IA propose : " << r << std::endl;
    return guess;
}

int AI_UpdateBounds(int result, int &min, int &max)
{
    if (result == -1)
    {
        min += 1;
    }
    else if (result == 1)
    {
        max -= 1;
    }
    return 0;
}

int main()
{
    AIData ai;
    srand((unsigned int)time(NULL));
    int nbToFind = rand() % 100 + 1; // random between 1 and 100
    int playerInput = 0;


    std::cout << "Chaud Froid - devinez le chiffre mystère" << std::endl;
    std::cout << "Le jeu va choisir un chiffre entre 1 et 100" << std::endl;
    std::cout << "Vous devrez deviner ce chiffre en recevant des indices" << std::endl;
    std::cout << "Plus vous serez proche du chiffre, plus l'indice sera chaud" << std::endl;
    std::cout << "Plus vous serez loin du chiffre, plus l'indice sera froid" << std::endl;
    std::cout << "Souhaitez vous utiliser l'IA ?" << std::endl;
    (std::cin.get() == 'y') ? ai.isActive = true : ai.isActive = false;

    if (ai.isActive)
    {
        int stats[100] = { 0 };
        for(int i = 0; i < 100; i++){
            std::cout << "L'IA va deviner le chiffre mystère" << std::endl;
            int result = -1;
            ai.boundMin = 1; 
            ai.boundMax = 100;
            do
            {
               // std::cout << "min " << ai.boundMax << std::endl;
                playerInput = AI_Guess(ai,ai.boundMin, ai.boundMax);
                result = CompareAndDisplay(playerInput, nbToFind);
                AI_UpdateBounds(result, ai.boundMin, ai.boundMax);
                stats[i]++;
            } while (result != 0);
            std::cout << "L'IA a trouvé le chiffre mystère en " << stats[i] << " essais" << std::endl;

        }

        std::cout << "L'IA a trouvé le chiffre mystère en moyenne en "<< stats << " -- " << (float)(std::accumulate(stats, stats + 100, 0)) / 100.0f << " essais" << std::endl;
    }
    else
    {
        std::cout << "Appuyez sur une touche pour commencer  " << nbToFind << std::endl;
        do
        {
            std::cin >> playerInput;
        } while (CompareAndDisplay(playerInput, nbToFind) != 0);
    }

    return 0;
}