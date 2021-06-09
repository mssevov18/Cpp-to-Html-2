#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

#include "Website.h"

Website::Website()
{
}

void Website::makeHtmlFile()
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

		file
			<< "<SCRIPT type = \"text/JavaScript\">\n"
			<< "	function AutoRefresh(t) {\n"
			<< "	setTimeout(\"location.reload(true);\", t);\n"
			<< "}\n"
			<< "</SCRIPT>\n";
		file
			<< "</HEAD>\n"
			<< "<BODY onload = \"JavaScript:AutoRefresh(5000);\">\n";

		for (size_t i = 0; i < elements.size(); i++)
			file << elements[i] << endl;

		// Thanks to EIR
		//for (WebsiteElement element : elements)
		//	file << element.toString() << endl;

		file
			<< "\n"
			<< "</BODY>\n"
			<< "</HTML>\n";

		file.close();
	}
}
