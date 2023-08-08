
#ifndef UNTITLED3_BUSINESSUSER_H
#define UNTITLED3_BUSINESSUSER_H


#include "User.h"
/**
 * @class BusinessUser
 * @brief Derived from User, represents a specialized business user.
 *
 * The BusinessUser class inherits from the User class and offers a specialized method
 * to send messages, with its own specific logic and exceptions handling.
 */
class BusinessUser: public User {
public:
    /**
    * @brief Default constructor for the BusinessUser class.
    */
    BusinessUser() = default;
    /**
     * @brief Send a message to another user.
    *
    * @param user The recipient User pointer.
    * @param message The message to send.
     *
    * @throw NullUserException If the provided user pointer is null.
    * @throw UserNotFoundException If the provided user is not found in the social network.
    *
    * @override Overrides the sendMessage function from the base User class.
    */
    void sendMessage(User* user, Message* message) override;

    /**
    * @brief Default destructor for the BusinessUser class.
    */
    ~BusinessUser() override = default;
};


#endif //UNTITLED3_BUSINESSUSER_H
