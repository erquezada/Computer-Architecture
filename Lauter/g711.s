# First Name: Eric
# Last Name: Quezada
# Student ID: 80532860
# Computer Organization Final: Fall 2024
.option nopic              # We do not write PIC code
.attribute arch, "rv32i2p0_m2p0_a2p0_f2p0_d2p0_c2p0" # Requirements for our code
.attribute unaligned_access, 0  # We do not use unaligned accesses 
.attribute stack_align, 16      # We align the stack
.text                       # This is where the program starts
.align	1                   # Align this function
.globl	program             # Label program is a globally callable function
.type	program, @function  # Label program is a function

program:                            # Label for the program function. The function starts here
    addi    sp, sp, -64         # Adjust stack pointer to reserve 64 bytes for local variables
    sw      ra, 60(sp)          # Store return address on stack (save the link register)
    sw      s0, 56(sp)          # Save frame pointer (s0) on stack
    addi    s0, sp, 64          # Set the frame pointer to the current stack po
    # Initialize pointers for the conversion tables
    la t3, alaw_to_ulaw_table    # Load address of alaw_to_ulaw_table
    la t4, ulaw_to_alaw_table   # Load address of ulaw_to_alaw_table

    # Function to convert a from A-law to u-law (simplified lookup)
alaw_to_ulaw_ez:
    addi t0, a0, 0              # Copy input a (a0) to t0
    lb t2, 0(t3)                # Load the value from the table at the index t0
    jr ra                       # Return from function

    # Function to convert u from u-law to A-law (simplified lookup)
ulaw_to_alaw_ez:
    addi t0, a0, 0              # Copy input u (a0) to t0
    lb t2, 0(t4)                # Load the value from the table at the index t0
    jr ra                       # Return from function

main:
    # Main function that populates the conversion table
    addi a0, zero, 0            # Set a = 0 (initialize a)

    # Load immediate value 255 into register t0
    li t0, 255

populate_conversion_table:
    bge a0, t0, end_loop       # If a0 >= 255, jump to end_loop

    # Call alaw_to_ulaw(a) and store the result
    jal ra, alaw_to_ulaw_ez     # Call alaw_to_ulaw_ez with a in a0
    move t0, a0                 # Save the result (alaw_to_ulaw)

    # Call ulaw_to_alaw(a) and store the result
    jal ra, ulaw_to_alaw_ez     # Call ulaw_to_alaw_ez with a in a0
    move t1, a0                 # Save the result (ulaw_to_alaw)

    # Store the results in the conversion tables
    sb t0, 0(t3)                # Store alaw_to_ulaw result at index a
    sb t1, 0(t4)                # Store ulaw_to_alaw result at index a

    # Print the result of conversions for testing
    # Example printf will be skipped for simplicity in assembly but can be handled through system calls or external libraries

    addi a0, a0, 1              # Increment a by 1
    jal zero, populate_conversion_table   # Go back to start of loop

end_loop:
    # End of the program, return
    li a0, 0                    # Return value 0
    jr ra                       # Return from main

# Epilogue - Restore the saved registers and adjust stack pointer
    lw      ra, 60(sp)          # Restore the return address (ra)
    lw      s0, 56(sp)          # Restore frame pointer (s0)
    addi    sp, sp, 64          # Restore the stack pointer (move it back to its original position)
    jr      ra                  # Return from program
# Data section for the tables
    .data                       
alaw_to_ulaw_table: 
    .space 256                  # Allocate space for 256 elements
ulaw_to_alaw_table:
    .space 256                  # Allocate space for 256 elements
