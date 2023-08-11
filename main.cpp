#include <iostream>
#include "social/USocial.h"
#include "media/Photo.h"
#include "media/Audio.h"
#include "users/BusinessUser.h"

void testPost();

int main() {
    USocial us;
    User *u1 = us.registerUser("Liron");
    User *u2 = us.registerUser("Yahav");
    User *u3 = us.registerUser("Shachaf");
    User *u4 = us.registerUser("Tsur", true);
    User *u5 = us.registerUser("Elit");
    u1->post("Hello world!");
    u2->post("I'm having a great time here :)", new Audio());
    u3->post("This is awesome!", new Photo());
    u5->addFriend(u1);
    u5->addFriend(u2);
    u5->viewFriendsPosts(); // should see only u1, u2 s' posts
    u4->sendMessage(u5, new Message("Buy Falafel!"));
    u5->viewReceivedMessages();
    try {
        u3->sendMessage(u5, new Message("All your base are belong to us"));
    }
    catch (const std::exception &e) {
        std::cout << "error: " << e.what() << std::endl;
    }
    u5->viewReceivedMessages();
    u3->addFriend(u5);
    u3->sendMessage(u5, new Message("All your base are belong to us"));
    u5->viewReceivedMessages();
//----------------------------------------------------------------------------------------------------------------------
    //My additional check
//----------------------------------------------------------------------------------------------------------------------

    //Adding a friend again
    try {
        u3->addFriend(u5);
    } catch (const std::exception &e) {
        std::cout << "error: " << e.what() << std::endl;

    }
//----------------------------------------------------------------------------------------------------------------------
    //remove friend
    try {
        std::cout << "-----------------------" << std::endl;
        std::cout << "Messages before removing a friend:" << std::endl;
        u5->viewFriendsPosts();
        u5->removeFriend(u1);
        std::cout << "-----------------------";
        std::cout << "Messages after removing a friend:" << std::endl;
        u5->viewFriendsPosts();

    } catch (const std::exception &e) {
        std::cout << "error: " << e.what() << std::endl;

    }
//----------------------------------------------------------------------------------------------------------------------
    //trying to remove a friend that doesn't exist:
    try {
        u5->removeFriend(u3);
    } catch (const std::exception &e) {
        std::cout << "error: " << e.what() << std::endl;

    }
//----------------------------------------------------------------------------------------------------------------------
    //trying to remove a user:
    try {
        std::cout << "------------------------------" << std::endl;
        std::cout << "Before deleting  the _users:" << std::endl;
        for (const auto &userPair: us.getUsers()) {
            unsigned long id = userPair.first;
            User *user = userPair.second;
            std::cout << "User ID: " << id << " Name: " << user->getName() << std::endl;
        }
        us.removeUser(u5);
        us.removeUser(u3);
        std::cout << "------------------------------" << std::endl;
        std::cout << "After deleting  the _users:" << std::endl;
        for (const auto &userPair: us.getUsers()) {
            unsigned long id = userPair.first;
            User *user = userPair.second;
            std::cout << "User ID: " << id << " Name: " << user->getName() << std::endl;
        }
    } catch (const std::exception &e) {
        std::cout << "error: " << e.what() << std::endl;

    }
//----------------------------------------------------------------------------------------------------------------------
    //removing all the _users:
    std::cout << "------------------------------" << std::endl;
    std::cout << "Removing all the _users:" << std::endl;
    us.removeUser(u1);
    us.removeUser(u2);
    us.removeUser(u4);
    for (const auto &userPair: us.getUsers()) {
        unsigned long id = userPair.first;
        User *user = userPair.second;
        std::cout << "User ID: " << id << " Name: " << user->getName() << std::endl;
    }
//----------------------------------------------------------------------------------------------------------------------
    //creating them again:
    User *u6 = us.registerUser("Liron");
    User *u7 = us.registerUser("Yahav");
    User *u8 = us.registerUser("Shachaf");
    User *u9 = us.registerUser("Tsur", true);

//----------------------------------------------------------------------------------------------------------------------
    u6->addFriend(u7);
    u6->addFriend(u8);
    //Trying to send a message as a business to a regular user
    u9->sendMessage(u6, new Message("how are you?"));
    std::cout << "------------------------------" << std::endl;
    std::cout << "Should have only one message:" << std::endl;
    u6->viewReceivedMessages();
    std::cout << "------------------------------" << std::endl;
    std::cout << "Trying to answer and will fail:" << std::endl;
    try {
        u6->sendMessage(u9, new Message("ok how are you?"));
    } catch (const std::exception &e) {
        std::cout << "error: " << e.what() << std::endl;
    }
//----------------------------------------------------------------------------------------------------------------------
    std::cout << "------------------------------" << std::endl;
    std::cout << "Trying to add yourself as a friend:" << std::endl;
    try {
        u6->addFriend(u6);
    } catch (const std::exception &e) {
        std::cout << "error: " << e.what() << std::endl;
    }
//----------------------------------------------------------------------------------------------------------------------
    std::cout << "------------------------------" << std::endl;
    std::cout << "TestsPost :" << std::endl;
    testPost();
//----------------------------------------------------------------------------------------------------------------------
    std::cout << "------------------------------" << std::endl;
    std::cout << "Trying to add a friend from a different network" << std::endl;
    USocial us1;
    USocial us2;
    auto u11 = us1.registerUser("Leonid");
    auto u12 = us2.registerUser("Mazarsky");

    try {
        u11->addFriend(u12);
    } catch (const std::exception &e) {
        std::cout << "error: " << e.what() << std::endl;
    }
//----------------------------------------------------------------------------------------------------------------------
    std::cout << "------------------------------" << std::endl;
    std::cout << "Trying to send a message to a different friend" << std::endl;
    auto u13 = us1.registerUser("shlomi", true);
    try {
        u13->sendMessage(u12, new Message("check"));
    } catch (const std::exception &e) {
        std::cout << "error: " << e.what() << std::endl;
    }
//----------------------------------------------------------------------------------------------------------------------
    std::cout << "------------------------------" << std::endl;
    std::cout << "Trying to Removing a Non-existent User" << std::endl;
    try {
        us.removeUser(nullptr);
    } catch (const std::exception &e) {
        std::cout << "error: " << e.what() << std::endl;
    }
//----------------------------------------------------------------------------------------------------------------------
    std::cout << "------------------------------" << std::endl;
    std::cout << "Trying to Fetch a User with Non-existent ID" << std::endl;
    try {
        us.getUserById(999999); // Assuming this ID doesn't exist.
    } catch (const std::exception &e) {
        std::cout << "error: " << e.what() << std::endl;
    }

    return 0;
}


