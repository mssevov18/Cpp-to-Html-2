#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "WebsiteElement.h"

class Paragraph : public WebsiteElement
{
public:
	Paragraph();
	Paragraph(const std::string& __class, const std::string& __style, const std::string& __content);

protected:
	std::string _content;

public:
	void		setContent(const std::string& in);
	std::string getContent();


	virtual std::string toString();
};

class Link : public Paragraph
{
public:
	Link();
	Link(const std::string& __class, const std::string& __style, const std::string& __content, const std::string& __href);

protected:
	std::string _href;

public:
	void		setHref(const std::string& in);
	std::string getHref();


	virtual std::string toString();
};

class Image : protected Link
{
public:
	Image();
	Image(const std::string& __class, const std::string& __style, const std::string& __src, const std::string& __alt);

protected:
	std::string _src;
	std::string _alt;

public:
	void		setSrc(const std::string& in);
	std::string getSrc();

	void		setAlt(const std::string& in);
	std::string getAlt();


	virtual std::string toString();
};