// TO DO: #include needed standard libraries and your own libraries here
#include "User.h"
#include <iostream>
// #include "LinkedBagDS/LinkedBag.h"

// TO DO: function implementations


User::User(const std::string& username, const std::string& email, const std::string& password, const std::string&  bio, const std::string& URL):
	_username(username), _email(email),_password(password), _bio(bio), _profilePicture(URL){
}


User::User(): _username(""), _email(""), _password(""), _bio(""), _profilePicture(""){}


User::~User() {
	User::_posts.clear();
}

User::User(const User& other)
{
	_username = other._username;       
	_email = other._email;  
	_password = other._password;
	_bio = other._bio;
	_profilePicture = other._profilePicture;
}

User& User::operator=(const User& other) {
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



void User::displayProfile() {
	std::cout << std::endl << "username: " << _username << std::endl;
	std::cout << "email: " << _email << std::endl;
	std::cout << "bio: " << _bio << std::endl;
	std::cout << "profilePicture: " << _profilePicture << std::endl;


}
bool User::changePassword(std::string newPassword) {
		_password = newPassword;
		std::cout << "New password: " << _password<<std::endl;
		return true;
}

std::shared_ptr<Post> User::getKthPost(int indexK) {
	Node<std::shared_ptr<Post>>* post = _posts.findKthItem(indexK);
	if (post == nullptr) {
		std::cout << "Error: Could not find the Kth post.\n";
		return nullptr;
	}

	 

	return post->getItem();
}

void User::monetizePosts()
{
}

int User:: getPostCount() {
	return _posts.getCurrentSize();
}

void User::displayPosts(){
   std::cout << "You have " << _posts.getCurrentSize()
   << " posts:" << std::endl;
   std::vector<std::shared_ptr<Post>> bagItems = _posts.toVector();

       for (std::shared_ptr<Post> post : bagItems) {
        std::cout << *post << std::endl;
    }


}

bool User::addPost(std::shared_ptr<Post> post) {
	_posts.add(post);
	return true;
}

bool User::addReel(std::shared_ptr<Reel> reel) {
	_posts.append(reel);
	return true;
}

bool User::addStory(std::shared_ptr<Story> story) {
	_posts.append(story);
	return true;
}


std::string User::getUsername(){
	return _username;
}

//MIGHT HAVE PROBELMS
bool User::deletePost(int index) {
    // check for outliers
    if (index < 0 || index >= _posts.getCurrentSize()) {
        std::cout << "Error: Invalid index " << index << ". LinkedBag size: " << _posts.getCurrentSize() << std::endl;
        return false;
    }
    // get the node at index K
    Node<std::shared_ptr<Post>>* postNode = _posts.findKthItem(index);
    if (postNode == nullptr) {
        std::cout << "Error: Post not found at index " << index << std::endl;
        return false;
    }

    //set delete post to the node to be deleted
    std::shared_ptr<Post> deletePost = postNode->getItem();
    if (deletePost == nullptr) {
        std::cout << "Error: couldnt find Node" << std::endl;
        return false;
    }

    std::cout << "Deleting post: " << std::endl; 

    // deletethe post. 
    return _posts.remove(deletePost);



}
// Operator == overloading implementation
bool User::operator==(const User& otherUser) const {
	return (User::_username == otherUser._username) && (User::_email == otherUser._email);
}

std::ostream &User::print(std::ostream &stream) const
{
	stream << std::endl << "username: " << _username << std::endl;
	stream << "email: " << _email << std::endl;
	stream << "bio: " << _bio << std::endl;
	stream << "profilePicture: " << _profilePicture << std::endl;

    return stream;
}

std::ostream& operator<< (std::ostream& stream, const User& user){
	return user.print(stream);
}

std::istream& operator>>(std::istream& stream, User& user) {
    std::cout << "Enter name: ";
    std::getline(stream, user._username); 

    std::cout << "Email: ";
    stream >> user._email;

    std::cout << "Bio: ";
    std::getline(stream,user._bio);

	std::cout << "Password: ";
    stream >> user._password;

	std::cout << "Profile Picture: ";
    stream >> user._profilePicture;
	

    return stream;
}


