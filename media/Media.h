
//
// Abstract Media Class
//

#ifndef UNTITLED3_MEDIA_H
#define UNTITLED3_MEDIA_H

/**
 * @brief Abstract base class for different media types.
 */
class Media {
public:
    /**
    * @brief Virtual function to display media content.
    */
    virtual void display() = 0;

    /**
    * @brief Default virtual destructor.
    */
    virtual ~Media() = default;
};


#endif //UNTITLED3_MEDIA_H
