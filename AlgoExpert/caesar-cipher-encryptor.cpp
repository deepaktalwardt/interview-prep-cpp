using namespace std;

string caesarCypherEncryptor(string str, int key) {
  // Write your code here.
  string str2;
	for (int i = 0; i < str.size(); i++) {
		char c = str[i];
		if (c + key > 'z') {
      int diff = c + key - 'z' - 1;
			c = 'a' + diff % 26;
		} else {
			c += key;
		}
		str2.push_back(c);
	}
	return str2;
}