#pragma once
#include "Skill.h"
#include <string>
#include <iostream>
using namespace std;

class MultiTarget :
    public Skill
{
public:
    MultiTarget(string name, int damageCoefficient, int mpCost);
    ~MultiTarget();

    // Override parent's virtual function. There's no need to set this to virtual since we're not expecting this class to be inherited further.
    void activate(Unit* target);


private:
    int mDamageCoefficient;
};

