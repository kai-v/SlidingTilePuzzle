#include "State.h"
#include "SlideDir.h"
#include <iostream>

State::State(int m, int n) {
    
    //init variables
    this->m = m;
    this->n = n;
    this->blank_tile_post = 0;
    
    //init blank tile
    tiles.push_back("BLANK");
    //init the rest
    for(int i = 1; i < m*n; i++){
        
        tiles.push_back(std::to_string(i));
    }
}

State::State(const State& orig) {
    
    m = orig.m;
    n = orig.n;
    blank_tile_post = orig.blank_tile_post;
    tiles = orig.tiles;
}

bool State::operator ==(const State& other) const{
    
    if(n == other.n && m == other.m && blank_tile_post == other.blank_tile_post && tiles == other.tiles){
        
        return true;
        
    }
    else{
        
        return false;
    }
}

void State::reset(){
    //set blank tile
    this->blank_tile_post = 0;
    tiles[0] = "BLANK";
    //set the rest
    for(int i = 1; i < m*n; i++){
        
        tiles[i] = std::to_string(i);
    }
}

void State::swap(int x, int y){
    
    if(tiles[x] == "BLANK"){
        
        blank_tile_post = y;
        
    }
    else if(tiles[y] == "BLANK"){
        
        blank_tile_post = x;
        
    }
    
    std::string temp = tiles[x];
    tiles[x] = tiles[y];
    tiles[y] = temp;
}

void State::print(){
    
    std::cout<<std::endl;
    for(int i = 0; i < m*n; i++){
        
        std::cout << "'" << tiles[i] << "'\t";
        
        if(i%n == n-1){
            
            std::cout<< "\n\n";
            
        }
    }
}





