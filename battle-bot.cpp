#include "battle-bot.h"

#include <iostream>

using namespace std;

// START OF ROBOLEG CLASS
RoboLeg::RoboLeg()
{
    isRaised = false;
    position = 'u';
}

void RoboLeg::Step()
{
    liftLeg();
    cout << "Leg was lifted" << endl;
    swing('f');
    cout << "leg was swung forward" << endl;
    lowerLeg();
    cout << "Leg was lowered" << endl;
    swing('u');

}
void RoboLeg::Kick()
{
    liftLeg();
    cout << "Leg was lifted" << endl;
    swing('b');
    cout << "leg was swung backward" << endl;
    swing('u');
    cout << "leg is swinging (currently under)" << endl;
    swing('f');
    cout << "leg was swung forward" << endl;
    swing('u');
    cout << "leg was swung back under" << endl;
    lowerLeg();
    cout << "Leg was lowered" << endl;
}


void RoboLeg::liftLeg()
{
    isRaised = true;
}
void RoboLeg::swing(char p)
{
    position = p;
}
void RoboLeg::lowerLeg()
{
    isRaised = false;
}
//END OF ROBOLEG CLASS

//START OF ROBOARM CLASS

RoboArm::RoboArm()
{
    isDrawnBack = false;
}

void RoboArm::Punch()
{
    drawBack();
    cout << "Arm was drawn back" << endl;
    thrust();
    cout << "Arm was thrust, and returned to original position" << endl;
}

void RoboArm::drawBack()
{
    isDrawnBack = true;
}

void RoboArm::thrust()
{
    isDrawnBack = false;
}

//END OF ROBOARM CLASS

//START OF THE PROJECTILELAUNCHER CLASS

ProjectileLauncher::ProjectileLauncher()
{
    isLoaded = false;
}

void ProjectileLauncher::Load()
{
    cout << "Launcher was Loaded" << endl;
    isLoaded = true;
}

void ProjectileLauncher::Fire()
{
    while (checkLoaded() == false)
    {
        cout << "load the launcher!!" << endl;
    }
    isLoaded = false;
    cout << "Launcher was fired" << endl;
}

