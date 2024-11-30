#include <iostream> 
#include <string>

// TO DO: #include any other libraries you need
#include "Instagram340.h"
#include "LinkedBagDS/LinkedBag.h"
#include "User.h"
#include "Reel.h"
using namespace std;

// /** 
//  * 
//  * Displays the application's main menu
//  * pre create a new object of type User
//  * @param user object to interact with
//  * 
//  * */
void displayUserManu(User& user){
	int userChoice = 0;
	do {
		cout << "\n Hi, "<< user.getUsername() <<", what would you like to do:\n"
		<< "1. Display Profile\n"
		<< "2. Modify Password\n"
		<< "3. Create Post\n"
		<< "4. Display All Posts\n"
		<< "5. Display Kth Post\n"
		<< "6. Modify Post\n"
		<< "7. Delete Post\n"
		<< "8. Edit Post\n"
		<< "9. Monitize Posts\n"
		<< "0. Logout\n"
		<< "Choice: ";
		cin >> userChoice;

		switch (userChoice) {
			case 1:{
				// TO DO: display user's profile information
				    cout  << user ;
				break;
			}
			case 2: {
				// TO DO: ask for new password and update user's password
				std:string x; 
				cout << "Type your new password: "; 
				cin >> x; //user input
				user.changePassword(x);//changes password
				break;
			}
			case 3: {
				//Pick a type of post
				int pick = 0;
				cout << "Choose post type:\n"// choose between reel and Story
				<< "1. Reel\n"
				<< "2. Story\n";
				cin >> pick;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(),'\n');

				if(pick == 1) {
					//create reel
					cout<<"creating reel\n";
					// string title;
					// cout<<"Title: \n";//ask for title
					// cin >> title;

					// cin.clear();
					// cin.ignore(numeric_limits<streamsize>::max(),'\n');

					// string url;
					// cout<<"URL: \n";//ask for url
					// cin >> url;

					// cin.clear();
					// cin.ignore(numeric_limits<streamsize>::max(),'\n');

					// int dur;
					// cout<<"Duration: \n";
					// cin >> dur;// ask for duration
					// cout <<  dur;

					// cin.clear();
					// cin.ignore(numeric_limits<streamsize>::max(),'\n');

					// if(dur > 90) {
					// 	cout << "max Story duratoin is 90. Setting duration to 90";
					// 	dur = 90;
					// }
					Reel reel;
					cin >> reel;
					if (std::cin.fail()) {
 					   	std::cout << "Invalid input. \n";
						std::cin.clear();
    					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
					} else {
   						user.addReel(std::make_shared<Reel>(reel)); 
					}
				
	
					break;
				}
				else if(pick == 2){ //create story

					cout<<"creating story\n";

					Story story;
					cin >> story;
					
					if (std::cin.fail()) {
 					   	std::cout << "Invalid input. \n";
						std::cin.clear();
    					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
					} else {
						user.addStory(make_shared<Story>(story));// add story
					}

				}
				else{
					std::cout << "invalid";
				}
				// TO DO: ask user to choose between Reel and Story, ask them to input post details:
				//        (title, media URL, video length in seconds)
				//        Your program should set the time stamp to current time (code provided in Post.cpp) 
				// then create the post and add it to the user's posts
				break;
			}
			case 4:{
				// cout<< user << endl;
				user.displayPosts(); //user.displayPosts uses << operator
				break;
			}
			case 5: {
				int pick = 0;
				cout << "Choose Value K:\n";//ask usefor value
				cin >> pick;
				if(pick <= 0 ||pick > user.getPostCount()) {// check for outlier
					cout<<"error: Value to big.\n Posts:" << user.getPostCount();
				}
				else {
					std::shared_ptr<Post> thepost = user.getKthPost(pick - 1); //gets the post and displays
					thepost->displayPost();
				}

			
				// TO DO: ask the user for a value k
				// Find the Kth post, if k > Linked Bag size, 
				//    return an error message that includes the size of the Linked Bag
				break;
			}
			case 6: {
				int pick = 0;
				cout << "Choose Value K:\n";
				cin >> pick;

				string title;

				if(pick < 1 ||pick > user.getPostCount()) {
					cout<<"error: Value to big.\n LinkedBag size:" << user.getPostCount(); // check if k is too big
				}
				else {
					cout <<"New Title: \n";//ask for new title
					cin >> title;
					std::shared_ptr<Post> thepost = user.getKthPost(pick - 1);
					thepost->changeTitle(title);// changes titles
				}
				// TO DO: ask the user for the index of the post they want to modify and the new title
				// Find the post, then update the title. 
				// If index > Linked Bag size, 
				//   return an error message that includes the size of the Linked Bag
				break;
			}

			case 7: {
				int pick = 0;
				cout << "Choose Value K:\n";
				cin >> pick;

				if(pick < 1 ||pick > user.getPostCount()) {
					cout<<"error: Value to big.\n LinkedBag size:" << user.getPostCount();//check for outlier
				}
				else {
					user.deletePost(pick - 1);//delete post at index
					// Post* thepost = user.getKthPost(pick - 1);
					// if (thepost != nullptr) {
           			//  	std::cout << "Editing post..." << std::endl;
           			// 	thepost->(); 
        			// } else {
           			// 	 std::cout << "Error: Post not found." << std::endl;
       				//  }
				}
				// TO DO: ask the user for the index of the post they want to delete 
				// Find the post, then remove it from the list. 
				// If index > LinkedBag size, 
				//    return an error message that includes the size of the Linked Bag
				break;
			}

			case 8: {
				int pick = 0;
				cout << "Choose Value K:\n"; //ask for k value
				cin >> pick;

				if(pick < 1 ||pick > user.getPostCount()) {
					cout<<"error: Value to big.\n LinkedBag size:" << user.getPostCount(); //check for outliser
				}
				else {
					std::shared_ptr<Post> thepost = user.getKthPost(pick - 1);// get the kth post
					if (thepost != nullptr) {
           			 	std::cout << "Editing post..." << std::endl;
           				thepost->editPost(); //edits post
        			} else {
           				 std::cout << "Error: Post not found." << std::endl;
       				 }
				}
				break;
				//edit a post (using the video editing function described below): the user needs to specify
				// the index of the post they want to edit, and
			}
			case 9: {
				user.monetizePosts();
				break;
			}
			case 0: {
				cout << "Logging you out." << endl;
				break;
			}
			default:
				cout << "Invalid choice. Please try again." << endl;
		}

	} while (userChoice != 0);
}


