#pragma once

#ifdef ME_PLATFORM_WINDOWS

// this is a function defined in client
// which will return that application 
// and creating application is done in client
extern MyEngine::Application* MyEngine::CreateApplication();

int main(int argc, char** argv) {
	MyEngine::Log::Init();
	ME_CORE_WARN("Initialized Log!");
	int a = 5;
	ME_INFO("Hello Var = {0}", a);

	auto app = MyEngine::CreateApplication();
	app->Run();
	delete app;
}

#endif 