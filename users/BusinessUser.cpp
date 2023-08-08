#include "BusinessUser.h"

/**
 * @brief Sends a message to another user, specific to Business User.
 *
 * @details This function checks the existence of the user and then sends a message if they are found in the social network.
 *
 * @param user - Pointer to the recipient User.
 * @param message - Pointer to the Message object to send.
 * @exception NullUserException Thrown if the provided user pointer is null.
 * @exception UserNotFoundException Thrown if the user is not found in the social network.
 */

void BusinessUser::sendMessage(User *user, Message *message) {
    if (user == nullptr) {
        delete message;
        throw NullUserException();
    }

    User *userMsg = us->getUserById(user->getId());

    if (userMsg == nullptr) {
        delete message;
        throw UserNotFoundException();
    }

    if (this->us != user->getUSocialInstance()) {
        delete message;
        throw CrossNetworkMsgError();
    }

    userMsg->receiveMessage(message);
}
