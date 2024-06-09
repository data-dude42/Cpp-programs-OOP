# *This project is based on Huffman Coding, a lossless, bottom-up compression algorithm. It can compress and decompress any text files.*

##### **Huffman Decompression Tool (decode.cpp)**

This program decompresses files using Huffman coding, a lossless compression technique that assigns shorter codes to more frequent characters.

**Requirements**

* A C++ compiler that supports C++11 features (for the `std::string` class and exception handling)
* The `huffman.hpp` header file, which should define the `huffman` class and its functionalities for decompression

**Building**

Compile the source code (`decompress.cpp`) along with the `huffman.hpp` header file using your preferred C++ compiler. Here's an example command using GCC:

Bash

```
g++ decompress.cpp -o decompress -Ipath/to/huffman.hpp
```

Replace `path/to/huffman.hpp` with the actual location of your `huffman.hpp` header file.

**Usage**

Run the compiled program (`decompress`) with the following command syntax:

Bash

```
./decompress <input_file> <output_file>
```

* `<input_file>`: The path to the compressed file you want to decompress.
* `<output_file>`: The path where you want to save the decompressed file.

**Example**

Bash

```
./decompress compressed_data.huf decompressed_data.txt
```

This will decompress the file `compressed_data.huf` and save the decompressed data to `decompressed_data.txt`.

**Error Handling**

The program checks for the following errors:

* Incorrect number of command-line arguments: It expects exactly two arguments (input and output file paths).
* Decompression errors: If an error occurs during decompression (e.g., invalid compressed file format), an error message with details will be printed to the standard error stream (`cerr`).

**Assumptions**

* This README assumes the `huffman.hpp` header file defines the `huffman` class with a constructor that takes the input and output file paths, and a `decompress()` method for performing decompression.
* The compressed file format is compatible with the implementation in `huffman.hpp`.

**Additional Notes**

* This is a basic example of a Huffman decompression tool. Advanced features like handling different compressed file formats or progress reporting might be added depending on your specific requirements.
* For more information about Huffman coding, refer to online resources or textbooks on data compression.


## Huffman Compression Tool (encode.cpp)

This program compresses files using Huffman coding, a lossless compression technique that assigns shorter codes to more frequent characters.

**Requirements**

* A C++ compiler that supports C++11 features (for `std::string` class)
* The `huffman.hpp` header file, which should define the `huffman` class and its functionalities for compression

**Building**

Compile the source code (`compress.cpp`) along with the `huffman.hpp` header file using your preferred C++ compiler. Here's an example command using GCC:

Bash

```
g++ compress.cpp -o compress -Ipath/to/huffman.hpp
```

Replace `path/to/huffman.hpp` with the actual location of your `huffman.hpp` header file.

**Usage**

Run the compiled program (`compress`) with the following command syntax:

Bash

```
./compress <input_file> <output_file>
```

* `<input_file>`: The path to the file you want to compress.
* `<output_file>`: The path where you want to save the compressed file.

**Example**

Bash

```
./compress original_data.txt compressed_data.huf
```

This will compress the file `original_data.txt` and save the compressed data to `compressed_data.huf`.

**Error Handling**

The program currently doesn't include specific error handling for invalid arguments or potential compression issues. Consider adding checks in the future for:

* Incorrect number of command-line arguments
* File opening errors
* Memory allocation issues

**Assumptions**

* This README assumes the `huffman.hpp` header file defines the `huffman` class with a constructor that takes the input and output file paths, and a `compress()` method for performing compression.
* The program assumes successful compression based on the `compress()` method call. Error handling in the `huffman.hpp` implementation might be necessary.

**Additional Notes**

* This is a basic example of a Huffman compression tool. Advanced features like progress reporting or handling different input file types might be added depending on your specific needs.
* For more information about Huffman coding, refer to online resources or textbooks on data compression.
