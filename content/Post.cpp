//
// Post Class Implementation
//


#include "Post.h"


#include <utility>

/**
 * @brief Constructs a post object with given text.
 *
 * @param post Text content of the post.
 */
Post::Post(std::string post) {
    if (post.length() < POST_MIN_SIZE || post.length() > POST_MAX_SIZE) {
        throw InvalidLengthException();
    }
    _text = std::move(post);
    _media = nullptr;
}
/**
 * @brief Constructs a post object with given text and media content.
 *
 * @param post Text content of the post.
 * @param media Media content for the post.
 */
Post::Post(std::string post, Media *media) {
    if (post.length() < POST_MIN_SIZE || post.length() > POST_MAX_SIZE) {
        delete media;  // prevent potential memory leak
        throw InvalidLengthException();
    }
    _text = std::move(post);
    _media = media;
}
/**
 * @brief Fetches the text content of the post.
 *
 * @return Text content of the post.
 */
std::string Post::getText() { return _text; }
/**
 * @brief Fetches the media content of the post.
 *
 * @return Media content of the post.
 * @throws NullMediaException If the post doesn't contain any media.
 */
Media *Post::getMedia() {
    if (_media == nullptr) {
        throw NullMediaException();
    }
    return _media;
}
/**
 * @brief Checks if the post contains any media.
 *
 * @return true if the post contains media, otherwise false.
 */
bool Post::hasMedia() const {
    return _media != nullptr;
}
/**
 * @brief Destructor that deletes the media content.
 */
Post::~Post() {
    delete _media;
}



