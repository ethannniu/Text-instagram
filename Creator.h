#ifndef CREATOR
#define CREATOR

#include "user.h"

class Creator: public User {
    public:
    Creator();
    Creator(const std::string& username, const std::string& email, const std::string& password, const std::string& bio, const std::string& URL);
    virtual ~Creator();

    Creator(const Creator& other);
    Creator& operator=(const Creator& other);

    void monetizePosts() override;
    virtual std::ostream& print(std::ostream& stream) const;

};

#endif