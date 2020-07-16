#include "State.h"

#ifndef BFSDATA_H
#define BFSDATA_H

class BFSData {
    
public:
    
    BFSData(State s, State parent, int depth);
    
    State get_parent();
    void set_parent(State p);
    int get_depth();
    void set_depth(int d);
    State get_S();
    void set_S(State s);
    
private:
    
    State S;
    State parent;
    int depth;
};

#endif /* BFSDATA_H */

