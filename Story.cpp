#include "Story.h"
#include "Post.h"
Story::Story(){
    _likes = 0;

    _time_stamp = std::chrono::steady_clock::now();
};

Story::Story(std::string& title,std::string& URL, int duration) {
	_duration = duration;
    _time_stamp = std::chrono::steady_clock::now();

	_likes = 0;
	_title = title;
	_URL = URL;


}

Story::~Story(){}

Story::Story(const Story& other)
{
	_title = other._title;       
	_URL = other._URL;  
	_duration = other._duration;
	_time_stamp = other._time_stamp;
}

Story& Story::operator=(const Story& other) {
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


void Story::displayPost() {
    std::cout << "STORY"<<std:: endl;
	std::cout << "Title: " << _title << std::endl;
    std::cout<< "Duration: " << _duration <<std::endl;
	std::cout << "likes: " << _likes << std::endl;
	std::cout << "URL: " << _URL << std::endl;
    int time = computeTimeToExpiration();

    if(computeTimeToExpiration() < 0) {
        std::cout << "Story is expired"<<std::endl;
    }else {
        std::cout << "Time left: " << time<<std::endl;
    }

}

bool Story::editPost() {
    std::cout << "Filter, music, stickers, and effects have been added";
    return true;
}

int Story::computeTimeToExpiration() const{
	const int secondsInHour = 3600;
	// 24 hours in seconds
	const int expiresAfter = 24 *3600; 

	// Get current time
    std::chrono::steady_clock::time_point time_now = std::chrono::steady_clock::now();

	// Compute elapsed time since post creation
	std::chrono::duration<double> elapsed_seconds = time_now - Story::_time_stamp;
	// time to expiration in hours

	int timeToExpiration = (expiresAfter - elapsed_seconds.count());

	return timeToExpiration;
}


bool Story::changeTitle(std::string title) {
    std::cout<<"CHANgeTITLE" <<title;
	_title = title;
	return true;
}

std::ostream& Story::print(std::ostream& stream) const {
    stream << "Story"<<std:: endl;
	stream << "Title: " << _title << std::endl;
    stream<< "Duration: " <<_duration <<std::endl;
	stream << "likes: " << _likes << std::endl;
	stream << "URL: " << _URL << std::endl;

    int time = this->computeTimeToExpiration();
;

    if(this->computeTimeToExpiration() < 0) {
        std::cout << "Story is expired";
    }else {
        std::cout << "Time left: " << time;
    }


    return stream;

}


std::istream &Story::out(std::istream &stream)
{


    std::cout<< "sTORY INPUT"  << std::endl;
    // std::cout<<"Title: \n";//ask for title
    // stream >> _title;


    // std::cout<<"URL: \n";//ask for url
    // stream >> _URL;

    // std::cout<<"Duration: \n";
    // stream >> _duration;// ask for duration

    std::cout << "Title: \n";
    std::getline(stream, _title); 

    std::cout << "URL: \n";
    std::getline(stream, _URL);

    std::cout<<"Duration: \n";
    stream >> _duration;// ask for duration

    if(_duration > 60) {
        std::cout << "max Story duratoin is 60. Setting duration to 90";
        _duration = 60;
    }

    return stream;
}

