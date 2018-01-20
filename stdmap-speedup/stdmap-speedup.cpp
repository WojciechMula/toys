/*
	Author: Wojciech Muła
	e-mail: wojciech_mula@poczta.onet.pl
	www:    http://wm.ite.pl/

	License: public domain

	initial release 3-04-2010
*/
#include <iostream>
#include <vector>
#include <map>

#include <sys/time.h>

unsigned gettime() {
	struct timeval tv;
	gettimeofday(&tv, NULL);

	return (tv.tv_sec * 1000000 + tv.tv_usec)/1000;
}
//---------------------------------------------------------------------------

template <class TValue>
class size_char_map_t {
	private:
		typedef std::map<std::string, TValue>	map_t;
		typedef std::vector<map_t>		vector_map_t;
		typedef std::vector<vector_map_t>	vector_t;

		vector_t	table;
	public:
		size_char_map_t(size_t max_length);

		int count(const std::string& key) const;
		size_t size() const;
		void insert(const std::string& key, TValue val);
};

template <class TValue>
size_char_map_t<TValue>::size_char_map_t(size_t max_length) {
	for (size_t k=0; k < max_length; k++) {
		vector_map_t subtable;
		map_t map;
		for (int i=0; i < 256; i++)
			subtable.push_back(map);

		table.push_back(subtable);
	}
}
//---------------------------------------------------------------------------

template <class TValue>
int size_char_map_t<TValue>::count(const std::string& key) const {
	const vector_map_t& subtable = table[key.size()];
	const unsigned idx = (unsigned char)(key[0]);
	const map_t& map = subtable[idx];
	return map.count(key);
}
//---------------------------------------------------------------------------

template <class TValue>
size_t size_char_map_t<TValue>::size() const {
	unsigned i, j, n;
	size_t k = 0;

	n = table.size();
	for (i=0; i < n; i++) {
		const vector_map_t& subtable = table[i];
//		std::cout << "length=" << i << std::endl;
		for (j=0; j < 256; j++) {
//			std::cout << '\t' << "count[" << j << "]=" << subtable[j].size() << std::endl;
			k += subtable[j].size();
		}
	}

	return k;
}
//---------------------------------------------------------------------------

