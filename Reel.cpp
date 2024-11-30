#include "Reel.h"
#include "Post.h"
#include <iostream>
Reel::Reel(){
    _likes = 0;
};


Reel::~Reel(){};

Reel::Reel(const std::string& title, const std::string& URL, int duration) {
	_duration = duration;
	auto _time_stamp = std::chrono::steady_clock::now();
	_likes = 0;
	_title = title;
	_URL = URL;


}

Reel::Reel(const Reel& other)
{
	_title = other._title;       
	_URL = other._URL;  
	_duration = other._duration;
	_time_stamp = other._time_stamp;
}

Reel& Reel::operator=(const Reel& other) {
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

void Reel::displayPost() {
    std::cout << "REEL\n";
	std::cout << "Title: " << _title<<std::endl;
    std::cout<< "Duration: " << _duration <<std::endl;
	std::cout << "likes: " << _likes << std::endl;
	std::cout << "URL: " << _URL << std::endl << std::endl;

}

bool Reel::changeTitle(std::string title) {
    std::cout<<"TITLE CHANGE" <<title;
	_title = title;
	return true;
}

// std::ostream &Reel::doprint(std::ostream &stream) const
// {
//     // TODO: insert return statement here
// }

bool Reel::editPost() {
    std::cout << "added filter, AR effects, and music";
    return true;
}


std::ostream& operator<< (std::ostream& stream, const Reel& reel){
    reel.print(stream);
    return stream;
}

std::ostream& Reel::print(std::ostream& stream) const {
    stream << "REEL"<<std:: endl;
	stream << "Title: " << _title << std::endl;
    stream<< "Duration: " <<_duration <<std::endl;
	stream << "likes: " << _likes << std::endl;
	stream << "URL: " << _URL;

    return stream;
}

std::istream& operator>>(std::istream& stream, Reel& reel) {

	reel.out(stream);
	return stream;
}


std::istream &Reel::out(std::istream &stream)
{
    std::cout<< "REEL INPUT"  << std::endl;

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


    if(_duration > 90) {
        std::cout << "max Story duratoin is 90. Setting duration to 90";
        _duration = 90;
    }

    return stream;
}



