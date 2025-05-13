#ifndef MAIN_H
#define MAIN_H

#include "gba.h"

// TODO: Create any necessary structs
struct Point {
    int row;
    int col;
};

struct bunny {
    int length;
    struct Point currCorrd;
    struct Point prevCorrd;
    struct Point topLeft;
    struct Point bottomLeft;
    struct Point topRight;
    struct Point bottomRight;
};
struct animationBunny {
    int length;
    int faceingRight; //0=left and 1=right
    int moving; //0=us moving next and 1= use sitting next
    struct Point currCorrd;
    
};

struct bush {
    int length;
    struct Point topLeftCorrd;
    struct Point bottomRightCorrd;
};
struct carrot {
    int length;
    struct Point topLeftCorrd;
    struct Point bottomRightCorrd;
    int removed; //0 = onscreen 1 = collected
};


// Array of 24 coordinates
const struct Point bushCoordinates[24] = {
    {13, 71}, {13, 115}, {13, 159}, {13, 203}, 

    {35, 38}, 
    {46, 71}, {46, 104}, {46, 203}, 
    {57, 5}, {57, 137},
    {68, 38}, 
    {79, 104}, {79, 181}, {79, 225}, 
    {90, 5}, {90, 137}, 
    
    {112, 38}, {112, 82},
    {123, 27}, {123, 159}, {123, 192}, {123, 225}, 
    
    {145, 60}, {145, 126}
};

void setInnerPoints(struct bunny *b) {
    b->topLeft.row = b->currCorrd.row + 6;
    b->topLeft.col = b->currCorrd.col + 6;

    b->topRight.row = b->currCorrd.row + 6;
    b->topRight.col = b->currCorrd.col + 17;

    b->bottomLeft.row = b->currCorrd.row + 17;
    b->bottomLeft.col = b->currCorrd.col + 6;
   
    b->bottomRight.row = b->currCorrd.row + 17;
    b->bottomRight.col = b->currCorrd.col + 17;
}

int touchObstacle(struct bush *bush, struct bunny *bunny) {
    for (int i = 0; i < 24; i++) {
        if (bush[i].topLeftCorrd.col <= bunny->topLeft.col && bunny->topLeft.col <= bush[i].bottomRightCorrd.col) {
            if(bush[i].topLeftCorrd.row <= bunny->topLeft.row && bunny->topLeft.row <= bush[i].bottomRightCorrd.row) {
            
                return 1;
            }
        } if (bush[i].topLeftCorrd.col <= bunny->topRight.col && bunny->topRight.col <= bush[i].bottomRightCorrd.col) {
            if (bush[i].topLeftCorrd.row <= bunny->topRight.row && bunny->topRight.row <= bush[i].bottomRightCorrd.row) {
            
                return 1;
            }
        } if (bush[i].topLeftCorrd.col <= bunny->bottomLeft.col && bunny->bottomLeft.col <= bush[i].bottomRightCorrd.col) {
            if (bush[i].topLeftCorrd.row <= bunny->bottomLeft.row && bunny->bottomLeft.row <= bush[i].bottomRightCorrd.row) {
            
                return 1;
            }
        } if (bush[i].topLeftCorrd.col <= bunny->bottomRight.col && bunny->bottomRight.col <= bush[i].bottomRightCorrd.col) {
            if (bush[i].topLeftCorrd.row <= bunny->bottomRight.row && bunny->bottomRight.row <= bush[i].bottomRightCorrd.row) {
            
                return 1;
            }
        } 
    }
    return 0;
}

int touchCarrot(struct carrot *carrot, struct bunny *bunny) {
    int count = 0;
    for (int i = 0; i < 8; i++) {   
        if (carrot[i].topLeftCorrd.col <= bunny->topLeft.col && bunny->topLeft.col <= carrot[i].bottomRightCorrd.col) {
            if(carrot[i].topLeftCorrd.row <= bunny->topLeft.row && bunny->topLeft.row <= carrot[i].bottomRightCorrd.row) {
                carrot[i].removed = 1;
                count = count+1;
            }
        } if (carrot[i].topLeftCorrd.col <= bunny->topRight.col && bunny->topRight.col <= carrot[i].bottomRightCorrd.col) {
            if (carrot[i].topLeftCorrd.row <= bunny->topRight.row && bunny->topRight.row <= carrot[i].bottomRightCorrd.row) {
                carrot[i].removed = 1;
                count = count+1;
            }
        } if (carrot[i].topLeftCorrd.col <= bunny->bottomLeft.col && bunny->bottomLeft.col <= carrot[i].bottomRightCorrd.col) {
            if (carrot[i].topLeftCorrd.row <= bunny->bottomLeft.row && bunny->bottomLeft.row <= carrot[i].bottomRightCorrd.row) {
                carrot[i].removed = 1;
                count = count+1;
            }
        } if (carrot[i].topLeftCorrd.col <= bunny->bottomRight.col && bunny->bottomRight.col <= carrot[i].bottomRightCorrd.col) {
            if (carrot[i].topLeftCorrd.row <= bunny->bottomRight.row && bunny->bottomRight.row <= carrot[i].bottomRightCorrd.row) {
                carrot[i].removed = 1;
                count = count+1;
            }
        }  
        
    }
    return count;
}

int spaceOccupied(struct bush *bush, struct carrot *c, struct carrot *array, int numofCarrots, int carrotIndex) {
    for (int i = 0; i < 24; i++) {
        if (bush[i].topLeftCorrd.col == c->topLeftCorrd.col && bush[i].topLeftCorrd.row == c->topLeftCorrd.row) {
            return 1;
        }
    }
    for (int i = 0; i < numofCarrots; i++) {
        if (array[i].topLeftCorrd.col == c->topLeftCorrd.col && array[i].topLeftCorrd.row == c->topLeftCorrd.row && i != carrotIndex) {
            return 1;
        }
    }
    return 0;
}

#endif