bool ProjectileLauncher::checkLoaded()
{
    if(isLoaded == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}
// END OF PROJECETILELAUNCHER CLASS

//START OF THE BATTLEBOT CLASS

int GetDistance(const BattleBot &bot1, const BattleBot &bot2)
{
    int distance;
    //checks direction
    if(bot1.direction == 'n')
    {
        // checks if the bots are on the same line
        if(bot1.x == bot2.x)
        {
            // checks if bot 2 is behind the bot1
            if(bot2.y > bot1.y)
            {
                // calculates distance
                distance = bot2.y - bot1.y;
                // checks if the distance is between 1-4
                if (distance >= 1 && distance <= 4)
                {
                    return distance;
                }
                    // checks if the distance ins between -1 and -4 and makes it positive
                else if (distance >= -4 && distance <= -1)
                {
                    distance = distance*-1;
                    return distance;
                }
                else
                {
                    return -1;
                }
            }
            else
            {
                return -1;
            }
        }
        else
        {
            return -1;
        }
    }
    else if(bot1.direction == 'e')
    {
        // checks if the bots are on the same line
        if(bot1.y == bot2.y)
        {
            // checks if bot 2 is behind the bot1
            if(bot2.x > bot1.x)
            {
                // calculates distance
                distance = bot2.x - bot1.x;
                // checks if the distance is between 1-4
                if (distance >= 1 && distance <= 4)
                {
                    return distance;
                }
                    // checks if the distance ins between -1 and -4 and makes it positive
                else if (distance >= -4 && distance <= -1)
                {
                    distance = distance*-1;
                    return distance;
                }
                else
                {
                    return -1;
                }
            }
            else
            {
                return -1;
            }
        }
        else
        {
            return -1;
        }
    }
    else if(bot1.direction == 's')
    {
        // checks if the bots are on the same line
        if(bot1.x == bot2.x)
        {
            // checks if bot 2 is behind the bot1
            if(bot1.y > bot2.y)
            {
                // calculates distance
                distance = bot2.y - bot1.y;
                // checks if the distance is between 1-4
                if (distance >= 1 && distance <= 4)
                {
                    return distance;
                }
                    // checks if the distance ins between -1 and -4 and makes it positive
                else if (distance >= -4 && distance <= -1)
                {
                    distance = distance*-1;
                    return distance;
                }
                else
                {
                    return -1;
                }
            }
            else
            {
                return -1;
            }
        }
        else
        {
            return -1;
        }
    }
    else if(bot1.direction == 'w')
    {
        // checks if the bots are on the same line
        if(bot1.y == bot2.y)
        {
            // checks if bot 2 is behind the bot1
            if(bot1.x > bot2.x)
            {
                // calculates distance
                distance = bot2.x - bot1.x;
                // checks if the distance is between 1-4
                if (distance >= 1 && distance <= 4)
                {
                    return distance;
                }
                    // checks if the distance ins between -1 and -4 and makes it positive
                else if (distance >= -4 && distance <= -1)
                {
                    distance = distance*-1;
                    return distance;
                }
                else
                {
                    return -1;
                }
            }
            else
            {
                return -1;
            }
        }
        else
        {
            return -1;
        }
    }
    return 0;
}

BattleBot::BattleBot()
{
    x = 0;
    y = 0 ;
    direction = 'n';
    health = 100;
}

BattleBot::BattleBot(int a, int b, char constructerDirection)
{
    x = a;
    y = b;
    direction = constructerDirection;
    health = 100;
}

void BattleBot::Move()
{
    leftLeg.Step();
    rightLeg.Step();

    if(direction == 'n')
    {
        y += 1;
    }
    else if(direction == 'e')
    {
        x += 1;
    }
    else if(direction == 's')
    {
        y -= 1;
    }
    else if(direction == 'w')
    {
        x -= 1;
    }
}

void BattleBot::Turn(char d)
{
    // originally facing north
    if(direction == 'n' && d == 'r')
    {
        direction = 'e';
    }
    else if(direction == 'n' && d == 'l')
    {
        direction = 'w';
    }

    // originally facing east
    if(direction == 'e' && d == 'r')
    {
        direction = 's';
    }
    else if(direction == 'e' && d == 'l')
    {
        direction = 'n';
    }

    // originally facing south
    if(direction == 's' && d == 'r')
    {
        direction = 'w';
    }
    else if(direction == 's' && d == 'l')
    {
        direction = 'e';
    }

    // originally facing west
    if(direction == 'w' && d == 'r')
    {
        direction = 'n';
    }
    else if(direction == 'w' && d == 'l')
    {
        direction = 's';
    }

}

void BattleBot::fire(BattleBot &target)
{
    int temp;
    launcher.Load();
    launcher.Fire();
    temp = GetDistance(*this, target);
    if (temp != -1)
    {
        if(temp == 1)
        {
            target.Hit(10);
            cout << "Target was shot with 10 damage!" << endl;
        }
        else if (temp == 2)
        {
            target.Hit(5);
            cout << "Target was shot with 5 damage!" << endl;
        }
        else if(temp == 3)
        {
            target.Hit(4);
            cout << "Target was shot with 4 damage!" << endl;
        }
        else if(temp == 4)
        {
            target.Hit(3);

            cout << "Target was shot with 3 damage!" << endl;
        }
        else
        {
            cout << "The target is not in line of sight, The shot missed !!" << endl;
        }
    }
    else
    {
        cout << "The target is not in line of sight, The shot missed !!" << endl;
    }
}

void BattleBot::RightPunch(BattleBot &target)
{
    rightArm.Punch();
    int temp;
    temp = GetDistance(*this, target);
    if (temp != -1)
    {
        if(temp == 1)
        {
            target.Hit(5);
            cout << "Target was punched(right) with 5 damage!" << endl;
        }
        else if (temp == 2)
        {
            target.Hit(3);
            cout << target.health << endl;
            cout << "Target was punched(right) with 3 damage!" << endl;
        }
        else
        {
            cout << "The target is not in line of sight, The punch missed !!" << endl;
        }
    }
    else
    {
        cout << "The target is not in line of sight, The punch missed !!" << endl;
    }
}

void BattleBot::LeftPunch(BattleBot &target)
{
    leftArm.Punch();
    int temp;
    temp = GetDistance(*this, target);
    if (temp != -1)
    {
        if(temp == 1)
        {
            target.Hit(5);
            cout << "Target was punched(left) with 5 damage!" << endl;
        }
        else if (temp == 2)
        {
            target.Hit(3);
            cout << "Target was punched(left) with 3 damage!" << endl;
        }
        else
        {
            cout << "The target is not in line of sight, The punch missed !!" << endl;
        }
    }
    else
    {
        cout << "The target is not in line of sight, The punch missed !!" << endl;
    }
}

void BattleBot::RightKick(BattleBot &target)
{
    rightLeg.Kick();
    int temp;
    temp = GetDistance(*this, target);
    if (temp != -1)
    {
        if(temp == 1)
        {
            target.Hit(3);
            cout << "Target was kicked(right) with 3 damage!" << endl;
        }
        else
        {
            cout << "The target is not in line of sight, The kick missed !!" << endl;
        }
    }
    else
    {
        cout << "The target is not in line of sight, The kick missed !!" << endl;
    }
}

void BattleBot::LeftKick(BattleBot &target)
{
    leftLeg.Kick();
    int temp;
    temp = GetDistance(*this, target);
    if (temp != -1)
    {
        if(temp == 1)
        {
            target.Hit(3);
            cout << "Target was kicked(left) with 3 damage!" << endl;
        }
        else
        {
            cout << "The target is not in line of sight, The kick missed !!" << endl;
        }
    }
    else
    {
        cout << "The target is not in line of sight, The kick missed !!" << endl;
    }
}

int BattleBot::GetHealth()
{
    return health;
}

void BattleBot::Hit(int d)
{
    health = health-d;
}

char BattleBot::GetDirection()
{
    return direction;
}

int BattleBot::GetX()
{
    return x;
}

int BattleBot::GetY()
{
    return y;
}

ostream& operator<<(ostream& s, BattleBot bot)
{
    s << "bot position: "<<"(" << bot.x << "," << bot.y << ")" << "\n"<< "Bot Direction : " << bot.direction << "\n" << "Bot Health: " << bot.health << endl;
    return s;
}



