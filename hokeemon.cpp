// hokeemon.cpp
// Taha Zeeshan

#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

//function prototypes
void greeting();
void start();
void menu();
void validInput(int& choice);

class creature{
public:
    int hunger;
    int bore;
    string name;
    string element;
    string technique;
    string spec;
    
    virtual int returnHunger() = 0;
    virtual  int returnBore() = 0;
};

// Child Class
class mon : public creature
{
public:
    void passTime();
    void displayTypes();
    void displayAll();
    void listen();
    void play();
    void feed();
    void die();
    void testMethod();
    
    //returns the hunger value
    int returnHunger(){
        return hunger;
    }
    //returns boredom value
    int returnBore(){
        return bore;
    }
    //returns species type
    string returnSpecies(){
        return spec;
    }
    //returns the element type
    string returnEl(){
        return element;
    }
    //returns technique type
    string returnTec(){
        return technique;
    }
    //returns its name
    string returnName(){
        return name;
    }
    //sets the hunger and boredom at random values
    void setStats(){
        hunger = (rand() % 6);
        bore = (rand() % 6);
    }
    //following used to combine 2 hokeemons
    //gets the name
    void getName(string n){
        name = n;
    }
    //gets the element
    void getEl(string n){
        element = n;
    }
    //gets the technique
    void getTec(string n){
        technique = n;
    }
    //gets the species
    void getSpec(string n){
        spec = n;
    }
    //gives random element, technique, and species
    void setTypes(){
        string elementTypes[5] = {"fire", "water", "earth", "air", "lightning"};
        string techniqueTypes[5] = {"jutsu", "cursed technique", "nen", "stand", "geass"};
        string specTypes[5] = {"ninja", "sorceror", "titan", "hunter", "ghoul"};
        
        element = elementTypes[(rand() % 6)];
        technique = techniqueTypes[(rand() % 6)];
        spec = specTypes[(rand() % 6)];
    }
    //Overload Assignment Operator
    void operator = (const mon &m){
        hunger = m.hunger;
        bore = m.bore;
    }
    friend ostream& operator << (ostream& info, mon& entry);
};
ostream & operator << (ostream& info, mon& entry){
    
    info << "name: " << entry.returnName() << endl;
    info << "species: " << entry.returnSpecies() << endl;
    info << "element: " << entry.returnEl() << endl;
    info << "technique: " << entry.returnTec() << endl;
    info << "hunger: " << entry.returnHunger() << endl;
    info << "boredom: " << entry.returnBore() << endl;
    
    return info;
}

void mon::passTime(){
    hunger--;
    bore++;
};

//subtracts a value 4-8 from boredom
void mon::play(){
    int x = (rand() % 5) + 4;
    bore -= x;
}

//adds a value 3-6 to hunger
void mon::feed(){
    int x = (rand() % 4) + 3;
    hunger += x;
}

//displays just types
void mon::displayTypes(){
    cout << "species: " << spec << endl;
    cout << "element: " << element << endl;
    cout << "technique: " << technique << endl;
};

//displays just stats
void mon::listen(){
    cout << "hunger level:" << hunger << endl;
    cout << "boredom level:" << bore << endl;
};

//displays everything
void mon::displayAll(){
    cout << "name: " << name << endl;
    cout << "species: " << spec << endl;
    cout << "element: " << element << endl;
    cout << "technique: " << technique << endl;
    cout << "hunger level:" << hunger << endl;
    cout << "boredom level:" << bore << endl;
}

