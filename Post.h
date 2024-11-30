// TO DO: #include all the standard libraries and your own libraries here
#ifndef POST__
#define POST__
#include <iostream>
#include <chrono>
// #include "LinkedBagDS/LinkedBag.h"
// To DO: define the class Post with the necessary functions' prototypes and data fields
class Post{
    protected:
        std::string _title;
        std::chrono::_V2::steady_clock::time_point _time_stamp;
        int _likes;
        std::string _URL;
        int _duration;

    private:
        int computeTimeToExpiration() const;

    public: 
        Post();
        Post(const std::string& title, const std::string& URL, const int duration);
        virtual ~Post();
        Post(const Post& other);

        bool operator==(const Post& otherPost) const; 
        Post& operator=(const Post& other);

        virtual void displayPost();
        bool changeTitle(std::string title);
        virtual bool editPost();


        virtual std::ostream& print(std::ostream& stream) const;
        friend std::ostream& operator<< (std::ostream& stream, const Post& post);

        friend std::istream& operator>> (std::istream& stream, Post& post);
        virtual std::istream& out(std::istream& stream);
};




// This is a function that allows you to compare two posts based on their title. 
// You may directly include it in your class definition. 
// You don't need to modify it but will have to put it inside your class. 
// Operator overloading function prototype:

// This is a helper function -- it should be private.

#endif