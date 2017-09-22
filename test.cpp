#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "notebook.hpp"

TEST_CASE( "NoteBook keeps track of notes", "[NoteBook]" ) {

	Note *n;

	NoteBook nbV;
	n = nbV.noteOn(100, 100);
	REQUIRE( n->velocity == 100 );
	n = nbV.noteOn(100, 101);
	REQUIRE( n->velocity == 101 );

	NoteBook nbH(highest);

	n = nbH.noteOn(100, 100);
	REQUIRE( n != 0 );
	REQUIRE( n->pitch == 100 );
	Note *n2 = nbH.noteOff(100);
	REQUIRE( n2 == 0 );
}