//test method
void mon::testMethod(){
    mon test1;
    mon test2;
    mon test3;
    int h1 = test1.returnHunger();
    int b1 = test1.returnBore();
    int h2 = test2.returnHunger();
    int b2 = test2.returnBore();
    int h3 = test3.returnHunger();
    int b3 = test3.returnBore();
    
    bool pass1 = true;
    test1.passTime();
    if(test1.returnBore() == (b1 + 1) && test1.returnHunger() == (h1 - 1)){
        pass1 = true;
    }
    else{
        pass1 = false;
    }
    test1.feed();
    test1.play();
    
    if(test1.returnBore() < (b1 - 3) && test1.returnHunger() > (h1 + 2)){
        pass1 = true;
    }
    else{
        pass1 = false;
    }
    
    if(pass1){
        cout << "test 1 passed";
    }
    else{
        cout << "test 1 failed";
    }
    cout << endl;
    
    bool pass2 = true;
    test2.passTime();
    if(test2.returnBore() == (b2 + 1) && test2.returnHunger() == (h2 - 1)){
        pass2 = true;
    }
    else{
        pass2 = false;
    }
    test2.feed();
    test2.play();
    
    if(test2.returnBore() < (b2 - 3) && test2.returnHunger() > (h2 + 2)){
        pass2 = true;
    }
    else{
        pass2 = false;
    }
    
    if(pass1){
        cout << "test 2 passed";
    }
    else{
        cout << "test 2 failed";
    }
    cout << endl;
    
    bool pass3 = true;
    test3.passTime();
    if(test3.returnBore() == (b3 + 1) && test1.returnHunger() == (h3 - 1)){
        pass3 = true;
    }
    else{
        pass3 = false;
    }
    test3.feed();
    test3.play();
    
    if(test3.returnBore() < (b3 - 3) && test1.returnHunger() > (h3 + 2)){
        pass3 = true;
    }
    else{
        pass3 = true;
    }
    
    if(pass3){
        cout << "test 3 passed";
    }
    else{
        cout << "test 3 failed";
    }
    cout << endl;
}



//  Second Child Class
class mon2 : public creature{
    int returnHunger(){
        return hunger;
    }
    int returnBore(){
        return bore;
    }
    // Copy Constructor
    mon2(const mon2 &copy){
        name = copy.name;
        hunger = copy.hunger;
        bore = copy.bore;
    }
};

