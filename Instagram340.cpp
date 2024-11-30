// TO DO: Implementation of Instagram340 functions
#include <iostream>
#include <string>
#include "Instagram340.h"
// #include "LinkedBagDS/LinkedBag.h"

Instagram340::Instagram340(){

}

Instagram340::~Instagram340(){
	Instagram340::users.clear();
}

void Instagram340::createUser(const std::string& _username, const std::string& _email, const std::string& _password,
				const std::string& _bio, const std::string& _profilePicture){
					
					users.add(std::make_shared<User>(_username, _email, _password, _bio, _profilePicture));
					// users.add(User(username, email, password, bio, profilePicture));
	// TO DO: implement function

}

Instagram340::Instagram340(const Instagram340& other)
{
	users = other.users;
}

Instagram340& Instagram340::operator=(const Instagram340& other) {
    if (this == &other) {
        return *this;
    }
	users.clear();
	users = other.users;

    return *this;
}

void Instagram340::displayUsers() {
	   std::cout << "You have " << users.getCurrentSize()
   << " users:" << std::endl;
   std::vector<std::shared_ptr<User>> bagItems = users.toVector();

       for (std::shared_ptr<User> users : bagItems) {
        std::cout << *users << std::endl;
    }

}

int Instagram340::userCount() {
	return users.getCurrentSize();
}


void Instagram340::createUser(const std::shared_ptr<User> newUser){
	users.append(newUser);

}

std::shared_ptr<User> Instagram340::getUser(const int& indexK){
	// TO DO: implement function
	Node<std::shared_ptr<User>>* userNode = users.findKthItem(indexK); //users.findKthItem(indexK);
	if(userNode != nullptr) {
		return userNode->getItem();
	}
	else {
		throw std::out_of_range("out of range");
	}
	// return userNode->getItem();
}

std::ostream& operator<< (std::ostream& stream, const Instagram340& instagram) {
	std::cout<< "Welcome to Instagram 340!" << std::endl;
	return stream;
}
std::istream& operator>> (std::istream &stream, Instagram340& instagram) {
	std::string _username, _email, _password, _bio, _profilePicture;
    
	// stream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	int choice;

	std::cout << "Enter name:";
    std::getline(stream, _username); 

    std::cout << "Email: ";
    std::getline(stream, _email);

    std::cout << "Bio: ";
    std::getline(stream, _bio);

	std::cout << "Password: ";
    std::getline(stream, _password);

	std::cout << "Profile Picture: ";
    std::getline(stream, _profilePicture);

	std::cout << "Choose account type: " <<std::endl;
	std::cout << "1. Personal " << std::endl;
	std::cout << "2. Creator" << std::endl;
	std::cin >> choice;

	if(choice == 1) {
		instagram.createUser(std::make_shared<Personal>(_username, _email, _password, _bio, _profilePicture));
	}
	else if(choice == 2) {
		instagram.createUser(std::make_shared<Creator>(_username, _email, _password, _bio, _profilePicture));
	}
	else {
		std::cout << "not a valid choice" << std::endl;
	}
	
    return stream;
}