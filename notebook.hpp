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
	Note *newNote = new Note(_pitch, _velocity);

	if (head == 0) {
		head = newNote;
		return head;
	}

	Note *previous, *current = head;
	switch (this->mode) {
		case highest:
			if (head->pitch < _pitch) {
				newNote->next = head;
				head = newNote;
				break;
			}
			do {
				previous = current;
				current = current->next;
			} while ((current != 0) && (_pitch < current->pitch));
			newNote->next = current;
			previous->next = newNote;
			break;
	}
	return head;
}

Note *NoteBook::noteOff(char _pitch) {
	Note *current = head;
	if (head == 0) {
		return head;
	}
	if (head->pitch == _pitch) {
		head = head->next;
		delete current;
		return head;
	}
	Note *previous;
	while ((current != 0) && (current->pitch != _pitch)) {
		previous = current;
		current = current->next;
	}
	if (current == 0) return head;
	previous->next = current->next;
	delete current;
	return head;
}
