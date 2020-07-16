#include "DFID.h"
#include "State.h"
#include <stdint.h>
#include <iostream>
#include <vector>
#include <stack>
#include <deque>

using namespace std;

DFID::DFID() {
    
    expanded = -1;
}

bool DFID::GetPath(STP& stp, State& start, State& goal){
    
    cout << "START" << endl;
    start.print();
    cout << "GOAL" << endl;
    goal.print();
    
    int d = 0 ;
    bool result;
    
    while(true){
        cout << "depth " <<  d << endl;
        result = DFS(stp, start, goal, d);
        cout << "depth " <<  d << " returned " << result << endl;
        if(result){return true;}
        
        d++;
    }
    
    return false;
}

uint64_t DFID::GetNodesExpanded(){
    
    return expanded;
    
}


bool DFID::DFS(STP &stp, State &start,State &goal, int depth){
    
    cout << "given state " << endl;
    start.print();
    
    if(depth == 0){
        
        if(start == goal){
            
            cout << "GOAL!" << endl;
            return true;
        }
    }
    
    else{
        
        expanded ++;
        vector<State> succ;
        stp.GetSuccessors(start, succ);
        
        for(int i = 0; i < succ.size(); i++){
            bool found = DFS(stp, succ[i], goal, depth-1);
            
            if(found){
                
                cout << "GOALS" << endl;
                return true;
            }
        }
    }
    
    return false;
}


