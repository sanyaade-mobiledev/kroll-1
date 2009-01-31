/**
 * Appcelerator Kroll - licensed under the Apache Public License 2
 * see LICENSE in the root folder for details on the license.
 * Copyright (c) 2008 Appcelerator, Inc. All Rights Reserved.
 */
#include "host.h"
#include <iostream>
#include <cstring>
#include <windows.h>
#include <commctrl.h>
#include <ole2.h>

namespace kroll
{
	bool Win32Host::ole_initialized = false;

	/*static*/
	void Win32Host::InitOLE() {
		if (!ole_initialized) {
			OleInitialize(NULL);
			ole_initialized = true;
		}
	}

	Win32Host::Win32Host(HINSTANCE hInstance, int _argc, const char** _argv) : Host(_argc,_argv), instance_handle(hInstance)
	{
		char *p = getenv("KR_PLUGINS");
		if (p)
		{
			FileUtils::Tokenize(p, this->module_paths, ";");
		}

	}

	Win32Host::~Win32Host()
	{
		if (ole_initialized) {
			OleUninitialize();
		}
	}

	int Win32Host::Run()
	{
		std::cout << "Kroll Running (Win32)..." << std::endl;
		this->AddModuleProvider(this);
		this->LoadModules();

		thread_id = GetCurrentThreadId();
		MSG message;
		while (GetMessage(&message, NULL, 0, 0))
		{
			TranslateMessage(&message);
			DispatchMessage(&message);
		}

		return 0;
	}

	Module* Win32Host::CreateModule(std::string& path)
	{
		std::cout << "Win32Host::CreateModule " << path.c_str() << std::endl;

		HMODULE module = LoadLibraryA(path.c_str());

		if (!module)
		{
			fprintf(stderr, "Error loading module (%d): %s\n", GetLastError(), path.c_str());
			return 0;
		}

		// get the module factory
		ModuleCreator* create = (ModuleCreator*)GetProcAddress(module, "CreateModule");
		if (!create)
		{
			fprintf(stderr, "Couldn't find ModuleCreator entry point for %s\n", path.c_str());
			return 0;
		}

		std::cout << "Win32Host creating module ..." << std::endl;

		return create(this,FileUtils::GetDirectory(path));
	}

	SharedValue Win32Host::InvokeMethodOnMainThread(SharedBoundMethod method,
                                                  SharedPtr<ValueList> args)
	{
		//FIXME - implement for Win32 and Linux. Until then...we
		//will just forward on same thread
		std::cerr << "WARNING: Invoking method on non-main Thread!" << std::endl;
		//PostThreadMessage(thread_id)

		SharedValue result = method->Call(*args);
		return result;
	}
}

