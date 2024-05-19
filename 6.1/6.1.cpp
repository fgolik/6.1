#include <iostream>
#include <string>

using namespace std;

class Entity 
{
protected:
    int x;
    int y;

public:
    Entity(int x, int y) : x(x), y(y) {}

    virtual void displayInfo() const 
    {
        cout << "Coordinates: (" << x << ", " << y << ")";
    }
};

class Stone : public Entity 
{
private:
    int imageId;

public:
    Stone(int x, int y, int imageId) : Entity(x, y), imageId(imageId) {}

    void displayInfo() const override 
    {
        Entity::displayInfo();
        cout << ", Image ID: " << imageId << endl;
    }
};

class Chest : public Entity 
{
private:
    unsigned int width;
    unsigned int height;
    unsigned int goldCoins;

public:
    Chest(int x, int y, unsigned int width, unsigned int height, unsigned int goldCoins)
        : Entity(x, y), width(width), height(height), goldCoins(goldCoins) {}

    void displayInfo() const override 
    {
        Entity::displayInfo();
        cout << ", Width: " << width << ", Height: " << height << ", Gold Coins: " << goldCoins << endl;
    }
};

class Trader : public Entity 
{
private:
    int itemType;
    int itemCount;

public:
    Trader(int x, int y, int itemType, int itemCount) : Entity(x, y), itemType(itemType), itemCount(itemCount) {}

    void displayInfo() const override 
    {
        Entity::displayInfo();
        cout << ", Item Type: " << itemType << ", Item Count: " << itemCount << endl;
    }
};

class Player : public Entity 
{
private:
    unsigned char red;
    unsigned char green;
    unsigned char blue;
    string name;

public:
    Player(int x, int y, unsigned char red, unsigned char green, unsigned char blue, const std::string& name)
        : Entity(x, y), red(red), green(green), blue(blue), name(name) {}

    void displayInfo() const override {
        Entity::displayInfo();
        cout << ", Color: (" << static_cast<int>(red) << ", " << static_cast<int>(green) << ", " << static_cast<int>(blue) << "), Name: " << name << endl;
    }
};

int main() {
    Stone stone(10, 20, 1001);
    Chest chest(15, 25, 30, 40, 50);
    Trader trader(20, 30, 1, 10);
    Player player(25, 35, 255, 0, 0, "Player1");

    stone.displayInfo();
    chest.displayInfo();
    trader.displayInfo();
    player.displayInfo();

    return 0;
}