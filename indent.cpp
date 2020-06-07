//Chethram Ramoutar
//4/1/20
//Lab 7B
//Instructor Maryash/Melissa

#include <iostream>
#include <cctype>
#include <fstream>
#include <string>
using namespace std;


string Indent_Count(string unindented, int indents)
{
    string tab = "";
    for(int i = 0; i < indents; i++) //add a tab into the string
    {
        tab += "\t";
    }
    return (tab + unindented); //return the string of tabs and the unindented string
}


int countChar(string e_string, char c)
{
    int count = 0;
    for(int i = 0; i < e_string.length(); i++) //counts the amount of a specific character in the given string
        if(e_string[i] == c)
            count++;
    return count;
}


string removeLeadingSpaces(string e_string)
{
    bool foundChar= false;
    for(int i = 0; i < e_string.length(); i++)
    {
        if(!isspace(e_string[i])) //checks if the current character is a space
            foundChar = true;

        if(foundChar) 
            return e_string.substr(i, e_string.length() - i); //return everything except the space at the end. Keeps the entire string.
    }

    return "";
}

int main()
{
    string e_string = "";
    int T_Amount = 0; //Increase based on the indentation.


    string input_file;
    cout << "File name: ";
    cin >> input_file;

    string output_file_name;
    cout << "Exit File Name: ";
    cin >> output_file_name;

    ofstream output_file;
    output_file.open(output_file_name);


    ifstream fin(input_file);
    while(getline(fin, e_string))
    {
        if(removeLeadingSpaces(e_string)[0] == '}') //if its equal to that character, do this
            output_file << Indent_Count(removeLeadingSpaces(e_string), T_Amount - 1) << endl;

        else
            output_file << Indent_Count(removeLeadingSpaces(e_string), T_Amount) << endl; //else do this.

        T_Amount += countChar(e_string, '{'); //add the indent amount 
        T_Amount -= countChar(e_string, '}'); //subtract the amount from the indented
    }
    output_file.close();
    cout << "Done!";

    return 0;
}