int main(){
	// Instantiating the program using the default constructor
	// With this implementation, the application will only have one user
	
	Instagram340 instagram; 
	cout << instagram << endl;
	cin >> instagram;
	// TO DO: Ask the user to enter their information 
	//        Instantiate a new User object
	int choice = 0;
	do{
		cout << endl << "---------------------------------------"<< endl;

		cout << "Instagram 340 menu"<< endl;
		cout << "1: create account"<< endl;
		cout << "2: choose account/ login"<< endl;
		cout << "3: display users"<< endl;
		cout << "0: logout" << endl;

		cout << "Choose a number: ";
		cin >> choice;

 		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 

		switch(choice) {


			case 1:{
				cin >> instagram;
				break;
			}

			case 2: {
				int num;
				cout << "Choose a number: "<< endl;
				cin >> num;

				if(num > instagram.userCount()) {
					cout << "Error: number too big";
					break;
				}
	 			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 

				std::shared_ptr<User> currentUser = instagram.getUser(num - 1);
				displayUserManu(*currentUser);
				break;
			}

			case 3: {
				instagram.displayUsers();
				break;
			}
			case 0: {
				cout << "Logging you out." << endl;
				break;
			}
			default:
				cout << "Invalid choice. Please try again." << endl;



		}


	}while(choice !=0);

	// call instagram createUser function 
	// replace /*...*/ with the right parameters


	// instagram.createUser(_username, _email, _password, _bio, _profilePicture);



	// Retrieve the user 



				
	return 0;
}