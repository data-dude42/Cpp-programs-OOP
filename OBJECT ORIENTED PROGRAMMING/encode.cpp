#include <iostream> //<iostream> for input/output operations (e.g., cout)
#include "huffman.hpp"//huffman.hpp containing the Huffman coding implementation details 
using namespace std;

int main(int argc, char* argv[]) { //Validates the presence of exactly two command-line arguments using argc.
    if (argc != 3) { 
        cout << "Failed to detect Files";
		exit(1);
	}
    
    huffman f(argv[1], argv[2]);
    f.compress();
    cout << "Compressed successfully" << endl; // Calls the compress() method on the huffman object to initiate compression
    
    return 0; // Returns 0 to indicate successful execution.
}