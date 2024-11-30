#ifndef INSTA360
#define INSTA360
// TO DO include necessary libraries
#include "User.h"
#include "LinkedBagDS/LinkedBag.h"
#include "Personal.h"
#include "Creator.h"

// This class only contains a list of users
// It should allow clients to add users and retrieve a user from the list

class Instagram340 {
	private:
		LinkedBag<std::shared_ptr<User>> users;

	public:
		Instagram340();
		~Instagram340();
		Instagram340(const Instagram340& other);
		Instagram340& operator=(const Instagram340& other);

		void createUser(const std::string& _username, const std::string& _email, const std::string& _password,
						const std::string& _bio, const std::string& _profilePicture);

		void createUser(const std::shared_ptr<User> newUser);
		void displayUsers();
		int userCount();

		std::shared_ptr<User> getUser(const int& indexK);
		friend std::ostream& operator<< (std::ostream& stream, const Instagram340& instagram);
		friend std::istream& operator>> (std::istream& stream, Instagram340& instagram);
};

#endif