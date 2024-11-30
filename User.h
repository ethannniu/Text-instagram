// TO DO: #include all the standard libraries and your own libraries here
#ifndef USER__
#define USER__
#include <iostream>
#include "Post.h"
#include "LinkedBagDS/LinkedBag.h"
#include "Reel.h"
#include "Story.h"
#include <memory>

// To DO: define the class User with the necessary functions and data fields

class User{
    protected:
        std::string _username;
        std::string _email;
        std::string _password;
        std::string _bio;
        std::string _profilePicture;
        LinkedBag<std::shared_ptr<Post>> _posts;
        // LinkedBag<Post*> _posts;

    public:
        User();
        virtual ~User();
        User(const std::string& username, const std::string& email, const std::string& password, const std::string& bio, const std::string& URL);
        User(const User& other);
        User& operator=(const User& other);

        void displayProfile();
        bool changePassword(std::string newPassword);
        bool operator==(const User& otherUser) const; 
        std::shared_ptr<Post> getKthPost(int k);

        virtual void monetizePosts();
        bool modifyPost(int index);
        bool deletePost(int index);
        std::string getUsername();
        bool addPost(std::shared_ptr<Post> post);
        void displayPosts();
        int getPostCount();
        bool addReel(std::shared_ptr<Reel> reel);
        bool addStory(std::shared_ptr<Story> story);

        virtual std::ostream& print(std::ostream& stream) const;
        friend std::ostream& operator<< (std::ostream& stream, const User& user);
        friend std::istream& operator>>(std::istream& stream, User& user);
};

// This is a function that allows you to compare two users based on their username and email address.  
// You may directly include it in your class definition. 
// You don't need to modify it but will have to put it inside your class. 
// Operator == overloading function prototype:
#endif