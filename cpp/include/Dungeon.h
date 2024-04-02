#pragma once
#include <vector>
#include <memory>
#include <unordered_map>
#include "Room.h"

class Dungeon {
public:
    void generateDungeon();
    Room* getStartRoom() const { return rooms[startRoomIndex].get(); }
    Room* getTreasureRoom() const { return rooms[treasureRoomIndex].get(); }
    const std::unordered_map<Room*, std::vector<Room*>>& getRoomConnections() const { return roomConnections; }

private:
    std::vector<std::unique_ptr<Room>> rooms;
    std::size_t startRoomIndex = 0;
    std::size_t treasureRoomIndex = 0;
    std::unordered_map<Room*, std::vector<Room*>> roomConnections;
};
