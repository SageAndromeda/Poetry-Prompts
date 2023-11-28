// Poetry Prompts
// Sage Hardiman
// 10/29/2023
// Randomly generates a list of prompts to help inspire poems
// Inspired by https://wewritepoems.wordpress.com/2010/07/01/thursday-prompt-9-line-by-line/

// Includes
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


int main()
{
    srand(time(nullptr));

    vector <pair<string, bool>> promptList;

    // Preloaded prompts:
    // Kept in vectors with string, bool pairs to prevent repetition
    promptList.push_back(make_pair("A feeling", false));
    promptList.push_back(make_pair("Observe the scenery of your immediate surroundings", false));
    promptList.push_back(make_pair("Personification of an inanimate object", false));
    promptList.push_back(make_pair("Use a metaphor", false));
    promptList.push_back(make_pair("Recall a prominent memory", false));
    promptList.push_back(make_pair("Use symbolism in a statement", false));
    promptList.push_back(make_pair("Associate some form of weather with a feeling described elsewhere in your poem", false));
    promptList.push_back(make_pair("Tell a lie, about anything", false));
    promptList.push_back(make_pair("Make a reference to a holiday or season", false));
    promptList.push_back(make_pair("State a fact about a favorite artist or poet", false));
    promptList.push_back(make_pair("Compare yourself to a specific piece from a favorite artist/poet", false));
    promptList.push_back(make_pair("Negate a lie", false));
    promptList.push_back(make_pair("Describe a daydream or parts of a dream you've had", false));
    promptList.push_back(make_pair("Refer to a vacationing location", false));
    promptList.push_back(make_pair("Describe your gender abstractly", false));
    promptList.push_back(make_pair("Complete the phrase \"_____ is stronger than \"_____\"", false));
    promptList.push_back(make_pair("Write about summer", false));
    promptList.push_back(make_pair("Make up something about someone near you", false));
    promptList.push_back(make_pair("Only use words that start with a letter from your first name", false));
    promptList.push_back(make_pair("Think of a random word. Now use that as the first word in this line", false));
    promptList.push_back(make_pair("Write about a sport", false));
    promptList.push_back(make_pair("State a fact about a favorite character", false));
    promptList.push_back(make_pair("Ask someone for a random word to use", false));
    promptList.push_back(make_pair("Only use words starting with letters from your last name", false));
    promptList.push_back(make_pair("Choose a random noun to use", false));
    promptList.push_back(make_pair("Choose a random adjective to use", false));
    promptList.push_back(make_pair("Choose a random verb to use", false));
    promptList.push_back(make_pair("Choose a random number to use", false));
    promptList.push_back(make_pair("Choose a random adverb to use", false));
    promptList.push_back(make_pair("Use a pronoun", false));
    promptList.push_back(make_pair("Turn on the radio and write about what's playing", false));
    promptList.push_back(make_pair("Mention a day of the week", false));
    promptList.push_back(make_pair("Mention an animal", false));
    promptList.push_back(make_pair("Write about someone you haven't talked to in a long time", false));
    promptList.push_back(make_pair("Use an idiom", false));
    promptList.push_back(make_pair("Write about a mundane moment", false));
    promptList.push_back(make_pair("Use a line from your favorite song", false));
    promptList.push_back(make_pair("Use alliteration", false));
    promptList.push_back(make_pair("Use a simile", false));
    promptList.push_back(make_pair("Use an onomatopoeia", false));
    promptList.push_back(make_pair("Use a rhyme", false));
    promptList.push_back(make_pair("Use two similes", false));
    promptList.push_back(make_pair("Use a simile and a metaphor", false));
    promptList.push_back(make_pair("Write a different line of the poem in reverse", false));
    promptList.push_back(make_pair("Use your least favorite color", false));
    promptList.push_back(make_pair("Use repitition", false));
    promptList.push_back(make_pair("Describe something you can't currently see", false));
    promptList.push_back(make_pair("Use a hyperbole", false));
    promptList.push_back(make_pair("Repeat a different line in your poem, but change one or two words", false));
    promptList.push_back(make_pair("Personify your favorite food", false));

    // Let user input prompts:
    string uPrompts = "";
    while (uPrompts != "DONE") {
        std::cout << "Insert a prompt you would like to add, or type \"done\". " << endl;
        getline(cin, uPrompts);

        // Check for "DONE"
        transform(uPrompts.begin(), uPrompts.end(), uPrompts.begin(), ::toupper);
        if (uPrompts != "DONE") {
            promptList.push_back(make_pair(uPrompts, false));
        }
    }

    // Ask how many prompts they would like to print
    // It cannot be bigger than the total number of prompts or less than 1
    int numPrompts = 0;
    do {
        cout << "How many lines would you like to write? (Cannot be greater than "
            << promptList.size() << ")\n";

        cin >> numPrompts;

        // Tell user that they put in an invalid amount
        if ((numPrompts > promptList.size()) || (numPrompts < 1))
            cout << "Invalid amount. " << endl;

    } while ((numPrompts > promptList.size()) || (numPrompts < 1));

    cout << endl << "Here are your prompts: " << endl;

    // Randomly print unique prompts:
    int numPrinted = 0;
    do {
        int aPrompt = rand() % (promptList.size());

        // If the prompt hasn't been printed already, print it and increment amount printed 
        if ((promptList[aPrompt].second) == false) {
            promptList[aPrompt].second = true;
            cout << (numPrinted + 1) << ". " << promptList[aPrompt].first << endl;
            ++numPrinted;
        }

    } while (numPrinted < numPrompts);

}

