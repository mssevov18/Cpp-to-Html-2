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

private:

public:
	std::string path;
	std::string filename;
	std::string pagename;
	std::vector<std::string> elements;
	std::vector<std::string> styleSheets;

public:
	void makeHtmlFile();
};

