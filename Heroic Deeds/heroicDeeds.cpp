#include <iostream>
#include <vector>
#include <string>
#include <algorithm> //for transform
#include <cctype> //for tolower
using namespace std;

// Function prototypes
void displayBanner();
void addHeroicDeed(vector<string>& deeds, vector<string>& branches);
void displayDeeds(const vector<string>& deeds, const vector<string>& branches);
void displayStatistics(const vector<string>& deeds, const vector<string>& branches);
void createPatrioticPattern();
void searchByBranch(const vector<string>& deeds, const vector<string>& branches);

int main() {
    vector<string> heroicDeeds;
    vector<string> serviceBranches;
    int choice;

    // Display program banner
    displayBanner();

    do {
        // Main menu
        cout << "\n=== MAIN MENU ===\n";
        cout << "1. Add a veteran's heroic deed\n";
        cout << "2. Display all heroic deeds\n";
        cout << "3. Show tribute statistics\n";
        cout << "4. Create patriotic pattern\n";
        cout << "5. Search deeds by branch\n";
        cout << "6. Exit\n";
        cout << "Choose an option (1-6): ";
        cin >> choice;
        cin.ignore();  // clear newline

        switch(choice) {
            case 1:
                // TODO: Implement addHeroicDeed() - done
                addHeroicDeed(heroicDeeds, serviceBranches);
                break;
            case 2:
                // TODO: Implement displayDeeds() - done
                displayDeeds(heroicDeeds, serviceBranches);
                break;
            case 3:
                // TODO: Implement displayStatistics() - done
                displayStatistics(heroicDeeds, serviceBranches);
                break;
            case 4:
                // TODO: Implement createPatrioticPattern() - done
                createPatrioticPattern();
                break;
            case 5:
                // TODO: Implement searchByBranch() - done
                searchByBranch(heroicDeeds, serviceBranches);
                break;
            case 6:
                cout << "Thank you for honoring our veterans!\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while(choice != 6);

    return 0;
}

// TODO: Implement the displayBanner() function - done
void displayBanner() {
    cout << "========================================\n";
    cout << "      VETERANS DAY TRIBUTE PROGRAM      \n";
    cout << "========================================\n";
    cout << "   Honoring Those Who Served Our Nation\n";
    cout << "========================================\n\n";
}

// TODO: Implement addHeroicDeed() function - Done
void addHeroicDeed(vector<string>& deeds, vector<string>& branches) {
    // Steps:
    // 1. Ask user to enter branch
    // 2. Ask user to describe heroic deed
    // 3. Store data in vectors
    
    string branchInput, deedInput;
    
    cout << "\n\nEnter the branch of the heroic deed: ";
    getline(cin, branchInput);
    branches.push_back(branchInput);
    
    cout << "\nDescribe the heroic deed: ";
    getline(cin, deedInput);
    deeds.push_back(deedInput);
}

// TODO: Implement displayDeeds() function - Done
void displayDeeds(const vector<string>& deeds, const vector<string>& branches) {
    // Steps:
    // 1. Check if vectors are empty
    // 2. Loop through vectors and print deeds with branch
    
    if (deeds.empty() && branches.empty()) {
        cout << "\nThere are no heroic deeds and branches to display!\n";
    }
    else if (deeds.size() != branches.size()) {
        cout << "\nThere is an uneven amount!\n";
    }
    else {
        for (int i = 0; i < deeds.size(); ++i) {
                cout << deeds.at(i) << " - " << branches.at(i) << endl;
        }
    }
}

// TODO: Implement displayStatistics() function - Done
void displayStatistics(const vector<string>& deeds, const vector<string>& branches) {
    // Steps:
    // 1. Count total deeds
    // 2. Count deeds by branch
    // 3. Display results
    
    int marinesCount = 0;
    int coastCount = 0 ;
    int navyCount = 0;
    int spaceCount = 0;
    int armyCount = 0;
    int airforceCount = 0;
    
    for (const string&s : branches) {
        string tempBranch = s;
        transform(tempBranch.begin(), tempBranch.end(), tempBranch.begin(), [](unsigned char c){return tolower(c);}); 
        if (tempBranch == "marines" || tempBranch == "marine corps" || tempBranch == "marine") {
            marinesCount++;
        }
        else if (tempBranch == "coast guard" || tempBranch == "coast") {
            coastCount++;
        }
        else if (tempBranch == "navy" || tempBranch == "sailor") {
            navyCount++;
        }
        else if (tempBranch == "space force" || tempBranch == "guardian" || tempBranch == "guardians") {
            spaceCount++;
        }
        else if (tempBranch == "army" || tempBranch == "gi" || tempBranch == "g.i." || tempBranch == "soldier") {
            armyCount++;
        } 
        else if (tempBranch == "air force" || tempBranch == "airman") {
            airforceCount++;
        }
    }
    
    cout << "\nTotal deeds: " << deeds.size() << endl;
    cout << "Marines: " << marinesCount << endl;
    cout << "Army: " << armyCount << endl;
    cout << "Navy: " << navyCount << endl;
    cout << "Air Force: " << airforceCount << endl;
    cout << "Coast Guard: " << coastCount << endl;
    cout << "Space Force: " << spaceCount << endl;
}

// TODO: Implement createPatrioticPattern() function - 
void createPatrioticPattern() {
    // Steps:
    // 1. Ask user for number of rows
    // 2. Use loops to print a pattern (★, ●, ▲)
    
    int rows;
    cout << "\nHow many rows would you like? ";
    cin >> rows;
    if (rows == 0) {
        cout << "\nNo rows to be displayed.\n";
        return;
    }
    
    else {
        while (rows != 0) {
            cout << "\n\n★~●~▲~★~●~▲~●~▲~★~●~▲~●~▲~★~●~▲~●~▲~★~●~▲~●~▲~★~●~▲\n";
            rows--;
        }
    }
    
}

// TODO: Implement searchByBranch() function - Done, could be improved
void searchByBranch(const vector<string>& deeds, const vector<string>& branches) {
    // Steps:
    // 1. Ask user for branch to search
    // 2. Loop through branches vector and display matching deeds
    string searchTerm;
    int searchCount = 0;
    cout << "\nEnter the branch you want to view the heroic deeds of: ";
    getline(cin, searchTerm);
    
    cout << "\nHeroic deeds of the: " << searchTerm << endl;
    
    for (int i = 0; i < branches.size(); ++i) {
        if (branches.at(i) == searchTerm) {
            cout << deeds.at(i) << endl;
            searchCount++;
        }
    }
    if (searchCount == 0) {
        cout << "No heroic deeds found for this branch.\n";
    }
}
