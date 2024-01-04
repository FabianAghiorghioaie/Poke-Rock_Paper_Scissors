#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <windows.h>

using namespace std;

char names(int x)
{
    char name[255] = " Normal Fighting Flying Poison Ground Rock Bug Ghost Steel Fire Water Grass Electric Psychic Ice Dragon Dark Fairy ";
    int i = x;
    int j = 0;
    while (i != 0)
    {
        if (name[j] == ' ')
            i--;
        j++;
    }
    while (name[j] != ' ')
    {
        cout << name[j];
        j++;
    }
    return 0;
}

int hpbar(int x)
{
    cout << "[";
    for (int i = 0; i < 10; i++)
    {
        if (i <= x / 10)
            cout << "|";
        else cout << " ";
    }
    cout << "]";
    return 0;
}

int random(int x)
{
    int y;
    y = rand() % x + 1;
    return y;
}

int main()
{
    ifstream f;
    f.open("multipliers.txt");
    srand(time(NULL));
    int moves[3][5];
    for (int j = 1; j < 3; j++)
        for (int i = 0; i < 5; i++)
            moves[j][i] = random(18);
    float types[19][19];
    for (int j = 1; j < 19; j++)
        for (int i = 1; i < 19; i++)
            f >> types[i][j];
    int hp[3];
    hp[1] = 100;
    hp[2] = 100;
    long long int p = 2;
    int attack[3];
    int damage[3];
    attack[1] = 0;
    attack[2] = 0;
    while (hp[1] > 0 && hp[2] > 0)
    {
        system("CLS");
        cout << endl;
        p = 3 - p;
        cout << "Hp:" << hp[p] << "     ";
        hpbar(hp[p]);
        cout << endl;
        cout << "Player " << p << "'s Type: ";
        cout << names(moves[p][0]) << endl;
        cout << "Player " << p << "'s Moves: ";
        for (int i = 1; i < 5; i++)
        {
            cout << "(" << i << ")" << names(moves[p][i]) << "	";
        }
        cout << endl << "Opponent" << p << "'s Type: ";
        cout << names(moves[3-p][0]) << endl;
        while (attack[p] > 4 || attack[p] < 1)
        {
            cin >> attack[p];
        }
        attack[p] = moves[p][attack[p]];
        system("CLS");
        if (attack[1] != 0 && attack[2] != 0)
        {
            damage[1] = ((20 / types[attack[1]][moves[1][0]]) * types[attack[1]][attack[2]]);
            if (random(10) == 10)
            {
                damage[1] *= 2;
                cout << "Crit! ";
            }
            cout << damage[1] << " Damage from Player1!" << endl;
            damage[2] = ((20 / types[attack[2]][moves[2][0]]) * types[attack[2]][attack[1]]);
            if (random(10) == 10)
            {
                damage[2] *= 2;
                cout << "Crit! ";
            }
            cout << damage[2] << " Damage from Player2!" << endl;
            if (damage[1] > damage[2])
            {
                cout << "Player 1 did " << damage[1] - damage[2] << " damage using ";
                cout << names(attack[1]);
                hp[2] = hp[2] + damage[2] - damage[1];
                Sleep(3000);
            }
            if (damage[2] > damage[1])
            {
                cout << "Player 2 did " << damage[2] - damage[1] << " damage using ";
                cout << names(attack[2]);
                hp[1] = hp[1] + damage[1] - damage[2];
                Sleep(3000);
            }
            if (damage[2] == damage[1])
            {
                cout << "Tie! Both players recieve " << damage[1] / 2 << " damage! ";
                hp[1] -= damage[2] / 2;
                hp[2] -= damage[1] / 2;
                Sleep(3000);
            }
                
            cout << endl;
            attack[1] = 0;
            attack[2] = 0;
        }
    }
    cout << endl;
    if (hp[1] < hp[2])
        cout << "Player 2 Wins";
    else cout << "Player 1 Wins";
    cout << endl;    cout << endl;    cout << endl;    cout << endl;    cout << endl;
    return 0;
}
