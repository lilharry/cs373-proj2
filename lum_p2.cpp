#include <iostream>
#include <string>

using namespace std;

int main(int argc, char * argv[]){
	if (argc != 3){
		cout << "args should be gatedirections and input string" << endl;
        exit(1);
	}

	string gates = argv[1];
	string input = argv[2];
	cout << gates;
	for (long unsigned int i = 0; i < input.length(); i++ ){
		char c = input[i];
		string new_gates = "XXXX";
		int gate;
		char exit;
		if (c == '0'){
			if (gates[0] == 'L'){
				new_gates[0] = 'R';
				gate = 2;
			}
			else if (gates[0] == 'R'){
				new_gates[0] = 'C';
				gate = 4;
			}
			else{
				new_gates[0] = 'L';
				gate = 3;
			}
			
		}else{
			if (gates[0] == 'L'){
				new_gates[0] = 'C';
				gate = 2;
			}
			else if (gates[0] == 'C'){
				new_gates[0] = 'R';
				gate = 3;
			}
			else{
				new_gates[0] = 'L';
				gate = 4;
			}
		}

		if (gate == 2){

			if (gates[1] == 'L'){
				new_gates[1] = 'R';
				exit = 'B';
			}else{
				new_gates[1] = 'L';
				exit = 'C';
			}
			new_gates[2] = gates[2];
			new_gates[3] = gates[3];

		}else if (gate == 3){

			if (gates[2] == 'L'){
				new_gates[2] = 'R';
				exit = 'C';
			}else{
				new_gates[2] = 'L';
				exit = 'D';
			}			
			new_gates[1] = gates[1];
			new_gates[3] = gates[3];

		}else if (gate == 4){

			if (gates[3] == 'L'){
				new_gates[3] = 'R';
				exit = 'D';
			}else{
				new_gates[3] = 'L';
				exit = 'E';
			}			
			new_gates[1] = gates[1];
			new_gates[2] = gates[2];
			
		}

		gates = new_gates;

		cout << "->" << new_gates;

		if (i == input.length() - 1){
			cout << " " << exit << endl;
		}


	}

}
