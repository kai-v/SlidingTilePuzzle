#include "State.h"
#include "STP.h"

#ifndef BFS_H
#define BFS_H

class BFS {
    
public:
    
    BFS();
    bool GetPath(STP &stp, State &start, State &goal);
    uint64_t GetNodesExpanded();
    
private: 
    
    uint64_t expanded;
};

#endif /* BFS_H */

