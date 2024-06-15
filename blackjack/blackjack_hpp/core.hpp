#ifndef CORE
#define CORE
#include <vector>
#include <string>
#include "../blackjack_hpp/player.hpp"
#include "../blackjack_hpp/hand.hpp"
using std::string;
using std::vector;

class Core{
    private:
    vector<int> cards;
    vector<string> suits;

    public:
    void initiateCards();
    void initiateSuits();
    vector<string> generateSuitvector(string suit);
    void play(string playerName, float playerBalance);
    Hand* generateHands(vector<int>* cards, vector<string>* suits);
    Hand getNewcard(vector<int>* cards, vector<string>* suits);
    int verifynumElements(vector<int> vector);
    int verifynumElements(vector<int>* vector);
    int verifynumElements(vector<string> vector);
    int verifynumElements(vector<string>* vector);
    void printCards(Player player);
    string verifyCard(int card);
    void clear();


};
#endif