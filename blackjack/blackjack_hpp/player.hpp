#ifndef PLAYER
#define PLAYER
#include <vector>
#include <string>
#include "./hand.hpp"

using std::vector;
using std::string;

class Player {
private:
    int id;
    string name;
    bool isplaying;
    Hand* hand;
    float balance;
public:
    Player(int id, string name, bool isplaying, float balance);
    int getId();
    string getName();
    bool getIsplaying();
    Hand* getHand();
    float getBalance();
    void setHand(Hand* Hand);
    void setIsplaying(bool status);
    void setBalance(float balance);
    void insertNewcard(int card, string suit);
};

#endif
