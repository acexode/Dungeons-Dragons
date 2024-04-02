#include "../include/Dungeon.h"

void Dungeon::generateDungeon() {
    // Create rooms
    std::unique_ptr<EmptyRoom> emptyRoom1 = std::make_unique<EmptyRoom>();
    std::unique_ptr<EmptyRoom> emptyRoom2 = std::make_unique<EmptyRoom>();
    std::unique_ptr<MonsterRoom> monsterRoom = std::make_unique<MonsterRoom>();
    std::unique_ptr<TreasureRoom> treasureRoom = std::make_unique<TreasureRoom>();

    // Add rooms to the dungeon
    rooms.push_back(std::move(emptyRoom1));
    rooms.push_back(std::move(emptyRoom2));
    rooms.push_back(std::move(monsterRoom));
    rooms.push_back(std::move(treasureRoom));

    // Set start and treasure room indices
    startRoomIndex = 0;
    treasureRoomIndex = 3;

    // Connect rooms
    roomConnections[rooms[0].get()] = { rooms[1].get(), rooms[2].get() };
    roomConnections[rooms[1].get()] = { rooms[0].get(), rooms[3].get() };
    roomConnections[rooms[2].get()] = { rooms[0].get(), rooms[3].get() };
    roomConnections[rooms[3].get()] = { rooms[1].get(), rooms[2].get() };
}
