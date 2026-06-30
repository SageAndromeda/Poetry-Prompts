// Poetry Prompts
// Sage Hardiman
// 1/21/2024
// Randomly generates a list of prompts to help inspire poems
// Inspired by "Thursday Prompt #9: Line by Line" by Mallery
    // https://wewritepoems.wordpress.com/2010/07/01/thursday-prompt-9-line-by-line/

// Includes and using statements
// Useful tools that let parts of the code work
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <cstdlib> 

using std::cout; using std::cin; using std::endl;
using std::vector;
using std::string;
using std::pair; using std::make_pair;
using std::transform;

// Code starts here
int main()
{
    // Uses the time this starts for random number generation
    srand(time(nullptr));

    // Vectors hold a list of stuff such as strings (words/sentences)
    vector <pair<string, int>> promptList;

    // Preloaded prompts:
    // Kept in vectors with string, int pairs to prevent repetition
    promptList.push_back(make_pair("Use two metaphors", 0));
    promptList.push_back(make_pair("Use a metaphor", 0));
    promptList.push_back(make_pair("Write about your favorite item", 0));
    promptList.push_back(make_pair("Write the first fun fact that comes to mind", 0));
    promptList.push_back(make_pair("Lie", 0));
    promptList.push_back(make_pair("Write about a time spent with a friend", 0));
    promptList.push_back(make_pair("Tell the truth. About anything", 0));
    promptList.push_back(make_pair("Mention a work of art and/or an artist", 0));
    promptList.push_back(make_pair("Mention an author; they don't have to be famous", 0));
    promptList.push_back(make_pair("Write about someone you consider \"family.\" They don't necessarily have to be related to you", 0));
    promptList.push_back(make_pair("Write four lines where the last word of each rhymes", 0));
    promptList.push_back(make_pair("Use a gerund", 0));
    promptList.push_back(make_pair("Use the subject line of a recent email", 0));
    promptList.push_back(make_pair("Use personification", 0));
    promptList.push_back(make_pair("Describe your gender abstractly", 0));
    promptList.push_back(make_pair("Complete the phrase \"_____ is stronger than \"_____\"", 0));
    promptList.push_back(make_pair("Write about summer", 0));
    promptList.push_back(make_pair("Make up something about someone near you", 0));
    promptList.push_back(make_pair("Only use words that start with letters in your first name", 0));
    promptList.push_back(make_pair("Think of a random word. Now use that as the first word in this line", 0));
    promptList.push_back(make_pair("Write about a sport", 0));
    promptList.push_back(make_pair("State a fact about a favorite character", 0));
    promptList.push_back(make_pair("Ask someone for a random word to use", 0));
    promptList.push_back(make_pair("Only use words starting with letters from your last name", 0));
    promptList.push_back(make_pair("Choose a random noun to use", 0));
    promptList.push_back(make_pair("Choose a random adjective to use", 0));
    promptList.push_back(make_pair("Choose a random verb to use", 0));
    promptList.push_back(make_pair("Choose a random number to use", 0));
    promptList.push_back(make_pair("Choose a random adverb to use", 0));
    promptList.push_back(make_pair("Use a pronoun", 0));
    promptList.push_back(make_pair("Turn on the radio and write about what's playing", 0));
    promptList.push_back(make_pair("Mention a day of the week", 0));
    promptList.push_back(make_pair("Mention an animal", 0));
    promptList.push_back(make_pair("Write about someone you haven't talked to in a long time", 0));
    promptList.push_back(make_pair("Use an idiom", 0));
    promptList.push_back(make_pair("Write about a mundane moment", 0));
    promptList.push_back(make_pair("Use a line from your favorite song", 0));
    promptList.push_back(make_pair("Use alliteration", 0));
    promptList.push_back(make_pair("Use a simile", 0));
    promptList.push_back(make_pair("Use an onomatopoeia", 0));
    promptList.push_back(make_pair("Use a rhyme", 0));
    promptList.push_back(make_pair("Use two similes", 0));
    promptList.push_back(make_pair("Use a simile and a metaphor", 0));
    promptList.push_back(make_pair("Write a different line of the poem in reverse", 0));
    promptList.push_back(make_pair("Use your least favorite color", 0));
    promptList.push_back(make_pair("Use repitition", 0));
    promptList.push_back(make_pair("Describe something you can't currently see", 0));
    promptList.push_back(make_pair("Use a hyperbole", 0));
    promptList.push_back(make_pair("Repeat a different line in your poem, but change one or two words", 0));
    promptList.push_back(make_pair("Personify your favorite food", 0));

    // Default number of prompts:
    int numPrompts = promptList.size();

    // Let user input prompts:
    string uPrompts = "";
    while (uPrompts != "DONE") {
        cout << "Insert a prompt you would like to add, or type \"done\". " << endl;
        getline(cin, uPrompts);

        // Check for "DONE"
        transform(uPrompts.begin(), uPrompts.end(), uPrompts.begin(), ::toupper);
        if (uPrompts != "DONE") {
            promptList.push_back(make_pair(uPrompts, 0));
        }
    }

    // If they added their own, ask if they'd only like those ones.
    if(promptList.size() > numPrompts) {
        cout << "Would you like to use built in prompts (yes/no)?" << endl;
        uPrompts = "";
        getline(cin, uPrompts);

        transform(uPrompts.begin(), uPrompts.end(), uPrompts.begin(), ::toupper);

        // Check that they input yes/no
        if (uPrompts == "N" || uPrompts == "NO") {
            // Delete user input prompts:
            promptList.erase(promptList.begin(), promptList.begin()+numPrompts);
        }
    }

    // Ask how many prompts they would like to print
    // It cannot be bigger than the total number of prompts or less than 1
    // You should also edit it so they cannot enter invalid input
    numPrompts = 0;
    do {
        cout << "How many lines would you like to write? (Cannot be greater than "
            << promptList.size() << ")\n";
        cin >> numPrompts;

        // Check that they put in a number:
        while (cin.fail()) {
            cout << "Invalid input. Please enter a number in digits" << endl;
            cin.clear();
            cin.ignore(256, '\n');
            cout << "How many lines would you like to write? (Cannot be greater than "
                << promptList.size() << ")\n";
            cin >> numPrompts;
        }


        // Tell user that they put in an invalid amount
        if ((numPrompts > promptList.size()) || (numPrompts < 1))
            cout << "Invalid amount. " << endl;

    } while ((numPrompts > promptList.size()) || (numPrompts < 1));

    cout << endl << "Here are your prompts: " << endl;

    // Randomly print unique prompts then delete them from list
    int numPrinted = 0;
    do {
        int aPrompt = rand() % (promptList.size());

        cout << (numPrinted + 1) << ". " << promptList[aPrompt].first << endl;
        promptList.erase(promptList.begin() + aPrompt);
        ++numPrinted;

    } while (numPrinted < numPrompts);

}
