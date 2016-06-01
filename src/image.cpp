#include <image.h>
#include <sstream>

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
	return "<bbox xmin='" + to_string(_xmin) + "' ymin='"
		+ to_string(_ymin) + "' xmax='"
		+ to_string(_xmax) + "' ymax='"
		+ to_string(_ymax) + "' />";
}

Object::Object(string label, float confidence, Bbox bbox) :
	_label(label), _confidence(confidence), _bbox(bbox)
{

}

Object::~Object()
{

}

string Object::XMLstring()
{
	return "<object name='" + _label + "' confidence='"
	+ to_string(_confidence) + "'>"
	+ _bbox.XMLstring() 
	+ "</object>";
}

Image::Image(vector<string> tokens) :
	_objects(), _fileName(tokens[0])
{
	for(unsigned int i = 1; i < tokens.size(); i+=6)
	{
		Bbox bbox(stof(tokens[i+2]), stof(tokens[i+3]), stof(tokens[i+4]), stof(tokens[i+5]));
		Object object(tokens[i], stof(tokens[i+1]), bbox);
		_objects.push_back(object);
	}
}

Image::~Image()
{

}

string Image::XMLstring()
{
	string xml = "<image url='" + _fileName + "'>";

	for(unsigned int i = 0; i < _objects.size(); i++)
	{
		xml += _objects[i].XMLstring();
	}

	xml += "</image>";

	return xml;
}