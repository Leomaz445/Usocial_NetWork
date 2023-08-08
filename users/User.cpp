
#include "User.h"
#include "BusinessUser.h"


/**
 * @brief Retrieve the ID of the user.
 * @return User's ID.
 */
unsigned long User::getId() const {
    return id;
}

/**
 * @brief Retrieve the name of the user.
 * @return User's name.
 */
std::string User::getName() const {
    return name;
}

/**
 * @brief Add a user to the user's friend list.
 * @param user The user to be added as a friend.
 * @throw NullUserException If the provided user pointer is null.
 * @throw UserNotFoundException If the user does not exist.
 * @throw AlreadyFriends If the user is already a friend.
 */
void User::addFriend(User *user) {
    checkUserNull(user);
    tryingToAddYourSelf(user);
    checkIfBelongToTheSameNetWork(user);
    checkUserExists(user->getId());
    checkAlreadyFriends(user->getId());

    friends.push_back(user->getId());
}

/**
 * @brief Remove a user from the user's friend list.
 * @param user The user to be removed.
 * @throw NullUserException If the provided user pointer is null.
 */
void User::removeFriend(User *user) {
    if (user == nullptr) {
        throw NullUserException();
    }
    unsigned long userId = user->getId();
    auto it = std::find(friends.begin(), friends.end(), userId);
    if (it != friends.end()) {
        friends.erase(it);
    }
}

/**
 * @brief Create and add a text post.
 * @param val Content of the post.
 */
void User::post(const std::string &val) {
    Post *newPost = new Post(val);
    posts.push_back(newPost);
}

/**
 * @brief Create and add a media post.
 * @param val Content of the post.
 * @param media Associated media with the post.
 */
void User::post(const std::string &val, Media *media) {
    Post *newPost = new Post(val, media);
    posts.push_back(newPost);
}

/**
 * @brief Retrieve all posts by the user.
 * @return A reference to the list of posts.
 */
std::list<Post *> &User::getPosts() {
    return posts;
}

/**
 * @brief Display posts from friends.
 * @throw USocialNullException If USocial instance is unavailable.
 * @throw UserNotFoundException If a user in the friend list is not found.
 */
void User::viewFriendsPosts() {
    // Validation 1: Ensure the USocial object is available
    if (us == nullptr) {
        throw USocialNullException();
    }

    // Validation 2: Check if the friends list is empty
    if (friends.empty()) {
        std::cout << YOU_NAVE_NOT_FRIENDS_TO_VIEW_POSTS_FROM;
        return;
    }

    for (auto friendId: friends) {
        User *friendUser = us->getUserById(friendId);

        if (friendUser == nullptr) {
            throw UserNotFoundException();
        }

        std::list<Post *> friendPosts = friendUser->getPosts();
        std::string friendName = friendUser->getName();

        // Validation 3: Check if the friend has any posts
        if (friendPosts.empty()) {
            std::cout << friendName << HAS_NOT_MADE_ANY_POSTS;
            continue;  // Move to the next friend
        }

        for (auto post: friendPosts) {
            messageBuilder(friendId, friendName, post);
            std::cout << "\n";
        }
    }
}

/**
 * @brief Helper function to display a friend's post.
 * @param friendId ID of the friend.
 * @param friendName Name of the friend.
 * @param post Post to be displayed.
 * @throw NullPostException If the provided post is null.
 * @throw InvalidFriendNameException If the provided friend's name is empty.
 */
void User::messageBuilder(unsigned long friendId, const std::string &friendName, Post *post) {
    // Validation 1: Ensure the post is not null
    if (post == nullptr) {
        throw NullPostException();
    }

    // Validation 2: Ensure friendName is not empty
    if (friendName.empty()) {
        throw InvalidFriendNameException();
    }

    std::cout << "Friend Name: " << friendName
              << " | Friend ID: " << friendId
              << " | Post: " << post->getText();

    if (post->hasMedia()) {
        std::cout << " | Media: ";
        post->getMedia()->display();
    }
}

/**
 * @brief Store a received message.
 * @param message The received message.
 */
void User::receiveMessage(Message *message) {
    receiveMsgs.push_back(message);
}

