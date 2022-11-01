// haxegitlib.cpp : Defines the entry point for the application.
//

#include "haxegitlib.h"

int main(int argc, char** argv)
{
	std::string path = argv[1] != nullptr ? argv[1] : "project.xml";
	path = std::filesystem::exists("project.xml") ? path : "Project.xml";
	if (!std::filesystem::exists(path)) {
		std::cerr << "ERROR: Could not find project.xml!\n"
			<< "Try to run this program in the same directory as one.\n"
			<< "You can also try running the program like this:\n $ "
			<< argv[0] << " /path/to/project\n";
		return 1;
	}
	std::cout << "Starting installation of haxelibs...\n\n";

	using namespace tinyxml2;
	XMLDocument* file = new tinyxml2::XMLDocument();
	if (file->LoadFile(path.c_str()) != tinyxml2::XML_SUCCESS) {
		std::cerr << "Error loading Project.xml: " << path << '\n';
		return 1;
	}
	XMLElement* project = file->FirstChildElement("project");
	XMLElement* haxelib = project->FirstChildElement("haxelib");
	while (haxelib != nullptr) {
		std::string name = haxelib->Attribute("name");

		const char* gitAttribute = haxelib->Attribute("git");
		std::string git = gitAttribute ? gitAttribute : "";

		std::string cmd("haxelib install " + name);
		if (git != "")
			cmd = "haxelib git " + name + " " + git;
		system(cmd.c_str());
		haxelib = haxelib->NextSiblingElement("haxelib");
	}
	return 0;
}
