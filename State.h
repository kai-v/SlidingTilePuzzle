#ifndef STATE_H
#define STATE_H
#include <string>
#include <vector>

class State {
    
public:
    // constructor
    State(int m, int n);
    
    // copy constructor
    State(const State& orig);
    
    // equals operator
    bool operator==(const State& other) const;
    void reset();
    
    // swap two elements in tiles
    void swap(int x,int y);
    
    //getter for m
    int get_m(){
        
        return m;
        
    }
    
    // getter for n
    int get_n(){
        
        return n;
        
    }
    
    // getter for blank_tile_post
    int get_blank_tile_post(){
        
        return blank_tile_post;
        
    }
    
    //getter for tiles
    std::vector<std::string>& get_tiles(){
        
        return tiles;
        
    };
    
    void print();
    
    virtual ~State(){}
    
private:
    // size
    int m, n;
    
    // where the blank tile is , this speeds up operations
    int blank_tile_post;
    
    // tile, order left to right, top to bottom
    std::vector<std::string> tiles;
    
};

#endif /* STATE_H */

