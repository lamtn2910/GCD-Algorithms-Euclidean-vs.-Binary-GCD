#include <stdio.h>

void ExplainBinaryGCD_WorkedExample(unsigned int a, unsigned int b) 
{
    printf("[WORKED EXAMPLE]: Computing GCD(%u, %u)\n\n", a, b);
    printf("1. Euclidean Algorithm: \n");

    unsigned int u = a, v = b;
    int euclid_steps = 0;
    int step = 1;

    while (v != 0) 
    {
        printf("   Step %d: %u %% %u = %u\n", step++, u, v, u % v);
        unsigned int temp = v;
        v = u % v;
        u = temp;
        euclid_steps++;
    }
    printf("   -> Result: %u | Total expensive modulo operations: %d\n", u, euclid_steps);
    printf("   -> Total expensive modulo operations: %d\n\n", euclid_steps);
    printf("2. Binary GCD Algorithm: \n");

    unsigned int u_bin = a, v_bin = b;
    int Count2 = 0;
    int binary_steps = 0;
    step = 1;

    printf("   Initial state: u = %u, v = %u\n", u_bin, v_bin);

    if (u_bin == 0) 
    {
        printf("   Base case reached. Result: %u\n", v_bin);
    } 
    else if (v_bin == 0) 
    {
        printf("   Base case reached. Result: %u\n", u_bin);
    } 
    else 
    {
        while ((u_bin & 1) == 0 && (v_bin & 1) == 0) 
        {
            u_bin >>= 1;
            v_bin >>= 1;
            Count2++;
            binary_steps += 2;
            printf("   Step %d: Both even. Shift right. u=%u, v=%u (Count2 = %d)\n", step++, u_bin, v_bin, Count2);
        }
        
        while ((u_bin & 1) == 0) 
        {
            u_bin >>= 1;
            binary_steps++;
            printf("   Step %d: u is even. Shift right. u=%u\n", step++, u_bin);
        }
        
        while (v_bin != 0) 
        {
            while ((v_bin & 1) == 0) 
            {
                v_bin >>= 1;
                binary_steps++;
                printf("   Step %d: v is even. Shift right. v=%u\n", step++, v_bin);
            }
            
            if (u_bin > v_bin) 
            {
                unsigned int temp = u_bin;
                u_bin = v_bin;
                v_bin = temp;
                printf("   Step %d: u > v. Swap u and v. u=%u, v=%u\n", step++, u_bin, v_bin);
            }
            
            v_bin = v_bin - u_bin;
            binary_steps++;
            printf("   Step %d: Subtract (v = v - u). v=%u\n", step++, v_bin);
        }
        
        printf("   -> Result: u * 2^Count2 = %u * 2^%d = %u\n", u_bin, Count2, (u_bin * (1 << Count2)));
        printf("   -> Total cheap operations (shifts/subtractions): %d\n\n", binary_steps);
    }

    printf("[EXPLANATION]:\n");
    printf("In the worked example above for GCD(%u, %u):\n", a, b);
    printf("- Euclid's algorithm required %d modulo operations. On hardware lacking a dedicated\n", euclid_steps);
    printf("  divider, one modulo instruction costs tens to hundreds of clock cycles.\n");
    printf("- The Binary GCD algorithm required %d bitwise shifts and subtractions. These are basic\n", binary_steps);
    printf("  ALU operations taking just 1 clock cycle each.\n");
    printf("Therefore, despite requiring more steps, Binary GCD consumes vastly fewer total CPU cycles, making it\n");
    printf("significantly faster on division-constrained hardware.\n");
}

int main() 
{
    ExplainBinaryGCD_WorkedExample(10000, 6800);
    return 0;
}
