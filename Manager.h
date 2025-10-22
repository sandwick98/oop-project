#ifndef MANAGER_H                                     
#define MANAGER_H

#include "Player.h"                                  
#include <vector>                                     // container for Player*
#include <string>                                     // log message strings
#include <iostream>                                   
using namespace std;                                  

// CLASS: Manager coordinates the duel (turns, HUD, victory checks, action log)
class Manager {
private:
    //A resizable list that keeps track of Player pointers (aggregation)
    vector<Player*> players;

    // ATTRIBUTE: turn — index of current player (0 or 1)
    int turn = 0; //starts with player 1

    // ATTRIBUTE: log views of the last few action strings 
    vector<string> log;

    // METHOD (helper): current returns pointer to the active player 
    Player* current() const { return players[turn]; }

    // METHOD (helper): other returns pointer to the opponent 
    Player* other()   const { return players[turn ^ 1]; }

public:
    // CONSTRUCTOR: default nothing to initialise beyond in-class defaults
    Manager() = default;

    // METHOD: addPlayer registers a Player* into the duel (expects 2 players before start)
    // Manager stores player pointers, but doesn’t free or delete them

    void addPlayer(Player* p) { players.push_back(p); }

    // METHOD (accessor): playerCount returns how many fighters are registered
    size_t playerCount() const { return players.size(); }

    // METHOD (accessor): currentTurn exposes the current turn index (0/1) for UI/tests
    int currentTurn() const { return turn; }

    // METHOD: startGame resets state and prints initial HUD/log
    void startGame();

    // METHOD: nextTurn advances to the next player (alternates between 0 and 1)
    void nextTurn();

    // METHOD: checkVictory returns true if duel is finished (KO or draw) and prints result
    bool checkVictory();

    // METHOD: printHUD — prints compact state view for both fighters (HP/STR/DEF + whose turn)
    void printHUD() const;

    // METHOD: pushLog adds a new action message and keeps only the latest 5
    void pushLog(const string& line);

    // METHOD: printLog renders the recent action lines for the player
    void printLog() const;

    // METHOD: 
    void runBattle();
};

#endif // MANAGER_H