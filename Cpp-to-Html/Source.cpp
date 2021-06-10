#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "conio.h"

using namespace std;

#include "Website.h"
#include "WebsiteElement.h"
#include "InheritedWebsiteEliments.h"

int main()
{
	bool testing = false;
	if (!testing)
	{
		CSS css("C:/Users/mssevov18/Documents/Website", "styleSheet");
		css.addContent(
			"BODY\
			{\
				background-color: rgb(120,50,10);\
				color:rgb(50,150,250);\
			}");
		css.makeFile();

		HTML index("C:/Users/mssevov18/Documents/Website", "index", "Main Page");
		index.addStyleSheet("styleSheet");
		index.addElement(Paragraph("", "", "Hello World").toString());
		
		HTML result("C:/Users/mssevov18/Documents/Website", "result", "Main Page");
		result.addStyleSheet("styleSheet");
		
		HTML extra("C:/Users/mssevov18/Documents/Website", "extra", "Main Page");
		extra.addStyleSheet("styleSheet2");
		extra.addElement(Paragraph("", "", "Hello World").toString());

		std::vector<std::string> links;
		std::vector<int> data;
		int size;
		int temp;
		int sum = 0;

		links.push_back("index");
		links.push_back("result");
		links.push_back("extra");

		for (size_t i = 0; i < links.size(); i++)
		{
			index.addElement(Link("", "", links[i], links[i] + ".html").toString());
			result.addElement(Link("", "", links[i], links[i] + ".html").toString());
			extra.addElement(Link("", "", links[i], links[i] + ".html").toString());
		}

		cout << "size: ";
		cin >> size;

		cout << "\nInput numbers: ";
		for (size_t i = 0; i < size; i++)
		{
			cin >> temp;
			data.push_back(temp);
			sum++;
		}

		index.addElement(Paragraph("", "", to_string(char(sum) + char(sum / size))).toString());

		std::string tempS = "\n";
		for (size_t i = 0; i < size; i++)
			tempS += Paragraph::ListItem("", "", to_string(data[i]), "").toString() + "\n";

		bool swapped;
		for (int i = 0; i < size - 1; i++)
		{
			swapped = false;
			for (int j = 0; j < size - i - 1; j++)
			{
				if (data[j] > data[j + 1])
				{
					int tmp = data[j];
					data[j] = data[j + 1];
					data[j + 1] = tmp;
					swapped = true;
				}
			}
			if (swapped == false)
				break;
		}

		result.addElement(Paragraph::OrderedList("", "", tempS, "").toString());

		tempS = "\n\n";
		for (size_t i = 0; i < size; i++)
			tempS += Paragraph::ListItem("", "", to_string(data[i]), "").toString() + "\n";

		result.addElement(Paragraph::OrderedList("", "", tempS, "").toString());

		index.makeFile();
		result.makeFile();
		extra.makeFile();


		int r = 100, g = 100, b = 100;
		extra.addElement(Paragraph("", "", to_string(r) + ", " + to_string(g) + ", " + to_string(b)).toString());
		CSS css2("C:/Users/mssevov18/Documents/Website", "styleSheet2");
		css2.addContent(
			"BODY\
			{\
				background-color: rgb(" + to_string(r) + "," + to_string(g) + "," + to_string(b) + ");\
				color:rgb(" + to_string(255 - r) + "," + to_string(255 - g) + "," + to_string(255 - b) + ");\
			}");
		css2.makeFile();
		char a = 0;
		while (a!=27)
		{
			a = _getch();
			switch (a)
			{
			case 'q':
				r++;
				break;
			case 'a':
				r--;
				break;
			case 'w':
				g++;
				break;
			case 's':
				g--;
				break;
			case 'e':
				b++;
				break;
			case 'd':
				b--;
				break;
			default:
				break;
			}

			if (r > 255)
				r = 0;
			if (r < 0)
				r = 255;
			if (g > 255)
				g = 0;
			if (g < 0)
				g = 255;
			if (b > 255)
				b = 0;
			if (b < 0)
				b = 255;

			css2.replaceContent(
				"BODY\
				{\
					background-color: rgb(" + to_string(r) + "," + to_string(g) + "," + to_string(b) + ");\
					color:rgb(" + to_string(255 - r) + "," + to_string(255 - g) + "," + to_string(255 - b) + ");\
				}");
			css2.makeFile();

			extra.removeElement();
			extra.addElement(Paragraph("", "", to_string(r) + ", " + to_string(g) + ", " + to_string(b)).toString());
			extra.makeFile();
		}

		return 0;
	}
	CSS css("C:/Users/mssevov18/Documents/Website", "styleSheet");
	css.addContent(
		"BODY\
		{\
			background-color: rgb(40,40,40);\
			color:rgb(250,250,250);\
		}\
		.mitko\
		{\
			position: absolute;\
			left: 100px;\
			top: 150px;\
			font-size: 30;\
		}");
	css.makeFile();

	HTML page("C:/Users/mssevov18/Documents/Website", "index", "Main Page");
	page.addStyleSheet("styleSheet");
	page.addElement(Paragraph("", "", "Hello World").toString());
	page.addElement(Paragraph("", "color:blue; font-size:200", "Eat banica").toString());
	page.addElement(Paragraph::Div("", "",
		Paragraph("", "", "Lorem ipsum").toString() + "\n" +
		Paragraph("", "", "Dolor sit amen").toString() + "\n" +
		Image("", "", "C:/Users/mssevov18/Downloads/Tom-And-Jerry-11-1024x640.jpg", "dell").toString() + "\n" +
		Paragraph::OrderedList("","",
			Paragraph::ListItem("","","mtiko","").toString() + "\n" +
			Paragraph::ListItem("","","pianica","").toString() + "\n" +
			Paragraph::ListItem("","","milka","").toString() + "\n" +
			Paragraph::ListItem("","","c++ is best","").toString() + "\n"
			,"10").toString() + "\n" +
		Paragraph("", "", "letaklsdn").toString() + "\n" +
		Paragraph("", "", "sindf").toString() + "\n" +
		Paragraph("mitko", "", "Hello World").toString() + "\n" +
		Image("", "", "", "dell").toString() + "\n" +
		Paragraph("", "", "Helloasd ad World").toString() + "\n" +
		Paragraph("", "", "Hello Worladssadd").toString()
		).toString());
	page.addElement(WebsiteElement("hr", "", "height: 20; border-color:green; background-color: yellow").toString());
	page.addElement(Image("", "border: 10px solid black", "https://th.bing.com/th/id/Rba87c4ad9cbac7b686798af9fae36c14?rik=RQsSpmEUsiUdkw&riu=http%3a%2f%2fwww.codingburgas.bg%2fwp-content%2fuploads%2f2019%2f07%2fcode-new-23-3-410x260.png&ehk=Lni%2fuTtpVyeNSzqtrkTfs0mHeV8%2f4wzbCCGuasGwudE%3d&risl=&pid=ImgRaw", "Dicks").toString());
	page.addElement(Paragraph("mitko", "", "Welcome to hell").toString());
	page.addElement(WebsiteElement("br", "", "").toString());
	page.addElement(Link("", "", "Welcome to hell, pt2.", "https://www.bing.com").toString());
	page.makeFile();
}