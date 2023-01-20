#define MAX_SIZE 100000 /*size of integers array*/

int main() {
    unsigned int i; 
    unsigned int j;
    unsigned int max_filled_index;
    unsigned int numbers[MAX_SIZE];
    unsigned int primes[MAX_SIZE];
    unsigned int num_to_sieve;
    unsigned int prime_count = 0;

    /*Read in an upper limit, n*/
    printf("Please enter a value for n: ");
    if (scanf("%d", &num_to_sieve) != 1) {
        printf("Sorry, cannot read n.\n");
        return 1;
    }

    max_filled_index = num_to_sieve - 2;
    /*fill the array with natural numbers*/
    for (i = 0; i <= max_filled_index; i++) {
        numbers[i] = i + 2;
    }


    /*sieve the non-primes*/
    for (i = 0; i <= max_filled_index; i++) {
        if (numbers[i] != 0) {
            for (j = 2 * numbers[i] - 2; j <= max_filled_index; j += numbers[i]) {
                numbers[j] = 0;
            }
        }
    }

    /*transfer the primes to their own array*/
    for (i = 0; i <= max_filled_index && prime_count < MAX_SIZE; i++)
        if (numbers[i] != 0) {
            primes[prime_count] = numbers[i];
            prime_count++;
        }

    /*print*/
    for (i = 0; i < prime_count; i++)
        printf("%d\n", primes[i]);

    return 0;
}