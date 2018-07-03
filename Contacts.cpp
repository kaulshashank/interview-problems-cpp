#include<iostream>
#include<string>

#define MAX_CHARS 26;

using namespace std; 

class Node {
	Node *children = new Node[MAX_CHARS];
	
	int getCharIndex(char c) {
		return(c - 'a');
	}

	Node getNode(char c) {
		return children[getCharIndex(c)];
	}

	void setNode(char c, Node node) {
		children[getCharIndex(c)] = node;
	}

	void add(string s) {
		add(s, 0);
	}

	void add(string s, Node node) {
		if (index == s.length())
			return;
		char current = s.at(index);
		int charCode = getCharIndex(current);
		Node child = getNode(current);
		if (child == null) {
			child = new Node();
			setNode(current, child);
		}
		child.add(s, index + 1);
	}
	
	int findCount(string s, int index) {
		if (index == s.length)
			return size;
		Node child = getNode(s.at(index));
		if (child == NULL) {
			return 0;
		}
		return child.findCount(s, index + 1);
	}
};

int main() {

	return 0;
}