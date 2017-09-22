enum NB_Mode { highest, lowest, velocity };

class Note {
	public:
		Note(char _pitch, char _velocity) : 
			pitch(_pitch), velocity(_velocity) {
			this->next = 0;
		}
		char pitch;
		char velocity;
		Note *next;
};

class NoteBook {
	public:
		NoteBook(NB_Mode _mode = velocity) : mode(_mode) { 
			head = 0;
		};
		Note *noteOn(char _pitch, char _velocity);
		Note *noteOff(char _pitch);
		NB_Mode mode;
	private:
		Note *head;
};

Note *NoteBook::noteOn(char _pitch, char _velocity) {
	return head;
}
Note *NoteBook::noteOff(char _pitch) {
	return head;
}
