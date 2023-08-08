
#include "USocial.h"
#include "../users/BusinessUser.h"
/**
 * @brief Remove a user from the platform.
 * @details Removes the user from all friend lists and deletes it.
 * @param user Pointer to the user to be removed.
 * @exception NullUserException Thrown if provided user pointer is null.
 * @exception UserNotFoundException Thrown if user is not found in the platform.
 */
void USocial::removeUser(User *user) {
    if (user == nullptr) {
        throw NullUserException();
    }

    if (isExists(user->getId())) {
        for (auto& userPair : _users) {
            User* anotherUser = userPair.second;
            anotherUser->removeFriend(user);
        }

        User *userToRemove = _users[user->getId()];
        _users.erase(user->getId());
        delete userToRemove;
    } else {
        throw UserNotFoundException();
    }
}

/**
 * @brief Register a user in the platform.
 * @details Depending on the status flag, registers either a regular user or a business user.
 * @param name Name of the user to register.
 * @param status If true, register as BusinessUser, otherwise as User.
 * @return Pointer to the newly registered user.
 */
User *USocial::registerUser(const std::string &name, bool status) {
    unsigned long userId = generateUserId();
    User *newUser = nullptr;
    if (status) {
        newUser = new BusinessUser();
        newUser->name = name;
        newUser->id = userId;
        newUser->us = this;
    } else {
        newUser = new User();
        newUser->name = name;
        newUser->id = userId;
        newUser->us = this;
    }
    _users.emplace(userId, newUser);
    return newUser;
}

/**
 * @brief Generate a unique user ID.
 * @details Keeps generating IDs until a unique one is found.
 * @return Unique user ID.
 */
unsigned long USocial::generateUserId() {
    unsigned long key = 0;
    std::uniform_int_distribution<unsigned long> distribution(0, std::numeric_limits<unsigned long>::max());
    do {
        key = distribution(_generator);
    } while (_users.find(key) != _users.end());

    return key;

}

/**
 * @brief Check if a user with the given ID exists in the platform.
 * @param serialId ID of the user to check.
 * @return true if user exists, false otherwise.
 */
bool USocial::isExists(unsigned long serialId) {
    auto it = _users.find(serialId);
    if (it != _users.end())
        return true;
    return false;
}

/**
 * @brief Retrieve a user by their ID.
 * @param serialId ID of the user to retrieve.
 * @return Pointer to the user.
 * @exception UserNotFoundException Thrown if the user with the given ID is not found.
 */
User *USocial::getUserById(unsigned long serialId) {
    if (isExists(serialId)) {
        return _users[serialId];
    }
    throw UserNotFoundException();
}

/**
 * @brief Destructor. Frees memory of all users.
 */
USocial::~USocial() {
    for (auto &userPair: _users) {
        delete userPair.second;
    }
    _users.clear();
}

/**
 * @brief Copy constructor. Deep copies all users.
 * @param other Another USocial object to copy from.
 */
USocial::USocial(const USocial &other) {
    for (auto &pair : other._users) {
        _users[pair.first] = new User(*(pair.second));
    }
}

/**
 * @brief Copy assignment operator. Deep copies all users.
 * @param other Another USocial object to copy from.
 * @return Reference to this USocial object.
 */
USocial& USocial::operator=(const USocial &other) {
    if (this != &other) {
        // Free the existing resources
        for (auto &pair : _users) {
            delete pair.second;
        }
        _users.clear();

        // Copy from other
        for (auto &pair : other._users) {
            _users[pair.first] = new User(*(pair.second));
        }
    }
    return *this;
}





