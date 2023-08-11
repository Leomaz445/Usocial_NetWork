/**
 * @file User.h
 * @brief Defines the User class, representing a user in a social networking context.
 * @details This class provides functionalities for managing a user's friends, posts, and messages.
 * @author [Leonid Mazarsky]
 * @date [08.08.2023]
 */
#ifndef UNTITLED3_USER_H
#define UNTITLED3_USER_H

#include "../social/USocial.h"
#include "../content/Post.h"
#include <list>
#include "../content/Message.h"
#include <algorithm>
#include "../exceptions/NullUserException.h"
#include "../exceptions/AlreadyFriends.h"
#include "../exceptions/NotInYourFriendList.h"
#include "../exceptions/CantAddYourSelf.h"
#include "../exceptions/InvalidFriendNameException.h"
#include "../exceptions/NullPostException.h"
#include "../exceptions/USocialNullException.h"
#include "../exceptions/DifferentSocialNetWork.h"
#include "../exceptions/CrossNetworkMsgError.h"

static const char *const HAS_NOT_MADE_ANY_POSTS = " has not made any posts.\n";
static const char *const YOU_NAVE_NOT_FRIENDS_TO_VIEW_POSTS_FROM = "You have no friends to view posts from.\n";

/**
 * @class User
 * @brief Represents a user in the USocial context.
 */
class User {
    friend class USocial; // Give USocial class access to private and protected members of User

private:
    // Private helper functions for internal operations
    static void messageBuilder(unsigned long friendId, const std::string &friendName, Post *post);

    static void checkUserNull(User *user);

    void checkUserExists(unsigned long friendsId);

    void checkAlreadyFriends(unsigned long friendsId);

    bool isAlreadyFriends(unsigned long friendsId);

    void tryingToAddYourSelf(User *pUser) const;

protected:
    USocial *us{};                       // Pointer to the USocial instance associated with the user.
    unsigned long id{};                  // Unique identifier for the user.
    std::string name;                    // Name of the user.
    std::list<unsigned long> friends;    // List of friends' IDs.
    std::list<Post *> posts;             // List of posts by the user.
    std::list<Message *> receiveMsgs;    // List of messages received by the user.

    User() = default;                    // Default constructor is protected to prevent external instantiation.

    /**
     * @brief Destructor for the User class.
     * @details This destructor is virtual to ensure that derived classes are destructed properly.
     */
    virtual ~User();

public:
    /**
     * @brief Copy constructor for the User class.
     * @param other The User object to be copied.
     */
    User(const User &other);

    /**
     * @brief Copy assignment operator for the User class.
     * @param other The User object to be copied.
     * @return Reference to the copied User object.
     */
    User &operator=(const User &other);

    /**
     * @brief Get the user's ID.
     * @return The ID of the user.
     */
    unsigned long getId() const;

    /**
     * @brief Get the user's name.
     * @return The name of the user.
     */
    std::string getName() const;

    /**
     * @brief Add a user to the friend list.
     * @param user Pointer to the User object to be added as a friend.
     */
    void addFriend(User *user);

    /**
     * @brief Remove a user from the friend list.
     * @param user Pointer to the User object to be removed from friends.
     */
    void removeFriend(User *user);

    /**
     * @brief Post a text-based content.
     * @param val The content of the post.
     */
    void post(const std::string &val);

    /**
     * @brief Post a media-based content.
     * @param val The content of the post.
     * @param media Pointer to the Media object associated with the post.
     */
    void post(const std::string &val, Media *media);

    /**
     * @brief Retrieve all posts by the user.
     * @return A list of pointers to Post objects.
     */
    std::list<Post *> &getPosts();

    /**
     * @brief View posts by friends.
     */
    void viewFriendsPosts();

    /**
     * @brief Receive a message.
     * @param message Pointer to the Message object.
     */
    void receiveMessage(Message *message);

    /**
     * @brief Send a message to another user.
     * @param user Pointer to the User to whom the message should be sent.
     * @param message Pointer to the Message object.
     */
    virtual void sendMessage(User *user, Message *message);

    /**
     * @brief View all received messages.
     */
    void viewReceivedMessages();

    void checkIfBelongToTheSameNetWork(User *pUser);

    USocial *getUSocialInstance() const;  // Getter function for 'us'
};

#endif //UNTITLED3_USER_H
