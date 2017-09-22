enum NB_Mode { highest, lowest, velocity };

class Note {
	public:
		Note(char _pitch, char _velocity) : pitch(_pitch), velocity(_velocity) {
			this->next = 0;
		}
		char pitch;
		char velocity;
		Note *next;
};


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
