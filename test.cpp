#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "notebook.hpp"

NoteBook nb;

TEST_CASE( "NoteBook keeps track of notes", "[NoteBook]" ) {
	REQUIRE( nb.mode == highest );
}
