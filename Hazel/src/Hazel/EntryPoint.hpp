#pragma once

#ifdef HZ_PLATFORM_WINDOWS

extern Hazel::Application* Hazel::CreateApplication();

int main(int argc, char** argv)
{
	Hazel::Console::Init();
	Hazel::Console::CoreWarn("Initialized Log!");
	int a = 5;
	Hazel::Console::Log("Hello! Var={0}", a);

	auto app = Hazel::CreateApplication();
	app->Run();
	delete app;

	Hazel::Console::End();
}

#endif