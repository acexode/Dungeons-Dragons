#pragma once

enum class RoomType { Empty, Monster, Treasure };

class Room {
public:
    virtual RoomType getType() const = 0;
    virtual ~Room() = default;
};

class EmptyRoom : public Room {
public:
    RoomType getType() const override { return RoomType::Empty; }
};

class MonsterRoom : public Room {
public:
    RoomType getType() const override { return RoomType::Monster; }
};

class TreasureRoom : public Room {
public:
    RoomType getType() const override { return RoomType::Treasure; }
};
