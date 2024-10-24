// monopolySimulation.cpp
// Taha Zeeshan

#include <iostream>

using namespace std;

void roll(int& dice);
void cards(int& num);

struct spots{
    int spotNum;
    string spotName;
};

int main() {
    spots board[40];
    int dice = 0;
    int card = 0;
    int landCount[40];
    int position = 1;
    int runCount = 0;
    
    srand(time(0));
    
    cout << "Simulation Running.\n";
    cout << "One chance spot, one chest spot, and one jail.\n";
    
    for(int i = 0; i < 40; i++){
        board[i].spotNum = (i + 1);
        board[i].spotName = "N/A";
    }
    
    for(int i = 0; i < 40; i++){
        landCount[i] = 0;
    }
    
    board[0].spotName = "go";
    board[9].spotName = "chance card";
    board[19].spotName = "jail";
    board[29].spotName = "community chest  card";
    
    for (int i = 0; i < 10000; i++){
        int outJail = 0;
        
        roll(dice);
        
        position += dice;
        
        if (position > 40){
            position = position - 40;
        }
        
        landCount[position - 1] += 1;
        int temp = position;
        
        if((position - 1) == 9){
            cards(card);
            
            if(card == 1 || card == 5){
                position += 3;
            }
            if(card == 2 || card == 6){
                position -= 3;
            }
            if(card == 3){
                position = 0;
            }
            if(card == 7){
                position = 19;
            }
            if(card == 4){
                outJail = 1;
            }
            if(card == 8){
                position = 4;
            }
            if(position != temp){
            landCount[position - 1] += 1;
            }
        }
        if((position - 1) == 29){
            cards(card);
            
            if(card == 1 || card == 5){
                position += 3;
            }
            if(card == 2 || card == 6){
                position -= 3;
            }
            if(card == 3){
                position = 0;
            }
            if(card == 7){
                position = 19;
            }
            if(card == 4){
                outJail = 1;
            }
            if(card == 8){
                position = 34;
            }
            if(position != temp){
            landCount[position - 1] += 1;
            }
        }
        if((position - 1) == 19){
            if(outJail == 1){
                outJail = 0;
            }
            else{
                i++;
            }
            landCount[position - 1] += 1;
        }
        
    }
    
    cout << "Monopoly Simulation Result:\n";
    
    for(int i = 0; i < 40; i++){
        int x = landCount[i];
        runCount += x;
    }
    
    for(int i = 0; i < 40; i++){
        cout << "spot "<< board[i].spotNum << ": "<< board[i].spotName;
        cout << "   landed on: " << landCount[i] << " times\n";
    }
    
    cout << "numbers of times position changed: " << runCount;
    
    return 0;
}

void roll(int& dice){
    
    dice = (rand() % 6) + 1;
}
void cards(int& num){
    
    num = (rand() % 16) + 1;
}
