#include <iostream>
#include <bits/stdc++.h> //Alle benötigten Includes

using namespace std;

///
/// \brief decode
/// \param str [1a2b3c]
/// \return encodet string [abbccc]
///
string decode(string str) {
	vector<int> intVec = {};

	if (str.empty() or str == "") {
		return "";
	}
	//--------------------------------------------------

}

int main() {
	//decode("");
	decode("1a");
	decode("2b");
	decode("1b3c");
	return 0;
}