/**
 * @brief Send a message to another user.
 * @param user The recipient user.
 * @param message The message to be sent.
 * @throw NullUserException If the recipient user is null.
 * @throw UserNotFoundException If the recipient user does not exist.
 * @throw NotInYourFriendList If the recipient user is not a friend.
 */
void User::sendMessage(User *user, Message *message) {
    if (user == nullptr) {
        delete message;
        throw NullUserException();
    }

    User *userMsg = us->getUserById(user->getId());

    if (userMsg == nullptr) {
        delete message;
        throw UserNotFoundException();
    }

    if (!isAlreadyFriends(user->getId())) {
        delete message;
        throw NotInYourFriendList();
    }

    userMsg->receiveMessage(message);
}

/**
 * @brief Display all received messages.
 */
void User::viewReceivedMessages() {
    for (auto message: receiveMsgs) {
        std::cout << message->getText() << "\n";
    }
}

/**
 * @brief Determine if a user is already a friend.
 * @param friendsId The ID of the user to check.
 * @return True if the user is a friend, otherwise false.
 */
bool User::isAlreadyFriends(unsigned long friendsId) {
    return std::find(friends.begin(), friends.end(), friendsId) != friends.end();
}

/**
 * @brief Check if the provided user is null.
 * @param user The user to check.
 * @throw NullUserException If the provided user pointer is null.
 */
void User::checkUserNull(User *user) {
    if (user == nullptr) {
        throw NullUserException();
    }
}

/**
 * @brief Check if a user with the given ID exists.
 * @param friendsId The ID of the user to check.
 * @throw UserNotFoundException If the user does not exist.
 */
void User::checkUserExists(unsigned long friendsId) {
    if (!us->isExists(friendsId)) {
        throw UserNotFoundException();
    }
}

/**
 * @brief Check if a user with the given ID is already a friend.
 * @param friendsId The ID of the user to check.
 * @throw AlreadyFriends If the user is already a friend.
 */
void User::checkAlreadyFriends(unsigned long friendsId) {
    if (isAlreadyFriends(friendsId)) {
        throw AlreadyFriends();
    }
}

/**
 * @brief Destructor for the User class. Cleans up dynamically allocated memory.
 */
User::~User() {
    for (auto &post: posts) {
        delete post;
    }
    posts.clear();

    for (auto &message: receiveMsgs) {
        delete message;
    }
    receiveMsgs.clear();
}

/**
 * @brief Copy constructor for the User class. Performs a deep copy.
 * @param other The User object to copy from.
 */
User::User(const User &other) : us(other.us), id(other.id), name(other.name), friends(other.friends) {
    for (auto &post: other.posts) {
        posts.push_back(new Post(*post));
    }
    for (auto &message: other.receiveMsgs) {
        receiveMsgs.push_back(new Message(*message));
    }
}

/**
 * @brief Copy assignment operator for the User class. Performs a deep copy.
 * @param other The User object to copy from.
 * @return Reference to the copied User object.
 */
User &User::operator=(const User &other) {
    if (this != &other) {
        // Free the existing resources
        for (auto &post: posts) {
            delete post;
        }
        for (auto &message: receiveMsgs) {
            delete message;
        }

        // Copy the data members
        us = other.us;
        id = other.id;
        name = other.name;
        friends = other.friends;

        // Copy the posts and messages
        for (auto &post: other.posts) {
            posts.push_back(new Post(*post));
        }
        for (auto &message: other.receiveMsgs) {
            receiveMsgs.push_back(new Message(*message));
        }
    }
    return *this;
}

/**
 * @brief Check if the user is trying to add themselves as a friend.
 * @param pUser The user to check against.
 * @throw CantAddYourSelf If the user tries to add themselves.
 */
void User::tryingToAddYourSelf(User *pUser) const {
    if (this->getId() == pUser->getId())
        throw CantAddYourSelf();

}

void User::checkIfBelongToTheSameNetWork(User *pUser) {
    if (this->us != pUser->us) {
        throw DifferentSocialNetWork();

    }

}

/**
 * @brief Returns the USocial instance associated with this user.
 *
 * @return Pointer to the USocial instance.
 */
USocial *User::getUSocialInstance() const {
    return us;
}
