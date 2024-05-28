#include "./header/Array.h"
#include "./header/LinkedList.h"
#include <iostream>

void handleArray() {
    std::cout << "\nInitialize size of array:\n>> ";

    std::string input = "";
    std::getline(std::cin, input);

    int size = 0;
    try{
        size = std::stoi(input);
    }
    catch (const std::invalid_argument& e) {
        throw std::runtime_error("\t[System] Error: not a number");
    }
    catch (const std::out_of_range& e) {
        throw std::runtime_error("\t[System] Error: number out of range");
    }
    catch (const std::exception& e) {
        throw std::runtime_error("\t[System] Error: unexpected exception");
    }

    Array<int> arr(size);

    while (input != "back") {
        std::cout << "\nArray Menu:" << std::endl;
        std::cout << "1. Insert element" << std::endl;
        std::cout << "2. Delete element" << std::endl;
        std::cout << "3. Display array" << std::endl;
        std::cout << "Type 'back' to return to the main menu." << std::endl;
        std::cout << "\nEnter your choice:\n>> ";
        std::getline(std::cin, input);

        if (input == "1") {
            int index, value;
            std::cout << "Enter index:\n>> ";
            std::cin >> index;
            std::cout << "Enter value:\n>> ";
            std::cin >> value;
            std::cin.ignore(); // Ignore the newline character left in the input buffer
            try {
                arr.insert(index, value);
                std::cout << "\t[System] Inserted " << value << " at index " << index << "." << std::endl;
            } catch (const std::exception& e) {
                std::cerr << "\t[System] Error: " << e.what() << std::endl;
            }
        } else if (input == "2") {
            int index;
            std::cout << "Enter index:\n>> ";
            std::cin >> index;
            std::cin.ignore(); // Ignore the newline character left in the input buffer
            try {
                arr.remove(index);
                std::cout << "\t[System] Removed element at index " << index << "." << std::endl;
            } catch (const std::exception& e) {
                std::cerr << "\t[System] Error: " << e.what() << std::endl;
            }
        } else if (input == "3") {
            arr.display();
        } else if (input != "back") {
            std::cerr << "\t[System] Invalid choice! Please try again." << std::endl;
        }
    }
}

void handleLinkedList() {
    LinkedList<int> list;
    std::string input = "";

    while (input != "back") {
        std::cout << "\nLinkedList Menu:" << std::endl;
        std::cout << "1. Insert element at front" << std::endl;
        std::cout << "2. Insert element at back" << std::endl;
        std::cout << "3. Delete element" << std::endl;
        std::cout << "4. Search for element" << std::endl;
        std::cout << "5. Display list" << std::endl;
        std::cout << "Type 'back' to return to the main menu." << std::endl;
        std::cout << "\nEnter your choice:\n>> ";
        std::getline(std::cin, input);

        if (input == "1") {
            int value;
            std::cout << "Enter value:\n>> ";
            std::cin >> value;
            std::cin.ignore(); // Ignore the newline character left in the input buffer
            list.insertFront(value);
            std::cout << "\t[System] Inserted " << value << " at the front." << std::endl;
        } else if (input == "2") {
            int value;
            std::cout << "Enter value:\n>> ";
            std::cin >> value;
            std::cin.ignore(); // Ignore the newline character left in the input buffer
            list.insertBack(value);
            std::cout << "\t[System] Inserted " << value << " at the back." << std::endl;
        } else if (input == "3") {
            int value;
            std::cout << "Enter value:\n>> ";
            std::cin >> value;
            std::cin.ignore(); // Ignore the newline character left in the input buffer
            list.deleteElement(value);
            std::cout << "\t[System] Deleted " << value << " from the list." << std::endl;
        } else if (input == "4") {
            int value;
            std::cout << "Enter value:\n>> ";
            std::cin >> value;
            std::cin.ignore(); // Ignore the newline character left in the input buffer
            bool found = list.search(value);
            std::cout << "\t[System] Element " << (found ? "found." : "not found.") << std::endl;
        } else if (input == "5") {
            list.display();
        } else if (input != "back") {
            std::cerr << "\t[System] Invalid choice! Please try again." << std::endl;
        }
    }
}

void displayMainMenu() {
    std::cout << "\nMain Menu:" << std::endl;
    std::cout << "1. Test Array" << std::endl;
    std::cout << "2. Test LinkedList" << std::endl;
    std::cout << "Type 'exit' to quit." << std::endl;
    std::cout << "\nEnter your choice:\n>> ";
}

int main(){
 std::string input = "";

    while (input != "exit") {
        displayMainMenu();
        std::getline(std::cin, input);
        
        if (input == "1") {
            handleArray();
        } else if (input == "2") {
            handleLinkedList();
        } else if (input != "exit") {
            std::cerr << "\t[System] Invalid choice! Please try again." << std::endl;
        }
    }

    std::cout << "\nExiting...\n" << std::endl;
    return 0;
}