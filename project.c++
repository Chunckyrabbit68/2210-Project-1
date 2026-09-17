#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

#include "Resource.h"
#include "Reservation.h"

using namespace std;

vector<Resource> resources;

// Load resources from resources.txt
void loadResources(const string& filename) {
    ifstream file(filename);

    if (!file.is_open()) {
        cout << "Error opening resource file." << endl;
        return;
    }

    string line;

    while (getline(file, line)) {
        stringstream ss(line);

        string id;
        string name;
        string type;
        string status;

        getline(ss, id, '|');
        getline(ss, name, '|');
        getline(ss, type, '|');
        getline(ss, status);

        Resource resource(id, name, type, status);
        resources.push_back(resource);
    }

    file.close();
}

// Display every resource
void displayResources() {
    cout << "\n--- All Resources ---" << endl;

    for (const Resource& resource : resources) {
        resource.display();
    }
}

// Display availability
void displayAvailability() {
    cout << "\n--- Resource Availability ---" << endl;

    for (const Resource& resource : resources) {
        cout << resource.getResourceID()
             << " - "
             << resource.getResourceName()
             << ": "
             << resource.getStatus()
             << endl;
    }
}

// Find resource by ID
Resource* findResource(const string& resourceID) {
    for (Resource& resource : resources) {
        if (resource.getResourceID() == resourceID) {
            return &resource;
        }
    }

    return nullptr;
}

int main() {
    loadResources("resources.txt");

    displayResources();
    displayAvailability();

    return 0;
}
