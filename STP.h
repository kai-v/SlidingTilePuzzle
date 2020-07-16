#ifndef STP_H
#define STP_H
#include "State.h"
#include "SlideDir.h"
#include <vector>

class STP {
    
public:
    
    void test();
    void GetSuccessors(State nodeID, std::vector<State> &actions);
    void GetOperators(State &nodeID, std::vector<SlideDir> &operators);
    void ApplyOperator(State &s, SlideDir o);
    void UndoOperator(State &s, SlideDir o);
    
};

#endif /* STP_H */

