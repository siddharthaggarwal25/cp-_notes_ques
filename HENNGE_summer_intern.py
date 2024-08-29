def sum_of_square(x, values):
    if x == 0:
        return 0
    # Process the first value from the list
    y = values.pop(0)
    # If the value is positive, add its square to the result of the recursive call
    if y > 0:
        return y * y + sum_of_square(x - 1, values)
    # If the value is not positive, continue with the recursion
    return sum_of_square(x - 1, values)

def read_values(x, values=None):
    if values is None:
        values = []
    if x == 0:
        return values
    # Read all the values in a single input and split them into a list of integers
    value = int(input())
    # Add the value to the list
    values.append(value)
    # Recursively read the remaining values
    return read_values(x - 1, values)

def read_inputs(n, test_cases=None):
    if test_cases is None:
        test_cases = []
    if n == 0:
        return test_cases
    # Read the integer x which tells how many values will follow
    x = int(input())
    # Recursively read the next x values
    values = list(map(int, input().split()))
    # Add the current test case to the list
    test_cases.append((x, values))
    # Recursively read the remaining test cases
    return read_inputs(n - 1, test_cases)

def process_and_print_results(test_cases):
    if not test_cases:
        return
    # Extract the first test case           
    x, values = test_cases.pop(0)
    # Calculate the result for this test case
    result = sum_of_square(x, values)
    # Print the result
    print(result)
    # Recursively process and print the remaining test cases
    process_and_print_results(test_cases)

def main():
    # Read the number of test cases
    n = int(input())
    # Recursively read all inputs
    test_cases = read_inputs(n)
    # Process and print all results
    process_and_print_results(test_cases)

if __name__ == "__main__":
    main()