#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

#include "Website.h"

HTML::HTML()
{
	path = "C:/Users/mssevov18/Documents";
	filename = "temp";
	pagename = "Temporary";
}

HTML::HTML(const std::string& path, const std::string& filename, const std::string& pagename)
{
	this->path = path;
	this->filename = filename;
	this->pagename = pagename;
}

void HTML::addElement(const std::string& element)
{
	elements.push_back(element + "\n");
}

void HTML::removeElement()
{
	elements.pop_back();
}

void HTML::removeElement(const size_t& index)
{
	elements.erase(elements.begin() + index);
}

void HTML::addStyleSheet(const std::string& styleSheet)
{
	styleSheets.push_back(styleSheet);
}

std::string HTML::getFilePath()
{
	return std::string(path + "/" + filename + ".html");
}

void HTML::makeFile(int refreshRate)
{
	fstream file;
	file.open(path + "/" + filename + ".html", fstream::out, fstream::trunc);

	if (file.is_open())
	{
		file
			<< "<HTML>\n"
			<< "<HEAD>\n"
			<< "<META NAME = \"GENERATOR\" Content = \"Microsoft Visual Studio\">\n"
			<< "<TITLE>" + pagename + "</TITLE>\n";

		for (size_t i = 0; i < styleSheets.size(); i++)
			file << "<LINK rel = \"stylesheet\" type = \"text/css\" href = \"" << path + "/" + styleSheets[i] + ".css" << "\">\n";

		if (refreshRate!=0)
			file
				<< "<SCRIPT type = \"text/JavaScript\">\n"
				<< "	function AutoRefresh(t) {\n"
				<< "	setTimeout(\"location.reload(true);\", t);\n"
				<< "}\n"
				<< "</SCRIPT>\n"
				<< "</HEAD>\n"
				<< "<BODY onload = \"JavaScript:AutoRefresh(" + to_string(refreshRate) +");\">\n";
		else
			file
				<< "</HEAD>\n"
				<< "<BODY>\n";

		for (size_t i = 0; i < elements.size(); i++)
			file << elements[i];

		file
			<< "\n"
			<< "</BODY>\n"
			<< "</HTML>\n";

		file.close();
	}
}

CSS::CSS()
{
	path = "C:/Users/mssevov18/Documents";
	filename = "temp";
}

CSS::CSS(const std::string& path, const std::string& filename)
{
	this->path = path;
	this->filename = filename;
}

void CSS::addContent(const std::string& newContent)
{
	content += newContent + "\n";
}

void CSS::replaceContent(const std::string& newContent)
{
	content = newContent;
}

void CSS::makeFile()
{
	fstream file;
	file.open(path + "/" + filename + ".css", fstream::out, fstream::trunc);

	if (file.is_open())
	{
		file << content;
		file.close();
	}
}
