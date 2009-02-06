#ifndef ScriptEvaluator_h
#define ScriptEvaluator_h

namespace WebCore {
	class ScriptSourceCode;

	class ScriptEvaluator {
	public:
		virtual bool matchesMimeType(const String& mimeType) = 0;
		virtual void evaluate(const String& mimeType, const ScriptSourceCode& sourceCode) = 0;
	};
}

#endif