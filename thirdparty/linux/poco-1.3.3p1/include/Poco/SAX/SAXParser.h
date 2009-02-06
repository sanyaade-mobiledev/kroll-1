//
// SAXParser.h
//
// $Id: //poco/1.3/XML/include/Poco/SAX/SAXParser.h#2 $
//
// Library: XML
// Package: SAX
// Module:  SAX
//
// Implementation of the XMLReader interface.
//
// Copyright (c) 2004-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// Permission is hereby granted, free of charge, to any person or organization
// obtaining a copy of the software and accompanying documentation covered by
// this license (the "Software") to use, reproduce, display, distribute,
// execute, and transmit the Software, and to prepare derivative works of the
// Software, and to permit third-parties to whom the Software is furnished to
// do so, all subject to the following:
// 
// The copyright notices in the Software and this entire statement, including
// the above license grant, this restriction and the following disclaimer,
// must be included in all copies of the Software, in whole or in part, and
// all derivative works of the Software, unless such copies or derivative
// works are solely in the form of machine-executable object code generated by
// a source language processor.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
// SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
// FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//


#ifndef SAX_SAXParser_INCLUDED
#define SAX_SAXParser_INCLUDED


#include "Poco/XML/XML.h"
#include "Poco/SAX/XMLReader.h"
#include "Poco/XML/ParserEngine.h"


namespace Poco {
namespace XML {


class XML_API SAXParser: public XMLReader
	/// This class provides a SAX2 (Simple API for XML) interface to expat, 
	/// the XML parser toolkit.
	/// The following SAX2 features and properties are supported:
	///   * http://xml.org/sax/features/external-general-entities
	///   * http://xml.org/sax/features/external-parameter-entities
	///   * http://xml.org/sax/features/namespaces
	///   * http://xml.org/sax/features/namespace-prefixes
	///   * http://xml.org/sax/properties/lexical-handler
	///   * http://xml.org/sax/properties/declaration-handler
{
public:
	SAXParser();
		/// Creates an SAXParser.

	SAXParser(const XMLString& encoding);
		/// Creates an SAXParser with the given encoding.
		
	~SAXParser();
		/// Destroys the SAXParser.
	
	void setEncoding(const XMLString& encoding);
		/// Sets the encoding used by the parser if no
		/// encoding is specified in the XML document.
		
	const XMLString& getEncoding() const;
		/// Returns the name of the encoding used by
		/// the parser if no encoding is specified in
		/// the XML document.

	void addEncoding(const XMLString& name, Poco::TextEncoding* pEncoding);
		/// Adds an encoding to the parser. Does not take ownership of the pointer!

	/// XMLReader
	void setEntityResolver(EntityResolver* pResolver);
	EntityResolver* getEntityResolver() const;
	void setDTDHandler(DTDHandler* pDTDHandler);
	DTDHandler* getDTDHandler() const;
	void setContentHandler(ContentHandler* pContentHandler);
	ContentHandler* getContentHandler() const;
	void setErrorHandler(ErrorHandler* pErrorHandler);
	ErrorHandler* getErrorHandler() const;
	void setFeature(const XMLString& featureId, bool state);
	bool getFeature(const XMLString& featureId) const;
	void setProperty(const XMLString& propertyId, const XMLString& value);
	void setProperty(const XMLString& propertyId, void* value);
	void* getProperty(const XMLString& propertyId) const;
	void parse(InputSource* pSource);
	void parse(const XMLString& systemId);
	void parseMemoryNP(const char* xml, std::size_t size);
	
	/// Extensions
	void parseString(const std::string& xml);

protected:
	void setupParse();

private:
	ParserEngine _engine;
	bool _namespaces;
	bool _namespacePrefixes;
};


} } // namespace Poco::XML


#endif // SAX_SAXParser_INCLUDED