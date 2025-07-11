#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    // Variables
    double dt;
    int nsteps;

    // Read params from file
    ifstream paramFile("params.dat");
    if (!paramFile) {
        cerr << "Error: Could not open params.dat\n";
        return 1;
    }
    paramFile >> dt >> nsteps;
    paramFile.close();

    // Initialize values
    double x = 1.0;  // initial condition
    double t = 0.0;

    // Open output file
    ofstream outFile("output.dat");
    if (!outFile) {
        cerr << "Error: Could not open output.dat\n";
        return 1;
    }

    // Write header
    outFile << "# time x\n";

    // Euler method loop
    for (int i = 0; i <= nsteps; ++i) {
        outFile << t << " " << x << "\n";
        x = (1 - 3 * dt) * x; // Explicit Euler step
        t += dt;
    }

    outFile.close();
    cout << "Simulation complete. Output written to output.dat\n";
    return 0;
}