int main() {
    int startC = 0;
    int monN = 0;
    int monC = -1;
    int opt = 0;
    bool go = true;
    bool play = true;
    
    greeting();
    
    mon test;
    
    test.testMethod();
    
    //creates object with 10 slots
    mon hokeemon[10];
    
    //will go forever
    while(go){
        start();
        validInput(startC);
        
        if(startC == 1){
            string name;
            
            monC++;
            //sets information for new hokeemon
            hokeemon[monC].setStats();
            hokeemon[monC].setTypes();
            
            hokeemon[monC].displayTypes();
            
            cout << "Enter a name for this Hokeemon: ";
            cin >> name;
            hokeemon[monC].getName(name);
            
            cout << "\nGreat! Heres your new hokeemon:\n";
            
            hokeemon[monC].displayAll();
          
        }
        else if(startC == 2){
            bool invalidResponse = true;
            
            cout << "Select a Hokeemon to see more info on and then go play with.\n";
            
            //diplays hokeemons and their names
            for(int i = 0; i <= monC; i++){
                cout << (i + 1) << ". " << hokeemon[i].returnName() << endl;
            }
            
            //only allows valid input
            while(invalidResponse){

                cin >> monN;

                if(cin.fail()){
                    cin.clear();
                    cin.ignore();
                }
                else if (monN > 0 && monN <= (monC + 1)){
                    invalidResponse = false;
                }
                
                if (invalidResponse == true){
                    cout << "\ninvalid, please choose a number from the given Hokeemons: ";
                }
            }
            monN--;
            
            hokeemon[monN].displayTypes();
            
        }
        else if(startC == 3){
            cout << "Playing with following Hokeemon: \n";
            
            //informs about the selected hokeemon
            hokeemon[monN].displayAll();
            cout << endl;
            
            //will go until quit which returns back to main menu
            while(play){
                
                //doesn't let them play with it if hunger level goes below 0
                if(hokeemon[monN].returnHunger() < 0){
                    cout << "Your Hokeemon has starved! The hunger level went below 0. RIP \n";
                    play = false;
                }
                //doesn't let them play if boredom level exceeds 20
                if(hokeemon[monN].returnBore() > 20){
                    cout << "Your Hokeemon has become unresponsive! The boredom level went went over 20. RIP \n";
                    play = false;
                }
                
                menu();
                validInput(opt);
                
                if(opt == 1){
                    hokeemon[monN].listen();
                }
                else if(opt == 2){
                    hokeemon[monN].play();
                }
                else if(opt == 3){
                    hokeemon[monN].feed();
                }
                else if(opt == 4){
                    play = false;
                }
                hokeemon[monN].passTime();
            }
        }
        else if(startC == 4){
            //doesn't allow you to do this if 1 or less hokeemon have been made
            if (monC < 1){
                cout << "Not enough hokemons made\n";
            }
            else{
            bool invalidResponse = true;
            int h1 = 0;
            int h2 = 0;
            cout << "Select 2 Hokeemon to combine.\n";
            
            //displays hokeemon to choose from
            for(int i = 0; i <= monC; i++){
                cout << (i + 1) << ". " << hokeemon[i].returnName() << endl;
            }
            //only allows valid number input
            while(invalidResponse){
                
                cin >> h1;
                
                if(cin.fail()){
                    cin.clear();
                    cin.ignore();
                }
                else if (h1 > 0 && h1 <= (monC + 1)){
                    invalidResponse = false;
                }
                cout << endl;
                
                cin >> h2;

                if(cin.fail()){
                    cin.clear();
                    cin.ignore();
                }
                
                else if (h2 > 0 && h2 <= (monC + 1)){
                    invalidResponse = false;
                }
                
                if(h1 == h2){
                    invalidResponse = true;
                }
                
                if (invalidResponse == true){
                    cout << "\ninvalid, please choose 2 different numbers from the given Hokeemons: ";
                }
            }
            h1--;
            h2--;
            
            monC++;
            
            monN = monC;
            
            // Overload + Operator
            //simply combines the names, species, element, and techniques to make new hokeemon
            string n = hokeemon[h1].returnName() + hokeemon[h2].returnName();
            string s = hokeemon[h1].returnSpecies() + hokeemon[h2].returnSpecies();
            string e = hokeemon[h1].returnEl() + hokeemon[h2].returnEl();
            string t = hokeemon[h1].returnTec() + hokeemon[h2].returnTec();
            hokeemon[monN].getName(n);
            hokeemon[monN].getSpec(s);
            hokeemon[monN].getEl(e);
            hokeemon[monN].getTec(t);
            
            cout << "\nGreat! Heres your new hokeemon:\n";
            
            hokeemon[monN].displayAll();
            }
        }
    }

    return 0;
}

//greeting function
void greeting(){
    cout << "Welcome to the Hokeemon Game!\n";
    cout << "by Taha Zeeshan\n";
    cout << "In this game you can create up to 10 Hokeemon\n";
    cout << "each one has a species, element, and technique.\n";
    cout << "When playing with one you must keep its boredom\n";
    cout << "within 20 and hunger at atleast 0 or else it may die.\n";
    cout << "every turn boredom increases by 1 while hunger decreases by 1\n" << endl;
}

//main menu function
void start(){
    cout << "1. Create a new Hokeemon\n";
    cout << "2. View all Hokeemons\n";
    cout << "3. Play with Hokeemon\n";
    cout << "4. Merge Hokeemons\n" << endl;
}

//playing menu function
void menu(){
    cout << "1. Listen\n";
    cout << "2. Play\n";
    cout << "3. Feed\n";
    cout << "4. Quit\n";
}

//validate input function
void validInput(int& choice){
    bool invalidResponse = true;

    while(invalidResponse){

        cin >> choice;

        if(cin.fail()){
            cin.clear();
            cin.ignore();
        }
        else if (choice > 0 && choice < 5){
            invalidResponse = false;
        }
        
        if (invalidResponse == true){
            cout << "\ninvalid, please choose an option 1-4: ";
        }
    }
}
