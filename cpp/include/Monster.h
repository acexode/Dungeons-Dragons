#pragma once

class Monster {
public:
    virtual int getHealth() const = 0;
    virtual int getAttack() const = 0;
    virtual ~Monster() = default;
};

class Goblin : public Monster {
public:
    int getHealth() const override { return 10; }
    int getAttack() const override { return 2; }
};
