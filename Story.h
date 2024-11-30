#include "Post.h"
#ifndef STORY__
#define STORY__

class Story: public Post {
    private:
    int computeTimeToExpiration() const;
    std::chrono::_V2::steady_clock::time_point _time_stamp;

    public:

    Story();
    Story(std::string& title,std::string& URL, int duration);
    virtual ~Story();
    Story(const Story& other);
    Story& operator=(const Story& other);

    bool createReel();
    void displayPost() override;
    bool editPost();
    bool changeTitle(std::string title);
    // friend std::ostream& operator<< (std::ostream& stream, const Story& story);
    virtual std::ostream& print(std::ostream& stream) const;

    virtual std::istream& out(std::istream& stream);
};
#endif