#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "WebsiteElement.h"
#include "InheritedWebsiteEliments.h"

class Website
{
public:
	Website();
	Website(const std::string& path, const std::string& filename, const std::string& pagename);

private:
	std::string path;
	std::string filename;
	std::string pagename;

public:
	std::vector<std::string> elements;
	std::vector<std::string> styleSheets;

public:
	void addElement(const std::string& element);
	void addStyleSheet(const std::string& styleSheet);


	void makeHtmlFile();
};

