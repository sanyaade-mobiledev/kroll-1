/**
 * Appcelerator Kroll - licensed under the Apache Public License 2
 * see LICENSE in the root folder for details on the license.
 * Copyright (c) 2008 Appcelerator, Inc. All Rights Reserved.
 */
#ifndef RUBY_TYPES_H_
#define RUBY_TYPES_H_

#include <typeinfo>
#include "ruby_module.h"

namespace kroll
{
	class RubyUtils
	{
	public:
		static void InitializeDefaultBindings(Host *host);
		
		static const char* TypeToString (int type);
		static VALUE Create(BoundObject* value);
		static VALUE Create(BoundList* list);
		static std::string ToString(VALUE value);
		static bool ToBool(VALUE value);
		static int ToInt(VALUE value);
		static double ToDouble(VALUE value);
		static Value* ToValue(VALUE value);
		static VALUE ToValue(Value* value);
		static std::string ToUpper (std::string s);

	private:
		RubyUtils(){}
		~RubyUtils(){} 
	};
}

#endif
