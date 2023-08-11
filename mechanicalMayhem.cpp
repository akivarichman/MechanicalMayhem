#include <iostream>
using namespace std;

// - have to check user input
//    - empty white space
//    - do I care about capital vs lowercase
//    - there should be a message for no solution 

struct tileNum { // create a struct called "tileNumber" that has four string characteristics (top, right, bottom, left)
    string top;
    string bottom;
    string right;
    string left;
};

tileNum one, two, three, four, five, six, seven, eight, nine, ten, eleven, twelve, thirteen, fourteen, fifteen, sixteen;
tileNum *p1 = &one; tileNum *p2 = &two; tileNum *p3 = &three; tileNum *p4 = &four; tileNum *p5 = &five;
tileNum *p6 = &six; tileNum *p7 = &seven; tileNum *p8 = &eight; tileNum *p9 = &nine; tileNum *p10 = &ten;
tileNum *p11 = &eleven; tileNum *p12 = &twelve; tileNum *p13 = &thirteen; tileNum *p14 = &fourteen; 
tileNum *p15 = &fifteen; tileNum *p16 = &sixteen;

tileNum numToTile(int x) { // function to convert a number into a tile
    if(x == 1) return one; if(x == 2) return two; if(x == 3) return three; if(x == 4) return four; 
    if(x == 5) return five; if(x == 6) return six; if(x == 7) return seven; if(x == 8) return eight; 
    if(x == 9) return nine; if(x == 10) return ten; if(x == 11) return eleven; if(x == 12) return twelve; 
    if(x == 13) return thirteen; if(x == 14) return fourteen; if(x == 15) return fifteen; 
    else return sixteen;
}

void placeGears(tileNum *x, string t, string b, string r, string l) {
    (*x).top = t; (*x).bottom = b; (*x).right = r; (*x).left = l;
}

bool ok(int order[], int index) { 
    int helper[16][3] = {{-1,0,0},{0,-1,0},{1,-1,0},{2,-1,0},{0,-1,0},{1,4,-1},{2,5,-1},{3,6,-1},{4,-1,0},{5,8,-1},{6,9,-1},{7,10,-1},{8,-1,0},{9,12,-1},{10,13,-1},{11,14,-1}};

    for(int i = 0; i < index; i++) { // make sure tile wasn't used yet
        if(order[i] == order[index]){
            return false;
        }
    }

    for(int i = 0; helper[index][i] != -1; i++) {
        if(helper[index][i] == index - 1){
            if(numToTile(order[index]).left != numToTile(order[index-1]).right) { // the tileNum (represented by an actual number) at order[index] .left must== the tileNum (represented by an actual number) at order[index-1] .right
                return false;
            }
        }
        else {
            if(numToTile(order[index]).top != numToTile(order[index-4]).bottom) { // the tileNum (represented by an actual number) at order[index] .top must== the tileNum (represented by an actual number) at order[index-4] .bottom
                return false;
            }
        }
    }
    return true;
}

void print(int solution[]) {
    for(int i = 0; i < 16; i=i+4) {
        for(int j = 0; j < 4; j++) {
            cout << solution[i+j] << " ";
        }
        cout << endl;
    }
}

int main(){

    // Gear names: tooManyOne / orangeOneOne / smallOne / sunLookingOne / dontGoTogether / boatOne / spikeyOneyOne / bigOne   
    // Directions: top / bottom / right / left
    
    placeGears(p13, "tooManyOne" , "smallOne" , "sunLookingOne" , "bigOne");
    placeGears(p2,"sunLookingOne","orangeOne", "tooManyOne" , "tooManyOne");
    placeGears(p10, "dontGoTogether" , "bigOne" , "boatOne" , "bigOne");
    placeGears(p9, "tooManyOne" , "tooManyOne" , "spikeyOne" , "sunLookingOne");
    placeGears(p1, "boatOne" , "orangeOne" , "orangeOne" , "spikeyOne");
    placeGears(p6, "orangeOne" , "sunLookingOne" , "orangeOne" , "tooManyOne");
    placeGears(p3, "smallOne" , "tooManyOne" , "bigOne" , "sunLookingOne");
    placeGears(p4, "tooManyOne" , "smallOne" , "sunLookingOne" , "orangeOne");
    placeGears(p5, "smallOne" , "boatOne" , "tooManyOne" , "sunLookingOne");
    placeGears(p14, "smallOne" , "sunLookingOne" , "tooManyOne" , "sunLookingOne");
    placeGears(p16, "sunLookingOne" , "orangeOne" , "tooManyOne" , "sunLookingOne");
    placeGears(p12, "smallOne" , "dontGoTogether" , "spikeyOne" , "smallOne");
    placeGears(p11, "orangeOne" , "tooManyOne" , "sunLookingOne" , "boatOne");
    placeGears(p15, "sunLookingOne" , "orangeOne" , "smallOne" , "tooManyOne");
    placeGears(p8, "orangeOne" , "boatOne" , "tooManyOne" , "spikeyOne");
    placeGears(p7, "orangeOne" , "tooManyOne" , "sunLookingOne" , "orangeOne");

    int tileOrder[16], index = 0; // int array size 16 that representd the grid going from right to left starting from the top to the bottom
    tileOrder[index] = 1;

    while(index > -1) { // code runs until we cant backtrack anymore
        index++;
        if(index == 16) { // prints the solution if we made it through all 16 spaces (0-15) succesfully, then backtrack
            print(tileOrder);
            index--;
        }
        else {
            tileOrder[index] = 0; // set row to 0 so goes to 1 when we increase it
        }
        while(index > -1) {
            tileOrder[index]++;
            if(tileOrder[index] == 17) { // if we ran out of tiles
                index--;
            }
            else if(ok(tileOrder,index)) { // if we can put a tile in this spot, break out of the loop and go to the next space
                break;
            }
        }
    }

    return 0;
}