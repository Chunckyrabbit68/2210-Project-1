#include "Resource.h"
#include <iostream>
using namespace std;

Resource::Resource() {
    resourceID = "";
    resourceName = "";
    resourceType = "";
    status = "Available";
}

Resource::Resource(string id,
                   string name,
                   string type,
                   string status) {
    resourceID = id;
    resourceName = name;
    resourceType = type;
    this->status = status;
}

string Resource::getResourceID() const {
    return resourceID;
}

string Resource::getResourceName() const {
    return resourceName;
}

string Resource::getResourceType() const {
    return resourceType;
}

string Resource::getStatus() const {
    return status;
}

bool Resource::isAvailable() const {
    return status == "Available";
}

void Resource::setStatus(string newStatus) {
    status = newStatus;
}

void Resource::display() const {
    cout << resourceID << " | "
         << resourceName << " | "
         << resourceType << " | "
         << status << endl;
}
