//
// Statement.h
//
// $Id: //poco/1.3/Data/include/Poco/Data/Statement.h#3 $
//
// Library: Data
// Package: DataCore
// Module:  Statement
//
// Definition of the Statement class.
//
// Copyright (c) 2006, Applied Informatics Software Engineering GmbH.
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


#ifndef Data_Statement_INCLUDED
#define Data_Statement_INCLUDED


#include "Poco/Data/Data.h"
#include "Poco/Data/StatementImpl.h"
#include "Poco/Data/Range.h"
#include "Poco/SharedPtr.h"


namespace Poco {
namespace Data {


class AbstractBinding;
class AbstractExtraction;
class Session;
class Limit;


class Data_API Statement
	/// A Statement is used to execute SQL statements. 
	/// It does not contain code of its own.
	/// Its main purpose is to forward calls to the concrete StatementImpl stored inside.
{
public:
	typedef void (*Manipulator)(Statement&);
	
	Statement(StatementImpl* pImpl);
		/// Creates the Statement.

	explicit Statement(Session& session);
		/// Creates the Statement for the given Session.
		///
		/// The following:
		///
		///     Statement stmt(sess);
		///     stmt << "SELECT * FROM Table", ...
		///
		/// is equivalent to:
		/// 
		///     Statement stmt(sess << "SELECT * FROM Table", ...);
		///
		/// but in some cases better readable.

	~Statement();
		/// Destroys the Statement.

	Statement(const Statement& stmt);
		/// Copy constructor

	Statement& operator = (const Statement& stmt);
		/// Assignment operator.

	void swap(Statement& other);
		/// Swaps the statement with another one.

	template <typename T> 
	Statement& operator << (const T& t)
		/// Concatenates the send data to a string version of the SQL statement.
	{
		_ptr->add(t);
		return *this;
	}

	Statement& operator , (Manipulator manip);
		/// Handles manipulators, such as now.

	Statement& operator , (AbstractBinding* info);
		/// Registers the Binding at the Statement

	Statement& operator , (AbstractExtraction* extract);
		/// Registers objects used for extracting data at the Statement.

	Statement& operator , (const Limit& extrLimit);
		/// Sets a limit on the maximum number of rows a select is allowed to return.
		///
		/// Set per default to Limit::LIMIT_UNLIMITED which disables the limit.

	Statement& operator , (const Range& extrRange);
		/// Sets a an etxraction Range on the maximum number of rows a select is allowed to return.
		///
		/// Set per default to Limit::LIMIT_UNLIMITED which disables the range.

	std::string toString() const;
		/// Creates a string from the accumulated SQL statement

	Poco::UInt32 execute();
		/// Executes the whole statement. Stops when either a limit is hit or the whole statement was executed.
		/// Returns the number of rows extracted from the Database.

	bool done();
		/// Returns if the statement was completely executed or if a previously set limit stopped it
		/// and there is more work to do. When no limit is set, it will always - after calling execute() - return true.

	Statement& reset(Session& session);
		/// Resets the Statement so that it can be filled with a new SQL command.

protected:
	const AbstractExtractionVec& extractions() const;
		/// Returns the extractions vector.

	const MetaColumn& metaColumn(std::size_t pos) const;
		/// Returns the type for the column at specified position.

	const MetaColumn& metaColumn(const std::string& name) const;
		/// Returns the type for the column with specified name.

private:
	typedef Poco::SharedPtr<StatementImpl> StatementImplPtr;

	bool _executed;
	StatementImplPtr _ptr;
};


//
// Manipulators
//
void Data_API now(Statement& statement);


//
// inlines
//
inline Statement& Statement::operator , (Manipulator manip)
{
	manip(*this);
	return *this;
}


inline Statement& Statement::operator , (AbstractBinding* info)
{
	_ptr->addBinding(info);
	return *this;
}


inline Statement& Statement::operator , (AbstractExtraction* extract)
{
	_ptr->addExtract(extract);
	return *this;
}


inline Statement& Statement::operator , (const Limit& extrLimit)
{
	_ptr->setExtractionLimit(extrLimit);
	return *this;
}


inline Statement& Statement::operator , (const Range& extrRange)
{
	_ptr->setExtractionLimit(extrRange.lower());
	_ptr->setExtractionLimit(extrRange.upper());
	return *this;
}


inline std::string Statement::toString() const
{
	return _ptr->toString();
}


inline const AbstractExtractionVec& Statement::extractions() const
{
	return _ptr->extractions();
}


inline const MetaColumn& Statement::metaColumn(std::size_t pos) const
{
	return _ptr->metaColumn(static_cast<UInt32>(pos));
}


inline const MetaColumn& Statement::metaColumn(const std::string& name) const
{
	return _ptr->metaColumn(name);
}


} } // namespace Poco::Data


#endif // Data_Statement_INCLUDED
