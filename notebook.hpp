enum nbMode { highest, lowest, velocity };

class Note {
	public:
		Note(char _pitch, char _velocity);
		char pitch;
		char velocity;
};

Note::Note(char note, char velocity) {
}

class NoteBook {
	public:
		NoteBook();
		void noteOn(char _pitch, char _velocity);
		nbMode mode;
		
};

NoteBook::NoteBook() {
	this->mode = velocity;
}
