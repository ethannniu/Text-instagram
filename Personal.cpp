#include "Personal.h"

Personal::Personal(const std::string& username, const std::string& email, const std::string& password, const std::string&  bio, const std::string& URL){
        std::cout << "PERSONAL";

        _username = username;
        _email = email;
        _password = password;
        _bio = bio;
        _profilePicture = URL;
}

Personal::~Personal()
{
    _posts.clear();
}

Personal::Personal(const Personal& other)
{
	_username = other._username;       
	_email = other._email;  
	_password = other._password;
	_bio = other._bio;
	_profilePicture = other._profilePicture;
}

Personal& Personal::operator=(const Personal& other) {
    if (this == &other) {
        return *this;
    }
	_posts.clear();
	_posts = other._posts;
    _username = other._username;       
	_email = other._email;  
	_password = other._password;
	_bio = other._bio;
	_profilePicture = other._profilePicture;

    return *this;
}


void Personal::monetizePosts()
{
    std::cout << "This account is unable to monetize posts because it's a personal account"<< std::endl;
}

Personal::Personal(){}


std::ostream &Personal::print(std::ostream &stream) const
{
    stream <<std::endl << "Account type: Personal"<< std::endl;
	stream << "username: " << _username << std::endl;
	stream << "email: " << _email << std::endl;
	stream << "bio: " << _bio << std::endl;
	stream << "profilePicture: " << _profilePicture << std::endl;

    return stream;
}

