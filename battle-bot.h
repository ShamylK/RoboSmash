#ifndef BATTLEBOT_BATTLE_BOT_H
#define BATTLEBOT_BATTLE_BOT_H

#include <iostream>

using namespace std;

class RoboArm;
class RoboLeg;
class ProjectileLauncher;
class BattleBot;

class RoboLeg
{
public:
    // default constructor
    RoboLeg();
    void Step();
    void Kick();
private:

    bool isRaised;
    // can be b-behind, u-under, f-in front
    char position;
    void liftLeg();
    void swing(char p);
    void lowerLeg();

};

class RoboArm
{
public:

    RoboArm();
    void Punch();

private:

    bool isDrawnBack;
    void drawBack();
    void thrust();

};

class ProjectileLauncher
{
public:

    ProjectileLauncher();
    void Load();
    void Fire();

private:

    bool isLoaded;
    bool checkLoaded();
};

class BattleBot
{
public:

    friend int GetDistance(const BattleBot& bot1, const BattleBot& bot2);
    BattleBot();
    BattleBot(int x, int y, char direction);
    void fire(BattleBot &target);
    void Move();
    // l is for left and r is for right
    void Turn(char d);
    void RightPunch(BattleBot &target);
    void LeftPunch(BattleBot &target);
    void RightKick(BattleBot &target);
    void LeftKick(BattleBot &target);
    int GetHealth();
    void Hit(int d);
    char GetDirection();
    int GetX();
    int GetY();
    friend ostream& operator<<(ostream& s, BattleBot bot);

private:

    RoboArm leftArm;
    RoboArm rightArm;
    RoboLeg leftLeg;
    RoboLeg rightLeg;
    ProjectileLauncher launcher;
    int x;
    int y;
    char direction;
    int health;

};

#endif //BATTLEBOT_BATTLE_BOT_H
