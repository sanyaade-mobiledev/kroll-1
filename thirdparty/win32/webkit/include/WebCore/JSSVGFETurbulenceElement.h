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

#ifndef JSSVGFETurbulenceElement_h
#define JSSVGFETurbulenceElement_h


#if ENABLE(SVG) && ENABLE(SVG_FILTERS)

#include "JSSVGElement.h"

namespace WebCore {

class SVGFETurbulenceElement;

class JSSVGFETurbulenceElement : public JSSVGElement {
    typedef JSSVGElement Base;
public:
    JSSVGFETurbulenceElement(PassRefPtr<JSC::Structure>, PassRefPtr<SVGFETurbulenceElement>);
    static JSC::JSObject* createPrototype(JSC::ExecState*);
    virtual bool getOwnPropertySlot(JSC::ExecState*, const JSC::Identifier& propertyName, JSC::PropertySlot&);
    virtual const JSC::ClassInfo* classInfo() const { return &s_info; }
    static const JSC::ClassInfo s_info;

    static PassRefPtr<JSC::Structure> createStructure(JSC::JSValue* prototype)
    {
        return JSC::Structure::create(prototype, JSC::TypeInfo(JSC::ObjectType));
    }

    static JSC::JSValue* getConstructor(JSC::ExecState*);
};


class JSSVGFETurbulenceElementPrototype : public JSC::JSObject {
public:
    static JSC::JSObject* self(JSC::ExecState*);
    virtual const JSC::ClassInfo* classInfo() const { return &s_info; }
    static const JSC::ClassInfo s_info;
    virtual bool getOwnPropertySlot(JSC::ExecState*, const JSC::Identifier&, JSC::PropertySlot&);
    static PassRefPtr<JSC::Structure> createStructure(JSC::JSValue* prototype)
    {
        return JSC::Structure::create(prototype, JSC::TypeInfo(JSC::ObjectType));
    }
    JSSVGFETurbulenceElementPrototype(PassRefPtr<JSC::Structure> structure) : JSC::JSObject(structure) { }
};

// Functions

JSC::JSValue* jsSVGFETurbulenceElementPrototypeFunctionGetPresentationAttribute(JSC::ExecState*, JSC::JSObject*, JSC::JSValue*, const JSC::ArgList&);
// Attributes

JSC::JSValue* jsSVGFETurbulenceElementBaseFrequencyX(JSC::ExecState*, const JSC::Identifier&, const JSC::PropertySlot&);
JSC::JSValue* jsSVGFETurbulenceElementBaseFrequencyY(JSC::ExecState*, const JSC::Identifier&, const JSC::PropertySlot&);
JSC::JSValue* jsSVGFETurbulenceElementNumOctaves(JSC::ExecState*, const JSC::Identifier&, const JSC::PropertySlot&);
JSC::JSValue* jsSVGFETurbulenceElementSeed(JSC::ExecState*, const JSC::Identifier&, const JSC::PropertySlot&);
JSC::JSValue* jsSVGFETurbulenceElementStitchTiles(JSC::ExecState*, const JSC::Identifier&, const JSC::PropertySlot&);
JSC::JSValue* jsSVGFETurbulenceElementType(JSC::ExecState*, const JSC::Identifier&, const JSC::PropertySlot&);
JSC::JSValue* jsSVGFETurbulenceElementX(JSC::ExecState*, const JSC::Identifier&, const JSC::PropertySlot&);
JSC::JSValue* jsSVGFETurbulenceElementY(JSC::ExecState*, const JSC::Identifier&, const JSC::PropertySlot&);
JSC::JSValue* jsSVGFETurbulenceElementWidth(JSC::ExecState*, const JSC::Identifier&, const JSC::PropertySlot&);
JSC::JSValue* jsSVGFETurbulenceElementHeight(JSC::ExecState*, const JSC::Identifier&, const JSC::PropertySlot&);
JSC::JSValue* jsSVGFETurbulenceElementResult(JSC::ExecState*, const JSC::Identifier&, const JSC::PropertySlot&);
JSC::JSValue* jsSVGFETurbulenceElementClassName(JSC::ExecState*, const JSC::Identifier&, const JSC::PropertySlot&);
JSC::JSValue* jsSVGFETurbulenceElementStyle(JSC::ExecState*, const JSC::Identifier&, const JSC::PropertySlot&);
JSC::JSValue* jsSVGFETurbulenceElementConstructor(JSC::ExecState*, const JSC::Identifier&, const JSC::PropertySlot&);
// Constants

JSC::JSValue* jsSVGFETurbulenceElementSVG_TURBULENCE_TYPE_UNKNOWN(JSC::ExecState*, const JSC::Identifier&, const JSC::PropertySlot&);
JSC::JSValue* jsSVGFETurbulenceElementSVG_TURBULENCE_TYPE_FRACTALNOISE(JSC::ExecState*, const JSC::Identifier&, const JSC::PropertySlot&);
JSC::JSValue* jsSVGFETurbulenceElementSVG_TURBULENCE_TYPE_TURBULENCE(JSC::ExecState*, const JSC::Identifier&, const JSC::PropertySlot&);
JSC::JSValue* jsSVGFETurbulenceElementSVG_STITCHTYPE_UNKNOWN(JSC::ExecState*, const JSC::Identifier&, const JSC::PropertySlot&);
JSC::JSValue* jsSVGFETurbulenceElementSVG_STITCHTYPE_STITCH(JSC::ExecState*, const JSC::Identifier&, const JSC::PropertySlot&);
JSC::JSValue* jsSVGFETurbulenceElementSVG_STITCHTYPE_NOSTITCH(JSC::ExecState*, const JSC::Identifier&, const JSC::PropertySlot&);

} // namespace WebCore

#endif // ENABLE(SVG) && ENABLE(SVG_FILTERS)

#endif
