/*
    This file is part of the WebKit open source project.
    This file has been generated by generate-bindings.pl. DO NOT MODIFY!

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public License
    along with this library; see the file COPYING.LIB.  If not, write to
    the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
    Boston, MA 02110-1301, USA.
*/

#ifndef JSHTMLOListElement_h
#define JSHTMLOListElement_h

#include "JSHTMLElement.h"

namespace WebCore {

class HTMLOListElement;

class JSHTMLOListElement : public JSHTMLElement {
    typedef JSHTMLElement Base;
public:
    JSHTMLOListElement(PassRefPtr<JSC::Structure>, PassRefPtr<HTMLOListElement>);
    static JSC::JSObject* createPrototype(JSC::ExecState*);
    virtual bool getOwnPropertySlot(JSC::ExecState*, const JSC::Identifier& propertyName, JSC::PropertySlot&);
    virtual void put(JSC::ExecState*, const JSC::Identifier& propertyName, JSC::JSValue*, JSC::PutPropertySlot&);
    virtual const JSC::ClassInfo* classInfo() const { return &s_info; }
    static const JSC::ClassInfo s_info;

    static PassRefPtr<JSC::Structure> createStructure(JSC::JSValue* prototype)
    {
        return JSC::Structure::create(prototype, JSC::TypeInfo(JSC::ObjectType));
    }

    static JSC::JSValue* getConstructor(JSC::ExecState*);
};


class JSHTMLOListElementPrototype : public JSC::JSObject {
public:
    static JSC::JSObject* self(JSC::ExecState*);
    virtual const JSC::ClassInfo* classInfo() const { return &s_info; }
    static const JSC::ClassInfo s_info;
    JSHTMLOListElementPrototype(PassRefPtr<JSC::Structure> structure) : JSC::JSObject(structure) { }
};

// Attributes

JSC::JSValue* jsHTMLOListElementCompact(JSC::ExecState*, const JSC::Identifier&, const JSC::PropertySlot&);
void setJSHTMLOListElementCompact(JSC::ExecState*, JSC::JSObject*, JSC::JSValue*);
JSC::JSValue* jsHTMLOListElementStart(JSC::ExecState*, const JSC::Identifier&, const JSC::PropertySlot&);
void setJSHTMLOListElementStart(JSC::ExecState*, JSC::JSObject*, JSC::JSValue*);
JSC::JSValue* jsHTMLOListElementType(JSC::ExecState*, const JSC::Identifier&, const JSC::PropertySlot&);
void setJSHTMLOListElementType(JSC::ExecState*, JSC::JSObject*, JSC::JSValue*);
JSC::JSValue* jsHTMLOListElementConstructor(JSC::ExecState*, const JSC::Identifier&, const JSC::PropertySlot&);

} // namespace WebCore

#endif
