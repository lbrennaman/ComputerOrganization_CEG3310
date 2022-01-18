#include <stdio.h>
#include <string.h>
#include <malloc.h>

// Defining a max length for strings to be input
#define MAX_LENGTH 100

// Creating the string type (an array of a max of 100 characters)
typedef char string[MAX_LENGTH];

// Structure to use to form tree
typedef struct Tree {
    string question;    // Question the cpu will ask the user
    struct Tree* yes;   // Pointer to this question's "yes" branch
    struct Tree* no;    // Pointer to this question's "no" branch
} Tree ;

// Function Prototypes
Tree* inquire(Tree*, Tree*);
Tree* create(Tree*, Tree*);
void getChoice(string);
void printer(Tree*);

// Main method
int main(void) {

    // Initialize a choice variable for the user's choice input
    string choice = "yes\n";

    // Initialize the head branch
    Tree* head = (Tree*) malloc(sizeof(Tree));
    strcpy(head->question, "dog");   // First and only animal the computer knows at the start

    // Execute as a do/while since the program must execute at least once
    do {
        // Create a current since the head should only change if it is replace by another head (not the case every time)
        Tree* current = head;

        // Begin asking questions
        current = inquire(current, head);

        // If either yes or no pointer == head, set the head to the current pointer
        if (current->yes == head || current->no == head) {
            head = current;
        } // Otherwise, the head did not change

        // Get user's input to see if they wish to continue
        printf("Would you like to continue? \n > ");
        getChoice(choice);
    } while (strcmp(choice, "yes\n") == 0);

    // Clean up
    printf("Cleaning up:\n");
    printer(head);

    // Free memory
    free(head);
}

// Function definitions

//__________________________________________________________________
// inquire function
// The computer goes through the tree, asking questions until a null
// Yes? The computer has won if it reached a null yes pointer
// No? The computer lost if it reached a null no pointer
//__________________________________________________________________
Tree* inquire(Tree* current, Tree* head) {

    // Initialize a string variable to keep track of the user's choices
    string choice = "";

    // Keep going until the computer has hit a win or a loss
    int victory = 1;
    while (victory) {
        // Print out the current branch's question
        // This prompt is for animals, only print when on an animal's branch (last branch in tree)
        if (current->yes == NULL && current->no == NULL) {
            printf("Is it a %s?\n > ", current->question);
        } else {
            printf("%s\n > ", current->question);
        }

        // Get user input to answer the computer's question
        getChoice(choice);

        // Depending on the answer, yes or no, branch to different points
        // If choice == yes, if current-> yes != null then set current = current->yes
        if (strcmp(choice, "yes\n") == 0) {
            if (current->yes != NULL) { // Move to the next branch in the tree
                current = current->yes;
            } else { // Otherwise, the computer wins
                printf("I win!\n");
                victory = 0;
            }
        } else { // Else, the input had to be no. If current-> no != null, move to next branch. Otherwise, create two new branches and insert them into tree
            if (current->no != NULL) { // Move on to the next branch in the tree
                current = current->no;
            } else {
                // Create two new branches
                current = create(current, head);
                victory = 0;
            }
        }
    }
    return current;
}

//________________________________________________
// create function
// Function to create two new branches on the tree
//________________________________________________
Tree* create(Tree* current, Tree* head) {
    // Create the two new branches (named after what their questions will be based on)
    Tree* whatAnimal = (Tree*) malloc(sizeof(Tree));
    Tree* distinguish = (Tree*) malloc(sizeof(Tree));

    // Initialize questions by getting user input
    printf("I lose! What animal were you thinking of: \n > ");
    fgets(whatAnimal->question, MAX_LENGTH - 1, stdin);
    whatAnimal->question[strlen(whatAnimal->question) - 1] = 0; // Remove null from animal

    printf("What question would help differentiate a %s from a %s?\n > ", current->question, whatAnimal->question);
    fgets(distinguish->question, MAX_LENGTH - 1, stdin);
    distinguish->question[strlen(distinguish->question) - 1] = 0; // Remove null from question

    // Now that the questions are set, based off of user input set distinguish's yes and no pointers
    printf("Would the answer to that be yes or no for a %s?\n > ", current->question);
    string choice;
    getChoice(choice);
    if (strcmp(choice, "yes\n") == 0) { // If the user entered yes, set the yes pointer to current and no pointer to whatAnimal
        distinguish->yes = current;
        distinguish->no = whatAnimal;
    } else { // Set no pointer to current and yes pointer to whatAnimal
        distinguish->no = current;
        distinguish->yes = whatAnimal;
    }

    // The two branches have been added to the tree
    return distinguish;
}

//____________________________________________________________
// getChoice function
// Validates input so that either "no" or "yes" must be input
//____________________________________________________________
void getChoice(string choice) {
    // Set validate to 1 (true) to run loop until a "no" or "yes" has been input
    int validate = 1;
    while (validate) {
        // Get user for choice
        fgets(choice, MAX_LENGTH - 1, stdin);

        // Verify if yes or no, if so then set validate to 0 to exit validation loop
        if (strcmp(choice, "no\n") == 0 || strcmp(choice, "yes\n") == 0) {
            validate = 0;
        } else {
            printf("Input was not \"no\" or \"yes\" so you must retry.\n");
        }
    }
}

//______________________________________________________________________________
// printer function
// While pointer not null, go through and print questions
// Recursively go through branches and print them until all branches are printed
//______________________________________________________________________________
void printer(Tree* head) {
    if (head->yes) {
        printer(head->yes);
    }
    if (head->no) {
        printer(head->no);
    }
    if (head->yes == NULL && head->no == NULL) { // Prints when on last branch (when branch must be an animal and only an animal)
        printf("Deleting question: Is it a %s\n", head->question);
    } else { // Prints when it cannot be an animal
        printf("Deleting question: %s\n", head->question);
    }
}