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
	//Website web("C:/Users/mssevov18/source/repos/Cpp-to-Html/Cpp-to-Html/SiteTest", "index", "Main Page");
	Website web("C:/Users/mssevov18/Documents/Website", "index", "Main Page");
	web.addStyleSheet("Body{background-color:");
	web.addElement(Paragraph("", "", "Hello World").toString());
	web.addElement(Paragraph("", "color:blue; font-size:200", "Eat banica").toString());
	web.addElement(WebsiteElement("hr", "", "height: 20; border-color:green; background-color: yellow").toString());
	web.addElement(Paragraph("", "", "Welcome to hell").toString());
	web.addElement(WebsiteElement("br", "", "").toString());
	web.addElement(Link("", "", "Welcome to hell, pt2.", "www.bing.com").toString());
	web.makeHtmlFile();
}