void testPost() {
    // Test for valid post text
    try {
        Post p1("Hello, world!");
        std::cout << "Post p1: " << p1.getText() << "\n";
    } catch (const std::exception &e) {
        std::cout << "Error creating Post p1: " << e.what() << "\n";
    }

    // Test for long post text
    try {
        Post p2(std::string(300, 'a'));  // 300 'a' characters
    } catch (const std::exception &e) {
        std::cout << "Error creating Post p2: " << e.what() << "\n";
    }

    // Test for empty post text
    try {
        Post p3("");
    } catch (const std::exception &e) {
        std::cout << "Error creating Post p3: " << e.what() << "\n";
    }

    // Test for valid post with media
    try {
        auto *audio = new Audio();
        Post p4("This is an audio post", audio);
        std::cout << "Post p4: " << p4.getText() << ", Media: ";
        p4.getMedia()->display();
        std::cout << "\n";
    } catch (const std::exception &e) {
        std::cout << "Error creating Post p4: " << e.what() << "\n";
    }

    // Test for valid post with different media
    try {
        auto *photo = new Photo();
        Post p5("This is a photo post", photo);
        std::cout << "Post p5: " << p5.getText() << ", Media: ";
        p5.getMedia()->display();
        std::cout << "\n";
    } catch (const std::exception &e) {
        std::cout << "Error creating Post p5: " << e.what() << "\n";
    }

}