#ifndef IMAGE_H
#define IMAGE_H

#include <vector>
#include <string>

/**
 * @brief Represents a Bounding Box around an object (rectangular)
 */
class Bbox
{
	public:

		/**
		 * @brief Builds a bounding box
		 * @param xmin the x coordinate of the top-left corner
		 * @param ymin the y coordinate of the top-left corner
		 * @param xmax the x coordinate of the bot-right corner
		 * @param ymax the y coordinate of the bot-right corner
		 */
		Bbox(float xmin, float ymin, float xmax, float ymax);

		~Bbox();

		/**
		 * @brief Gives the XML definition of this object
		 * @return the XML string of this object
		 */
		std::string XMLstring();

	private:

		/**
		 * @brief the x coordinate of the top-left corner
		 */
		float _xmin;

		/**
		 * @brief the y coordinate of the top-left corner
		 */
		float _ymin;

		/**
		 * @brief the x coordinate of the bot-right corner
		 */
		float _xmax;

		/**
		 * @brief the y coordinate of the bot-right corner
		 */
		float _ymax;
};

/**
 * @brief An object in a picture
 */
class Object
{
	public:

		/**
		 * @brief Builds an object with his label and the bounding box around him
		 * @param label the name of the object
		 * @param confidence the confidence score of detection
		 * @param bbox the bounding box around the object
		 */
		Object(std::string label, float confidence, Bbox bbox);

		~Object();

		/**
		 * @brief Gives the XML definition of this object
		 * @return the XML string of this object
		 */
		std::string XMLstring();

	private:

		/**
		 * @brief the name of the object
		 */
		std::string _label;

		/**
		 * @brief the confidence score of detection
		 */
		float _confidence;

		/**
		 * @brief the bounding box around the object
		 */
		Bbox _bbox;
};

/**
 * @brief The Image class contains all the information about the objects in it etc.
 */
class Image
{
	public:

		/**
		 * @brief Builds an Image given a line divided into substrings
		 * @param tokens the vector of sub-strings of a line in a .txt file
		 */
		Image(std::vector<std::string> tokens);

		~Image();

		/**
		 * @brief Gives the XML definition of this object
		 * @return the XML string of this object
		 */
		std::string XMLstring();

	private:

		/**
		 * @brief the objects detected in the image
		 */
		std::vector<Object> _objects;

		/**
		 * @brief the fileName of the picture
		 */
		std::string _fileName;
};

#endif