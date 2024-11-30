// TO DO: #include all the standard libraries and your own libraries here
#include <chrono>
#include "Post.h"


// TO DO: function implementations
Post::Post(){
	_likes = 0;
};
Post::~Post(){};

Post::Post(const std::string& title, const std::string& URL, int duration) {
	_duration = duration;
	auto _time_stamp = std::chrono::steady_clock::now(); //sets time at time of contruction
	_likes = 0;
	_title = title;
	_URL = URL;
}


Post::Post(const Post& other)
{
	_title = other._title;       
	_URL = other._URL;  
	_duration = other._duration;
	_time_stamp = other._time_stamp;
}

Post& Post::operator=(const Post& other) {
    if (this == &other) {
        return *this;
    }
    _title = other._title;     
    _URL = other._URL;            
    _duration = other._duration;  
    _likes = other._likes;
    _time_stamp = other._time_stamp;

    return *this;
}

void Post::displayPost() {
	std::cout << "Title: " << _title<<std::endl;
	std::cout<< "Duration: " << _duration <<std::endl;
	std::cout << "likes: " << _likes << std::endl;
	std::cout << "URL: " << _URL << std::endl;
}

bool Post::changeTitle(std::string title) {
	_title = title;
	return true;
}


//When creating a post, you may use this code to set time stamp



// ------------------------------------------------------------------------------
// Operator overloading implementation
bool Post::operator==(const Post& otherPost) const {
	return Post::_title == otherPost._title;
}

// When displaying a story, use this to compute expected expiration time: timeToExpiration
// Define this as a private function 
int Post::computeTimeToExpiration() const{// I dont think this provided function works properly
	const int secondsInHour = 3600;
	// 24 hours in seconds
	const int expiresAfter = 24 * secondsInHour; 

	// Get current time
	auto time_now = std::chrono::steady_clock::now();
	// Compute elapsed time since post creation
	std::chrono::duration<double> elapsed_seconds = time_now - Post::_time_stamp;
	// time to expiration in hours
	int timeToExpiration = (expiresAfter - elapsed_seconds.count()) / secondsInHour;

	return timeToExpiration;
}

std::ostream& Post::print(std::ostream& stream) const {

    stream << "POST"<<std:: endl;
	stream << "Title: " << _title << std::endl;
    stream<< "Duration: " << _duration <<std::endl;
	stream << "likes: " << _likes << std::endl;
	stream << "URL: " << _URL;

    return stream;
}

std::ostream& operator<< (std::ostream& stream, const Post& post){
	return post.print(stream);
}


std::istream& operator>>(std::istream& stream, Post& post) {

	post.out(stream);
	return stream;
}


std::istream &Post::out(std::istream &stream)
{
        std::cout << "Title: ";
        stream >> _title;

        std::cout << "URL: ";
        stream >> _URL;

        std::cout << "Duration: ";
        stream >> _duration;

		_likes = 0;
        return stream;


}




bool Post::editPost() {
    return true;
}


