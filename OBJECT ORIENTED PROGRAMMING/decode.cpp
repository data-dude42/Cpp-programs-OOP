#include <iostream>
#include "huffman.hpp" // Assuming huffman.hpp defines Huffman coding functionality

using namespace std;

int main(int argc, char* argv[]) {
    // Validate presence of exactly two command-line arguments for input and output files
    if (argc != 3) {
        cerr << "Error: Expected two arguments (input and output file paths)." << endl;
        exit(1);
    }

    // Create a Huffman object to handle decompression
    try {
        huffman decompressor(argv[1], argv[2]); // Assuming constructor takes input and output paths

        // Decompress the file
        decompressor.decompress();
        cout << "Decompressed successfully to " << argv[2] << endl;
    } catch (const exception& e) {
        cerr << "Error during decompression: " << e.what() << endl;
        exit(1);
    }

    return 0;
}
