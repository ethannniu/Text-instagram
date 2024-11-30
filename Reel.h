#include "Post.h"
#ifndef REEL__
#define REEL__

class Reel: public Post {
    public:

    Reel();
    Reel(const std::string& title, const std::string& URL,int duration);
    virtual ~Reel();
    Reel(const Reel& other);
    Reel& operator=(const Reel& other);

    bool createReel();
    void displayPost() override;
    bool editPost();
    bool changeTitle(std::string title);
    friend std::ostream& operator<< (std::ostream& stream, const Reel& reel);
    virtual std::ostream& print(std::ostream& stream) const;

    friend std::istream& operator>> (std::istream& stream, Reel& reel);
    virtual std::istream& out(std::istream& stream);

};
#endif