#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

#include "Website.h"
#include "WebsiteElement.h"
#include "InheritedWebsiteEliments.h"

int main()
{
	Website web;
	web.path = "C:/Users/mssevov18/source/repos/Cpp-to-Html/Cpp-to-Html/SiteTest";
	web.filename = "index";
	web.pagename= "Main Page";
	web.elements.push_back(Paragraph("", "", "Hello dimitko").toString());
	web.elements.push_back(Paragraph("", "color:blue; font-size:200", "Eat banica").toString());
	web.elements.push_back(WebsiteElement("hr", "", "height: 20; border-color:green; background-color: yellow").toString());
	web.elements.push_back(Paragraph("", "", "Welcome to hell").toString());
	web.elements.push_back(WebsiteElement("br", "", "").toString());
	web.elements.push_back(Link("", "", "Welcome to hell, pt2.", "www.bing.com").toString());
	web.makeHtmlFile();
}