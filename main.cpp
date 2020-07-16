#include <iostream>
#include <time.h>
#include "State.h"
#include "SlideDir.h"
#include "STP.h"
#include "BFS.h"
#include "BFSData.h"
#include "DFID.h"

State DoRandomWalk_Op(STP &stp, State &s, int n){
    
    // reset to goal
    s.reset();
    
    // for each walk
    for(int i = 0; i <= n; i++){
        
        // get operators
        std::vector<SlideDir> ops;
        stp.GetOperators(s, ops);
        
        // choose random operator
        int ranIndex = rand() % ops.size();
        SlideDir op = ops[ranIndex];
        
        // alter state
        stp.ApplyOperator(s, op);        
    }
    return s;
}

State DoRandomWalk_Succ(STP &stp, State s, int n){
    
    // reset to goal
    s.reset();
    
    // for each walk
    for(int i = 0; i <= n; i++){
        // get Successors
        std::vector<State> states;
        stp.GetSuccessors(s, states);
        // pick random state to be current
        int ranIndex = rand() % states.size();
        s = states[ranIndex];
    }
    
    return s;
}

int main(int argc, char** argv) {
    
    STP stp;
    State goal(3, 10);
    State start = DoRandomWalk_Op(stp, goal, 10);
    goal.reset();
    
    BFS bfs;
    DFID dfid;
    
    std::cout << dfid.GetPath(stp, start, goal) << std::endl;
    std::cout  << "expanded: " << dfid.GetNodesExpanded() << std::endl;
    
    return 0;
}
