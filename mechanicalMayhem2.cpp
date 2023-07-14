#include <iostream>
using namespace std;

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

    // Gear names: tooManyOne / orangeOne / smallOne / sunLookingOne / dontGoTogether / boatOne / spikeyOne / bigOne   

/*
    one.top = "boatOne"; one.bottom = "orangeOne"; one.right = "orangeOne"; one.left = "spikeyOne";
    two.top = "sunLookingOne"; two.bottom = "orangeOne"; two.right = "tooManyOne"; two.left = "tooManyOne";
    three.top = "smallOne"; three.bottom = "tooManyOne"; three.right = "bigOne"; three.left = "sunLookingOne";
    four.top = "tooManyOne"; four.bottom = "smallOne"; four.right = "sunLookingOne"; four.left = "orangeOne";
    five.top = "smallOne"; five.bottom = "boatOne"; five.right = "tooManyOne"; five.left = "sunLookingOne";
    six.top = "orangeOne"; six.bottom = "sunLookingOne"; six.right = "orangeOne"; six.left = "tooManyOne";
    seven.top = "orangeOne"; seven.bottom = "tooManyOne"; seven.right = "sunLookingOne"; seven.left = "orangeOne";
    eight.top = "orangeOne"; eight.bottom = "boatOne"; eight.right = "tooManyOne"; eight.left = "spikeyOne";
    nine.top = "tooManyOne"; nine.bottom = "tooManyOne"; nine.right = "spikeyOne"; nine.left = "sunLookingOne";
    ten.top = "dontGoTogether"; ten.bottom = "bigOne"; ten.right = "boatOne"; ten.left = "bigOne";
    eleven.top = "orangeOne"; eleven.bottom = "tooManyOne"; eleven.right = "sunLookingOne"; eleven.left = "boatOne";
    twelve.top = "smallOne"; twelve.bottom = "dontGoTogether"; twelve.right = "spikeyOne"; twelve.left = "smallOne";
    thirteen.top = "tooManyOne"; thirteen.bottom = "smallOne"; thirteen.right = "sunLookingOne"; thirteen.left = "bigOne";
    fourteen.top = "smallOne"; fourteen.bottom = "sunLookingOne"; fourteen.right = "tooManyOne"; fourteen.left = "sunLookingOne";
    fifteen.top = "sunLookingOne"; fifteen.bottom = "orangeOne"; fifteen.right = "smallOne"; fifteen.left = "tooManyOne";
    sixteen.top = "sunLookingOne"; sixteen.bottom = "orangeOne"; sixteen.right = "tooManyOne"; sixteen.left = "sunLookingOne";
*/

    string up, down, ri, le;
 //  int sq = 1;
 /*   
    while(sq < 17) {
        cout << "Gear on the top of tile #1: ";
        cin >> up;

        one.top = up;
        //(numToTile(sq)).top = up;

         //cout << one.top;
        cout << numToTile(sq).top;

        sq++;
    }
*/

    for(int i = 1; i <= 16; i++) {
        cout << "Top Gear on Tile #" << i << ": "; cin >> up; 
        cout << "Bottom Gear on Tile #" << i << ": "; cin >> down;
        cout << "Rightmost Gear on Tile #" << i << ": "; cin >> ri;
        cout << "Leftmost Gear on Tile #" << i << ": "; cin >> le;
        if(i == 1){ one.top = up; one.bottom = down; one.right = ri; one.left = le; }
        else if(i == 2){ two.top = up; two.bottom = down; two.right = ri; two.left = le; }
        else if(i == 3){ three.top = up; three.bottom = down; three.right = ri; three.left = le; }
        else if(i == 4){ four.top = up; four.bottom = down; four.right = ri; four.left = le; }
        else if(i == 5){ five.top = up; five.bottom = down; five.right = ri; five.left = le; }
        else if(i == 6){ six.top = up; six.bottom = down; six.right = ri; six.left = le; }
        else if(i == 7){ seven.top = up; seven.bottom = down; seven.right = ri; seven.left = le; }
        else if(i == 8){ eight.top = up; eight.bottom = down; eight.right = ri; eight.left = le; }
        else if(i == 9){ nine.top = up; nine.bottom = down; nine.right = ri; nine.left = le; }
        else if(i == 10){ ten.top = up; ten.bottom = down; ten.right = ri; ten.left = le; }
        else if(i == 11){ eleven.top = up; eleven.bottom = down; eleven.right = ri; eleven.left = le; }
        else if(i == 12){ twelve.top = up; twelve.bottom = down; twelve.right = ri; twelve.left = le; }
        else if(i == 13){ thirteen.top = up; thirteen.bottom = down; thirteen.right = ri; thirteen.left = le; }
        else if(i == 14){ fourteen.top = up; fourteen.bottom = down; fourteen.right = ri; fourteen.left = le; }
        else if(i == 15){ fifteen.top = up; fifteen.bottom = down; fifteen.right = ri; fifteen.left = le; }
        else if(i == 16){ sixteen.top = up; sixteen.bottom = down; sixteen.right = ri; sixteen.left = le; }
    }
    

    int tileOrder[16] = {0}, index = 0; // int array size 16 that representd the grid going from right to left starting from the top to the bottom
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

/*
    while(index > -1) { // code runs until we cant backtrack anymore
        index++;
        if(index == 16) { // prints the solution if we made it through all 16 spaces (0-15) succesfully, then backtrack
            print(tileOrder);
            index--;
        }
        else {
            tileOrder[index] = 0; // set value to 0 so goes to 1 when we increase it
        }
        while(index > -1) {
            tileOrder[index]++;
            if(tileOrder[index] == 17) { // if we ran out of tiles
                index--;
            }
            else {
                // rotate to original direction
            }
            while(___) {
                if(/* rotation at 5th option *//*) {
                    // backtrack?
                }
                else if(ok(tileOrder,index)) { // if we can put a tile in this spot, break out of the loop and go to the next space
                    break;
                }
            }
        }
    } */

    return 0;
}