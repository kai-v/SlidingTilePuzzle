#include "BFSData.h"

BFSData::BFSData(State S_, State parent_, int depth):

S(S_),
parent(parent_){
    this->depth = depth;
}

State BFSData:: get_parent(){
    
    return parent;
}

void BFSData::set_parent(State p){
    
    parent =  p;
}

int BFSData::get_depth(){
   
    return depth;
}

void BFSData:: set_depth(int d){
   
    depth = d;
}

State BFSData:: get_S(){
    
    return S;
}

void BFSData:: set_S( State s){
   
    S = s;
}
