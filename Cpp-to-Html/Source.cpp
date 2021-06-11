#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "conio.h"

using namespace std;

#include "Website.h"
#include "WebsiteElement.h"
#include "InheritedWebsiteEliments.h"

#define _path "C:/Users/mssevov18/Documents/Website"

int main()
{
	HTML page(_path, "index", "Main Page");

	CSS css(_path, "sheet");
	css.addContent(
		"Body{\
		background-color:black;\
		color:white;}\
		Div{\
		border: 5 solid black}\
		"
	);
	page.addStyleSheet("sheet");

	int size;
	int tmp;
	vector<int> data;

	cin >> size;
	for (int i = 0; i < size; i++)
	{
		cin >> tmp;
		data.push_back(tmp);
	}

		bool swapped;
		for (size_t i = 0; i < data.size() - 1; i++)
		{
			swapped = false;
			for (size_t j = 0; j < data.size() - 1 - i; j++)
			{
				if (data[j] > data[j + 1])
				{
					int temp = data[j];
					data[j] = data[j + 1];
					data[j + 1] = temp;
					swapped = true;
				}
			}
			if (swapped == false)
				break;
		}

		for (size_t i = 0; i < data.size(); i++)
		{
			page.addElement(Paragraph::Div(
				"",
				"width:" + to_string(data[i] * 100) + "; background-color:rgb(" + to_string(data[i] * 16) + ", " + to_string(data[i] * 16) + "," + to_string(data[i] * 32) + ");",
				Paragraph("", "", to_string(data[i])).toString()
			).toString());
		}
		
		css.makeFile();
		page.makeFile(0);

		for (size_t i = 0; i < data.size(); i++)
			cout << data[i] << ' ';
}