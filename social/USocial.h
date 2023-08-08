#ifndef UNTITLED3_USOCIAL_H
#define UNTITLED3_USOCIAL_H

#include <iostream>
#include <map>
#include <random>
#include "../exceptions/UserNotFoundException.h"

class User;//forward declaration
/**
 * @brief Represents the social networking platform which manages users.
 */
class USocial {
private:
    std::map<unsigned long, User *> _users; // Maps User IDs to User pointers
    std::default_random_engine _generator; //Random engine for generating user IDs
public:
    /**
     * @brief Default constructor.
    */

    USocial() = default;

    /**
     * @brief Copy constructor.
     * @param other Another USocial object.
     */

    USocial(const USocial &other);

    /**
    * @brief Copy assignment operator.
    * @param other Another USocial object.
    * @return Reference to this USocial.
    */
    USocial &operator=(const USocial &other); // Copy assignment operator

    /**
     * @brief Generate a unique user ID.
     * @return Unique user ID.
     */
    unsigned long generateUserId();

    /**
    * @brief Register a new user.
    * @param name Name of the user.
    * @param status Indicates if user is a business user.
    * @return Pointer to the newly registered User.
    */
    User *registerUser(const std::string &name, bool status = false);

    /**
    * @brief Remove a user.
    * @param user Pointer to the user to be removed.
    */
    void removeUser(User *);

    /**
    * @brief Checks if a user with given ID exists.
    * @param serialId ID of the user.
    *@return true if user exists, false otherwise.
    */
    bool isExists(unsigned long serialId);

    /**
     * @brief Fetch user pointer using ID.
     * @param serialId ID of the user.
     * @return Pointer to the user with given ID.
     * @exception UserNotFoundException Thrown if user is not found.
     */
    User *getUserById(unsigned long serialId);

    /**
     * @brief Fetch all users.
     * @return Reference to the map of all users.
     */
    std::map<unsigned long, User *> &getUsers() { return _users; }

    /**
     * @brief Destructor. Cleans up all users.
     */
    ~USocial();
};


#endif //UNTITLED3_USOCIAL_H
