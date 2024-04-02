#include "../include/Game.h"
#include "../include/Monster.h"
#include <iostream>
#include <string>

Game::Game() : dungeon(), monk("", "") {}
void Game::start() {
    dungeon.generateDungeon();

    std::cout << "Welcome to the Dungeon Explorer game!" << std::endl;
    std::cout << "Enter your monk's name: ";
    std::string name;
    std::getline(std::cin, name);

    std::cout << "Enter a short description for your monk: ";
    std::string description;
    std::getline(std::cin, description);

    monk = Monk(name, description);
    monk.move(dungeon.getStartRoom());

    std::cout << "Your monk, " << monk.getName() << ", has been created!" << std::endl;
    std::cout << "Description: " << monk.getDescription() << std::endl;
    std::cout << "Let the exploration begin!" << std::endl;

    explore();
}

void Game::explore() {
    Room* currentRoom = dungeon.getStartRoom();
    Room* treasureRoom = dungeon.getTreasureRoom();
    const auto& roomConnections = dungeon.getRoomConnections();

    while (currentRoom != treasureRoom && monk.getHealth() > 0) {
        std::cout << "You are in a " << static_cast<int>(currentRoom->getType()) << " room." << std::endl;

        if (currentRoom->getType() == RoomType::Empty) {
            char action;
            std::cout << "Enter 'p' to pray or 'm' to move: ";
            std::cin >> action;

            if (action == 'p') {
                monk.pray();
            } else if (action == 'm') {
                std::vector<Room*> connectedRooms = roomConnections.at(currentRoom);
                if (!connectedRooms.empty()) {
                    std::cout << "Connected rooms: ";
                    for (Room* room : connectedRooms) {
                        std::cout << static_cast<int>(room->getType()) << " ";
                    }
                    std::cout << std::endl;

                    std::cout << "Enter the room type to move to: ";
                    int roomType;
                    std::cin >> roomType;

                    bool found = false;
                    for (Room* room : connectedRooms) {
                        if (static_cast<int>(room->getType()) == roomType) {
                            monk.move(room);
                            currentRoom = room;
                            found = true;
                            break;
                        }
                    }

                    if (!found) {
                        std::cout << "Invalid room type!" << std::endl;
                    }
                } else {
                    std::cout << "No connected rooms!" << std::endl;
                }
            } else {
                std::cout << "Invalid action!" << std::endl;
            }
        } else if (currentRoom->getType() == RoomType::Monster) {
            Goblin goblin;
            monk.fight(&goblin);
        } else {
            std::cout << "You have reached the treasure room!" << std::endl;
            std::cout << "Congratulations! You have completed the game!" << std::endl;
            break;
        }
    }

    if (monk.getHealth() <= 0) {
        std::cout << "You have been defeated!" << std::endl;
    }
}
