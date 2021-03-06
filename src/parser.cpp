#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

#include <image.h>

using namespace std;

/**
 * @brief splits a string into a vector of substrings given a delimiter
 * @param str the string to split
 * @param char the delimiter
 * @return a vector of strings
 */
vector<string> split(string str, char delimiter) 
{
  vector<string> internal;
  stringstream ss(str); // Turn the string into a stream.
  string tok;
  
  while(getline(ss, tok, delimiter)) 
  {
    internal.push_back(tok);
  }
  
  return internal;
}

/**
 * @brief Reads a TXT file to output it in a XML file for detection purpose objects
 * @param  argc the amount of argument, must be 2 (3 considering command)
 * @param  argv the arguments, meaning input and ouptut files
 * @return      0 EXIT_SUCCESS
 */
int main(int argc, char** argv)
{
	if(argc != 3)
		cerr << "USAGE : input_file.txt output_file.xml" << endl;

	ifstream input(argv[1]);
	string line;
	vector<Image> images;

	while(getline(input, line))
	{
		vector<string> tokens = split(line, '/');
		Image image(tokens);
		images.push_back(image);
	}

	string xml = "<images>";

	for(unsigned int i = 0; i < images.size(); i++)
		xml += images[i].XMLstring();

	xml += "</images>";

	ofstream output(argv[2]);
	output << xml;

	input.close();
	output.close();

	return 0;
}