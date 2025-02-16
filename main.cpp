#include <algorithm>
#include <iostream>
#include <fstream>
using namespace std;

void appendFile(const string& filename) {
    ofstream outFile(filename, ios::app);

    string input;
    cout << "Enter data to add to the file (type 'exit' to stop):\n";

    while (true) {
        getline(cin,input);
        if (input == "exit") break;
        outFile << input;
    }

    outFile.close();
    cout << "Data successfully appended.\n";
}

void reverseFile(const string& inputFilename, const string& outputFilename) {
    ifstream inFile(inputFilename);

    string content, line;
    while (getline(inFile, line)) {
        content += line + "\n";
    }
    inFile.close();

    reverse(content.begin(), content.end());

    ofstream outFile(outputFilename);
    outFile << content;
    outFile.close();

    cout << "Reversed text successfully written to " << outputFilename;
}

int main() {

    string inputFile = "C:/Users/iansm/OneDrive/Desktop/CSC450_CT5_mod5.txt";
    string outputFile = "C:/Users/iansm/OneDrive/Desktop/CSC450-mod5-reverse.txt";

    appendFile(inputFile);
    reverseFile(inputFile, outputFile);

    return 0;
}