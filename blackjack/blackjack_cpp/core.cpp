#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../blackjack_hpp/core.hpp"
using std::cin;
using std::cout;
using std::endl;
using std::rand;
using std::string;
using std::to_string;
using std::vector;

void Core::initiateCards()
{
    vector<int> cards = {};
    for (int i = 1; i < 14; i++)
    {
        cards.push_back(i);
    }
    for (int i = 0; i < 4; i++)
    {
        this->cards.insert(this->cards.end(), cards.begin(), cards.end());
    }
};

void Core::initiateSuits()
{
    vector<string> spade = generateSuitvector("♠");
    vector<string> hearts = generateSuitvector("♥");
    vector<string> diamond = generateSuitvector("♦");
    vector<string> club = generateSuitvector("♣");
    this->suits.insert(this->suits.end(), spade.begin(), spade.end());
    this->suits.insert(this->suits.end(), hearts.begin(), hearts.end());
    this->suits.insert(this->suits.end(), diamond.begin(), diamond.end());
    this->suits.insert(this->suits.end(), club.begin(), club.end());
};

vector<string> Core::generateSuitvector(string suit)
{
    vector<string> suits = {};
    for (int i = 1; i < 14; i++)
    {
        suits.push_back(suit);
    }
    return suits;
}

void Core::play(string playerName, float playerBalance)
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    initiateCards();
    initiateSuits();

    while (1)
    {
        vector<int> currentCards = this->cards;
        vector<string> currentSuits = this->suits;
        bool newRound = true;
        Player house(1, "house", true, 0);
        Player player1(2, playerName, true, playerBalance);
        int option = 0;
        clear();
        cout << "Jogador " << player1.getName() << ", oq voce deseja fazer?" << endl
             << endl;
        cout << "1. Jogar uma rodada" << endl;
        cout << "2. Voltar ao menu principal" << endl;
        cout << "3. Ler como jogar black jack" << endl;

        cin >> option;
        if (option == 1)
        {
            option = 0;
            while (player1.getIsplaying() || house.getIsplaying())
            {
                if (player1.getIsplaying())
                {
                    while (option != 1 || option != 2)
                    {
                        clear();
                        if (newRound == true)
                        {
                            player1.setHand(generateHands(&currentCards, &currentSuits));
                            newRound = false;
                        }
                        cout << "Jogador " << player1.getName() << " , suas cartas são:" << endl
                             << endl;
                        printCards(player1);

                        cout << "1. Pedir por uma nova carta" << endl;
                        cout << "2. Parar de jogar" << endl;

                        cin >> option;
                        if (option == 1)
                        {
                            Hand newhand = getNewcard(&currentCards, &currentSuits);
                            player1.insertNewcard(newhand.getCards()[0], newhand.getSuits()[0]);
                        }
                        else if (option == 2)
                        {
                            player1.setIsplaying(false);
                        }
                    }
                }
                else if (house.getIsplaying())
                {
                }
                else
                {
                    while (option != 1)
                    {
                        clear();
                        cout << "Essa rodada acabou" << endl
                             << endl;

                        cout << "Precione 1 para voltar" << endl
                             << endl;
                        cin >> option;
                    }
                }
            }
        }
        else if (option == 3)
        {
            while (option != 1)
            {
                clear();
                cout << "Como jogar" << endl
                     << endl;

                cout << "Precione 1 para voltar" << endl
                     << endl;
                cin >> option;
            }
        }
        else
        {
            clear();
            return;
        }
    }
};

Hand *Core::generateHands(vector<int> *cards, vector<string> *suits)
{
    vector<int> handCards;
    vector<string> handSuits;
    for (size_t i = 0; i < 2; i++)
    {
        int numEle = verifynumElements(cards);
        int j = rand() % numEle;
        j--;
        handCards.push_back((*cards)[j]);
        handSuits.push_back((*suits)[j]);
        (*cards).erase((*cards).begin() + j);
        (*suits).erase((*suits).begin() + j);
    }

    Hand *hand = new Hand(handCards, handSuits);
    return hand;
};
Hand Core::getNewcard(vector<int> *cards, vector<string> *suits)
{
    vector<int> handCards;
    vector<string> handSuits;
    int numEle = verifynumElements(cards);
    int j = rand() % numEle;
    j--;
    handCards.push_back((*cards)[j]);
    handSuits.push_back((*suits)[j]);
    (*cards).erase((*cards).begin() + j);
    (*suits).erase((*suits).begin() + j);
    Hand hand(handCards, handSuits);
    return hand;
}
int Core::verifynumElements(vector<int> vector)
{
    int j = 0;
    for (auto i : vector)
    {
        j++;
    }
    return j;
};

int Core::verifynumElements(vector<string> vector)
{
    int j = 0;
    for (auto i : vector)
    {
        j++;
    }
    return j;
};

int Core::verifynumElements(vector<int> *vector)
{
    int j = 0;
    for (auto i : *vector)
    {
        j++;
    }
    return j;
};

int Core::verifynumElements(vector<string> *vector)
{
    int j = 0;
    for (auto i : *vector)
    {
        j++;
    }
    return j;
};
void Core::printCards(Player player)
{
    for (int i = 0; i < verifynumElements(player.getHand()->getCards()); i++)
    {
        cout << verifyCard(player.getHand()->getCards()[i]) << player.getHand()->getSuits()[i];
        if (i == (verifynumElements(player.getHand()->getCards()) - 1))
        {
            cout << endl
                 << endl;
        }
        else
        {
            cout << ", ";
        }
    }
}
string Core::verifyCard(int card)
{
    if (card == 1 || card > 10)
    {
        switch (card)
        {
        case 1:
            return "A";
            break;
        case 11:
            return "J";
            break;
        case 12:
            return "Q";
            break;
        case 13:
            return "K";
            break;

        default:
            break;
        }
    }
    return to_string(card);
}

void Core::clear()
{
    system("cls");
}