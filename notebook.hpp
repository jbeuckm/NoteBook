enum NB_Mode { highest, lowest, velocity };

class Note {
	public:
		Note(char pitch, char velocity);
		char pitch;
		char velocity;
};

Note::Note(char note, char velocity) {
}

class NoteBook {
	public:
		NoteBook(NB_Mode mode = velocity);
		void noteOn(char pitch, char velocity);
		NB_Mode mode;
	private:
		Note *head;
};

NoteBook::NoteBook(NB_Mode mode) {
	this->mode = mode;
}
