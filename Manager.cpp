#include "Manager.h"                                  // include own declaration

// METHOD IMPLEMENTATION: startGame
// WHAT: begins a new duel; sets turn to Player 1; prints initial HUD and (empty) log
// WHY: centralised entry point for main() so game restarts are consistent
void Manager::startGame() {
    cout << "== New Duel Started ==" << endl;       // banner: user feedback
    turn = 0;                                         // rule: Player 1 starts
    printHUD();                                       // show initial fighter states
    printLog();                                       // show empty/initial log area
}

// METHOD IMPLEMENTATION: nextTurn
// WHAT: toggles current player after a valid action
// WHY: core of turn-based flow; safe if players not yet set
void Manager::nextTurn() {
    if (players.empty()) return;                      // guard: avoid divide by zero
    turn = (turn + 1) % players.size();               // alternate 0 ↔ 1 using modulo
}

// METHOD IMPLEMENTATION: checkVictory
// WHAT: determines if duel is over (single KO or simultaneous KO)
// RETURNS: true if finished; also prints outcome and pushes a log line
bool Manager::checkVictory() {
    // branch: both down → draw (only meaningful when exactly 2 fighters)
    if (players.size() == 2 &&
        players[0]->get_hp() <= 0 && players[1]->get_hp() <= 0) {
        cout << "Both fighters are down! It's a draw.\n";          // announce draw
        pushLog("Simultaneous KO → Draw");                         // log event
        printLog();                                                // show log
        return true;                                               // stop duel
    }

    // branch: single KO → somebody defeated
    for (auto* p : players) {                                      // examine each fighter
        if (p->get_hp() <= 0) {                                    // KO condition
            cout << p->get_name() << " has been defeated!\n";      // announce KO
            pushLog(p->get_name() + " is KO");                     // log event
            printLog();                                            // show log
            return true;                                           // duel ends
        }
    }
    return false;                                                  // no victory yet
}

// METHOD IMPLEMENTATION: printHUD
// WHAT: draws a compact status table + whose turn
// CONST: read-only — does not modify Manager or Players
void Manager::printHUD() const {
    cout << "\n===== Battle Status =====\n";                        // header
    for (auto* p : players) {                                      // list fighters
        cout << p->get_name()                                      // Name
             << " | HP: " << p->get_hp()                           // Health points
             << " | STR: " << p->get_strength()                    // Strength
             << " | DEF: " << p->get_defense() << '\n';            // Defense
    }
    cout << "Turn: P" << (turn + 1) << "\n";                       // show active player (1-based)
    cout << "=========================\n";                          // footer
}

// METHOD IMPLEMENTATION: pushLog
// WHAT: appends a message and caps the history to last 5
// WHY: keeps UI readable while still providing recent context
void Manager::pushLog(const string& line) {
    log.push_back(line);                                           // add newest message
    if (log.size() > 5) log.erase(log.begin());                    // cut oldest if > 5
}

// METHOD IMPLEMENTATION: printLog
// prints the rolling action list (or placeholder when empty)
// CONST: read-only; does not mutate log or other state
void Manager::printLog() const {
    if (log.empty()) {                                             // nothing recorded yet
        cout << "--- No recent actions ---\n";                     // placeholder UI
        return;
    }
    cout << "--- Recent Actions ---\n";                            // header
    for (const auto& s : log) cout << s << '\n';                   // each logged action
    cout << "----------------------\n";                             // footer
}