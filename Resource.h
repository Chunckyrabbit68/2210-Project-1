#ifndef RESOURCE_H
#define RESOURCE_H

#include <string>
using namespace std;

class Resource {
private:
    string resourceID;
    string resourceName;
    string resourceType;
    string status;

public:
    Resource();

    Resource(string id,
             string name,
             string type,
             string status);

    string getResourceID() const;
    string getResourceName() const;
    string getResourceType() const;
    string getStatus() const;

    bool isAvailable() const;

    void setStatus(string newStatus);

    void display() const;
};

#endif
