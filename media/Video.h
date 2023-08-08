//
// Video Media Class
//

#ifndef UNTITLED3_VIDEO_H
#define UNTITLED3_VIDEO_H


#include "Photo.h"
#include <iostream>
/**
 * @brief Derived class representing Video media.
 */
class Video: public Media {
private:
    /**
    * @brief Constant indicating media type.
    */
    constexpr static const char *const VIDEO = "VIDEO";
public:
    /**
    * @brief Override display function to show video content.
    */
    void display() override;

};


#endif //UNTITLED3_VIDEO_H
