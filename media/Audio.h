//
// Audio Media Class
//

#ifndef UNTITLED3_AUDIO_H
#define UNTITLED3_AUDIO_H


#include "Media.h"
#include <iostream>
/**
 * @brief Derived class representing Audio media.
 */
class Audio: public Media {
private:
    /**
    * @brief Constant indicating media type.
    */
    constexpr static const char *const AUDIO = "AUDIO";
public:
    /**
    * @brief Override display function to show audio content.
    */
    void display() override;


};


#endif //UNTITLED3_AUDIO_H
