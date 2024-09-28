//
// Created by David Gaitros on 4/9/23.
//
#ifndef DICE_H
#define DICE_H
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
using namespace std;
const int MINIMUMTHROWS=2;
const int MAXIMUMTHROWS=9;
const int DEFAULTTHROWS=2;
class Dice {
public:
    Dice();
    Dice(const int t);
    void Roll();
    void PrintDice();
    void SetThrows(const int t);
    int GetThrows();
    int GetSum();
private:
    void ClearDice();
    int throws;
    int dice_values[MAXIMUMTHROWS];
    int sum;
};
#endif //DICE_H
