#pragma comment(lib,"cryptlib.lib")

#include <iostream>
#include<fstream>
#include<sstream>
#include <Cryptopp/files.h>
#include <Cryptopp/modes.h>
#include <Cryptopp/osrng.h>
#include <cryptopp/rsa.h>
#include <Cryptopp/sha.h>
#include <Cryptopp/hex.h>

using namespace std;
using namespace CryptoPP;


string hexToASCII(string );
string int_to_hex(Integer );

int main() {

	std::string msg = "109550025";
	std::string digest;
	Integer nonce = 0x00000000;
	SHA256 hash;
	fstream fout("out.txt");


	StringSource (msg, true, new HashFilter(hash, new HexEncoder( new StringSink(digest))));
	
    string hexnonce= int_to_hex(nonce);

    string ascnonce=hexToASCII(hexnonce);
    string ascdig=hexToASCII(digest);
	
    msg =ascnonce+ascdig;

    int i=0;

	while(i<11) {

		cout << i << endl;
		cout << digest << endl;

		fout << i << endl;
		fout << digest << endl;
		string digest1 = digest;
		digest = "";

		while (1) {

			StringSource (msg, true, new HashFilter(hash, new HexEncoder(new StringSink(digest))));
			
			int zero=0;

			for (int k = 0; k < 8; k++) {
				if (digest[k] == '0') {
					zero++;
				}
				else break;
			}


            bool flag=(zero==i);


			if (flag) {
				cout << int_to_hex(nonce)<<endl;
				cout << digest << endl;

				fout << int_to_hex(nonce) << endl;
				fout << digest << endl;

                string hexnonce= int_to_hex(nonce);

                string ascnonce=hexToASCII(hexnonce);
                string ascdig=hexToASCII(digest);

                msg =ascnonce+ascdig;

				nonce = 0x00000000;
				break;

			}
			else {
				zero = 0;


                string hexnonce= int_to_hex(++nonce);

                string ascnonce=hexToASCII(hexnonce);
                string ascdig1=hexToASCII(digest1);

                msg =ascnonce+ascdig1;
				digest = "";
			}

		}


        i++;
	}

    fout.close();
	return 0;
}


string hexToASCII(string hex)
{
	string ascii = "";
	for (size_t i = 0; i < hex.length(); i += 2)
	{
		string part = hex.substr(i, 2);
		char ch =stoul(part, nullptr, 16);
		
		ascii += ch;
	}
	return ascii;
}


string int_to_hex(Integer i) {
	string result;
	stringstream ss;
	ss << hex << i;
	result = ss.str();
	result.pop_back();
	const string zero = "0";
	for (int j= result.size();j<8; j++) {
		result.insert(0, zero);
	}

	return result;

}
