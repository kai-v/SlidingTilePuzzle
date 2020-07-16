#include "STP.h"
#include <iostream>

void STP::test(){
    
    std::cout << "I seem to be working" << std::endl;
}

void STP::GetSuccessors(State nodeID, std::vector<State> &actions){
    
    int m = nodeID.get_m();
    int n = nodeID.get_n();
    int blank = nodeID.get_blank_tile_post();
    
    // If Blank Can be moved up
    if(blank - n >= 0){
        
        State newNode(nodeID);
        newNode.swap(blank, blank - n);
        actions.push_back(newNode);
    }
    
    // If Blank Can be moved down
    if(blank + n <= n*m-1){
        
        State newNode(nodeID);
        newNode.swap(blank, blank + n);
        actions.push_back(newNode);
    }
    
    // If Blank Can be moved right
    if((blank + 1) < m*n && (blank + 1)%n != 0){
        State newNode(nodeID);
        newNode.swap(blank, blank + 1);
        actions.push_back(newNode);
    }
    
    // If Blank Can be moved left
    if((blank - 1) >= 0 && (blank - 1)%n != n-1){
        State newNode(nodeID);
        newNode.swap(blank, blank - 1);
        actions.push_back(newNode);
    }
    
}

void STP::GetOperators(State &nodeID, std::vector<SlideDir> &operators){
    int m = nodeID.get_m();
    int n = nodeID.get_n();
    int blank = nodeID.get_blank_tile_post();
    
    // If Blank Can be moved up
    if(blank - n >= 0){
        
        SlideDir newOp = up;
        operators.push_back(up);
    }
    // If Blank Can be moved down
    if(blank + n <= n*m-1){
        
        SlideDir newOp = down;
        operators.push_back(down);
    }
    // If Blank Can be moved right
    if((blank + 1) < m*n && (blank + 1) % n != 0){\
        
        SlideDir newOp = right;
        operators.push_back(right);
    }
    
    // If Blank Can be moved left
    if((blank - 1) >= 0 && (blank - 1)%n != n-1){
        
        SlideDir newOp = left;
        operators.push_back(left);
    }
}

void STP::ApplyOperator(State &s, SlideDir o){
    
    int blank = s.get_blank_tile_post();
    int n = s.get_n();
    
    switch(o) {
            
        case up :
            s.swap(blank, blank - n);
            break;
            
        case down :
            s.swap(blank, blank + n);
            break;
            
        case left :
            s.swap(blank, blank-1);
            break;
            
        case right :
            s.swap(blank, blank+1);
            break;
    }
}

void STP::UndoOperator(State &s, SlideDir o){
    
    int blank = s.get_blank_tile_post();
    int n = s.get_n();
    
    switch(o) {
            
        case up :
            s.swap(blank, blank + n);
            break;
            
        case down :
            s.swap(blank, blank - n);
            break;
            
        case left :
            s.swap(blank, blank+1);
            break;
            
        case right :
            s.swap(blank, blank-1);
            break;
    }
}
