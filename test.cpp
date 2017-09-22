#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main()
#include "catch.hpp"
#include "notebook.hpp"

TEST_CASE( "NoteBook keeps track of notes", "[NoteBook]" ) {

	Note *n;
	NoteBook nb;

	SECTION( "velocity priority" ) {
		n = nb.noteOn(1, 100);
		REQUIRE( n->velocity == 100 );
		n = nb.noteOn(2, 101);
		REQUIRE( n->velocity == 101 );
		n = nb.noteOff(2);
		REQUIRE( n->velocity == 100 );
		n = nb.noteOn(3, 99);
		REQUIRE( n->velocity == 100 );
		n = nb.noteOff(1);
		REQUIRE( n->velocity == 99 );
		n = nb.noteOff(3);
		REQUIRE( n == 0 );
	}

	SECTION( "can set mode" ) {
		nb.setMode(velocity);
		nb.setMode(lowest);
		nb.setMode(highest);
	}

	SECTION( "highest note priority" ) {
		nb.setMode(highest);
		n = nb.noteOn(5, 1);
		REQUIRE( n != 0 );
		REQUIRE( n->pitch == 5 );
		n = nb.noteOn(6, 1);
		REQUIRE( n->pitch == 6 );
		n = nb.noteOff(6);
		REQUIRE( n->pitch == 5 );
	}
	
}