template <class TValue>
void size_char_map_t<TValue>::insert(const std::string& key, TValue val) {
	vector_map_t& subtable = table[key.size()];
	const unsigned idx = (unsigned char)(key[0]);
	subtable[idx][key] = val;
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

template <class TValue>
class size_map_t {
	private:
		typedef std::map<std::string, TValue>	map_t;
		typedef std::vector<map_t>		vector_t;

		vector_t	table;
	public:
		size_map_t(size_t max_length);

		int count(const std::string& key) const;
		size_t size() const;
		void insert(const std::string& key, TValue val);
};

template <class TValue>
size_map_t<TValue>::size_map_t(size_t max_length) {
	for (size_t k=0; k < max_length; k++) {
		map_t map;
		table.push_back(map);
	}
}
//---------------------------------------------------------------------------

template <class TValue>
int size_map_t<TValue>::count(const std::string& key) const {
	const map_t& map = table[key.size()];
	return map.count(key);
}
//---------------------------------------------------------------------------

template <class TValue>
size_t size_map_t<TValue>::size() const {
	unsigned i, j, n;
	size_t k = 0;

	n = table.size();
	for (i=0; i < n; i++) {
//		std::cout << "length=" << i << " count=" << table[i].size() << std::endl;
		k += table[i].size();
	}

	return k;
}
//---------------------------------------------------------------------------

template <class TValue>
void size_map_t<TValue>::insert(const std::string& key, TValue val) {
	table[key.size()][key] = val;
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

template <class TValue>
class char_map_t {
	private:
		typedef std::map<std::string, TValue>	map_t;
		typedef std::vector<map_t>		vector_t;

		vector_t	table;
	public:
		char_map_t();

		int count(const std::string& key) const;
		size_t size() const;
		void insert(const std::string& key, TValue val);
};

template <class TValue>
char_map_t<TValue>::char_map_t() {
	map_t map;
	for (int i=0; i < 256; i++)
		table.push_back(map);
}
//---------------------------------------------------------------------------

template <class TValue>
int char_map_t<TValue>::count(const std::string& key) const {
	const unsigned idx = (unsigned char)(key[0]);
	const map_t& map = table[idx];
	return map.count(key);
}
//---------------------------------------------------------------------------

template <class TValue>
size_t char_map_t<TValue>::size() const {
	unsigned i, j, n;
	size_t k = 0;

	for (j=0; j < 256; j++) {
//		std::cout << '\t' << "count[" << j << "]=" << table[j].size() << std::endl;
		k += table[j].size();
	}

	return k;
}
//---------------------------------------------------------------------------

template <class TValue>
void char_map_t<TValue>::insert(const std::string& key, TValue val) {
	const unsigned idx = (unsigned char)(key[0]);
	map_t& map = table[idx];
	map[key] = val;
}
//---------------------------------------------------------------------------


int main(int argc, char* argv[]) {
	using namespace std;

	size_char_map_t<int>	map1(1024);
	size_map_t<int>		map2(1024);
	char_map_t<int>		map3;
	map<string, int>	map4;

	vector<string>		words;
	string s;
	unsigned t1, t2;

	//--------------------------------------------------
	t1 = gettime();
	cout << "loading words..." << endl;
	while (not cin.eof()) {
		cin >> s;
		if (not s.empty())
			words.push_back(s);
	}
	t2 = gettime();
	cout << t2 - t1 << " ms" << " words=" << words.size() << endl;

	//--------------------------------------------------
	t1 = gettime();
	cout << "inserting into maps grouped by size & first char" << endl;
	unsigned i, n = words.size();
	for (i=0; i < n; i++) {
		//cout << '#' << i << " '" << words[i] << '\'' << endl;
		map1.insert(words[i], i);
	}
	t2 = gettime();
	cout << t2 - t1 << " ms" << endl;

	//--------------------------------------------------
	t1 = gettime();
	cout << "inserting into maps grouped by size" << endl;
	for (i=0; i < n; i++)
		//cout << '#' << i << " '" << words[i] << '\'' << endl;
		map2.insert(words[i], i);

	t2 = gettime();
	cout << t2 - t1 << " ms" << endl;

	//--------------------------------------------------
	t1 = gettime();
	cout << "inserting into maps grouped by first char" << endl;
	for (i=0; i < n; i++)
		//cout << '#' << i << " '" << words[i] << '\'' << endl;
		map3.insert(words[i], i);

	t2 = gettime();
	cout << t2 - t1 << " ms" << endl;

	//--------------------------------------------------
	t1 = gettime();
	cout << "inserting into std::map" << endl;
	for (i=0; i < n; i++)
		map4[words[i]] = i;

	t2 = gettime();
	cout << t2 - t1 << " ms" << endl;

	//--------------------------------------------------
	cout << endl;
	cout <<  "size1=" << map1.size() <<
		" size2=" << map2.size() <<
		" size3=" << map3.size() <<
		" size4=" << map4.size() << endl;

	//--------------------------------------------------
	t1 = gettime();
	cout << "reading from maps grouped by size & first char" << endl;
	for (i=0; i < n; i++)
		if (map1.count(words[i]) == 0) {
			cerr << "error1 at #" << i;
			return 1;
		}
	t2 = gettime();
	cout << t2 - t1 << " ms" << endl;

	//--------------------------------------------------
	t1 = gettime();
	cout << "reading from maps grouped by size" << endl;
	for (i=0; i < n; i++)
		if (map2.count(words[i]) == 0) {
			cerr << "error2 at #" << i;
			return 1;
		}
	t2 = gettime();
	cout << t2 - t1 << " ms" << endl;
	
	//--------------------------------------------------
	t1 = gettime();
	cout << "reading from maps grouped by first char" << endl;
	for (i=0; i < n; i++)
		if (map3.count(words[i]) == 0) {
			cerr << "error3 at #" << i;
			return 1;
		}
	t2 = gettime();
	cout << t2 - t1 << " ms" << endl;


	//--------------------------------------------------
	t1 = gettime();
	cout << "reading from std::map" << endl;
	for (i=0; i < n; i++)
		if (map4.count(words[i]) == 0) {
			cerr << "error4 at #" << i;
			return 1;
		}
	t2 = gettime();
	cout << t2 - t1 << " ms" << endl;

	return 0;
}
