#include "Sovereign.h"


class Sandbox : public Sovereign::Application {

public:
	Sandbox() {

	}
	~Sandbox(){

	}

};

Sovereign::Application* Sovereign::CreateApplication() {
	return new Sandbox();
}
