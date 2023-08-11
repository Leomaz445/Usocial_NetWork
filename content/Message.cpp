
#include "Message.h"
#include "../exceptions/InvalidLengthException.h"

#include <utility>

/**
 * @brief Implementation of the getText method from the Message class.
 *
 * @return The text content of the message.
 */
std::string Message::getText() {
    return _text;
}

/**
 * @brief Constructs a Message object with the provided text.
 *
 * @param txt The text content intended for the message.
 * @throws InvalidLengthException If the length of the text is outside
 *         the valid range (between MIN_MESSAGE_SIZE and MAX_MESSAGE_SIZE).
 */
Message::Message(std::string txt) {
    if (txt.length() < MIN_MESSAGE_SIZE || txt.length() > MAX_MESSAGE_SIZE) {
        throw InvalidLengthException();
    }
    _text = std::move(txt);
}
