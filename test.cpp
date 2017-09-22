#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "notebook.hpp"

TEST_CASE( "NoteBook keeps track of notes", "[NoteBook]" ) {

	NoteBook nbH(highest);

	Note *n = nbH.noteOn(100, 100);
	REQUIRE( n != 0 );
	REQUIRE( n->pitch == 100 );
	Note *n2 = nbH.noteOff(100);
	REQUIRE( n2 == 0 );
}
