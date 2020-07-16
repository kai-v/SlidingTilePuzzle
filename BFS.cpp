#include <stdint.h>
#include <queue>
#include <iostream>
#include <vector>
#include "BFS.h"
#include "BFSData.h"

using namespace std;

BFS::BFS(){
    // -1 to indicate none expanded
    expanded = -1;
}

bool BFS::GetPath(STP &stp, State &start, State &goal){
    
    cout << "START" << endl;
    start.print();
    
    cout << "GOAL" << endl;
    goal.print();
    
    // we have started on a graph
    expanded =0;
    
    // to search
    queue<BFSData> Q;
    BFSData s(start, start, 0);
    Q.push(s);
    
    while(!Q.empty()){
        
        BFSData curr = Q.front();
        Q.pop();
        cout << "EXPANDING" <<endl;
        curr.get_S().print();
        
        //expanding curr
        expanded ++;
        vector<State> succ;
        stp.GetSuccessors(curr.get_S(), succ);
        
        // check if a successor is the goal
        cout << "HAS " << succ.size() << " SUCCESSORS:" << endl;
        for(int i = 0; i < succ.size(); i++){
            
            succ[i].print();
            
            // is goal, reutrn
            if(succ[i] == goal){
                cout << "THATS THE GOAL!!!" << endl;
                // done!
                return true;
            }
            
            // if not parent, push
            else if(!(succ[i] == curr.get_parent())){
                cout << "here" << endl;
                BFSData temp(succ[i], curr.get_S(), curr.get_depth()+1);
                Q.push(temp);
            }
            
            // else nothing
            
            else{
                
            }
            
        }
    }
    
    return false;
}

uint64_t BFS::GetNodesExpanded(){
    
    return expanded;
}


