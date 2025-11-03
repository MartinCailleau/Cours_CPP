#include <iostream>

void StartTurn(int remainingTurn, int playerId);
void NextPlayer(int &playerId);
bool EndTurn(int &remainingTurn);


int main()
{
    const int totalTurns = 5;
    int remainingTurn = totalTurns;
    int currentPlayerId = 0;

    while (remainingTurn > 0)
    {
        StartTurn(remainingTurn, currentPlayerId);

        NextPlayer(currentPlayerId);

        EndTurn(remainingTurn);
    }

    return 0;
}

void StartTurn(int remainingTurn, int playerId)
{
    std::cout << "Player " << playerId << " starts their turn. Remaining turns: " << remainingTurn << std::endl;
}

void NextPlayer(int &playerId)
{
    std::cout << "Player " << playerId << " ends their turn." << std::endl;
    playerId = (playerId+1) % 2; //2 players
}

bool EndTurn(int &remainingTurn)
{
    --remainingTurn;
    if (remainingTurn <= 0)
    {
        std::cout << "End of game" << std::endl;
        return true;
    }
    return false;
}

