#include <iostream>
#include <iomanip>
using namespace std;

struct tileNum { // create a struct called "tileNumber" that has four string characteristics (top, right, bottom, left)
    string top;
    string bottom;
    string right;
    string left;
//    int orientation;
};

tileNum one, two, three, four;

tileNum numToTile(int x) { // function to convert a number into a tile
    if(x == 1) return one; if(x == 2) return two; if(x == 3) return three; if(x == 4) return four; 
}

void placeGears(tileNum& x, string t, string b, string r, string l) {
    x.top = t; x.bottom = b; x.right = r; x.left = l;
}

bool ok(int order[], int index) { 
    int helper[4][3] = {{-1,0,0},{0,-1,0},{0,-1,0},{2,1,-1}};

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
            if(numToTile(order[index]).top != numToTile(order[index-2]).bottom) { // the tileNum (represented by an actual number) at order[index] .top must== the tileNum (represented by an actual number) at order[index-4] .bottom
                return false;
            }
        }
    }
    return true;
}

// recheck this
void print(int solution[]) {
    for(int i = 0; i < 4; i=i+2) {
        for(int j = 0; j < 2; j++) {
            cout << left << setw(5) << solution[i+j] << " ";
        }
        cout << endl;
    }
}

// void rotate(tileNum &x) {
//     string temp = x.top;
//     x.top = x.right;
//     x.right = x.bottom;
//     x.bottom = x.left;
//     x.left = temp;
//     if (x.orientation == 4) x.orientation = 1;
//     else x.orientation++;
// }

int main(){

    // int numberOfRotations;

    placeGears(one, "smallOne" , "tooManyOne" , "bigOne" , "sunLookingOne");
    placeGears(two, "tooManyOne" , "smallOne" , "sunLookingOne" , "bigOne");
    placeGears(three, "tooManyOne" , "smallOne" , "sunLookingOne" , "orangeOne");
    placeGears(four, "smallOne" , "boatOne" , "tooManyOne" , "sunLookingOne");

    // one.orientation = 1; two.orientation = 1; three.orientation = 1; four.orientation = 1;
    
    int tileOrder[4], index = 0; // int array size 16 that representd the grid going from right to left starting from the top to the bottom
    tileOrder[index] = 1;
    bool isSolution = false;

    while(index > -1) { // code runs until we cant backtrack anymore
        index++;
        if(index == 4) { // prints the solution if we made it through all 16 spaces (0-15) succesfully, then backtrack
            isSolution = true;
            print(tileOrder);
            index--;
        }
        else {
            tileOrder[index] = 0; // set row to 0 so goes to 1 when we increase it
        }
        while(index > -1) {
            tileOrder[index]++;
            if(tileOrder[index] == 5) { // if we ran out of tiles
                index--;
            }
            // else { 
                // while(numToTile(tileOrder[index]).orientation != 4) { // set orientation to 4 so goes to 1 when we rotate it
                //     rotate(numToTile(tileOrder[index]));
                // }
                // numberOfRotations = 0;
            // }
            // while(tileOrder[index] > 0) {
                // rotate(numToTile(tileOrder[index]));
                // numberOfRotations++;
                // if(numberOfRotations == 5) {
                //     tileOrder[index]--; // backtrack
                // }
            else if(ok(tileOrder,index)) { // if we can put a tile in this spot, break out of the loop and go to the next space
                break;
            }
        }
    }
    if(!isSolution) {
        cout << "No solution";
    }
    return 0;
}