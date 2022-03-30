#include "battle-bot.h"

#include <iostream>

using namespace std;

int main()
{
    BattleBot sasuke(1,5,'s');
    BattleBot naruto(1,1,'n');

    //original state
    cout << naruto;
    cout << sasuke;

    cout<< endl;

    // kick
    naruto.LeftKick(sasuke);
    cout << sasuke;

    cout<< endl;

    // launch
    sasuke.fire(naruto);
    cout << naruto;

    cout<< endl;

    // move
    sasuke.Move();
    cout << sasuke;

    cout<< endl;

    //move
    naruto.Move();
    cout << naruto;

    cout<< endl;

    // launch
    naruto.fire(sasuke);
    cout << sasuke;

    cout<< endl;

    // punch
    sasuke.RightPunch(naruto);
    cout << naruto;

    cout<< endl;

    if (sasuke.GetHealth() > naruto.GetHealth())
        cout << "SASUKE WINS!!!";
    else if (sasuke.GetHealth() < naruto.GetHealth())
        cout << "NARUTO WINS!!!";
    else if (sasuke.GetHealth() == naruto.GetHealth())
    {
        cout << "ITS A TIE!!";
    }


};

