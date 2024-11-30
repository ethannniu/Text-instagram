#ifndef PERSONAL
#define PERSONAL

#include "user.h"

class Personal: public User {
    public:
    Personal();
    Personal(const std::string& username, const std::string& email, const std::string& password, const std::string& bio, const std::string& URL);
    virtual ~Personal();

    Personal(const Personal& other);
    Personal& operator=(const Personal& other);


    void monetizePosts() override;
    virtual std::ostream& print(std::ostream& stream) const;

};

#endif