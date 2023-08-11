#ifndef UNTITLED3_MESSAGE_H
#define UNTITLED3_MESSAGE_H

#include <string>

// Define constraints on the message's size.
static const int MIN_MESSAGE_SIZE = 1;
static const int MAX_MESSAGE_SIZE = 255;

/**
 * @class Message
 * @brief Represents a text-based message with size constraints.
 *
 * The Message class encapsulates a text string with length restrictions
 * determined by MIN_MESSAGE_SIZE and MAX_MESSAGE_SIZE.
 */
class Message {
private:
    std::string _text; ///< Text content of the message.
public:
    /**
    * @brief Constructs a Message object with the provided text.
    *
    * @param text The text content intended for the message.
    * @throws InvalidLengthException If the length of the text is outside
    *         the valid range (between MIN_MESSAGE_SIZE and MAX_MESSAGE_SIZE).
    */
    explicit Message(std::string text);

/**
 * @brief Retrieves the text content of the message.
 *
 * @return The text content of the message.
 */
    std::string getText();

    /// Default destructor for the Message class.
    ~Message() = default;

};


#endif //UNTITLED3_MESSAGE_H


   