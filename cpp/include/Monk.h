#pragma once
#include <string>

class Room;
class Monster;

class Monk {
public:
    Monk(const std::string& name, const std::string& description);
    void move(Room* room);
    void pray();
    void fight(Monster* monster);
    int getHealth() const { return health; }
    int getAttack() const { return attack; }
    const std::string& getName() const { return name; }
    const std::string& getDescription() const { return description; }

private:
    std::string name;
    std::string description;
    int health = 15;
    int attack = 3;
    Room* currentRoom = nullptr;

    bool performAction(int chance);
};
