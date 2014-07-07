#include <iostream>
#include <string>
#include <map>
#include <cmath>
#include <set>

using namespace std;

struct book_t {
	string origSubject;
	string reduTitle;
};

struct cmp_book {
	bool operator()(const book_t& lhs, const book_t& rhs) {
		return lhs.reduTitle < rhs.reduTitle;
	}
};

struct subject_t {
	set<book_t, cmp_book> books;
};

string normalize(const string& original) {
	string result;
	for (char c : original)
	{
		c |= 0x20;
		if (c >= 'a' && c <= 'z')
			result += c;
	}

	return result;
}

int main()
{
	int numEntries = 0;
	cin >> numEntries;
	cin.ignore();
	
	while (numEntries--)
	{
		map<string, subject_t> subjectsWithBooks;
		set<string> subjects;
		int N,M;
		cin >> N >> M;
		cout << (int) (ceil(N/double(M))) << endl;
		for (int i = 0; i < N; i++) {
			string name, subject;
			cin >> subject;
			cin.get();
			cin.get();
			cin.get();
			cin >> name;
			string normSubject = normalize(subject);
			string normName = normalize(name);
			//cout << "asdga " << subject << " " << normSubject << endl;
			book_t book = {subject, normName};
			subjectsWithBooks[normSubject].books.insert(book);
			subjects.insert(normSubject);
		}

		int counter = 0;
		int shelfN = 0;
		string begin = "";
		for (const string &subj : subjects)
		{
			for (const book_t &book : subjectsWithBooks[subj].books)
			{
				if (begin.size() == 0) {
					begin = book.origSubject;
				}
				if (++counter == M)
				{
					shelfN++;
					counter -= M;
					cout << "Shelf " << shelfN << ": " << begin << " - " << book.origSubject << endl;
					begin = "";
				}
			}
		}
		if (counter) {
			shelfN++;
			cout << "Shelf " << shelfN << ": " << begin << " - " << subjectsWithBooks[*subjects.rbegin()].books.rbegin()->origSubject << endl;
		}
	}
	return 0;
}
