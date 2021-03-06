#include "InheritedWebsiteEliments.h"

Paragraph::Paragraph()
{
	_tag = "p";
	_class = "";
	_style = "";

	_content = "Hello World";
}

Paragraph::Paragraph(const std::string& __class, const std::string& __style, const std::string& __content)
{
	_tag = "p";
	_class = __class;
	_style = __style;

	_content = __content;
}

Paragraph Paragraph::Div(const std::string& __class, const std::string& __style, const std::string& __content)
{
	Paragraph out(__class, __style, __content);
	out._tag = "div";
	return out;
}

Paragraph Paragraph::OrderedList(const std::string& __class, const std::string& __style, const std::string& __content, const std::string& __start)
{
	Paragraph out(__class + "\" start=\"" + __start, __style, __content);
	out._tag = "ol";
	return out;
}

Paragraph Paragraph::UnorderedList(const std::string& __class, const std::string& __style, const std::string& __content)
{
	Paragraph out(__class, __style, __content);
	out._tag = "ul";
	return out;
}

Paragraph Paragraph::ListItem(const std::string& __class, const std::string& __style, const std::string& __content, const std::string& __value)
{
	Paragraph out(__class, __style, __content);
	out._tag = "li";
	return out;
}

void Paragraph::setContent(const std::string& in)
{
	_content = in;
}

std::string Paragraph::getContent()
{
	return _content;
}

std::string Paragraph::toString()
{
	return ("<" + _tag + " class=\"" + _class + "\" style=\"" + _style + "\"> " + _content + " </" + _tag + ">");
}


Link::Link()
{
	_tag = "a";
	_class = "";
	_style = "";
	_content = "Hello World";

	_href = "codingburgas.bg";
}

Link::Link(const std::string& __class, const std::string& __style, const std::string& __content, const std::string& __href)
{
	_tag = "a";
	_class = __class;
	_style = __style;
	_content = __content;

	_href = __href;
}

void Link::setHref(const std::string& in)
{
	_href = in;
}

std::string Link::getHref()
{
	return _href;
}


std::string Link::toString()
{
	return ("<" + _tag + " href=\"" + _href + "\" class=\"" + _class + "\" style=\"" + _style + "\"> " + _content + "</" + _tag + ">");
}

Image::Image()
{
	_tag = "img";
	_class = "";
	_style = "";

	_src = "";
	_alt = "img";
}

Image::Image(const std::string& __class, const std::string& __style, const std::string& __src, const std::string& __alt)
{
	_tag = "img";
	_class = __class;
	_style = __style;

	_src = __src;
	_alt = __alt;
}

void Image::setSrc(const std::string& in)
{
	_src = in;
}

std::string Image::getSrc()
{
	return _src;
}

void Image::setAlt(const std::string& in)
{
	_alt = in;
}

std::string Image::getAlt()
{
	return _alt;
}

std::string Image::toString()
{
	return ("<" + _tag + " src=\"" + _src + "\" alt=\"" + _alt + " class=\"" + _class + "\" style=\"" + _style + "\">");
}
