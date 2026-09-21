#ifndef LISTENER_HPP
#define LISTENER_HPP

class Listener {
public:
    // false inseamna iesire; true inseamna ca position contine o casuta 1..9.
    bool readMove(int& position) const;
};

#endif
