#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main()
#include "catch.hpp"
#include "notebook.hpp"

TEST_CASE( "NoteBook keeps track of notes", "[NoteBook]" ) {

	Note *n;
	NoteBook nb;

	SECTION( "velocity priority" ) {
		nb.setMode(velocity);
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

	SECTION( "highest note priority" ) {
		nb.setMode(highest);
		n = nb.noteOn(5, 1);
		REQUIRE( n != 0 );
		REQUIRE( n->pitch == 5 );
		n = nb.noteOn(6, 1);
		REQUIRE( n->pitch == 6 );
		n = nb.noteOff(6);
		REQUIRE( n->pitch == 5 );
		n = nb.noteOn(7, 1);
		REQUIRE( n->pitch == 7 );
		n = nb.noteOff(6);
		REQUIRE( n->pitch == 7 );
	}

	SECTION( "lowest note priority" ) {
		nb.setMode(lowest);
		n = nb.noteOn(100, 1);
		n = nb.noteOn(99, 1);
		REQUIRE( n->pitch == 99 );
		n = nb.noteOn(101, 1);
		REQUIRE( n->pitch == 99 );
		n = nb.noteOff(100);
		n = nb.noteOff(101);
		REQUIRE( n->pitch == 99 );
		n = nb.noteOff(99);
		REQUIRE( n == 0 );
	}

	SECTION( "noteOff kills every copy of a note" ) {
		nb.noteOn(64, 1);
		nb.noteOn(64, 1);
		nb.noteOn(64, 1);
		n = nb.noteOff(64);
		REQUIRE( n == 0 );
	}

	SECTION( "allNotesOff" ) {
		nb.noteOn(1, 100);
		nb.noteOn(2, 100);
		nb.noteOn(3, 100);
		REQUIRE( nb.allNotesOff() == 3 );
	}
	
}
