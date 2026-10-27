#include <string>
#include <iostream>
#include <cstdio>
#include <cstdint>
#include <random>
#include <set>

using namespace std;
const int minimum = -1048576;
const int maximum = 1048576;

/***************************************************/
int main(int argc, char* argv[]) {

    // Convert the arguments to int
    unsigned int n = stoi(argv[1]);
    unsigned int P = stoi(argv[2]);

    if (n > 0 && P > 0) {

        int totalCount = n * P;

        // Creates a new array of numbers to be sorted
        int64_t* numbers = new int64_t[totalCount];

        char fileName[64];
        FILE *inputFile;

        // Randomization of the numbers
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int64_t> distr(minimum,maximum);

        set <int64_t> used; // Creates a set for the numbers

        for (int i = 0; i < totalCount; i++) {
            int64_t addnumber = distr(gen);
            if (!(used.count(addnumber))) {
                numbers[i] = addnumber;
                if (numbers[i] < minimum || numbers[i] > maximum) {
                    cerr << "Outside range: " << numbers[i] << '\n';
                }
                used.insert(addnumber);
            }
        }
        

        for (unsigned int r = 0; r < P; r++) {
            // Create the fileName
            snprintf(fileName, sizeof(fileName), "input%u.bin", r);

            // Open the file and write the numbers
            inputFile = fopen(fileName,"wb");
            fwrite(&numbers[r * n], sizeof(numbers[0]), n, inputFile);
            fclose(inputFile); // Close the file
        }

        // Free memory
        delete[] numbers;

    }
    

    return 0;

}







