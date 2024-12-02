#include <emp-tool/emp-tool.h>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include "test/single_execution.h"
#include "test/plaintext_sha256.h"
#include <time.h>
using namespace std;
using namespace emp;

int main(int argc, char** argv) {
	int party, port;
	parse_party_and_port(argv, &party, &port);
	NetIO* io = new NetIO(party==ALICE ? nullptr:IP, port);
//	io->set_nodelay();
	string a = "0000000000000000000000000000000000000000000000000000000000000000";
	string b = "0000000000000000000000000000000000000000000000000000000000000000";

	string a_mask = "0000000000000000000000000000000000000000000000000000000000000000";
	string b_mask = "0000000000000000000000000000000000000000000000000000000000000000";

	if (party == ALICE) {
		a = "570F73DE8329FEE1A228090EB74C03B835C2EAE8B1F8EBF99AC8586CEB63DC35";
        a = hex_string_reverse_bits(a);
		a_mask = hex_string_reverse_bits(generate_random_hex_string(64));
	} else {
		b = "4AD4D960FA7DBA81965BE89A50BFC40EFA9B5CB3AC91B8C5CBB126C4F25E39F1";
        b = hex_string_reverse_bits(b);
		b_mask = hex_string_reverse_bits(generate_random_hex_string(64));
	}

    string res = ag2pc_exec(party, io, circuit_file_location+"ECtF/add_2_xor.txt",
        b + b_mask + a + a_mask
    );

    res = hex_string_reverse_bits(res);

	cout << party << " gets 0x" << res << endl;

	string out = (party == ALICE) ? a_mask : xorHexStrings(res, b_mask);

    out = hex_string_reverse_bits(out);

	cout << party << " gets 0x" << out << endl;

	delete io;
	return 0;
}