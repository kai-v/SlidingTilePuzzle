
#include "STP.h"
#include "State.h"

#ifndef DFID_H
#define DFID_H

class DFID {
    
public:
    
    DFID();
    bool GetPath(STP &stp, State &start, State &goal);
    uint64_t GetNodesExpanded();
    
private:
    
    uint64_t expanded;
    bool DFS(STP& stp, State& start, State& goal, int dpt );
};

#endif /* DFID_H */

