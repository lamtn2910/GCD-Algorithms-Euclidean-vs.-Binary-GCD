#include <iostream>

using namespace std;

void ExplainBinaryGCD_WorkedExample(unsigned int a, unsigned int b) 
{
    cout << "[WORKED EXAMPLE]: Computing GCD(" << a << ", " << b << ")\n\n";
    cout << "1. Euclidean Algorithm: \n";

    unsigned int u = a, v = b;
    int euclid_steps = 0;
    int step = 1;

    while (v != 0) 
    {
        cout << "   Step " << step++ << ": " << u << " % " << v << " = " << u % v << "\n";
        unsigned int temp = v;
        v = u % v;
        u = temp;
        euclid_steps++;
    }
    cout << "   -> Result: " << u << " | Total expensive modulo operations: " << euclid_steps << "\n";
    cout << "   -> Total expensive modulo operations: "<< euclid_steps << "\n\n";
    cout << "2. Binary GCD Algorithm: \n";

    unsigned int u_bin = a, v_bin = b;
    int Count2 = 0;
    int binary_steps = 0;
    step = 1;

    cout << "   Initial state: u = " << u_bin << ", v = " << v_bin << "\n";

    if (u_bin == 0 ) 
    {
        cout << "   Base case reached. Result: " << v_bin << "\n";
    } 
    else if( v_bin == 0 )
    {
        cout << "   Base case reached. Result: " << u_bin << "\n";
    }
    else 
    {
        while ((u_bin & 1) == 0 && (v_bin & 1) == 0) 
        {
            u_bin >>= 1;
            v_bin >>= 1;
            Count2++;
            binary_steps += 2;
            cout << "   Step " << step++ << ": Both even. Shift right. u=" << u_bin << ", v=" << v_bin << " (Count2 = " << Count2 << ")\n";
        }
        while ((u_bin & 1) == 0) 
        {
            u_bin >>= 1;
            binary_steps++;
            cout << "   Step " << step++ << ": u is even. Shift right. u=" << u_bin << "\n";
        }
        while (v_bin != 0) 
        {
            while ((v_bin & 1) == 0) 
            {
                v_bin >>= 1;
                binary_steps++;
                cout << "   Step " << step++ << ": v is even. Shift right. v=" << v_bin << "\n";
            }
            
            if (u_bin > v_bin) 
            {
                unsigned int temp = u_bin;
                u_bin = v_bin;
                v_bin = temp;
                cout << "   Step " << step++ << ": u > v. Swap u and v. u=" << u_bin << ", v=" << v_bin << "\n";
            }
            
            v_bin = v_bin - u_bin;
            binary_steps++;
            cout << "   Step " << step++ << ": Subtract (v = v - u). v=" << v_bin << "\n";
        }
        cout << "   -> Result: u * 2^Count2 = " << u_bin << " * 2^"<< Count2 << " = " << (u_bin * (1 << Count2)) << "\n";
        cout << "   -> Total cheap operations (shifts/subtractions): " << binary_steps << "\n\n";
    }

    cout << "[EXPLANATION]:\n";
    cout << "In the worked example above for GCD(" << a << ", " << b << "):\n";
    cout << "- Euclid's algorithm required " << euclid_steps << " modulo operations. On hardware lacking a dedicated\n";
    cout << "  divider, one modulo instruction costs tens to hundreds of clock cycles.\n";
    cout << "- The Binary GCD algorithm required " << binary_steps << " bitwise shifts and subtractions. These are basic\n";
    cout << "  ALU operations taking just 1 clock cycle each.\n";
    cout << "Therefore, despite requiring more steps, Binary GCD consumes vastly fewer total CPU cycles, making it\n";
    cout << "significantly faster on division-constrained hardware.\n";
}

int main() 
{
    ExplainBinaryGCD_WorkedExample(10000, 6800);
    return 0;
}