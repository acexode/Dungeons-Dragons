#include "../include/Monk.h"
#include "../include/Room.h"
#include "../include/Monster.h"
#include <iostream>
#include <cstdlib>

Monk::Monk(const std::string& name, const std::string& description)
    : name(name), description(description) {}

void Monk::move(Room* room) {
    currentRoom = room;
    std::cout << "Moved to a " << static_cast<int>(room->getType()) << " room." << std::endl;
}

void Monk::pray() {
    if (currentRoom->getType() == RoomType::Empty) {
        health = 15;
        std::cout << "Health restored to 15." << std::endl;
    } else {
        std::cout << "Cannot pray in this room." << std::endl;
    }
}

void Monk::fight(Monster* monster) {
    std::cout << "Engaging in combat with a monster!" << std::endl;
    bool monsterTurn = true;
    int monsterHealth = monster->getHealth();
    int monkHealth = health;

    while (monsterHealth > 0 && monkHealth > 0) {
        std::cout << "Monk Health: " << monkHealth << ", Monster Health: " << monsterHealth << std::endl;

        if (monsterTurn) {
            std::cout << "Monster's turn: ";
            if (performAction(50)) {
                std::cout << "Attack!" << std::endl;
                monkHealth -= monster->getAttack();
            } else {
                std::cout << "Defend." << std::endl;
                monsterHealth += 1;
            }
        } else {
            std::cout << "Monk's turn: ";
            char action;
            std::cout << "Enter 'a' to attack or 'd' to defend: ";
            std::cin >> action;

            if (action == 'a') {
                std::cout << "Attack!" << std::endl;
                if (performAction(50)) {
                    monsterHealth -= attack;
                } else {
                    std::cout << "Attack failed." << std::endl;
                }
            } else if (action == 'd') {
                std::cout << "Defend." << std::endl;
                monkHealth += 1;
            } else {
                std::cout << "Invalid action." << std::endl;
            }
        }

        monsterTurn = !monsterTurn;
    }

    if (monkHealth <= 0) {
        std::cout << "Monk has been defeated!" << std::endl;
    } else {
        std::cout << "Monk has defeated the monster!" << std::endl;
    }

    health = monkHealth;
}

bool Monk::performAction(int chance) {
    return rand() % 100 < chance;
}
