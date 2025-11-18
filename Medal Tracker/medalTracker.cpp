#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

// Structure for veteran information
struct Veteran {
    string name;
    int age;
    vector<string> medals; // Each veteran can have multiple medals
};

// Function prototypes
void displayBanner();
void addVeteran(vector<Veteran>& veterans);
void displayVeterans(const vector<Veteran>& veterans);
void searchByMedal(const vector<Veteran>& veterans);
void medalStatistics(const vector<Veteran>& veterans);
void removeVeteran(vector<Veteran>& veterans);
void sortVeteransByAge(vector<Veteran>& veterans);
void sortVeteransByName(vector<Veteran>& veterans);

int main() {
    vector<Veteran> veterans;
    int choice;

    //sample data, uncomment to save hassle of needing to test other functions requiring data
    // Veteran sampleData1;
    // sampleData1.name = "John Smith";
    // sampleData1.age = 32;
    // sampleData1.medals = {"Purple Heart", "Bronze Star"};
    // Veteran sampleData2;
    // sampleData2.name = "Alice Brown";
    // sampleData2.age = 45;
    // sampleData2.medals = {"Bronze Star", "Purple Heart"};
    // Veteran sampleData3;
    // sampleData3.name = "Michael Lee";
    // sampleData3.age = 50;
    // sampleData3.medals = {"Bronze Star", "Purple Heart"};
    // veterans.push_back(sampleData1);
    // veterans.push_back(sampleData2);
    // veterans.push_back(sampleData3);


    displayBanner();

    do {
        cout << "\n=== MAIN MENU ===\n";
        cout << "1. Add a veteran and their medals\n";
        cout << "2. Display all veterans and medals\n";
        cout << "3. Search veterans by medal\n";
        cout << "4. Show medal statistics\n";
        cout << "5. Remove a veteran by name\n";
        cout << "6. Sort veterans by age\n";
        cout << "7. Sort veterans alphabetically\n";
        cout << "8. Exit\n";
        cout << "Choose an option (1-7): ";
        cin >> choice;
        cin.ignore(); // clear newline

        switch(choice) {
            case 1: addVeteran(veterans); break;
            case 2: displayVeterans(veterans); break;
            case 3: searchByMedal(veterans); break;
            case 4: medalStatistics(veterans); break;
            case 5: removeVeteran(veterans); break;
            case 6: sortVeteransByAge(veterans); break;
            case 7: sortVeteransByName(veterans); break;
            case 8: cout << "Thank you for honoring our veterans!\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }

    } while(choice != 8);

    return 0;
}

// TODO: Implement displayBanner() - done
// Hint: Print program title and Veterans Day tribute
void displayBanner() {
    cout << "========================================\n";
    cout << "      VETERANS DAY TRIBUTE PROGRAM      \n";
    cout << "========================================\n";
    cout << "             MEDAL TRACKER\n";
    cout << "========================================\n";
    cout << "   Honoring Those Who Served Our Nation\n";
    cout << "========================================\n\n";
}

// TODO: Implement addVeteran() - done
// Hint: Ask for veteran's name, age, number of medals, and names of each medal
// Ensure duplicate medals are NOT allowed
void addVeteran(vector<Veteran>& veterans) {
    Veteran tempEntry;
    string veteranName, medalDesc;
    int veteranAge, medalNum, tempMedalNum;
    
    cout << "\nEnter veteran's name: ";
    getline(cin, tempEntry.name); 
    cout << "\nEnter veteran's age: ";
    cin >> tempEntry.age;
    cout << "\nEnter how many medals this veteran has: ";
    cin >> medalNum;
    cin.ignore(); //clears buffer
    tempMedalNum = medalNum;
    
    for (int i = 0; i < medalNum; i++) {
        string medal;
        cout << "Enter medal #" << (i + 1) << ": ";
        getline(cin, medal);

        // Prevent duplicates
        if (find(tempEntry.medals.begin(), tempEntry.medals.end(), medal) == tempEntry.medals.end()) {
            tempEntry.medals.push_back(medal);
        } else {
            cout << "Duplicate medal ignored.\n";
            i--;
        }
    }

    veterans.push_back(tempEntry);
    cout << "Veteran added successfully\n";
}

// TODO: Implement displayVeterans() - done
// Hint: Loop through the vector and print each veteran's name, age, and medals
void displayVeterans(const vector<Veteran>& veterans) {
    if (veterans.empty()) {
        cout << "\nNo veterans have been entered yet.\n";
        return;
    }

    cout << "\nVeteran List: \n";
    for (const auto& v : veterans) {
        cout << "\nName: " << v.name << "\nAge: " << v.age << "\nMedals: ";
        if (v.medals.empty()) {
            cout << "No medals\n";
        }
        else {
            for (int i = 0; i < v.medals.size(); ++i) {
                if (i != (v.medals.size()-1)) {
                    cout << v.medals.at(i) << ", ";
                }
                else {
                    cout << v.medals.at(i);
                }
            }
        }
    }
    cout << endl;
}

// TODO: Implement searchByMedal() - done
// Hint: Ask user for a medal and display all veterans who have it
void searchByMedal(const vector<Veteran>& veterans) {
    if (veterans.empty()) {
        cout << "\nNo veterans available to search.\n";
        return;
    }

    string medal;
    cout << "\nEnter medal to search for: ";
    getline(cin, medal);

    bool found = false;
    cout << "\nVeterans with medal '" << medal << "':\n";

    for (const auto& v : veterans) {
        if (find(v.medals.begin(), v.medals.end(), medal) != v.medals.end()) {
            cout << "- " << v.name << " -Age " << v.age << "\n";
            found = true;
        }
    }

    if (!found) {
        cout << "No veterans found with that medal.\n";
    }
}



// TODO: Implement medalStatistics() - done
// Hint: Count how many times each medal has been awarded and display
void medalStatistics(const vector<Veteran>& veterans) {
    if (veterans.empty()) {
        cout << "\nNo medal data available.\n";
        return;
    }

    //Using map to pair medal name with medal count
    map<string, int> medalCount;

    for (const auto& v : veterans) {
        for (const string& m : v.medals) {
            medalCount[m]++;
        }
    }

    cout << "\nMedal Statistics\n";
    for (const auto& c : medalCount) {
        cout << c.first << ": " << c.second << " award(s)\n";
    }
}


// TODO: Implement removeVeteran() - done
// Hint: Ask user for veteran's name and remove from the vector if found
void removeVeteran(vector<Veteran>& veterans) {
    if (veterans.empty()) {
        cout << "\nNo veterans to remove.\n";
        return;
    }

    string name;
    cout << "\nEnter the name of the veteran to remove: ";
    getline(cin, name);

    auto it = remove_if(veterans.begin(), veterans.end(), [&](const Veteran& v) {return v.name == name; });
    if (it != veterans.end()) {
        veterans.erase(it, veterans.end());
        cout << "Veteran removed.\n";
    }
    else {
        cout << "Veteran not found.\n";
    }
}


// TODO: Implement sortVeteransByAge() - done
// Hint: Sort the vector of veterans in ascending order of age using a lambda or function
void sortVeteransByAge(vector<Veteran>& veterans) {
    sort(veterans.begin(), veterans.end(),
        [](const Veteran& a, const Veteran& b) {
            return a.age < b.age;
        }
    );
    cout << "\nVeterans sorted by age.\n";
}

//Sort veterans by name in alphabetical order - done
void sortVeteransByName(vector<Veteran>& veterans) {
    sort(veterans.begin(), veterans.end(),
        [](const Veteran& a, const Veteran& b) {
            return a.name < b.name;
        }
    );
    cout << "\nVeterans sorted alphabetically.\n";
}

