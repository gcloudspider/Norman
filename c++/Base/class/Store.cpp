#include <iostream>
#include <stdio.h>
using namespace std;

struct Rice {
	int id;
	string name;
	int total;
	int income;
};
enum class Mode {
	in,
	out,
	app
};

struct File {
public:
	bool open(const string& name, Mode m)
	{
		const char* s = NULL; 
		switch (m) {
		case Mode::in:
			s = "r";
			break;
		case Mode::out:
			s = "w";
			break;
		case Mode::app:
			s = "a";
			break;
		}
		fp = fopen(name.c_str(), s);
		if (fp == NULL) {
			return false;
		} else {
			return true;
		}
	}
	void close()
	{
		if (fp != NULL) {
			fclose(fp);
			fp = NULL;
		}
	}
	bool read(Rice* r)
	{
		char name[20];
		int t = fscanf(fp, "%d%s%d%d", &r->id, name, &r->total, &r->income);
		r->name = name;

		if (t == EOF) {
			return false;
		} else {
			return true;
		}
	}
	bool write(const Rice& r)
	{
		int t = fprintf(fp, "%d %s %d %d\n", r.id, r.name.c_str(), r.total, r.income);
		if (t == EOF) {
			return false;
		} else {
			return true;
		}
	}
private:
	FILE* fp;
};

struct Store {
public:
	void init(const string& loadFile)
	{
		count = 0;
		Rice r;
		File f;
		if (!f.open(loadFile, Mode::in)) {
			return ;
		}

		while (f.read(&r)) {
			t[count] = r;
			count++;
		}
	}
	void save(const string& saveFile)
	{
		File f;
		f.open(saveFile, Mode::out);
		for (int i=0; i<count; ++i) {
			f.write(t[i]);
		}
	}
	void buy(string name, int total, int price)
	{
		int j = count;
		for (int i=0; i<count; i++) {
			if (t[i].name == name) {
				j = i;
				break;
			}
		}
		if (j < count) {
			t[j].total += total;
			t[j].income -= total * price;
		} else {
			t[count].id = count;
			t[count].name = name;
			t[count].total += total;
			t[count].income -= total * price;
			count++;
		}
		
	}
	void sell(string name, int total, int price)
	{
		int j = count;
		for (int i=0; i<count; i++) {
			if (t[i].name == name) {
				j = i;
				break;
			}
		}

		if (j < count) {
			int r = t[j].total>total? total : t[j].total;
			t[j].total -= r;
			t[j].income += r * price;
		}
	}

	void show()
	{
		for (int i=0; i<count; i++) {
			cout << t[i].name << " " << t[i].income << endl;
		}
	}

private:
	Rice t[10];
	int count;
};


int main()
{
	Store s;
	s.init("store.txt");

	s.buy("HeiMi", 100, 2);
	s.buy("Dolu", 200, 2);
	s.buy("XiXi", 300, 3);

	s.sell("HeiMi", 50, 3);
	s.sell("gggg", 10, 2);
	s.sell("XiXi", 250, 4);

	s.show();
	s.save("store.txt");
}