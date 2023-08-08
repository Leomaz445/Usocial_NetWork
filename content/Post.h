//
// Post Class Header
//

#ifndef UNTITLED3_POST_H
#define UNTITLED3_POST_H

#include <string>
#include "../media/Media.h"
#include "../exceptions/InvalidLengthException.h"
#include "../exceptions/NullMediaException.h"

// Constants for post size boundaries.
static const int POST_MIN_SIZE = 1;
static const int POST_MAX_SIZE = 255;

/**
 * @brief Represents a post that can optionally contain media.
 */
class Post {
private:
    std::string _text; /**< Text of the post */
    Media *_media; /**< Media content of the post (can be null) */
public:
    /**
    * @brief Constructor that creates a post with given text.
    *
    * @param post Text for the post.
    * @throws InvalidLengthException If post length is out of valid range.
    */
    explicit Post(std::string post);

    /**
    * @brief Constructor that creates a post with given text and media.
    *
    * @param post Text for the post.
    * @param media Media content for the post.
    * @throws InvalidLengthException If post length is out of valid range.
    */
    Post(std::string post, Media *media);

    /**
    * @brief Retrieves the text of the post.
    *
    * @return Text of the post.
    */
    std::string getText();

    /**
    * @brief Retrieves the media content of the post.
    *
    * @return Pointer to the Media object.
    * @throws NullMediaException If there's no media content in the post.
    */
    Media *getMedia();

    /**
    * @brief Checks if the post has any media content.
    *
    * @return true if the post has media, otherwise false.
    */
    bool hasMedia() const;

    /**
    * @brief Destructor for the Post class. Frees the media content.
    */
    ~Post();
};


#endif //UNTITLED3_POST_H
