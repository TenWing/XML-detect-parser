#include <image.h>

using namespace std;

Bbox::Bbox(float xmin, float ymin, float xmax, float ymax) :
	_xmin(xmin), _ymin(ymin), _xmax(xmax), _ymax(ymax)
{

}

Bbox::~Bbox()
{

}

string Bbox::XMLstring()
{
	return "";
}

Object::Object(string label, Bbox bbox) :
	_label(label), _bbox(bbox)
{

}

Object::~Object()
{

}

string Object::XMLstring()
{
	return "";
}

Image::Image(vector<string> tokens) :
	_objects(), _fileName(tokens[0])
{

}

Image::~Image()
{

}

string Image::XMLstring()
{
	return "";
}