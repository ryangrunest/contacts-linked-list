#include <iostream>
#include <string>

/*
test input:

Roxanne Hughes
443-555-2864
Juan Alberto Jr.
410-555-9385
Rachel Phillips
310-555-6610
*/

using namespace std;

class ContactNode {
  public:
    ContactNode() {
        contactName = "";
        contactPhoneNumber = "";
        nextNodePtr = nullptr;
    }
    ContactNode(string name, string phoneNumber) {
        contactName = name;
        contactPhoneNumber = phoneNumber;
        nextNodePtr = nullptr;
    }
    string GetName() {
        return contactName;
    }
    string GetPhoneNumber() {
        return contactPhoneNumber;
    }
    void InsertAfter(ContactNode* nodeAfterThis) {
      nodeAfterThis->nextNodePtr = this->nextNodePtr;
      this->nextNodePtr = nodeAfterThis;
    }
    ContactNode* GetNext() {
        return nextNodePtr;
    }
    void PrintContactNode() {
        cout << "Name: " << GetName() << endl;
        cout << "Phone number: " << GetPhoneNumber() << endl;
        
        return;
    }
   
  private:
    string contactName;
    string contactPhoneNumber;
    ContactNode* nextNodePtr;
};

class ContactList {
  private:
    ContactNode* head;

  public:
    ContactList() : head(nullptr) {}

    void append(string name, string phoneNumber) {
      ContactNode* newNode = new ContactNode(name, phoneNumber);

      if (head == nullptr) {
        head = newNode;
      } else {
        ContactNode* temp = head;

        while (temp->GetNext() != nullptr) {
          temp = temp->GetNext();
        }

        temp->InsertAfter(newNode);
      }
    }

    void print() {
      ContactNode* temp = head;

      std::cout << "CONTACT LIST" << endl;

      while (temp != nullptr) {
        temp->PrintContactNode();

        std::cout << endl;

        temp = temp->GetNext();
      }
    }

    // deconstructor to delete linked list in memory, so you don't get memory leaks
    ~ContactList() {
      ContactNode* temp;

      while (head != nullptr) {
        temp = head;
        head = head->GetNext();

        delete temp; // delete each node
      }
    }
};

/* Define member functions here */

int main() {
  std::string name;
  std::string phoneNumber;

  int i;

  ContactList list;

  for (i = 0; i < 3; i++) {
    std::getline(std::cin, name);
    std::getline(std::cin, phoneNumber);

    cout << "Person " << i + 1 << ": " << name << ", " << phoneNumber << endl;

    list.append(name, phoneNumber);
  }

  cout << endl;

  list.print();
   
  return 0;
}
