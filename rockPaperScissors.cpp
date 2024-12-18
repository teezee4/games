// RockPaperScissors.cpp
// Taha Zeeshan

#include <iostream>

using namespace std;

void optionMenu();
void validOption(int& option);
void convert(int num, string& result);

int main() {
    bool go = true;
    int option = 0;
    int playWin = 0;
    int compWin = 0;
    int draw = 0;
    int computerOpt = 0;
    string choice;
    string compChoice;
    
    while(go){
        optionMenu();
    
        validOption(option);
        
        convert(option, choice);
        
        srand(time(0));
        
        computerOpt = (rand() % 3) + 1;
        
        convert(computerOpt, compChoice);
        
        if(option == 4){
            cout << "Your win count: " << playWin << endl;
            cout << "Computer win count: " << compWin << endl;
            cout << "Draw count: " << draw << endl;
            go = false;
        }
        else{
            cout << "Your choice: " << choice << endl;
            cout << "Computer choice: " << compChoice << endl;
            
            if (option == computerOpt){
                cout << "Draw!" << endl;
                draw++;
            }
            if ((option == 1 && computerOpt == 2) || (option == 3 && computerOpt == 1) || (option == 2 && computerOpt == 3)){
                cout << "computer wins" << endl;
                compWin++;
            }
            if ((option == 1 && computerOpt == 3) || (option == 2 && computerOpt == 1) || (option == 3 && computerOpt == 2)){
                cout << "You win!!" << endl;
                playWin++;
            }
            cout << endl;
        }
        
    }
    return 0;
}

void optionMenu(){
    cout << "1. Rock\n" << "2. Paper\n" << "3. Scissors\n" << "4. Quit\n";
}

void validOption(int& option){
    bool invalidResponse = true;

    while(invalidResponse){

        cin >> option;

        if(cin.fail()){
            cin.clear();
            cin.ignore();
        }
        else if (option > 0 && option < 5){
            invalidResponse = false;
        }
        
        if (invalidResponse == true){
            cout << "\ninvalid, please enter a valid option: ";
        }
    }
}

void convert(int num, string& result){
    if (num == 1)
        result = "rock";
    if (num == 2)
        result = "paper";
    if (num == 3)
        result = "scissors";
}
