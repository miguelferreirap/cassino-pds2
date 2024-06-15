#include <vector>
#include <string>
#include "../blackjack_hpp/player.hpp"
using std::string;
using std::vector;

Player::Player(int id, string name, bool isplaying, float balance) : id(id), name(name), isplaying(isplaying), balance(balance){};

int Player::getId()
{
    return this->id;
};

string Player::getName()
{
    return this->name;
};

bool Player::getIsplaying()
{
    return this->isplaying;
};

Hand *Player::getHand()
{
    return this->hand;
};
float Player::getBalance()
{
    return this->balance;
}
void Player::setHand(Hand *hand)
{
    this->hand = hand;
}

void Player::setIsplaying(bool status)
{
    this->isplaying = status;
};

void Player::setBalance(float balance)
{
    this->balance = balance;
};

 void Player::insertNewcard(int card, string suit){
    this->hand->insertCard(card);
    this->hand->insertSuit(suit);
 };
