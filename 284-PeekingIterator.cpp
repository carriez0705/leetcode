// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
    struct Data;
	Data* data;
public:
	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);
	virtual ~Iterator();
	// Returns the next element in the iteration.
	int next();
	// Returns true if the iteration has more elements.
	bool hasNext() const;
};


class PeekingIterator : public Iterator {
    int top;
    bool hasTop;
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    hasTop = false;
	    top = -1;
	}

    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
	    if(!hasTop){
	        hasTop = hasNext();
	        top = hasTop?Iterator::next():-1;
	    } 
	    return top;
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    peek();
	    hasTop = false;
	    return top;
	}

	bool hasNext() const {
	    if(!hasTop) return Iterator::hasNext();
	    return hasTop;
	}
};
