#include "Creator.h"

Creator::Creator(const std::string& username, const std::string& email, const std::string& password, const std::string&  bio, const std::string& URL){
        std::cout << "CREATOR";

        _username = username;
        _email = email;
        _password = password;
        _bio = bio;
        _profilePicture = URL;
}

Creator::~Creator()
{
    _posts.clear();
}

Creator::Creator(const Creator& other)
{
	_username = other._username;       
	_email = other._email;  
	_password = other._password;
	_bio = other._bio;
	_profilePicture = other._profilePicture;
}

Creator& Creator::operator=(const Creator& other) {
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


void Creator::monetizePosts()
{
    std::cout << "Monetized all posts."<< std::endl;
}

Creator::Creator(){}


std::ostream &Creator::print(std::ostream &stream) const
{
    stream <<std::endl << "Account type: Creator"<< std::endl;
	stream << "username: " << _username << std::endl;
	stream << "email: " << _email << std::endl;
	stream << "bio: " << _bio << std::endl;
	stream << "profilePicture: " << _profilePicture << std::endl;

    return stream;
}

